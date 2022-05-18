#include <math.h>
#include <ei_types.h>
#include <ei_widget.h>

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

ei_point_t* anchor_to_point(const ei_anchor_t ancre, ei_rect_t* rect)
{
        ei_point_t* point = malloc(sizeof(ei_point_t));
        if (ancre != ei_anc_none)
        {
                ei_size_t size = rect->size;
                int width = size.width;
                int height = size.height;
                if (ancre == ei_anc_northeast)
                {
                        return &(rect->top_left);
                }
                else if (ancre == ei_anc_north)
                {
                        int point_x = width/3;
                        point->x = point_x;
                        point->y = 0;
                        return point;
                }
                else if (ancre == ei_anc_northwest)
                {
                        int point_x = 2*width/3;
                        point->x = point_x;
                        point->y = 0;
                        return point;
                }
                else if (ancre == ei_anc_east)
                {
                        int point_y = height/3;
                        point->x = 0;
                        point->y = point_y;
                        return point;
                }
                else if (ancre == ei_anc_center)
                {
                        int point_x = width/3;
                        int point_y = height/3;
                        point->x = point_x;
                        point->y = point_y;
                        return point;
                }
                else if (ancre == ei_anc_west)
                {
                        int point_x = 2*width/3;
                        int point_y = height/3;
                        point->x = point_x;
                        point->y = point_y;
                        return point;
                }
                else if (ancre == ei_anc_southeast)
                {
                        int point_y = 2*height/3;
                        point->x = 0;
                        point->y = point_y;
                        return point;
                }
                else if (ancre == ei_anc_south)
                {
                        int point_x = width/3;
                        int point_y = 2*height/3;
                        point->x = point_x;
                        point->y = point_y;
                        return point;
                }
                else if (ancre == ei_anc_southwest)
                {
                        int point_x = 2*width/3;
                        int point_y = 2*height/3;
                        point->x = point_x;
                        point->y = point_y;
                        return point;
                }
        }
        return &(rect->top_left); /* If it is none it will return the northeast point*/
}

void free_link(ei_linked_point_t *deb) {
        ei_linked_point_t* sauvegarde = deb;
        while (deb->next != NULL) {
                deb = deb->next;
                free(sauvegarde);
                sauvegarde = deb;
        }
        free(deb);
}
