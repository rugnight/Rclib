solution "rclib"
   configurations { "Debug", "Release" }
   platforms { "native" }
   -- platforms { "x64" }
   --platforms { "universal64" }
   --platforms { "universal32" }
   --platforms { "Universal" }
   --platforms { "x32" }

   -- ===================================== --
   -- Project "rclib"                      --
   -- ===================================== --
   project "rclib"
      kind "StaticLib" -- WindowedApp or ColsoleApp or StaticLib
      language "C++"

      files { 
          "./programs/include/**.h",
          "./programs/source/**.cpp",
      }

      includedirs { -- -I/usr/include/openglに相当
          "./programs/include",
          "./third_party/include",
          "./third_party/GLFW/include/",
          "./third_party/GLEW/include/",

          "/System/Library/Frameworks/OpenGL.framework/Headers/",
      }
      libdirs { -- -L/usr/lib/w32apiに相当
          "./third_party/GLFW/lib/",
          "./third_party/GLEW/lib/",

          "/System/Library/Frameworks/OpenGL.framework/Libraries/",
      }
      links { -- -lopengl32 -lglu32 -lglut32 に相当
          "GL", 
          "GLU", 
          "GLEW",
          "glfw3",
      }
      linkoptions {
          "-framework Carbon -framework OpenGL",
      }
      buildoptions {
          "-std=c++11",
          "-stdlib=libc++",
      }

      configuration "Debug"
         defines { "_DEBUG" } -- -DDEBUG
         flags   { "Symbols" }
         targetdir "build/rclib/debug"
         targetname "rclib"

      configuration "Release"
         defines { "_NDEBUG" } -- -NDEBUG
         flags   { "Optimize" }
         targetdir "build/rclib/release"
         targetname "rclib"

   -- ===================================== --
   -- Project "test"                      --
   -- ===================================== --
   project "test"
      kind "ConsoleApp" -- WindowedApp or ColsoleApp
      language "C++"
      files { 
          "test/**.h",
          "test/**.cpp",
      }
      includedirs { -- -I/usr/include/openglに相当
          "programs/include/",
      }
      libdirs { -- -L/usr/lib/w32apiに相当
          "./third_party/GLFW/lib/",
          "./third_party/GLEW/lib/",

          "/System/Library/Frameworks/OpenGL.framework/Libraries/",
      }
      links { -- -lopengl32 -lglu32 -lglut32 に相当
          "GL",
          "GLU",
          "GLEW",
          "glfw3",
          "rclib",
      }
      linkoptions {
      }
      buildoptions {
          "-std=c++11",
          "-stdlib=libc++",
      }
      configuration "Debug"
         defines { "_DEBUG" } -- -DDEBUG
         flags   { "Symbols" }
         targetdir "build/test/debug"
         targetname "test"

      configuration "Release"
         defines { "_NDEBUG" } -- -NDEBUG
         flags   { "Optimize" }
         targetdir "build/test/release"
         targetname "test"
