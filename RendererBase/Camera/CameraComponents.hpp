#pragma once

#include "glm/glm.hpp"

namespace Alius {

struct CameraMatrix
{
  glm::mat4 Model;
  glm::mat4 View;
  glm::mat4 Projection;
};

}