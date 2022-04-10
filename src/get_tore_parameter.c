/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_tore_parameter - 2022
**
** *****************************************************************************
*/

#include        "volume.h"

void            std_get_tore_parameter(t_bunny_configuration        *cnf,
				       size_t                       i,
				       t_shape                      *shape)
{
  t_geometry	geo;
  t_zposition	pos;
  double	theta;
  double	phi;

  geo = std_get_geometry_configuration(cnf, i);
  theta = 0;
  while (theta < 2 * M_PI)
    {
      phi = 0;
      while (phi < 2 * M_PI)
	{
	  pos = std_set_zposition(geo.pos.x + (geo.height + geo.radius * cos(theta)) * cos(phi),
				  geo.pos.y + (geo.height + geo.radius * cos(theta)) * sin(phi),
				  geo.pos.z + geo.radius * sin(theta));
	  phi = phi + ((2 * M_PI) / geo.smoothness);
	  std_add_spot(shape, pos, geo.color);
	}
      theta = theta + ((2 * M_PI) / geo.smoothness);
    }
}
