//
// Created by axel on 15/05/22.
//

#ifndef PROJETC_IG_EI_FCT_ANNEXES_H
#define PROJETC_IG_EI_FCT_ANNEXES_H

#endif //PROJETC_IG_EI_FCT_ANNEXES_H

<<<<<<< HEAD
#include <ei_types.h>
/**
 * @brief 	Return the lower value between the 2 given.
 *
 * @param 	a 		First int to compare.
 * @param 	b		Second int to compare.
 *
 * @return 			The lower value between the 2.
 */
int     min     (int a,
                 int b);
/**
 * @brief 	Return the higher value between the 2 given.
 *
 * @param 	a 		First int to compare.
 * @param 	b		Second int to compare.
 *
 * @return 			The higher value between the 2.
 */
int     max     (int a,
                 int b);

/**
 * @brief 	It returns the point of the rectangle pointed by the anchor.
 *
 * @param 	ancre 		Which point is pointed.
 * @param 	b		The rectangle pointed by the anchor.
 *
 * @return 			the point of the rectangle pointed by the anchor.
 */
ei_point_t* anchor_to_point(ei_anchor_t* ancre,
                           ei_rect_t* rect);
=======
#include <math.h>
#include <ei_types.h>

int     min     (int a,
                 int b);

int     max     (int a,
                 int b);

ei_linked_point_t*       arc[2]            (ei_point_t     centre,
                                            int          rayon,
                                            float          pre_angle,
                                            float          deu_angle);
>>>>>>> refs/remotes/origin/master
