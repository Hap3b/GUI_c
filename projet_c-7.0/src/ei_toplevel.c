#include <ei_widgetclass.h>
#include <ei_widget.h>
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
        ei_point_t* centre_r = malloc(sizeof(ei_point_t));
        centre_r->x = k_default_button_corner_radius;
        centre_r->y = k_default_button_corner_radius;
        ei_linked_point_t** couple0 = arc(centre_r, k_default_button_corner_radius, -M_PI, -M_PI/2);
        centre_r->x = widget->screen_location.size.width - k_default_button_corner_radius;
        ei_linked_point_t** couple1 = arc(centre_r, k_default_button_corner_radius, -M_PI/2, 0);

        // Création des points en bas de l'en-tête
        ei_point_t* lower_left = malloc(sizeof(ei_point_t));
        lower_left->x = widget->screen_location.top_left.x;
        lower_left->y = widget->screen_location.top_left.y + widget->screen_location.size.height;
        ei_point_t* lower_right = malloc(sizeof(ei_point_t));
        lower_right->x = widget->screen_location.top_left.x + widget->screen_location.size.width;
        lower_right->y = widget->screen_location.top_left.y + widget->screen_location.size.height;
        ei_linked_point_t* linked_lower_left;
        ei_linked_point_t* linked_lower_right;
        linked_lower_left->point = *lower_left;
        linked_lower_right->point = *lower_right;


        // Dessin de la forme de l'en-tête + frame avec la bordure
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

        // Dessin du texte de l'en-tête -> à faire


        // Dessin de la frame intérieure
        ei_point_t* middle_left = malloc(sizeof(ei_point_t));
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
        linked_lower_left_int->point = *lower_left_int;
        linked_lower_right_int->point = *lower_right_int;
        linked_middle_left->next = linked_middle_right;
        linked_middle_right->next = linked_lower_right_int;
        linked_lower_right_int->next = linked_lower_left_int;
        linked_lower_left_int->next = NULL;
        ei_draw_polygon(surface, linked_middle_left, *toplevel->color, clipper);
        free(lower_left_int);
        free(lower_right_int);
        free(middle_left);
        free(middle_right);

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
                ei_linked_point_t *linked_pt_square1;
                ei_linked_point_t *linked_pt_square2;
                ei_linked_point_t *linked_pt_square3;
                ei_linked_point_t *linked_pt_square4;
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
        }

        hw_surface_unlock(surface);

        //On dessine tous les widgets qui sont dans le toplevel
        draw_children(widget, surface, pick_surface, widget->content_rect);
}


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
        ((ei_toplevel_t *)toplevel) -> requested_size = r_size;
        ((ei_toplevel_t *)toplevel) -> color = cl;
        ((ei_toplevel_t *)toplevel) -> border_width = b_width;
        ((ei_toplevel_t *)toplevel) -> title = ttl;
        ((ei_toplevel_t *)toplevel) -> closable = clb;
        ((ei_toplevel_t *)toplevel) -> resizable = rsb;
        ((ei_toplevel_t *)toplevel) -> min_size = &m_size;

}