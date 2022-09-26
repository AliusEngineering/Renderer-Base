#pragma once

namespace Alius {

class Window
{
public:
  virtual ~Window() = default;

  // When the window is closed, this should return true
  virtual bool ShouldClose() = 0;

  // Your custom logic may be usd here: you can flag window as inactive if it's
  // minimized, lost focus, etc.
  virtual bool IsActive() = 0;

  // Usually polls and captures events
  virtual void OnUpdate() = 0;
};

}
