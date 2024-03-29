/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:32:35 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/24 15:12:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef QUIT_HPP
#define QUIT_HPP

#include "ACommand.hpp"

class Quit : public ACommand {

	public:
		Quit(void);
		~Quit(void);

		virtual void	execute(Server* server, t_Message* msg, Client* client);
};

#endif //QUIT_HPP
