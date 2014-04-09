/*
 *  @file    
 *  @date    
 *  @author  
 *  @brief   
 */

#include "Rclib/Graphics/GraphicsTypes.h"

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

ClearOptions& operator|=(ClearOptions& a, ClearOptions b) 
{
    a = a | b;
    return a;
}

ClearOptions& operator&=(ClearOptions& a, ClearOptions b) 
{
    a = a & b;
    return a;
}

}
