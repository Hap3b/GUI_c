//
// Created by jules on 10/05/22.
//
#include "ei_geometrymanager.h"
#include "ei_types.h"
#include<ei_event.h>

#ifndef PROJETC_IG_EI_VARIABLE_GLOBALE_H
#define PROJETC_IG_EI_VARIABLE_GLOBALE_H

#endif //PROJETC_IG_EI_VARIABLE_GLOBALE_H

<<<<<<< HEAD
/**
 * It is the address of all the widget class created
 */
ei_widgetclass_t* addr_class_cree();
/**
 * It is the address of the offscreen
 */
ei_surface_t addr_surface_cache();
=======
ei_widgetclass_t* addr_class_cree();

ei_surface_t addr_surface_cache();


ei_widgetclass_t * addr_button();
>>>>>>> refs/remotes/origin/master

/**
 * It is the address of the widget class button
 */
ei_widgetclass_t * addr_button();

/**
 *
 */
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


ei_geometrymanager_t* addr_geom_placeur_t();

/*typedef struct event_bind {
        ei_eventtype_t*  eventtype;
        ei_widget_t*    widget;
        ei_tag_t*        tag;
        ei_callback_t*   callback;
        void*           user_param;
        struct event_bind*      next;
}event_bind;*/

/*event_bind* recherche_event(ei_event_t* event);*/


