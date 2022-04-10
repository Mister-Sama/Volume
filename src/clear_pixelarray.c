/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** clear_pixelarray - 2021
**
** *****************************************************************************
*/

#include        "volume.h"

void            std_clear_pixelarray(t_bunny_pixelarray        *px,
                                     unsigned int              color)
{
  int           i;
  unsigned int  *adresse;

  i = 0;
  adresse = px->pixels;
  while (i != px->clipable.buffer.width * (px->clipable.buffer.height))
    {
      adresse[i] = color;
      i = i + 1;
    }
}
