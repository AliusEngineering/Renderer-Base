#pragma once

#include "array"
#include "utility"

#include "glm/glm.hpp"

namespace Alius {

class Triangle
{
public:
  struct TriangleData
  {
    TriangleData() = default;
    explicit TriangleData(const std::array<glm::vec2, 3>& vertices);

    std::array<glm::vec2, 3> PositionVertices{};
    glm::vec3 Color{ 1.0f };

    // Texture slot 0 is supposed to be occupied with "color" texture, which is
    // equivalent to basically not having one.
    uint32_t TexIndex = 0;
  };

  Triangle() = default;
  Triangle(TriangleData data);

  TriangleData GetData() const { return m_Data; }

private:
  TriangleData m_Data;
};

class Quad
{
public:
  struct QuadData
  {
    QuadData() = default;
    explicit QuadData(
      const std::array<glm::vec2, 4>& vertices,
      const std::array<uint32_t, 6>& indices = { 0, 1, 2, 1, 2, 3 });

    std::array<glm::vec2, 4> PositionVertices{};
    std::array<uint32_t, 6> Indices{};

    glm::vec3 Color{ 1.0f };

    // Texture slot 0 is supposed to be occupied with "color" texture, which is
    // equivalent to basically not having one.
    uint32_t TexIndex = 0;
  };

  Quad() = default;
  Quad(QuadData data);

  QuadData GetData() const { return m_Data; }

private:
  QuadData m_Data;
};

}