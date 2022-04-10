/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_shape_color - 2022
**
** *****************************************************************************
*/

#include		"volume.h"

unsigned int		std_get_shape_color(t_bunny_configuration        *cnf,
					    size_t                       i)
{
  int			color[3];

  bunny_configuration_getf(cnf, &color[0], "Mesh[%ld].Color[0]", i);
  bunny_configuration_getf(cnf, &color[1], "Mesh[%ld].Color[1]", i);
  bunny_configuration_getf(cnf, &color[2], "Mesh[%ld].Color[2]", i);
  return (COLOR(color[0], color[1], color[2], 255));
}

