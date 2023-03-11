#pragma once

#include "array"
#include "cstdint"
#include "memory"
#include "utility"
#include "vector"

#include "glm/glm.hpp"

#define STATIC inline static constexpr

namespace Alius {

class ObjectData;

class ObjectImplData
{
public:
  virtual ~ObjectImplData() = default;
};

class RendererObjectBase
{
public:
  virtual ~RendererObjectBase() = default;

  virtual ObjectData GetData() const = 0;

  virtual std::shared_ptr<ObjectImplData> GetImplData() { return m_ImplData; }

  template<class DataT>
  void SetImplData(const DataT& data)
  {
    m_ImplData = std::make_shared<DataT>(data);
  }

  template<class DataT>
  void SetImplData(std::shared_ptr<DataT> data)
  {
    m_ImplData = data;
  }

  virtual uint32_t GetVerticesCount() = 0;
  virtual uint32_t GetVerticesSize() = 0;

  virtual uint32_t GetIndicesSize() const = 0;
  virtual uint32_t GetIndicesCount() const = 0;

protected:
  std::shared_ptr<ObjectImplData> m_ImplData;
};

struct VertexPosition
{
  VertexPosition() = default;

  VertexPosition(float x, float y);
  VertexPosition(float x, float y, float z);
  explicit VertexPosition(const glm::vec2& position);
  explicit VertexPosition(const glm::vec3& position);

  glm::vec3 Position{};
};

struct Vertex
{
  Vertex() = default;
  Vertex(const VertexPosition& position);

  STATIC uint32_t GetStride() { return sizeof(Vertex); }

  STATIC uint32_t PositionOffset() { return offsetof(Vertex, Position); }
  STATIC uint32_t ColorOffset() { return offsetof(Vertex, Color); }
  STATIC uint32_t TexIndexOffset() { return offsetof(Vertex, TexIndex); }
  STATIC uint32_t TexCoordOffset() { return offsetof(Vertex, TexCoord); }

  VertexPosition Position;
  glm::vec4 Color{ 0.0f };

  // Texture slot 0 is supposed to be occupied with "color" texture, which is
  // equivalent to basically not having one.
  uint32_t TexIndex = 0;
  glm::vec2 TexCoord{ 0.0f };
};

struct ObjectData
{
  ObjectData() = default;
  ObjectData(std::initializer_list<VertexPosition> vertices);

  void SetIndices(std::vector<uint32_t> indices);

  void SetColor(const glm::vec3& color);
  void SetColor(const glm::vec4& color);

  void SetVertexColor(uint32_t vertexIndex, const glm::vec3& color);
  void SetVertexColor(uint32_t vertexIndex, const glm::vec4& color);

  void SetVertexTexIndex(uint32_t vertexIndex, uint32_t index);
  void SetVertexTexCoord(uint32_t vertexIndex, const glm::vec2& coord);

  STATIC uint32_t GetStride() { return sizeof(Vertex); }

  uint32_t GetVerticesCount();
  uint32_t GetVerticesSize();
  Vertex* GetVerticesPointer();
  const Vertex* GetVerticesPointer() const;

  uint32_t GetIndicesCount() const;
  uint32_t GetIndicesSize() const;
  uint32_t* GetIndicesPointer();
  const uint32_t* GetIndicesPointer() const;

private:
  std::vector<Vertex> m_Vertices;
  std::vector<uint32_t> m_Indices;
};

}
