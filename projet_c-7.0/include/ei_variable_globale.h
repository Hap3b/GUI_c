//
// Created by jules on 10/05/22.
//
#include "ei_geometrymanager.h"
#include "ei_types.h"
#ifndef PROJETC_IG_EI_VARIABLE_GLOBALE_H
#define PROJETC_IG_EI_VARIABLE_GLOBALE_H

#endif //PROJETC_IG_EI_VARIABLE_GLOBALE_H

ei_surface_t* addr_surface_cache();
void ei_geometrymanager_register_tout();
ei_widgetclass_t* addr_class_cree();
ei_surface_t *addr_surface_cache();
ei_surface_t *addr_racine();

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