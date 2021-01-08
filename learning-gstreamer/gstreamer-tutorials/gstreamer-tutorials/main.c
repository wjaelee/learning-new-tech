//
//  main.c
//  gstreamer-tutorials
//
//  Created by Wung Jae Lee on 1/8/21.
//

#include <gst/gst.h>

int main(int argc, char * argv[]) {
    // insert code here...
    GMainLoop *main_loop;
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;
    
    /* Initalize GStreamer */
    gst_init(&argc, &argv);
    
    /* Build the pipeline */
    pipeline = gst_parse_launch("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm", NULL);
    
    main_loop = g_main_loop_new(NULL, FALSE);
    
    /* Start playing */
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    g_main_loop_run(main_loop);
    /* Wait until error or EOS */
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);
    
    /* Free resources */
    if (msg != NULL)
        gst_message_unref(msg);
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;
}
