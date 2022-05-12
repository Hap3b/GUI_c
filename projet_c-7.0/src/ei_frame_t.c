//
// Created by jules on 06/05/22.
//
#include<ei_widgetclass.h>
#include<ei_widget.h>
#include "ei_variable_globale.h"
void	ei_frame_setdefaultsfunc_t	(struct ei_widget_t*	frame);
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
};

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
        ei_frame_t* frame = (ei_frame_t*)widget;
        ei_surface_t * racine_bis = addr_racine();
        hw_surface_lock(racine_bis);
        ei_draw_polygon(surface, &pol1,*(frame->color), clipper);
        ei_draw_polygon(pick_surface, &pol1,trans, clipper);
        hw_surface_unlock(racine_bis);
};
static ei_widgetclass_t classe_frame =
        {
                "frame",
                &ei_frame_allocfunc_t,
                &ei_frame_releasefunc_t,
                &ei_frame_drawfunc_t,
                &ei_frame_setdefaultsfunc_t,
                NULL,
                NULL
        };

void	ei_frame_setdefaultsfunc_t	(struct ei_widget_t*	frame)
{
        frame -> wclass = &classe_frame;
        frame->requested_size.height = 540; /* Half screen on a 1920x1080 screen*/
        frame->requested_size.width = 960;
        frame ->user_data = NULL;
        frame-> destructor = NULL;
        frame->parent = NULL;
        frame->children_head = NULL;
        frame->children_tail = NULL;
        frame->next_sibling = NULL;
        frame->geom_params = NULL;
        ((ei_frame_t *)frame)->relief = ei_relief_none;
        ((ei_frame_t *)frame)->fonte = ei_default_font;
        ((ei_frame_t *)frame)->title = NULL;
        ((ei_frame_t *)frame)->ancre = ei_anc_center;
        ((ei_frame_t *)frame)->img_anchor = ei_anc_center;
        ((ei_frame_t *)frame)->img = NULL;
        ((ei_frame_t *)frame)->img_rect = NULL;
        ((ei_frame_t*)frame)->color = &ei_default_background_color;

};



ei_widgetclass_t* addr_frame(){
        return &classe_frame;
}
