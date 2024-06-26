//
// Created by dbaule on 5/30/24.
//

#include "Cmd.hpp"
#include "Server.hpp"

void Quit(std::string cmd, Clients& client, Server& server)
{
	std::string reason;
	if (cmd[5] == ':')
		reason = &cmd[6];
	else
		reason = &cmd[5];
	reason = reason.substr(0, reason.size() - 2);
	int fdCible = client.getFd();

	std::map<std::string, Channels>& servChannel = server.getChannels();
	for (std::map<std::string, Channels>::iterator itChan = servChannel.begin(); itChan != servChannel.end(); ++itChan) 
	{
		std::map<int, Clients>& clientInChan = itChan->second.getClientMap();
		for (std::map<int, Clients>::iterator itClient = clientInChan.begin(); itClient != clientInChan.end();) 
		{
			if (fdCible == itClient->first)
			{
				Clients operatorChan = itChan->second.getOperator(itClient->first);
				if (operatorChan.getFd() == fdCible && itChan->second.getClientMap().size() > 1)
				{
					if (itChan->second.getOperatorVector().size() == 1)
					{
						std::map<int, Clients>::iterator itTmp = clientInChan.begin();
						if (itTmp->first != fdCible)
							itChan->second.setOperator(itTmp->second);
						else 
						{
							++itTmp;
							itChan->second.setOperator(itTmp->second);
						}
						NameLstUpdate(client, itChan->second);
					}
					itChan->second.removeOperator(client);
				}
				sendBroadcastChannel(RPL_QUIT_CHANNEL(client.getNickname(), client.getUsername(), client.getAddrIp(), itChan->first, reason), itChan->second);
				if (itChan->second.getClientMap().size() == 1)
				{
					itChan->second.removeOperator(client);
					sendCmd(RPL_PART(client.getNickname(), itChan->second.getName(), client.getUsername(), client.getAddrIp()), client);
					server.getChannels().erase(itChan++);
					if (server.getClients().size() != 1)
						++itChan;
					else
					{
						int i = 0;
						for (std::vector<pollfd>::iterator itPollFd = server.getLstPollFd().begin(); itPollFd != server.getLstPollFd().end(); ++itPollFd) 
						{
							if (itPollFd->fd == fdCible)
							{
								server.getLstPollFd().at(i).events = 0;
								server.getLstPollFd().at(i).revents = 0;
								close(server.getLstPollFd().at(i).fd);
								server.getLstPollFd().erase(itPollFd);
								break ;
							}
							i++;
						}
						server.getClients().erase(client.getFd());
						return ;
					}
					break ;
				}
				clientInChan.erase(itClient++);
			}
			else
				++itClient;
		}
	}
	int i = 0;
	for (std::vector<pollfd>::iterator itPollFd = server.getLstPollFd().begin(); itPollFd != server.getLstPollFd().end(); ++itPollFd) 
	{
		if (itPollFd->fd == fdCible)
		{
			server.getLstPollFd().at(i).events = 0;
			server.getLstPollFd().at(i).revents = 0;
			close(server.getLstPollFd().at(i).fd);
			server.getLstPollFd().erase(itPollFd);
			break ;
		}
		i++;
	}
	server.getClients().erase(client.getFd());
}
