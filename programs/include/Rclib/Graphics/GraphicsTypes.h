/*
 *  @file   Rclib/Graphics/GraphicsTypes.h
 *  @date
 *  @author
 *  @brief
 */

#ifndef __RCLIB_CLEAR_OPTIONS_H__
#define __RCLIB_CLEAR_OPTIONS_H__

#include "Rclib/Core/Core.h"

namespace rc {

enum class ClearOptions : std::uint8_t {
    /// @brief カラーバッファ
    Color = 0x01,
    /// @brief ステンシルバッファ
    Stencil = 0x02,
    /// @brief ディプスバッファ
    Depth = 0x04,
    ColorDepth = (Color | Depth),
    ColorStencil = (Color | Stencil),
    ColorStencilDepth = (Color | Stencil | Depth),
    StencilDepth = (Stencil | Depth),
};

constexpr ClearOptions operator|(ClearOptions a, ClearOptions b)
{
    return static_cast<ClearOptions>(static_cast<std::uint8_t>(a) |
                                     static_cast<std::uint8_t>(b));
}

constexpr ClearOptions operator&(ClearOptions a, ClearOptions b)
{
    return static_cast<ClearOptions>(static_cast<std::uint8_t>(a) &
                                     static_cast<std::uint8_t>(b));
}

ClearOptions& operator|=(ClearOptions& a, ClearOptions b);

ClearOptions& operator&=(ClearOptions& a, ClearOptions b);

}

#endif  // __FILENAME__H__

