/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** move_scale - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void            std_move_scale(t_parameter	*p,
			       t_zposition	addpos)
{
  t_shape       *shape;
  size_t        i;

  i = 0;
  shape = p->shape_list;
  while (shape != NULL)
    {
      if (p->select_shape == i + 1 || p->select_shape == 0)
        {
          shape->scale.x = shape->scale.x + addpos.x;
          shape->scale.y = shape->scale.y + addpos.y;
          shape->scale.z = shape->scale.z + addpos.z;
        }
        shape = shape->next;
	i = i + 1;
    }
}
