//
// Created by jules on 03/05/22.
//


#include<ei_widget.h>
#include <ei_variable_globale.h>

#include "ei_application.h"
#include "ei_frame_t.h"


void dessine_widget(ei_widget_t *widget)
{
        if (widget == NULL)
        {
                return ;
        }
        (*(widget->wclass->drawfunc))(widget,ei_app_root_surface(),addr_surface_cache(),NULL);
        ei_widget_t *widget_frere = widget->next_sibling;
        while( widget_frere !=NULL)
        {
                (*(widget_frere->wclass->drawfunc))(widget_frere,ei_app_root_surface(),*addr_surface_cache(),NULL);
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
        ei_widget_t* arbre = ei_app_root_widget();
        arbre ->screen_location.size.height = arbre ->requested_size.height;
        arbre ->screen_location.size.width = arbre->requested_size.width;
        dessine_widget(ei_app_root_widget());
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
    ei_frame_t* frame = (ei_frame_t*)widget;
    int* zero = malloc(sizeof(int));
    *zero = 0;
    ei_anchor_t* base = malloc(sizeof(ei_anchor_t));
    *base = ei_anc_center;
    ei_relief_t* base2 = malloc(sizeof(ei_relief_t));
    *base2 = ei_relief_none;
    if (requested_size != NULL)
    {
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
        }

        if(border_width != NULL)
        {
                frame -> border_width = border_width;
        }
        else
        {
                frame -> border_width = zero;
        }

        if (relief != NULL)
        {
                frame -> relief = relief;
        }
        else
        {
                frame -> relief = base2;
        }

        if (text != NULL)
        {
                frame -> title = text;
        }

        if ( text_font != NULL)
        {
                frame -> title_fonte = text_font;
        }
        else
        {
                frame -> title_fonte = &ei_default_font;
        }

        if (text_color != NULL)
        {
                frame -> color_title = text_color;
        }
        else
        {
                frame->color_title = &ei_font_default_color;
        }

        if (text_anchor != NULL)
        {
                frame -> title_anchor = text_anchor;
        }
        else
        {
                frame -> title_anchor = base;
        }

        if (img != NULL)
        {
                frame -> img = img;
        }

        if( img_rect != NULL)
        {
                frame -> img_rect = img_rect;
        }

        if (img_anchor != NULL)
        {
                frame -> img_anchor = img_anchor;
        }
        else
        {
                frame -> img_anchor = base;
        }

    free(zero);
    free(base);
    free(base2);
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




