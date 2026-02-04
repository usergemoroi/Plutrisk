#include "settings_tab.h"
#include "imgui.h"

namespace Tabs {

static struct SettingsData {
    char userName[128] = "Player";
    float accentColor[4] = { 0.26f, 0.59f, 0.98f, 1.0f };
} s_settingsData;

void RenderSettingsTab() {
    ImGui::Spacing();
    
    ImGui::Text("Menu Settings");
    ImGui::Separator();
    ImGui::Spacing();
    
    ImGui::InputText("User Name", s_settingsData.userName, sizeof(s_settingsData.userName));
    
    ImGui::Spacing();
    ImGui::Text("Accent Color");
    ImGui::ColorEdit4("##AccentColor", s_settingsData.accentColor, ImGuiColorEditFlags_NoInputs);
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    
    ImGui::Text("Menu Information");
    ImGui::Spacing();
    
    ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "Version: 1.0.0");
    ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "Build: ImGui Mockup");
    ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "Platform: Android/Desktop");
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    
    ImGui::Text("About");
    ImGui::Spacing();
    ImGui::TextWrapped("This is a complete GUI mockup of the cheat menu interface. "
                      "All UI elements are present but without functional implementation. "
                      "Created with Dear ImGui for cross-platform compatibility.");
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    
    if (ImGui::Button("Reset to Defaults", ImVec2(200, 30))) {
        strcpy(s_settingsData.userName, "Player");
        s_settingsData.accentColor[0] = 0.26f;
        s_settingsData.accentColor[1] = 0.59f;
        s_settingsData.accentColor[2] = 0.98f;
        s_settingsData.accentColor[3] = 1.0f;
    }
}

}
