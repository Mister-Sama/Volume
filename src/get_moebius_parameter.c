/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_moebius_parameter - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void            std_get_moebius_parameter(t_bunny_configuration        *cnf,
                                           size_t                       i,
                                           t_shape                      *shape)
{
  t_geometry	geo;
  t_zposition	pos;
  double	theta;
  double	h;

  h = 0;
  geo = std_get_geometry_configuration(cnf, i);
  while (h < geo.height)
    {
      theta = 0;
      while (theta <= 2 * M_PI)
	{
	  pos = std_set_zposition(geo.pos.x + (geo.radius + h * cos(theta)) * cos(theta),
				  geo.pos.y + (geo.radius + h * cos(theta)) * sin(theta),
				  geo.pos.z + h * sin(theta));
	  std_add_spot(shape, pos, geo.color);
	  theta = theta + (2 * M_PI / geo.smoothness);
	}
      h = h + 1;
    }
}
