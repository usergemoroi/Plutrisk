#!/bin/bash
set -e

echo "================================================"
echo "  Cheat Menu Mockup - Setup Script"
echo "================================================"
echo ""

# Check for required tools
command -v cmake >/dev/null 2>&1 || { echo "Error: cmake is required but not installed."; exit 1; }
command -v wget >/dev/null 2>&1 || command -v curl >/dev/null 2>&1 || { echo "Error: wget or curl is required but not installed."; exit 1; }

# Download ImGui
if [ ! -d "imgui" ]; then
    echo "[1/3] Downloading ImGui v1.90.1..."
    if command -v wget >/dev/null 2>&1; then
        wget -q --show-progress https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz -O imgui.tar.gz
    else
        curl -L https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.tar.gz -o imgui.tar.gz
    fi
    tar xzf imgui.tar.gz
    mv imgui-1.90.1 imgui
    rm imgui.tar.gz
    echo "✓ ImGui downloaded"
else
    echo "[1/3] ImGui already exists, skipping..."
fi

# Download GLFW for desktop build
if [ ! -d "glfw" ]; then
    echo "[2/3] Downloading GLFW..."
    git clone --quiet --depth 1 https://github.com/glfw/glfw.git
    echo "✓ GLFW downloaded"
else
    echo "[2/3] GLFW already exists, skipping..."
fi

# Build desktop version
echo "[3/3] Building desktop version..."
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 2)
cd ..

echo ""
echo "================================================"
echo "  Setup Complete!"
echo "================================================"
echo ""
echo "To run the mockup:"
echo "  ./build/CheatMenuMockup"
echo ""
echo "For Android build, see README.md"
echo ""
