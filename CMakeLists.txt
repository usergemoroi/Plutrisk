cmake_minimum_required(VERSION 3.10)
project(CheatMenuMockup)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ImGui sources
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
)

# Platform-specific setup
if(ANDROID)
    # Android build
    add_library(native-lib SHARED
        src/main_android.cpp
        src/gui/menu.cpp
        src/gui/tabs/aimbot_tab.cpp
        src/gui/tabs/visuals_tab.cpp
        src/gui/tabs/exploits_tab.cpp
        src/gui/tabs/skins_tab.cpp
        src/gui/tabs/config_tab.cpp
        src/gui/tabs/settings_tab.cpp
        ${IMGUI_SOURCES}
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_DIR}/backends/imgui_impl_android.cpp
    )

    target_include_directories(native-lib PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
    )

    target_link_libraries(native-lib
        android
        log
        EGL
        GLESv3
    )
else()
    # Desktop build with GLFW
    find_package(OpenGL REQUIRED)
    
    add_executable(CheatMenuMockup
        src/main_desktop.cpp
        src/gui/menu.cpp
        src/gui/tabs/aimbot_tab.cpp
        src/gui/tabs/visuals_tab.cpp
        src/gui/tabs/exploits_tab.cpp
        src/gui/tabs/skins_tab.cpp
        src/gui/tabs/config_tab.cpp
        src/gui/tabs/settings_tab.cpp
        ${IMGUI_SOURCES}
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    )

    target_include_directories(CheatMenuMockup PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
    )

    # Try to find GLFW
    find_package(glfw3 QUIET)
    if(glfw3_FOUND)
        target_link_libraries(CheatMenuMockup glfw OpenGL::GL)
    else()
        # Build GLFW from source if not found
        set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
        set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
        set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glfw EXCLUDE_FROM_ALL)
        target_link_libraries(CheatMenuMockup glfw OpenGL::GL)
    endif()
endif()
