/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clients.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:36:58 by bfaure            #+#    #+#             */
/*   Updated: 2024/06/04 13:43:57 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Clients.hpp"
#include <sstream>
#include "Cmd.hpp"

Clients::Clients()
{
    _fd = -1;
    _addrIp = "";
    _nickname = "";
    _username = "";
    _pass = "";
    _isRegistered = false;
    bzero(_buffer, 512);
    bzero(_bufferTmp, 512);
}

Clients::~Clients() {}

// Getters

int Clients::getFd() const {return (_fd);}

std::string Clients::getAddrIp() const {return (_addrIp);}

std::string Clients::getNickname() const {return (_nickname);}

std::string Clients::getUsername() const {return (_username);}

std::string Clients::getPass() const {return (_pass);}

std::map<std::string, Channels>& Clients::getChannelsClient() {return (_channels);}

std::map<std::string, Channels>& Clients::getChannelsInvite() {return (_channelsInvite);}

bool Clients::getIsRegistered() const {return (_isRegistered);}

char* Clients::getBuffer() {return (_buffer);}

char* Clients::getBufferTmp() {return (_bufferTmp);}

std::string Clients::getNicknameTmp() const {return (_nicknameTmp);}

// Setters

void Clients::setFd(int fd) {_fd = fd;}

void Clients::setAddrIp(std::string addrIp) {_addrIp = addrIp;}

void Clients::setNickname(std::string nickname) {_nickname = nickname;}

void Clients::setUsername(std::string username) {_username = username;}

void Clients::setPass(std::string pass) {_pass = pass;}

void Clients::setIsRegistered(bool isRegistered) {_isRegistered = isRegistered;}

void Clients::setBuffer(char* buffer)
{
    if (buffer != NULL)
        strcpy(_buffer, buffer);
    else
        bzero(_buffer, 512);
}

void Clients::setBufferTmp(char* bufferTmp)
{
    if (bufferTmp != NULL)
        strcat(_bufferTmp, bufferTmp);
    else
        bzero(_bufferTmp, 512);
}

void Clients::setNicknameTmp(std::string nicknameTmp) {_nicknameTmp = nicknameTmp;}

// Print info

void Clients::printInfo()
{
    std::cout << "Nickname : " << _nickname << std::endl;
    std::cout << "Username : " << _username << std::endl;
    std::cout << "Pass : " << _pass << std::endl;
    std::cout << "fd : " << _fd << std::endl;
    std::cout << "Ip Address : " << _addrIp << std::endl;
}

void Clients::printChannels()
{
    std::cout << "Channels size : " << _channels.size() << std::endl;
    for (std::map<std::string, Channels>::iterator it = _channels.begin(); it != _channels.end(); ++it)
    {
        std::cout << "Channel : " << it->first << std::endl;
    }
}

std::vector<std::string> parseLine(std::string line)
{
    std::vector<std::string> tokens;
    std::istringstream iss(line);
    std::string part;
    while (std::getline(iss, part, '\n'))
	{
        size_t pos = part.find('\r');
        if (pos != std::string::npos)
            part = part.substr(0, pos);
        pos = part.find(' ');
        if (pos != std::string::npos)
        {
            tokens.push_back(part.substr(0, pos));
            tokens.push_back(part.substr(pos + 1));
        }
        else
            tokens.push_back(part);
    }
    return (tokens);
}

std::vector<int> passMode(std::vector<std::string> tokens, Clients &client, Server &server, std::vector<int> &flags)
{
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        if (tokens[i].find("PASS") != std::string::npos && flags[0] < 0)
        {
            if (tokens[i + 1] != server.getPassword())
            {
                sendCmd(ERR_PASSWDMISMATCH(tokens[i + 1]), client);
                client.setIsRegistered(false);
                flags[0] = -1; // PASS
                flags[1] = -1; // USER
                flags[2] = -1; // NICK
                flags[3] = 0; // BOOL FALSE
                return (flags);
            }
            flags[0] = i; // PASS
            client.setPass(tokens[i + 1]);
            flags[3] = 1; // BOOL TRUE
            return (flags);
        }
        else if (flags[0] >= 0)
        {
            flags[3] = 1; // BOOL TRUE
            return (flags);
        }
    }
    flags[3] = 0; // BOOL TRUE
    return (flags);
}

std::vector<int> userMode(std::vector<std::string> tokens, Clients &client, Server &server, std::vector<int> &flags)
{
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        if (tokens[i].find("USER") != std::string::npos && flags[1] < 0)
        {
            if (client.getPass() == "")
            {
                sendCmd("ERROR :You must confirm your password before registering\r\n", client);
                client.setIsRegistered(false);
                flags[0] = -1; // PASS
                flags[1] = -1; // USER
                flags[2] = -1; // NICK
                flags[3] = 0; // BOOL FALSE
                return (flags); 
            }
            if (User(tokens[i + 1], client, server) == false)
                return (flags);
            flags[1] = i; // USER
            flags[3] = 1; // BOOL TRUE
            return (flags);
        }
        else if (flags[1] >= 0)
        {
            flags[3] = 1; // BOOL TRUE
            return (flags);
        }
    }
    flags[3] = 0; // BOOL FALSE
    return (flags);
}

std::vector<int> nickMode(std::vector<std::string> tokens, Clients &client, Server &server, std::vector<int> &flags)
{
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        if (tokens[i].find("NICK") != std::string::npos && flags[2] < 0)
        {
            if (client.getPass() == "")
            {
                sendCmd("ERROR :You must confirm your password before registering\r\n", client);
                client.setIsRegistered(false);
                flags[0] = -1; // PASS
                flags[1] = -1; // USER
                flags[2] = -1; // NICK
                flags[3] = 0; // BOOL FALSE
                return (flags);
            }
            if (tokens[i + 1].find(" ") != std::string::npos)
            {
                sendCmd(ERR_NONICKNAMEGIVEN(client.getNickname()), client);
                return (flags);
            }
            if (NickInit(tokens[i + 1], client, server) == false)
                return (flags);
            flags[2] = i; // NICK
            flags[3] = 1; // BOOL TRUE
            return (flags);
        }
        else if (flags[2] >= 0)
        {
            flags[3] = 1; // BOOL TRUE
            return (flags);
        }
    }
    flags[3] = 0; // BOOL FALSE
    return (flags);
}

std::vector<int> initializeFlags()
{
    std::vector<int> temp(4, -1);
    temp[3] = 0;
    return (temp);
}

bool Clients::initClients(std::string line, Server &server)
{
    static std::vector<int> flags = initializeFlags();
    std::vector<std::string> tokens = parseLine(line);

    flags = passMode(tokens, *this, server, flags);
    flags = userMode(tokens, *this, server, flags);
    flags = nickMode(tokens, *this, server, flags);
    if (flags[3] == 0)
        return (false);
    if (((flags[1] > -1 || flags[2] > -1) || (flags[1] > -1 && flags[2] > -1)) && flags[0] == -1)
    {
        sendCmd(ERR_PASSWDMISMATCH(getNickname()), *this);
        _isRegistered = false;
        flags[0] = -1; 
        flags[1] = -1;
        flags[2] = -1;
        flags[3] = 0;
        return (true);
    }
    if (flags[0] > -1 && flags[1] > -1 && flags[2] > -1)
    {
        if (getNicknameTmp() != "")
        {
            sendCmd(RPL_CMD_NICK(getNicknameTmp(), getUsername(), getAddrIp(), getNickname()), *this);
            setNicknameTmp("");
        }
        else
            sendCmd(RPL_CMD_NICK(getNickname(), getUsername(), getAddrIp(), getNickname()), *this);
        sendCmd(RPL_MOTD_START(getNickname()), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "Welcome to the FT_IRCheat"), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "This is the server of the FT_IRCheat"), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "To join a channel, you can use the command : \"/join <#channel>,<#channel>... <key>,<key>...\" on Hexchat and \"JOIN <#channel>,<#channel>... <key>,<key>...\" on NC"), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "To send a message, you can juste type your message in the right channel on Hexchat and \"PRIVMSG <nickname> :<message>\" on NC"), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "To change the mode of a channel, you can use the command : \"/mode <channel> <mode> <target>\" on Hexchat and \"MODE <channel> <mode> <target>\" on NC"), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "The following modes are available : <o> <i> <t> <k> <l>"), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "To kick someone, you can use the command : \"/kick <channel> <nickname> <reason>\" on Hexchat and \"KICK <channel> <nickname> :<reason>\" on NC"), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "To Invite someone, you can use the command : \"/invite <nickname> <channel>\" on Hexchat and \"INVITE <nickname> <channel>\" on NC"), *this);
        sendCmd(RPL_MOTD_MSG(getNickname(), "To change the topic of a channel, you can use the command : \"/topic <channel> <topic>\" on Hexchat and \"TOPIC <channel> <topic>\" on NC"), *this);
        sendCmd(RPL_MOTD_END(getNickname()), *this);
        setAddrIp(server.getAddrIp());
        _isRegistered = true;
        flags[0] = -1;
        flags[1] = -1;
        flags[2] = -1;
        return (true);
    }
    return (false);
}
