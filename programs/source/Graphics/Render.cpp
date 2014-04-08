//
//  render.cpp
//  glfw
//
//

#include "Rclib/Graphics/GraphicsCore.h"
#include "Rclib/Graphics/Render.h"
#include "Rclib/Graphics/Shader.h"

namespace rc {
namespace graphics {
Render::Render() {}

Render::~Render() {}

void Render::initialize(u32 width, u32 height) {}

void Render::terminate() {}

void Render::drawArrays(u32 primitiveType, u32 startOffset, u64 vertexCount)
{
    glDrawArrays(primitiveType, startOffset, static_cast<u32>(vertexCount));
}


}
}
