//
// Created by jules on 03/05/22.
//
#include<ei_event.h>
#include<ei_application.h>

typedef struct event_bind {
        ei_eventtype_t*  eventtype;
        ei_widget_t*    widget;
        ei_tag_t*        tag;
        ei_callback_t*   callback;
        void*           user_param;
        struct event_bind*      next;
}event_bind;

event_bind* liste_event_bind = NULL;

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
                new_bind->eventtype = &eventtype;
                new_bind->widget = widget;
                new_bind->tag = &tag;
                new_bind->callback = &callback;
                new_bind->user_param = user_param;

                if (liste_event_bind == NULL)
                {
                        liste_event_bind = new_bind;
                }
                else
                {
                        liste_event_bind -> next = new_bind;
                }
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
        uint8_t* buffer = hw_surface_get_buffer(ei_app_root_surface());
        buffer += 4*(x+y);
        uint8_t red = *buffer;
        uint8_t green = *(buffer+1);
        uint8_t blue = *(buffer+2);
        uint8_t alpha = *(buffer+3);
        ei_color_t pick_color_souris = {red, green, blue, alpha,};
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
        uint8_t type_event = souris_event(*(lien_event ->eventtype));
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
                if (event->type == *(liste_bis->eventtype) && widget_concerne(liste_bis, event)) {
                        if (liste_event_concerne != NULL) {
                                event_bind *event_a_traite = liste_bis;
                                event_a_traite->next = NULL;
                                liste_event_concerne->next = event_a_traite;
                        } else {
                                liste_event_concerne = liste_bis;
                                liste_event_concerne->next = NULL;
                        }
                }
                liste_bis = liste_bis->next;
        }
        return liste_event_concerne;
}


