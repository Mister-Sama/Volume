/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_geometry_configuration - 2022
**
** *****************************************************************************
*/

#include        "volume.h"

t_geometry      std_get_geometry_configuration(t_bunny_configuration    *cnf,
                                               size_t                   i)
{
  t_geometry    geo;
  int           color[3];

  geo.color = std_get_shape_color(cnf, i);
  bunny_configuration_getf(cnf, &geo.pos.x, "Mesh[%ld].Position[0]", i);
  bunny_configuration_getf(cnf, &geo.pos.y, "Mesh[%ld].Position[1]", i);
  bunny_configuration_getf(cnf, &geo.pos.z, "Mesh[%ld].Position[2]", i);
  bunny_configuration_getf(cnf, &color[0], "Mesh[%ld].Altcolor[0]", i);
  bunny_configuration_getf(cnf, &color[1], "Mesh[%ld].Altcolor[1]", i);
  bunny_configuration_getf(cnf, &color[2], "Mesh[%ld].Altcolot[2]", i);
  bunny_configuration_getf(cnf, &geo.radius, "Mesh[%ld].Diameter[0]", i);
  bunny_configuration_getf(cnf, &geo.height, "Mesh[%ld].Height[0]", i);
  if (bunny_configuration_getf(cnf, &geo.smoothness, "Mesh[%ld].Smoothness[0]", i) == false)
    geo.smoothness = 10;
  geo.smoothness = (geo.smoothness == 0) ? 10 : geo.smoothness;
  geo.radius = geo.radius / 2;
  geo.altcolor = COLOR(color[0], color[1], color[2], 255);
  return (geo);
}

