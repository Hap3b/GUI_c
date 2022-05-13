//
// Created by jules on 03/05/22.
//


#include<ei_widget.h>
#include <ei_variable_globale.h>
#include <ei_geometrymanager.h>
#include "ei_application.h"

struct ei_widget_t *arbre_de_widget =NULL;
void dessine_widget(ei_widget_t *widget)
{
        if (widget == NULL)
        {
                return ;
        }
        widget->wclass->drawfunc(arbre_de_widget,ei_app_root_surface(),*addr_surface_cache(),NULL);
        ei_widget_t *widget_frere = widget->next_sibling;
        while( widget_frere !=NULL)
        {
                widget_frere->wclass->drawfunc(widget_frere,ei_app_root_surface(),*addr_surface_cache(),NULL);
                widget_frere = widget_frere -> next_sibling;
        }
        while(widget != NULL)
        {
                dessine_widget(widget->children_head);
                widget = widget ->next_sibling;
        }
}
void dessine_tout_widget()
{
        dessine_widget(arbre_de_widget);
}

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
        if (color == NULL)
        {
                widget -> pick_color = &ei_default_background_color;
        }
        else
        {
                widget -> pick_color = color;
        }

}

ei_widget_t*		ei_widget_create		(ei_widgetclass_name_t	class_name,
                                             ei_widget_t*		parent,
                                             void*			user_data,
                                             ei_widget_destructor_t destructor)
{
        ei_widgetclass_t* classe_cree = addr_class_cree();
        while ( classe_cree != NULL && classe_cree ->name != class_name)
        {
                classe_cree = classe_cree ->next;
        }
        ei_widget_t* new_widget = classe_cree ->allocfunc();
        classe_cree ->setdefaultsfunc(new_widget);
        new_widget ->user_data = user_data;
        new_widget -> parent = parent


}

void ei_rajoute_widget_abr_widget(ei_widget_t* widget)
{
        if (arbre_de_widget == NULL)
        {
                arbre_de_widget = widget ;
        }

        ei_widget_t *widget_frere = widget->next_sibling;

        while( widget_frere !=NULL && widget_frere != widget ->parent)
        {
                widget_frere = widget_frere ->next_sibling;
        }
        if (widget_frere != NULL)
                widget_frere -> children_tail -> next_sibling = widget
        while(widget != NULL)
        {
                dessine_widget(widget->children_head);
                widget = widget ->next_sibling;
        }

