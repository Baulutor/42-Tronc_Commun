#include "Server.hpp"
#include "Cmd.hpp"

Server::Server(){}

int Server::getFd() const {return this->_fd;}

std::string Server::getAddrIp() const {return this->_addrIp;}

std::string Server::getPassword() const {return (this->_password);}

std::map<std::string, Channels>& Server::getChannels() {return (_channels);}

std::map<int, Clients>& Server::getClients() {return (_clients);}

std::vector<pollfd> &Server::getLstPollFd() {return (this->_lstPollFd);}

void Server::setFd(int fd) {this->_fd = fd;}

void Server::setAddrIp(std::string addrIp) {this->_addrIp = addrIp;}

void Server::setChannels(std::map<std::string, Channels> channels) {this->_channels = channels;}

void Server::setClient(std::map<int, Clients> clients) {this->_clients = clients;}

void Server::setPassword(std::string password) {this->_password = password;}

bool startWith(const std::string &line, const char *cmd) {return (line.find(cmd) == 0);}

std::string Server::getNameClientByFd(int fd)
{
    std::map<int, Clients>::iterator it = _clients.find(fd);
    return (it->second.getNickname());
}

int Server::getFdClientByName(std::string name)
{
    for (std::map<int, Clients>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        if (it->second.getNickname() == name)
            return (it->first);
    }
	if (name[0] == '#')
		return (-42);
    return (-1);
}

void Server::cmdHandler(std::string cmd, Clients& client)
{
    const char *lstCmd[] = {"JOIN ", "KICK ", "PRIVMSG ", "PING ", "INVITE ", "MODE ", "TOPIC ", "NICK ", "QUIT "};
    void (*lstFunc[])(std::string, Clients&, Server&) = {Join, Kick, Privmsg, Pong, Invite, Mode, Topic, Nick, Quit};
    for (int i = 0; i < 9; i++)
    {
        if (startWith(cmd, lstCmd[i]))
        {
            lstFunc[i](cmd, client, *this);
            return;
        }
    }
	if (startWith(cmd, "WHO"))
		return ;
	sendCmd("ERROR : command not found\r\n", client);
}

void Server::launch(std::string av, std::string av2)
{
	int opt = 1;

	setAddrIp("127.0.0.1");
	setPassword(av2);
	_fd = -1;

	setFd(socket(AF_INET, SOCK_STREAM, 0));
	if (getFd() < 0)
	{
		perror("Error Socket");
		throw std::invalid_argument("");
	}
	signal(SIGINT, signalHandler);

	if (setsockopt(getFd(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("Error setsockopt");
		close(_fd);
		throw std::invalid_argument("");
	}

	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY;
	_address.sin_port = htons(atoi(av.c_str()));

	if (bind(getFd(), (struct sockaddr *)&_address, sizeof(_address)) < 0)
	{
		perror("Error bind");
		close(_fd);
		throw std::invalid_argument("");
	}

	if (listen(getFd(), 3) < 0)
	{
		perror("Error listen: ");
		close(_fd);
		throw std::invalid_argument("");
	}
	serverHandler();
}

bool Server::ClientConnexion()
{
	int newClientFd = 0;
	std::cout << "New connexion detected" << std::endl;
	Clients newClient;
	socklen_t sock_info_len = sizeof(_address);
	struct pollfd pollClienTmp;
	newClientFd = accept(getFd(), (struct sockaddr*)&_address, &sock_info_len);
	newClient.setFd(newClientFd);
	_clients.insert(std::make_pair(newClient.getFd(), newClient));
	pollClienTmp.fd = newClientFd;
	pollClienTmp.events = POLLIN;
	pollClienTmp.revents = 0;
	_lstPollFd.push_back(pollClienTmp);
	return (true);
}

bool Server::ClientHandler(bool init)
{
	size_t i = 1;
	while (i < _lstPollFd.size())
	{
		if (i < _lstPollFd.size() && _lstPollFd[i].revents & POLLIN)
		{
			std::map<int, Clients>& clientsMap = getClients();
			std::map<int, Clients>::iterator itClients = clientsMap.find(_lstPollFd[i].fd);

			if (itClients == clientsMap.end())
			{
				i++;
				break;
			}
			else
			{
				Clients& client = itClients->second;
				bzero(client.getBuffer(), 512);
				ssize_t bytes = recv(_lstPollFd[i].fd, client.getBuffer(), 511, MSG_DONTWAIT);
				if (bytes == 0)
				{
					std::cout << "connexion closed " << std::endl;
					close(client.getFd());
					close(_lstPollFd[i].fd);
					_clients.erase(client.getFd());
					_lstPollFd.erase(_lstPollFd.begin() + i);
					continue ;
				}
				else if (bytes > 0)
				{
					if ((client.getBuffer()[bytes - 1] != '\n' && (bytes == 1 || client.getBuffer()[bytes - 2] != '\r')))
					{
						client.setBufferTmp(client.getBuffer());
						itClients->second.setBuffer(NULL);
						continue ;
					}
					if (client.getBufferTmp()[0] != '\0')
					{
						client.setBufferTmp(client.getBuffer());
						client.setBuffer(client.getBufferTmp());
						client.setBufferTmp(NULL);
					}
				}
				if (startWith(client.getBuffer(), "CAP LS 302") || !init)
				{
					init = client.initClients(client.getBuffer(), *this);
					if (init && client.getIsRegistered() == true)
						std::cout << "init client" << std::endl;
					else if (init && client.getIsRegistered() == false)
					{
						std::cerr << "client not registered" << std::endl;
						sendCmd("ERROR :Deconnexion", client);
						i--;
						Quit(itClients->second.getBuffer(), itClients->second, *this);
						if (itClients == _clients.end())
							break;
					}
					break;
				}
			}
			if (itClients->second.getIsRegistered() == true)
			{
				char tmp[512];
				bzero(tmp, 512);
				if (startWith(itClients->second.getBuffer(), "QUIT "))
					strcpy(tmp, itClients->second.getBuffer());
				cmdHandler(itClients->second.getBuffer(), itClients->second);
				if (tmp[0] != '\0')
					return (true);
			}
		}
		i++;
	}
	return (init);
}

void	Server::serverHandler()
{
	struct pollfd pollServ;
	pollServ.fd = getFd();
	pollServ.events = POLLIN;
	pollServ.revents = 0;
	_lstPollFd.push_back(pollServ);
	bool init = false;
	while (true)
	{
		if (poll(&_lstPollFd[0], _lstPollFd.size(), -1) >= 0)
		{
			if (_lstPollFd[0].revents & POLLIN)
				init = ClientConnexion();
			else
				init = ClientHandler(init);
		}
		else
			throw std::invalid_argument("ERR poll\r\n");
	}
}

Server::~Server()
{

}