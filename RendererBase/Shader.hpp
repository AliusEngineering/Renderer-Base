#pragma once

#include <string_view>

namespace Alius {

class Shader
{
public:
  virtual ~Shader() = default;

  // Create shader object from source shading language (GLSL, HLSL, etc.)
  virtual void CreateFromSource(std::string_view filepath) = 0;

  // Create shader object from compiled shader file (useful for resource
  // caching)
  virtual void CreateFromCompiled(std::string_view filepath) = 0;

  // Use the shader for ongoing draw calls
  virtual void Bind() = 0;

  // Do not use the shader for ongoing draw calls
  virtual void Unbind() = 0;
};

}
