//
// Created by axel on 11/05/22.
//

#ifndef PROJET_C_EI_BUTTON_H
#define PROJET_C_EI_BUTTON_H

#endif //PROJET_C_EI_BUTTON_H
#include "ei_types.h"
<<<<<<< HEAD
/**
* \brief	Draw linked_points which form a curved line like an arc between 2 points.
*
* @param	centre 	        If the final point will be connected to the first one it will form a circle.
*                               Hence there is a center.
* @param	rayon 	        The rayon of the circle arc drawn.
* @param	pre_angle	It is the first angle.
* @param	deu_angle	It is the second angle.
* @param	deb      	The first point to link by the arc.
* @param	fin     	The last point to link by the arc.
*
*
*/
ei_linked_point_t**       arc         (ei_point_t*     centre,
                                            int*          rayon,
                                            double*         pre_angle,
                                            double*          deu_angle,
                                            ei_linked_point_t ** deb,
                                            ei_linked_point_t** fin);
/**
 * We are defining the widget button rounded in the angles
 * The callback
 */
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
* \brief	It makes a rectangular frame angles rounded.
*
* @param	rectangle 	The rectangle representing the frame
* @param	rayon 	        The rayon of the circle arc drawn.
* @param	partie  	If it is equal to 0 only the top left part is rounded,
*                               If it is equal to 1 only the bottom right part is rounded,
*                               If it is equal to 2 both parts are rounded
* @param	cadre   	Linked points where to store the points representing lines of the frame
*/
=======

ei_linked_point_t**       arc         (ei_point_t*     centre,
                                            int*          rayon,
                                            double*         pre_angle,
                                            double*          deu_angle,
                                            ei_linked_point_t ** deb,
                                            ei_linked_point_t** fin);
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

>>>>>>> refs/remotes/origin/master
void     rounded_frame              (ei_rect_t*     rectangle,
                                                     int*          rayon,
                                                     int*            partie,
                                                     ei_linked_point_t** cadre);
