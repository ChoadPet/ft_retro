// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:56:35 by vpoltave          #+#    #+#             //
//   Updated: 2017/11/05 19:56:36 by vpoltave         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "game.h"
#include "Player.class.hpp"

Player::Player(char ch, int x, int y) : GameEntity(x, y, ch), _helth(100), _score(0) {
	mvaddch(this->_y, this->_x, this->_ch);
	srand(time(0));
}

int		Player::getH() {
	return (this->_helth);
}

int		Player::getS() {
	return this->_score;
}


void	Player::setH(int h) {
	this->_helth = h;
}

void	Player::setS(int s) {
	this->_score = s;
}


void	Player::move(int key, int maxx, int maxy) {
	mvaddch(this->_y, this->_x, ' ');
	switch  (key) {
		case KEY_UP:
		case 'w':
			this->_y -= 1;
			break;
		case KEY_DOWN:
		case 's':
			this->_y += 1;
			break;
		case KEY_LEFT:
		case 'a':
			this->_x -= 1;
			break;
		case KEY_RIGHT:
		case 'd':
			this->_x += 1;
			break;
		default:
			break;
	}
	attron(COLOR_PAIR(5));
	this->_y = this->_y > maxy - 5 ? maxy - 5 : this->_y;
	this->_y = this->_y < 0 ? 0 : this->_y;
	this->_x = this->_x > maxx ? maxx : this->_x;
	this->_x = this->_x < 0 ? 0 : this->_x;
	mvaddch(this->_y, this->_x, this->_ch);
	refresh();
}
