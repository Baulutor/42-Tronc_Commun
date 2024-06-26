/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:10 by nibernar          #+#    #+#             */
/*   Updated: 2024/06/04 13:37:22 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cmd.hpp"

void Pong(std::string cmd, Clients& client, Server& server)
{
    (void) server;
    std::vector<std::string> splited = split(cmd, ' ');
    if (splited.size() < 2) {
        std::cerr << "error arg" << std::endl;
        return ;
    }
    sendCmd(RPL_CMD_PONG(client.getNickname(), client.getUsername(), client.getAddrIp(), splited[1]), client);
}