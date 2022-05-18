//
// Created by jules on 06/05/22.
//
#include<ei_widgetclass.h>
#include<ei_widget.h>
#include "ei_variable_globale.h"
#include "ei_fct_annexes.h"*
#include "hw_interface.h"
void	ei_frame_setdefaultsfunc_t	(struct ei_widget_t*	frame);
typedef struct ei_frame_t {
        ei_widget_t     widget;
        ei_relief_t     relief;
        int            border_width;
        char*           title;
        ei_font_t       title_fonte;
        ei_anchor_t     title_anchor;
        ei_color_t      color;
        ei_color_t     color_title;
        ei_anchor_t     ancre;
        ei_surface_t    img;
        ei_rect_t*       img_rect;
        ei_anchor_t     img_anchor;


}ei_frame_t;




struct ei_widget_t*      ei_frame_allocfunc_t        (void)
{
        struct ei_frame_t *frame = calloc(1, sizeof(ei_frame_t));
        return (ei_widget_t*)frame;
};

void        ei_frame_releasefunc_t      (struct ei_widget_t*	frame)
{
        free(frame);
};

void	ei_frame_drawfunc_t		(struct ei_widget_t*	widget,
                                                ei_surface_t		surface,
                                                ei_surface_t		pick_surface,
                                                ei_rect_t*		clipper)
{
        ei_frame_t* frame = (ei_frame_t*)widget;
        ei_point_t depart = widget->screen_location.top_left;
        ei_point_t droite = depart;
        droite.x = droite.x + widget->screen_location.size.width;
        ei_point_t bdroite = droite;
        bdroite.y = bdroite.y + widget->screen_location.size.height;
        ei_point_t final = depart;
        final.y = final.y + widget->screen_location.size.height;
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
        hw_surface_lock(pick_surface);
        ei_draw_polygon(pick_surface, &pol1,*(widget->pick_color), clipper);
        hw_surface_unlock(pick_surface);

        ei_draw_polygon(surface, &pol1,(frame->color), clipper);

        frame->color.blue = min(frame->color.blue + 10, 255);
        frame->color.green = min(frame->color.green + 10, 255);
        frame->color.red = min(frame->color.red + 10, 255);

        ei_point_t depart_b = widget->screen_location.top_left;
        ei_point_t final_b = depart_b;
        ei_point_t droite_b = depart_b;
        ei_point_t bdroite_b = droite_b;
        depart_b.x = depart_b.x + frame->border_width;
        depart_b.y = depart_b.y + frame->border_width;
        droite_b.x = droite_b.x + widget->screen_location.size.width - frame->border_width;
        droite_b.y = droite_b.y + frame->border_width;
        bdroite_b.y = bdroite_b.y + widget->screen_location.size.height - frame->border_width;
        bdroite_b.x = bdroite_b.x + widget->screen_location.size.width -  frame->border_width;
        final_b.y = final_b.y + widget->screen_location.size.height - frame->border_width;
        final_b.x = final_b.x + frame->border_width;
        ei_linked_point_t pol1_b;
        ei_linked_point_t pol2_b;
        ei_linked_point_t pol3_b;
        ei_linked_point_t pol4_b;
        pol1_b.point = depart_b;
        pol1_b.next = &pol2_b;
        pol2_b.point = droite_b;
        pol2_b.next = &pol3_b;
        pol3_b.point = bdroite_b;
        pol3_b.next = &pol4_b;
        pol4_b.point = final_b;
        pol4_b.next = NULL;
        hw_surface_lock(surface);

        ei_draw_polygon(surface, &pol1_b,(frame->color), clipper);
        ei_rect_t* rectangle = malloc(sizeof(ei_rect_t));
        *rectangle = hw_surface_get_rect(surface);
        hw_surface_unlock(surface);
        if (frame->title != NULL) {
                ei_point_t* where_text = anchor_to_point((ei_anchor_t *) frame->title_anchor, rectangle);
                ei_draw_text(surface,
                             where_text,
                             frame->title,
                             frame->title_fonte,
                             frame->color_title,
                             clipper);
        }

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
        ((ei_frame_t *)frame)->border_width = 0;
        ((ei_frame_t *)frame)->title = NULL;
        ((ei_frame_t *)frame)->title_fonte = ei_default_font;
        ((ei_frame_t *)frame)->title_anchor = ei_anc_center;
        ((ei_frame_t *)frame)->color = ei_default_background_color;
        ((ei_frame_t *)frame)->color_title = ei_default_background_color;
        ((ei_frame_t *)frame)->img_rect = NULL;
        ((ei_frame_t*)frame)->img_anchor = ei_anc_center;

        ((ei_frame_t *)frame)->ancre = ei_anc_northwest;


};



ei_widgetclass_t* addr_frame(){
        return &classe_frame;
}
