//
//  core.h
//

#ifndef __RCLIB_CORE__
#define __RCLIB_CORE__

#include <stdio.h>
#include <cstdint>

// 基本型
typedef std::int8_t    int8;
typedef std::int16_t   int16;
typedef std::int32_t   int32;
typedef std::int64_t   int64;
typedef std::uint8_t   uint8;
typedef std::uint16_t  uint16;
typedef std::uint32_t  uint32;
typedef std::uint64_t  uint64;
typedef float          float32;
typedef double         float64;
typedef bool           boolean;

// 基本型省略形
typedef int8    s8;
typedef int16   s16;
typedef int32   s32;
typedef int64   s64;
typedef uint8   u8;
typedef uint16  u16;
typedef uint32  u32;
typedef uint64  u64;
typedef float32 f32;
typedef float64 f64;

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW3
#define GLFW_NO_GLU
#define GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>

#include <OpenGL/glext.h>
#include <OpenGL/gl3ext.h>

bool RclibInitialize();
void RclibTerminate();

#endif /* defined(__glfw__core__) */
