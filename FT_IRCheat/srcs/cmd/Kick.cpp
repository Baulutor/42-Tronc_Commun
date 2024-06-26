/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:14:18 by bfaure            #+#    #+#             */
/*   Updated: 2024/05/13 16:37:36 by bfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cmd.hpp"
#include "Channels.hpp"

bool LFTarget(std::string &chanTarget, std::string &target, std::string &com, std::string cmd) {
    std::vector<std::string> splited = split(cmd, ' ');
    
    if (splited.size() < 3)
        return false;
    size_t targetIdx = 2;
    size_t commentIdx = 3;
    chanTarget = splited[1];
    if (splited[1][0] == '#' && splited[2][0] == '#')
        return false;
    if (splited[2][0] == '#') {
        chanTarget = splited[2];
        targetIdx = 3;
        commentIdx = 4;
    }
    target = splited[targetIdx][0] == ':' ? splited[targetIdx].substr(1) : splited[targetIdx];

    com = "";
    for (size_t i = commentIdx; i < splited.size(); i++) {
        com += " " + splited[i];
    }
    return true;
}


void Kick(std::string cmd, Clients& client, Server& server) {
    std::map<std::string, Channels>& channel = server.getChannels();
    std::map<std::string, Channels>::iterator it = channel.begin();
    std::string chanTarget;
    std::string target;
    std::string com;

    if (LFTarget(chanTarget, target, com, cmd) != true)
	{
        std::cout << "KICK <channel> <user> :<comment>" << std::endl;
        sendCmd(ERR_NEEDMOREPARAMS(client.getNickname(), "KICK"), client);
        return;
    }
    for (; it != channel.end(); ++it) {
        if (it->first == chanTarget) {
            std::map<int, Clients>& clientsMap = it->second.getClientMap();
            std::map<int, Clients>::iterator it2 = clientsMap.begin();
			if (clientsMap.find(client.getFd()) == clientsMap.end())
			{
				sendCmd(ERR_NOTONCHANNEL(client.getNickname(), chanTarget), client);
				return ;
			}
            for(; it2 != clientsMap.end(); ++it2)
			{
				Clients op = it->second.getOperator(client.getFd());
				if (op.getNickname() == "")
					return(sendCmd(ERR_NOTCHANOP(client.getNickname(), it->second.getName()), client));
                if ((it2->second.getNickname()) == target)
				{
                    if (client.getNickname() == target)
                        return (sendBroadcastChannel(RPL_KICK_NOTICE(client.getNickname(), it->first), it->second));
                    sendBroadcastChannel(RPL_CMD_KICK(client.getNickname(), client.getUsername(), client.getAddrIp(), it->first, it2->second.getNickname(), com), it->second);
					std::vector<Clients> &opeVec = it->second.getOperatorVector();
					for (std::vector<Clients>::iterator iter = opeVec.begin(); iter != opeVec.end(); ++iter)
					{
                        if (iter->getFd() == it2->first)
                        {
                            it->second.removeOperator(it2->second);
                            it->second.removeMode(it2->first, "o");
                            NameLstUpdate(client, it->second);
                            break;
                        }
					}
					if (it->second.getClientInvited().find(it2->first) != it->second.getClientInvited().end())
						it->second.getClientInvited().erase(it->second.getClientInvited().find(it2->first));
                    clientsMap.erase(it2);
                    return ;
                }
            }
            if (it2 == clientsMap.end())
                return (sendBroadcastChannel(ERR_USERNOTFOUND(client.getNickname(), target, it->first), it->second));
        }
    }
    if (it == channel.end()) {
        it--;
        return (sendBroadcastChannel(ERR_NOSUCHCHANNEL(client.getNickname(), chanTarget), it->second));
    }
}

