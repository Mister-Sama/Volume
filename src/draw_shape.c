/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** draw_mesh - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

static void		std_draw_triangle(t_bunny_pixelarray	*px,
					  t_shape		*shape)
{
  unsigned int		color[2];
  t_bunny_position	pos[2];
  t_spot                *spot;

  spot = shape->front;
  while (spot != NULL && spot->next != NULL)
    {
      color[0] = spot->color;
      color[1] = spot->next->color;
      pos[0] = std_ajust_spot(shape, spot->pos);
      pos[1] = std_ajust_spot(shape, spot->next->pos);
      std_set_line(px, pos, color);
      spot = spot->next;
    }
  color[0] = shape->back->color;
  color[1] = shape->front->color;
  pos[0] = std_ajust_spot(shape, shape->back->pos);
  pos[1] = std_ajust_spot(shape, shape->front->pos);
  std_set_line(px, pos, color);
}

int			std_draw_shape(t_bunny_pixelarray	*px,
				       t_shape			*shape)
{
  t_spot		*spot;
 
  spot = shape->front;
  if (spot == NULL)
    return (-1);
  if (std_strcmp(shape->name, "Triangle") == true)
    std_draw_triangle(px, shape);
  else
    while (spot != NULL)
      {
	std_set_pixel(px, std_ajust_spot(shape, spot->pos), spot->color);
	spot = spot->next;
      }
  return (0);
}
