/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kill.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:01 by kmorin            #+#    #+#             */
/*   Updated: 2024/02/06 10:33:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Commands/Kill.hpp"

Kill::Kill(void) {}

Kill::~Kill(void) {}

/**
 * https://datatracker.ietf.org/doc/html/rfc2812#section-3.7.1
 *
 * Parameters:
 * 		<nickname> <comment>
 *
 * If the number of parameters is not valid, ERR_NEEDMOREPARAMS
 * If the client is not an operator, ERR_NOPRIVILEGES
 * If the nickname of the client to be killed is not found, ERR_NOSUCHNICK
 * Else, the client receive a custom message explaining why he has been killed and the server closes the connection.
 *
 * @param server The server Object.
 * @param msg The message object containing the command and parameters.
 * @param client The client object.
*/
void	Kill::execute(Server* server, t_Message* msg, Client* client) {

	if (msg->params.size() < 2 || !msg->params[1].compare(":")) {
		std::string	errNeedMoreParams = ERR_NEEDMOREPARAMS(client->getAddress(), client->getNick(), msg->command);
		client->sendMessage(errNeedMoreParams);
		return;
	}
	else if (!client->isOperator()) {
		std::string	errNoPrivileges = ERR_NOPRIVILEGES(client->getAddress(), client->getNick());
		client->sendMessage(errNoPrivileges);
		return;
	}

	Client*	clientToKill = server->getClient(msg->params[0]);

	if (!clientToKill) {
		std::string	errNoSuchNick = ERR_NOSUCHNICK(client->getAddress(), client->getNick(), msg->params[0]);
		client->sendMessage(errNoSuchNick);
	}
	else {
		std::string	params = getParams(msg, 1);
		if (params.empty() == false && params[0] == ':')
			params.erase(0, 1);
		std::string	rplKill = "You were removed from the server because " + params + "\r\n";
		clientToKill->sendMessage(rplKill);
		clientToKill->setDeconnection(true);
	}
}
