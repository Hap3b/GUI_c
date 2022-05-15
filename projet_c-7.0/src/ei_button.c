#include <math.h>

#define min(a, b) = a < b ? a : b;
#define max(a, b) = a > b ? a : b;

ei_linked_point_t*       arc[2]            (ei_point_t     centre,
                                        int          rayon,
                                        float          pre_angle,
                                        float          deu_angle)
{
    ei_linked_point_t *lis;
    ei_linked_point *deb;
    ei_point_t nv_point = malloc(sizeof(ei_point_t));
    nv_point.x = centre.x + (int) ((float) rayon * math.cos(pre_angle));
    nv_point.y = centre.y + (int) ((float) rayon * math.sin(pre_angle));
    deb->point = nv_point;
    lis->point = nv_point;
    lis->next = NULL;
    deb->next = lis;
    for (int i = 1; i <= 100; i++) {
        float pas = pre_angle + i * (deu_angle - pre_angle) / 100;
        ei_point_t nv_point = malloc(sizeof(ei_point_t));
        nv_point.x = centre.x + (int) ((float) rayon * math.cos(pas));
        nv_point.y = centre.y + (int) ((float) rayon * math.sin(pas));
        lis = lis->suivant;
        lis->point = nv_point;
        lis->next = NULL;
    }
    return {deb, lis};
}

ei_linked_point_t*       rounded_frame              (ei_rect_t     rectangle,
                                                    int          rayon,
                                                    int            partie)
{
    int h = min(rectangle.width, rectangle.height);
    ei_point_t centre_r = malloc(sizeof(ei_point_t));
    // Si partie = 0, on dessine la partie haute; si partie = 1, on dessine la partie basse; si partie = 2, on dessine tout le button
    if (partie == 2) {
        centre_r.x = rayon;
        centre_r.y = rayon;
        ei_linked_point couple0[2] = arc(centre_r, rayon, -math.pi, -math.pi/2);
        centre_r.x = rectangle.width - rayon;
        ei_linked_point couple1[2] = arc(centre_r, rayon, -math.pi/2, 0);
        centre_r.y = rectangle.height - rayon;
        ei_linked_point couple2[2] = arc(centre_r, rayon, 0, math.pi/2);
        centre_r.x = rayon;
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
        centre_r.x = rayon;
        centre_r.y = rayon;
        ei_linked_point couple0[2] = arc(centre_r, rayon, -math.pi, -math.pi/2);
        centre_r.x = rectangle.width - rayon;
        ei_linked_point couple1[2] = arc(centre_r, rayon, -math.pi/2, -math.pi/4);
        centre_r.x = rayon;
        centre_r.y = rectangle.height - rayon;
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
        centre_r.x = rectangle.width - rayon;
        centre_r.y = rectangle.height - rayon;
        ei_linked_point couple0[2] = arc(centre_r, rayon, 0, math.pi/2);
        centre_r.x = rayon;
        ei_linked_point couple1[2] = arc(centre_r, rayon, math.pi/2, 3*math.pi/4);
        centre_r.x = rectangle.width - rayon;
        centre_r.y = rayon;
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
    ei_widget_t* widget;
    const ei_color_t* color;
    int* border_width;
    int* corner_radius;
    ei_relief_t* relief;
    char** text;
    ei_font_t* text_font;
    ei_color_t* text_color;
    ei_anchor_t* text_anchor;
    ei_surface_t* img;
    ei_rect_t** img_rect;
    ei_anchor_t* img_anchor;
    ei_callback_t* callback;
    void** user_param;
} ei_button_t;

struct ei_button_t*      ei_button_allocfunc_t        (void)
{
    struct ei_button_t *button = calloc(1, sizeof(ei_button_t));
    return button;
};

void        ei_button_releasefunc_t      (struct ei_button_t*	button)
{
    free(button -> color);
    free(button -> border_width);
    free(button -> corner_radius);
    free(button -> relief);
    free(button -> text);
    free(button-> text_font);
    free(button -> text_color);
    free(button -> text_anchor);
    free(button -> img);
    free(button -> img_rect);
    free(button -> img_anchor);
    free(button -> callback);
    free(button -> user_param);
};

void	ei_button_drawfunc_t		(struct ei_widget_t*	widget,
                                    ei_surface_t		surface,
                                    ei_surface_t		pick_surface,
                                    ei_rect_t*		clipper)
{
    ei_color_t trans = {0xff, 0xff, 0xff, 0x00};
    ei_button_t* button = (ei_button_t*)widget;
    ei_surface_t * racine_bis = addr_racine();
    hw_surface_lock(racine_bis);

    ei_draw_polygon(pick_surface, rounded_frame(button->screen_location, button->corner_radius, 2),trans, clipper);

    ei_color_t col_sombre = {min(255, button->color->red + 30), min(255, button->color->green + 30), min(255, button->color->blue + 30), button->color->alpha};
    ei_color_t col_claire = {max(0, button->color->red - 30), max(0, button->color->green - 30), max(0, button->color->blue - 30), button->color->alpha};

    if (*button->relief == ei_relief_raised) {
        ei_draw_polygon(surface, rounded_frame(button->screen_location, button->corner_radius, 0), col_claire,clipper);
        ei_draw_polygon(surface, rounded_frame(button->screen_location, button->corner_radius, 1), col_sombre,clipper);
    } elif (*button->relief == ei_relief_sunken) {
        ei_draw_polygon(surface, rounded_frame(button->screen_location, button->corner_radius, 0), col_sombre,clipper);
        ei_draw_polygon(surface, rounded_frame(button->screen_location, button->corner_radius, 1), col_claire,clipper);
    }
    ei_rect_t nv_rect = {{screen_location.top_left.x + button->border_width, screen_location.top_left.y + button->border_width}, {screen_location.size.width - 2*button->border_width, screen_location.size.height - 2*button->border_width}};
    ei_draw_polygon(surface, rounded_frame(nv_rect, button->corner_radius, 2), *button->color ,clipper);
    hw_surface_unlock(racine_bis);
};

void	ei_button_setdefaultsfunc_t	(struct ei_widget_t*	button)
{
    ((ei_button_t *)button) -> color = &ei_default_background_color;
    ((ei_button_t *)button) -> border_width = k_default_button_border_width;
    ((ei_button_t *)button) -> corner_radius = k_default_button_corner_radius;
    ((ei_button_t *)button) -> relief = ei_relief_raised;
    ((ei_button_t *)button) -> text = NULL;
    ((ei_button_t *)button) -> text_fonte = ei_default_font;
    ((ei_button_t *)button) -> text_color = ei_font_default_color;
    ((ei_button_t *)button) -> text_color = ei_font_default_color;
    ((ei_button_t *)button) -> text_anchor = ei_anc_center;
    ((ei_button_t *)button) -> img = NULL;
    ((ei_button_t *)button) -> img_rect = NULL;
    ((ei_button_t *)button) -> img_anchor = ei_anc_center;
    ((ei_button_t *)button) -> callback = NULL;
    ((ei_button_t *)button) -> user_param = NULL;
};


extern ei_widgetclass_t classe_button =
        {
                "button",
                &ei_button_allocfunc_t,
                &ei_button_releasefunc_t,
                &ei_button_drawfunc_t,
                &ei_button_setdefaultsfunc_t,
                NULL,
                NULL
        };
