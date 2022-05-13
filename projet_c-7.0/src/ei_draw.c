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
{
        ei_size_t size_src;
        ei_size_t size_dst;
        ei_point_t dbt_dst;
        ei_point_t dbt_src;
        ei_size_t size_surface;
        if (dst_rect != NULL)
        {
                ei_size_t size_dst = dst_rect->size;
                ei_point_t dbt_dst = dst_rect->top_left;
        }
        else
        {
                ei_size_t size_dst = hw_surface_get_size(destination);
                ei_point_t dbt_dst = {0 , 0};
        }
        if (src_rect != NULL)
        {
                ei_size_t size_src = src_rect->size;
                ei_point_t dbt_src = src_rect->top_left;
        }
        else
        {
                ei_size_t size_src = hw_surface_get_size(source);
                ei_point_t dbt_src = {0, 0};
        }
        int width = size_dst.width;
        int height = size_dst.height;
        int difference = size_surface.width - width;
        if ((size_src.height != size_dst.height) || (size_src.height != size_dst.height))
        {
                return 1;
        }
        else
        {
                hw_surface_lock(destination);
                hw_surface_lock(source);
                uint32_t* pixel_dst = hw_surface_get_buffer(destination);
                uint32_t* pixel_src = hw_surface_get_buffer(source);
                for (int y = 0; y < dbt_dst.y; y++)
                {
                        for (int x = 0; x < dbt_dst.x; x++)
                        {
                                pixel_dst++; /* Place the pointer to the right address */
                        }
                }
                for (int y = 0; y < dbt_src.y; y++)
                {
                        for (int x = 0; x < dbt_src.x; x++)
                        {
                                pixel_src++; /* Place the pointer to the right address */
                        }
                }
                if (alpha == EI_FALSE)
                {
                        for (int j = 0; j < width; j++)
                        {
                                for (int i = 0; i < height; i++)
                                {
                                        *pixel_dst = *pixel_src;
                                        pixel_dst++;
                                        pixel_src++;
                                }
                                for (int k = 0; k < difference; k++)
                                {
                                        pixel_dst++; /* case if one of the rectangle is not NULL, place the pointer to right address */
                                        pixel_src++;
                                }
                        }
                }
                else
                {
                        for (int j = 0; j < width; j++)
                        {
                                for (int i = 0; i < height; i++)
                                {
                                        *pixel_dst = (*pixel_src + *pixel_dst)/2; /* Average in count of the alpha channel */
                                        int *ia;
                                        int *ig;
                                        int *ir;
                                        int *ib;
                                        hw_surface_get_channel_indices(destination, ir, ig, ib, ia);
                                        *pixel_dst += 0xff << (8* (*ia)); /* Set to opaque */
                                        pixel_dst++;
                                        pixel_src++;
                                }
                                for (int k = 0; k < difference; k++)
                                {
                                        pixel_dst++; /* case if one of the rectangle is not NULL, place the pointer to right address */
                                        pixel_src++;
                                }
                        }
                }
                return 0;
        }
}

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

