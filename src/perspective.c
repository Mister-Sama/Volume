/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** perspective - 2022
**
** *****************************************************************************
*/

#include		"volume.h"

t_bunny_position	std_perspective(float	x,
					float	y,
					float	z)
{
  t_bunny_position	pos;

  pos.x = (z < 1) ? 960 : (x * (1 / (z / 200))) + 960;
  pos.y = (z < 1) ? 540 : (y * (1 / (z / 200))) + 540;
  return (pos);
}

