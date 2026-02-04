# Quick Start Guide

Get the ImGui cheat menu mockup running in 5 minutes!

## Prerequisites Check

```bash
# Check if you have the basics
cmake --version   # Need 3.10+
gcc --version     # Or clang/MSVC
```

If missing, install:
- **Ubuntu/Debian**: `sudo apt install cmake build-essential`
- **macOS**: `brew install cmake` (after installing Xcode tools)
- **Windows**: Install Visual Studio + CMake

## One-Command Build & Run

### Linux/macOS

```bash
./setup.sh && ./build/CheatMenuMockup
```

That's it! The setup script will:
1. Download ImGui v1.90.1
2. Download GLFW
3. Build the project
4. Leave you with a ready-to-run executable

### Windows

```cmd
REM Install dependencies first (manual)
REM Then build:
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
cd ..
build\Release\CheatMenuMockup.exe
```

## What You'll See

A window will open with a dark-themed menu containing 6 tabs:

1. **Aimbot** - Targeting settings with bone selection
2. **Visuals** - ESP settings for players, weapons, grenades, world
3. **Exploits** - Game modification options (weapon, movement, bomb, host, premium)
4. **Skins** - Weapon skin editor with add/edit/delete
5. **Config** - Configuration manager
6. **Settings** - User preferences and accent color

## Try These Actions

### In Aimbot Tab
- Toggle "Enable" checkbox
- Move the "FOV" slider
- Select different target bones

### In Visuals Tab
- Go to "Players" sub-tab
- Enable "Box" and "Name"
- Try the "Chams Type" dropdown

### In Exploits Tab
- Check out "Premium" sub-tab
- Notice the color-coded warnings
- Click the dangerous red buttons (they're safe, just UI!)

### In Skins Tab
- Click "Add Skin"
- Choose weapon type
- Enter a skin name
- Set pattern and rarity
- Click "Apply"

### In Config Tab
- Click "Create New Config"
- Enter a name
- See it appear in the list
- Try Load/Save/Delete

### In Settings Tab
- Change your username
- Click the accent color box
- Pick a new color
- Watch the theme update!

## Controls

- **Mouse**: Click and drag everything
- **Scroll**: In lists and child windows
- **Tab**: Navigate between inputs
- **ESC**: Close dialogs
- **X button**: Close menu (exits app)

## Troubleshooting

### "Command not found: cmake"
Install CMake first (see Prerequisites above)

### "GLFW not found" 
The setup script downloads it automatically. If building manually, install with:
- Ubuntu: `sudo apt install libglfw3-dev`
- macOS: `brew install glfw`

### "OpenGL not found" (Linux)
```bash
sudo apt install libgl1-mesa-dev
```

### Build fails with compiler errors
Make sure you have a C++17-compatible compiler:
- GCC 7+
- Clang 5+
- MSVC 2017+

### Window is black/blank
Check OpenGL support:
```bash
glxinfo | grep "OpenGL version"  # Should be 3.0+
```

### Window doesn't appear
Check terminal for error messages. Ensure you're running from the project directory.

## Next Steps

- **Read FEATURES.md** - See complete menu structure
- **Read TESTING.md** - Full testing checklist
- **Read BUILD.md** - Detailed build instructions
- **Read STRUCTURE.md** - Code architecture details

## Customization

Want to modify the UI? Edit these files:

- `src/gui/menu.cpp` - Main window and styling
- `src/gui/tabs/*_tab.cpp` - Individual tab content
- Change colors in `CheatMenu::ApplyStyle()` function

## Performance

Expected performance on modern hardware:
- **Desktop**: 60 FPS, 2-5% CPU, < 50 MB RAM
- **Android**: 60 FPS, 5-8% CPU, < 40 MB RAM

## Building for Android

Requires Android NDK. See **BUILD.md** for complete instructions.

Quick version:
```bash
export ANDROID_NDK=/path/to/ndk
mkdir build-android && cd build-android
cmake .. -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
         -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-21 -DANDROID=ON
make
```

## Clean Up

To remove build artifacts:
```bash
rm -rf build/ build-android/ imgui/ glfw/
```

To rebuild from scratch:
```bash
rm -rf build/ imgui/ glfw/
./setup.sh
```

## Getting Help

1. **Build problems?** → BUILD.md
2. **Feature questions?** → FEATURES.md  
3. **Testing issues?** → TESTING.md
4. **Code questions?** → STRUCTURE.md
5. **General overview?** → README.md

## Common Issues

### Issue: "setup.sh: Permission denied"
**Fix**: `chmod +x setup.sh`

### Issue: Build works but window is tiny on 4K display
**Fix**: This is normal. ImGui uses pixel sizes. You can resize the window.

### Issue: Can't see accent color changes
**Fix**: Color only affects certain UI elements (checkmarks, sliders, buttons on hover). Try checking a checkbox or hovering over a button.

### Issue: Tabs don't switch
**Fix**: Click directly on the tab name at the top. Make sure the window has focus.

### Issue: Sliders are hard to grab
**Fix**: Click and drag from the colored grab handle (circle/square on the slider).

## Demo Workflow

For a quick demo, try this sequence:

1. Open menu (should auto-open)
2. Aimbot → Enable → Select Head bone
3. Visuals → Players → Enable Box, Name, Health Bar
4. Exploits → Premium → Enable TPV
5. Skins → Add Skin → Create "AK-47 | Fire Serpent"
6. Config → Create New → Save your settings
7. Settings → Change accent color to red
8. See your red-themed menu!

## Screenshots

*(If you add screenshots, place them in a `docs/images/` folder)*

The menu looks like:
- Dark blue-gray theme
- Cyan accent color (customizable)
- Rounded corners everywhere
- Clean, modern UI
- 6 main tabs at top
- Sub-tabs where applicable
- Smooth interactions

## Video Demo

To record a demo:
```bash
# Linux with ffmpeg
ffmpeg -video_size 1280x720 -framerate 30 -f x11grab -i :0.0 demo.mp4

# Then run the app and interact with it
./build/CheatMenuMockup

# Press Ctrl+C in ffmpeg terminal when done
```

## Contributing

This is a mockup/demo project. To extend it:

1. Add new tabs: Copy existing tab files, modify, add to menu.cpp
2. Add new settings: Add variables to tab's static struct
3. Add new features: Use ImGui widgets (see imgui_demo.cpp)

## Credits

- ImGui by Omar Cornut
- GLFW by Camilla Löwy
- Menu structure from binary analysis

## License

This project is for educational/demonstration purposes.

---

**That's it! You're ready to explore the mockup.**

For questions or issues, check the other documentation files.

Happy exploring! 🚀
