#include <ei_widgetclass.h>
#include <ei_widget.h>
<<<<<<< HEAD
#include <ei_fct_annexes.h>

void    draw_children          (ei_widget_t* children, ei_surface_t  surface, ei_surface_t pick_surface, ei_rect_t* clipper)
{
        if (children != NULL) {
                children->wclass->drawfunc(children, surface, pick_surface, clipper);
                draw_children(children->next_sibling, surface, pick_surface, clipper);
        }
}

typedef struct ei_toplevel_t {
        ei_widget_t* widget;
        ei_size_t* requested_size;
        ei_color_t* color;
        int* border_width;
        char** title;
        ei_bool_t* closable;
        ei_axis_set_t* resizable;
        ei_size_t** min_size;
} ei_toplevel_t;

struct ei_toplevel_t*      ei_toplevel_allocfunc_t        (void)
{
        struct ei_toplevel_t *toplevel = calloc(1, sizeof(ei_toplevel_t));
        return toplevel;
}

void        ei_toplevel_releasefunc_t      (struct ei_toplevel_t*	toplevel)
{
        free(toplevel -> requested_size);
        free(toplevel-> color);
        free(toplevel-> border_width);
        free(toplevel-> title);
        free(toplevel-> closable);
        free(toplevel-> resizable);
        free(toplevel-> min_size);
=======
#include <ei_button.h>
#include <ei_geometrymanager.h>
#include "ei_event.h"
#include "ei_types.h"
#include "ei_variable_globale.h"

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
>>>>>>> refs/remotes/origin/master
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
<<<<<<< HEAD
        ei_point_t* centre_r = malloc(sizeof(ei_point_t));
        centre_r->x = k_default_button_corner_radius;
        centre_r->y = k_default_button_corner_radius;
        ei_linked_point_t** couple0 = arc(centre_r, k_default_button_corner_radius, -M_PI, -M_PI/2);
        centre_r->x = widget->screen_location.size.width - k_default_button_corner_radius;
        ei_linked_point_t** couple1 = arc(centre_r, k_default_button_corner_radius, -M_PI/2, 0);
=======
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
>>>>>>> refs/remotes/origin/master

        // Création des points en bas de l'en-tête
        ei_point_t* lower_left = malloc(sizeof(ei_point_t));
        lower_left->x = widget->screen_location.top_left.x;
        lower_left->y = widget->screen_location.top_left.y + widget->screen_location.size.height;
        ei_point_t* lower_right = malloc(sizeof(ei_point_t));
        lower_right->x = widget->screen_location.top_left.x + widget->screen_location.size.width;
        lower_right->y = widget->screen_location.top_left.y + widget->screen_location.size.height;
<<<<<<< HEAD
        ei_linked_point_t* linked_lower_left;
        ei_linked_point_t* linked_lower_right;
=======
        ei_linked_point_t* linked_lower_left = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* linked_lower_right = malloc(sizeof(ei_linked_point_t));
>>>>>>> refs/remotes/origin/master
        linked_lower_left->point = *lower_left;
        linked_lower_right->point = *lower_right;


        // Dessin de la forme de l'en-tête + frame avec la bordure
<<<<<<< HEAD
        linked_lower_left->next = couple0[0];
        couple0[1]->next = couple1[0];
        couple1[1]->next = linked_lower_right;
        linked_lower_right->next = NULL;
        ei_draw_polygon(pick_surface, linked_lower_left, trans, clipper);
        hw_surface_unlock(pick_surface);
        ei_draw_polygon(surface, linked_lower_left, dark_grey, clipper);
        free(centre_r);
        free(lower_left);
        free(lower_right);
        // Il faudrait pouvoir free les points des arcs créés -> à faire
=======
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
>>>>>>> refs/remotes/origin/master

        // Dessin du texte de l'en-tête -> à faire


        // Dessin de la frame intérieure
        ei_point_t* middle_left = malloc(sizeof(ei_point_t));
<<<<<<< HEAD
        middle_left->x = widget->screen_location.top_left.x + *toplevel->border_width;
        middle_left->y = widget->screen_location.top_left.y + 30 + *toplevel->border_width;
        ei_point_t* middle_right = malloc(sizeof(ei_point_t));
        middle_right->x = widget->screen_location.top_left.x + widget->screen_location.size.width - *toplevel->border_width;
        middle_right->y = widget->screen_location.top_left.y + 30 + *toplevel->border_width;
        ei_linked_point_t* linked_middle_left;
        linked_middle_left->point = *middle_left;
        ei_linked_point_t* linked_middle_right;
        linked_middle_right->point = *middle_right;
        ei_point_t* lower_left_int = malloc(sizeof(ei_point_t));
        lower_left_int->x = widget->screen_location.top_left.x + *toplevel->border_width;
        lower_left_int->y = widget->screen_location.top_left.y + widget->screen_location.size.height - *toplevel->border_width;
        ei_point_t* lower_right_int = malloc(sizeof(ei_point_t));
        lower_right_int->x = widget->screen_location.top_left.x + widget->screen_location.size.width - *toplevel->border_width;
        lower_right_int->y = widget->screen_location.top_left.y + widget->screen_location.size.height - *toplevel->border_width;
        ei_linked_point_t* linked_lower_left_int;
        ei_linked_point_t* linked_lower_right_int;
=======
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
>>>>>>> refs/remotes/origin/master
        linked_lower_left_int->point = *lower_left_int;
        linked_lower_right_int->point = *lower_right_int;
        linked_middle_left->next = linked_middle_right;
        linked_middle_right->next = linked_lower_right_int;
        linked_lower_right_int->next = linked_lower_left_int;
        linked_lower_left_int->next = NULL;
<<<<<<< HEAD
        ei_draw_polygon(surface, linked_middle_left, *toplevel->color, clipper);
=======
        ei_draw_polygon(surface, linked_middle_left, toplevel->color, clipper);
>>>>>>> refs/remotes/origin/master
        free(lower_left_int);
        free(lower_right_int);
        free(middle_left);
        free(middle_right);
<<<<<<< HEAD
=======
        free(linked_lower_left_int);
        free(linked_lower_right_int);
        free(linked_middle_left);
        free(linked_middle_right);
>>>>>>> refs/remotes/origin/master

        // Dessin d'un petit carré gris en bas à droite si la fenêtre peut être redimensionnéee
        if (toplevel->resizable != ei_axis_none) {
                ei_point_t *pt_square1 = malloc(sizeof(ei_point_t));
                ei_point_t *pt_square2 = malloc(sizeof(ei_point_t));
                ei_point_t *pt_square3 = malloc(sizeof(ei_point_t));
                ei_point_t *pt_square4 = malloc(sizeof(ei_point_t));
                pt_square1->x = widget->screen_location.top_left.x + widget->screen_location.size.width - 15;
                pt_square2->x = widget->screen_location.top_left.x + widget->screen_location.size.width - 15;
                pt_square3->x = widget->screen_location.top_left.x + widget->screen_location.size.width;
                pt_square4->x = widget->screen_location.top_left.x + widget->screen_location.size.width;
                pt_square1->y = widget->screen_location.top_left.y + widget->screen_location.size.height;
                pt_square2->y = widget->screen_location.top_left.y + widget->screen_location.size.height - 15;
                pt_square3->y = widget->screen_location.top_left.y + widget->screen_location.size.height - 15;
                pt_square4->y = widget->screen_location.top_left.y + widget->screen_location.size.height;
<<<<<<< HEAD
                ei_linked_point_t *linked_pt_square1;
                ei_linked_point_t *linked_pt_square2;
                ei_linked_point_t *linked_pt_square3;
                ei_linked_point_t *linked_pt_square4;
=======
                ei_linked_point_t *linked_pt_square1 = malloc(sizeof(ei_linked_point_t));
                ei_linked_point_t *linked_pt_square2 = malloc(sizeof(ei_linked_point_t));
                ei_linked_point_t *linked_pt_square3 = malloc(sizeof(ei_linked_point_t));
                ei_linked_point_t *linked_pt_square4 = malloc(sizeof(ei_linked_point_t));
>>>>>>> refs/remotes/origin/master
                linked_pt_square1->point = *pt_square1;
                linked_pt_square2->point = *pt_square2;
                linked_pt_square3->point = *pt_square3;
                linked_pt_square4->point = *pt_square4;
                linked_pt_square1->next = linked_pt_square2;
                linked_pt_square2->next = linked_pt_square3;
                linked_pt_square3->next = linked_pt_square4;
                linked_pt_square4->next = NULL;
                ei_draw_polygon(surface, linked_pt_square1, dark_grey, clipper);
                free(pt_square1);
                free(pt_square2);
                free(pt_square3);
                free(pt_square4);
<<<<<<< HEAD
        }

        hw_surface_unlock(surface);

        //On dessine tous les widgets qui sont dans le toplevel
        draw_children(widget, surface, pick_surface, widget->content_rect);
}

=======
                free(linked_pt_square1);
                free(linked_pt_square2);
                free(linked_pt_square3);
                free(linked_pt_square4);
        }

        hw_surface_unlock(surface);
}

static ei_widgetclass_t classe_toplevel =
        {
                "toplevel",
                &ei_toplevel_allocfunc_t,
                &ei_toplevel_releasefunc_t,
                &ei_toplevel_drawfunc_t,
                &ei_toplevel_setdefaultsfunc_t,
                NULL,
                NULL
        };
>>>>>>> refs/remotes/origin/master

void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	toplevel)
{
        ei_size_t *r_size = malloc(sizeof(ei_size_t));
        r_size->width = 320;
        r_size->height = 240;
        ei_color_t* cl = malloc(sizeof(ei_color_t));
        *cl = ei_default_background_color;
        int *b_width = malloc(sizeof(int));
        *b_width = 4;
        char **ttl = malloc(sizeof(char));
        *ttl = "Toplevel";
        ei_bool_t* clb = malloc(sizeof(ei_bool_t));
        *clb = EI_TRUE;
        ei_axis_set_t* rsb = malloc(sizeof(ei_axis_set_t));
        *rsb = ei_axis_both;
        ei_size_t *m_size = malloc(sizeof(ei_size_t));
        m_size->width = 160;
        m_size->height = 120;
<<<<<<< HEAD
        ((ei_toplevel_t *)toplevel) -> requested_size = r_size;
        ((ei_toplevel_t *)toplevel) -> color = cl;
        ((ei_toplevel_t *)toplevel) -> border_width = b_width;
        ((ei_toplevel_t *)toplevel) -> title = ttl;
        ((ei_toplevel_t *)toplevel) -> closable = clb;
        ((ei_toplevel_t *)toplevel) -> resizable = rsb;
        ((ei_toplevel_t *)toplevel) -> min_size = &m_size;

=======
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

}



ei_widgetclass_t* addr_toplevel()
{
        return &classe_toplevel;
}

ei_bool_t	button_press_exit	(ei_widget_t*		widget,
                                  struct ei_event_t*	event,
                                  void*			user_param) {
    free(widget);
    des
    return EI_FALSE;
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
        }
>>>>>>> refs/remotes/origin/master
}