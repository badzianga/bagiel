#ifndef BAGIEL_RENDERER_HPP
#define BAGIEL_RENDERER_HPP

#include <cstdint>

#include <Color.hpp>
#include <Vector2.hpp>

namespace bgl {

    struct Vertex {
        Vector2 position;
        Color color;
        //Vector2 textureCoord;
        //uint32_t textureId;
    };

    class VertexArray {
    public:
        VertexArray();
        virtual ~VertexArray();
        void bind() const;
        void unbind() const;
    private:
        uint32_t m_id;
    };

    class VertexBuffer {
    public:
        VertexBuffer(const void* data, uint32_t size);
        virtual ~VertexBuffer();
        void bind() const;
        void unbind() const;
    private:
        uint32_t m_id;
    };

    class ElementBuffer {
    public:
        ElementBuffer(const uint32_t* data, uint32_t count);
        virtual ~ElementBuffer();
        void bind() const;
        void unbind() const;
        [[nodiscard]] uint32_t getCount() const;
    private:
        uint32_t m_id;
        uint32_t m_count;
    };

    class Renderer {

    };

} // bgl

#endif //BAGIEL_RENDERER_HPP
