/**
 * @file about.hpp
 * @author HenryAWE
 * @brief About page
 */

#ifndef SROSE_UI_GUI_about_hpp_
#define SROSE_UI_GUI_about_hpp_

#include <sr/ui/gui/widget.hpp>


namespace srose::ui
{
    class About : public Widget
    {
    public:
        About();

        void Update() override;

    private:
        std::string m_str_return;
        std::string m_str_website;

        void Load();
        void OnImbue() override;
    };
} // namespace srose::ui


#endif
