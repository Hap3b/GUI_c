//
// Created by jules on 03/05/22.
//
#include<ei_event.h>
#include<ei_application.h>
#include "ei_variable_globale.h"
typedef struct event_bind {
        ei_eventtype_t  eventtype;
        ei_widget_t*    widget;
        ei_tag_t*        tag;
        ei_callback_t   callback;
        void*           user_param;
        struct event_bind*      next;
}event_bind;

static event_bind* liste_event_bind = NULL;

event_bind* addr_liste_event_bind()
{
        return liste_event_bind;
}

void register_bind(event_bind* new_bind)
{
        new_bind->next = liste_event_bind;
        liste_event_bind = new_bind;
}

void		ei_bind			(ei_eventtype_t		eventtype,
                                                    ei_widget_t*		widget,
                                                    ei_tag_t		tag,
                                                    ei_callback_t		callback,
                                                    void*			user_param)
{
        if (widget != NULL && tag != NULL)
        {
                printf("Erreur widget et tag ne peuvent pas être non nul en même temps");
        }
        else {
                event_bind *new_bind = malloc(sizeof(event_bind));
                new_bind->eventtype = eventtype;
                new_bind->widget = widget;
                new_bind->tag = &tag;
                new_bind->callback = callback;
                new_bind->user_param = user_param;
                register_bind(new_bind);
        }
}

uint8_t souris_event(ei_eventtype_t event) {
        switch (event)
        {
                case (ei_ev_mouse_buttondown):
                        return 0;
                        break;
                case (ei_ev_mouse_buttonup):
                        return 0;
                        break;
                case (ei_ev_mouse_move):
                        return 0;
                        break;
                default:
                        return 1;
                        break;

        }
}

ei_color_t recherche_pick_color(int x, int y)
{
        hw_surface_lock(addr_surface_cache());
        ei_size_t surface_size = hw_surface_get_size(addr_surface_cache());
        int ir;
        int ig;
        int ib;
        int ia;
        hw_surface_get_channel_indices(addr_surface_cache(),&ir, &ig, &ib, &ia);
        uint8_t* buffer = hw_surface_get_buffer(addr_surface_cache());
        buffer = buffer + 4*(x + y * surface_size.width);
        uint8_t red = buffer[ir];
        uint8_t green = buffer[ig];
        uint8_t blue = buffer[ib];
        uint8_t alpha = buffer[ia];
        ei_color_t pick_color_souris = {red, green, blue, alpha,};
        hw_surface_unlock(ei_app_root_surface());
        return pick_color_souris;
}

ei_bool_t comp_color(ei_color_t* color1,ei_color_t* color2)
{
        if (color1 ->red == color2 -> red && color1 ->green == color2 -> green && color1 -> blue == color2 ->blue)
        {
                return EI_TRUE;
        }
        else
        {
                return EI_FALSE;
        }
}
ei_bool_t widget_concerne(event_bind* lien_event,ei_event_t* event)
{
        uint8_t type_event = souris_event((lien_event ->eventtype));
        if (type_event == 1)
        {
                return EI_TRUE;
        }
        else
        {
                ei_color_t pick_color = recherche_pick_color(event ->param.mouse.where.x, event -> param.mouse.where.y);
                return (comp_color(&pick_color, lien_event ->widget ->pick_color));
        }
}

event_bind* event_recherche(ei_event_t* event)
{
        event_bind *liste_bis = liste_event_bind;
        event_bind* liste_event_concerne = NULL;
        while (liste_bis != NULL) {
                if (event->type == (liste_bis->eventtype) && widget_concerne(liste_bis, event)) {
                                event_bind *event_a_traite = liste_bis;
                                event_a_traite->next = liste_event_concerne;
                                liste_event_concerne = event_a_traite;
                }
                liste_bis = liste_bis->next;
        }
        return liste_event_concerne;
}


