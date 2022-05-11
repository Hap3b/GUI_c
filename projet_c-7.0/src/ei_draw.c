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
                                                            const ei_rect_t*	clipper)
{
        hw_surface_lock(surface);
        uint32_t* origin = (hw_surface_get_buffer(surface)); /* Change in 32 bit to have an easier access to the pixel */
        uint32_t pixel_to_print = ei_map_rgba(surface, *color);
        ei_size_t size = hw_surface_get_size(surface);
        int height;
        int width;
        int clipper_x;
        int clipper_y;
        if (clipper != NULL)
        {
                int clipper_x = clipper->top_left.x;
                int clipper_y = clipper->top_left.y;
                if (clipper->size.width > size.width)
                {
                        width = size.width;
                }
                else
                {
                        width = clipper->size.width;
                }
                if (clipper->size.height > size.height)
                {
                        height = size.height;
                }
                else
                {
                        height = clipper->size.height;
                }
        }
        else
        {
                int clipper_x = 0;
                int clipper_y = 0;
                int width = size.width;
                int height = size.height;
        }
        for (int i = clipper_x; i < width; i++)
        {
                for (int j = clipper_y; j < height; j++)
                {
                        *origin = pixel_to_print;
                        origin++; /* Next memory space */
                }
        }
        hw_surface_unlock(surface);
}

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
