#include "hw_interface.h"

uint32_t		ei_map_rgba		(ei_surface_t surface, ei_color_t color)
{
    int *ia;
    int *ib;
    int *ir;
    int *ib;
    hw_surface_get_channel_indices(surface, ir, ig, ib, ia);
    uint32_t tot = 0;
    tot += color.red << (8 * (*ir));
    tot += color.blue << (8 * (*ib));
    tot += color.green << (8 * (*ig));
    if (*ia == -1) {
        return tot
    };
    tot += color.alpha << (8* (*ia));
    return tot;
}
