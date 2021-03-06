/**
 * @file program_name.cpp
 * @author HenryAWE
 * @brief Get the full path to the program executable
 */

#include <sr/util/program_name.hpp>
#include <string.h>
#include <SDL_platform.h>
#include <SDL_syswm.h>
#ifndef __WINDOWS__
#   include <unistd.h>
#endif


namespace srose::util
{
    const char* SRSCALL GetProgramName()
    {
    #ifdef __WINDOWS__
        static CHAR buffer[MAX_PATH];
        GetModuleFileNameA(NULL, buffer, MAX_PATH);

        return buffer;
    #elif defined __LINUX__
        static char buffer[512];
        int ret = readlink("/proc/self/exe", buffer, 512);
        if(ret<0||ret>512)
            return ""; // failed

        return buffer;
    #else
        static char buffer[512];
        getcwd(buffer, 512);
        strcat(buffer, "/srose-exec");

        return buffer;
    #endif
    }
} // namespace srose::util
