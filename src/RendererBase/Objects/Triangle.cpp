#include "RendererBase/Objects/Triangle.hpp"

namespace Alius {

Triangle::Triangle(ObjectData data)
  : m_Data(std::move(data))
{
}

}
