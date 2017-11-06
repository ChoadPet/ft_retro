/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemies.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:36:18 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/11/05 19:19:08 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemies.class.hpp"

Enemies::Enemies() : GameEntity('*', true) {

}

Enemies::~Enemies() {

}

void	Enemies::setXY(int maxx, int maxy) {
	this->_x = rand() % maxx;
	this->_y = (rand() % maxy) - maxy;
}

void	Enemies::foul(int maxy, Player & player, bool *exit, int seconds) {
	if (this->_is) {
		if (this->_y + 2 < maxy - 4)
			mvaddch(this->_y + 2, this->_x, ' ');
		if (this->_y + 1 < maxy - 4) {
			mvaddch(this->_y + 1, this->_x, ' ');
			mvaddch(this->_y + 1, this->_x + 1, ' ');
			mvaddch(this->_y + 1, this->_x - 1, ' ');
		}
			mvaddch(this->_y, this->_x, ' ');
		this->_y += 1;
        if (seconds > 10) {
            this->_x += rand() % 5 - 2;
        }
		if ((this->_x == player.getX() && this->_y + 2 == player.getY()) ||
			(this->_x == player.getX() && this->_y == player.getY()) ||
			(this->_x == player.getX() && this->_y + 1 == player.getY()) ||
			(this->_x + 1 == player.getX() && this->_y + 1 == player.getY()) ||
			(this->_x - 1 == player.getX() && this->_y + 1 == player.getY())) {
			player.setH(player.getH() - 25);
			attron(COLOR_PAIR(6));
			if (player.getH() <= 0) {
				*exit = true;
				mvprintw(10, 10, "GGGGGGGGGGGGG");
				mvprintw(11, 10, "GGG::::::::::::G");
				mvprintw(12, 10, "GG:::::::::::::::G");
				mvprintw(13, 10, "G:::::GGGGGGGG::::G");
				mvprintw(14, 10, "G:::::G       GGGGGG  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee            ooooooooooo vvvvvvv           vvvvvvv eeeeeeeeeeee    rrrrr   rrrrrrrrr");
				mvprintw(15, 10, "G:::::G                a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::ee        oo:::::::::::oov:::::v         v:::::vee::::::::::::ee  r::::rrr:::::::::r");
				mvprintw(16, 10, "G:::::G                aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::::ee     o:::::::::::::::ov:::::v       v:::::ve::::::eeeee:::::eer:::::::::::::::::r");
				mvprintw(17, 10, "G:::::G    GGGGGGGGGG           a::::a m::::::::::::::::::::::me::::::e     e:::::e     o:::::ooooo:::::o v:::::v     v:::::ve::::::e     e:::::err::::::rrrrr::::::r");
				mvprintw(18, 10, "G:::::G    G::::::::G    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e     o::::o     o::::o  v:::::v   v:::::v e:::::::eeeee::::::e r:::::r     r:::::r");
				mvprintw(19, 10, "G:::::G    GGGGG::::G  aa::::::::::::a m::::m   m::::m   m::::me:::::::::::::::::e      o::::o     o::::o   v:::::v v:::::v  e:::::::::::::::::e  r:::::r     rrrrrrr");
				mvprintw(20, 10, "G:::::G        G::::G a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee       o::::o     o::::o    v:::::v:::::v   e::::::eeeeeeeeeee   r:::::r");
				mvprintw(21, 10, "G:::::G       G::::Ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e                o::::o     o::::o     v:::::::::v    e:::::::e            r:::::r");
				mvprintw(22, 10, "G:::::GGGGGGGG::::Ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e               o:::::ooooo:::::o      v:::::::v     e::::::::e           r:::::r");
				mvprintw(23, 10, "GG:::::::::::::::Ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee       o:::::::::::::::o       v:::::v       e::::::::eeeeeeee   r:::::r");
				mvprintw(24, 10, "GGG::::::GGG:::G a::::::::::aa:::am::::m   m::::m   m::::m  ee:::::::::::::e        oo:::::::::::oo         v:::v         ee:::::::::::::e   r:::::r");
				mvprintw(25, 10, "GGGGGG   GGGG  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee          ooooooooooo            vvv            eeeeeeeeeeeeee   rrrrrrr");
			}
		}
		this->_is = this->_y > maxy - 5 ? false : true;
		attron(COLOR_PAIR(3));
		if (this->_y + 2 < maxy - 4)
			mvaddch(this->_y + 2, this->_x, this->_ch);
		if (this->_y + 1 < maxy - 4) {
			mvaddch(this->_y + 1, this->_x, '|');
			mvaddch(this->_y + 1, this->_x + 1, '>');
			mvaddch(this->_y + 1, this->_x - 1, '<');
		}
		if (this->_is)
			mvaddch(this->_y, this->_x, '^');
	}
}

void	Enemies::setIs(bool is) {
	this->_is = is;
}
