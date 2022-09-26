# Alius Renderer Base

## Quick start

To write your own renderer implementation simply include the `Renderer.hpp` header file in your project however is good
for you and derive your class from `Renderer`.

## Runtime support

To be able to use your renderer at runtime, Renderer Base has unordered map with keys being strings and values being
functions to instantiate and retrieve your renderer implementation (return value is base class though).

## Implementation requirements

Each Renderer component has well-documented pure virtual functions so you should be able to understand their purposes.

# Renderer objects

Renderer objects are a new concept to Alius. They are not extendable (at least not modular, like renderer itself) and
actually are part of implementation requirements. Any renderer module should override functions that accept different
renderer objects and can make use of the contained data (e.g., position, color, texture data).