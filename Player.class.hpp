/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:53:57 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/11/05 19:13:35 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include "game.h"

class	Player : public GameEntity {

public:

	Player(char ch, int x, int y);
			
	void	move(int key, int maxx, int maxy);
	int		getH();
	int		getS();

	void	setH(int h);
	void	setS(int s);


private:

	int		_helth;
	int		_score;

};

#endif
