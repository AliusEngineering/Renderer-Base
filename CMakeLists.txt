cmake_minimum_required(VERSION 3.16)
project(RendererBase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE RendererBaseHeaders CONFIGURE_DEPENDS "RendererBase/**")
message(STATUS "[RendererBase] Sources are: ${RendererBaseHeaders}")

add_library(RendererBase INTERFACE)

target_sources(RendererBase INTERFACE
        FILE_SET HEADERS
        FILES
        ${RendererBaseHeaders}
        )