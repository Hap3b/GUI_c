#include <stdio.h>
#include <stdlib.h>

#include "ei_application.h"
#include "hw_interface.h"
#include "ei_widget.h"
#include "ei_geometrymanager.h"
#define pi 3.14159
/*
 * main --
 *
 *	Main function of the application.
 */
#include<ei_button.h>
int main(int argc, char** argv)
{
/*	ei_size_t	screen_size		= {600, 600};
	ei_color_t	root_bgcol		= {0x52, 0x7f, 0xb4, 0xff};

	ei_widget_t*	frame;
	ei_size_t	frame_size		= {300,200};
	int		frame_x			= 150;
	int		frame_y			= 200;
	ei_color_t	frame_color		= {0x88, 0x88, 0x88, 0xff};
	ei_relief_t	frame_relief		= ei_relief_raised;
	int		frame_border_width	= 6;
*/
	/* Create the application and change the color of the background. */
//	ei_app_create(screen_size, EI_FALSE);


//	ei_frame_configure(ei_app_root_widget(), NULL, &root_bgcol, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	/* Create, configure and place the frame on screen. */
//	frame = ei_widget_create("frame", ei_app_root_widget(), NULL, NULL);
//	ei_frame_configure(frame, &frame_size, &frame_color,
//		    &frame_border_width, &frame_relief, NULL, NULL, NULL, NULL,
//			    NULL, NULL, NULL);
//	ei_place(frame, NULL, &frame_x, &frame_y, NULL, NULL, NULL, NULL, NULL, NULL );

	/* Run the application's main loop. */
//	ei_app_run();

	/* We just exited from the main loop. Terminate the application (cleanup). */
//	ei_app_free();

        //
// Created by jules on 15/05/22.
//

       ei_size_t	screen_size		= {600, 600};
        ei_color_t	root_bgcol		= {0x52, 0x7f, 0xb4, 0xff};
        ei_color_t	frame_color		= {0xff, 0xff, 0xff, 0xff};
        ei_color_t	clair		= {0x50, 0x50, 0x50, 0x50};

        ei_point_t* centre = malloc(sizeof(ei_point_t));
        centre ->x = 300;
        centre ->y = 300;
        ei_rect_t* rectangle = malloc(sizeof(ei_rect_t));
        rectangle -> top_left.x = 100;
        rectangle -> top_left.y = 100;
        rectangle -> size.height = 300;
        rectangle -> size.width = 400;
        double * rayon = malloc(sizeof(int));
        double * pre_angle = malloc(sizeof(float ));
        double* deu_angle = malloc(sizeof(float));
        ei_linked_point_t* deb = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* fin = deb;
        ei_linked_point_t* cadre = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* cadre_haut = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* cadre_interieur = malloc(sizeof(ei_linked_point_t));
        *rayon = 50;
        int* partie = malloc(sizeof(int));
        *partie = 1;
        *pre_angle = 0;
        *deu_angle = pi;
        ei_app_create(screen_size, EI_FALSE);
        ei_frame_configure(ei_app_root_widget(), NULL, &root_bgcol, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
        ei_surface_t racine = ei_app_root_surface();
        rounded_frame(rectangle, rayon, partie, &cadre);

        *partie = 0;
        rounded_frame(rectangle, rayon, partie, &cadre_haut);
        ei_rect_t* interieur = malloc(sizeof(ei_rect_t));
        interieur->size.width = 380;
        interieur->size.height = 280;
        interieur->top_left.x = 120;
        interieur->top_left.y = 120;
        *partie = 2;
        rounded_frame(interieur, rayon, partie, &cadre_interieur);
        hw_surface_lock(racine);
        ei_app_run();
        ei_draw_polygon(racine,cadre,clair, NULL);
        ei_draw_polygon(racine,cadre_haut,frame_color, NULL);
        ei_draw_polygon(racine,cadre_interieur,clair, NULL);


        hw_surface_unlock(racine);
        hw_surface_update_rects(racine, NULL);
        getchar();
	return (EXIT_SUCCESS);
}
