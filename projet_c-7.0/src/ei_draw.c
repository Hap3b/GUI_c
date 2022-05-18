#include "hw_interface.h"

uint32_t		ei_map_rgba		(ei_surface_t surface, ei_color_t color)
{
    int *ia;
    int *ib;
    int *ir;
    int *ig;
    hw_surface_get_channel_indices(surface, ir, ig, ib, ia);
    uint32_t tot = 0;
    tot += color.red << (8 * (*ir));
    tot += color.blue << (8 * (*ib));
    tot += color.green << (8 * (*ig));
    if (*ia == -1) {
        return tot;
    };
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
        ei_point_t* dbt_dst = malloc(sizeof(ei_point_t));
        ei_point_t* dbt_src = malloc(sizeof(ei_point_t));
        hw_surface_lock(destination);
        hw_surface_lock(source);
        uint32_t* pixel_dst = (uint32_t*) hw_surface_get_buffer(destination);
        uint32_t* pixel_src = (uint32_t*) hw_surface_get_buffer(source);
        if (dst_rect != NULL)
        {
                size_dst = dst_rect->size;
                *dbt_dst = dst_rect->top_left;
                pixel_dst += size_dst.width * dbt_dst->y + dbt_dst->x;
        }
        else
        {
                size_dst = hw_surface_get_size(destination);
                dbt_dst->x      = 0;
                dbt_dst->y      = 0;
        }
        if (src_rect != NULL)
        {
                size_src = src_rect->size;
                *dbt_src = src_rect->top_left;
                pixel_src += size_src.width * dbt_src->y + dbt_src->x;
        }
        else
        {
                size_src = hw_surface_get_size(source);
                dbt_src->x = 0;
                dbt_src->y = 0;
        }
        int width = size_dst.width;
        int height = size_dst.height;
        int difference_source = size_src.width - width;
        int difference_destination = size_dst.width - width;
        if ((size_src.height != size_dst.height) || (size_src.width != size_dst.width))
        {
                hw_surface_unlock(source);
                hw_surface_unlock(destination);
                return 1;
        }
        else
        {
                if (alpha == EI_FALSE)
                {
                        for (int j = 0; j < height; j++)
                        {
                                for (int i = 0; i < width; i++)
                                {
                                        *pixel_dst = *pixel_src;
                                        pixel_dst++;
                                        pixel_src++;
                                }
                                pixel_dst += difference_destination;
                                pixel_src += difference_source;
                        }
                }
                else
                {
                        for (int j = 0; j < width; j++)
                        {
                                for (int i = 0; i < height; i++)
                                {
                                        *pixel_dst = (*pixel_src + *pixel_dst)/2; /* Average in count of the alpha channel */
                                        int *ia = malloc(sizeof(int));
                                        int *ig = malloc(sizeof(int));
                                        int *ir = malloc(sizeof(int));
                                        int *ib = malloc(sizeof(int));
                                        hw_surface_get_channel_indices(destination, ir, ig, ib, ia);
                                        (uint8_t) *pixel_src;
                                        (uint8_t) *pixel_dst;
                                        uint8_t Pg;
                                        uint8_t Pb;
                                        uint8_t Pr;
                                        uint8_t Pa;
                                        uint8_t Sg;
                                        uint8_t Sb;
                                        uint8_t Sr;
                                        uint8_t Sa;
                                        for (int k = 0; k < 4; k++){
                                                if (k == *ig){
                                                        Pg = (uint8_t) *pixel_src;
                                                        Sg = (uint8_t) *pixel_dst;
                                                }
                                                else if (k == *ib){
                                                        Pb = (uint8_t) *pixel_src;
                                                        Sb = (uint8_t) *pixel_dst;
                                                }
                                                else if (k == *ir){
                                                        Pr = (uint8_t) *pixel_src;
                                                        Sr = (uint8_t) *pixel_dst;
                                                }
                                                else {
                                                        Pa = (uint8_t) *pixel_src;
                                                        Sa = (uint8_t) *pixel_src;
                                                }
                                                pixel_src++;
                                                pixel_dst++;
                                        }
                                        Sr = (Pa * Pr + (255 - Pa)*Sr)/255;
                                        Sg = (Pa * Pg + (255 - Pa)*Sg)/255;
                                        Sb = (Pa * Pb + (255 - Pa)*Sb)/255;
                                        uint32_t* tot = 0;
                                        uint32_t init = Sr << (8 * (*ir));
                                        tot = &init;
                                        *tot += Sb << (8 * (*ib));
                                        *tot += Sg << (8 * (*ig));
                                        if (*ia != -1){
                                                *tot += 0xff << (8* (*ia)); /* Set to opaque */
                                        }
                                        (uint32_t)* pixel_dst;
                                        (uint32_t)* pixel_src;
                                        pixel_dst = tot;
                                }
                                (uint32_t)* pixel_src;
                                pixel_dst += difference_destination; /* Place the pointer to the right address */
                                pixel_src += difference_source;
                        }
                }
                hw_surface_update_rects(destination, NULL);
                hw_surface_update_rects(source, NULL);
                hw_surface_unlock(destination);
                hw_surface_unlock(source);
                return 0;
        }
}

void			ei_fill			(ei_surface_t		surface,
                                                            const ei_color_t*	color,
                                                            const ei_rect_t*	clipper)
{
        hw_surface_lock(surface);
        uint32_t* origin = (uint32_t*) hw_surface_get_buffer(surface); /* Change in 32 bit to have an easier access to the pixel */
        uint32_t pixel_to_print = ei_map_rgba(surface, *color);
        ei_size_t size = hw_surface_get_size(surface);
        int width = size.width;
        int height = size.height;
        if (clipper == NULL){
                for (int i = 0; i < height; i++) {
                        for (int j = 0; j < width; j++) {
                                *origin = pixel_to_print;
                                origin++; /* Next memory space */
                        }
                }
        }
        else {
                width = clipper->size.width;
                height = clipper->size.height;
                int difference = size.width - width;
                origin += clipper->top_left.y * size.width + clipper->top_left.x;
                for (int i = 0; i < height; i++){
                        for (int j = 0; j < width; j++){
                                *origin = pixel_to_print;
                                origin++; /* Next memory space */
                        }
                        origin += difference;
                }
        }
        hw_surface_unlock(surface);
        hw_surface_update_rects(surface, NULL);
}

void			ei_draw_text		(ei_surface_t		surface,
                                                         const ei_point_t* where,
                                                         const char*		text,
                                                         ei_font_t		font,
                                                         ei_color_t		color,
                                                         const ei_rect_t*	clipper)
{
        hw_surface_lock(surface);
        if (font == NULL){
                font = ei_default_font;
        }
        ei_surface_t surfa_text = hw_text_create_surface(text, font, color);
        hw_surface_lock(surfa_text);
        int* width = malloc(sizeof(int));
        int* height = malloc(sizeof(int));
        hw_text_compute_size(text, font, width, height);
        ei_size_t* size = malloc(sizeof(ei_size_t));
        size->height = *height;
        size->width  = *width;
        ei_rect_t* src_rect = malloc(sizeof(ei_rect_t));
        src_rect->top_left = *where;
        src_rect->size = *size;
        ei_rect_t* dst_rect = malloc(sizeof(ei_rect_t));
        *dst_rect = hw_surface_get_rect(surfa_text);
        if (clipper == NULL)
        {
                ei_copy_surface(surface, src_rect, surfa_text, dst_rect, EI_TRUE);
        }
        else
        {
                if (dst_rect->size.width > clipper->size.width){
                        dst_rect->size.width = clipper->size.width;
                }
                else if (dst_rect->size.width > clipper->size.width){
                        dst_rect->size.width = clipper->size.width;
                }
                ei_copy_surface(surface, src_rect, surfa_text, dst_rect, EI_TRUE);
        }
        hw_surface_unlock(surface);
        hw_surface_unlock(surfa_text);
        //hw_surface_free(surfa_text);
        free(size);
        free(src_rect);
}
