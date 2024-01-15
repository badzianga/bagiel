#include <Renderer.hpp>

#include <glad/glad.h>

namespace bgl {

    VertexArray::VertexArray() : m_id(0) {
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_id);
    }

    void VertexArray::bind() const {
        glBindVertexArray(m_id);
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }

    // ------------------------------------------------------------------------

    VertexBuffer::VertexBuffer(const void *data, uint32_t size) : m_id(0) {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, (long)size, data, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_id);
    }

    void VertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    // ------------------------------------------------------------------------

    ElementBuffer::ElementBuffer(const uint32_t *data, uint32_t count) : m_id(0), m_count(count) {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (long)(count * sizeof(uint32_t)), data, GL_STATIC_DRAW);
    }

    ElementBuffer::~ElementBuffer() {
        glDeleteBuffers(1, &m_id);
    }

    void ElementBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void ElementBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    uint32_t ElementBuffer::getCount() const {
        return m_count;
    }

} // bgl
