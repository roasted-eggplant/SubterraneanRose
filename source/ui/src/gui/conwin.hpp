/**
 * @file conwin.hpp
 * @author HenryAWE
 * @brief Graphical console
 */

#ifndef SROSE_UI_GUI_conwin_hpp_
#define SROSE_UI_GUI_conwin_hpp_

#include <tuple>
#include <deque>
#include <sr/ui/gui/widget.hpp>
#include <SDL_log.h>


namespace srose::ui
{
    class ConsoleWindow : public Widget
    {
    public:
        ConsoleWindow();

        ~ConsoleWindow();

        bool open = true;
        void Update() override;

        bool verbose = false;

    private:
        std::string m_title;
        std::string m_logviewer;
        void Load();
        void OnImbue() override;

        void UpdateLogViewerTabItem();

        std::deque<std::tuple<SDL_LogPriority, std::string>> m_logbuf;
        bool m_logchanged = false;
        void RedirectSdlOutput();
        void SdlLogCallback(int category, SDL_LogPriority priority, const char* message);
    };
} // namespace srose::ui


#endif
