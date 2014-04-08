//
//  vertexArrayObject.cpp
//  glfw
//
//

#include "Rclib/Graphics/GraphicsCore.h"
#include "Rclib/Graphics/VertexArrayObject.h"

namespace rc {
namespace graphics {

VertexArrayObject::VertexArrayObject() : arrayObject_(0)
{
    glGenVertexArrays(1, &arrayObject_);
    glBindVertexArray(arrayObject_);
}

VertexArrayObject::~VertexArrayObject()
{
    if (0 < arrayObject_) {
        glDeleteVertexArrays(1, &arrayObject_);
        arrayObject_ = 0;
    }
}

void VertexArrayObject::bind() { glBindVertexArray(arrayObject_); }

void VertexArrayObject::unbind() { glBindVertexArray(0); }
}
}
