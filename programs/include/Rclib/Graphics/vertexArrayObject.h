//
//  vertexArrayObject.h
//  glfw
//
//

#ifndef __glfw__vertexArrayObject__
#define __glfw__vertexArrayObject__

#include <iostream>
#include "Rclib/Core/Core.h"

namespace rc {
namespace graphics {

/* -------------------------------------------------- */
class VertexArrayObject
/* -------------------------------------------------- */
{
public:
    VertexArrayObject();
    virtual ~VertexArrayObject();

    void bind();
    void unbind();

private:
    u32 arrayObject_;
};
}
}

#endif /* defined(__glfw__vertexArrayObject__) */
