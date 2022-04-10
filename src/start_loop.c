/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** start_loop - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void		std_start_loop(t_parameter	*p)
{
  bunny_set_key_response(std_key_response);
  bunny_set_loop_main_function(std_draw_mesh);
  bunny_loop(p->win, 60, p);
}
