#ifndef BAGIEL_RENDERER_HPP
#define BAGIEL_RENDERER_HPP

#include <cstdint>
#include <vector>

#include <Color.hpp>
#include <Vector2.hpp>
#include <Vertex.hpp>
#include <Rectangle.hpp>

namespace bgl {

    class Renderer {
    public:
        Renderer();
        virtual ~Renderer();
        void addData(const Rectangle& rect);
        void renderData();
        void clearData();
    private:
        uint32_t m_vao;
        uint32_t m_vbo;
        uint32_t m_ebo;
        size_t m_elementCount;
        std::vector<Vertex> m_vertices;
    };

} // bgl

#endif //BAGIEL_RENDERER_HPP
