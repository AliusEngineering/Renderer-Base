#pragma once

#include "ObjectsBase.hpp"

namespace Alius {

class Triangle : public RendererObjectBase
{
public:
  Triangle() = default;
  Triangle(ObjectData data);

  ObjectData GetData() const override { return m_Data; }

  uint32_t GetVerticesCount() override { return m_Data.GetVerticesCount(); }
  uint32_t GetVerticesSize() override { return m_Data.GetVerticesSize(); }

  uint32_t GetIndicesSize() const { return m_Data.GetIndicesSize(); }
  uint32_t GetIndicesCount() const { return m_Data.GetIndicesCount(); }

private:
  ObjectData m_Data;
};

}
