//
// Created by jules on 10/05/22.
//
#include "ei_geometrymanager.h"
#include "ei_types.h"
#include<ei_event.h>

#ifndef PROJETC_IG_EI_VARIABLE_GLOBALE_H
#define PROJETC_IG_EI_VARIABLE_GLOBALE_H

#endif //PROJETC_IG_EI_VARIABLE_GLOBALE_H
/**
 * \brief	Return an address to all the widgetclass created
 *
 * @return      A pointer to all the widgetclass.
 */
ei_widgetclass_t* addr_class_cree();

/**
 * \brief	Return an address to the offscreen
 *
 * @return      A pointer to the offscreen.
 */
ei_surface_t addr_surface_cache();

/**
 * \brief	Return an address to the widgetclass of the button
 *
 * @return      A pointer to the widgetclass of the button.
 */
ei_widgetclass_t * addr_button();

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


