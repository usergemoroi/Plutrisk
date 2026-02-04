# Project Structure

Visual guide to the codebase organization.

## Directory Tree

```
project/
├── .git/                       # Git repository
├── .gitignore                  # Ignore build artifacts
│
├── CMakeLists.txt              # Build configuration
├── README.md                   # Main documentation
├── BUILD.md                    # Build instructions
├── FEATURES.md                 # Feature overview
├── TESTING.md                  # Testing guide
├── STRUCTURE.md                # This file
│
├── setup.sh                    # Auto-setup script (downloads deps + builds)
├── build_with_deps.sh          # Build script
│
├── libx.so                     # Original binary (reference only)
│
├── imgui/                      # ImGui library (downloaded by setup.sh)
│   ├── imgui.h
│   ├── imgui.cpp
│   ├── imgui_demo.cpp
│   ├── imgui_draw.cpp
│   ├── imgui_tables.cpp
│   ├── imgui_widgets.cpp
│   ├── imgui_internal.h
│   └── backends/
│       ├── imgui_impl_opengl3.h/cpp
│       ├── imgui_impl_glfw.h/cpp
│       └── imgui_impl_android.h/cpp
│
├── glfw/                       # GLFW library (downloaded by setup.sh)
│   └── (GLFW source code)
│
├── build/                      # Build output (created by CMake)
│   ├── CheatMenuMockup         # Desktop executable
│   ├── CMakeFiles/
│   └── ...
│
├── build-android/              # Android build output (if building for Android)
│   ├── libnative-lib.so
│   └── ...
│
└── src/                        # Source code
    ├── main_desktop.cpp        # Desktop entry point (GLFW + OpenGL)
    ├── main_android.cpp        # Android entry point (EGL + OpenGL ES)
    │
    └── gui/                    # GUI implementation
        ├── menu.h              # Main menu class declaration
        ├── menu.cpp            # Main menu implementation + styling
        │
        └── tabs/               # Individual tab implementations
            ├── aimbot_tab.h
            ├── aimbot_tab.cpp
            ├── visuals_tab.h
            ├── visuals_tab.cpp
            ├── exploits_tab.h
            ├── exploits_tab.cpp
            ├── skins_tab.h
            ├── skins_tab.cpp
            ├── config_tab.h
            ├── config_tab.cpp
            ├── settings_tab.h
            └── settings_tab.cpp
```

---

## Code Architecture

### High-Level Flow

```
┌─────────────────────────────────────────────────────────┐
│                    Platform Entry                        │
│  ┌────────────────────┐      ┌────────────────────┐    │
│  │  main_desktop.cpp  │      │  main_android.cpp  │    │
│  │                    │      │                    │    │
│  │  • Init GLFW       │      │  • Init EGL        │    │
│  │  • Init OpenGL 3   │      │  • Init GLES3      │    │
│  │  • Init ImGui      │      │  • Init ImGui      │    │
│  │  • Create Window   │      │  • Handle NativeApp│    │
│  └─────────┬──────────┘      └──────────┬─────────┘    │
│            │                            │               │
│            └────────────┬───────────────┘               │
│                         │                               │
└─────────────────────────┼───────────────────────────────┘
                          │
                          ▼
┌─────────────────────────────────────────────────────────┐
│                    Menu System                           │
│  ┌──────────────────────────────────────────────────┐   │
│  │                  CheatMenu Class                  │   │
│  │  ┌────────────────────────────────────────────┐  │   │
│  │  │  • Render()        - Main render loop      │  │   │
│  │  │  • ApplyStyle()    - Theme configuration   │  │   │
│  │  │  • RenderMainWindow() - Tab bar rendering  │  │   │
│  │  └────────────────────────────────────────────┘  │   │
│  └────────────────────────┬─────────────────────────┘   │
│                           │                              │
└───────────────────────────┼──────────────────────────────┘
                            │
                            ▼
┌─────────────────────────────────────────────────────────┐
│                     Tab System                           │
│                                                          │
│  ┌──────────┬──────────┬──────────┬──────────┬────────┐ │
│  │  Aimbot  │ Visuals  │ Exploits │  Skins   │ Config │ │
│  │   Tab    │   Tab    │   Tab    │   Tab    │  Tab   │ │
│  └────┬─────┴────┬─────┴────┬─────┴────┬─────┴────┬───┘ │
│       │          │          │          │          │     │
│       │   ┌──────┴───────┐  │          │          │     │
│       │   │  Settings    │  │          │          │     │
│       │   │     Tab      │  │          │          │     │
│       │   └──────────────┘  │          │          │     │
│       ▼          ▼          ▼          ▼          ▼     │
│  [Sub-tabs] [Sub-tabs] [Sub-tabs] [Editor]  [Manager]  │
│  Main/Set.  Ply/Wpn/   Wpn/Mov/   List+Edit List+CRUD  │
│            Gre/Wld    Bmb/Hst/Prm                       │
│                                                          │
└──────────────────────────────────────────────────────────┘
```

---

## File Dependencies

### Build Files
```
CMakeLists.txt
├── Detects platform (ANDROID vs Desktop)
├── Configures ImGui sources
├── Links platform libraries
│   ├── Desktop: GLFW + OpenGL
│   └── Android: EGL + GLESv3 + android + log
└── Creates output binary
```

### Source Files
```
main_desktop.cpp
├── #include "imgui.h"
├── #include "imgui_impl_glfw.h"
├── #include "imgui_impl_opengl3.h"
├── #include "gui/menu.h"
└── Links: GLFW, OpenGL

main_android.cpp
├── #include "imgui.h"
├── #include "imgui_impl_android.h"
├── #include "imgui_impl_opengl3.h"
├── #include "gui/menu.h"
├── #include <android/log.h>
├── #include <android_native_app_glue.h>
├── #include <EGL/egl.h>
└── #include <GLES3/gl3.h>

menu.cpp
├── #include "menu.h"
├── #include "tabs/aimbot_tab.h"
├── #include "tabs/visuals_tab.h"
├── #include "tabs/exploits_tab.h"
├── #include "tabs/skins_tab.h"
├── #include "tabs/config_tab.h"
└── #include "tabs/settings_tab.h"

Each tab .cpp:
└── #include "imgui.h"
```

---

## Data Flow

### Render Loop

```
┌─────────────────────────────────────────────────────────┐
│                   Frame Rendering                        │
└─────────────────────────────────────────────────────────┘
                            │
                            ▼
                    [ Event Polling ]
                    (Input handling)
                            │
                            ▼
              ┌─────────────────────────┐
              │  ImGui::NewFrame()      │
              └─────────┬───────────────┘
                        │
                        ▼
              ┌─────────────────────────┐
              │  CheatMenu::Render()    │
              └─────────┬───────────────┘
                        │
                        ▼
              ┌─────────────────────────┐
              │  ImGui::Begin("...")    │
              │  + Tab Bar              │
              └─────────┬───────────────┘
                        │
        ┌───────────────┼───────────────┬─── ... ─┐
        ▼               ▼               ▼          ▼
   [Aimbot Tab]   [Visuals Tab]   [Exploits]  [Config]
        │               │               │          │
        │               ▼               │          │
        │      ┌────────────────┐       │          │
        │      │  Sub-tab Bar   │       │          │
        │      └───┬────────┬───┘       │          │
        │          ▼        ▼           │          │
        │      [Players] [Weapons]      │          │
        │                               │          │
        └───────────────┬───────────────┴──────────┘
                        │
                        ▼
              ┌─────────────────────────┐
              │  ImGui::End()           │
              └─────────┬───────────────┘
                        │
                        ▼
              ┌─────────────────────────┐
              │  ImGui::Render()        │
              └─────────┬───────────────┘
                        │
                        ▼
              ┌─────────────────────────┐
              │  ImGui_Impl_*_Render()  │
              │  (Draw to GPU)          │
              └─────────┬───────────────┘
                        │
                        ▼
                   [Swap Buffers]
                        │
                        ▼
                   (Next Frame)
```

---

## State Management

### Menu State
```cpp
CheatMenu {
    bool m_isOpen;          // Menu visibility
    int m_selectedTab;      // Active main tab
    ImVec4 m_accentColor;   // Theme color
}
```

### Tab States (Static within each tab .cpp)

```cpp
// aimbot_tab.cpp
static struct AimbotSettings {
    bool enable;
    bool fovCheck;
    // ... more settings
    
    struct Bones {
        bool head;
        bool neck;
        // ... bone selections
    } bones;
    
    struct Settings {
        int boneFilterDamage;
        float speed;
        // ... advanced settings
    } settings;
} s_aimbotSettings;

// visuals_tab.cpp
static struct VisualsSettings {
    struct Player { ... } player;
    struct Weapons { ... } weapons;
    struct Grenades { ... } grenades;
    struct World { ... } world;
} s_visualsSettings;

// exploits_tab.cpp
static struct ExploitsSettings {
    struct Weapon { ... } weapon;
    struct Movement { ... } movement;
    struct Bomb { ... } bomb;
    struct Host { ... } host;
    struct Premium { ... } premium;
} s_exploitsSettings;

// skins_tab.cpp
static struct SkinsState {
    std::vector<SkinItem> skins;
    int selectedSkin;
    bool editMode;
    SkinItem editingSkin;
    char skinNameBuffer[128];
    // ... editing state
} s_skinsState;

// config_tab.cpp
static struct ConfigState {
    std::vector<ConfigItem> configs;
    int selectedConfig;
    bool showCreateDialog;
    char newConfigName[128];
    std::string statusMessage;
    float statusMessageTime;
} s_configState;

// settings_tab.cpp
static struct SettingsData {
    char userName[128];
    float accentColor[4];
} s_settingsData;
```

**Note**: All state is static and in-memory only. No persistence between runs.

---

## Build Process

### Desktop Build Flow
```
setup.sh
    │
    ├─→ Download imgui-1.90.1.tar.gz
    ├─→ Extract to imgui/
    ├─→ Clone glfw repo
    │
    └─→ mkdir build && cd build
        │
        └─→ cmake ..
            │
            ├─→ Find/Build GLFW
            ├─→ Find OpenGL
            ├─→ Configure ImGui sources
            ├─→ Add desktop backend files
            │
            └─→ make
                │
                ├─→ Compile all .cpp files
                ├─→ Link libraries
                │
                └─→ Output: CheatMenuMockup
```

### Android Build Flow
```
Download imgui → setup NDK environment → cmake with Android toolchain
    │
    ├─→ Set ANDROID=ON
    ├─→ Set ABI to arm64-v8a
    ├─→ Set platform to android-21
    │
    └─→ cmake .. -DCMAKE_TOOLCHAIN_FILE=$NDK/build/cmake/android.toolchain.cmake
        │
        └─→ Configure ImGui sources
            │
            ├─→ Add Android backend files
            ├─→ Link: EGL, GLESv3, android, log
            │
            └─→ make
                │
                └─→ Output: libnative-lib.so
```

---

## Memory Layout (Runtime)

### Approximate Memory Usage

```
┌─────────────────────────────────────────┐
│          Process Memory (~50 MB)        │
├─────────────────────────────────────────┤
│                                         │
│  [ImGui Context]         ~5-10 MB      │
│    • Font atlas                         │
│    • Draw buffers                       │
│    • Window state                       │
│                                         │
│  [Application State]     ~1-2 MB       │
│    • Tab settings structures            │
│    • Skin/config vectors               │
│    • String buffers                     │
│                                         │
│  [OpenGL Buffers]        ~5-10 MB      │
│    • Vertex buffers                     │
│    • Texture buffers                    │
│    • Shader programs                    │
│                                         │
│  [Platform Runtime]      ~20-30 MB     │
│    • GLFW/Android libs                  │
│    • OpenGL/EGL drivers                 │
│    • System libraries                   │
│                                         │
└─────────────────────────────────────────┘
```

---

## Compilation Units

### Desktop Build
```
Source files compiled:
1. src/main_desktop.cpp
2. src/gui/menu.cpp
3. src/gui/tabs/aimbot_tab.cpp
4. src/gui/tabs/visuals_tab.cpp
5. src/gui/tabs/exploits_tab.cpp
6. src/gui/tabs/skins_tab.cpp
7. src/gui/tabs/config_tab.cpp
8. src/gui/tabs/settings_tab.cpp
9. imgui/imgui.cpp
10. imgui/imgui_demo.cpp
11. imgui/imgui_draw.cpp
12. imgui/imgui_tables.cpp
13. imgui/imgui_widgets.cpp
14. imgui/backends/imgui_impl_opengl3.cpp
15. imgui/backends/imgui_impl_glfw.cpp

Total: 15 compilation units
```

### Android Build
```
Source files compiled:
1. src/main_android.cpp
2-8. (same gui files as desktop)
9-13. (same imgui core files)
14. imgui/backends/imgui_impl_opengl3.cpp
15. imgui/backends/imgui_impl_android.cpp

Total: 15 compilation units
```

---

## Performance Characteristics

### CPU Usage
- **Idle**: ~1-2% (just rendering static UI)
- **Active**: ~3-5% (user interacting with sliders/buttons)
- **Peak**: ~10% (rapid tab switching, multiple animations)

### GPU Usage
- **Minimal**: ImGui is 2D only, very light on GPU
- **~1-5%** on modern GPUs
- **Vertex count**: ~1000-5000 per frame (depends on visible UI)
- **Draw calls**: ~10-50 per frame

### Memory Access Patterns
- **Static state**: All tab settings are static variables (fast access)
- **ImGui state**: Managed internally by ImGui (optimized)
- **No dynamic allocation** during rendering (stable performance)
- **Small vector resizes** only when adding skins/configs

---

## Threading Model

### Desktop
```
┌─────────────────────────────────┐
│        Main Thread              │
│  ┌──────────────────────────┐   │
│  │  Event Loop              │   │
│  │  ├─ Poll Events (GLFW)   │   │
│  │  ├─ ImGui Update         │   │
│  │  ├─ Render UI            │   │
│  │  └─ Swap Buffers         │   │
│  └──────────────────────────┘   │
└─────────────────────────────────┘

Single-threaded, simple event loop
```

### Android
```
┌─────────────────────────────────┐
│     Android Main Thread         │
│  ┌──────────────────────────┐   │
│  │  NativeActivity Glue     │   │
│  │  ├─ Input Events         │   │
│  │  ├─ Lifecycle Events     │   │
│  │  └─ Window Events        │   │
│  └──────────┬───────────────┘   │
└─────────────┼───────────────────┘
              │
              ▼
┌─────────────────────────────────┐
│      App Main Loop              │
│  ┌──────────────────────────┐   │
│  │  Event Loop              │   │
│  │  ├─ Poll Looper          │   │
│  │  ├─ ImGui Update         │   │
│  │  ├─ Render UI            │   │
│  │  └─ EGL Swap             │   │
│  └──────────────────────────┘   │
└─────────────────────────────────┘

Also single-threaded with event processing
```

---

## Extension Points

Want to add more features? Here's where to add them:

### New Tab
1. Create `src/gui/tabs/newtab_tab.h` and `.cpp`
2. Add header in `menu.cpp`
3. Add `Tabs::RenderNewTab()` function
4. Add tab bar item in `CheatMenu::RenderMainWindow()`
5. Update CMakeLists.txt to compile new files

### New Setting in Existing Tab
1. Add variable to relevant tab's state struct
2. Add ImGui widget in tab's render function
3. Done! (no other changes needed)

### New Sub-tab
1. Add `ImGui::BeginTabBar()` if not present
2. Add `ImGui::BeginTabItem("Name")`
3. Add content
4. Add `ImGui::EndTabItem()`

### Custom Widget
1. Create widget in tab .cpp or separate file
2. Call widget function from tab render function
3. ImGui provides: Button, Checkbox, Slider, InputText, ColorEdit, etc.
4. Can combine primitives for custom layouts

---

## Platform Differences

| Feature | Desktop | Android |
|---------|---------|---------|
| Window management | GLFW | EGL/NativeActivity |
| OpenGL version | 3.0+ | ES 3.0+ |
| Input handling | GLFW callbacks | AInputEvent |
| Build output | Executable | Shared library (.so) |
| Packaging | None (raw binary) | APK |
| Touch support | Mouse only | Touch events |
| File paths | Absolute paths | Android storage |
| Exit method | Close window | Back button/kill |

---

## Future Considerations

If you want to make this more than a mockup:

### Persistence
- Add JSON serialization for all settings
- Save to file on exit, load on start
- Config files could be real .json files

### Functionality
- Hook into actual game process (requires game-specific code)
- Implement memory reading/writing
- Add network communication
- Implement actual cheat features (not recommended!)

### UI Improvements
- Add animations (ImGui supports custom animation)
- Add icons (requires icon font or textures)
- Add more themes
- Add keybind configuration
- Add search/filter in lists

### Quality of Life
- Add tooltips on hover
- Add confirmation dialogs for destructive actions
- Add undo/redo for editing
- Add drag-and-drop for reordering
- Add copy/paste between configs
