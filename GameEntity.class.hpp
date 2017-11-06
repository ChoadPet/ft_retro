// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameEntity.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:57:23 by vpoltave          #+#    #+#             //
//   Updated: 2017/11/05 19:57:24 by vpoltave         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP

//#include "game.h"

class GameEntity {

protected:

	int		_x, _y;
	char	_ch;
	bool	_is;

public:

	GameEntity();
	GameEntity(int x, int y, char ch);
	GameEntity(int x, int y, char c, bool is);
	GameEntity(char c, bool is);
	GameEntity(GameEntity const & obj);
	~GameEntity();

	GameEntity &operator=(GameEntity const & obj);

	void	setX(int x);
	void	setY(int y);
	void	setCh(char c);

	void	set();
	bool	get();
	bool	getIs();

	int		getX();
	int		getY();
	char	getCh();

	void	rand_cr(int maxx);

};


#endif
