//
<<<<<<< HEAD
<<<<<<< HEAD
// Created by jules on 06/05/22.
=======
// Created by jules on 10/05/22.
>>>>>>> ea6f1e68bf05b78dbbbf5c9959e6f2e9194aaf05
//
=======

// Created by jules on 06/05/22.

// Created by jules on 10/05/22.
>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3

//

<<<<<<< HEAD
<<<<<<< HEAD
#endif //PROJETC_IG_EI_FRAME_T_H*
#include<ei_widget.h>

=======
#endif //PROJETC_IG_EI_FRAME_T_H
#include<ei_widgetclass.h>
#include<ei_widget.h>
>>>>>>> ea6f1e68bf05b78dbbbf5c9959e6f2e9194aaf05
=======
#include<ei_widget.h>
#include<ei_widgetclass.h>
#include<ei_widget.h>

>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3
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

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3
extern ei_widgetclass_t classe_frame;

struct ei_frame_t*      ei_frame_allocfunc_t        (void);
void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);
<<<<<<< HEAD
=======
=======

>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3
struct ei_frame_t*      ei_frame_allocfunc_t        (void);

void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);

<<<<<<< HEAD
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
>>>>>>> ea6f1e68bf05b78dbbbf5c9959e6f2e9194aaf05
=======
ei_widgetclass_t* addr_frame();
>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3
