/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_cylinder_parameter - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void		std_get_cylinder_parameter(t_bunny_configuration	*cnf,
					   size_t			i,
					   t_shape			*shape)
{
  t_geometry	geo;
  t_zposition	pos;
  double	theta;
  double	h;

  geo = std_get_geometry_configuration(cnf, i);
  h = 0;
  while (h < geo.height)
    {
      theta = 0;
      while (theta <= 2 * M_PI)
        {
          pos = std_set_zposition(geo.pos.x + geo.radius * cos(theta),
				  geo.pos.y + geo.radius * sin(theta), geo.pos.z + h);
	  std_add_spot(shape, pos, geo.color);
          theta = theta + (2 * M_PI) / geo.smoothness;
        }
      h = h + 1;
    }
}
