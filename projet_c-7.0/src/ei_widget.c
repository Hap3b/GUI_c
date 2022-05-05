//
// Created by jules on 03/05/22.
//

#include<hw_interface.h>
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





};

void			ei_frame_configure		(ei_widget_t*		widget,
                                           ei_size_t*		requested_size,
                                           const ei_color_t*	color,
                                           int*			border_width,
                                           ei_relief_t*		relief,
                                           char**			text,
                                           ei_font_t*		text_font,
                                           ei_color_t*		text_color,
                                           ei_anchor_t*		text_anchor,
                                           ei_surface_t*		img,
                                           ei_rect_t**		img_rect,
                                           ei_anchor_t*		img_anchor)
{


}

ei_widget_t*		ei_widget_create		(ei_widgetclass_name_t	class_name,
                                             ei_widget_t*		parent,
                                             void*			user_data,
                                             ei_widget_destructor_t destructor)
{

}

struct ei_frame_t*      ei_frame_allocfunc_t        (void)
{
    struct ei_frame_t *frame = calloc(1, sizeof(ei_frame_t));
    return frame;
};

void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame)
{
    free(frame.relief);
    free(frame.title);
    free(frame.fonte);
    free(frame.color);
    free(frame.ancre);
    free(frame.img);
    free(frame.img_rect);
    free(frame.img_anchor);
}