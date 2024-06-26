
#include "Cmd.hpp"

bool	parsForInvite(Clients client, std::string &nickname, std::string &channelName, std::string cmd);
bool 	checkIfUserAlreadyInviteOrInChannel(std::map<std::string, Channels>::iterator it, std::string nickname, std::string channelName, Clients client, std::map<int, Clients>::iterator ite);
bool	checkChannelExistAndUserLegitimateToInvite(std::map<std::string, Channels>::iterator it, Clients client, std::string channelName);


void    Invite(std::string cmd, Clients& client, Server& server)
{
	std::string nickname = &cmd[7];
	std::string channelName;


	if (parsForInvite(client, nickname, channelName, cmd) == 1)
		return ;
	std::map<std::string, Channels> &servChannel = server.getChannels();
	std::map<std::string, Channels>::iterator it = servChannel.find(channelName);
	if (it == servChannel.end() || servChannel.size() == 0)
	{
		sendCmd(ERR_NOSUCHCHANNEL(client.getNickname(), channelName), client);
		return ;
	}
	if (checkChannelExistAndUserLegitimateToInvite(it, client, channelName))
		return ;
	std::map<int, Clients>::iterator ite;
	std::map<int, Clients> allClient = server.getClients();
	for (ite = allClient.begin(); ite != allClient.end(); ite++)
	{
		if (nickname == ite->second.getNickname())
		{
			if (checkIfUserAlreadyInviteOrInChannel(it, nickname, channelName, client, ite))
					return ;
			server.getChannels().find(it->first)->second.getClientInvited().insert(std::make_pair(ite->first, ite->second));
			sendCmd(RPL_INVITING(client.getNickname(), channelName, nickname), client);
			sendCmd(RPL_INVITE_MESSAGE(client.getNickname(), channelName, client.getUsername(), client.getAddrIp(), ite->second.getNickname()),  ite->second);
			return ;
		}
	}
	sendCmd(ERR_NOSUCHNICK(client.getUsername(), nickname), client);
}

bool	Channels::checkIfOpeUserForInvite(Clients client)
{
	size_t i = 0;
	while(i < _operator.size())
	{
		if (_operator[i].getNickname() == client.getNickname())
			break;
		i++;
	}
	if (i == _operator.size())
	{
		sendCmd(ERR_CHANOPRIVSNEEDED(client.getNickname(), _name), client);
		return 1;
	}
	return 0;
}


bool	parsForInvite(Clients client, std::string &nickname, std::string &channelName, std::string cmd)
{
	size_t spacefind;

	spacefind = nickname.find_first_of(" ");
	nickname = nickname.substr(0, spacefind);
	channelName = &cmd[7 + nickname.size() + 1];
	channelName = channelName.substr(0, channelName.size() - 2);

	if (channelName == client.getUsername())
	{
		sendCmd(ERR_NEEDMOREPARAMS(nickname, "INVITE"), client);
		return 1;
	}
	return 0;
}

bool	checkChannelExistAndUserLegitimateToInvite(std::map<std::string, Channels>::iterator it, Clients client, std::string channelName)
{
	if (it->second.getClientMap().end() == it->second.getClientMap().find(client.getFd()))
	{
		sendCmd(ERR_NOTONCHANNEL(channelName, it->second.getName()), client);
		return true;
	}
	if (it->second.checkIfOpeUserForInvite(client) == 1)
		return true;
	return false;
}

bool checkIfUserAlreadyInviteOrInChannel(std::map<std::string, Channels>::iterator it, std::string nickname, std::string channelName, Clients client, std::map<int, Clients>::iterator ite)
{
	std::map<int, Clients> clientChannel = it->second.getClientMap();
	if (clientChannel.find(ite->first) != clientChannel.end())
	{
		sendCmd(ERR_USERONCHANNEL(client.getNickname(), nickname, channelName), client);
		return true;
	}
	std::map<int, Clients> &verif = it->second.getClientInvited();
	if (verif.find(ite->first) != verif.end())
	{
		sendCmd(RPL_INVITING(client.getNickname(), channelName, nickname), client);
		sendCmd(RPL_INVITE_MESSAGE(client.getNickname(), channelName, client.getUsername(), client.getAddrIp(), ite->second.getNickname()),  ite->second);
		return true;
	}
	return false;
}


