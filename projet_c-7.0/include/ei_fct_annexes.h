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

ei_point_t* anchor_to_point(const ei_anchor_t* ancre, ei_rect_t* rect);

void free_link(ei_linked_point_t *deb);