#include "hw_interface.h"

uint32_t		ei_map_rgba		(ei_surface_t surface, ei_color_t color)
{
    int *ia;
    int *ig;
    int *ir;
    int *ib;
    hw_surface_get_channel_indices(surface, ir, ig, ib, ia);
    uint32_t tot = 0;
    tot += color.red << (8 * (*ir));
    tot += color.blue << (8 * (*ib));
    tot += color.green << (8 * (*ig));
    if (*ia == -1) {
        return tot;
    }
    tot += color.alpha << (8* (*ia));
    return tot;
}

int ei_copy_surface (ei_surface_t		destination,
                     const ei_rect_t*	dst_rect,
                     ei_surface_t		source,
                     const ei_rect_t*	src_rect,
                     ei_bool_t		alpha)
;

void			ei_fill			(ei_surface_t		surface,
                                                            const ei_color_t*	color,
                                                            const ei_rect_t*	clipper);

void			ei_draw_text		(ei_surface_t		surface,
                                                         const ei_point_t*	where,
                                                         const char*		text,
                                                         ei_font_t		font,
                                                         ei_color_t		color,
                                                         const ei_rect_t*	clipper)
{
        hw_surface_lock(surface);
        ei_surface_t surfa_text = hw_text_create_surface(text, font, color);
        hw_surface_lock(surfa_text);
        int* width;
        int* height;
        hw_text_compute_size(text, font, width, height);
        ei_size_t* size;
        size->height = *height;
        size->width  = *width;
        ei_rect_t* src_rect;
        src_rect->top_left = *where;
        src_rect->size = *size;
        ei_fill(surfa_text, &color, clipper);
        ei_copy_surface(surface, src_rect, surfa_text, src_rect, EI_FALSE);
        hw_surface_unlock(surface);
        hw_surface_unlock(surfa_text);
}
