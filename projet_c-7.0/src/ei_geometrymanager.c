//
// Created by jules on 03/05/22.
//

#include<ei_widget.h>
#include<ei_geometrymanager.h>
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
        if (((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor =  ei_anc_northwest || ((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor ==  NULL)
        {
                widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + ((ei_geometry_placeur_t*)(widget -> geom_params)) -> x;
                widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + ((ei_geometry_placeur_t*)(widget -> geom_params)) -> y;
                widget -> screen_location.size.width = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> width;
                widget -> screen_location.size.height = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> height;
        }
        else
        {
                if(((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor =  ei_anc_north)
                {
                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> x - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> width)/2;
                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> y;
                        widget -> screen_location.size.width = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> width;
                        widget -> screen_location.size.height = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> height;
                }
                else
                {
                        if(((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor =  ei_anc_east)
                        {
                                widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> x - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> width);
                                widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> y - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> height)/2;
                                widget -> screen_location.size.width = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> width;
                                widget -> screen_location.size.height = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> height;
                        }
                        else
                        {
                                if (((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor =  ei_anc_southeast)
                                {
                                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> x - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> width);
                                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> y - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> height);
                                        widget -> screen_location.size.width = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> width;
                                        widget -> screen_location.size.height = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> height;
                                }
                                else
                                {
                                        if (((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor =  ei_anc_south)
                                        {
                                                widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> x - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> width)/2;
                                                widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> y - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> height);
                                                widget -> screen_location.size.width = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> width;
                                                widget -> screen_location.size.height = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> height;
                                        }
                                        else
                                        {
                                                if (((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor =  ei_anc_southwest)
                                                {
                                                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> x;
                                                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> y - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> height);
                                                        widget -> screen_location.size.width = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> width;
                                                        widget -> screen_location.size.height = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> height;
                                                }
                                                else
                                                {
                                                        if (((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor =  ei_anc_west)
                                                        {
                                                                widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> x;
                                                                widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> y - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> height)/2;
                                                                widget -> screen_location.size.width = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> width;
                                                                widget -> screen_location.size.height = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> height;
                                                        }
                                                        else
                                                        {
                                                                if (((ei_geometry_placeur_t*)(widget -> geom_params)) -> anchor =  ei_anc_northeast)
                                                                {
                                                                        widget -> screen_location.top_left.x = widget->parent->screen_location.top_left.x + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> x - *(((ei_geometry_placeur_t*)(widget -> geom_params)) -> width);
                                                                        widget -> screen_location.top_left.y = widget->parent->screen_location.top_left.y + *((ei_geometry_placeur_t*)(widget -> geom_params)) -> y;
                                                                        widget -> screen_location.size.width = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> width;
                                                                        widget -> screen_location.size.height = ((ei_geometry_placeur_t*)(widget -> geom_params)) -> height;
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
};
void	ei_releasefunc_placeur_t	(struct ei_widget_t*	widget)
{

}

extern struct ei_geometrymanager_t geom_placeur_t = {
        "geom_placeur_t",
        &ei_runfunc_placeur_t,
        &ei_releasefunc_placeur_t,
        NULL
};


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

        struct ei_geometry_placeur_t* placeur_widget = (ei_geometry_placeur_t *)malloc(sizeof(struct ei_geometry_placeur_t));
        placeur_widget -> manager = &geom_placeur_t;
        placeur_widget -> anchor = anchor;
        placeur_widget ->x = x;
        placeur_widget -> y = y;
        placeur_widget -> width = width;
        placeur_widget -> height = height;
        placeur_widget -> rel_x = rel_x;
        placeur_widget -> rel_y = rel_y;
        placeur_widget -> rel_width = rel_width;
        placeur_widget -> rel_height = rel_height;
        widget -> geom_params = placeur_widget;
        ei_runfunc_placeur_t(widget);


}
void ei_geometrymanager_register_tout()
{
        ei_geometrymanager_t* geometrymanager_cree_bis = geometrymanager_cree;
        while (geometrymanager_cree_bis != NULL)
        {
                ei_geometrymanager_register(geometrymanager_cree_bis);
                geometrymanager_cree_bis = geometrymanager_cree_bis -> next;
        }
}
void			ei_geometrymanager_register	(ei_geometrymanager_t* geometrymanager)
{
        geometrymanager->next = geometrymanager_cree;
        geometrymanager_cree = geometrymanager;
}
