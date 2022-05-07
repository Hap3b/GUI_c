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

