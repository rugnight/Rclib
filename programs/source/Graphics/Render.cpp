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

bool Render::initialize()
{
    // ------------------------------
    // glew
    // glfwMakeContextCurrent(window_); の後でないと失敗する。
    // ------------------------------
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit()) {
        printf("glewInit failed.\n");
        return false;
    }
    return true;
}

void Render::terminate() {}

void Render::drawArrays(u32 primitiveType, u32 startOffset, u64 vertexCount)
{
    glDrawArrays(primitiveType, startOffset, static_cast<u32>(vertexCount));
}


void Render::clear(const ClearOptions& clear_options)
{
    std::uint8_t buffer_flag = 0;
    if ((clear_options & ClearOptions::Color) == ClearOptions::Color) {
        buffer_flag |= GL_COLOR_BUFFER_BIT;
    }
    if ((clear_options & ClearOptions::Stencil) == ClearOptions::Stencil) {
        buffer_flag |= GL_STENCIL_BUFFER_BIT;
    }
    if ((clear_options & ClearOptions::Depth) == ClearOptions::Depth) {
        buffer_flag |= GL_DEPTH_BUFFER_BIT;
    }

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(buffer_flag);
}

}
}
