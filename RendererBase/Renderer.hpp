#pragma once

#include "WindowBase/Window.hpp"

#include "cstdint"

#include "unordered_map"
#include "string"
#include "functional"

#include "memory"

namespace Alius {

    class Renderer {
    public:
        virtual ~Renderer() = default;

        virtual std::shared_ptr <Window> GetWindow() const = 0;

        virtual void BeginFrame(/* all the possible parameters: cameras, scene metadata, etc. */) = 0;

        virtual void
        Draw(uint32_t vertexCount, uint32_t firstVertex, uint32_t instanceCount, uint32_t firstInstance) = 0;
        // All the other overloads for different draw metadata
        // ...

        virtual void EndFrame() = 0;

    };

    using RendererModuleCreator = std::function<
    std::shared_ptr<Renderer>(size_t, size_t,
    const char*)>;

    /**
     * Append your module to this map for it to be recognizable by Alius at runtime.
     * @tparam key Your module identifier.
     * @tparam value Function that returns a shared_ptr of your module. (return type
     * should be shared_ptr<Renderer>). Is of type std::function<std::shared_ptr<Renderer>(size_t, size_t, const char*)>.
     * Should accept size_t width, size_t height and const char* title for underlying window creation.
     */
    std::unordered_map <std::string, RendererModuleCreator> s_RendererModules{};

}
