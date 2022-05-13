//
// Created by jules on 03/05/22.
//

<<<<<<< HEAD
=======

#include<ei_widget.h>
#include <ei_variable_globale.h>
#include <ei_geometrymanager.h>
#include "ei_application.h"
#include "ei_frame_t.h"
>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3

#include<ei_widget.h>
#include <ei_variable_globale.h>
#include <ei_geometrymanager.h>
#include "ei_application.h"

<<<<<<< HEAD
struct ei_widget_t *arbre_de_widget =NULL;
=======
>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3
void dessine_widget(ei_widget_t *widget)
{
        if (widget == NULL)
        {
                return ;
        }
<<<<<<< HEAD
        widget->wclass->drawfunc(arbre_de_widget,ei_app_root_surface(),*addr_surface_cache(),NULL);
        ei_widget_t *widget_frere = widget->next_sibling;
        while( widget_frere !=NULL)
        {
                widget_frere->wclass->drawfunc(widget_frere,ei_app_root_surface(),*addr_surface_cache(),NULL);
=======
        (*(widget->wclass->drawfunc))(widget,ei_app_root_surface(),addr_surface_cache(),NULL);
        ei_widget_t *widget_frere = widget->next_sibling;
        while( widget_frere !=NULL)
        {
                (*(widget_frere->wclass->drawfunc))(widget_frere,ei_app_root_surface(),*addr_surface_cache(),NULL);
>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3
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
<<<<<<< HEAD
        dessine_widget(arbre_de_widget);
=======
        ei_widget_t* arbre = ei_app_root_widget();
        arbre ->screen_location.size.height = arbre ->requested_size.height;
        arbre ->screen_location.size.width = arbre->requested_size.width;
        dessine_widget(ei_app_root_widget());
>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3
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
<<<<<<< HEAD
        if (color == NULL)
        {
                widget -> pick_color = &ei_default_background_color;
        }
        else
        {
                widget -> pick_color = color;
=======
    ei_frame_t* frame = (ei_frame_t*)widget;
    if (requested_size != NULL) {
        widget->requested_size.width = requested_size->width;
        widget->requested_size.height = requested_size->height;
    }

    if (color == NULL)
        {
                frame -> color = &ei_default_background_color;
        }
        else
        {
                frame -> color = color;
>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3
        }

}
void ei_rajoute_widget_abr_widget(ei_widget_t* parent,ei_widget_t* widget)
{
        if (parent == NULL)
        {
            return;
        }
        else
        {
            widget ->next_sibling = parent -> children_head;
            parent -> children_head = widget;
        }
}

ei_widget_t*		ei_widget_create		(ei_widgetclass_name_t	class_name,
                                             ei_widget_t*		parent,
                                             void*			user_data,
                                             ei_widget_destructor_t destructor)
{
        ei_widgetclass_t* classe_cree = addr_class_cree();
<<<<<<< HEAD
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
=======
        while ( classe_cree != NULL && strcmp(classe_cree ->name, class_name) !=0)
        {
                classe_cree = classe_cree ->next;
        }
        if(classe_cree != NULL)
        {
                ei_widget_t *new_widget = classe_cree->allocfunc();
                classe_cree->setdefaultsfunc(new_widget);
                new_widget->user_data = user_data;
                new_widget->parent = parent;
                ei_rajoute_widget_abr_widget(parent,new_widget);
                return new_widget;
        }
        else
        {
                printf("La classe voulu n'existe pas");
        }

}



>>>>>>> cbebcfa349c1d78f4212ff0bdf7bec844ff196a3

