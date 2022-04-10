/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** volume - 2022
**
** *****************************************************************************
*/

#include		<lapin.h>

#ifndef			__VOLUME_H__
#define			__VOLUME_H__

#define ABS(a)          ((a) < 0) ? (a) * -1 : (a)
#define DIFF(a, b)      ABS((a) - (b))

typedef struct		s_zposition
{
  double		x;
  double		y;
  double		z;
}			t_zposition;

typedef struct		s_spot
{
  t_zposition		pos;
  unsigned int		color;
  struct s_spot		*next;
}			t_spot;

typedef struct		s_shape
{
  const char		*name;
  t_zposition		pos;
  t_zposition		scale;
  t_zposition		rot;
  unsigned int		color;
  t_spot		*front;
  t_spot		*back;
  struct s_shape	*next;
}			t_shape;

typedef struct		s_parameter
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*px;
  size_t		select_shape;
  size_t		mesh_size;
  t_shape		*shape_list;
}			t_parameter;

typedef struct		s_geometry
{
  double		radius;
  unsigned int		color;
  unsigned int		altcolor;
  t_zposition		pos;
  double		smoothness;
  double		height;
}			t_geometry;
  
t_bunny_position	std_perspective(float					x,
					float					y,
					float					z);

bool			std_strcmp(const char					*str,
				   const char					*str2);

unsigned int            std_get_shape_color(t_bunny_configuration		*cnf,
                                           size_t				i);

void			std_get_triangle_parameter(t_bunny_configuration        *cnf,
						   size_t                       i,
						   t_shape			*shape);

void			std_get_sphere_parameter(t_bunny_configuration		*cnf,
						 size_t				i,
						 t_shape			*shape);

void			std_get_cylinder_parameter(t_bunny_configuration        *cnf,
						   size_t                       i,
						   t_shape                      *shape);

void                    std_get_moebius_parameter(t_bunny_configuration		*cnf,
                                                   size_t                       i,
                                                   t_shape                      *shape);


void                    std_get_cone_parameter(t_bunny_configuration		*cnf,
					       size_t				i,
					       t_shape				*shape);

void			std_get_tore_parameter(t_bunny_configuration		*cnf,
					       size_t				i,
					       t_shape				*shape);

int			std_open_dab_configuration(t_parameter			*p,
						   const char			*file);

t_shape			*std_add_shape(t_shape					**shape);

t_zposition		std_set_zposition(double				x,
					  double				y,
					  double				z);

int			std_init_parameter(t_parameter				*p);

unsigned int            std_get_position_color(t_bunny_configuration		*cnf,
                                               size_t				i,
                                               size_t				j);

bool			std_add_spot(t_shape					*shape,
				     t_zposition				pos,
				     unsigned int				color);

void			std_start_loop(t_parameter				*p);

t_bunny_response	std_key_response(t_bunny_event_state			state,
					 t_bunny_keysym				sym,
					 void					*data);

void			std_move_position(t_parameter				*p,
					  t_zposition				addpos);

void			std_move_scale(t_parameter				*p,
				       t_zposition				addpos);

void			std_move_rotation(t_parameter				*p,
					  t_zposition				addpos);

void			std_clear_pixelarray(t_bunny_pixelarray			*px,
					     unsigned int			color);

t_bunny_response        std_draw_mesh(void					*data);

int			std_draw_shape(t_bunny_pixelarray			*px,
				       t_shape					*shape);

t_bunny_position        std_ajust_spot(t_shape					*shape,
                                       t_zposition				pos);

void			std_set_pixel(t_bunny_pixelarray			*px,
				      t_bunny_position				pos,
				      unsigned int				color);

void			std_set_line(t_bunny_pixelarray				*px,
				     t_bunny_position				*position,
				     unsigned int				*color);

void			std_get_shape_parameter(t_bunny_configuration		*cnf,
						size_t				i,
						t_shape				*shape);

void			std_delete_shape(t_shape				**shape);

void			std_clear_shape(t_shape					*shape);

void			std_reset_shape_parameter(t_parameter			*p);

t_geometry		std_get_geometry_configuration(t_bunny_configuration    *cnf,
						       size_t                   i);

#endif

