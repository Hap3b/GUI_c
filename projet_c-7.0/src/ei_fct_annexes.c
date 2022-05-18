<<<<<<< HEAD
#include <ei_types.h>
=======
#include <math.h>
#include <ei_types.h>
#include <ei_widget.h>
>>>>>>> refs/remotes/origin/master

int     min     (int a,
                 int b)
{
        return a < b ? a : b;
<<<<<<< HEAD
}
=======
};
>>>>>>> refs/remotes/origin/master

int     max     (int a,
                 int b)
{
        return a > b ? a : b;
}

<<<<<<< HEAD
ei_point_t* anchor_to_point(const ei_anchor_t* ancre, ei_rect_t* rect)
{
        if (ancre != ei_anc_none)
        {
                ei_size_t size = rect->size;
                int width = size.width;
                int height = size.height;
                if (*ancre == ei_anc_northeast)
                {
                        return &(rect->top_left);
                }
                else if (*ancre == ei_anc_north)
                {
                        int point_x = width/3;
                        ei_point_t point;
                        point.x = point_x;
                        point.y = 0;
                        return &point;
                }
                else if (*ancre == ei_anc_northwest)
                {
                        int point_x = 2*width/3;
                        ei_point_t point;
                        point.x = point_x;
                        point.y = 0;
                        return &point;
                }
                else if (*ancre == ei_anc_east)
                {
                        int point_y = height/3;
                        ei_point_t point;
                        point.x = 0;
                        point.y = point_y;
                        return &point;
                }
                else if (*ancre == ei_anc_center)
                {
                        int point_x = width/3;
                        int point_y = height/3;
                        ei_point_t point;
                        point.x = point_x;
                        point.y = point_y;
                        return &point;
                }
                else if (*ancre == ei_anc_west)
                {
                        int point_x = 2*width/3;
                        int point_y = height/3;
                        ei_point_t point;
                        point.x = point_x;
                        point.y = point_y;
                        return &point;
                }
                else if (*ancre == ei_anc_southeast)
                {
                        int point_y = 2*height/3;
                        ei_point_t point;
                        point.x = 0;
                        point.y = point_y;
                        return &point;
                }
                else if (*ancre == ei_anc_south)
                {
                        int point_x = width/3;
                        int point_y = 2*height/3;
                        ei_point_t point;
                        point.x = point_x;
                        point.y = point_y;
                        return &point;
                }
                else if (*ancre == ei_anc_southwest)
                {
                        int point_x = 2*width/3;
                        int point_y = 2*height/3;
                        ei_point_t point;
                        point.x = point_x;
                        point.y = point_y;
                        return &point;
                }
        }
        return &(rect->top_left); /* If it is none it will return the northeast point*/
}
=======
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
>>>>>>> refs/remotes/origin/master
