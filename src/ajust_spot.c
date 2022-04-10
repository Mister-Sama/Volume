/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** ajust_spot - 2022
**
** *****************************************************************************
*/

#include                "volume.h"

void		std_set_rotation(t_zposition		*pos,
				 t_zposition		rotation)
{
  double	save;

  save = pos->y * cos(rotation.x) + pos->z * (-sin(rotation.x));
  pos->z = pos->y * sin(rotation.x) + pos->z * cos(rotation.x);
  pos->y = save;
  save = pos->x * cos(rotation.y) + pos->z * sin(rotation.y);
  pos->z = pos->x * (-sin(rotation.y)) + pos->z * cos(rotation.y);
  pos->x = save;
  save = pos->x * cos(rotation.z) + pos->y * (-sin(rotation.z));
  pos->y = pos->x * sin(rotation.z) + pos->y * cos(rotation.z);
  pos->x = save;
}

void		std_set_scale(t_zposition		*pos,
			      t_zposition		scale)
{
  pos->x = pos->x * scale.x;
  pos->y = pos->y * scale.y;
  pos->z = pos->z * scale.z;
}

static void		std_set_position(t_zposition	*pos,
					 t_zposition	planpos)
{
  pos->x = pos->x + planpos.x;
  pos->y = pos->y + planpos.y;
  pos->z = pos->z + planpos.z;
}

t_bunny_position        std_ajust_spot(t_shape		*shape,
                                       t_zposition	pos)
{
  t_zposition	ajustpos;

  ajustpos = pos;
  std_set_scale(&ajustpos, shape->scale);
  std_set_rotation(&ajustpos, shape->rot);
  std_set_position(&ajustpos, shape->pos);
  return (std_perspective(ajustpos.x, ajustpos.y, ajustpos.z));
}

