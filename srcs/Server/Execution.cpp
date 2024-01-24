/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Execution.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:54:28 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/24 14:58:44 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/*
	! * msg is new
*/
void	Server::execCommand(t_Message* msg, Client* client) {

	(void) msg;
	(void) client;

	if (msg->command[0] == '/')
		msg->command = msg->command.erase(0, 1);

	if (msg->command.empty())
		return;

	std::cout << msg->command << std::endl;

	for (size_t i = 0; i < msg->command.size(); i++)
		toupper(msg->command[i]);

	std::cout << msg->command << std::endl;

	// Compare the command with the map of commands and return if not found
	if (_commands.find(msg->command) == _commands.end())
		return;

	ACommand*	cmd = _commands.at(msg->command);

	cmd->execute(this, msg, client);
}
