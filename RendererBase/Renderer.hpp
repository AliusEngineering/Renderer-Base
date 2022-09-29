#pragma once

#include "RendererBasePch.hpp"

namespace Alius {

class Renderer
{
public:
  virtual ~Renderer() = default;

  virtual Ref<Window> GetWindow() const = 0;

  template<class ObjT, class ObjDataT>
  Ref<ObjT> CreateObject(const ObjDataT& objectData)
  {
    auto newObj = std::make_shared<ObjT>(objectData);
    CreateObjectImpl(newObj);
    return newObj;
  }

  template<class ObjT>
  bool DestroyObject(Ref<ObjT> obj)
  {
    DestroyObjectImpl(obj);
  }

  virtual void BeginFrame(/* cameras, scene metadata, etc. */) = 0;

  virtual void Draw(Ref<RendererObjectBase> object) = 0;

  virtual void EndFrame() = 0;

  /**
   * Append your module to this map for it to be recognizable by Alius at
   * runtime.
   * @tparam key Your module identifier.
   * @tparam value Function that returns a shared_ptr of your module. (return
   * type should be shared_ptr<Renderer>). Is of type
   * std::function<std::shared_ptr<Renderer>(size_t, size_t, const char*)>.
   * Should accept size_t width, size_t height and const char* title for
   * underlying window creation.
   */
  inline static std::unordered_map<
    std::string,
    std::function<Ref<Renderer>(size_t, size_t, const char*)>>
    s_RendererModules{};

private:
  /*
   * Templated method implementation. On Renderer object creation you would
   * probably want to load vertex/index data to the GPU and somehow synchronize
   * object creation with your Renderer implementation pipeline: this is what
   * this method is for.
   */
  virtual void CreateObjectImpl(Ref<RendererObjectBase> object) = 0;

  virtual void DestroyObjectImpl(Ref<RendererObjectBase> object) = 0;
};

}
