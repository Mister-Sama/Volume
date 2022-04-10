/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** set_line - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

static double           std_get_value(double             ratio,
                                      double             min,
                                      double             max)
{
  return (ratio * (max - min));
}

static double		std_get_step(t_bunny_position	*position)
{
  if ((DIFF(position[0].x, position[1].x)) == 0 &&
      (DIFF(position[0].y, position[1].y)) == 0)
    return (100);
  if ((DIFF(position[0].x, position[1].x)) > (DIFF(position[0].y, position[1].y)))
    return (99.9 / (DIFF(position[0].x, position[1].x)));
  return (99.9 / (DIFF(position[0].y, position[1].y)));
}
void            std_set_line(t_bunny_pixelarray         *px,
                             t_bunny_position           *position,
                             unsigned int               *color)
{
  t_bunny_position      pos[1];
  double		i;
  double		j;

  i = 0;
  j = std_get_step(position);
  while (i < 100)
    {
      pos[0].x = position[0].x + std_get_value((i / 100), position[0].x,
                                               position[1].x);
      pos[0].y = position[0].y + std_get_value((i / 100), position[0].y,
                                               position[1].y);
      std_set_pixel(px, pos[0], color[0]);
      i = i + j;
    }
}
