# Alius Renderer Base

## Quick start

To write your own renderer implementation simply include the `Renderer.hpp` header file in your project however is good
for you and derive your class from `Renderer`.

## Runtime support

To be able to use your renderer at runtime, Renderer Base has unordered map with keys being strings and values being
functions to instantiate and retrieve your renderer implementation (return value is base class though).

## Implementation requirements

Renderer Base has methods that are purely virtual and are required to be implemented. Those are:

- `BeginFrame()` - which is for passing scene metadata, such as cameras and so on.
- `DrawDraw(uint32_t vertexCount, uint32_t firstVertex, uint32_t instanceCount = 1, uint32_t firstInstance = 0)` - which
  is for drawing certain amount of vertices and their instances, as well as to start from a specific one (first
  vertex/instance).
- `EndFrame()` - which is for, theoretically, optimizing gathered data and finally rendering it on GPU.