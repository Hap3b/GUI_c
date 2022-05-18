//
// Created by axel on 15/05/22.
//

#ifndef PROJETC_IG_EI_TOPLEVEL_H
#define PROJETC_IG_EI_TOPLEVEL_H

#endif //PROJETC_IG_EI_TOPLEVEL_H

#include <ei_widgetclass.h>
#include <ei_widget.h>

/**
 * \brief	A function drawing the children widget and its siblings
 *
 * @param       children    The first child to be drawn (linked with its siblings)
 */
void    draw_children          (ei_widget_t* children);


/**
 * It is a frame with a rounded header frame which is closable resizable and cant be smaller than a given size.
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
 * \brief	Reserve the space needed by a toplevel
 *
 */

struct ei_toplevel_t*      ei_toplevel_allocfunc_t        (void);

/**
 * \brief	free the space needed by a toplevel
 *
 * @param toplevel the toplevel which should be free
 */
void        ei_toplevel_releasefunc_t      (struct ei_toplevel_t*	toplevel);


/**
 * \brief	A function called in  \ref dessine_tout to draw a toplevel
 *
 * @param  widget       the toplevel which should be drawn but it is cast as a widget to be in a widget_class
 * @param  surface      the surface representing the toplevel
 * @param  pick_surface the surface representing the offscreen
 * @param  clipper      if it is not NULL the drawing is restricted in this rectangle.
 */
void	ei_toplevel_drawfunc_t		(struct ei_widget_t*	widget,
                                                   ei_surface_t		surface,
                                                   ei_surface_t		pick_surface,
                                                   ei_rect_t*		clipper);
/**
 * \brief	Set the default value to a toplevel
 *
 * @param  toplevel the toplevel which should be set to default
 */
void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	toplevel);