#include "visuals_tab.h"
#include "imgui.h"

namespace Tabs {

static struct VisualsSettings {
    struct Player {
        bool enable = false;
        bool box = false;
        bool fill = false;
        bool healthBar = false;
        bool healthAmount = false;
        bool name = false;
        bool weaponIcon = false;
        bool traces = false;
        bool skeleton = false;
        float thickness = 1.0f;
        float rounding = 0.0f;
        
        struct Chams {
            bool enable = false;
            int type = 0;
        } chams;
    } player;
    
    struct Weapons {
        bool enable = false;
        bool name = false;
        bool ammo = false;
    } weapons;
    
    struct Grenades {
        bool enable = false;
        bool circle = false;
        bool timer = false;
    } grenades;
    
    struct World {
        bool bulletTracer = false;
        bool sceneColor = false;
        bool fog = false;
        float fogStart = 0.0f;
        float fogEnd = 1000.0f;
        bool skyBox = false;
        float atmosphereThickness = 1.0f;
        float exposure = 1.0f;
        float sunSize = 1.0f;
        int sunQuality = 2;
    } world;
} s_visualsSettings;

void RenderVisualsTab() {
    if (ImGui::BeginTabBar("##VisualsSubTabs")) {
        if (ImGui::BeginTabItem("Players")) {
            ImGui::Spacing();
            
            ImGui::Text("Player ESP");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Enable", &s_visualsSettings.player.enable);
            ImGui::Checkbox("Box", &s_visualsSettings.player.box);
            ImGui::Checkbox("Fill", &s_visualsSettings.player.fill);
            ImGui::Checkbox("Health Bar", &s_visualsSettings.player.healthBar);
            ImGui::Checkbox("Health Amount", &s_visualsSettings.player.healthAmount);
            ImGui::Checkbox("Name", &s_visualsSettings.player.name);
            ImGui::Checkbox("Weapon Icon", &s_visualsSettings.player.weaponIcon);
            ImGui::Checkbox("Traces", &s_visualsSettings.player.traces);
            ImGui::Checkbox("Skeleton", &s_visualsSettings.player.skeleton);
            
            ImGui::Spacing();
            ImGui::SliderFloat("Thickness", &s_visualsSettings.player.thickness, 0.5f, 5.0f);
            ImGui::SliderFloat("Rounding", &s_visualsSettings.player.rounding, 0.0f, 12.0f);
            
            ImGui::Spacing();
            ImGui::Text("Chams");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Enable Chams", &s_visualsSettings.player.chams.enable);
            
            const char* chamsTypes[] = { "Normal", "Flat", "Wireframe", "Glow" };
            ImGui::Combo("Chams Type", &s_visualsSettings.player.chams.type, chamsTypes, IM_ARRAYSIZE(chamsTypes));
            
            ImGui::EndTabItem();
        }
        
        if (ImGui::BeginTabItem("Weapons")) {
            ImGui::Spacing();
            
            ImGui::Text("Weapon ESP");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Enable", &s_visualsSettings.weapons.enable);
            ImGui::Checkbox("Name", &s_visualsSettings.weapons.name);
            ImGui::Checkbox("Ammo", &s_visualsSettings.weapons.ammo);
            
            ImGui::EndTabItem();
        }
        
        if (ImGui::BeginTabItem("Grenades")) {
            ImGui::Spacing();
            
            ImGui::Text("Grenade ESP");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Enable", &s_visualsSettings.grenades.enable);
            ImGui::Checkbox("Circle", &s_visualsSettings.grenades.circle);
            ImGui::Checkbox("Timer", &s_visualsSettings.grenades.timer);
            
            ImGui::EndTabItem();
        }
        
        if (ImGui::BeginTabItem("World")) {
            ImGui::Spacing();
            
            ImGui::Text("World Visuals");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Bullet Tracer", &s_visualsSettings.world.bulletTracer);
            ImGui::Checkbox("Scene Color", &s_visualsSettings.world.sceneColor);
            
            ImGui::Spacing();
            ImGui::Text("Fog");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Enable Fog", &s_visualsSettings.world.fog);
            ImGui::SliderFloat("Fog Start", &s_visualsSettings.world.fogStart, 0.0f, 5000.0f);
            ImGui::SliderFloat("Fog End", &s_visualsSettings.world.fogEnd, 0.0f, 10000.0f);
            
            ImGui::Spacing();
            ImGui::Text("Sky");
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::Checkbox("Custom SkyBox", &s_visualsSettings.world.skyBox);
            ImGui::SliderFloat("Atmosphere Thickness", &s_visualsSettings.world.atmosphereThickness, 0.0f, 5.0f);
            ImGui::SliderFloat("Exposure", &s_visualsSettings.world.exposure, 0.0f, 5.0f);
            ImGui::SliderFloat("Sun Size", &s_visualsSettings.world.sunSize, 0.0f, 10.0f);
            ImGui::SliderInt("Sun Quality", &s_visualsSettings.world.sunQuality, 0, 4);
            
            ImGui::EndTabItem();
        }
        
        ImGui::EndTabBar();
    }
}

}
