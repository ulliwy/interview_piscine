/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:17:36 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/24 10:06:24 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <string.h>

/*--------------------------------
  !! required structure
--------------------------------*/

struct  s_art {
    char *name;
    int price;
};


/*--------------------------------
  :) function you must implement
--------------------------------*/

int  searchPrice(struct s_art **arts, char *name);


/*--------------------------------
  ?? test function used in main 
--------------------------------*/

struct s_art		**getArts(void);

/*--------------------------------
  &  your own other function
--------------------------------*/


#endif
