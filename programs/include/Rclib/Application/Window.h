/*
 *  @file    Application/Window.h
 *  @date    2014/04/06
 *  @author  
 *  @brief   
 */

#ifndef __RCLIB_WINDOW_H__
#define __RCLIB_WINDOW_H__

#include "Rclib/Core/Core.h"

namespace rc {
    
    /* ================================================== */
    class Window
    /* ================================================== */
    {
    private:
        GLFWwindow *window_;
    public:
        Window();
        virtual ~Window();
        
        bool create(u32 width, u32 height, const char *name);
        void destroy();
        
        void present();

        bool isClosed();
    };
}

#endif // __FILENAME__H__


