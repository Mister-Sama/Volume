/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_sphere_parameter - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void		std_get_sphere_parameter(t_bunny_configuration		*cnf,
					 size_t				i,
					 t_shape			*shape)
{
  t_geometry		geo;
  t_zposition		pos;
  double                theta;
  double                phi;
  double                thetastep;
  double                phistep;

  geo = std_get_geometry_configuration(cnf, i);
  thetastep = M_PI / geo.smoothness;
  phistep = (2 * M_PI) / geo.smoothness;
  theta = -M_PI / 2;
  while (theta < M_PI / 2)
    {
      phi = -M_PI;
      while (phi < M_PI)
        {
          pos = std_set_zposition(geo.pos.x + geo.radius * cos(theta) * cos(phi),
				  geo.pos.y + geo.radius * cos(theta) * sin(phi),
				  geo.pos.z + geo.radius * sin(theta));
          std_add_spot(shape, pos, geo.color);
          phi = phi + phistep;
	}
      theta = theta + thetastep;
    }
}
