/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** open_dab_configuration - 2022
**
** *****************************************************************************
*/

#include		"volume.h"

t_zposition		std_set_zposition(double	x,
					  double	y,
					  double	z)
{
  t_zposition		pos;

  pos.x = x;
  pos.y = y;
  pos.z = z;
  return (pos);
}
