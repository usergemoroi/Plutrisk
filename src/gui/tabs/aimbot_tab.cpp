#include "aimbot_tab.h"
#include "imgui.h"

namespace Tabs {

static struct AimbotSettings {
    bool enable = false;
    bool fovCheck = false;
    bool drawFov = false;
    bool fireCheck = false;
    bool autoFire = false;
    bool untouchableCheck = false;
    bool silent = false;
    
    struct Bones {
        bool head = true;
        bool neck = false;
        bool stomach = false;
        bool hands = false;
        bool legs = false;
        bool foots = false;
    } bones;
    
    struct Settings {
        int boneFilterDamage = 50;
        int boneFilterAngle = 45;
        float speed = 1.0f;
        float hitChance = 0.85f;
        float fov = 90.0f;
    } settings;
} s_aimbotSettings;

void RenderAimbotTab() {
    if (ImGui::BeginTabBar("##AimbotSubTabs")) {
        if (ImGui::BeginTabItem("Main")) {
            ImGui::Spacing();
            
            ImGui::Text("Main Settings");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Enable", &s_aimbotSettings.enable);
            ImGui::Checkbox("FOV Check", &s_aimbotSettings.fovCheck);
            ImGui::Checkbox("Draw FOV", &s_aimbotSettings.drawFov);
            ImGui::Checkbox("Fire Check", &s_aimbotSettings.fireCheck);
            ImGui::Checkbox("Auto Fire", &s_aimbotSettings.autoFire);
            ImGui::Checkbox("Untouchable Check", &s_aimbotSettings.untouchableCheck);
            ImGui::Checkbox("Silent", &s_aimbotSettings.silent);
            
            ImGui::Spacing();
            ImGui::Text("Target Bones");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Head", &s_aimbotSettings.bones.head);
            ImGui::Checkbox("Neck", &s_aimbotSettings.bones.neck);
            ImGui::Checkbox("Stomach", &s_aimbotSettings.bones.stomach);
            ImGui::Checkbox("Hands", &s_aimbotSettings.bones.hands);
            ImGui::Checkbox("Legs", &s_aimbotSettings.bones.legs);
            ImGui::Checkbox("Foots", &s_aimbotSettings.bones.foots);
            
            ImGui::EndTabItem();
        }
        
        if (ImGui::BeginTabItem("Settings")) {
            ImGui::Spacing();
            
            ImGui::Text("Bone Filter");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::SliderInt("Damage", &s_aimbotSettings.settings.boneFilterDamage, 0, 100);
            ImGui::SliderInt("Angle", &s_aimbotSettings.settings.boneFilterAngle, 0, 180);
            
            ImGui::Spacing();
            ImGui::Text("Advanced");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::SliderFloat("Speed", &s_aimbotSettings.settings.speed, 0.1f, 10.0f);
            ImGui::SliderFloat("Hit Chance", &s_aimbotSettings.settings.hitChance, 0.0f, 1.0f);
            ImGui::SliderFloat("FOV", &s_aimbotSettings.settings.fov, 1.0f, 180.0f);
            
            ImGui::EndTabItem();
        }
        
        ImGui::EndTabBar();
    }
}

}
