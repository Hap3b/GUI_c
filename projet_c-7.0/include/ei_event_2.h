//
// Created by jules on 17/05/22.
//

#ifndef PROJETC_IG_EI_EVENT_2_H
#include "ei_event.h"
#define PROJETC_IG_EI_EVENT_2_H

#endif //PROJETC_IG_EI_EVENT_2_H


/**
 * @brief	The types of events bind with the call of ei_bind().
 */

typedef struct event_bind {
        ei_eventtype_t*  eventtype;
        ei_widget_t*    widget;
        ei_tag_t        tag;
        ei_callback_t   callback;
        void*           user_param;
        struct event_bind*      next;
}event_bind;

/**
 * \brief	Find the color of the pick surface pixel at the mouse position
 *
 * @param	x	abscissa position.
 * @param	y   ordered position
 *
 *  @return 	return the color of the pixel
 */

ei_color_t recherche_pick_color(int x, int y);

/**
 * \brief	Function to have button_origin in all files
 *
 *  @return 	return the adress of the button_origin function
 */

ei_callback_t addr_boutton_origin();

/**
 * \brief	Find all the event wich have to be treated
 *
 * @param	event   the user event
 * @param	widget  an adress wich points to concerned widget
 *
 *  @return 	return a list of event_bind wich all have to be treated
 */

event_bind* event_recherche(ei_event_t* event, ei_widget_t** widget);

/**
 * \brief	this the classical function wich push up or down a button
 *
 * @param	widget  the button to push up or down
 * @param	event   the user event
 * @param   user_param  no user_param
 *
 *  @return 	return EI_TRUE
 */

ei_bool_t	boutton_origin  	(ei_widget_t*		widget,
                                        struct ei_event_t*	event,
                                        void*			user_param);