//

// Created by jules on 06/05/22.

// Created by jules on 10/05/22.

//

#include<ei_widget.h>
#include<ei_widgetclass.h>
#include<ei_widget.h>

void dessine_tout_widget();

typedef struct ei_frame_t {
        ei_widget_t     widget;
        ei_relief_t*     relief;
        int*            border_width;
        char*           title;
        ei_font_t*       title_fonte;
        ei_anchor_t*     title_anchor;
        ei_color_t*      color;
        ei_color_t*     color_title;
        ei_anchor_t*     ancre;
        ei_surface_t*    img;
        ei_rect_t*       img_rect;
        ei_anchor_t*     img_anchor;

}ei_frame_t;


extern ei_widgetclass_t classe_frame;

struct ei_frame_t*      ei_frame_allocfunc_t        (void);
void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);

struct ei_frame_t*      ei_frame_allocfunc_t        (void);

void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);

ei_widgetclass_t* addr_frame();