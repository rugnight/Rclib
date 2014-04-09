//
//  render.h
//  glfw
//
//

#ifndef __RC__RENDER__
#define __RC__RENDER__

#include "Rclib/Core/Core.h"
#include "Rclib/Graphics/GraphicsTypes.h"

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

    bool initialize();
    void terminate();

    void drawArrays(u32 primitiveType, u32 startOffset, u64 vertexCount);

    void drawQuad();

    void clear(const ClearOptions& clear_options);
};
}
}

#endif /* defined(__glfw__render__) */
