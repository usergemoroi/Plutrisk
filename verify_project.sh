#!/bin/bash

echo "================================================"
echo "  Project Verification Script"
echo "================================================"
echo ""

ERRORS=0
WARNINGS=0

# Check for required files
echo "[1/5] Checking required files..."

REQUIRED_FILES=(
    "CMakeLists.txt"
    "README.md"
    "BUILD.md"
    "FEATURES.md"
    "TESTING.md"
    "STRUCTURE.md"
    "PROJECT_SUMMARY.md"
    ".gitignore"
    "setup.sh"
    "build_with_deps.sh"
    "src/main_desktop.cpp"
    "src/main_android.cpp"
    "src/gui/menu.h"
    "src/gui/menu.cpp"
    "src/gui/tabs/aimbot_tab.h"
    "src/gui/tabs/aimbot_tab.cpp"
    "src/gui/tabs/visuals_tab.h"
    "src/gui/tabs/visuals_tab.cpp"
    "src/gui/tabs/exploits_tab.h"
    "src/gui/tabs/exploits_tab.cpp"
    "src/gui/tabs/skins_tab.h"
    "src/gui/tabs/skins_tab.cpp"
    "src/gui/tabs/config_tab.h"
    "src/gui/tabs/config_tab.cpp"
    "src/gui/tabs/settings_tab.h"
    "src/gui/tabs/settings_tab.cpp"
)

for file in "${REQUIRED_FILES[@]}"; do
    if [ ! -f "$file" ]; then
        echo "  ✗ Missing: $file"
        ERRORS=$((ERRORS + 1))
    fi
done

if [ $ERRORS -eq 0 ]; then
    echo "  ✓ All required files present (${#REQUIRED_FILES[@]} files)"
fi

echo ""
echo "[2/5] Checking file permissions..."

EXEC_FILES=("setup.sh" "build_with_deps.sh")
for file in "${EXEC_FILES[@]}"; do
    if [ ! -x "$file" ]; then
        echo "  ✗ Not executable: $file"
        ERRORS=$((ERRORS + 1))
    fi
done

if [ $ERRORS -eq 0 ]; then
    echo "  ✓ All scripts are executable"
fi

echo ""
echo "[3/5] Checking code structure..."

# Check for includes
if ! grep -q "#include \"gui/menu.h\"" src/main_desktop.cpp; then
    echo "  ✗ main_desktop.cpp doesn't include gui/menu.h"
    ERRORS=$((ERRORS + 1))
fi

if ! grep -q "#include \"gui/menu.h\"" src/main_android.cpp; then
    echo "  ✗ main_android.cpp doesn't include gui/menu.h"
    ERRORS=$((ERRORS + 1))
fi

# Check for tab includes in menu.cpp
TABS=("aimbot" "visuals" "exploits" "skins" "config" "settings")
for tab in "${TABS[@]}"; do
    if ! grep -q "#include \"tabs/${tab}_tab.h\"" src/gui/menu.cpp; then
        echo "  ✗ menu.cpp doesn't include ${tab}_tab.h"
        ERRORS=$((ERRORS + 1))
    fi
done

if [ $ERRORS -eq 0 ]; then
    echo "  ✓ Code structure is correct"
fi

echo ""
echo "[4/5] Checking documentation..."

# Check if README has basic sections
if grep -q "## Features" README.md && grep -q "## Building" README.md; then
    echo "  ✓ README.md has required sections"
else
    echo "  ✗ README.md missing required sections"
    WARNINGS=$((WARNINGS + 1))
fi

# Check documentation word count
DOC_FILES=("README.md" "BUILD.md" "FEATURES.md" "TESTING.md" "STRUCTURE.md" "PROJECT_SUMMARY.md")
TOTAL_WORDS=0
for doc in "${DOC_FILES[@]}"; do
    if [ -f "$doc" ]; then
        WORDS=$(wc -w < "$doc")
        TOTAL_WORDS=$((TOTAL_WORDS + WORDS))
    fi
done

echo "  ✓ Total documentation: ~$TOTAL_WORDS words"

echo ""
echo "[5/5] Checking for dependencies availability..."

# Check if cmake is available
if command -v cmake >/dev/null 2>&1; then
    CMAKE_VERSION=$(cmake --version | head -n1)
    echo "  ✓ CMake found: $CMAKE_VERSION"
else
    echo "  ✗ CMake not found (required for building)"
    WARNINGS=$((WARNINGS + 1))
fi

# Check if wget or curl is available
if command -v wget >/dev/null 2>&1; then
    echo "  ✓ wget found (for downloading dependencies)"
elif command -v curl >/dev/null 2>&1; then
    echo "  ✓ curl found (for downloading dependencies)"
else
    echo "  ✗ Neither wget nor curl found (needed by setup.sh)"
    WARNINGS=$((WARNINGS + 1))
fi

# Check if git is available
if command -v git >/dev/null 2>&1; then
    echo "  ✓ git found"
else
    echo "  ! git not found (optional, only needed for GLFW download)"
fi

echo ""
echo "================================================"
echo "  Verification Complete"
echo "================================================"

if [ $ERRORS -eq 0 ] && [ $WARNINGS -eq 0 ]; then
    echo "✓ All checks passed!"
    echo ""
    echo "Project is ready to build. Run:"
    echo "  ./setup.sh"
    echo ""
    exit 0
elif [ $ERRORS -eq 0 ]; then
    echo "✓ No errors found"
    echo "⚠ $WARNINGS warnings (non-critical)"
    echo ""
    echo "Project is ready to build. Run:"
    echo "  ./setup.sh"
    echo ""
    exit 0
else
    echo "✗ Found $ERRORS errors and $WARNINGS warnings"
    echo ""
    echo "Please fix errors before building."
    echo ""
    exit 1
fi
