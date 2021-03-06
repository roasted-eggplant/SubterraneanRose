/**
 * @file editor_window.hpp
 * @author HenryAWE
 * @brief Editor window
 */

#ifndef SROSE_UI_GUI_editor_window_hpp_
#define SROSE_UI_GUI_editor_window_hpp_

#include <sr/ui/property.hpp>
#include <imguisr.h>
#include <sr/ui/gui/widget.hpp>


namespace srose::ui::editor
{
    class EditorWindow : public Widget
    {
        bool first_appeared = true;
    public:
        EditorWindow();

        void Update() override;

    private:
        std::string m_title;
        void LoadAll();
        void OnImbue() override;

        void UpdateMenuBar();

        std::string m_button_return;
        void Button_Return();

        void OnSetWindowSubtitle() override { DoSetWindowSubtitle(m_title.c_str()); }
    };
} // namespace srose::ui


#endif
