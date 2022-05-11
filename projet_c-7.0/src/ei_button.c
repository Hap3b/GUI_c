#include <math.h>

ei_linked_point_t*       arc[2]            (ei_point_t     centre,
                                        float          rayon,
                                        float          pre_angle,
                                        float          deu_angle)
{
    ei_linked_point_t *lis;
    ei_linked_point *deb;
    ei_point_t nv_point = malloc(sizeof(ei_point_t));
    nv_point.x = centre.x + (int) (rayon * math.cos(pre_angle));
    nv_point.y = centre.y + (int) (rayon * math.sin(pre_angle));
    deb->point = nv_point;
    lis->point = nv_point;
    lis->next = NULL;
    deb->next = lis;
    for (int i = 1; i <= 100; i++) {
        float pas = pre_angle + i * (deu_angle - pre_angle) / 100;
        ei_point_t nv_point = malloc(sizeof(ei_point_t));
        nv_point.x = centre.x + (int) (rayon * math.cos(pas));
        nv_point.y = centre.y + (int) (rayon * math.sin(pas));
        lis = lis->suivant;
        lis->point = nv_point;
        lis->next = NULL;
    }
    return {deb, lis};
}

ei_linked_point_t*       rounded_frame              (ei_rect_t     rectangle,
                                                    float          rayon,
                                                    int            partie)
{
    int h = min(rectangle.width, rectangle.height);
    ei_point_t centre_r = malloc(sizeof(ei_point_t));
    // Si partie = 0, on dessine la partie haute; si partie = 1, on dessine la partie basse; si partie = 2, on dessine tout le button
    if (partie == 2) {
        centre_r.x = (int) rayon;
        centre_r.y = (int) rayon;
        ei_linked_point couple0[2] = arc(centre_r, rayon, -math.pi, -math.pi/2);
        centre_r.x = rectangle.width - (int) rayon;
        ei_linked_point couple1[2] = arc(centre_r, rayon, -math.pi/2, 0);
        centre_r.y = rectangle.height - (int) rayon;
        ei_linked_point couple2[2] = arc(centre_r, rayon, 0, math.pi/2);
        centre_r.x = (int) rayon;
        ei_linked_point couple3[2] = arc(centre_r, rayon, math.pi/2, math.pi);
        free(centre_r);
        couple2[1]->suivant = couple3[0];
        couple3[1]->suivant = couple0[0];
        couple0[1]->suivant = couple1[0];
        return couple2[0];
    }

    ei_point_t centre_m_d = malloc(sizeof(ei_point_t));
    centre_m_d.x = rectangle.width - h;
    centre_m_d.y = h;
    ei_point_t centre_m_g = malloc(sizeof(ei_point_t));
    centre_m_g.x = h;
    centre_m_g.y = rectangle.height - h;
    ei_linked_point_t *linked_m_d;
    ei_linked_point_t *linked_m_g;
    linked_m_d->point = centre_m_d;
    linked_m_g->point = centre_m_g;

    if (partie == 0){
        centre_r.x = (int) rayon;
        centre_r.y = (int) rayon;
        ei_linked_point couple0[2] = arc(centre_r, rayon, -math.pi, -math.pi/2);
        centre_r.x = rectangle.width - (int) rayon;
        ei_linked_point couple1[2] = arc(centre_r, rayon, -math.pi/2, -math.pi/4);
        centre_r.x = (int) rayon;
        centre_r.y = rectangle.height - (int) rayon;
        ei_linked_point couple2[2] = arc(centre_r, rayon, 3*math.pi/4, math.pi);
        free(centre_r);
        couple2[1]->suivant = couple0[0];
        couple0[1]->suivant = couple1[0];
        linked_m_g->next = NULL;
        linked_m_d->next = linked_m_g;
        couple1[1]->suivant = linked_m_d;
        return couple2[0];
    }
    if (partie == 1){
        centre_r.x = rectangle.width - (int) rayon;
        centre_r.y = rectangle.height - (int) rayon;
        ei_linked_point couple0[2] = arc(centre_r, rayon, 0, math.pi/2);
        centre_r.x = (int) rayon;
        ei_linked_point couple1[2] = arc(centre_r, rayon, math.pi/2, 3*math.pi/4);
        centre_r.x = rectangle.width - (int) rayon;
        centre_r.y = (int) rayon;
        ei_linked_point couple2[2] = arc(centre_r, rayon, -math.pi/4, 0);
        free(centre_r);
        couple2[1]->suivant = couple0[0];
        couple0[1]->suivant = couple1[0];
        linked_m_d->next = NULL;
        linked_m_g->next = linked_m_d;
        couple1[1]->suivant = linked_m_g;
        return couple2[0]
    }
}

typedef struct ei_button_t {
    ei_widget_t widget;
    ei_relief_t *relief;
    char *title;
    ei_font_t *fonte;
    ei_color_t *color;
    ei_anchor_t *ancre;
    ei_surface_t *img;
    ei_rect_t *img_rect;
    ei_anchor_t *img_anchor;
} ei_button_t;

struct ei_button_t*      ei_button_allocfunc_t        (void)
{
    struct ei_button_t *button = calloc(1, sizeof(ei_button_t));
    return button;
};

void        ei_button_releasefunc_t      (struct ei_button_t*	button)
{
    free(button -> relief);
    free(button -> title);
    free(button -> fonte);
    free(button ->color);
    free(button -> ancre);
    free(button-> img);
    free(button-> img_rect);
    free(button -> img_anchor);
};

void	ei_button_drawfunc_t		(struct ei_widget_t*	widget,
                                    ei_surface_t		surface,
                                    ei_surface_t		pick_surface,
                                    ei_rect_t*		clipper)
{
    ei_color_t trans = {0xff, 0xff, 0xff, 0x00};
    ei_draw_polygon(pick_surface, rounded_frame(widget->screen_location, 5.0, 2),trans, clipper);
    ei_color_t col_sombre = {min(255, widget->pick_color->red + 30), min(255, widget->pick_color->green + 30), min(255, widget->pick_color->blue + 30), widget->pick_color->alpha};
    ei_color_t col_claire = {max(0, widget->pick_color->red - 30), max(0, widget->pick_color->green - 30), max(0, widget->pick_color->blue - 30), widget->pick_color->alpha};
    ei_draw_polygon(surface, rounded_frame(widget->screen_location, 5.0, 0), col_claire,clipper);
    ei_draw_polygon(surface, rounded_frame(widget->screen_location, 5.0, 1), col_sombre,clipper);
    ei_rect_t nv_rect = {{screen_location.top_left.x + screen_location.size.width/10, screen_location.top_left.y + screen_location.size.height/10}, {screen_location.size.width*8/10, screen_location.size.height*8/10}};
    ei_draw_polygon(surface, rounded_frame(nv_rect, 5.0, 2), *widget->pick_color ,clipper);
};

void	ei_button_setdefaultsfunc_t	(struct ei_frame_t*	frame)
{
    frame->color = &ei_default_background_color;
    frame->widget.requested_size.height = 540; /* Half screen on a 1920x1080 screen*/
    frame->widget.requested_size.width = 960;
    frame->relief = ei_relief_none;
    frame->fonte = ei_default_font;
    frame->title = NULL;
    frame->ancre = ei_anc_center;
    frame->img_anchor = ei_anc_center;
    frame->img = NULL;
    frame->img_rect = NULL;
    frame->widget.user_data = NULL;
    frame->widget.destructor = NULL;
    frame->widget.parent = NULL;
    frame->widget.children_head = NULL;
    frame->widget.children_tail = NULL;
    frame->widget.next_sibling = NULL;
    frame->widget.geom_params = NULL;
};

extern ei_widgetclass_t classe_frame =
        {
                "frame",
                &ei_button_allocfunc_t,
                &ei_button_releasefunc_t,
                &ei_button_drawfunc_t,
                &ei_button_setdefaultsfunc_t,
                NULL,
                NULL
        };
