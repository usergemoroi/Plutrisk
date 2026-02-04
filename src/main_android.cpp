#ifdef __ANDROID__

#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"
#include "gui/menu.h"

#include <android/log.h>
#include <android_native_app_glue.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "CheatMenuMockup", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "CheatMenuMockup", __VA_ARGS__))

struct Engine {
    struct android_app* app;
    EGLDisplay display;
    EGLSurface surface;
    EGLContext context;
    int32_t width;
    int32_t height;
    bool initialized;
    CheatMenu* menu;
};

static int engine_init_display(Engine* engine) {
    const EGLint attribs[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_BLUE_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_RED_SIZE, 8,
        EGL_DEPTH_SIZE, 24,
        EGL_NONE
    };
    
    EGLint w, h, format;
    EGLint numConfigs;
    EGLConfig config = nullptr;
    
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(display, nullptr, nullptr);
    eglChooseConfig(display, attribs, &config, 1, &numConfigs);
    eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format);
    
    ANativeWindow_setBuffersGeometry(engine->app->window, 0, 0, format);
    
    EGLSurface surface = eglCreateWindowSurface(display, config, engine->app->window, nullptr);
    
    const EGLint contextAttribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 3,
        EGL_NONE
    };
    
    EGLContext context = eglCreateContext(display, config, nullptr, contextAttribs);
    
    if (eglMakeCurrent(display, surface, surface, context) == EGL_FALSE) {
        LOGE("eglMakeCurrent failed");
        return -1;
    }
    
    eglQuerySurface(display, surface, EGL_WIDTH, &w);
    eglQuerySurface(display, surface, EGL_HEIGHT, &h);
    
    engine->display = display;
    engine->context = context;
    engine->surface = surface;
    engine->width = w;
    engine->height = h;
    
    glViewport(0, 0, w, h);
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    
    ImGui_ImplAndroid_Init(engine->app->window);
    ImGui_ImplOpenGL3_Init("#version 300 es");
    
    engine->menu = new CheatMenu();
    engine->initialized = true;
    
    LOGI("Display initialized: %dx%d", w, h);
    
    return 0;
}

static void engine_term_display(Engine* engine) {
    if (engine->menu) {
        delete engine->menu;
        engine->menu = nullptr;
    }
    
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();
    ImGui::DestroyContext();
    
    if (engine->display != EGL_NO_DISPLAY) {
        eglMakeCurrent(engine->display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        if (engine->context != EGL_NO_CONTEXT) {
            eglDestroyContext(engine->display, engine->context);
        }
        if (engine->surface != EGL_NO_SURFACE) {
            eglDestroySurface(engine->display, engine->surface);
        }
        eglTerminate(engine->display);
    }
    
    engine->display = EGL_NO_DISPLAY;
    engine->context = EGL_NO_CONTEXT;
    engine->surface = EGL_NO_SURFACE;
    engine->initialized = false;
}

static void engine_draw_frame(Engine* engine) {
    if (engine->display == nullptr) return;
    
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame();
    ImGui::NewFrame();
    
    if (engine->menu) {
        engine->menu->Render();
    }
    
    ImGui::Render();
    glViewport(0, 0, engine->width, engine->height);
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    eglSwapBuffers(engine->display, engine->surface);
}

static int32_t engine_handle_input(struct android_app* app, AInputEvent* event) {
    return ImGui_ImplAndroid_HandleInputEvent(event);
}

static void engine_handle_cmd(struct android_app* app, int32_t cmd) {
    Engine* engine = (Engine*)app->userData;
    
    switch (cmd) {
        case APP_CMD_SAVE_STATE:
            break;
        case APP_CMD_INIT_WINDOW:
            if (engine->app->window != nullptr) {
                engine_init_display(engine);
            }
            break;
        case APP_CMD_TERM_WINDOW:
            engine_term_display(engine);
            break;
        case APP_CMD_GAINED_FOCUS:
            break;
        case APP_CMD_LOST_FOCUS:
            engine_draw_frame(engine);
            break;
    }
}

void android_main(struct android_app* state) {
    Engine engine = {};
    engine.app = state;
    state->userData = &engine;
    state->onAppCmd = engine_handle_cmd;
    state->onInputEvent = engine_handle_input;
    
    while (true) {
        int ident;
        int events;
        struct android_poll_source* source;
        
        while ((ident = ALooper_pollAll(engine.initialized ? 0 : -1, nullptr, &events, (void**)&source)) >= 0) {
            if (source != nullptr) {
                source->process(state, source);
            }
            
            if (state->destroyRequested != 0) {
                engine_term_display(&engine);
                return;
            }
        }
        
        if (engine.initialized) {
            engine_draw_frame(&engine);
        }
    }
}

#endif
