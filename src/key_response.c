/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** key_response - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

static void	std_pos_keyresponse(t_bunny_keysym		sym,
				    void			*data)
{
  t_parameter	*p;

  p = data;
  if (sym == BKS_A)
    std_move_position(p, std_set_zposition(5, 0, 0));
  if (sym == BKS_Q)
    std_move_position(p, std_set_zposition(-5, 0, 0));
  if (sym == BKS_S)
    std_move_position(p, std_set_zposition(0, 5, 0));
  if (sym == BKS_Z)
    std_move_position(p, std_set_zposition(0, -5, 0));
  if (sym == BKS_E)
    std_move_position(p, std_set_zposition(0, 0, 5));
  if (sym == BKS_D)
    std_move_position(p, std_set_zposition(0, 0, -5));
}

static void     std_scale_keyresponse(t_bunny_keysym              sym,
				      void                        *data)
{
  t_parameter   *p;

  p = data;
  if (sym == BKS_U)
    std_move_scale(p, std_set_zposition(0.1, 0, 0));
  if (sym == BKS_J)
    std_move_scale(p, std_set_zposition(-0.1, 0, 0));
  if (sym == BKS_I)
    std_move_scale(p, std_set_zposition(0, 0.1, 0));
  if (sym == BKS_K)
    std_move_scale(p, std_set_zposition(0, -0.1, 0));
  if (sym == BKS_O)
    std_move_scale(p, std_set_zposition(0, 0, 0.1));
  if (sym == BKS_L)
    std_move_scale(p, std_set_zposition(0, 0, -0.1));
}

static void     std_rotation_keyresponse(t_bunny_keysym              sym,
					 void                        *data)
{
  t_parameter   *p;

  p = data;
  if (sym == BKS_R)
    std_move_rotation(p, std_set_zposition(0.2, 0, 0));
  if (sym == BKS_F)
    std_move_rotation(p, std_set_zposition(-0.2, 0, 0));
  if (sym == BKS_T)
    std_move_rotation(p, std_set_zposition(0, 0.2, 0));
  if (sym == BKS_G)
    std_move_rotation(p, std_set_zposition(0, -0.2, 0));
  if (sym == BKS_Y)
    std_move_rotation(p, std_set_zposition(0, 0, 0.2));
  if (sym == BKS_H)
    std_move_rotation(p, std_set_zposition(0, 0, -0.2));
}  

t_bunny_response                std_key_response(t_bunny_event_state		state,
                                                 t_bunny_keysym			sym,
                                                 void				*data)
{
  t_parameter			*p;

  p = data;
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (sym == BKS_W)
    p->select_shape = (p->select_shape - 1) % (p->mesh_size + 1);
  if (sym == BKS_X)
    p->select_shape = (p->select_shape + 1) % (p->mesh_size + 1);
  if (sym == BKS_N)
    std_reset_shape_parameter(p);
  std_pos_keyresponse(sym, data);
  std_scale_keyresponse(sym, data);
  std_rotation_keyresponse(sym, data);
  return (GO_ON);
}
