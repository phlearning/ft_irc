/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:49:28 by pvong             #+#    #+#             */
/*   Updated: 2024/01/19 11:29:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "ft_irc.hpp"
#include "Client.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <map>
#include <list>
#include <utility>
#include <poll.h>

#define MAX_SOCKETS 10
#define ERR_MAX_CLIENTS "Error: maximum number of clients reached."
#define BUFF_SIZE 4096

struct Message {
	std::string	prefix;
	std::string	name;
	std::string	message;
};

class Server {

	public:
		Server(const std::string port, const std::string password);
		~Server();

		void	run();
		void	deleteClient(std::vector<pollfd> &pollfds, int clientSocketFd);
		void	handleMaxClient(int clientSocketFd);
		void	parseMessage(std::string message, int clientSocketFd);
		void	fillUserInfo(std::map<const int, Client> &clients, int clientSocketFd, std::string message);

	private:
		struct sockaddr_in			_serverAddress;
		std::map<const int, Client>	_clients;

		int			_serverSocketFd;

		std::string	_port;
		std::string	_password;
		std::string	_version;
		std::string	_name;

/* ------------------------------ REGISTRATION ------------------------------ */
// TODO: work on the parsing to get the user info -> NICK, USER
// link parsing: https://tools.ietf.org/html/rfc2812#section-2.3.1
// TODO: work on the commands, PASS, NICK, USER -> RPL_WELCOME
// link welcome: https://tools.ietf.org/html/rfc2812#section-5.1
// TODO: work on the replies -> RPL_WELCOME, RPL_YOURHOST, RPL_CREATED, RPL_MYINFO

// TODO: ADD a map of channels

};

#endif
