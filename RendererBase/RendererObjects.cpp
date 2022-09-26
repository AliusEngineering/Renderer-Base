#include "RendererObjects.hpp"

namespace Alius {

Triangle::TriangleData::TriangleData(const std::array<glm::vec2, 3>& vertices)
  : PositionVertices(vertices)
{
}

Triangle::Triangle(Triangle::TriangleData data)
  : m_Data(data)
{
}

Quad::QuadData::QuadData(const std::array<glm::vec2, 4>& vertices,
                         const std::array<uint32_t, 6>& indices)
  : PositionVertices(vertices)
  , Indices(indices)
{
}

Quad::Quad(Quad::QuadData data)
  : m_Data(data)
{
}

}
