#include<ei_widget.h>
#include<ei_widgetclass.h>
#include<ei_widget.h>
/**
 * \brief	Browse the tree widget and draw all of them.
 *
 */
void dessine_tout_widget();

/**
 * The first widget. It could be filled with text and image.
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
 * \brief	Reserve the space needed by a frame
 *
 */
struct ei_frame_t*      ei_frame_allocfunc_t        (void);


/**
 * \brief	free the space needed by a frame
 *
 * @param frame the frame which should be free
 */
void        ei_frame_releasefunc_t      (struct ei_frame_t*	frame);

/**
 * \brief	Set the default value to a frame
 *
 * @param  frame the frame which should be set to default
 */
void	ei_frame_setdefaultsfunc_t	(struct ei_widget_t*	frame);

/**
 * \brief	A function called in  \ref dessine_tout to draw a frame
 *
 * @param  widget       the frame which should be drawn but it is cast as a widget to be in a widget_class
 * @param  surface      the surface representing the frame
 * @param  pick_surface the surface representing the offscreen
 * @param  clipper      if it is not NULL the drawing is restricted in this rectangle.
 */
void	ei_frame_drawfunc_t		(struct ei_widget_t*	widget,
                                                ei_surface_t		surface,
                                                ei_surface_t		pick_surface,
                                                ei_rect_t*		clipper);

/**
 * \brief	A function returning the widget_class of a frame
 *
 * @return      A pointer to the widget_class frame.
 */
ei_widgetclass_t* addr_frame();

