cmake_minimum_required(VERSION 3.16)
project(RendererBase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE RendererBaseSources CONFIGURE_DEPENDS "RendererBase/**")
message(STATUS "[RendererBase] Sources are: ${RendererBaseSources}")

if (NOT TARGET RendererBase)
    add_library(RendererBase STATIC ${RendererBaseSources})
endif ()

target_precompile_headers(RendererBase PUBLIC "RendererBase/RendererBasePch.hpp")

target_include_directories(RendererBase PUBLIC "WindowBase")

add_subdirectory("3rd-party/glm")
target_link_libraries(RendererBase PUBLIC glm::glm)

target_link_libraries(RendererBase INTERFACE WindowBase)
