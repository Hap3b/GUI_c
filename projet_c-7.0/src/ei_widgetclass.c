//
// Created by jules on 03/05/22.
//

struct ei_widget_t *ei_widgetclass_allocfunc_t(void)
        {
    struct ei_widget_t *widget = calloc(1, sizeof(ei_widget_t));
    return widget;
        };