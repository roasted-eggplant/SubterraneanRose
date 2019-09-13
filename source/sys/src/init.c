/**
 * @file init.c
 * @author HenryAWE
 * @brief Initialization 
 */

#include <sr/sys/init.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <gl/glew.h>


int SRSCALL SR_SYS_InitSDL(int msgbox_on_err)
{
    #define VERSION_NUMBER_2_ARG(x) ((x).major),((x).minor),((x).patch)
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "[SYS] SDL_Init() failed: %s",
            SDL_GetError()
        );
        if(msgbox_on_err)
        {
            SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_ERROR,
                "SDL_Init() failed",
                SDL_GetError(),
                NULL
            );
        }

        return 1;
    }
    SDL_version sdl_version;
    SDL_version sdl_version_linked;
    SDL_VERSION(&sdl_version);
    SDL_GetVersion(&sdl_version_linked);;
    SDL_LogInfo(
        SDL_LOG_CATEGORY_APPLICATION,
        "[SYS] SDL_Init() success\n"
        "SDL Info:\n"
        "  Version %d.%d.%d\n"
        "  Runtime Version: %d.%d.%d",
        VERSION_NUMBER_2_ARG(sdl_version),
        VERSION_NUMBER_2_ARG(sdl_version_linked)
    );

    if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG) == 0)
    {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "[SYS] Mix_Init() failed: %s",
            SDL_GetError()
        );
        if(msgbox_on_err)
        {
            SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_ERROR,
                "Mix_Init() failed",
                SDL_GetError(),
                NULL
            );
        }
        SDL_Quit();

        return 1;
    }

    SDL_version mixer_version;
    const SDL_version* mixer_version_linked;
    MIX_VERSION(&mixer_version);
    mixer_version_linked = Mix_Linked_Version();
    SDL_LogInfo(
        SDL_LOG_CATEGORY_APPLICATION,
        "[SYS] Mix_Init() success\n"
        "Mixer Info:\n"
        "  Version %d.%d.%d\n"
        "  Runtime Version: %d.%d.%d",
        VERSION_NUMBER_2_ARG(mixer_version),
        VERSION_NUMBER_2_ARG(*mixer_version_linked)
    );

    if(IMG_Init(IMG_INIT_PNG) == 0)
    {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "[SYS] IMG_Init() failed: %s",
            IMG_GetError()
        );
        if(msgbox_on_err)
        {
            SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_ERROR,
                "IMG_Init() failed",
                IMG_GetError(),
                NULL
            );
        }
        Mix_Quit();
        SDL_Quit();

        return 1;
    }

    SDL_version image_version;
    const SDL_version* image_version_linked;
    SDL_IMAGE_VERSION(&image_version);
    image_version_linked = IMG_Linked_Version();
    SDL_LogInfo(
        SDL_LOG_CATEGORY_APPLICATION,
        "[SYS] IMG_Init() success\n"
        "Image Info:\n"
        "  Version %d.%d.%d\n"
        "  Runtime Version: %d.%d.%d",
        VERSION_NUMBER_2_ARG(image_version),
        VERSION_NUMBER_2_ARG(*image_version_linked)
    );

    return 0;
}

void SRSCALL SR_SYS_QuitSDL(void)
{
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

int SRSCALL SR_SYS_InitGL()
{
    glewExperimental = GL_TRUE;
    GLenum glew_state = glewInit();
    if(glew_state != GLEW_OK)
    {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "[SYS] glewInit() failed  with %ud - %s",
            glew_state,
            (const char*)glewGetErrorString(glew_state)
        );

        return (int)glew_state;
    }

    SDL_LogInfo(
        SDL_LOG_CATEGORY_APPLICATION,
        "[SYS] glewInit() succeeded\n"
        "GLEW Info:\n"
        "  Version: %s",
        (const char*)glewGetString(GLEW_VERSION)
    );

    return 0;
}
