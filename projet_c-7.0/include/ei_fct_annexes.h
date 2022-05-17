//
// Created by axel on 15/05/22.
//

#ifndef PROJETC_IG_EI_FCT_ANNEXES_H
#define PROJETC_IG_EI_FCT_ANNEXES_H

#endif //PROJETC_IG_EI_FCT_ANNEXES_H

#include <math.h>
#include <ei_types.h>

int     min     (int a,
                 int b);

int     max     (int a,
                 int b);

ei_linked_point_t**    arc           (ei_point_t*     centre,
                                      double          rayon,
                                      double          pre_angle,
                                      double          deu_angle);

void    free_arc        (struct ei_linked_point_t** arc);