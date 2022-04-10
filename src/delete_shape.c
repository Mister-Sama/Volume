/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** delete_shape - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void		std_delete_shape(t_shape	**shape)
{
  t_shape	*save;

  while (*shape != NULL)
    {
      save = *shape;
      *shape = (*shape)->next;
      std_clear_shape(save);
      bunny_free(save);
    }
}
