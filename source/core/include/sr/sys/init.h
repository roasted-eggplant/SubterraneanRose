/**
 * @file init.h
 * @author HenryAWE
 * @brief Initializaton
 */

#ifndef SROSE_SYS_init_h_
#define SROSE_SYS_init_h_


#include <sr/sys/macros.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize SDL and other SDL library
 * 
 * @param msgbox_on_err Show message box on error
 * @return int Zero for success, other value means an error occurred
 */
int SRSCALL SR_SYS_InitSDL(int msgbox_on_err);

/**
 * @brief Deinitialize SDL and other SDL library
 */
void SRSCALL SR_SYS_QuitSDL(void);

/**
 * @brief Initialize OpenGL render context
 * 
 * @warning MUST BE CALLED FROM A THREAD WITH GL CONTEXT!!!
 * 
 * @return int Zero for success, other value means an error occurred
 */
int SRSCALL SR_SYS_InitGL(void);

/**
 * @brief Initialize everything
 * 
 * @param msgbox_on_err Show message box on error
 * @return int Zero for success, other value means an error occurred
 */
int SRSCALL SR_SYS_Init(int argc, char* argv[], int msgbox_on_error);

/**
 * @brief Deinitialize everything
 */
void SRSCALL SR_SYS_Quit(void);

#ifdef __cplusplus
}
#endif

#endif