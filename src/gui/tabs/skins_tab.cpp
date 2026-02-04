#include "skins_tab.h"
#include "imgui.h"
#include <vector>
#include <string>

namespace Tabs {

struct SkinItem {
    std::string weaponType;
    std::string skinName;
    int pattern;
    bool stattrack;
    int rarity;
};

static struct SkinsState {
    std::vector<SkinItem> skins;
    int selectedSkin = -1;
    bool editMode = false;
    
    SkinItem editingSkin;
    char skinNameBuffer[128] = "";
    int weaponTypeIdx = 0;
    int pattern = 0;
    bool stattrack = false;
    int rarity = 0;
} s_skinsState;

void RenderSkinsTab() {
    ImGui::Spacing();
    
    ImGui::BeginChild("SkinsListChild", ImVec2(250, 0), true);
    {
        ImGui::Text("Skins List");
        ImGui::Separator();
        ImGui::Spacing();
        
        for (int i = 0; i < (int)s_skinsState.skins.size(); i++) {
            const auto& skin = s_skinsState.skins[i];
            
            ImGui::PushID(i);
            if (ImGui::Selectable(skin.skinName.c_str(), s_skinsState.selectedSkin == i, 0, ImVec2(0, 25))) {
                s_skinsState.selectedSkin = i;
            }
            ImGui::PopID();
        }
        
        ImGui::Spacing();
        
        if (ImGui::Button("Add Skin", ImVec2(-1, 30))) {
            s_skinsState.editMode = true;
            s_skinsState.selectedSkin = -1;
            s_skinsState.editingSkin = SkinItem();
            s_skinsState.skinNameBuffer[0] = '\0';
            s_skinsState.weaponTypeIdx = 0;
            s_skinsState.pattern = 0;
            s_skinsState.stattrack = false;
            s_skinsState.rarity = 0;
        }
    }
    ImGui::EndChild();
    
    ImGui::SameLine();
    
    ImGui::BeginChild("SkinsEditorChild", ImVec2(0, 0), true);
    {
        if (s_skinsState.editMode || s_skinsState.selectedSkin >= 0) {
            ImGui::Text("Skin Editor");
            ImGui::Separator();
            ImGui::Spacing();
            
            const char* weaponTypes[] = {
                "AK-47", "M4A4", "M4A1-S", "AWP", "Desert Eagle",
                "Glock-18", "USP-S", "P250", "Five-SeveN", "Tec-9",
                "MP7", "MP9", "UMP-45", "P90", "Bizon",
                "MAC-10", "Nova", "XM1014", "MAG-7", "Sawed-Off",
                "M249", "Negev", "Knife", "Gloves"
            };
            
            ImGui::Combo("Weapon Type", &s_skinsState.weaponTypeIdx, weaponTypes, IM_ARRAYSIZE(weaponTypes));
            
            ImGui::Spacing();
            ImGui::InputText("Skin Name", s_skinsState.skinNameBuffer, sizeof(s_skinsState.skinNameBuffer));
            
            ImGui::Spacing();
            ImGui::SliderInt("Pattern", &s_skinsState.pattern, 0, 999);
            
            ImGui::Spacing();
            ImGui::Checkbox("StatTrak™", &s_skinsState.stattrack);
            
            ImGui::Spacing();
            const char* rarities[] = { "Consumer", "Industrial", "Mil-Spec", "Restricted", "Classified", "Covert", "Contraband" };
            ImGui::Combo("Rarity", &s_skinsState.rarity, rarities, IM_ARRAYSIZE(rarities));
            
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
            
            if (ImGui::Button("Apply", ImVec2(100, 30))) {
                if (s_skinsState.editMode) {
                    SkinItem newSkin;
                    newSkin.weaponType = weaponTypes[s_skinsState.weaponTypeIdx];
                    newSkin.skinName = s_skinsState.skinNameBuffer;
                    newSkin.pattern = s_skinsState.pattern;
                    newSkin.stattrack = s_skinsState.stattrack;
                    newSkin.rarity = s_skinsState.rarity;
                    
                    if (!newSkin.skinName.empty()) {
                        s_skinsState.skins.push_back(newSkin);
                        s_skinsState.editMode = false;
                        s_skinsState.selectedSkin = (int)s_skinsState.skins.size() - 1;
                    }
                } else if (s_skinsState.selectedSkin >= 0) {
                    auto& skin = s_skinsState.skins[s_skinsState.selectedSkin];
                    skin.weaponType = weaponTypes[s_skinsState.weaponTypeIdx];
                    skin.skinName = s_skinsState.skinNameBuffer;
                    skin.pattern = s_skinsState.pattern;
                    skin.stattrack = s_skinsState.stattrack;
                    skin.rarity = s_skinsState.rarity;
                }
            }
            
            ImGui::SameLine();
            
            if (ImGui::Button("Back", ImVec2(100, 30))) {
                s_skinsState.editMode = false;
            }
            
            ImGui::SameLine();
            
            if (s_skinsState.selectedSkin >= 0 && !s_skinsState.editMode) {
                if (ImGui::Button("Edit", ImVec2(100, 30))) {
                    const auto& skin = s_skinsState.skins[s_skinsState.selectedSkin];
                    
                    for (int i = 0; i < 24; i++) {
                        if (weaponTypes[i] == skin.weaponType) {
                            s_skinsState.weaponTypeIdx = i;
                            break;
                        }
                    }
                    
                    strncpy(s_skinsState.skinNameBuffer, skin.skinName.c_str(), sizeof(s_skinsState.skinNameBuffer) - 1);
                    s_skinsState.pattern = skin.pattern;
                    s_skinsState.stattrack = skin.stattrack;
                    s_skinsState.rarity = skin.rarity;
                }
                
                ImGui::SameLine();
                
                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.2f, 0.2f, 1.0f));
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.3f, 0.3f, 1.0f));
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.7f, 0.1f, 0.1f, 1.0f));
                
                if (ImGui::Button("Delete", ImVec2(100, 30))) {
                    s_skinsState.skins.erase(s_skinsState.skins.begin() + s_skinsState.selectedSkin);
                    s_skinsState.selectedSkin = -1;
                }
                
                ImGui::PopStyleColor(3);
            }
        } else {
            ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "Select a skin or add a new one");
        }
    }
    ImGui::EndChild();
}

}
