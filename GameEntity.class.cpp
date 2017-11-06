// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameEntity.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:57:09 by vpoltave          #+#    #+#             //
//   Updated: 2017/11/05 19:59:45 by vpoltave         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstdlib>
#include "GameEntity.class.hpp"

GameEntity::GameEntity() {


}

GameEntity::GameEntity(int x, int y, char ch)
		: _x(x), _y(y), _ch(ch) {

}

GameEntity::GameEntity(int x, int y, char c, bool is)
		: _x(x), _y(y), _ch(c), _is(is) {

}

GameEntity::GameEntity(char c, bool is)
	: _ch(c), _is(is)
{


}

GameEntity::GameEntity(GameEntity const & obj) {

	*this = obj;
}

GameEntity::~GameEntity() {


}

GameEntity & GameEntity::operator=(GameEntity const & obj) {

	if (this != &obj)
	{
		_x = obj._x;
		_y = obj._y;
		_ch = obj._ch;
		_is = obj._is;
	}
	return *this;
}

void	GameEntity::rand_cr(int maxx) {
	this->_x = rand() % maxx;
	this->_y = 0;
	this->_is = true;
}

void	GameEntity::setX(int x) {

	_x = x;
}
void	GameEntity::setY(int y) {

	_y = y;
}
void	GameEntity::setCh(char c) {

	_ch = c;
}

void	GameEntity::set() {
	this->_is = true;
}

bool	GameEntity::get() {
	return this->_is;
}

int		GameEntity::getX() {

	return _x;
}
int		GameEntity::getY() {

	return _y;
}

char	GameEntity::getCh() {

	return _ch;
}

bool	GameEntity::getIs() {
	return this->_is;
}
