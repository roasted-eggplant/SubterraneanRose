/**
 * @file main_loop.cpp
 * @author HenryAWE
 * @brief 
 */

#include <glad/glad.h>
#include "main_loop.hpp"
#include <cstdlib>
#include <sr/wm/event.h>
#include <imgui.h>
#include "main_menu/main_menu_bar.hpp"
#include <sr/gpu/opengl3/texture.hpp>
#include <sr/gpu/opengl3/renderer.hpp>
#include <sr/locale/locale.hpp>
#include "i18n/i18n.hpp"


int SRSCALL main_loop(SR_WM_display* display)
{
    using namespace srose;
    using namespace srose::ui;

    srose::gpu::opengl3::Renderer renderer(display);
    main_menu::MainMenuBar main_menu(display);
    DebugUI dbg_ui(&main_menu.show_debug_ui);

    int loop = SDL_TRUE;
    while(loop)
    {
        /*Event processing*/
        loop = SR_WM_ProcessEvent();
        SR_WM_NewFrame();

        main_menu.Update();

        if(main_menu.show_imgui_demo)
            ImGui::ShowDemoWindow(&main_menu.show_imgui_demo);
        dbg_ui.Update();
        SR_WM_EndFrame();

        /*Rendering */
        renderer.ClearScreen();
        SR_WM_RenderFrame();
        renderer.Present();
    }

    return EXIT_SUCCESS;
}
