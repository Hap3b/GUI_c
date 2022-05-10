#include <math.h>

ei_linked_point_t*       arc            (ei_point_t     centre,
                                        float          rayon,
                                        float          pre_angle,
                                        float          deu_angle)
{
    ei_linked_point_t *lis;
    ei_point_t nv_point = malloc(sizeof(ei_point_t));
    nv_point.x = centre.x + (int) (rayon * math.cos(pre_angle));
    nv_point.y = centre.y + (int) (rayon * math.sin(pre_angle));
    lis->point = nv_point;
    lis->next = NULL;
    for (int i = 1; i <= 100; i++) {
        float pas = pre_angle + i * (deu_angle - pre_angle) / 100;
        ei_point_t nv_point = malloc(sizeof(ei_point_t));
        nv_point.x = centre.x + (int) (rayon * math.cos(pas));
        nv_point.y = centre.y + (int) (rayon * math.sin(pas));
        lis = lis->suivant;
        lis->point = nv_point;
        lis->next = NULL;
    }
    return lis;
}

ei_linked_point_t*       rounded_frame              (ei_rect_t     rectangle,
                                                    float          rayon)
{
    ei_linked_point_t *lis;
    ei_point_t centre = malloc(sizeof(ei_point_t));
    centre.x = (int) rayon;
    centre.y = (int) rayon;
    lis->suivant = arc(centre, rayon, -math.pi, -math.pi/2);
}

