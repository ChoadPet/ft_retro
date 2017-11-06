/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:15:38 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/11/05 18:36:55 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stars.class.hpp"

Stars::Stars() : GameEntity('.', true) {
}

Stars::~Stars() {

}

void	Stars::setXY(int maxx, int maxy) {
	this->_x = rand() % maxx;
	this->_y = rand() % maxy - 5;
}

void	Stars::foul(int maxy) {
	if (this->_is) {
		mvaddch(this->_y, this->_x, ' ');
		this->_y += 1;
		this->_is = this->_y > maxy - 5 ? false : true;
		attron(COLOR_PAIR(1));
		if (this->_is)
			mvaddch(this->_y, this->_x, this->_ch);
	}	
}
