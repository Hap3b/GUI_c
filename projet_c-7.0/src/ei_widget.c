//
// Created by jules on 03/05/22.
//


#include<ei_widget.h>
#include <ei_variable_globale.h>
#include "ei_application.h"
#include "ei_frame_t.h"
#include "ei_event_2.h"
#include<ei_button.h>
#include<ei_toplevel.h>
ei_color_t couleur_off_screnn = {0,0,0,255};

void incremente_couleur_off_screen()
{
        if (couleur_off_screnn.red <255)
        {
                couleur_off_screnn.red++;
        }
        else
        {
                if (couleur_off_screnn.green < 255)
                {
                        couleur_off_screnn.green++;
                } else
                {
                        couleur_off_screnn.blue++;
                }
        }
}


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
                (*(widget_frere->wclass->drawfunc))(widget_frere,ei_app_root_surface(),addr_surface_cache(),NULL);
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
    if (requested_size != NULL)
    {
        widget->requested_size.width = requested_size->width;
        widget->requested_size.height = requested_size->height;
    }

    if (color != NULL)
        {
                frame -> color = *color;
        }

        if(border_width != NULL)
        {
                frame -> border_width = *border_width;
        }

        if (relief != NULL)
        {
                frame -> relief = *relief;
        }

        if (text != NULL)
        {
                frame -> title = *text;
        }

        if ( text_font != NULL)
        {
                frame -> title_fonte = *text_font;
        }

        if (text_color != NULL)
        {
                frame -> color_title = *text_color;
        }


        if (text_anchor != NULL)
        {
                frame -> title_anchor = *text_anchor;
        }

        if (img != NULL)
        {
                frame -> img = *img;
        }

        if( img_rect != NULL)
        {
                frame -> img_rect = *img_rect;
        }

        if (img_anchor != NULL)
        {
                frame -> img_anchor = *img_anchor;
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
        while ( classe_cree != NULL && strcmp(classe_cree ->name, class_name) !=0)
        {
                classe_cree = classe_cree ->next;
        }
        if(classe_cree != NULL)
        {
                ei_widget_t *new_widget = classe_cree->allocfunc();
                classe_cree->setdefaultsfunc(new_widget);
                new_widget -> pick_color = malloc(sizeof(ei_color_t));
                *(new_widget -> pick_color) = couleur_off_screnn;
                incremente_couleur_off_screen();
                new_widget->user_data = user_data;
                new_widget->parent = parent;
                ei_rajoute_widget_abr_widget(parent,new_widget);
                if (strcmp(classe_cree->name,"button") ==0 )
                {
                        ei_callback_t button_clique = addr_boutton_origin();
                        ei_bind(ei_ev_mouse_buttondown,new_widget,NULL,button_clique,NULL);
                }
                return new_widget;
        }
        else
        {
                printf("La classe voulu n'existe pas");
        }

}

void			ei_button_configure		(ei_widget_t*		widget,
                                                                ei_size_t*		requested_size,
                                                                const ei_color_t*	color,
                                                                int*			border_width,
                                                                int*			corner_radius,
                                                                ei_relief_t*		relief,
                                                                char**			text,
                                                                ei_font_t*		text_font,
                                                                ei_color_t*		text_color,
                                                                ei_anchor_t*		text_anchor,
                                                                ei_surface_t*		img,
                                                                ei_rect_t**		img_rect,
                                                                ei_anchor_t*		img_anchor,
                                                                ei_callback_t*		callback,
                                                                void**			user_param)
{
        ei_button_t* button = (ei_button_t*) widget;

        if (requested_size != NULL)
        {
                widget->requested_size.width = requested_size->width;
                widget->requested_size.height = requested_size->height;
        }

        if (color != NULL)
        {
            button -> color = *color;
        }

        if(border_width != NULL)
        {
                button -> border_width = *border_width;
        }

        if (relief != NULL)
        {
                button -> relief = *relief;
        }

        if (text != NULL)
        {
                button -> text = *text;
        }

        if ( text_font != NULL)
        {
                button -> text_font = *text_font;
        }


        if (text_color != NULL)
        {
                button -> text_color = *text_color;
        }

        if (text_anchor != NULL)
        {
                button -> text_anchor = *text_anchor;
        }

        if (img != NULL)
        {
                button -> img = *img;
        }

        if( img_rect != NULL)
        {
                 button -> img_rect = *img_rect;
        }

        if (img_anchor != NULL)
        {
                button -> img_anchor = *img_anchor;
        }

        if (corner_radius != NULL)
        {
                button -> corner_radius = *corner_radius;
        }

        //button->callback = callback;
        //button->user_param = *user_param;
}

void			ei_toplevel_configure		(ei_widget_t*		widget,
                                                                  ei_size_t*		requested_size,
                                                                  ei_color_t*		color,
                                                                  int*			border_width,
                                                                  char**			title,
                                                                  ei_bool_t*		closable,
                                                                  ei_axis_set_t*		resizable,
                                                                  ei_size_t**		min_size)
{
        ei_toplevel_t* toplevel = (ei_toplevel_t*)widget;
        if (requested_size != NULL)
        {
                widget->requested_size.width = requested_size->width;
                widget->requested_size.height = requested_size->height;
        }
        if (color != NULL)
        {
                toplevel->color = *color;
        }
        if (border_width != NULL)
        {
                toplevel-> border_width = *border_width;
        }
        if (title != NULL)
        {
                toplevel->title = *title;
        }
        if (closable != NULL)
        {
                toplevel->closable = *closable;
        }
        if (resizable != NULL)
        {
                toplevel->resizable = *resizable;
        }
        if (min_size != NULL)
        {
                toplevel->min_size = *min_size;
        } ajoute_boutton_haut_gauche (widget);

}