/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clients.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:27:47 by bfaure            #+#    #+#             */
/*   Updated: 2024/06/04 13:19:50 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENTS_HPP
# define CLIENTS_HPP

# include "FT_IRCheat.hpp"
# include "Channels.hpp"
# include <poll.h>
# include <map>
#include "Server.hpp"

class Server;

class Channels;

class Clients
{
    public:
        Clients();
        ~Clients();
        
        void setFd(int fd);
        void setAddrIp(std::string addrIp);
        void setNickname(std::string nickname);
        void setUsername(std::string username);
        void setPass(std::string pass);
        void setIsRegistered(bool isRegistered);
        void setBuffer(char* buffer);
        void setBufferTmp(char* bufferTmp);
        void setNicknameTmp(std::string nicknameTmp);

        bool initClients(std::string line, Server &server);

        int getFd() const;
        std::string getAddrIp() const;
        std::string getNickname() const;
        std::string getUsername() const;
        std::string getPass() const;
        bool getIsRegistered() const;
        char* getBuffer();
        char* getBufferTmp();
        std::string getNicknameTmp() const;

        std::map<std::string, Channels>& getChannelsClient();
        std::map<std::string, Channels>& getChannelsInvite();

        void printInfo();
        void printChannels();

    private:
        std::string _nickname;
        std::string _nicknameTmp;
        std::string _username;
        std::string _pass;
        bool _isRegistered;
        int _fd;
        std::string _addrIp;
        char _buffer[512];
        char _bufferTmp[512];
        std::map<std::string, Channels> _channelsInvite;

        std::map<std::string, Channels> _channels;

};

#endif