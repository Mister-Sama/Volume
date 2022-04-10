/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** open_dab_configuration - 2022
**
** *****************************************************************************
*/

#include			"volume.h"

int                             std_open_dab_configuration(t_parameter	*p,
							   const char   *file)
{
  t_bunny_configuration         *cnf;
  const char                    *shape;
  size_t                        i;
  t_shape			*nshape;

  i = 0;
  cnf = bunny_open_configuration(file, NULL);
  if (cnf == NULL)
    return (0);
  while (bunny_configuration_getf(cnf, &shape, "Mesh[%ld].Shape[0]", i))
    {
      nshape = std_add_shape(&(p->shape_list));
      if (nshape == NULL)
	return (-1);
      nshape->name = shape;
      p->mesh_size = p->mesh_size + 1;
      std_get_shape_parameter(cnf, i, nshape);
      i = i + 1;
    }
  return (0);
}
