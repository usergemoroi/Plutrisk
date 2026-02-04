#include "config_tab.h"
#include "imgui.h"
#include <vector>
#include <string>
#include <ctime>

namespace Tabs {

struct ConfigItem {
    std::string name;
    std::string createdBy;
    std::string createdAt;
};

static struct ConfigState {
    std::vector<ConfigItem> configs;
    int selectedConfig = -1;
    bool showCreateDialog = false;
    char newConfigName[128] = "";
    char creatorName[128] = "User";
    std::string statusMessage;
    float statusMessageTime = 0.0f;
} s_configState;

static std::string GetCurrentTime() {
    time_t now = time(nullptr);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return std::string(buffer);
}

void RenderConfigTab() {
    ImGui::Spacing();
    
    ImGui::Text("Configuration Manager");
    ImGui::Separator();
    ImGui::Spacing();
    
    if (!s_configState.statusMessage.empty() && s_configState.statusMessageTime > 0.0f) {
        ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "%s", s_configState.statusMessage.c_str());
        ImGui::Spacing();
        s_configState.statusMessageTime -= ImGui::GetIO().DeltaTime;
    }
    
    ImGui::BeginChild("ConfigListChild", ImVec2(300, 400), true);
    {
        ImGui::Text("Saved Configs");
        ImGui::Separator();
        ImGui::Spacing();
        
        for (int i = 0; i < (int)s_configState.configs.size(); i++) {
            const auto& config = s_configState.configs[i];
            
            ImGui::PushID(i);
            
            if (ImGui::Selectable(config.name.c_str(), s_configState.selectedConfig == i, 0, ImVec2(0, 30))) {
                s_configState.selectedConfig = i;
            }
            
            if (s_configState.selectedConfig == i) {
                ImGui::Indent();
                ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "By: %s", config.createdBy.c_str());
                ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "At: %s", config.createdAt.c_str());
                ImGui::Unindent();
            }
            
            ImGui::PopID();
        }
    }
    ImGui::EndChild();
    
    ImGui::SameLine();
    
    ImGui::BeginChild("ConfigActionsChild", ImVec2(0, 400), true);
    {
        ImGui::Text("Actions");
        ImGui::Separator();
        ImGui::Spacing();
        
        if (s_configState.selectedConfig >= 0) {
            const auto& config = s_configState.configs[s_configState.selectedConfig];
            
            ImGui::Text("Selected: %s", config.name.c_str());
            ImGui::Spacing();
            
            if (ImGui::Button("Load Config", ImVec2(-1, 35))) {
                s_configState.statusMessage = "Config Loaded: " + config.name;
                s_configState.statusMessageTime = 3.0f;
            }
            
            if (ImGui::Button("Save Current to This", ImVec2(-1, 35))) {
                s_configState.statusMessage = "Config Saved: " + config.name;
                s_configState.statusMessageTime = 3.0f;
            }
            
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
            
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.2f, 0.2f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.3f, 0.3f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.7f, 0.1f, 0.1f, 1.0f));
            
            if (ImGui::Button("Delete Config", ImVec2(-1, 35))) {
                s_configState.statusMessage = "Config Removed: " + config.name;
                s_configState.statusMessageTime = 3.0f;
                s_configState.configs.erase(s_configState.configs.begin() + s_configState.selectedConfig);
                s_configState.selectedConfig = -1;
            }
            
            ImGui::PopStyleColor(3);
        } else {
            ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "Select a config to load or save");
        }
        
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        
        if (ImGui::Button("Create New Config", ImVec2(-1, 35))) {
            s_configState.showCreateDialog = true;
            s_configState.newConfigName[0] = '\0';
        }
    }
    ImGui::EndChild();
    
    if (s_configState.showCreateDialog) {
        ImGui::OpenPopup("Create Config");
    }
    
    if (ImGui::BeginPopupModal("Create Config", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text("Create New Configuration");
        ImGui::Separator();
        ImGui::Spacing();
        
        ImGui::InputText("Config Name", s_configState.newConfigName, sizeof(s_configState.newConfigName));
        ImGui::InputText("Created By", s_configState.creatorName, sizeof(s_configState.creatorName));
        
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        
        if (ImGui::Button("Create", ImVec2(120, 0))) {
            if (strlen(s_configState.newConfigName) > 0) {
                ConfigItem newConfig;
                newConfig.name = s_configState.newConfigName;
                newConfig.createdBy = s_configState.creatorName;
                newConfig.createdAt = GetCurrentTime();
                
                s_configState.configs.push_back(newConfig);
                s_configState.statusMessage = "Config Created: " + newConfig.name;
                s_configState.statusMessageTime = 3.0f;
                
                s_configState.showCreateDialog = false;
                ImGui::CloseCurrentPopup();
            }
        }
        
        ImGui::SameLine();
        
        if (ImGui::Button("Cancel", ImVec2(120, 0))) {
            s_configState.showCreateDialog = false;
            ImGui::CloseCurrentPopup();
        }
        
        ImGui::EndPopup();
    }
}

}
