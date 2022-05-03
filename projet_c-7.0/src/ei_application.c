//
// Created by jules on 03/05/22.
//
#include<hw_interface.h>
#include<ei_widget.h>

void ei_app_create(ei_size_t main_window_size, ei_bool_t fullscreen)
{
        hw_init();
        hw_create_window( main_window_size, fullscreen);
}

void ei_app_run(void)
{
        getchar();
}

void ei_app_free(void)
{

}

ei_widget_t* ei_app_root_widget(void)
{

}