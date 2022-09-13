#pragma once

#include "stdint.h"

#include "unordered_map"
#include "string"
#include "functional"

#include "memory"

namespace Alius {

    class Renderer {
    public:
        virtual void BeginFrame(/* all the possible parameters: cameras, scene metadata, etc. */);

        virtual void
        Draw(uint32_t vertexCount, uint32_t firstVertex, uint32_t instanceCount = 1, uint32_t firstInstance = 0);
        // All the other overloads for different draw metadata
        // ...

        virtual void EndFrame();
    };

    // Append your custom renderer module here with key being any string you would like to name your module.
    std::unordered_map<std::string, std::function<std::unique_ptr<Renderer>()>> s_RendererModules;

}
