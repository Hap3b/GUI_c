//
// Created by axel on 11/05/22.
//

#ifndef PROJET_C_EI_BUTTON_H
#define PROJET_C_EI_BUTTON_H

#endif //PROJET_C_EI_BUTTON_H

ei_linked_point_t*       arc[2]            (ei_point_t     centre,
                                            float          rayon,
                                            float          pre_angle,
                                            float          deu_angle);

ei_linked_point_t*       rounded_frame              (ei_rect_t     rectangle,
                                                     float          rayon,
                                                     int            partie);