/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** open_dab_configuration - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void		std_get_shape_parameter(t_bunny_configuration	*cnf,
					size_t			i,
					t_shape			*shape)
{
  if (std_strcmp(shape->name, "Triangle") == true)
    std_get_triangle_parameter(cnf, i, shape);
  if (std_strcmp(shape->name, "Sphere") == true)
    std_get_sphere_parameter(cnf, i, shape);
  if (std_strcmp(shape->name, "Cylinder") == true)
    std_get_cylinder_parameter(cnf, i, shape);
  if (std_strcmp(shape->name, "Cone") == true)
    std_get_cone_parameter(cnf, i, shape);
  if (std_strcmp(shape->name, "Moebius") == true)
    std_get_moebius_parameter(cnf, i, shape);
  if (std_strcmp(shape->name, "Tore") == true)
    std_get_tore_parameter(cnf, i, shape);
}
