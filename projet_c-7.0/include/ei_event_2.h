//
// Created by jules on 17/05/22.
//

#ifndef PROJETC_IG_EI_EVENT_2_H
#include "ei_event.h"
#define PROJETC_IG_EI_EVENT_2_H

#endif //PROJETC_IG_EI_EVENT_2_H

typedef struct event_bind {
        ei_eventtype_t*  eventtype;
        ei_widget_t*    widget;
        ei_tag_t*        tag;
        ei_callback_t*   callback;
        void*           user_param;
        struct event_bind*      next;
}event_bind;

ei_color_t recherche_pick_color(int x, int y);

ei_callback_t* addr_boutton_origin();

event_bind* event_recherche(ei_event_t* event);

ei_bool_t	boutton_origin  	(ei_widget_t*		widget,
                                        struct ei_event_t*	event,
                                        void*			user_param);