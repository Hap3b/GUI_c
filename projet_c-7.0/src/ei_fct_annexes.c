#include <math.h>
#include "ei_types.h"
#include <stdlib.h>
#include <stdio.h>

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

void print_point(ei_point_t point)
{
        printf("%d, %d \n", point.x, point.y);
}

ei_linked_point_t**    arc           (ei_point_t*     centre,
                                      double          rayon,
                                      double          pre_angle,
                                      double          deu_angle)
{
        ei_linked_point_t *lis = malloc(sizeof(ei_linked_point_t));
        ei_linked_point_t* lis_bis = lis;
        lis->next = NULL;
        for (int i = 0; i <= 10; i++) {
                double pas = (double) pre_angle + i * (double) (deu_angle - pre_angle) / 10;
                ei_point_t *nv_point2 = malloc(sizeof(ei_point_t));
                long oui = lround((float) rayon * cos(pas));
                nv_point2->x = centre->x + (int) oui;
                long non = lround((float) rayon * sin(pas));
                nv_point2->y = centre->y + (int) non;
                lis->point = *nv_point2;
                free(nv_point2);
                if (i != 10) {
                        lis->next = malloc(sizeof(ei_linked_point_t));
                        lis->next->next = NULL;
                        lis->next->point.x = lis->point.x;
                        lis->next->point.y = lis->point.y;
                        lis = lis->next;
                }
        }
        ei_linked_point_t** retour = calloc(2, sizeof(ei_linked_point_t));
        retour[0] = lis_bis;
        retour[1] = lis;
        return retour;
}

void    free_arc        (struct ei_linked_point_t** arc)
{
        ei_linked_point_t* list = arc[0];
        ei_linked_point_t* list_next = list->next;
        while (list_next != NULL) {
                free(list);
                list = list_next;
                list_next = list_next->next;
        }
        free(list);
        free(arc);
}

void print_list(ei_linked_point_t* list){
        if (list != NULL) {
                print_point(list->point);
                list = list->next;
                print_list(list);
        }
}
