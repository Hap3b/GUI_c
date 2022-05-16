//
// Created by axel on 11/05/22.
//

#ifndef PROJET_C_EI_BUTTON_H
#define PROJET_C_EI_BUTTON_H

#endif //PROJET_C_EI_BUTTON_H
#include "ei_types.h"

ei_linked_point_t**       arc         (ei_point_t*     centre,
                                            double*          rayon,
                                            double*         pre_angle,
                                            double*          deu_angle);

ei_linked_point_t*       rounded_frame              (ei_rect_t*     rectangle,
                                                     double*          rayon,
                                                     int*            partie);
