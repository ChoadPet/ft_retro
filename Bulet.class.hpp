/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bulet.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:34:51 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/11/05 19:09:33 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULET_CLASS_H
#define BULET_CLASS_H

#include "game.h"

class	Enemies;

class	Bullet  : public GameEntity {
	
public:

	Bullet();
	Bullet(int x, int y, char ch);
	~Bullet();

	void	fly();
	void	fight(Enemies & enemies, Player & player);

};

#endif
