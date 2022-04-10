/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** draw_mesh - 2022
**
** *****************************************************************************
*/

#include		"volume.h"

t_bunny_response	std_draw_mesh(void	*data)
{
  t_parameter		*p;
  t_shape		*shape;

  p = data;
  shape = p->shape_list;
  std_clear_pixelarray(p->px, BLACK);
  while (shape != NULL)
    {
      std_draw_shape(p->px, shape);
      shape = shape->next;
    }
  bunny_blit(&p->win->buffer, &p->px->clipable, NULL);
  bunny_display(p->win);
  return (GO_ON);
}

