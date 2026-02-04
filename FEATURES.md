# Feature Overview

Complete visual mockup of all menu tabs and features extracted from the original binary.

## Menu Structure

```
Cheat Menu
├── Aimbot
│   ├── Main
│   │   ├── Enable
│   │   ├── FOV Check
│   │   ├── Draw FOV
│   │   ├── Fire Check
│   │   ├── Auto Fire
│   │   ├── Untouchable Check
│   │   ├── Silent
│   │   └── Target Bones
│   │       ├── Head
│   │       ├── Neck
│   │       ├── Stomach
│   │       ├── Hands
│   │       ├── Legs
│   │       └── Foots
│   └── Settings
│       ├── Bone Filter
│       │   ├── Damage (0-100)
│       │   └── Angle (0-180)
│       ├── Speed (0.1-10.0)
│       ├── Hit Chance (0.0-1.0)
│       └── FOV (1.0-180.0)
│
├── Visuals
│   ├── Players
│   │   ├── Enable
│   │   ├── Box
│   │   ├── Fill
│   │   ├── Health Bar
│   │   ├── Health Amount
│   │   ├── Name
│   │   ├── Weapon Icon
│   │   ├── Traces
│   │   ├── Skeleton
│   │   ├── Thickness (0.5-5.0)
│   │   ├── Rounding (0.0-12.0)
│   │   └── Chams
│   │       ├── Enable
│   │       └── Type (Normal/Flat/Wireframe/Glow)
│   ├── Weapons
│   │   ├── Enable
│   │   ├── Name
│   │   └── Ammo
│   ├── Grenades
│   │   ├── Enable
│   │   ├── Circle
│   │   └── Timer
│   └── World
│       ├── Bullet Tracer
│       ├── Scene Color
│       ├── Fog
│       │   ├── Enable
│       │   ├── Start (0-5000)
│       │   └── End (0-10000)
│       └── Sky
│           ├── Custom SkyBox
│           ├── Atmosphere Thickness (0.0-5.0)
│           ├── Exposure (0.0-5.0)
│           ├── Sun Size (0.0-10.0)
│           └── Sun Quality (0-4)
│
├── Exploits
│   ├── Weapon
│   │   ├── Fire Rate (0.1-10.0)
│   │   └── Infinity Ammo
│   ├── Movement
│   │   ├── Air Jump
│   │   └── Move Before Timer
│   ├── Bomb
│   │   ├── Get Bomb
│   │   ├── Auto Win
│   │   ├── Fast Plant
│   │   ├── [Plant Bomb] Button
│   │   ├── [Defuse Bomb] Button
│   │   └── [Explode Bomb] Button
│   ├── Host
│   │   ├── Warning: Host detection
│   │   ├── Auto Win
│   │   ├── Fast Defuse
│   │   ├── Fast Detonate
│   │   ├── [Crash Host] Button (Dangerous)
│   │   ├── [Destroy Enemies] Button (Dangerous)
│   │   └── [Destroy Teammates] Button (Dangerous)
│   └── Premium
│       ├── Third Person View (TPV)
│       ├── Invisible
│       ├── Chat Spam
│       ├── Auto Kill
│       ├── Fast Strafe
│       ├── Freeze Kill
│       ├── Crash Enemies
│       └── Crash Teammates
│
├── Skins
│   ├── [Skin List] (Left panel)
│   │   └── [Add Skin] Button
│   └── [Editor] (Right panel)
│       ├── Weapon Type (24 weapons + knives/gloves)
│       ├── Skin Name (Text input)
│       ├── Pattern (0-999)
│       ├── StatTrak™ (Checkbox)
│       ├── Rarity (7 levels)
│       ├── [Apply] Button
│       ├── [Back] Button
│       ├── [Edit] Button
│       └── [Delete] Button
│
├── Config
│   ├── [Config List] (Left panel)
│   │   └── Shows: Name, Creator, Date
│   ├── [Actions] (Right panel)
│   │   ├── [Load Config] Button
│   │   ├── [Save Current to This] Button
│   │   ├── [Delete Config] Button (Red)
│   │   └── [Create New Config] Button
│   └── [Create Dialog] Popup
│       ├── Config Name (Input)
│       ├── Created By (Input)
│       ├── [Create] Button
│       └── [Cancel] Button
│
└── Settings
    ├── User Name (Text input)
    ├── Accent Color (Color picker)
    ├── Menu Information
    │   ├── Version: 1.0.0
    │   ├── Build: ImGui Mockup
    │   └── Platform: Android/Desktop
    ├── About (Description text)
    └── [Reset to Defaults] Button
```

---

## UI Elements Used

### Standard Controls
- **Checkboxes**: All boolean options
- **Sliders**: Float and integer ranges
- **Combo Boxes**: Multiple choice options (weapon types, rarities, chams types)
- **Text Inputs**: User names, config names, skin names
- **Buttons**: Actions (Load, Save, Delete, Create, Apply, etc.)
- **Color Picker**: Accent color customization

### Custom Layouts
- **Tab Bars**: Main tabs and sub-tabs
- **Child Windows**: Split panels for list/editor views
- **Modal Popups**: Config creation dialog
- **Separators**: Section dividers
- **Text Colors**: Warnings (orange), Errors (red), Info (gray)
- **Button Colors**: Dangerous actions highlighted in red

---

## Color Scheme

### Theme: Dark Blue-Gray
- **Background**: Deep blue-gray (#1C262B)
- **Panels**: Darker panels (#262E38)
- **Accent**: Cyan blue (#42C0FB) - customizable
- **Text**: Off-white (#F2F4F8)
- **Text Disabled**: Gray (#5C6A79)
- **Danger**: Red (#CC3333)
- **Warning**: Orange (#FF8000)
- **Success**: Green (#00FF00)

### Visual Effects
- Rounded corners on all elements
- Smooth hover transitions
- Highlighted selections
- Consistent spacing (12px items, 15px window padding)
- Drop shadows on popups

---

## Weapon Types in Skins Tab

The skins editor includes all CS:GO weapon categories:

### Rifles
- AK-47
- M4A4
- M4A1-S

### Sniper Rifles
- AWP

### Pistols
- Desert Eagle
- Glock-18
- USP-S
- P250
- Five-SeveN
- Tec-9

### SMGs
- MP7
- MP9
- UMP-45
- P90
- PP-Bizon
- MAC-10

### Shotguns
- Nova
- XM1014
- MAG-7
- Sawed-Off

### Heavy
- M249
- Negev

### Melee & Gloves
- Knife
- Gloves

---

## Rarity Levels (Skins)

Following CS:GO skin rarity system:

1. **Consumer Grade** (White)
2. **Industrial Grade** (Light Blue)
3. **Mil-Spec** (Blue)
4. **Restricted** (Purple)
5. **Classified** (Pink/Magenta)
6. **Covert** (Red)
7. **Contraband** (Gold/Yellow)

---

## Chams Types (Visuals > Players)

Visual rendering styles for player models:

1. **Normal** - Standard colored overlay
2. **Flat** - Solid color without lighting
3. **Wireframe** - Only edges visible
4. **Glow** - Glowing outline effect

---

## Status Messages (Config Tab)

The config manager shows temporary status messages:

- ✓ "Config Loaded: [name]" (Green, 3s)
- ✓ "Config Saved: [name]" (Green, 3s)
- ✓ "Config Created: [name]" (Green, 3s)
- ✓ "Config Removed: [name]" (Green, 3s)

---

## Dummy Data Examples

### Sample Aimbot Settings
```
Enable: true
FOV Check: true
Draw FOV: true
Fire Check: false
Auto Fire: false
Untouchable Check: true
Silent: false

Bones:
  Head: true
  Neck: false
  Stomach: false
  Others: false

Bone Filter Damage: 50
Bone Filter Angle: 45
Speed: 1.0
Hit Chance: 0.85
FOV: 90.0
```

### Sample Visual Settings
```
Player ESP:
  Enable: true
  Box: true
  Fill: false
  Health Bar: true
  Name: true
  Thickness: 1.5
  Rounding: 2.0
  
Chams:
  Enable: true
  Type: Glow

Grenades:
  Enable: true
  Circle: true
  Timer: true
```

### Sample Skin Configuration
```
Weapon: AK-47
Skin Name: Fire Serpent
Pattern: 661
StatTrak™: true
Rarity: Covert
```

### Sample Config
```
Name: "Pro Settings"
Created By: "Player"
Created At: "2024-02-04 14:30:00"
```

---

## Keyboard/Mouse Controls (Desktop)

- **Mouse**: Click and drag for all interactions
- **Scroll**: Scroll within child windows and sliders
- **Tab**: Navigate between input fields
- **Enter**: Confirm in text inputs
- **ESC**: Close popups
- **Click X**: Close menu window

## Touch Controls (Android)

- **Tap**: Select/toggle checkboxes
- **Tap + Hold**: Drag sliders
- **Swipe**: Scroll lists and windows
- **Tap X**: Close menu

---

## Performance Notes

All UI rendering is done via ImGui with minimal overhead:

- **Desktop**: Targets 60+ FPS on any modern system
- **Android**: Optimized for 60 FPS on mid-range devices (2017+)
- **Memory**: ~5-10 MB for UI state and ImGui context
- **GPU**: Minimal - basic 2D rendering with OpenGL ES 3.0/OpenGL 3.0

---

## Implementation Notes

### What's Included
✓ Complete UI layout and structure  
✓ All tabs and sub-tabs  
✓ All settings and controls  
✓ Proper styling and theming  
✓ Dummy state management  
✓ Interactive elements  
✓ Status messages  
✓ Modal dialogs  

### What's NOT Included (Mockup Only)
✗ No game interaction/hooking  
✗ No memory manipulation  
✗ No network functionality  
✗ No file I/O for configs  
✗ No actual cheat logic  
✗ No anti-cheat bypass  

This is purely a **visual interface mockup** for design and demonstration purposes.
