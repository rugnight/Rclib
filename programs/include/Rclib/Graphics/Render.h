//
//  render.h
//  glfw
//
//

#ifndef __RC__RENDER__
#define __RC__RENDER__

#include "Rclib/Core/Core.h"

namespace rc {
namespace graphics {

/* -------------------------------------------------- */
class Render
/* -------------------------------------------------- */
{
public:
    Render();
    virtual ~Render();

    static Render& self()
    {
        static Render render;
        return render;
    }

    void initialize(u32 width, u32 height);
    void terminate();

    void drawArrays(u32 primitiveType, u32 startOffset, u64 vertexCount);

    void drawQuad();
};
}
}

#endif /* defined(__glfw__render__) */
