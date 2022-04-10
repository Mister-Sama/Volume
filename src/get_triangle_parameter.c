/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_triangle_parameter - 2022
**
** *****************************************************************************
*/

#include		"volume.h"

void			std_get_triangle_parameter(t_bunny_configuration        *cnf,
						   size_t                       i,
						   t_shape			*shape)
{
  size_t		j;
  t_zposition		pos;
  unsigned int		color;
  
  j = 0;
  while (j != 3)
    {
      bunny_configuration_getf(cnf, &pos.x, "Mesh[%ld].Coord[%ld].Position[0]", i, j);
      bunny_configuration_getf(cnf, &pos.y, "Mesh[%ld].Coord[%ld].Position[1]", i, j);
      bunny_configuration_getf(cnf, &pos.z, "Mesh[%ld].Coord[%ld].Position[2]", i, j);
      color = (bunny_configuration_getf(cnf, NULL, "Mesh[%ld].Coord[%ld].Color", i, j)
	       == true) ? std_get_position_color(cnf, i, j) : std_get_shape_color(cnf, i);;  
      std_add_spot(shape, pos, color);
      j = j + 1;
    }
}

