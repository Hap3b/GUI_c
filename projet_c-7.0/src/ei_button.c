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

