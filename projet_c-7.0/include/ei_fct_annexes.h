//
// Created by axel on 15/05/22.
//

#ifndef PROJETC_IG_EI_FCT_ANNEXES_H
#define PROJETC_IG_EI_FCT_ANNEXES_H

#endif //PROJETC_IG_EI_FCT_ANNEXES_H

#include <ei_types.h>
/**
 * \brief	Returns the lower value.
 *
 * @param	a		First value to compare.
 * @param	b		Second value to compare.
 *
 * @return                      The lower value
 */
int     min     (int a,
                 int b);
/**
 * \brief	Returns the higher value.
 *
 * @param	a		First value to compare.
 * @param	b		Second value to compare.
 *
 * @return                      The higher value
 */
int     max     (int a,
                 int b);

/**
 * \brief	Returns the point of the rectangle pointed by the anchor.
 *
 * @param	ancre		Anchor pointing a point of a rectangle.
 * @param	rect		The rectangle pointed.
 *
 * @return                      The higher value
 */
ei_point_t* anchor_to_point(ei_anchor_t* ancre,
                           ei_rect_t* rect);