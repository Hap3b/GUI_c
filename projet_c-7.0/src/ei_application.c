//
// Created by jules on 03/05/22.
//
#include<hw_interface.h>
#include<ei_widget.h>
#include<ei_frame_t.h>
#include<ei_variable_globale.h>
#include <ei_geometrymanager.h>
static ei_surface_t racine;
static ei_surface_t surface_cache;
void ei_app_create(ei_size_t main_window_size, ei_bool_t fullscreen)
{
        ei_widgetclass_register(&classe_frame);
        ei_geometrymanager_register_tout();
        hw_init();
        racine = hw_create_window( main_window_size, fullscreen);
        surface_cache = hw_create_window(main_window_size, fullscreen);
}

ei_surface_t* addr_surface_cache()
{
        return &surface_cache;
}

void ei_app_run(void)
{
        dessine_tout_widget();
}

void ei_app_free(void)
{

}

ei_widget_t* ei_app_root_widget(void)
{

}

ei_surface_t ei_app_root_surface(void)
{
        return racine;
}