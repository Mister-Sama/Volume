/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** set_pixel - 2022
**
** *****************************************************************************
*/

#include	"volume.h"

void            std_set_pixel(t_bunny_pixelarray   *px,
                              t_bunny_position     pos,
                              unsigned int         color)
{
  unsigned int  *adresse;

  adresse = px->pixels;
  if (pos.x >= 0 && pos.x < px->clipable.buffer.width && pos.y >= 0 && pos.\
      y < px->clipable.buffer.height)
    {
      adresse[px->clipable.buffer.width * pos.y + pos.x] = color;
    }
}
