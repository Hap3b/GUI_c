#include<ei_widget.h>
#include<ei_widgetclass.h>
#include<ei_widget.h>

/**
 *@brief Browse the widget tree and draw them
 */
void dessine_tout_widget();

/**
*			Frame is the first widget. It can be composed by text and images
*			Ancre is the position where to place the frame in the root widget.
*/
typedef struct ei_frame_t {
        ei_widget_t     widget;
        ei_relief_t     relief;
        int            border_width;
        char*           title;
        ei_font_t       title_fonte;
        ei_anchor_t     title_anchor;
        ei_color_t      color;
        ei_color_t     color_title;
        ei_anchor_t     ancre;
        ei_surface_t    img;
        ei_rect_t*       img_rect;
        ei_anchor_t     img_anchor;

}ei_frame_t;

/**
 *@brief Reserve the memory space needed for a frame
 */
struct ei_frame_t*      ei_frame_allocfunc_t        (void);

/**
 *@brief Free the memory space needed for a frame
 */
void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);

/**
 *@brief If a value of a frame is not precised, this value is set by this function
 *
 * @param       frame           Frame to configure by default.
 */
void	ei_frame_setdefaultsfunc_t	(struct ei_widget_t*	frame);

/**
 *@brief A function called in \ref dessine_tout_widget() to draw the frame
 *
 * @param       widget           In order to be called in a ei_widget_class frame need to be cast as a widget
 * @param       surface          The surface where the frame is defined
 * @param       pick_surface     The surface where the offscreen is defined
 * @param       widget           If it is not NULL the frame drawn is restricted in the clipper
 */
void	ei_frame_drawfunc_t		(struct ei_widget_t*	widget,
                                                ei_surface_t		surface,
                                                ei_surface_t		pick_surface,
                                                ei_rect_t*		clipper);

/**
 *@brief To get a pointer pointer the widget_class of frame
 *
 * @return                       The address of the widget_class frame
 */
ei_widgetclass_t* addr_frame();

