//
<<<<<<< HEAD
// Created by jules on 06/05/22.
=======
// Created by jules on 10/05/22.
>>>>>>> ea6f1e68bf05b78dbbbf5c9959e6f2e9194aaf05
//

#ifndef PROJETC_IG_EI_FRAME_T_H
#define PROJETC_IG_EI_FRAME_T_H

<<<<<<< HEAD
#endif //PROJETC_IG_EI_FRAME_T_H*
#include<ei_widget.h>

=======
#endif //PROJETC_IG_EI_FRAME_T_H
#include<ei_widgetclass.h>
#include<ei_widget.h>
>>>>>>> ea6f1e68bf05b78dbbbf5c9959e6f2e9194aaf05
void dessine_tout_widget();

typedef struct ei_frame_t {
        ei_widget_t     widget;
        ei_relief_t*     relief;
        char*           title;
        ei_font_t*       fonte;
        ei_color_t*      color;
        ei_anchor_t*     ancre;
        ei_surface_t*    img;
        ei_rect_t*       img_rect;
        ei_anchor_t*     img_anchor;

}ei_frame_t;

<<<<<<< HEAD
extern ei_widgetclass_t classe_frame;

struct ei_frame_t*      ei_frame_allocfunc_t        (void);
void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);
=======
struct ei_frame_t*      ei_frame_allocfunc_t        (void);

void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);

extern ei_widgetclass_t classe_frame =
        {
                "frame",
                &ei_frame_allocfunc_t,
                &ei_frame_releasefunc_t,
                NULL,
                NULL,
                NULL,
                NULL
        };
>>>>>>> ea6f1e68bf05b78dbbbf5c9959e6f2e9194aaf05
