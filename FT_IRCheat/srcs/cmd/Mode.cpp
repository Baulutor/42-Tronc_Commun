/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:42:28 by bfaure            #+#    #+#             */
/*   Updated: 2024/06/04 16:14:11 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cmd.hpp"

bool isChannel(std::string target)
{
    if (target.find('#') != std::string::npos)
        return (true);
    return (false);
}

bool isMode(std::string target)
{
    if (target.find_first_of("it") != std::string::npos)
        return (true);
    if (target.find("-") != std::string::npos && target.find("l") != std::string::npos)
        return (true);
    if (target.find("-") != std::string::npos && target.find("k") != std::string::npos)
        return (true);
    return (false);
}

bool isArgsMode(std::string target)
{
    if (target.find_first_of("o") != std::string::npos)
        return (true);
    if (target.find("+") != std::string::npos && target.find("l") != std::string::npos)
        return (true);
    if (target.find("+") != std::string::npos && target.find("k") != std::string::npos)
        return (true);
    return (false);
}

bool checkChannel(std::string target, Server& server, Clients& client, std::map<std::string, Channels>::iterator channelIt)
{
    if (channelIt == server.getChannels().end())
        return (sendCmd(ERR_NOSUCHCHANNEL(client.getNickname(), target), client), false);
    return (true);
}

char getMode(std::string target, size_t i)
{
    return (target[i]);
}

int addOpMode(std::vector<std::string> args, size_t i, std::map<std::string, Channels>::iterator channelIt, Server& server)
{
    while (i >= args.size())
        i--;
    int fdClient = server.getFdClientByName(args[i]);
    std::map<int, Clients>::iterator clientIt = channelIt->second.getClientMap().find(fdClient);
    if (clientIt != channelIt->second.getClientMap().end())
    {
        if (server.getChannels().find(channelIt->first)->second.getMode(fdClient).find('o') == std::string::npos)
        {
            server.getChannels().find(channelIt->first)->second.setMode(fdClient, "o");
            server.getChannels().find(channelIt->first)->second.setOperator(clientIt->second);
            NameLstUpdate(clientIt->second, channelIt->second);
            return (1);
        }
    }
    return (1);
}

int removeOpMode(std::vector<std::string> args, size_t i, std::map<std::string, Channels>::iterator channelIt, Server& server)
{
    while (i >= args.size())
        i--;
    int fdClient = server.getFdClientByName(args[i]);
    std::map<int, Clients>::iterator clientIt = channelIt->second.getClientMap().find(fdClient);
    if (clientIt != channelIt->second.getClientMap().end())
    {
        if (server.getChannels().find(channelIt->first)->second.getMode(fdClient).find('o') != std::string::npos)
        {
            server.getChannels().find(channelIt->first)->second.removeMode(fdClient, "o");
            server.getChannels().find(channelIt->first)->second.removeOperator(clientIt->second);
            NameLstUpdate(clientIt->second, channelIt->second);
            return (1);
        }
    }
    return (1);
}

int addInviteMode(int target, std::map<std::string, Channels>::iterator channelIt)
{
    if (channelIt->second.getMode(target).find('i') == std::string::npos)
    {
        channelIt->second.setMode(target, "i");
        return (1);
    }
    return (1);
}

int removeInviteMode(int target, std::map<std::string, Channels>::iterator channelIt)
{
    if (channelIt->second.getMode(target).find('i') != std::string::npos)
    {
        channelIt->second.removeMode(target, "i");
        return (1);
    }
    return (1);
}

int addTopicMode(int target, std::map<std::string, Channels>::iterator channelIt)
{
    if (channelIt->second.getMode(target).find('t') == std::string::npos)
    {
        channelIt->second.setMode(target, "t");
        return (1);
    }
    return (1);
}

int removeTopicMode(int target, std::map<std::string, Channels>::iterator channelIt)
{
    if (channelIt->second.getMode(target).find('t') != std::string::npos)
    {
        channelIt->second.removeMode(target, "t");
        return (1);
    }
    return (1);
}

int addKeyMode(int target, std::vector<std::string> args, size_t i, std::map<std::string, Channels>::iterator channelIt)
{
    std::cout << "target = |" << target << "|" << std::endl;
    while (i >= args.size())
        i--;
    std::cout << "channelIt->second.getMode(target) = |" << channelIt->second.getMode(target) << "|" << std::endl;
    if (channelIt->second.getMode(target).find('k') == std::string::npos)
    {
        channelIt->second.setMode(target, "k");
        channelIt->second.setPassword(args[i]);
        return (1);
    }
    return (1);
}

int removeKeyMode(int target, std::map<std::string, Channels>::iterator channelIt)
{
    if (channelIt->second.getMode(target).find('k') != std::string::npos)
    {
        channelIt->second.removeMode(target, "k");
        return (1);
    }
    return (1);
}

int addLimitMode(int target, std::vector<std::string> args, size_t i, std::map<std::string, Channels>::iterator channelIt, Clients& client)
{
    std::cout << "target = |" << target << "|" << std::endl;
    while (i >= args.size())
        i--;
    std::cout << "channelIt->second.getMode(target) = |" << channelIt->second.getMode(target) << "|" << std::endl;
    if (channelIt->second.getMode(target).find('l') == std::string::npos)
    {
        if (args[i].find_first_not_of("0123456789") == std::string::npos)
        {
            if (atoi(args[i].c_str()) > 0)
            {
                channelIt->second.setMode(target, "l");
                channelIt->second.setLimit(atoi(args[i].c_str()));
            }
            else
                return (sendCmd(ERR_INVALIDMODEPARAM(client.getNickname(), "+l", args[i]), client), 1);
        }
        else
            return (sendCmd(ERR_INVALIDMODEPARAM(client.getNickname(), "+l", args[i]), client), 1);
        return (1);
    }
    return (1);
}

int removeLimitMode(int target, std::map<std::string, Channels>::iterator channelIt)
{
    if (channelIt->second.getMode(target).find('l') != std::string::npos)
    {
        channelIt->second.removeMode(target, "l");
        return (1);
    }
    return (1);
}

void checkArgs(std::vector<std::string> args, std::string modes, Clients& client, std::map<std::string, Channels>::iterator channelIt, Server& server)
{
    size_t i = 0;
    bool plusSign = false;
    bool minusSign = false;
    (void)client;
    while (i < modes.size())
    {
        if ((modes[i] == '+' || plusSign == true) && modes[i] != '-')
        {
            minusSign = false;
            plusSign = true;
            if (getMode(modes, i) == 'i')
            {
                i += addInviteMode(server.getFdClientByName(channelIt->first), channelIt);
                continue;
            }
            if (getMode(modes, i) == 't')
            {
                i += addTopicMode(server.getFdClientByName(channelIt->first), channelIt);
                continue;
            }
			if (args.size() == 0 && isArgsMode(modes))
			{
				sendCmd(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"), client);
				return ;
			}
            if (getMode(modes, i) == 'o')
            {
                i += addOpMode(args, i, channelIt, server);
                continue;
            }
            if (getMode(modes, i) == 'k')
            {
                i += addKeyMode(server.getFdClientByName(channelIt->first), args, i, channelIt);
                continue;
            }
            if (getMode(modes, i) == 'l')
            {
                i += addLimitMode(server.getFdClientByName(channelIt->first), args, i, channelIt, client);
                continue;
            }
        }
        if ((modes[i] == '-' || minusSign == true) && modes[i] != '+')
        {
            plusSign = false;
            minusSign = true;
            if (getMode(modes, i) == 'o')
            {
                i += removeOpMode(args, i, channelIt, server);
                continue;
            }
            if (getMode(modes, i) == 'i')
            {
                i += removeInviteMode(server.getFdClientByName(channelIt->first), channelIt);
                continue;
            }
            if (getMode(modes, i) == 't')
            {
                i += removeTopicMode(server.getFdClientByName(channelIt->first), channelIt);
                continue;
            }
            if (getMode(modes, i) == 'k')
            {
                i += removeKeyMode(server.getFdClientByName(channelIt->first), channelIt);
                continue;
            }
            if (getMode(modes, i) == 'l')
            {
                i += removeLimitMode(server.getFdClientByName(channelIt->first), channelIt);
                continue;
            }
        }
        i++;
    }
}

void Mode(std::string cmd, Clients& client, Server& server)
{
    cmd.erase(0, 5);
    std::vector<std::string> tokens = splitInit(cmd, ' ');
    if (tokens.size() == 0)
        return (sendCmd(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"), client));
    std::map<std::string, Channels>::iterator channelIt = server.getChannels().find(tokens[0]);
    for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        if (*it == "WHO")
        {
            tokens.erase(it, tokens.end());
            break;
        }
    }
    if (channelIt == server.getChannels().end())
        return (sendCmd(ERR_NOSUCHCHANNEL(client.getNickname(), tokens[0]), client));
    if (channelIt->second.getOperator(client.getFd()).getFd() != client.getFd())
        return (sendCmd(ERR_CHANOPRIVSNEEDED(client.getNickname(), tokens[0]), client));
    if (tokens.size() < 1)
        return (sendCmd(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"), client));
    else if (tokens.size() == 1)
    {
        if (!checkChannel(tokens[0], server, client, channelIt))
            return ;
        return (sendCmd(RPL_CHANNELMODEIS(client.getNickname(), tokens[0], channelIt->second.getMode(-42)), client));
    }
    else if (tokens.size() == 2)
    {
        if (!checkChannel(tokens[0], server, client, channelIt))
            return ;
        int fdClient = findFdClientByName(tokens[1], server.getClients());
        std::map<int, Clients>::iterator clientIt = channelIt->second.getClientMap().find(fdClient);
        if (clientIt == channelIt->second.getClientMap().end())
        {
            if (!isMode(tokens[1]) && (tokens[1][0] != '-' || tokens[1][0] != '+'))
            {
                if (isArgsMode(tokens[1]) && (tokens[1][0] != '-' || tokens[1][0] != '+'))
                    return (sendCmd(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"), client));
                else
                    return (sendCmd(ERR_UMODEUNKNOWNFLAG(client.getNickname(), tokens[1]), client));
            }
            else
            {
                std::vector<std::string> args(tokens.begin() + 2, tokens.end());
                checkArgs(args, tokens[1], client, channelIt, server);
            }
        }
        else
            return (sendCmd(RPL_UMODEIS(client.getNickname(), tokens[1], channelIt->second.getMode(server.getFdClientByName(tokens[1]))), client));
    }
    else if (tokens.size() >= 3)
    {
        if (!checkChannel(tokens[0], server, client, channelIt))
            return ;
        if ((isMode(tokens[1]) && !isArgsMode(tokens[1])) && (tokens[1][0] != '-' || tokens[1][0] != '+'))
            return (sendCmd(ERR_INVALIDMODEPARAM(client.getNickname(), tokens[1], tokens[2]), client));
        std::vector<std::string> args(tokens.begin() + 2, tokens.end());
        checkArgs(args, tokens[1], client, channelIt, server);
    }
}

