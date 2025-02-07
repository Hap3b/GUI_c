//
// Created by jules on 03/05/22.
//

#include<ei_widget.h>
#include<ei_geometrymanager.h>
#include <ei_toplevel.h>
static ei_geometrymanager_t* geometrymanager_cree = NULL;

typedef struct ei_geometry_placeur_t {
        ei_geometrymanager_t manager;
        ei_anchor_t anchor;
        int  x;
        int y;
        float  rel_x;
        float  rel_y;
        int			width;
        int			height;
        float			rel_width;
        float			rel_height;
}ei_geometry_placeur_t;

void	ei_runfunc_placeur_t    (struct ei_widget_t*	widget)
{
        ei_geometry_placeur_t* placeur = ((ei_geometry_placeur_t*)(widget -> geom_params));
        if (placeur->width == 0)
        {
            (placeur -> width) = (int) ((placeur -> rel_width)* (float) (widget -> parent -> screen_location . size . width));
        }
        if (placeur -> height ==0)
        {
            (placeur -> height) = (int) ((placeur -> rel_height) * (float) (widget -> parent -> screen_location . size .height));
        }
        widget->screen_location.size.height = (placeur->height);
        widget->screen_location.size.width = (placeur->width);

        ei_anchor_t anchor = (placeur -> anchor);
        switch(anchor)
        {
                case  ei_anc_northwest:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x) + (int) ((placeur -> rel_x)* (float) widget->parent->screen_location.size.width);
                        widget -> screen_location.top_left.y = (widget->parent->screen_location.top_left.y) + (placeur -> y) + (int) ((placeur -> rel_y)* (float) widget->parent->screen_location.size.height);
                        break;
                case ei_anc_north:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x) + (int) ((placeur -> rel_x)* (float)(widget -> parent -> screen_location.size.width)) - (placeur ->width)/2;
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + (placeur -> y);
                        break;
                case ei_anc_northeast:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + + (placeur -> x) + (int) ((placeur -> rel_x)* (float) widget->parent->screen_location.size.width) -  (placeur ->width);
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + (placeur -> y) + + (placeur -> y) + (int) ((placeur -> rel_y)* (float) widget->parent->screen_location.size.height);
                        break;
                case ei_anc_east:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x) + (int) ((placeur -> rel_x)* (float) (widget->parent ->screen_location.size.width))- (placeur ->width);
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + (placeur -> y) + (int) ((placeur -> rel_y)* (float) (widget->parent->screen_location.size.height)) - (placeur->height)/2;
                        break;
                case ei_anc_southeast:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x) + (int) ((placeur -> rel_x)* (float) widget->parent->screen_location.size.width) -  (placeur ->width);
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + (placeur -> y) + (int) ((placeur -> rel_y)* (float) widget->parent->screen_location.size.height) - (placeur->height);
                        break;
                case ei_anc_south:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x) + (int) ((placeur -> rel_x)* (float) (widget -> parent -> screen_location .size .width)) - (placeur ->width)/2;
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + (placeur -> y) + (int) ((placeur -> rel_y)* (float) (widget -> parent -> screen_location .size .height)) - (placeur -> height);
                        break;
                case ei_anc_southwest:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x) + (int) ((placeur -> rel_x)* (float) widget->parent->screen_location.size.width);
                        widget -> screen_location.top_left.y = (widget->parent->screen_location.top_left.y) + (placeur -> y) + (int) ((placeur -> rel_y)* (float) widget->parent->screen_location.size.height) - (placeur->height);
                        break;
                case ei_anc_west:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x);
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + (placeur -> y) + (int) ((placeur -> rel_y)* (float) (widget -> parent -> screen_location .size .height)) - (placeur ->height)/2;
                        break;
                case ei_anc_center:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x) + (int) ((placeur -> rel_x)* (float) (widget -> parent -> screen_location .size .width)) - (placeur -> width)/2;
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + (placeur -> y) + (int) ((placeur -> rel_y)* (float)(widget -> parent -> screen_location .size .height))- (placeur ->height)/2;
                        break;
                case ei_anc_none:
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + (placeur -> x) + (int) ((placeur -> rel_x)* (float) widget->parent->screen_location.size.width);
                        widget -> screen_location.top_left.y = (widget->parent->screen_location.top_left.y) + (placeur -> y) + (int) ((placeur -> rel_y)* (float) widget->parent->screen_location.size.height);
                        break;
        }
        if((widget->wclass->geomnotifyfunc) != NULL)
        {
            ((widget->wclass->geomnotifyfunc))(widget);
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
        ei_anchor_t base = ei_anc_northwest;
        int  nv_height = widget->parent->screen_location.size.height/10;
        int  nv_width = widget->parent->screen_location.size.width/10;
        int zero = 0;
        if (anchor != NULL)
        {
                placeur_widget -> anchor = *anchor;
        }
        else
        {
                placeur_widget -> anchor = base;
        }

        if (x != NULL)
        {
                placeur_widget ->x = *x;
        }
        else
        {
                placeur_widget -> x = zero;
        }

        if (y != NULL)
        {
                placeur_widget -> y = *y;
        }
        else
        {
                placeur_widget -> y = zero;
        }

        if (width ==NULL)
        {
            if (rel_width == NULL)
            {
                    if (widget->requested_size.width == 0) {
                            placeur_widget->width = widget->parent->screen_location.size.width/10;
                    } else {placeur_widget->width = widget->requested_size.width;}
                    placeur_widget -> rel_width = (float)zero;
            }
            else
            {
                    placeur_widget ->rel_width = *rel_width;
                    placeur_widget -> width = zero;
            }
        }
        else
        {
                if (rel_width == NULL)
                {
                        if (widget->requested_size.width == 0) {
                                placeur_widget->width = nv_width;
                        } else {placeur_widget->width = widget->requested_size.width;}
                        placeur_widget->rel_width = (float)zero;
                }
                else
                {
                        if (widget->requested_size.width == 0) {
                                placeur_widget->width = nv_width;
                        } else {placeur_widget->width = widget->requested_size.width;}
                        placeur_widget->rel_width = *rel_width;
                }
        }

        if (height ==NULL)
        {
                if (rel_height == NULL)
                {
                        if (widget->requested_size.height == 0) {
                                placeur_widget->height = nv_height;
                        } else {placeur_widget->height = widget->requested_size.height;}
                        placeur_widget -> rel_height = (float)zero;
                }
                else
                {
                        placeur_widget ->rel_height = *rel_height;
                        placeur_widget -> height = zero;
                }
        }
        else
        {
                if (rel_height == NULL)
                {
                        if (widget->requested_size.height == 0) {
                                placeur_widget->height = nv_height;
                        } else {placeur_widget->height = (widget->requested_size.height);}
                        placeur_widget->rel_height = (float)zero;
                } else
                {
                        if (widget->requested_size.height == 0) {
                                placeur_widget->height = nv_height;
                        } else {placeur_widget->height = (widget->requested_size.height);}
                        placeur_widget->rel_height = *rel_height;
                }
        }
        if (rel_x != NULL)
        {
                placeur_widget -> rel_x = *rel_x;
        }
        else
        {
                placeur_widget -> rel_x = (float)zero;
        }

        if (rel_y != NULL)
        {
                placeur_widget -> rel_y = *rel_y;
        }
        else
        {
                placeur_widget -> rel_y = (float)zero;
        }
        placeur_widget -> manager = geom_placeur_t;
        widget -> geom_params = (ei_geometry_param_t *)placeur_widget;
        ei_runfunc_placeur_t(widget);

}

void			ei_geometrymanager_register	(ei_geometrymanager_t* geometrymanager)
{
        geometrymanager->next = geometrymanager_cree;
        geometrymanager_cree = geometrymanager;
}
