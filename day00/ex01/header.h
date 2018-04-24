#ifndef HEADER_H
# define HEADER_H

#include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_art {
	char *name;
	int price;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

void  sortArts(struct s_art **arts);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

int getSize(struct s_art **arts);

struct s_art **getArts(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
