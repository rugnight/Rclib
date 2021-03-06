/*
 *  @file    
 *  @date    
 *  @author  
 *  @brief   
 */

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

//#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "Rclib/Rclib.h"

using namespace rc::math;

int main(int argc, const char** argv)
{
    RclibInitialize();

    Vector3 vec0(1.0f, 2.0f, 3.0f);
    Vector3 vec1(3.0f, 2.0f, 1.0f);
    vec0 = vec0 + vec1;
    printf("%f, %f, %f\n", vec0.x, vec0.y, vec0.z);

    rc::Window window;
    if  ( false == window.create(300, 300, "test") ) {
        printf("window create failed.");
        return 0;
    }

    if ( false == rc::graphics::Render::self().initialize() ) {
        printf("render initialize failed.");
    }

    while (!window.isClosed()) {
        rc::graphics::Render::self().clear(rc::ClearOptions::Color);
        window.present();
    }

    window.destroy();

    printf("hello!!");

    RclibTerminate();

    return 0;
}
