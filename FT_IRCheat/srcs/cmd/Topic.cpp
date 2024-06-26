//
// Created by dbaule on 5/28/24.
//

#include "Cmd.hpp"

void 	Topic(std::string cmd, Clients& client, Server& server)
{
	std::string channelName = &cmd[6];
	size_t forSeparate;
	forSeparate = channelName.find(" ");
	channelName = channelName.substr(0, forSeparate);
	if (channelName[channelName.size() - 1] == '\n')
		channelName = channelName.substr(0, channelName.size() - 2);
	if (channelName == client.getUsername())
	{
		sendCmd(ERR_NEEDMOREPARAMS(client.getNickname(), "TOPIC"), client);
		return ;
	}
	std::map<std::string, Channels>::iterator channel = server.getChannels().find(channelName);
	if (channel == server.getChannels().end())
	{
		sendCmd(ERR_NOSUCHCHANNEL(client.getNickname(), channelName), client);
		return ;
	}
	std::string topicMessage;
	if (cmd[6 + channelName.size() + 2] == '\0')
	{
		if (channel->second.getTopic() == "")
			sendCmd(RPL_NOTOPIC(channelName),client);
		else
			sendCmd(RPL_CMD_TOPIC(client.getNickname(), channelName, channel->second.getTopic()), client);
		return ;
	}
	if (cmd[6 + channelName.size() + 1] == ':')
		topicMessage = &cmd[6 + channelName.size() + 2];
	else
		topicMessage = &cmd[6 + channelName.size() + 1];
	topicMessage = topicMessage.substr(0, topicMessage.size() - 2);
	if (topicMessage == "\"\"")
		topicMessage = "\0";
	std::map<int, Clients>::iterator ClientInChannel = channel->second.getClientMap().find(client.getFd());
	if (ClientInChannel == channel->second.getClientMap().end())
	{
		sendCmd(ERR_NOTONCHANNEL(client.getNickname(), channelName), client);
		return ;
	}
	if (channel->second.getOperator(client.getFd()).getNickname() == "" && channel->second.getMode(-42).find("t") != channelName.npos)
	{
		sendCmd(ERR_CHANOPRIVSNEEDED(client.getNickname(), channelName), client);
		return ;
	}
	server.getChannels().find(channelName)->second.setTopic(topicMessage);
	sendBroadcastChannel(RPL_CMD_TOPIC(client.getNickname(), channelName, topicMessage), channel->second);
}
