//
//  texture.h
//  glfw
//
//

#ifndef __GLFW__TEXTURE__
#define __GLFW__TEXTURE__

#include <memory>
#include "Rclib/Core/Core.h"
#include "Rclib/Graphics/GraphicsCore.h"

namespace rc {
namespace graphics {

/* -------------------------------------------------- */
class TextureBase
/* -------------------------------------------------- */
{
public:
    TextureBase();
    TextureBase(u32 width, u32 height, const PixelFormat& pixelFormat);
    virtual ~TextureBase();

    // ------------------------------
    // 生成
    // ------------------------------
    // 空のテクスチャ作成
    bool create(u32 width, u32 height, const PixelFormat& pixelFormat);
    void destroy();

    // ------------------------------
    // アタッチ
    // ------------------------------
    void bind() const;
    void unbind() const;

    // ------------------------------
    // パラメータ
    // ------------------------------
    u32 width() const
    {
        return width_;
    };
    u32 height() const { return height_; }
    virtual boolean isValid() { return (0 < texture_); }

    // ------------------------------
    // 操作
    // ------------------------------
    void writeImage(u32 x, u32 y, u32 width, u32 height,
                    const PixelFormat& pixelFormat, void* data);

    // ------------------------------
    // テクスチャステータス設定
    // ------------------------------
    void setWrapModeS(const TextureWrap& mode);
    void setWrapModeT(const TextureWrap& mode);
    // 拡大時の補完処理
    void setMagFilterMode(const TextureMipmap& mode);
    // 縮小時の補完処理
    void setMinFilterMode(const TextureMipmap& mode);

private:
    u32 texture_;
    u32 width_;
    u32 height_;
};
typedef std::shared_ptr<TextureBase> Texture;
}
}

#endif /* defined(__glfw__texture__) */
