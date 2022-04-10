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

unsigned int		std_get_position_color(t_bunny_configuration	*cnf,
					       size_t			i,
					       size_t			j)
{
  t_bunny_color         col;
  int                   color[3];

  bunny_configuration_getf(cnf, &color[0], "Mesh[%ld].Coord[%ld].Color[0]", i, j);
  bunny_configuration_getf(cnf, &color[1], "Mesh[%ld].Coord[%ld].Color[1]", i, j);
  bunny_configuration_getf(cnf, &color[2], "Mesh[%ld].Coord[%ld].Color[2]", i, j);
  col.argb[RED_CMP] = color[0];
  col.argb[GREEN_CMP] = color[1];
  col.argb[BLUE_CMP] = color[2];
  return (col.full);
}
