# Alius Renderer Base

## Quick start

To write your own renderer implementation simply include the `Renderer.hpp` header file in your project however is good
for you and derive your class from `Renderer`.

## Runtime support

To be able to use your renderer at runtime, Renderer Base has unordered map with keys being strings and values being
functions to instantiate and retrieve your renderer implementation (return value is base class though).

## Implementation requirements

Each Renderer component has well-documented pure virtual functions so you should be able to understand their purposes.