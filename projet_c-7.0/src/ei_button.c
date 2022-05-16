#include <math.h>
#include<ei_types.h>
#define min(a, b) = a < b ? a : b;
#define max(a, b) = a > b ? a : b;
#define pi 3.14159
ei_linked_point_t**    arc           (ei_point_t*     centre,
                                            double *          rayon,
                                            double *          pre_angle,
                                            double*          deu_angle)
{
        ei_linked_point_t *lis = malloc(sizeof(ei_linked_point_t));

        ei_linked_point_t* lis_bis = lis;
        ei_linked_point_t** retour = calloc(2, sizeof(ei_linked_point_t));
        retour[0] = lis;
        retour[1] = lis_bis;
        if(*pre_angle > *deu_angle) {
                for (int i = 0; i <= 1000; i++) {
                        double pas = (double) *pre_angle + i * (double) (*deu_angle - *pre_angle) / 1000;
                        ei_point_t *nv_point2 = malloc(sizeof(ei_point_t));
                        long oui = lround((float) *rayon * cos(pas));
                        nv_point2->x = centre->x + (int) oui;
                        long non = lround((float) *rayon * sin(pas));
                        nv_point2->y = centre->y + (int) non;
                        lis->point = *nv_point2;
                        if (lis->next == NULL) {
                                lis->next = malloc(sizeof(ei_linked_point_t));
                                lis->next->next = NULL;
                                lis->next->point.x = lis->point.x;
                                lis->next->point.y = lis->point.y;
                        }
                        lis = lis->next;
                }
        }
        else
        {
                for (int i = 0; i <= 5; i++) {
                        double pas = (double) *pre_angle + i * (double) (*deu_angle - *pre_angle) / 5;
                        ei_point_t *nv_point2 = malloc(sizeof(ei_point_t));
                        long oui = lround((float) *rayon * cos(pas));
                        nv_point2->x = centre->x + (int) oui;
                        long non = lround((float) *rayon * sin(pas));
                        nv_point2->y = centre->y - (int) non;
                        lis->point = *nv_point2;
                        if (lis->next == NULL) {
                                lis->next = malloc(sizeof(ei_linked_point_t));
                                lis->next->next = NULL;
                                lis->next->point.x = lis->point.x;
                                lis->next->point.y = lis->point.y;
                        }
                        lis = lis->next;
                }
        }
        return retour;

}

ei_linked_point_t*       rounded_frame              (ei_rect_t*     rectangle,
                                                     double*          rayon,
                                                     int*            partie)
{
        int h = rectangle ->size.height;
        ei_point_t* centre_r = malloc(sizeof(ei_point_t));
        centre_r -> x = rectangle->top_left.x +sqrt((*rayon)*(*rayon)/2);
        centre_r -> y = rectangle->top_left.y - sqrt((*rayon)*(*rayon)/2);
        double * pii = malloc(sizeof(double));
        *pii = pi;
        double * pii2 = malloc(sizeof(double));
        *pii = pi/2;
        ei_linked_point_t* cadre = malloc(sizeof(ei_linked_point_t));
        // Si partie = 0, on dessine la partie haute; si partie = 1, on dessine la partie basse; si partie = 2, on dessine tout le button
       switch(*partie)
       {
               case 0:
                       break;
               case 1:
                       break;
               case 2:
                       cadre = arc(centre_r,rayon,pii,pii2);


                       break;

        }
}
/*
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
*/