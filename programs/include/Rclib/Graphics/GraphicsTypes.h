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

enum class ClearOptions : u8 {
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
}

#endif  // __FILENAME__H__

