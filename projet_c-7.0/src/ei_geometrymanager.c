//
// Created by jules on 03/05/22.
//

#include<ei_widget.h>
#include<ei_geometrymanager.h>
#include <ei_toplevel.h>
static ei_geometrymanager_t* geometrymanager_cree = NULL;

typedef struct ei_geometry_placeur_t {
        ei_geometrymanager_t* manager;
        ei_anchor_t* anchor;
        int*  x;
        int*  y;
        float*  rel_x;
        float*  rel_y;
        int*			width;
        int*			height;
        float*			rel_width;
        float*			rel_height;
}ei_geometry_placeur_t;

void	ei_runfunc_placeur_t    (struct ei_widget_t*	widget)
{
        ei_geometry_placeur_t* placeur = ((ei_geometry_placeur_t*)(widget -> geom_params));
<<<<<<< HEAD
        if (placeur->width == 0)
=======
        if (*placeur->width == 0)
>>>>>>> refs/remotes/origin/master
        {
                *(placeur -> width) = (int) (*(placeur -> rel_width)* (float) (widget -> parent -> screen_location . size . width));
        }
<<<<<<< HEAD
        if (placeur -> height ==0)
=======
        if (*placeur -> height ==0)
>>>>>>> refs/remotes/origin/master
        {
                *(placeur -> height) = (int) (*(placeur -> rel_height) * (float) (widget -> parent -> screen_location . size .height));
        }
        widget->screen_location.size.height = *(placeur->height);
        widget->screen_location.size.width = *(placeur->width);
<<<<<<< HEAD
=======

>>>>>>> refs/remotes/origin/master
        ei_anchor_t anchor = *(placeur -> anchor);
        switch(anchor)
        {
                case  ei_anc_northwest:
<<<<<<< HEAD
                        widget -> screen_location.top_left.x = (widget->parent->screen_location.top_left.x) + *(placeur -> x) + (*(placeur -> rel_x)*(widget -> parent -> screen_location .size .height));
                        widget -> screen_location.top_left.y = (widget->parent->screen_location.top_left.y) + *(placeur -> y) + *(placeur -> rel_y)*(widget -> parent -> screen_location .size .width);
=======
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float) widget->parent->screen_location.size.width);
                        widget -> screen_location.top_left.y = (widget->parent->screen_location.top_left.y) + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float) widget->parent->screen_location.size.height);
>>>>>>> refs/remotes/origin/master
                        break;
                case ei_anc_north:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float)(widget -> parent -> screen_location.size.width)) - *(placeur ->width)/2;
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *(placeur -> y);
                        break;
                case ei_anc_northeast:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float) widget->parent->screen_location.size.width) -  *(placeur ->width);
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *(placeur -> y) + + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float) widget->parent->screen_location.size.height);
                        break;
                case ei_anc_east:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float) (widget->parent ->screen_location.size.width))- *(placeur ->width);
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float) (widget->parent->screen_location.size.height)) - *(placeur->height)/2;
                        break;
                case ei_anc_southeast:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float) widget->parent->screen_location.size.width) -  *(placeur ->width);
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float) widget->parent->screen_location.size.height) - *(placeur->height);
                        break;
                case ei_anc_south:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float) (widget -> parent -> screen_location .size .width)) - *(placeur ->width)/2;
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float) (widget -> parent -> screen_location .size .height)) - *(placeur -> height);
                        break;
                case ei_anc_southwest:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float) widget->parent->screen_location.size.width);
                        widget -> screen_location.top_left.y = (widget->parent->screen_location.top_left.y) + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float) widget->parent->screen_location.size.height) - *(placeur->height);
                        break;
                case ei_anc_west:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x);
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float) (widget -> parent -> screen_location .size .height)) - *(placeur ->height)/2;
                        break;
                case ei_anc_center:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float) (widget -> parent -> screen_location .size .width)) - *(placeur -> width)/2;
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float)(widget -> parent -> screen_location .size .height))- *(placeur ->height)/2;
                        break;
                case ei_anc_none:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *(placeur -> x) + (int) (*(placeur -> rel_x)* (float) widget->parent->screen_location.size.width);
                        widget -> screen_location.top_left.y = (widget->parent->screen_location.top_left.y) + *(placeur -> y) + (int) (*(placeur -> rel_y)* (float) widget->parent->screen_location.size.height);
                        break;
        }
};
void	ei_releasefunc_placeur_t	(struct ei_widget_t*	widget)
{

}

static ei_geometrymanager_t geom_placeur_t = {
        "geom_placeur_t",
        &ei_runfunc_placeur_t,
        &ei_releasefunc_placeur_t,
        NULL
};

ei_geometrymanager_t* addr_geom_placeur_t()
{
        return &geom_placeur_t;
}

void			ei_place			(ei_widget_t*		widget,
                                     ei_anchor_t*		anchor,
                                     int*			x,
                                     int*			y,
                                     int*			width,
                                     int*			height,
                                     float*			rel_x,
                                     float*			rel_y,
                                     float*			rel_width,
                                     float*			rel_height)
{

        struct ei_geometry_placeur_t* placeur_widget = malloc(sizeof(struct ei_geometry_placeur_t));
        ei_anchor_t* base = malloc(sizeof(ei_anchor_t));
        *base = ei_anc_northwest;
<<<<<<< HEAD
        float* zero = malloc(sizeof(int));
=======
        int * nv_height = malloc(sizeof(int));
        *nv_height = widget->parent->screen_location.size.height/10;
        int * nv_width = malloc(sizeof(int));
        *nv_width = widget->parent->screen_location.size.width/10;
        float* zero = malloc(sizeof(float));
>>>>>>> refs/remotes/origin/master
        *zero = 0;
        if (anchor != NULL)
        {
                placeur_widget -> anchor = anchor;
        }
        else
        {
                placeur_widget -> anchor = base;
        }

        if (x!= NULL)
        {
                placeur_widget ->x = x;
        }
        else
        {
                placeur_widget -> x = (int*)zero;
        }

        if (y != NULL)
        {
                placeur_widget -> y = y;
        }
        else
        {
                placeur_widget -> y = (int*)zero;
        }

        if (width ==NULL)
        {
            if (rel_width == NULL)
            {
<<<<<<< HEAD
                    placeur_widget -> width = &(widget -> requested_size.width);
=======
                    if (widget->requested_size.width == 0) {
                            *placeur_widget->width = widget->parent->screen_location.size.width/10;
                    } else {placeur_widget->width = &(widget->requested_size.width);}
>>>>>>> refs/remotes/origin/master
                    placeur_widget -> rel_width = zero;
            }
            else
            {
                    placeur_widget ->rel_width = rel_width;
                    placeur_widget -> width = (int*)zero;
            }
        }
        else
        {
                if (rel_width == NULL)
                {
<<<<<<< HEAD
                        placeur_widget->width = &(widget->requested_size.width);
=======
                        if (widget->requested_size.width == 0) {
                                placeur_widget->width = nv_width;
                        } else {placeur_widget->width = &(widget->requested_size.width);}
>>>>>>> refs/remotes/origin/master
                        placeur_widget->rel_width = zero;
                }
                else
                {
<<<<<<< HEAD
                        placeur_widget->width = &(widget->requested_size.width);
=======
                        if (widget->requested_size.width == 0) {
                                placeur_widget->width = nv_width;
                        } else {placeur_widget->width = &(widget->requested_size.width);}
>>>>>>> refs/remotes/origin/master
                        placeur_widget->rel_width = rel_width;
                }
        }

        if (height ==NULL)
        {
                if (rel_height == NULL)
                {
<<<<<<< HEAD
                        placeur_widget -> height = &(widget -> requested_size.height);
=======
                        if (widget->requested_size.height == 0) {
                                placeur_widget->height = nv_height;
                        } else {placeur_widget->height = &(widget->requested_size.height);}
>>>>>>> refs/remotes/origin/master
                        placeur_widget -> rel_height = zero;
                }
                else
                {
                        placeur_widget ->rel_height = rel_height;
                        placeur_widget -> height = (int*)zero;
                }
        }
        else
        {
                if (rel_height == NULL)
                {
<<<<<<< HEAD
                        placeur_widget->height = &(widget->requested_size.height);
                        placeur_widget->rel_height = zero;
                } else
                {
                        placeur_widget->height = &(widget->requested_size.height);
=======
                        if (widget->requested_size.height == 0) {
                                placeur_widget->height = nv_height;
                        } else {placeur_widget->height = &(widget->requested_size.height);}
                        placeur_widget->rel_height = zero;
                } else
                {
                        if (widget->requested_size.height == 0) {
                                placeur_widget->height = nv_height;
                        } else {placeur_widget->height = &(widget->requested_size.height);}
>>>>>>> refs/remotes/origin/master
                        placeur_widget->rel_height = rel_height;
                }
        }
        if (rel_x != NULL)
        {
                placeur_widget -> rel_x = rel_x;
        }
        else
        {
                placeur_widget -> rel_x = zero;
        }

        if (rel_y != NULL)
        {
                placeur_widget -> rel_y = rel_y;
        }
        else
        {
                placeur_widget -> rel_y = zero;
        }
        placeur_widget -> manager = &geom_placeur_t;
        widget -> geom_params = (ei_geometry_param_t *)placeur_widget;
        ei_runfunc_placeur_t(widget);
<<<<<<< HEAD
=======
        if (strcmp(widget->wclass->name, "toplevel") == 0 && ((ei_toplevel_t*) widget)->closable == EI_TRUE) {
                ei_anchor_t	button_anchor	= ei_anc_northwest;
                int           button_x    = 10;
                int           button_y    = 20;
                ei_place((widget->children_head), &button_anchor, &button_x, &button_y, NULL, NULL, NULL, NULL, NULL, NULL);
        }
>>>>>>> refs/remotes/origin/master

}

void			ei_geometrymanager_register	(ei_geometrymanager_t* geometrymanager)
{
        geometrymanager->next = geometrymanager_cree;
        geometrymanager_cree = geometrymanager;
}
