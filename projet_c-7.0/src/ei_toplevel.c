#include <ei_widgetclass.h>
#include <ei_widget.h>
#include <ei_types.h>

typedef struct ei_toplevel_t {
        ei_widget_t* widget;
        ei_size_t* requested_size;
        ei_color_t* color;
        int* border_width;
        char** title;
        ei_bool_t* closable;
        ei_axis_set_t* resizable;
        ei_size_t** min_size;
} ei_toplevel_t;

struct ei_toplevel_t*      ei_toplevel_allocfunc_t        (void)
{
        struct ei_toplevel_t *toplevel = calloc(1, sizeof(ei_toplevel_t));
        return toplevel;
};

void        ei_toplevel_releasefunc_t      (struct ei_toplevel_t*	toplevel)
{
        free(toplevel -> requested_size);
        free(toplevel-> color);
        free(toplevel-> border_width);
        free(toplevel-> title);
        free(toplevel-> closable);
        free(toplevel-> resizable);
        free(toplevel-> min_size);
};

void	ei_toplevel_drawfunc_t		(struct ei_widget_t*	widget,
                                                 ei_surface_t		surface,
                                                 ei_surface_t		pick_surface,
                                                 ei_rect_t*		clipper)
{

}


void	ei_toplevel_setdefaultsfunc_t	(struct ei_widget_t*	toplevel)
{
        ei_size_t *r_size = malloc(sizeof(ei_size_t));
        r_size->width = 320;
        r_size->height = 240;
        ei_color_t* cl = malloc(sizeof(ei_color_t));
        *cl = ei_default_background_color;
        int *b_width = malloc(sizeof(int));
        *b_width = 4;
        char **ttl = malloc(sizeof(char));
        *ttl = "Toplevel";
        ei_bool_t* clb = malloc(sizeof(ei_bool_t));
        *clb = EI_TRUE;
        ei_axis_set_t* rsb = malloc(sizeof(ei_axis_set_t));
        *rsb = ei_axis_both;
        ei_size_t *m_size = malloc(sizeof(ei_size_t));
        m_size->width = 160;
        m_size->height = 120;
        ((ei_toplevel_t *)toplevel) -> requested_size = r_size;
        ((ei_toplevel_t *)toplevel) -> color = cl;
        ((ei_toplevel_t *)toplevel) -> border_width = b_width;
        ((ei_toplevel_t *)toplevel) -> title = ttl;
        ((ei_toplevel_t *)toplevel) -> closable = clb;
        ((ei_toplevel_t *)toplevel) -> resizable = rsb;
        ((ei_toplevel_t *)toplevel) -> min_size = &m_size;

};
