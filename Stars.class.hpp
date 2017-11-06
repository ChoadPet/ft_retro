/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:15:26 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/11/05 16:00:36 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_CLASS_H
#define STARS_CLASS_H

#include "game.h"

class	Stars  : public GameEntity {

public:

	Stars();
	Stars(char c, bool is);
	~Stars();

	void	setXY(int maxx, int maxy);
	void	foul(int maxy);

};


#endif
