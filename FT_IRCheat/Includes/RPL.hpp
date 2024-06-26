/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:57:44 by bfaure            #+#    #+#             */
/*   Updated: 2024/06/04 13:23:38 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPL_HPP
# define RPL_HPP

# define ERR_USERONCHANNEL(ClientNickname, nickname, Channel) (ClientNickname + " " + nickname + " " + Channel + " :is already on channel\r\n")
# define ERR_CHANOPRIVSNEEDED(nickname, channel) (":server 482 " + nickname + " " + channel + " :You\'re not channel operator\r\n")
# define RPL_INVITING(client, channel, nick) (":server 341 " + client + " " + nick + " " + channel + "\r\n")
# define RPL_INVITE_MESSAGE(Nickname, Channel, Username, Hostname, Target) (":" + Nickname + "!" + Username + "@" + Hostname + " INVITE " + Target + " " + Channel + "\r\n")
# define RPL_NOTOPIC(channelName) (":server 331 " + channelName + " :No topic is set\r\n")
# define RPL_TOPIC(channelName, topicMessage) (":server 332 " + channelName + " : " + topicMessage + "\r\n")
# define RPL_QUIT_CHANNEL(Nickname, Username, Hostname, Channel, reason) (":" + Nickname + "!" + Username + "@" + Hostname + " QUIT " + Channel + " " + reason + "\r\n")
# define RPL_CMD_JOIN(Nickname, Username, Hostname, Channel) (":" + Nickname + "!" + Username + "@" + Hostname + " JOIN :" + Channel + "\r\n")
# define RPL_CMD_JOIN_KEY(Nickname, Username, Hostname, Channel, Key) (":" + Nickname + "!" + Username + "@" + Hostname + " JOIN :" + Channel + " " + Key + "\r\n")
# define RPL_JOIN_ERROR_NAME(Nickname, Channel) (":server 403 " + Nickname + " :💩 The channel (" + Channel + ") name must start with a #. Example : #" + Channel  + "\r\n")
# define RPL_JOIN_NOTICE(Nickname, Channel) (":server NOTICE " + Channel + " :" + Nickname + " Just join the channel" + "\r\n")
# define RPL_JOIN_ERROR_KEY(Nickname, Channel) (":server 475 " + Nickname + " " + Channel + " :Cannot join channel (+k)" + "\r\n")
# define ERR_INVITEONLYCHAN(Nickname, Channel) (":server 473 " + Nickname + " " + Channel + " :Cannot join channel (+i)" + "\r\n")
# define ERR_CHANNELFULL(Nickname, Channel) (":server 471 " + Nickname + " " + Channel + " :Cannot join channel (+l)" + "\r\n")
# define RPL_CMD_PONG(Nickname, Username, Hostname, Key) (":" + Nickname + "!" + Username + "@" + Hostname + " PONG " + Key + "\r\n")
# define RPL_CMD_KICK(Nickname, Username, Hostname, Channel, target, com) (":" + Nickname + "!" + Username + "@" + Hostname + " KICK " + Channel + " " + target + " " + com + "\r\n")
# define RPL_CMD_TOPIC(Nickname, Channel, Topic) (":server 332 " + Nickname + " " + Channel + " :" + Topic + "\r\n")
# define RPL_CMD_NAME_LST_START(Nickname, Channel, user) (":server 353 " + Nickname + " = " + Channel + " :" + user + "\r\n")
# define RPL_CMD_NAME_LST_END(Nickname, channel) (":server 366 " + Nickname + " " + channel + " :End of /NAMES list" + "\r\n")
# define ERR_NEEDMOREPARAMS(Nickname, cmd) (":server 461 " + Nickname + " " + cmd + " :Not enough parameters\r\n")
# define RPL_WELCOME(Nickname, Username, Hostname) (":server 001 " + Nickname + " :Welcome to the Internet Relay Network " + Username + "@" + Hostname + "\r\n")
# define RPL_MOTD_START(Nickname) (":server 375 " + Nickname + " :- Message of the day -" + "\r\n")
# define RPL_MOTD_MSG(Nickname, MSG) (":server 372 " + Nickname + " :" + MSG + "\r\n")
# define RPL_MOTD_END(Nickname) (":server 376 " + Nickname + " :End of /MOTD command" + "\r\n")
# define RPL_CMD_PRIVMSG(Nickname, Username, Hostname, Channel, Message) (":" + Nickname + "!" + Username + "@" + Hostname + " PRIVMSG " + Channel + " :" + Message + "\r\n")
# define RPL_ERROR_NICKNAME_IN_USE(Nickname, Nickname2) (":server 433 " + Nickname + " " + Nickname2 + " :Nickname is already in use" + "\r\n")
# define RPL_CMD_NICK(Nickname, Username, Hostname, NewNickname) (":" + Nickname + "!" + Username + "@" + Hostname + " NICK " + NewNickname + "\r\n")
# define RPL_CMD_MODE(Nickname, Username, Hostname, Channel, Mode, Target, Args) (":" + Nickname + "!" + Username + "@" + Hostname + " MODE " + Channel + " " + Mode + " " + Target + " " + Args + "\r\n")
# define ERR_NOSUCHNICK(Nickname, User) (":server 401 " + Nickname + " " + User + " :No such user" + "\r\n")
# define RPL_UMODEIS(Nickname, User, Mode) (":server 221 " + Nickname + " " + User + " :" + Mode + "\r\n")
# define ERR_UMODEUNKNOWNFLAG(Nickname, Mode) (":server 501 " + Nickname + " " + Mode + " :Unknown mode" + "\r\n")
# define ERR_NOSUCHCHANNEL(Nickname, Channel) (":server 403 " + Nickname + " " + Channel + " :No such channel" + "\r\n")
# define RPL_CHANNELMODEIS(Nickname, Channel, Mode) (":server 324 " + Nickname + " " + Channel + " " + Mode + "\r\n")
# define ERR_INVALIDMODEPARAM(Nickname, Mode, Param) (":server 696 " + Nickname + " " + Mode + " " + Param + " :Invalid mode parameter" + "\r\n")
# define ERR_NOTONCHANNEL(Nickname, Channel) (":server 442 " + Nickname + " " + Channel + " :You are not on that channel" + "\r\n")
# define ERR_NOTCHANOP(Nickname, channel) (":server 482 " + Nickname + " " + channel + " :You're not channel operator\r\n")
# define ERR_USERNOTFOUND(client, Nickname, channel) (":server 441 " + client + " " + Nickname + " " + channel + " :They aren't on that channel\r\n")
# define ERR_PASSWDMISMATCH(client) (":server 464 " + client + " :Password incorrect \r\n")
# define RPL_DISCONNECT(Nickname, Username, Hostname) (":" + Nickname + "!" + Username + "@" + Hostname + " QUIT :" + "\r\n")
# define ERR_NOTREGISTERED(Nickfd)(":server 451 " + Nickfd + ":You have not registered" + "\r\n")
# define RPL_KICK_NOTICE(Nickname, Channel) (":server NOTICE " + Channel + " :" + Nickname + " cannot kick yourself" + "\r\n")
# define ERR_ALREADYREGISTERED(Nickname) (":server 462 " + Nickname + " :You may not reregister\r\n")
# define RPL_ISUPPORT(Nickname, token) (":server 005 " + Nickname + " " + token + " :are supported by this server" + "\r\n")
# define ERR_CANNOTSENDTOCHAN(Nickname, Channel) (":server 404 " + Nickname + " " + Channel + " :Cannot send to channel\r\n")
# define ERR_ERRONEUSNICKNAME(Nickname, Nickname2) (":server 432 " + Nickname + " " + Nickname2 + " :Erroneus nickname" + "\r\n")
# define ERR_NONICKNAMEGIVEN(Nickname) (":server 431 " + Nickname + " :No nickname given" + "\r\n")
# define RPL_PART(Nickname, Channel, Username, Hostname) (":" + Nickname + "!" + Username + "@" + Hostname + " PART " + Channel + "\r\n")

#endif

