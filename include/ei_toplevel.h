//
// Created by axel on 15/05/22.
//

#ifndef PROJETC_IG_EI_TOPLEVEL_H
#define PROJETC_IG_EI_TOPLEVEL_H

#endif //PROJETC_IG_EI_TOPLEVEL_H

#include <ei_widgetclass.h>
#include <ei_widget.h>

struct ei_frame_t*      ei_toplevel_allocfunc_t        (void);

void        ei_toplevel_releasefunc_t      (struct ei_frame_t*	frame);

void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	frame);

void	ei_toplevel_drawfunc_t		(struct ei_widget_t*	widget,
                                                ei_surface_t		surface,
                                                ei_surface_t		pick_surface,
                                                ei_rect_t*		clipper);

typedef struct ei_toplevel_t {
        ei_widget_t widget;
        ei_size_t requested_size;
        ei_color_t color;
        int border_width;
        char* title;
        ei_bool_t closable;
        ei_axis_set_t resizable;
        ei_size_t* min_size;
} ei_toplevel_t;

void    ajoute_boutton_haut_gauche      (ei_widget_t  *widget);

ei_widgetclass_t* addr_toplevel();