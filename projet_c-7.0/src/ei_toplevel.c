#include <ei_widgetclass.h>
#include <ei_widget.h>
#include <ei_button.h>

void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	toplevel);

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

struct ei_widget_t*      ei_toplevel_allocfunc_t        (void)
{
        struct ei_toplevel_t *toplevel = malloc(sizeof(ei_toplevel_t));
        return (ei_widget_t*) toplevel;
}

void        ei_toplevel_releasefunc_t      (struct ei_widget_t*	widget)
{
        ei_toplevel_t* toplevel = (ei_toplevel_t*)widget;
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
        ei_linked_point_t* arc1 = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* arc2 = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* arc3 = malloc(sizeof (ei_linked_point_t));
        centre_r->x = widget->screen_location.top_left.x + k_default_button_corner_radius;
        centre_r->y = widget->screen_location.top_left.y + k_default_button_corner_radius;
        arc(centre_r, rayon, angle0, angle1, &arc0, &arc1);
        centre_r->x = widget->screen_location.size.width + widget->screen_location.top_left.x - k_default_button_corner_radius;
        arc(centre_r, rayon, angle1, angle2, &arc2, &arc3);

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
        linked_lower_left->next = arc0;
        arc1->next = arc2;
        arc3->next = linked_lower_right;
        linked_lower_right->next = NULL;
        ei_draw_polygon(pick_surface, linked_lower_left, trans, clipper);
        hw_surface_unlock(pick_surface);
        ei_draw_polygon(surface, linked_lower_left, dark_grey, clipper);
        free(centre_r);
        free(lower_left);
        free(lower_right);
        free(linked_lower_left);
        free(linked_lower_right);

        // Dessin du texte de l'en-tête -> à faire


        // Dessin de la frame intérieure
        ei_point_t* middle_left = malloc(sizeof(ei_point_t));
        middle_left->x = widget->screen_location.top_left.x + *toplevel->border_width;
        middle_left->y = widget->screen_location.top_left.y + 30 + *toplevel->border_width;
        ei_point_t* middle_right = malloc(sizeof(ei_point_t));
        middle_right->x = widget->screen_location.top_left.x + widget->screen_location.size.width - *toplevel->border_width;
        middle_right->y = widget->screen_location.top_left.y + 30 + *toplevel->border_width;
        ei_linked_point_t* linked_middle_left = malloc(sizeof(ei_linked_point_t));
        linked_middle_left->point = *middle_left;
        ei_linked_point_t* linked_middle_right = malloc(sizeof(ei_linked_point_t));
        linked_middle_right->point = *middle_right;
        ei_point_t* lower_left_int = malloc(sizeof(ei_point_t));
        lower_left_int->x = widget->screen_location.top_left.x + *toplevel->border_width;
        lower_left_int->y = widget->screen_location.top_left.y + widget->screen_location.size.height - *toplevel->border_width;
        ei_point_t* lower_right_int = malloc(sizeof(ei_point_t));
        lower_right_int->x = widget->screen_location.top_left.x + widget->screen_location.size.width - *toplevel->border_width;
        lower_right_int->y = widget->screen_location.top_left.y + widget->screen_location.size.height - *toplevel->border_width;
        ei_linked_point_t* linked_lower_left_int = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* linked_lower_right_int = malloc(sizeof(ei_linked_point_t));
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
        free(linked_lower_left_int);
        free(linked_lower_right_int);
        free(linked_middle_left);
        free(linked_middle_right);

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
                ei_linked_point_t *linked_pt_square1 = malloc(sizeof(ei_linked_point_t));
                ei_linked_point_t *linked_pt_square2 = malloc(sizeof(ei_linked_point_t));
                ei_linked_point_t *linked_pt_square3 = malloc(sizeof(ei_linked_point_t));
                ei_linked_point_t *linked_pt_square4 = malloc(sizeof(ei_linked_point_t));
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