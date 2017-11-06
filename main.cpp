/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:38:44 by rpikaliu          #+#    #+#             */
//   Updated: 2017/11/05 19:58:31 by vpoltave         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include	<ncurses.h>
#include	"game.h"

int  main () {

	Game game;

	int i = 0;
	int k = 0;
	bool pause = false;
	bool exit = false;
	float times;
	int seconds = 0;

	Player player('A', game.getMx() / 2, game.getMy() - 8);

	Bullet bullet[BULLETS];
	Stars stars[STAR];
	Enemies enemies[ENEMIES];

	for(int e = 0; e < ENEMIES; e++)
		enemies[e].setXY(game.getMx(), game.getMy());
	for (int n = 0; n < STAR; n++)
		stars[n].setXY(game.getMx(), game.getMy());
	while (1) {
		int key = wgetch(game.wnd);
		if (key == 'p' && !exit)
			pause = pause == true ? false : true;
		if (!pause && !exit) {
	  		if (key == ' ') {
				bullet[i].set();
				bullet[i].setX(player.getX());
				bullet[i].setY(player.getY());
				i++;
				i = i < BULLETS ? i : 0;
			}
			for (int n = 0; n < STAR; n++) {
				if (!pause)
					stars[n].foul(game.getMy());
				if (stars[n].getIs() == false)
					stars[n].rand_cr(game.getMx());
			}
			if (k % 10 == 0) {
				for (int e = 0; e < ENEMIES; e++) {
					if (!pause)
						enemies[e].foul(game.getMy(), player, &exit, seconds);
					if (enemies[e].getIs() == false)
						enemies[e].rand_cr(game.getMx());
				}
				k = 1;
			}
			for (int j = 0; j < BULLETS; j++) {
				if (bullet[j].get()) {
					bullet[j].fly();
					for (int e = 0; e < ENEMIES; e++)
						bullet[j].fight(enemies[e], player);
				}
			}
			player.move(key, game.getMx(), game.getMy());
		}
		if (key == 'q') {
			game.close();
			return 0;
		}
		times = (int)(clock() - game.start) / 30000;
		if ((int)times > seconds && !exit)
			seconds++;
		attron(COLOR_PAIR(1));
		mvprintw(game.getMy() - 2, 9,  "HEALTH:    ");
		mvprintw(game.getMy() - 2, 17,  "%d", player.getH());
		mvprintw(game.getMy() - 2, 30,  "SCORE:    ");
		mvprintw(game.getMy() - 2, 37,  "%d", player.getS());
		mvprintw(game.getMy() - 2, 50,  "TIME:    ");
		mvprintw(game.getMy() - 2, 56,  "%d", seconds);
        mvprintw(game.getMy() - 2, 67,  "LEVEL:    ");
        mvprintw(game.getMy() - 2, 74,  "%d", seconds > 10 ? 2 : 1);
		usleep(10000);
 		refresh();
		k++;
	}
	return 0;
}
