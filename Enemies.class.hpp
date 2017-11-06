/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemies.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:37:37 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/11/05 19:18:31 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_CLASS_H
#define ENEMIES_CLASS_H

#include "game.h"

class	Enemies  : public GameEntity {

public:

	Enemies();
	Enemies(char c, bool is);
	~Enemies();

	void	setXY(int maxx, int maxy);
	void	foul(int maxy, Player & player, bool *exit, int seconds);
	void	setIs(bool is);


};


#endif
