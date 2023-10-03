#include <android_native_app_glue.h>
#include <jni.h>

extern "C" {

    void handle_cmd(android_app* app, int32_t cmd) {
    }

    void android_main(struct android_app* app) {
        app->onAppCmd = handle_cmd;

        int events;
        android_poll_source* source;
        do {
            if(ALooper_pollAll(0, nullptr, &events, (void**)&source) >= 0) {
                if(source) {
                    source->process(app, source);
                }
            }
        } while(!app->destroyRequested);
    }

}