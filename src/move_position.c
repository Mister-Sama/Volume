/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** move_position - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void		std_move_position(t_parameter		*p,
				  t_zposition		addpos)
{
  t_shape	*shape;
  size_t	i;

  i = 0;
  shape = p->shape_list;
  while (shape != NULL)
    {
      if (p->select_shape == i + 1 || p->select_shape == 0)
	{
	  shape->pos.x = shape->pos.x + addpos.x;
	  shape->pos.y = shape->pos.y + addpos.y;
	  shape->pos.z = shape->pos.z + addpos.z;
	}
      shape = shape->next;
      i = i + 1;
    }
}
