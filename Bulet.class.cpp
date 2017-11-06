// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bulet.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:56:22 by vpoltave          #+#    #+#             //
/*   Updated: 2017/11/05 20:54:35 by rpikaliu         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "game.h"

Bullet::Bullet() : GameEntity(0, 0, '|', false) {
}

Bullet::~Bullet() {

}

void	Bullet::fly() {
	if (this->_is == true) {
		mvaddch(this->_y, this->_x, ' ');
		this->_y -= 1;
		if (this->_y < 0)
			this->_is = false;
		attron(COLOR_PAIR(2));
		mvaddch(this->_y, this->_x, this->_ch);
	}
}

void	Bullet::fight(Enemies & enemies, Player & player) {
	if ((this->_x == enemies.getX() && this->_y == enemies.getY() + 2) ||
		(this->_x == enemies.getX() + 1 && this->_y == enemies.getY() + 1)  ||
		(this->_x == enemies.getX() - 1 && this->_y == enemies.getY() + 1)) {
		mvaddch(enemies.getY(), enemies.getX(), ' ');
		mvaddch(enemies.getY() + 1, enemies.getX(), ' ');
		mvaddch(enemies.getY() + 1, enemies.getX() - 1, ' ');
		mvaddch(enemies.getY() + 1, enemies.getX() + 1, ' ');
		mvaddch(enemies.getY() + 2, enemies.getX(), ' ');
		this->_is = false;
		player.setS(player.getS() + 10);
		enemies.setIs(false);
	}
}
