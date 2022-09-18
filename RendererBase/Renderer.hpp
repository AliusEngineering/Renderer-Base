#pragma once

#include "cstdint"

#include "unordered_map"
#include "string"
#include "functional"

#include "memory"

namespace Alius {

    class Renderer {
    public:
        virtual ~Renderer() = default;

        // Initialize renderer infrastructure, such as windowing system
        virtual void Init() = 0;

        virtual void BeginFrame(/* all the possible parameters: cameras, scene metadata, etc. */) = 0;

        virtual void
        Draw(uint32_t vertexCount, uint32_t firstVertex, uint32_t instanceCount = 1, uint32_t firstInstance = 0) = 0;
        // All the other overloads for different draw metadata
        // ...

        virtual void EndFrame() = 0;

    };

    using RendererModuleCreator = std::function<std::unique_ptr<Renderer>()>;

    /**
     * Append your module to this map for it to be recognizable by Alius at runtime.
     * @tparam key Your module identifier.
     * @tparam value Function that returns a unique_ptr of your module. (return type
     * should be unique_ptr<Renderer>)
     */
    std::unordered_map <std::string, RendererModuleCreator> s_RendererModules{};

}
