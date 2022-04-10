/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** volume - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

t_shape		*std_add_shape(t_shape	**shape)
{
  t_shape	*nshape;
  t_shape	*save;

  nshape = bunny_malloc(sizeof(t_shape));
  if (nshape == NULL)
    return (NULL);
  nshape->next = NULL;
  nshape->front = NULL;
  nshape->color = 0;
  nshape->back = NULL;
  nshape->pos = std_set_zposition(0, 0, 200);
  nshape->scale = std_set_zposition(1, 1, 1);
  nshape->rot = std_set_zposition(0, 0, 0);
  if (*shape == NULL)
    *shape = nshape;
  else
    {
      save = *shape;
      while (save->next != NULL)
	save = save->next;
      save->next = nshape;
    }
  return (nshape);
}
