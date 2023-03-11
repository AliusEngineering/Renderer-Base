cmake_minimum_required(VERSION 3.16)
project(RendererBase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE Sources CONFIGURE_DEPENDS "src/**/*.cpp")
file(GLOB_RECURSE Headers CONFIGURE_DEPENDS "include/**/*.hpp")
message(STATUS "[RendererBase] Sources are: ${Sources}")
message(STATUS "[RendererBase] Headers are: ${Headers}")

if (NOT TARGET RendererBase)
    add_library(RendererBase STATIC ${Sources} ${Headers})
endif ()

target_include_directories(RendererBase PUBLIC "include")
target_precompile_headers(RendererBase PRIVATE "include/RendererBasePch.hpp")

if (NOT TARGET glm::glm)
    add_subdirectory("3rd-party/glm")
endif ()

target_link_libraries(RendererBase PUBLIC glm::glm)
