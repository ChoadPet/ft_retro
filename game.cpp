/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:17:11 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/11/05 18:36:10 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

Game::Game() {

	int maxx;
	int maxy;

	init_ncu();
	if(!has_colors()) {
        endwin();
        printf("ERROR: Terminal does not support color.\n");
        exit(1);
    }
	init_colors();
	getmaxyx(wnd, maxy, maxx);
	this->_wx = maxx - 1;
	this->_wy = maxy - 1;
	attron(COLOR_PAIR(4));
	while (maxx--)
		mvaddch(maxy - 5, maxx, '_');
	start = clock();
}

Game::Game(Game const & obj) {

	*this = obj;
}

Game::~Game() {

}

Game & Game::operator=(Game const &rhs) {

	if (this != &rhs)
	{
		_wx = rhs._wx;
		_wy = rhs._wy;
	}
	return *this;
}

void	Game::init_ncu() {

	this->wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	keypad(wnd, true);
	nodelay(wnd, true);
	curs_set(0);

}

void	Game::init_colors() {

	start_color ();
	attron(A_BOLD);
	attroff(A_BOLD);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	wbkgd(wnd, COLOR_PAIR(1));
}

void	Game::close() {
    endwin();
}

int		Game::getMx() {
	return this->_wx;
}

int		Game::getMy() {
	return this->_wy;
}
