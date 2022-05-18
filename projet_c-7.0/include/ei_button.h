//
// Created by axel on 11/05/22.
//

#ifndef PROJET_C_EI_BUTTON_H
#define PROJET_C_EI_BUTTON_H

#endif //PROJET_C_EI_BUTTON_H
#include "ei_types.h"
/**
 * \brief	Links 2 point forming an arc of circle
 *
 * @param	rect		The center of the circle drawn
 * @param	rayon		The radius of the circle drawn
 * @param	pre_angle	The first angle
 * @param	deu_angle	The second angle
 */
ei_linked_point_t**       arc         (ei_point_t*     centre,
                                            int*          rayon,
                                            double*         pre_angle,
                                            double*          deu_angle,
                                            ei_linked_point_t ** deb,
                                            ei_linked_point_t** fin);
/**
 * The widget button with a part which allow to click on hit*/
typedef struct ei_button_t {
        ei_widget_t widget;
        ei_color_t color;
        int border_width;
        int corner_radius;
        ei_relief_t relief;
        char* text;
        ei_font_t text_font;
        ei_color_t text_color;
        ei_anchor_t text_anchor;
        ei_surface_t img;
        ei_rect_t* img_rect;
        ei_anchor_t img_anchor;
        ei_callback_t callback;
        void* user_param;
} ei_button_t;

/**
 *@brief It makes the rectangle frame angles rounded
 *
 *@param        rectangle   The rectangle whose angles need to be rounded
 *@param        rayon       The radius of the circle of angles
 *@param        partie      If partie = 0 only the top left part is drawn
 *                          if partie = 1 only the bottom right part is drawn
 *                          if partie = 2 both parts are drown
 *@param        cadre       The linked points forming the perimeter of the rectangle*/
void     rounded_frame              (ei_rect_t*     rectangle,
                                                     int*          rayon,
                                                     int*            partie,
                                                     ei_linked_point_t** cadre);
