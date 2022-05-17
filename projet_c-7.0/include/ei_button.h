//
// Created by axel on 11/05/22.
//

#ifndef PROJET_C_EI_BUTTON_H
#define PROJET_C_EI_BUTTON_H

#endif //PROJET_C_EI_BUTTON_H
#include "ei_types.h"

ei_linked_point_t**       arc         (ei_point_t*     centre,
                                            int*          rayon,
                                            double*         pre_angle,
                                            double*          deu_angle,
                                            ei_linked_point_t ** deb,
                                            ei_linked_point_t** fin);
typedef struct ei_button_t {
        ei_widget_t widget;
        ei_color_t* color;
        int* border_width;
        int* corner_radius;
        ei_relief_t* relief;
        char** text;
        ei_font_t* text_font;
        ei_color_t* text_color;
        ei_anchor_t* text_anchor;
        ei_surface_t* img;
        ei_rect_t** img_rect;
        ei_anchor_t* img_anchor;
        ei_callback_t* callback;
        void** user_param;
} ei_button_t;

void     rounded_frame              (ei_rect_t*     rectangle,
                                                     int*          rayon,
                                                     int*            partie,
                                                     ei_linked_point_t** cadre);
