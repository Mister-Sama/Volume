/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** strcmp - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

bool		std_strcmp(const char   *str,
			   const char   *str2)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0' || str2[i] != '\0')
    {
      if (str[i] != str2[i])
        return (false);
      i = i + 1;
    }
  return (true);
}

