# Testing Guide

This document describes how to test and verify the GUI mockup.

## Quick Verification Checklist

After building and running, verify these items:

### ✓ Window Launch
- [ ] Application window opens without errors
- [ ] Window title shows "Cheat Menu Mockup" (Desktop) or "Cheat Menu" (Android)
- [ ] Window is resizable (Desktop only)
- [ ] Default size is approximately 800x600

### ✓ Main Tabs Visible
- [ ] Six main tabs appear at the top: Aimbot, Visuals, Exploits, Skins, Config, Settings
- [ ] Tabs are clickable and switch properly
- [ ] Active tab is highlighted with accent color
- [ ] Tab text is readable

---

## Tab-by-Tab Testing

### 1. Aimbot Tab

#### Sub-tabs
- [ ] Two sub-tabs: "Main" and "Settings"
- [ ] Can switch between sub-tabs

#### Main Sub-tab
- [ ] 7 checkboxes visible: Enable, FOV Check, Draw FOV, Fire Check, Auto Fire, Untouchable Check, Silent
- [ ] All checkboxes are toggleable
- [ ] "Target Bones" section header visible
- [ ] 6 bone checkboxes: Head, Neck, Stomach, Hands, Legs, Foots
- [ ] All bone checkboxes are toggleable

#### Settings Sub-tab
- [ ] "Bone Filter" section visible
- [ ] Damage slider (0-100) functional
- [ ] Angle slider (0-180) functional
- [ ] "Advanced" section visible
- [ ] Speed slider (0.1-10.0) functional
- [ ] Hit Chance slider (0.0-1.0) functional
- [ ] FOV slider (1.0-180.0) functional
- [ ] All sliders show current value

---

### 2. Visuals Tab

#### Sub-tabs
- [ ] Four sub-tabs: "Players", "Weapons", "Grenades", "World"
- [ ] Can switch between all sub-tabs

#### Players Sub-tab
- [ ] "Player ESP" section visible
- [ ] 9 checkboxes: Enable, Box, Fill, Health Bar, Health Amount, Name, Weapon Icon, Traces, Skeleton
- [ ] Thickness slider (0.5-5.0) functional
- [ ] Rounding slider (0.0-12.0) functional
- [ ] "Chams" section visible
- [ ] Enable Chams checkbox
- [ ] Chams Type combo box with 4 options: Normal, Flat, Wireframe, Glow
- [ ] Combo box is clickable and shows dropdown

#### Weapons Sub-tab
- [ ] "Weapon ESP" section visible
- [ ] 3 checkboxes: Enable, Name, Ammo
- [ ] All checkboxes toggleable

#### Grenades Sub-tab
- [ ] "Grenade ESP" section visible
- [ ] 3 checkboxes: Enable, Circle, Timer
- [ ] All checkboxes toggleable

#### World Sub-tab
- [ ] "World Visuals" section visible
- [ ] Bullet Tracer and Scene Color checkboxes
- [ ] "Fog" section visible
- [ ] Enable Fog checkbox
- [ ] Fog Start slider (0-5000)
- [ ] Fog End slider (0-10000)
- [ ] "Sky" section visible
- [ ] Custom SkyBox checkbox
- [ ] Atmosphere Thickness slider (0.0-5.0)
- [ ] Exposure slider (0.0-5.0)
- [ ] Sun Size slider (0.0-10.0)
- [ ] Sun Quality slider (0-4)

---

### 3. Exploits Tab

#### Sub-tabs
- [ ] Five sub-tabs: "Weapon", "Movement", "Bomb", "Host", "Premium"
- [ ] Can switch between all sub-tabs

#### Weapon Sub-tab
- [ ] "Weapon Modifications" section visible
- [ ] Fire Rate slider (0.1-10.0)
- [ ] Infinity Ammo checkbox

#### Movement Sub-tab
- [ ] "Movement Exploits" section visible
- [ ] Air Jump checkbox
- [ ] Move Before Timer checkbox

#### Bomb Sub-tab
- [ ] "Bomb Exploits" section visible
- [ ] Get Bomb checkbox
- [ ] Auto Win checkbox
- [ ] Fast Plant checkbox
- [ ] Three buttons: "Plant Bomb", "Defuse Bomb", "Explode Bomb"
- [ ] All buttons are clickable (200x30px)

#### Host Sub-tab
- [ ] Orange warning text: "Warning: You are not the host!"
- [ ] Info text about host exploits
- [ ] "Host Exploits" section visible
- [ ] Auto Win, Fast Defuse, Fast Detonate checkboxes
- [ ] "Dangerous" section visible
- [ ] Three RED buttons: "Crash Host", "Destroy Enemies", "Destroy Teammates"
- [ ] Buttons have red color (distinguishable from normal buttons)

#### Premium Sub-tab
- [ ] Gold/yellow title: "Premium Features"
- [ ] 6 checkboxes: TPV, Invisible, Chat Spam, Auto Kill, Fast Strafe, Freeze Kill
- [ ] "Crash" section visible
- [ ] 2 RED checkboxes: Crash Enemies, Crash Teammates
- [ ] Red styling visible on dangerous options

---

### 4. Skins Tab

#### Layout
- [ ] Split view: Left panel (list) and Right panel (editor)
- [ ] Left panel has border/background
- [ ] Right panel has border/background

#### Left Panel (List)
- [ ] "Skins List" header visible
- [ ] Separator line below header
- [ ] "Add Skin" button at bottom
- [ ] Button spans full width (-1 width)
- [ ] Button is 30px tall

#### Right Panel (Editor)
- [ ] Initially shows "Select a skin or add a new one" message
- [ ] Message is gray/dimmed color

#### After clicking "Add Skin"
- [ ] "Skin Editor" header appears in right panel
- [ ] Weapon Type combo box with 24 weapons
- [ ] Can select different weapon types
- [ ] Skin Name text input field
- [ ] Pattern slider (0-999)
- [ ] StatTrak™ checkbox
- [ ] Rarity combo box with 7 options
- [ ] "Apply" button (100x30)
- [ ] "Back" button (100x30)

#### After creating a skin
- [ ] Skin appears in left panel list
- [ ] Skin name is visible and selectable
- [ ] Clicking skin highlights it
- [ ] Right panel shows: Apply, Back, Edit, Delete buttons
- [ ] Delete button is RED

#### Edit functionality
- [ ] Clicking "Edit" loads skin data into editor
- [ ] Can modify values
- [ ] Changes apply when clicking "Apply"

#### Delete functionality
- [ ] Clicking "Delete" removes skin from list
- [ ] Confirmation not required (immediate action)

---

### 5. Config Tab

#### Layout
- [ ] "Configuration Manager" header visible
- [ ] Left child window (300px width, 400px height)
- [ ] Right child window (remaining width, 400px height)

#### Left Panel (Config List)
- [ ] "Saved Configs" header
- [ ] Initially empty (no configs)
- [ ] Configs are selectable when present

#### Right Panel (Actions)
- [ ] "Actions" header
- [ ] Initially shows "Select a config to load or save" message
- [ ] "Create New Config" button at bottom

#### After clicking "Create New Config"
- [ ] Popup window appears: "Create Config"
- [ ] Modal overlay (background dimmed)
- [ ] Config Name input field
- [ ] Created By input field (default: "User")
- [ ] "Create" button (120px width)
- [ ] "Cancel" button (120px width)

#### After creating config
- [ ] Config appears in left panel list
- [ ] Shows: Name on main line
- [ ] Shows: "By: [creator]" in gray
- [ ] Shows: "At: [timestamp]" in gray
- [ ] Timestamp is in format: YYYY-MM-DD HH:MM:SS

#### With config selected
- [ ] Right panel shows config name
- [ ] "Load Config" button (full width, 35px tall)
- [ ] "Save Current to This" button (full width, 35px tall)
- [ ] Separator line
- [ ] "Delete Config" button (RED, full width, 35px tall)

#### Status messages
- [ ] After Load: Green message "Config Loaded: [name]" appears for 3 seconds
- [ ] After Save: Green message "Config Saved: [name]" appears for 3 seconds
- [ ] After Create: Green message "Config Created: [name]" appears for 3 seconds
- [ ] After Delete: Green message "Config Removed: [name]" appears for 3 seconds

---

### 6. Settings Tab

#### Content
- [ ] "Menu Settings" header visible
- [ ] User Name input field
- [ ] "Accent Color" label
- [ ] Color picker widget
- [ ] Color picker shows current accent color (default: cyan blue)
- [ ] Can click to open color editor
- [ ] "Menu Information" section
- [ ] Version: 1.0.0 (gray text)
- [ ] Build: ImGui Mockup (gray text)
- [ ] Platform: Android/Desktop (gray text)
- [ ] "About" section
- [ ] Multi-line description text
- [ ] Text wraps properly
- [ ] "Reset to Defaults" button (200x30)

#### Reset functionality
- [ ] Clicking "Reset to Defaults" resets User Name to "Player"
- [ ] Accent color resets to default cyan blue

---

## Visual/Style Testing

### Colors
- [ ] Window background is dark blue-gray
- [ ] Panel backgrounds are slightly lighter
- [ ] Text is off-white/light gray
- [ ] Accent color (cyan blue by default) is visible on:
  - Active tabs
  - Checkmarks
  - Slider grabs
  - Button hovers
  - Selected items

### Typography
- [ ] All text is readable
- [ ] Headers are distinguishable from body text
- [ ] Disabled/info text is gray
- [ ] Warning text is orange
- [ ] Error/danger text is red
- [ ] Success messages are green

### Layout
- [ ] Proper spacing between elements (12px item spacing)
- [ ] Sections have clear separators
- [ ] Rounded corners on windows and buttons
- [ ] Consistent padding (15px window padding)

### Interactions
- [ ] Buttons highlight on hover
- [ ] Sliders respond to dragging
- [ ] Checkboxes toggle with visual feedback
- [ ] Combo boxes show dropdown on click
- [ ] Text inputs show cursor when clicked
- [ ] Tab switching is smooth

---

## Performance Testing

### Desktop
- [ ] Application launches within 1-2 seconds
- [ ] Window is responsive (no lag)
- [ ] Tab switching is instant
- [ ] UI updates are smooth
- [ ] CPU usage is low (< 5%)
- [ ] Memory usage is reasonable (< 50 MB)

### Android (if applicable)
- [ ] Application launches within 2-3 seconds
- [ ] Touch input is responsive
- [ ] Tab switching works smoothly
- [ ] Scrolling is smooth
- [ ] No frame drops during interaction
- [ ] App doesn't drain battery excessively

---

## Error Testing

### Edge Cases
- [ ] Empty config name: Apply button should still work (creates empty-named config)
- [ ] Maximum slider values work correctly
- [ ] Minimum slider values work correctly
- [ ] Deleting all skins works (list becomes empty again)
- [ ] Deleting all configs works (list becomes empty again)
- [ ] Very long skin names don't break layout
- [ ] Very long config names don't break layout
- [ ] Resizing window (desktop) maintains layout

### Stability
- [ ] No crashes when clicking rapidly
- [ ] No crashes when switching tabs rapidly
- [ ] No crashes when creating/deleting many items
- [ ] No memory leaks after extended use
- [ ] Application can be closed cleanly (X button or OS kill)

---

## Platform-Specific Tests

### Desktop Only
- [ ] Window can be resized
- [ ] Window can be minimized
- [ ] Window can be maximized
- [ ] Window can be moved
- [ ] Window remembers size (if imgui.ini enabled)
- [ ] Keyboard Tab navigation works
- [ ] Keyboard shortcuts work (if any)

### Android Only
- [ ] Touch scrolling in child windows
- [ ] Pinch to zoom (if enabled)
- [ ] Rotation handling (landscape/portrait)
- [ ] Back button behavior
- [ ] Home button behavior
- [ ] Recent apps switching
- [ ] Soft keyboard appears for text inputs
- [ ] Soft keyboard doesn't cover input fields

---

## Automated Test Script

For quick testing on desktop, you can use this test sequence:

```bash
# Build and run
./build_with_deps.sh
./build/CheatMenuMockup &

# Wait for window to appear
sleep 2

# Test all tabs (manual)
# Click: Aimbot → Visuals → Exploits → Skins → Config → Settings

# Test interactions (manual)
# 1. Toggle some checkboxes
# 2. Move some sliders
# 3. Create a skin
# 4. Create a config
# 5. Change accent color

# Close application
pkill CheatMenuMockup
```

---

## Reporting Issues

If you find any issues during testing, note:

1. **What**: Describe the issue
2. **Where**: Which tab/section
3. **How**: Steps to reproduce
4. **Expected**: What should happen
5. **Actual**: What actually happens
6. **Platform**: Desktop (OS) or Android (device)
7. **Build**: Debug or Release

Example:
```
What: Slider doesn't move
Where: Aimbot > Settings > Speed slider
How: Click and drag the slider handle
Expected: Slider value should change from 1.0 to other values
Actual: Slider is stuck at 1.0
Platform: Desktop Linux Ubuntu 22.04
Build: Debug
```

---

## Success Criteria

The mockup is considered complete and working when:

✓ All 6 main tabs are present and functional  
✓ All sub-tabs work correctly  
✓ All UI elements are interactive  
✓ Visual styling matches the dark theme  
✓ No crashes or errors during normal use  
✓ Performance is acceptable (60 FPS on desktop)  
✓ All dummy data can be created/edited/deleted  
✓ Status messages appear correctly  
✓ Modal dialogs work properly  
✓ Both desktop and Android builds work (if tested)  

---

## Known Limitations (By Design)

These are NOT bugs - they are intentional for a mockup:

- No persistence: Settings are lost when closing
- No game interaction: This is UI only
- No file I/O: Configs don't save to disk
- No networking: No online features
- No actual functionality: All actions are dummy
- No animations: Basic ImGui rendering only
- No audio: No sound effects
- No localization: English only
