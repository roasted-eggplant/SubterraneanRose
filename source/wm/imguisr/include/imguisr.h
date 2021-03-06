/**
 * @file imguisr.h
 * @author HenryAWE
 * @brief ImGui extensions
 */

#ifndef SROSE_WM_IMGUISR_imguisr_h_
#define SROSE_WM_IMGUISR_imguisr_h_

#include <functional>
#include <utility>
#include <optional>
#include <imgui.h>
#include <sr/filesystem/filesystem.hpp>


namespace ImGuiSR
{
    /* RAII helper classes for ImGui
     * 
     * Usage:
     *  auto object = ImGuiSR::PushGuard<ImGuiSR_ObjectType>(args...);
     */

    class PushGuardBase
    {
    public:
        const bool value;

        [[nodiscard]]
        constexpr operator bool() const noexcept { return value; }
    
    protected:
        PushGuardBase(bool value_) noexcept
            : value(value_) {}
    };

    enum ImGuiSRPushType : int
    {
        ImGuiSR_ID,
        ImGuiSR_Window,
        ImGuiSR_MenuBar,
        ImGuiSR_Menu,
        ImGuiSR_TabBar,
        ImGuiSR_TabItem
    };

    template <ImGuiSRPushType type>
    class PushGuard;

    template <>
    class PushGuard<ImGuiSR_ID> : public PushGuardBase
    {
    public:
        template <typename... Args>
        PushGuard(Args&&... args) noexcept
            : PushGuardBase((ImGui::PushID(std::forward<Args>(args)...), true)) {}

        ~PushGuard() noexcept { ImGui::PopID(); }
    };

    template <>
    class PushGuard<ImGuiSR_Window> : public PushGuardBase
    {
    public:
        template <typename... Args>
        PushGuard(Args&&... args) noexcept
            : PushGuardBase(ImGui::Begin(std::forward<Args>(args)...)) {}

        ~PushGuard() noexcept { ImGui::End(); }
    };

    #define IMGUISR_PUSHGUARD_TEMPLATE(objname, open_func, close_func) \
    template <>\
    class PushGuard<objname> : public PushGuardBase\
    {\
    public:\
        template <typename... Args>\
        PushGuard(Args&&... args) noexcept\
            : PushGuardBase(open_func(std::forward<Args>(args)...)) {}\
        \
        ~PushGuard() noexcept { if(value)close_func(); }\
    };

    IMGUISR_PUSHGUARD_TEMPLATE(ImGuiSR_MenuBar, ImGui::BeginMenuBar, ImGui::EndMenuBar);
    IMGUISR_PUSHGUARD_TEMPLATE(ImGuiSR_Menu, ImGui::BeginMenu, ImGui::EndMenu);
    IMGUISR_PUSHGUARD_TEMPLATE(ImGuiSR_TabBar, ImGui::BeginTabBar, ImGui::EndTabBar);
    IMGUISR_PUSHGUARD_TEMPLATE(ImGuiSR_TabItem, ImGui::BeginTabItem, ImGui::EndTabItem);
} // namespace ImGuiSR


#endif
