# Cheat Menu GUI Mockup

A complete ImGui-based mockup of a cheat menu interface extracted from the original binary. This is a **visual-only implementation** with no functional cheating code - all UI elements are present but dummy.

## Features

Complete implementation of all 6 main tabs:

### 1. **Aimbot Tab**
- Main Settings: Enable, FOV Check, Draw FOV, Fire Check, Auto Fire, Untouchable Check, Silent
- Target Bones: Head, Neck, Stomach, Hands, Legs, Foots
- Advanced Settings: Bone Filter (Damage, Angle), Speed, Hit Chance, FOV

### 2. **Visuals Tab**
- **Players**: Box, Fill, Health Bar, Health Amount, Name, Weapon Icon, Traces, Skeleton, Chams
- **Weapons**: Name, Ammo display
- **Grenades**: Circle, Timer
- **World**: Bullet Tracer, Scene Color, Fog settings, Sky customization

### 3. **Exploits Tab**
- **Weapon**: Fire Rate, Infinity Ammo
- **Movement**: Air Jump, Move Before Timer
- **Bomb**: Get Bomb, Auto Win, Fast Plant, Plant/Defuse/Explode buttons
- **Host**: Auto Win, Fast Defuse/Detonate, Crash Host, Destroy Enemies/Teammates
- **Premium**: TPV, Invisible, Chat Spam, Auto Kill, Fast Strafe, Freeze Kill, Crash options

### 4. **Skins Tab**
- Add/Edit/Delete weapon skins
- Configure: Weapon Type, Skin Name, Pattern, StatTrak™, Rarity
- List view of all configured skins

### 5. **Config Tab**
- Create, Load, Save, Delete configurations
- Metadata tracking (Created By, Created At)
- Status messages for all operations

### 6. **Settings Tab**
- User Name configuration
- Accent Color picker
- Menu information and about section

## Building

### Prerequisites

#### Desktop (Linux/macOS/Windows)
- CMake 3.10+
- C++17 compatible compiler
- OpenGL
- GLFW3 (will be downloaded if not found)

#### Android
- Android NDK r21+
- CMake 3.10+
- Android SDK with platform-tools

### Desktop Build

First, download ImGui and GLFW:

```bash
# Download ImGui
wget https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz
tar xzf v1.90.1.tar.gz
mv imgui-1.90.1 imgui

# Download GLFW (optional, will be built if not found)
git clone https://github.com/glfw/glfw.git

# Build
mkdir build && cd build
cmake ..
make
./CheatMenuMockup
```

### Android Build

1. Set up environment variables:
```bash
export ANDROID_NDK=/path/to/android-ndk
export ANDROID_SDK=/path/to/android-sdk
```

2. Download ImGui:
```bash
wget https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz
tar xzf v1.90.1.tar.gz
mv imgui-1.90.1 imgui
```

3. Create Android project structure and build with Gradle (requires Android Studio project setup) or use CMake directly:

```bash
mkdir build-android && cd build-android
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
    -DANDROID_ABI=arm64-v8a \
    -DANDROID_PLATFORM=android-21 \
    -DANDROID=ON
make
```

## Project Structure

```
.
├── CMakeLists.txt           # Build configuration
├── imgui/                   # ImGui library (not included)
├── glfw/                    # GLFW library (optional, not included)
├── src/
│   ├── main_desktop.cpp     # Desktop entry point
│   ├── main_android.cpp     # Android entry point
│   └── gui/
│       ├── menu.h/cpp       # Main menu window and styling
│       └── tabs/
│           ├── aimbot_tab.h/cpp
│           ├── visuals_tab.h/cpp
│           ├── exploits_tab.h/cpp
│           ├── skins_tab.h/cpp
│           ├── config_tab.h/cpp
│           └── settings_tab.h/cpp
├── libx.so                  # Original binary (reference only)
└── README.md
```

## Quick Setup Script

Save this as `setup.sh`:

```bash
#!/bin/bash
set -e

echo "Setting up ImGui Mockup project..."

# Download ImGui
if [ ! -d "imgui" ]; then
    echo "Downloading ImGui..."
    wget -q https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz
    tar xzf v1.90.1.tar.gz
    mv imgui-1.90.1 imgui
    rm v1.90.1.tar.gz
fi

# Download GLFW for desktop build
if [ ! -d "glfw" ]; then
    echo "Downloading GLFW..."
    git clone --depth 1 https://github.com/glfw/glfw.git
fi

# Build desktop version
echo "Building desktop version..."
mkdir -p build
cd build
cmake ..
make -j$(nproc)

echo "Done! Run: ./build/CheatMenuMockup"
```

Then run:
```bash
chmod +x setup.sh
./setup.sh
```

## UI Theme

The mockup features a dark theme with:
- Deep blue-gray backgrounds
- Cyan/blue accent colors (customizable)
- Smooth animations and transitions
- Modern rounded corners and spacing

## Notes

- All functionality is **dummy/placeholder** - no actual game interaction
- Perfect for UI/UX testing and design iteration
- Cross-platform: works on Desktop and Android
- Menu structure extracted from original binary strings
- Uses ImGui v1.90.1+ (latest stable)

## Controls

- **Desktop**: Mouse and keyboard
- **Android**: Touch input
- **Toggle Menu**: Click X or use Close button

## License

This is a mockup/demonstration project. The original binary is not included in functionality, only the UI structure was analyzed for accurate recreation.
