/*
 *  @file    
 *  @date    
 *  @author  
 *  @brief   
 */

#ifndef __RCLIB_ASSERT_H__
#define __RCLIB_ASSERT_H__

#include <iostream>
#include <cassert>

inline void ReportAssertionFailure(char const* expression,
        char const* filename, int line, char const* function)
{
    // notes: std::cerr in <iostream>
    std::cerr << "Assertion failed: " << expression << ", function "
        << function << ", file " << filename << ", line " << line << ".\n";
}

inline void RuntimeAssertion(char const* expression, char const* filename, int line)
{
    ReportAssertionFailure(expression, filename, line, "(unknown)");
    assert(false);
}

#if defined(DEBUG)
#   // Debug mode
#   define RC_DEBUGBREAK() __asm { int 3 }
#   define RC_ASSERT(expression) RC_ASSERT_MESSAGE(expression, "RC_ASSERT")
#   define RC_ASSERT_MESSAGE(expression, message) \
    do {\
        if (!(expression)) {\
            assert(message && expression) \
            RC_DEBUGBREAK(); \
        }\
    } while(false)
#else //!defined(DEBUG) || defined(NDEBUG)
#   // Release mode
#   define RC_ASSERT(expression)
#   define RC_ASSERT_MESSAGE(expression, message)
#endif

#endif // __FILENAME__H__
