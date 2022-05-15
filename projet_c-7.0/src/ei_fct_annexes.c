#include <math.h>
#include <ei_types.h>

int     min     (int a,
                 int b)
{
        return a < b ? a : b;
};

int     max     (int a,
                 int b)
{
        return a > b ? a : b;
}

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
};