#include "RendererBase/Objects/ObjectsBase.hpp"

namespace Alius {

VertexPosition::VertexPosition(float x, float y)
  : Position(x, y, 1.0f)
{
}

VertexPosition::VertexPosition(float x, float y, float z)
  : Position(x, y, z)
{
}

VertexPosition::VertexPosition(const glm::vec2& position)
  : Position(position, 1.0f)
{
}

VertexPosition::VertexPosition(const glm::vec3& position)
  : Position(position)
{
}

Vertex::Vertex(const VertexPosition& position)
  : Position(position)
{
}

ObjectData::ObjectData(std::initializer_list<VertexPosition> vertices)
  : m_Vertices(vertices.begin(), vertices.end())
{
}

void
ObjectData::SetIndices(std::vector<uint32_t> indices)
{
  m_Indices = std::move(indices);
}

void
ObjectData::SetColor(const glm::vec3& color)
{
  SetColor({ color, 1.0f });
}

void
ObjectData::SetColor(const glm::vec4& color)
{
  for (auto& vertex : m_Vertices) {
    vertex.Color = glm::vec4(color);
  }
}

void
ObjectData::SetVertexColor(uint32_t vertexIndex, const glm::vec3& color)
{
  SetVertexColor(vertexIndex, { color, 1.0f });
}

void
ObjectData::SetVertexColor(uint32_t vertexIndex, const glm::vec4& color)
{
  m_Vertices[vertexIndex].Color = color;
}

void
ObjectData::SetVertexTexIndex(uint32_t vertexIndex, uint32_t index)

{
  m_Vertices[vertexIndex].TexIndex = index;
}

void
ObjectData::SetVertexTexCoord(uint32_t vertexIndex, const glm::vec2& coord)

{
  m_Vertices[vertexIndex].TexCoord = coord;
}

uint32_t
ObjectData::GetVerticesCount()
{
  return m_Vertices.size();
}

uint32_t
ObjectData::GetVerticesSize()
{
  return GetVerticesCount() * sizeof(Vertex);
}

Vertex*
ObjectData::GetVerticesPointer()
{
  return m_Vertices.data();
}

const Vertex*
ObjectData::GetVerticesPointer() const
{
  return m_Vertices.data();
}

uint32_t
ObjectData::GetIndicesCount() const
{
  return m_Indices.size();
}

uint32_t
ObjectData::GetIndicesSize() const
{
  return GetIndicesCount() * sizeof(uint32_t);
}

uint32_t*
ObjectData::GetIndicesPointer()
{
  return m_Indices.data();
}

const uint32_t*
ObjectData::GetIndicesPointer() const
{
  return m_Indices.data();
}

}
