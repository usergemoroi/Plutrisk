# Build Instructions

This document provides detailed build instructions for all platforms.

## Table of Contents
- [Prerequisites](#prerequisites)
- [Quick Start (Desktop)](#quick-start-desktop)
- [Manual Build (Desktop)](#manual-build-desktop)
- [Android Build](#android-build)
- [Troubleshooting](#troubleshooting)

---

## Prerequisites

### All Platforms
- CMake 3.10 or higher
- Git
- C++17 compatible compiler

### Desktop (Linux)
```bash
# Ubuntu/Debian
sudo apt-get install build-essential cmake git libgl1-mesa-dev libx11-dev libxrandr-dev libxi-dev libxinerama-dev libxcursor-dev

# Fedora
sudo dnf install gcc-c++ cmake git mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXinerama-devel libXcursor-devel

# Arch Linux
sudo pacman -S base-devel cmake git mesa libx11 libxrandr libxi libxinerama libxcursor
```

### Desktop (macOS)
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Install Homebrew (if not already installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install CMake
brew install cmake
```

### Desktop (Windows)
1. Install [Visual Studio 2019+](https://visualstudio.microsoft.com/) with C++ Desktop Development
2. Install [CMake](https://cmake.org/download/)
3. Install [Git](https://git-scm.com/download/win)

### Android
- [Android NDK r21+](https://developer.android.com/ndk/downloads)
- [Android Studio](https://developer.android.com/studio) (recommended) or Android SDK
- CMake (usually included with Android Studio)

---

## Quick Start (Desktop)

The easiest way to build and run on desktop:

```bash
./setup.sh
```

This will:
1. Download ImGui v1.90.1
2. Download GLFW
3. Build the project
4. Create executable in `build/CheatMenuMockup`

Run the mockup:
```bash
./build/CheatMenuMockup
```

---

## Manual Build (Desktop)

### Step 1: Download Dependencies

#### Download ImGui
```bash
wget https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz
tar xzf v1.90.1.tar.gz
mv imgui-1.90.1 imgui
rm v1.90.1.tar.gz
```

#### Download GLFW (optional - CMake will build it if not found)
```bash
git clone --depth 1 https://github.com/glfw/glfw.git
```

### Step 2: Build

#### Linux/macOS
```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
cd ..
```

#### Windows (Visual Studio)
```cmd
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A x64
cmake --build . --config Release
cd ..
```

#### Windows (MinGW)
```cmd
mkdir build
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
mingw32-make -j4
cd ..
```

### Step 3: Run

#### Linux/macOS
```bash
./build/CheatMenuMockup
```

#### Windows
```cmd
build\Release\CheatMenuMockup.exe
```

---

## Android Build

### Method 1: Using Android Studio (Recommended)

1. **Create Android Studio Project Structure**:
```bash
mkdir -p android/app/src/main/jniLibs/arm64-v8a
mkdir -p android/app/src/main/java/com/example/cheatmenu
```

2. **Download ImGui**:
```bash
wget https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz
tar xzf v1.90.1.tar.gz
mv imgui-1.90.1 imgui
```

3. **Create Android Manifest** (`android/app/src/main/AndroidManifest.xml`):
```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="com.example.cheatmenu">
    
    <application
        android:label="Cheat Menu"
        android:hasCode="false">
        <activity
            android:name="android.app.NativeActivity"
            android:label="Cheat Menu"
            android:configChanges="orientation|keyboardHidden">
            <meta-data
                android:name="android.app.lib_name"
                android:value="native-lib" />
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />
                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>
</manifest>
```

4. **Create build.gradle** (`android/app/build.gradle`):
```gradle
apply plugin: 'com.android.application'

android {
    compileSdkVersion 30
    
    defaultConfig {
        applicationId "com.example.cheatmenu"
        minSdkVersion 21
        targetSdkVersion 30
        versionCode 1
        versionName "1.0"
        
        externalNativeBuild {
            cmake {
                arguments "-DANDROID=ON"
                cppFlags "-std=c++17"
            }
        }
        
        ndk {
            abiFilters 'arm64-v8a'
        }
    }
    
    externalNativeBuild {
        cmake {
            path "../../CMakeLists.txt"
        }
    }
    
    buildTypes {
        release {
            minifyEnabled false
        }
    }
}
```

5. **Build with Android Studio**:
   - Open the `android` folder as a project
   - Build > Make Project
   - Run on device/emulator

### Method 2: Command Line Build

```bash
# Set environment variables
export ANDROID_NDK=/path/to/android-ndk
export ANDROID_SDK=/path/to/android-sdk

# Download ImGui
wget https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz
tar xzf v1.90.1.tar.gz
mv imgui-1.90.1 imgui

# Build native library
mkdir build-android
cd build-android

cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
    -DANDROID_ABI=arm64-v8a \
    -DANDROID_PLATFORM=android-21 \
    -DCMAKE_BUILD_TYPE=Release \
    -DANDROID=ON

make -j$(nproc)
cd ..

# The compiled library will be in build-android/libnative-lib.so
```

---

## Troubleshooting

### Desktop Build Issues

#### "Could not find GLFW"
The CMakeLists.txt will automatically build GLFW from source if not found. If you still encounter issues:
```bash
# Install GLFW system-wide
# Ubuntu/Debian
sudo apt-get install libglfw3-dev

# macOS
brew install glfw

# Or download and build manually
git clone https://github.com/glfw/glfw.git
```

#### "OpenGL not found" (Linux)
```bash
# Ubuntu/Debian
sudo apt-get install libgl1-mesa-dev

# Fedora
sudo dnf install mesa-libGL-devel
```

#### ImGui Files Not Found
Ensure ImGui is in the correct location:
```bash
ls imgui/imgui.h  # Should exist
```

If not, download it:
```bash
wget https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz
tar xzf v1.90.1.tar.gz
mv imgui-1.90.1 imgui
```

### Android Build Issues

#### "NDK not found"
Set the NDK path:
```bash
export ANDROID_NDK=/path/to/android-ndk
```

#### "Platform not supported"
Ensure you're targeting at least Android API 21:
```bash
-DANDROID_PLATFORM=android-21
```

#### "EGL/GLES3 not found"
These are included with the NDK. Ensure you're using a recent NDK version (r21+).

### Runtime Issues

#### Window doesn't appear (Desktop)
Check if OpenGL is working:
```bash
glxinfo | grep "OpenGL version"  # Linux
```

#### Black screen (Desktop)
The menu should appear immediately. Check console for errors.

#### Crash on Android
Check logcat:
```bash
adb logcat | grep CheatMenuMockup
```

---

## Additional Resources

- [ImGui Documentation](https://github.com/ocornut/imgui)
- [GLFW Documentation](https://www.glfw.org/documentation.html)
- [Android NDK Guide](https://developer.android.com/ndk/guides)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

---

## Build Verification

After building successfully, you should see:

**Desktop**:
- Executable: `build/CheatMenuMockup` (Linux/macOS) or `build/Release/CheatMenuMockup.exe` (Windows)
- Size: ~2-5 MB

**Android**:
- Native library: `build-android/libnative-lib.so`
- Size: ~1-3 MB
- Architecture: arm64-v8a (AArch64)

Run the application and verify:
1. Menu window appears
2. All 6 tabs are visible (Aimbot, Visuals, Exploits, Skins, Config, Settings)
3. Can switch between tabs
4. UI elements are responsive
5. No crashes or errors
