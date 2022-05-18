#include <ei_widgetclass.h>
#include <ei_widget.h>
#include <ei_button.h>
#include <ei_geometrymanager.h>
#include "ei_event.h"
#include "ei_types.h"
#include "ei_variable_globale.h"
#include "ei_application.h"

ei_bool_t	redimensionnement_toplevel  	(ei_widget_t*		widget,
                                            struct ei_event_t*	event,
                                            void*			user_param);

void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	toplevel);

typedef struct ei_toplevel_t {
        ei_widget_t widget;
        ei_size_t requested_size;
        ei_color_t color;
        int border_width;
        char* title;
        ei_bool_t closable;
        ei_axis_set_t resizable;
        ei_size_t* min_size;
} ei_toplevel_t;

struct ei_widget_t*      ei_toplevel_allocfunc_t        (void)
{
        struct ei_toplevel_t *toplevel = malloc(sizeof(ei_toplevel_t));
        return (ei_widget_t*) toplevel;
}

void        ei_toplevel_releasefunc_t      (struct ei_widget_t*	widget)
{
        free(widget);
}

void	ei_toplevel_drawfunc_t		(struct ei_widget_t*	widget,
                                                 ei_surface_t		surface,
                                                 ei_surface_t		pick_surface,
                                                 ei_rect_t*		clipper)
{
        ei_color_t trans = {0xff, 0xff, 0xff, 0x00};
        ei_color_t dark_grey = {0x69, 0x69, 0x69, 0xff};
        ei_toplevel_t* toplevel = (ei_toplevel_t*)widget;
        hw_surface_lock(surface);
        hw_surface_lock(pick_surface);

        // Création des arcs de l'en tête.
        double *angle0 = malloc(sizeof(double));
        *angle0 = -M_PI;
        double *angle1 = malloc(sizeof(double));
        *angle1 = -M_PI/2;
        double *angle2 = malloc(sizeof(double));
        *angle2 = 0;
        int *rayon = malloc(sizeof(int));
        *rayon = k_default_button_corner_radius;
        ei_point_t* centre_r = malloc(sizeof(ei_point_t));
        ei_linked_point_t* arc0 = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* arc1 = arc0;
        ei_linked_point_t* arc2 = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* arc3 = arc2;
        centre_r->x = widget->screen_location.top_left.x + k_default_button_corner_radius;
        centre_r->y = widget->screen_location.top_left.y + k_default_button_corner_radius;
        arc(centre_r, rayon, angle1, angle0, &arc0, &arc1);
        centre_r->x = widget->screen_location.size.width + widget->screen_location.top_left.x - k_default_button_corner_radius;
        arc(centre_r, rayon, angle2, angle1, &arc2, &arc3);

        // Création des points en bas de l'en-tête
        ei_point_t* lower_left = malloc(sizeof(ei_point_t));
        lower_left->x = widget->screen_location.top_left.x;
        lower_left->y = widget->screen_location.top_left.y + widget->screen_location.size.height;
        ei_point_t* lower_right = malloc(sizeof(ei_point_t));
        lower_right->x = widget->screen_location.top_left.x + widget->screen_location.size.width;
        lower_right->y = widget->screen_location.top_left.y + widget->screen_location.size.height;
        ei_linked_point_t* linked_lower_left = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* linked_lower_right = malloc(sizeof(ei_linked_point_t));
        linked_lower_left->point = *lower_left;
        linked_lower_right->point = *lower_right;


        // Dessin de la forme de l'en-tête + frame avec la bordure
        linked_lower_right->next = arc2;
        arc3->next = arc0;
        arc1->next = linked_lower_left;
        linked_lower_left->next = NULL;
        ei_draw_polygon(pick_surface, linked_lower_right, trans, clipper);
        hw_surface_unlock(pick_surface);
        ei_draw_polygon(surface, linked_lower_right, dark_grey, clipper);
        free(centre_r);
        free(lower_left);
        free(lower_right);
        free(linked_lower_left);
        free(linked_lower_right);

        // Dessin du texte de l'en-tête -> à faire


        // Dessin de la frame intérieure
        ei_point_t* middle_left = malloc(sizeof(ei_point_t));
        middle_left->x = widget->screen_location.top_left.x + toplevel->border_width;
        middle_left->y = widget->screen_location.top_left.y + 30 + toplevel->border_width;
        ei_point_t* middle_right = malloc(sizeof(ei_point_t));
        middle_right->x = widget->screen_location.top_left.x + widget->screen_location.size.width - toplevel->border_width;
        middle_right->y = widget->screen_location.top_left.y + 30 + toplevel->border_width;
        ei_linked_point_t* linked_middle_left = malloc(sizeof(ei_linked_point_t));
        linked_middle_left->point = *middle_left;
        ei_linked_point_t* linked_middle_right = malloc(sizeof(ei_linked_point_t));
        linked_middle_right->point = *middle_right;
        ei_point_t* lower_left_int = malloc(sizeof(ei_point_t));
        lower_left_int->x = widget->screen_location.top_left.x + toplevel->border_width;
        lower_left_int->y = widget->screen_location.top_left.y + widget->screen_location.size.height - toplevel->border_width;
        ei_point_t* lower_right_int = malloc(sizeof(ei_point_t));
        lower_right_int->x = widget->screen_location.top_left.x + widget->screen_location.size.width - toplevel->border_width;
        lower_right_int->y = widget->screen_location.top_left.y + widget->screen_location.size.height - toplevel->border_width;
        ei_linked_point_t* linked_lower_left_int = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* linked_lower_right_int = malloc(sizeof(ei_linked_point_t));
        linked_lower_left_int->point = *lower_left_int;
        linked_lower_right_int->point = *lower_right_int;
        linked_middle_left->next = linked_middle_right;
        linked_middle_right->next = linked_lower_right_int;
        linked_lower_right_int->next = linked_lower_left_int;
        linked_lower_left_int->next = NULL;
        ei_draw_polygon(surface, linked_middle_left, toplevel->color, clipper);
        free(lower_left_int);
        free(lower_right_int);
        free(middle_left);
        free(middle_right);
        free(linked_lower_left_int);
        free(linked_lower_right_int);
        free(linked_middle_left);
        free(linked_middle_right);

        // Dessin d'un petit carré gris en bas à droite si la fenêtre peut être redimensionnéee

        hw_surface_unlock(surface);
}
ei_bool_t	button_press_exit	(ei_widget_t*		widget,
                                   struct ei_event_t*	event,
                                   void*			user_param) {
    if(widget != NULL)
    {
        supprime_widget_bis(widget -> parent);
        dessine_tout_widget(ei_app_root_widget());
        free(widget);
        return EI_FALSE;
    }

}


void    ajoute_boutton_haut_gauche      (ei_widget_t  *widget){
    ei_toplevel_t* toplevel = (ei_toplevel_t*)widget;
    if (toplevel->closable == EI_TRUE) {
        ei_color_t	button_color	= {0xE6, 0x1E, 0x3C, 0xff};
        ei_relief_t     relief          = ei_relief_raised;
        int             button_border_width    = 4;
        ei_size_t size = {25, 25};

        ei_widget_t* button;
        button = ei_widget_create("button", widget, NULL, NULL);
        ei_bind(ei_ev_mouse_buttondown,button,NULL,button_press_exit,NULL);
        ei_button_configure(button, &size, &button_color,
                            &button_border_width, NULL, &relief, NULL, NULL, NULL, NULL,
                            NULL, NULL, NULL, NULL, NULL);
        ei_anchor_t	button_anchor	= ei_anc_northwest;
        int           button_x    = 10;
        int           button_y    = 20;
        ei_place(button, &button_anchor, &button_x, &button_y, NULL, NULL, NULL, NULL, NULL, NULL);

    }
}
ei_bool_t debut_redimensionnement  	(ei_widget_t*		widget,
                                struct ei_event_t*	event,
                                void*			user_param){
    ei_bind(ei_ev_mouse_move,widget,NULL,redimensionnement_toplevel,NULL);
}

ei_bool_t fin_redimensionnement  	(ei_widget_t*		widget,
                                      struct ei_event_t*	event,
                                      void*			user_param)
{
    ei_unbind(event->type,widget,NULL,debut_redimensionnement,NULL);
}
void	ei_toplevel_geomnotifyfunc_t	(struct ei_widget_t*	widget)
{
    ei_toplevel_t* toplevel = (ei_toplevel_t*) widget;
    if (toplevel->resizable != ei_axis_none)
    {
        ei_widget_t* frame = ei_widget_create("frame",widget,NULL,NULL);
        float reel_size = (float)0.05;
        ei_color_t dark_grey = {0x69, 0x69, 0x69, 0xff};
        ei_frame_configure(frame,NULL, &dark_grey,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
        float reel_x = (float)0.95;
        ei_place(frame,NULL,NULL,NULL,NULL,NULL,&reel_x,&reel_x,&reel_size,&reel_size);
        ei_bind(ei_ev_mouse_buttondown,frame,NULL,debut_redimensionnement,NULL);
        ei_bind(ei_ev_mouse_buttonup,frame,NULL,fin_redimensionnement,NULL);
    }
    ajoute_boutton_haut_gauche(widget);
}

static ei_widgetclass_t classe_toplevel =
        {
                "toplevel",
                &ei_toplevel_allocfunc_t,
                &ei_toplevel_releasefunc_t,
                &ei_toplevel_drawfunc_t,
                &ei_toplevel_setdefaultsfunc_t,
                &ei_toplevel_geomnotifyfunc_t,
                NULL
        };

void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	toplevel)
{
        ei_size_t *r_size = malloc(sizeof(ei_size_t));
        r_size->width = 320;
        r_size->height = 240;
        ei_color_t* cl = malloc(sizeof(ei_color_t));
        *cl = ei_default_background_color;
        int *b_width = malloc(sizeof(int));
        *b_width = 4;
        char **ttl = malloc(sizeof(char*));
        *ttl = "Toplevel";
        ei_bool_t* clb = malloc(sizeof(ei_bool_t));
        *clb = EI_TRUE;
        ei_axis_set_t* rsb = malloc(sizeof(ei_axis_set_t));
        *rsb = ei_axis_both;
        ei_size_t *m_size = malloc(sizeof(ei_size_t));
        m_size->width = 160;
        m_size->height = 120;
        ((ei_toplevel_t *)toplevel) -> requested_size = *r_size;
        ((ei_toplevel_t *)toplevel) -> color = *cl;
        ((ei_toplevel_t *)toplevel) -> border_width = *b_width;
        ((ei_toplevel_t *)toplevel) -> title = *ttl;
        ((ei_toplevel_t *)toplevel) -> closable = *clb;
        ((ei_toplevel_t *)toplevel) -> resizable = *rsb;
        ((ei_toplevel_t *)toplevel) -> min_size = m_size;

        toplevel-> wclass = &classe_toplevel;
        toplevel->requested_size.height = 540; /* Half screen on a 1920x1080 screen*/
        toplevel->requested_size.width = 960;
        toplevel->user_data = NULL;
        toplevel-> destructor = NULL;
        toplevel->parent = NULL;
        toplevel->children_head = NULL;
        toplevel->children_tail = NULL;
        toplevel->next_sibling = NULL;
        toplevel->geom_params = NULL;
        free(cl);
        free(b_width);
        free(ttl);
        free(clb);
        free(rsb);
}



ei_widgetclass_t* addr_toplevel()
{
        return &classe_toplevel;
}

static ei_bool_t stop;

ei_bool_t	redimensionnement_toplevel  	(ei_widget_t*		widget,
                                struct ei_event_t*	event,
                                void*			user_param){

    int width =  event->param.mouse.where.x - widget->parent->screen_location.top_left.y;
    int height =  2*(widget ->parent->screen_location.size.height) + widget->parent->screen_location.top_left.x - event->param.mouse.where.y;
    ei_place(widget->parent,NULL,&(widget->parent->screen_location.top_left.x),&(widget->screen_location.top_left.y),&width,&height,NULL,NULL,NULL,NULL);
    (*(widget->parent->wclass->drawfunc))(widget->parent,ei_app_root_surface(),addr_surface_cache(),NULL);
    hw_surface_update_rects(ei_app_root_surface(),NULL);
}
