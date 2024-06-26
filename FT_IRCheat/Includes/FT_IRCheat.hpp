/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_IRCheat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:47:35 by bfaure            #+#    #+#             */
/*   Updated: 2024/05/07 11:47:35 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRCHEAT_HPP
# define FT_IRCHEAT_HPP

# include <string>
# include <cstdlib>
# include <iostream>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <vector>
# include <sstream>
# include "RPL.hpp"
# include "Clients.hpp"
# include <map>

class Clients;

class Channels;

class Server;

std::string intToString(int value);
std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> splitEOF(const std::string &s, char delim);
std::map<int, Clients>::iterator findClientByName(std::string nickname, std::map<int, Clients>& clientsServer);
std::map<std::string, Channels>::iterator findChannelByName(std::string channelName, std::map<std::string, Channels>& channelsServer); // VERIF
std::vector<std::string> splitInit(const std::string &line, char delim);
void signalHandler(int signum);
void sendCmd(const std::string& cmd, Clients &client);
void sendBroadcastChannel(const std::string& cmd, Channels& channel);
void sendBroadcastMSG(const std::string& cmd, Channels& channel, Clients& client);
void sendBroadcastServer(const std::string& cmd, Server& server);
void NameLstUpdate(Clients& client, Channels& channel);
void signalHandler(int signum);
int findFdClientByName(std::string nickname, std::map<int, Clients>& clientsServer);
#endif
