//
//  texture.cpp
//

#include "Rclib/Graphics/GraphicsCore.h"
#include "Rclib/Graphics/Texture.h"

namespace rc {
namespace graphics {
TextureBase::TextureBase() : texture_(0), width_(0), height_(0) {}

TextureBase::TextureBase(u32 width, u32 height, const PixelFormat& pixelFormat)
    : texture_(0), width_(0), height_(0)
{
    create(width, height, pixelFormat);
}

TextureBase::~TextureBase()
{
    printf("destroy texture [%d]\n", texture_);
    destroy();
}

bool TextureBase::create(u32 width, u32 height, const PixelFormat& pixelFormat)
{
    // 生成
    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);

    // 領域を確保
    glTexImage2D(GL_TEXTURE_2D, 0, pixelFormat.gl, width, height, 0,
                 pixelFormat.gl, GL_UNSIGNED_BYTE, nullptr);

    // パラメータの保持
    width_ = width;
    height_ = height;

    return true;
}

void TextureBase::writeImage(u32 x, u32 y, u32 width, u32 height,
                             const PixelFormat& pixelFormat, void* data)
{
}

/*!
 @brief テクスチャの破棄
 */
void TextureBase::destroy()
{
    if (0 < texture_) {
        glDeleteTextures(1, &texture_);
    }
    width_ = 0;
    height_ = 0;
}

void TextureBase::bind() const { glBindTexture(GL_TEXTURE_2D, texture_); }

void TextureBase::unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

// テクスチャステータス設定
void TextureBase::setWrapModeS(const TextureWrap& mode)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mode);
}

void TextureBase::setWrapModeT(const TextureWrap& mode)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mode);
}

void TextureBase::setMagFilterMode(const TextureMipmap& mode)
{
    // デフォルトのパラメータによる不具合
    //      テクスチャがミップマップを持たない場合，デフォルトのパラメータでは正常に描画ができない場合がある。
    //      そのときは GL_TEXTURE_MAX_LEVEL を0にしたり，GL_TEXTURE_MIN_FILTER
    //      を
    //      ミップマップを使わないもの( GL_NEAREST や GL_LINEAR
    //      )にすると正常に描画できる
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mode);
}

void TextureBase::setMinFilterMode(const TextureMipmap& mode)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mode);
}
}
}
