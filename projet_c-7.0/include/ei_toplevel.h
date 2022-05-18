//
// Created by axel on 15/05/22.
//

#ifndef PROJETC_IG_EI_TOPLEVEL_H
#define PROJETC_IG_EI_TOPLEVEL_H

#endif //PROJETC_IG_EI_TOPLEVEL_H

#include <ei_widgetclass.h>
#include <ei_widget.h>

void    draw_children          (ei_widget_t* children);

/**
 * It is like a frame but with a rounded header which can be closed and resizable and have a minimal size
 */
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


/**
 *@brief Reserve the memory space needed for a toplevel
 */
struct ei_toplevel_t*      ei_toplevel_allocfunc_t        (void);

/**
 *@brief Free the memory space needed for a toplevel
 */
void        ei_toplevel_releasefunc_t      (struct ei_toplevel_t*	toplevel);

/**
 *@brief A function called in \ref dessine_tout_widget() to draw the toplevel
 *
 * @param       widget           In order to be called in a ei_widget_class the toplevel need to be cast as a widget
 * @param       surface          The surface where the toplevel is defined
 * @param       pick_surface     The surface where the offscreen is defined
 * @param       widget           If it is not NULL the toplevel drawn is restricted in the clipper
 */
void	ei_toplevel_drawfunc_t		(struct ei_widget_t*	widget,
                                                   ei_surface_t		surface,
                                                   ei_surface_t		pick_surface,
                                                   ei_rect_t*		clipper);
/**
 * @brief If a value of a toplevel is not precised, this value is set by this function
 *
 * @param       toplevel           Frame to configure by default.
 */
void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	toplevel);