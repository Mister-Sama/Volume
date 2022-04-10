/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** key_response - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void		std_move_rotation(t_parameter		*p,
				  t_zposition		addpos)
{
  t_shape       *shape;
  size_t        i;

  i = 0;
  shape = p->shape_list;
  while (shape != NULL)
    {
      if (p->select_shape == i + 1 || p->select_shape == 0)
        {
          shape->rot.x = shape->rot.x + addpos.x;
          shape->rot.y = shape->rot.y + addpos.y;
          shape->rot.z = shape->rot.z + addpos.z;
        }
        shape = shape->next;
	i = i + 1;
    }
}

