/*
 *  @file    
 *  @date    
 *  @author  
 *  @brief   
 */

#include "Rclib/Application/Window.h"

//========================================================//
// local define                                           //
//========================================================//
//========================================================//
// type section                                           //
//========================================================//
//========================================================//
// extern data                                            //
//========================================================//
//========================================================//
// static data                                            //
//========================================================//
//========================================================//
// extern prototype                                       //
//========================================================//
//========================================================//
// static prototype                                       //
//========================================================//
//========================================================//
// program section                                        //
//========================================================//

namespace rc {

/* ================================================== */
// class Window
/* ================================================== */
Window::Window()
    : window_(NULL)
{

}
Window::~Window()
{
    destroy();
}

bool Window::create(u32 width, u32 height, const char *name)
{
    destroy();
    window_ = glfwCreateWindow(width, height, name, NULL, NULL);
    if ( !window_ ) {
        destroy();
        return false;
    }

    glfwMakeContextCurrent(window_);

    // ------------------------------
    // glew
    // glfwMakeContextCurrent(window_); の後でないと失敗する。
    // ------------------------------
    glewExperimental = GL_TRUE;
    if ( GLEW_OK != glewInit() ) {
        printf("glewInit failed.\n");
        return false;
    }

    glfwSwapInterval(1);

    return true;
}

void Window::destroy()
{
    if ( window_) {
        glfwDestroyWindow(window_);
    }
}

void Window::present()
{
    glfwSwapBuffers(window_);
    glfwPollEvents();
}


bool Window::isClosed()
{
    return glfwWindowShouldClose(window_);
}

}
