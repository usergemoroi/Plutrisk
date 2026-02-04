#pragma once

#include "imgui.h"

class CheatMenu {
public:
    CheatMenu();
    void Render();
    void ApplyStyle();
    
    bool IsOpen() const { return m_isOpen; }
    void SetOpen(bool open) { m_isOpen = open; }
    
private:
    void RenderMainWindow();
    
    bool m_isOpen = true;
    int m_selectedTab = 0;
    ImVec4 m_accentColor;
};
