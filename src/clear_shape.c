/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** clear_shape - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void		std_clear_shape(t_shape		*shape)
{
  t_spot	*save;

  while (shape->front != NULL)
    {
      save = shape->front;
      shape->front = shape->front->next;
      bunny_free(save);
    }
}
