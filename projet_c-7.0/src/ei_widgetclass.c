//
// Created by jules on 03/05/22.
//


/**
 * \brief	A function that draws widgets of a class.
 *
 * @param	widget		A pointer to the widget instance to draw.
 * @param	surface		A locked surface where to draw the widget. The actual location of the widget in the
 *				surface is stored in its "screen_location" field.
 * @param	pick_surface	The picking offscreen.
 * @param	clipper		If not NULL, the drawing is restricted within this rectangle
 *				(expressed in the surface reference frame).
 */
typedef void	(*ei_widgetclass_drawfunc_t)		(struct ei_widget_t*	widget,
							 ei_surface_t		surface,
							 ei_surface_t		pick_surface,
                                                         ei_rect_t*		clipper)
        {
        ei_color_t trans = {0xff, 0xff, 0xff, 0x00};
        ei_draw_polygon(surface, widget<-screen_location<-top_left,widget<-pick_color, clipper);/*Si bug ça vient du top left*/
        ei_draw_polygon(pick_surface, widget<-screen_location<-top_left,trans, clipper);
        }

/**
 * \brief	A function that sets the default values for a class.
 *
 * @param	widget		A pointer to the widget instance to initialize.
 */

typedef void	(*ei_widgetclass_setdefaultsfunc_t)	(struct ei_widget_t*	widget)
        {
        widget<-pick_color = {0x77, 0x77, 0x77, 0x255}; /* Couleur de base est un gris opaque*/
        widget<-user_data = NULL;
        widget<-destructor = NULL;
        widget<-parent = NULL;
        widget<-children_head = NULL;
        widget<-children_tail = NULL;
        widget<-next_siblings = NULL;
        widget<-geom_params = NULL;
        }