//
// Created by jules on 03/05/22.
//
#include<hw_interface.h>
#include<ei_widget.h>
#include<ei_frame_t.h>
#include<ei_variable_globale.h>
#include <ei_geometrymanager.h>
#include<ei_event_2.h>
#include <ei_toplevel.h>

static ei_surface_t racine = NULL;
static ei_surface_t surface_cache = NULL;
static ei_widget_t *arbre_de_widget = NULL;
static ei_bool_t quit = EI_FALSE;

void ei_app_quit_request(void)
{
        quit = EI_TRUE;
}

ei_surface_t addr_surface_cache(){
        return surface_cache;
}

void ei_app_create(ei_size_t main_window_size, ei_bool_t fullscreen)
{
        ei_widgetclass_register(addr_frame());
        ei_widgetclass_register(addr_button());
        ei_widgetclass_register(addr_toplevel());
        ei_geometrymanager_register(addr_geom_placeur_t());
        hw_init();
        racine = hw_create_window(main_window_size, fullscreen);
        surface_cache = hw_surface_create(racine, main_window_size, EI_FALSE);
}


void ei_app_run(void) {/* Create, configure and place the button on screen. */
        dessine_tout_widget();
        hw_surface_update_rects(racine, NULL);
        struct ei_event_t *event_cur = malloc(sizeof(struct ei_event_t));
        while (!quit) {
                    hw_event_wait_next(event_cur);
                    ei_widget_t* widget = NULL;
                    event_bind *event_traite = event_recherche(event_cur, &widget);
                    while (event_traite != NULL) {
                        ei_bool_t should_continue = event_traite->callback(widget, event_cur,
                                                                           event_traite->user_param);
                        event_traite = event_traite->next;
                    }
                    hw_surface_update_rects(racine, NULL);
        }
}


void ei_app_free(void)
{
        hw_quit();
}

ei_widget_t* ei_app_root_widget(void)
{
        if (arbre_de_widget == NULL){
                ei_widget_t* racine_bis = ei_widget_create("frame", NULL, NULL,NULL);
                ei_size_t surface_racine = hw_surface_get_size(racine);
                ei_frame_configure(racine_bis, &surface_racine, NULL, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
                arbre_de_widget = racine_bis;
        }
        return arbre_de_widget;
}

ei_surface_t ei_app_root_surface(void)
{
        return racine;
}