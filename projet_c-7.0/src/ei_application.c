//
// Created by jules on 03/05/22.
//
#include<hw_interface.h>
#include<ei_widget.h>
#include<ei_frame_t.h>
ei_widget_t *arbre_de_widget =NULL;
ei_surface_t racine;
ei_surface_t surface_cache;
void ei_app_create(ei_size_t main_window_size, ei_bool_t fullscreen)
{
        ei_widgetclass_register(&classe_frame);
        hw_init();
        racine = hw_create_window( main_window_size, fullscreen);
        surface_cache = hw_create_window(main_window_size, fullscreen);
}


void dessine_widget(ei_widget_t *widget)
{
        if (widget == NULL)
        {
                return ;
        }
       widget->wclass->drawfunc(arbre_de_widget,racine,surface_cache,NULL);
       ei_widget_t *widget_frere = widget->next_sibling;
       while( widget_frere !=NULL)
       {
               widget_frere->wclass->drawfunc(widget_frere,racine,surface_cache,NULL);
               widget_frere = widget_frere -> next_sibling;
       }
       while(widget != NULL)
       {
               dessine_widget(widget->children_head);
               widget = widget ->next_sibling;
       }
}
void ei_app_run(void)
{
        ei_widget_t * arbre_a_dessiner = arbre_de_widget;
        dessine_widget(arbre_a_dessiner);
}

void ei_app_free(void)
{

}

ei_widget_t* ei_app_root_widget(void)
{

}