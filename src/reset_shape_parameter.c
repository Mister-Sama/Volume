/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** reset_shape_parameter - 2022
**
** *****************************************************************************
*/

#include        "volume.h"

void            std_reset_shape_parameter(t_parameter           *p)
{
  t_shape       *shape;
  size_t        i;

  i = 0;
  shape = p->shape_list;
  while (shape != NULL)
    {
      if (p->select_shape == i + 1 || p->select_shape == 0)
        {
          shape->rot = std_set_zposition(0, 0, 0);
          shape->scale = std_set_zposition(1, 1, 1);
          shape->pos = std_set_zposition(0, 0, 200);
        }
        shape = shape->next;
	i = i + 1;
    }
}
