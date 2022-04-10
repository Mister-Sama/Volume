/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** init_parameter - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

int		std_init_parameter(t_parameter	*p)
{
  p->win = bunny_start(1920, 1080, false, "Volume");
  p->px = bunny_new_pixelarray(1920, 1080);
  p->select_shape = 0;
  p->mesh_size = 0;
  p->shape_list = NULL;
  return (0);
}
