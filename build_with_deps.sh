#!/bin/bash
set -e

echo "================================================"
echo "  Building Cheat Menu Mockup with Dependencies"
echo "================================================"

# Run setup first
if [ ! -d "imgui" ] || [ ! -d "glfw" ]; then
    echo "Running setup to download dependencies..."
    ./setup.sh
else
    echo "Dependencies already present, building..."
    mkdir -p build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Release
    make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 2)
    cd ..
    
    echo ""
    echo "================================================"
    echo "  Build Complete!"
    echo "================================================"
    echo ""
    echo "Run: ./build/CheatMenuMockup"
    echo ""
fi
