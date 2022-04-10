/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** main - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

int		main(int	argc,
		     char	*argv[])
{
  int		i;
  t_parameter	p;

  i = 0;
  if (argc < 2)
    return (0);
  std_init_parameter(&p);
  while (i != argc)
    {
      if (bunny_which_format(argv[i]) == 1)
	std_open_dab_configuration(&p, argv[i]);
      i = i + 1;
    }
  std_start_loop(&p);
  std_delete_shape(&p.shape_list);
  return (0);
}
