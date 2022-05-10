//
// Created by hugo on 10/05/22.
//

#ifndef PROJETC_IG_EI_FRAME_T_H
#define PROJETC_IG_EI_FRAME_T_H

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

struct ei_frame_t*      ei_frame_allocfunc_t        (void);

void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);

void	ei_frame_drawfunc_t		(struct ei_widget_t*	widget,
                                                      ei_surface_t		surface,
                                                      ei_surface_t		pick_surface,
                                                      ei_rect_t*		clipper);

void	ei_frame_setdefaultsfunc_t	(struct ei_frame_t*	frame);

extern ei_widgetclass_t classe_frame =
        {
                "frame",
                &ei_frame_allocfunc_t,
                &ei_frame_releasefunc_t,
                &ei_frame_drawfunc_t,
                &ei_frame_setdefaultsfunc_t,
                NULL,
                NULL
        };

#endif //PROJETC_IG_EI_FRAME_T_H
