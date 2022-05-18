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
        ei_callback_t   callback;
        void*           user_param;
        struct event_bind*      next;
}event_bind;

/**
 * @brief Select the pick_color in the offscreen
 *
 * @param       x
 * @param       y           Coordinate of a point.
 *
 * @return                  The color in the offscreen in the point given
 */

ei_color_t recherche_pick_color(int x, int y);

/**
 * @brief Return the address of the button origin (for the rise or not of the bottom)
 *
 * @return                  The address of the button origin.
 */
ei_callback_t addr_boutton_origin();

/**
 * @brief Search in a linked list the event and the events following it
 *
 * @param       event           Event to search.
 *
 * @return                      The linked list of the events to do after.
 */

event_bind* event_recherche(ei_event_t* event);

/**
 * @brief If a value of a frame is not precised, this value is set by this function
 *
 * @param       frame           Frame to configure by default.
 */
ei_bool_t	boutton_origin  	(ei_widget_t*		widget,
                                        struct ei_event_t*	event,
                                        void*			user_param);