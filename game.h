/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:13:26 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/11/05 19:59:34 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H
#include <string>
#include <ctime>
#include <ncurses.h>
#include <cstdint>
#include <unistd.h>
#include <iostream>
#include "GameEntity.class.hpp"
#include "Player.class.hpp"
#include "Enemies.class.hpp"
#include "Bulet.class.hpp"
#include "Stars.class.hpp"

#define STAR 25
#define BULLETS 50
#define ENEMIES 20

class	Game {

public:
		
	WINDOW* wnd;
	clock_t start;

	Game();
	Game(Game const & obj);
	~Game();

	Game &operator=(Game const &rhs);

	int		getMx();
	int		getMy();
	void	close();
	void	init_colors();
	void	init_ncu();

private:

	int	_wx;
	int	_wy;

};

#endif
