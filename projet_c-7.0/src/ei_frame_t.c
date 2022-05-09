//
// Created by jules on 06/05/22.
//
#include<ei_widgetclass.h>
#include<ei_widget.h>
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



struct ei_frame_t*      ei_frame_allocfunc_t        (void)
{
        struct ei_frame_t *frame = calloc(1, sizeof(ei_frame_t));
        return frame;
};

void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame)
{
        free(frame -> relief);
        free(frame -> title);
        free(frame-> fonte);
        free(frame ->color);
        free(frame -> ancre);
        free(frame-> img);
        free(frame-> img_rect);
        free(frame -> img_anchor);
}

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
void	ei_frame_drawfunc_t		(struct ei_widget_t*	widget,
                                                      ei_surface_t		surface,
                                                      ei_surface_t		pick_surface,
                                                      ei_rect_t*		clipper)
{
        ei_color_t trans = {0xff, 0xff, 0xff, 0x00};
        ei_point_t depart = widget->screen_location.top_left;
        ei_point_t droite = depart;
        droite.x = droite.x + widget->requested_size.width;
        ei_point_t bdroite = droite;
        bdroite.y = bdroite.y - widget->requested_size.height;
        ei_point_t final = depart;
        final.y = final.y - widget->requested_size.height;
        ei_linked_point_t pol1;
        ei_linked_point_t pol2;
        ei_linked_point_t pol3;
        ei_linked_point_t pol4;
        pol1.point = depart;
        pol1.next = &pol2;
        pol2.point = droite;
        pol2.next = &pol3;
        pol3.point = bdroite;
        pol3.next = &pol4;
        pol4.point = final;
        pol4.next = NULL;
        ei_draw_polygon(surface, &pol1,*widget->pick_color, clipper);/*Si bug ça vient du top left*/
        ei_draw_polygon(pick_surface, &pol1,trans, clipper);
}

/**
 * \brief	A function that sets the default values for a class.
 *
 * @param	widget		A pointer to the widget instance to initialize.
 */

void	ei_frame_setdefaultsfunc_t	(struct ei_widget_t*	widget)
{
        struct ei_frame_t frame = &widget;
        frame.color = &ei_default_background_color;
        widget->requested_size.height = 540; /* Half screen on a 1920x1080 screen*/
        widget->requested_size.width = 960;
        frame.relief = ei_relief_none;
        frame.fonte = ei_default_font;
        frame.title = NULL;
        frame.ancre = ei_anc_center;
        frame.img_anchor = ei_anc_center;
        frame.img = NULL;
        frame.img_rect = NULL;
        widget->user_data = NULL;
        widget->destructor = NULL;
        widget->parent = NULL;
        widget->children_head = NULL;
        widget->children_tail = NULL;
        widget->next_sibling = NULL;
        widget->geom_params = NULL;
}

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

