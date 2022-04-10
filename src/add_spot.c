/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_triangle_parameter - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

bool		std_add_spot(t_shape		*shape,
			     t_zposition	pos,
			     unsigned int	color)
{
  t_spot	*nspot;

  if (shape == NULL)
    return (NULL);
  nspot = bunny_malloc(sizeof(t_spot));
  if (nspot == NULL)
    return (false);
  nspot->next = NULL;
  nspot->color = color;
  nspot->pos = pos;
  if (shape->front == NULL || shape->back == NULL)
    {
      shape->front = nspot;
      shape->back = nspot;
    }
  else
    {
      shape->back->next = nspot;
      shape->back = nspot;
    }
  return (true);
}
