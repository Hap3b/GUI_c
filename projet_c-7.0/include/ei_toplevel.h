//
// Created by axel on 15/05/22.
//

#ifndef PROJETC_IG_EI_TOPLEVEL_H
#define PROJETC_IG_EI_TOPLEVEL_H

#endif //PROJETC_IG_EI_TOPLEVEL_H

#include <ei_widgetclass.h>
#include <ei_widget.h>

void    draw_children          (ei_widget_t* children);

typedef struct ei_toplevel_t {
        ei_widget_t* widget;
        ei_size_t* requested_size;
        ei_color_t* color;
        int* border_width;
        char** title;
        ei_bool_t* closable;
        ei_axis_set_t* resizable;
        ei_size_t** min_size;
} ei_toplevel_t;

struct ei_toplevel_t*      ei_toplevel_allocfunc_t        (void);

void        ei_toplevel_releasefunc_t      (struct ei_toplevel_t*	toplevel);

void	ei_toplevel_drawfunc_t		(struct ei_widget_t*	widget,
                                                   ei_surface_t		surface,
                                                   ei_surface_t		pick_surface,
                                                   ei_rect_t*		clipper);

void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	toplevel);