#include <math.h>
#include<ei_types.h>
#include<ei_application.h>
#include<ei_variable_globale.h>
#include<ei_widget.h>
#define min(a, b) = a < b ? a : b;
#define max(a, b) = a > b ? a : b;
#define pi 3.14159

void	ei_button_setdefaultsfunc_t	(struct ei_widget_t*	button);

void    arc           (ei_point_t*     centre,
                                            int *          rayon,
                                            double *          pre_angle,
                                            double*          deu_angle,
                                                ei_linked_point_t** deb,
                                                ei_linked_point_t** fin)
{
        if(*pre_angle > *deu_angle) {
                for (int i = 0; i <= 3; i++) {
                        double pas = (double) *pre_angle + i * (double) (*deu_angle - *pre_angle) / 3;
                        ei_point_t *nv_point2 = malloc(sizeof(ei_point_t));
                        long oui = lround((float) *rayon * cos(pas));
                        nv_point2->x = centre->x + (int) oui;
                        long non = lround((float) *rayon * sin(pas));
                        nv_point2->y = centre->y + (int) non;
                        (*fin)->point = *nv_point2;
                        (*fin)->next = malloc(sizeof(ei_linked_point_t));
                        (*fin)->next->next = NULL;
                        (*fin)->next->point.x = (*fin)->point.x;
                        (*fin)->next->point.y = (*fin)->point.y;
                        (*fin) = (*fin)->next;
                }
        }
        else
        {
                for (int i = 0; i <= 3; i++) {
                        double pas = (double) *pre_angle + i * (double) (*deu_angle - *pre_angle) / 3;
                        ei_point_t *nv_point2 = malloc(sizeof(ei_point_t));
                        long oui = lround((float) *rayon * cos(pas));
                        nv_point2->x = centre->x + (int) oui;
                        long non = lround((float) *rayon * sin(pas));
                        nv_point2->y = centre->y - (int) non;
                        (*fin)->point = *nv_point2;
                        (*fin)->next = malloc(sizeof(ei_linked_point_t));
                        (*fin)->next->next = NULL;
                        (*fin)->next->point.x = (*fin)->point.x;
                        (*fin)->next->point.y = (*fin)->point.y;
                        *fin = (*fin)->next;
                }
        }
        return;

}
int miin(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int maax(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void       rounded_frame              (ei_rect_t*     rectangle,
                                       int *          rayon,
                                       int*            partie,
                                       ei_linked_point_t** cadre) {
        int h = rectangle->size.height/2;
        ei_point_t* centre_r = malloc(sizeof(ei_point_t));
        centre_r->x = rectangle->top_left.x + (int)lround(sqrt((*rayon) * (*rayon) / 2));
        centre_r->y = rectangle->top_left.y - (int)lround(sqrt((*rayon) * (*rayon) / 2));
        double *pii = malloc(sizeof(double));
        *pii = pi/4;
        double *pii2 = malloc(sizeof(double));
        *pii2 = pi / 2;
        double* zero = malloc(sizeof(double));
        *zero = 0;
        ei_linked_point_t* fin1 = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* fin2 = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* fin3 = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* fin4 = malloc(sizeof (ei_linked_point_t));
        ei_linked_point_t* fin5 = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* deb = malloc(sizeof (ei_linked_point_t));
        ei_linked_point_t* fin = deb;
        // Si partie = 0, on dessine la partie haute; si partie = 1, on dessine la partie basse; si partie = 2, on dessine tout le button
        switch (*partie) {
                case 0:
                        centre_r -> x =centre_r->x + rectangle->size.width - 2*(int)lround(*rayon);
                        arc(centre_r, rayon, pii, pii2,&deb, &fin);

                        fin->point.x = fin->point.x - rectangle->size.width + 2* (int) lround(*rayon);
                        fin-> next = malloc(sizeof (ei_linked_point_t));
                        fin = fin ->next;
                        fin1 = fin;
                        centre_r->x = centre_r->x - rectangle->size.width + 2 * (int) lround(*rayon);
                        *pii = pi;
                        arc(centre_r, rayon, pii2, pii,&fin,&fin1);

                        fin1->point.y = fin->point.y + rectangle->size.height - 2 * (int) lround(*rayon);
                        fin1 -> next = malloc(sizeof (ei_linked_point_t));
                        fin1 = fin1 -> next;
                        centre_r -> y = centre_r->y + rectangle ->size.height -2*(int)lround(*rayon);
                        fin2 = fin1;
                        *pii2 = 1.25*pi;
                        arc(centre_r,rayon,pii,pii2,&fin1,&fin2);
                        fin2 -> point.x += h;
                        fin2->point.y -= h;
                        fin2-> next = malloc(sizeof (ei_linked_point_t));
                        fin2 -> next -> point.x = rectangle->size.width -2*h + fin2 ->point .x;
                        fin2->next->point.y = fin2->point.y;
                        fin2->next->next = NULL;
                        *cadre = deb;
                        break;
                case 1:
                        centre_r -> y = centre_r -> y + rectangle->size.height - 2* (int) lround(*rayon);
                        *pii2 = 1.25*pi;
                        *pii = 1.5*pi;
                        arc(centre_r,rayon,pii2, pii,&deb,&fin);

                        fin->point.x = fin->point.x + rectangle->size.width - 2 * (int) lround(*rayon);
                        centre_r->x = centre_r ->x + rectangle->size.width - 2* (int) lround(*rayon);
                        fin -> next = malloc(sizeof(ei_linked_point_t));
                        fin = fin -> next;
                        fin1 = fin;
                        *pii2 = 2*pi;
                        arc(centre_r, rayon, pii, pii2,&fin,&fin1);

                        centre_r->y = centre_r ->y - rectangle->size.height + 2* (int) lround(*rayon);
                        *pii = pi/4;
                        fin1 ->point.y = fin1->point.y + rectangle->size.height - 2 *(int) lround(*rayon);
                        fin1 -> next = malloc(sizeof (ei_linked_point_t));
                        fin1 = fin1 -> next;
                        fin2 = fin1;
                        arc(centre_r,rayon,zero,pii,&fin1,&fin2 );
                        fin2 -> point.x -= h;
                        fin2->point.y += h;
                        fin2-> next = malloc(sizeof (ei_linked_point_t));
                        fin2 -> next -> point.x = fin2 ->point .x - rectangle->size.width +2*h ;
                        fin2->next->point.y = fin2->point.y;
                        fin2 -> next->next =NULL;
                        *cadre = deb;


                        break;
                case 2:
                        centre_r -> x =centre_r->x + rectangle->size.width - 2*(int)lround(*rayon);
                        arc(centre_r, rayon, pii, pii2,&deb, &fin);

                        fin->point.x = fin->point.x - rectangle->size.width + 2* (int) lround(*rayon);
                        fin-> next = malloc(sizeof (ei_linked_point_t));
                        fin = fin ->next;
                        fin1 = fin;
                        centre_r->x = centre_r->x - rectangle->size.width + 2 * (int) lround(*rayon);
                        *pii = pi;
                        arc(centre_r, rayon, pii2, pii,&fin,&fin1);

                        fin1->point.y = fin->point.y + rectangle->size.height - 2 * (int) lround(*rayon);
                        fin1 -> next = malloc(sizeof (ei_linked_point_t));
                        fin1 = fin1 -> next;
                        centre_r -> y = centre_r->y + rectangle ->size.height -2*(int)lround(*rayon);
                        fin2 = fin1;
                        *pii2 = (5/4)*pi;
                        arc(centre_r,rayon,pii,pii2,&fin1,&fin2);

                        *pii = 1.5*pi;
                        fin3 = fin2;
                        arc(centre_r,rayon,pii2, pii,&fin2,&fin3);

                        fin3->point.x = fin3->point.x + rectangle->size.width - 2 * (int) lround(*rayon);
                        centre_r->x = centre_r ->x + rectangle->size.width - 2* (int) lround(*rayon);
                        fin3 -> next = malloc(sizeof(ei_linked_point_t));
                        fin3 = fin3 -> next;
                        fin4 = fin3;
                        *pii2 = 2*pi;
                        arc(centre_r, rayon, pii, pii2,&fin3,&fin4);

                        centre_r->y = centre_r ->y - rectangle->size.height + 2* (int) lround(*rayon);
                        *pii = pi/4;
                        fin4 ->point.y = fin4->point.y + rectangle->size.height - 2 *(int) lround(*rayon);
                        fin4 -> next = malloc(sizeof (ei_linked_point_t));
                        fin4 = fin4 -> next;
                        fin5 = fin4;
                        arc(centre_r,rayon,zero,pii,&fin4,&fin5 );
                        fin5->next = NULL;

                        *cadre = deb;
        }
}





typedef struct ei_button_t {
        ei_widget_t widget;
        ei_color_t color;
        int border_width;
        int corner_radius;
        ei_relief_t relief;
        char* text;
        ei_font_t text_font;
        ei_color_t text_color;
        ei_anchor_t text_anchor;
        ei_surface_t img;
        ei_rect_t* img_rect;
        ei_anchor_t img_anchor;
        ei_callback_t callback;
        void* user_param;
} ei_button_t;

ei_widget_t*      ei_button_allocfunc_t        (void)
{
        ei_button_t *button = malloc(sizeof(ei_button_t));
        return (ei_widget_t*)button;
}

void        ei_button_releasefunc_t      (struct ei_widget_t*	button)
{
        free(button);
}

void	ei_button_drawfunc_t		(struct ei_widget_t*	widget,
                                                 ei_surface_t		surface,
                                                 ei_surface_t		pick_surface,
                                                 ei_rect_t*		clipper)
{
        ei_button_t* button = (ei_button_t*)widget;
        ei_linked_point_t* cadre_haut = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* cadre_bas = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* cadre = malloc(sizeof(ei_linked_point_t));
        int partie = 0;
        rounded_frame(&(widget->screen_location), &(button->corner_radius), &partie, &cadre_haut);
        partie = 1;
        rounded_frame(&(widget->screen_location), &(button->corner_radius), &partie, &cadre_bas);
        partie = 2;
        ei_rect_t* interieur = malloc(sizeof(ei_rect_t));
        interieur->size.width = widget->screen_location.size.width-2*((button->border_width));
        interieur->size.height = widget->screen_location.size.height-2*((button->border_width));
        interieur->top_left.x = widget->screen_location.top_left.x + (button->border_width);
        interieur->top_left.y = widget->screen_location.top_left.y + (button->border_width);
        rounded_frame(interieur, &(button->corner_radius), &partie, &cadre);

        ei_color_t* sombre = malloc(sizeof(ei_color_t));
        ei_color_t* clair = malloc(sizeof(ei_color_t));
        sombre ->blue = (uint8_t) miin(button->color.blue+10,255);
        sombre ->green = (uint8_t)miin(button->color.green+10,255);
        sombre ->red = (uint8_t)miin(button->color.red+10,255);
        sombre ->alpha = (uint8_t)button->color.alpha;
        clair ->blue = (uint8_t)maax(button->color.blue-10,0);
        clair ->green = (uint8_t)maax(button->color.green-10,0);
        clair ->red = (uint8_t)maax(button->color.red-10,0);
        clair ->alpha = (uint8_t)button->color.alpha;

        hw_surface_lock(surface);
        hw_surface_lock(pick_surface);


        if (button->relief == ei_relief_raised) {
                ei_draw_polygon(surface, cadre_haut, *clair,clipper);
                ei_draw_polygon(surface, cadre_bas, *sombre,clipper);
        } else
        {
                ei_draw_polygon(surface, cadre_bas, *clair,clipper);
                ei_draw_polygon(surface, cadre_haut, *sombre,clipper);
        }

        ei_draw_polygon(pick_surface, cadre, *(widget->pick_color),clipper);
        ei_draw_polygon(surface, cadre, button->color ,clipper);
        hw_surface_unlock(surface);
        hw_surface_unlock(pick_surface);
}
static ei_widgetclass_t classe_button =
        {
                "button",
                &ei_button_allocfunc_t,
                &ei_button_releasefunc_t,
                &ei_button_drawfunc_t,
                &ei_button_setdefaultsfunc_t,
                NULL,
                NULL
        };

void	ei_button_setdefaultsfunc_t	(struct ei_widget_t*	button)
{
        ei_relief_t default_relief = ei_relief_raised;
        ei_anchor_t default_anchor = ei_anc_center;
        ei_button_t* button_bis = (ei_button_t*) button;

        button_bis->color = ei_default_background_color;
        button_bis -> border_width = k_default_button_border_width;

        button_bis -> corner_radius = k_default_button_corner_radius;
        button_bis -> relief = default_relief;
        button_bis -> text = NULL;
        button_bis -> text_font = ei_default_font;

        button_bis -> text_color = ei_font_default_color;
        button_bis -> text_anchor = default_anchor;
        button_bis -> img = NULL;
        button_bis -> img_rect = NULL;
        button_bis -> img_anchor = default_anchor;
        button_bis -> callback = NULL;
        button_bis -> user_param = NULL;

        button -> wclass = &classe_button;
        button->requested_size.height = 0; /* Half screen on a 1920x1080 screen*/
        button->requested_size.width = 0;
        button ->user_data = NULL;
        button-> destructor = NULL;
        button->parent = NULL;
        button->children_head = NULL;
        button->children_tail = NULL;
        button->next_sibling = NULL;
        button->geom_params = NULL;

}

ei_bool_t	boutton_origin  	(ei_widget_t*		widget,
                                          struct ei_event_t*	event,
                                          void*			user_param){

        ei_button_t* button = (ei_button_t*) widget;
        ei_relief_t relief_act;
        if ((button ->relief) == ei_relief_raised)
        {
                relief_act = ei_relief_sunken;
        }
        else
        {
                relief_act = ei_relief_raised;
        }
        ei_button_configure(widget, NULL, NULL, NULL, NULL,&relief_act, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
        ei_button_drawfunc_t(widget, ei_app_root_surface(), addr_surface_cache(), NULL);
        return EI_FALSE;
}

ei_callback_t addr_boutton_origin()
{
        return &boutton_origin;
}

ei_widgetclass_t* addr_button()
{
        return &classe_button;
}


