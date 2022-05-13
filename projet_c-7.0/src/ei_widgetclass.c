//
// Created by jules on 03/05/22.
//
#include<ei_widgetclass.h>

static ei_widgetclass_t *classe_cree =NULL;


void ei_widgetclass_register(ei_widgetclass_t * widgetclass){
        widgetclass -> next = classe_cree;
        classe_cree = widgetclass;
}

ei_widgetclass_t* addr_class_cree(){
        return classe_cree;
}