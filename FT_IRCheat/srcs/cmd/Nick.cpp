/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:55 by nibernar          #+#    #+#             */
/*   Updated: 2024/06/04 13:42:29 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cmd.hpp"

bool parseNick(std::string& nick, Clients& client)
{
    if (nick.size() == 0 || nick.size() > 30)
    {
        sendCmd(RPL_ISUPPORT(client.getNickname(), "NICKLEN=30"), client);
        return (false);
    }
    for (size_t i = 0; i < nick.size(); i++) {
        if (nick[i] == ',' || nick[i] == ' ' || nick[i] == '*' || nick[i] == '?' || nick[i] == '!' || nick[i] == '@' || (nick[i] >= 9 && nick[i] <= 13))
        {
            sendCmd(ERR_ERRONEUSNICKNAME(client.getNickname(), nick), client);
            return (false);
        }
    }
    if (nick[0] == '#' || nick[0] == '&' || nick[0] == ':')
    {
        sendCmd(ERR_ERRONEUSNICKNAME(client.getNickname(), nick), client);
        return (false);
    }
    return (true);
}

void 	Nick(std::string cmd, Clients& client, Server& server)
{
    static bool nickname_used = false;
    static std::string falseNickname = "";
    std::map<int, Clients>& mapClients = server.getClients();
    std::vector<std::string> splited = split(cmd, ' ');
    if (splited.size() != 2)
        return (sendCmd(ERR_NEEDMOREPARAMS(client.getNickname(), "NICK"), client));
    if (parseNick(splited[1], client) == false)
        return ;
    if (client.getNickname().size() != 0)
    {
        for (std::map<int, Clients>::iterator it = server.getClients().begin(); it != server.getClients().end(); it++)
        {
            if (it->second.getNickname() == splited[1])
            {
                nickname_used = true;
                falseNickname = splited[1];
                return (sendCmd(RPL_ERROR_NICKNAME_IN_USE(client.getNickname(), falseNickname), client));
            }
        }
    }
    if (nickname_used == true)
    {
        nickname_used = false;
        sendBroadcastServer(RPL_CMD_NICK(falseNickname, client.getUsername(), client.getAddrIp(), splited[1]), server);
        falseNickname = "";
    }
    else
        sendBroadcastServer(RPL_CMD_NICK(client.getNickname(), client.getUsername(), client.getAddrIp(), splited[1]), server);
    for (std::map<std::string, Channels>::iterator it = server.getClients().find(client.getFd())->second.getChannelsClient().begin(); it != server.getClients().find(client.getFd())->second.getChannelsClient().end(); it++)
        server.getChannels().find(it->first)->second.getClientMap().find(client.getFd())->second.setNickname(splited[1]);
    for (std::map<std::string, Channels>::iterator it = server.getClients().find(client.getFd())->second.getChannelsInvite().begin(); it != server.getClients().find(client.getFd())->second.getChannelsInvite().end(); it++)
        server.getChannels().find(it->first)->second.getClientInvited().find(client.getFd())->second.setNickname(splited[1]);
    mapClients.find(client.getFd())->second.setNickname(splited[1]);
    client.setNickname(splited[1]);
    return ;
}

bool 	NickInit(std::string cmd, Clients& client, Server& server)
{
    std::map<int, Clients>& mapClients = server.getClients();
    std::vector<std::string> splited = split(cmd, ' ');
    if (splited.size() != 1)
        return (sendCmd(ERR_NEEDMOREPARAMS(client.getNickname(), "NICK"), client), false);
    if (parseNick(splited[0], client) == false)
        return (false);
    for (std::map<int, Clients>::iterator it = server.getClients().begin(); it != server.getClients().end(); it++)
    {
        if (it->second.getNickname() == splited[0])
        {
            client.setNicknameTmp(splited[0]);
            return (sendCmd(RPL_ERROR_NICKNAME_IN_USE(client.getNickname(), client.getNicknameTmp()), client), false);
        }
    }
    mapClients.find(client.getFd())->second.setNickname(splited[0]);
    client.setNickname(splited[0]);
    return (true);
}