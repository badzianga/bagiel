#include <Renderer.hpp>

#include <glad/glad.h>

#include <iostream>

namespace bgl {

    Renderer::Renderer() : m_vao(0), m_vbo(0), m_ebo(0), m_elementCount(0) {
        const size_t maxQuadCount = 1024;
        const size_t maxVertexCount = maxQuadCount * 4;
        const size_t maxIndexCount = maxQuadCount * 6;

        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, (long)(maxVertexCount * sizeof(Vertex)), nullptr, GL_DYNAMIC_DRAW);

        uint32_t indices[maxIndexCount];
        size_t offset = 0;
        for (size_t i = 0; i < maxIndexCount; i += 6) {
            indices[i] = offset;
            indices[i + 1] = 1 + offset;
            indices[i + 2] = 2 + offset;

            indices[i + 3] = 2 + offset;
            indices[i + 4] = 3 + offset;
            indices[i + 5] = 1 + offset;

            offset += 4;
        }


        glGenBuffers(1, &m_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(bgl::Vertex), (const void*)offsetof(bgl::Vertex, position));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(bgl::Vertex), (const void*)offsetof(bgl::Vertex, color));
        glEnableVertexAttribArray(1);
    };

    Renderer::~Renderer() {
        glDeleteBuffers(1, &m_ebo);
        glDeleteBuffers(1, &m_vbo);
        glDeleteVertexArrays(1, &m_vao);
    }

    void Renderer::addData(const Rectangle& rect) {
        m_vertices.insert(m_vertices.end(), &rect.m_vertices[0], &rect.m_vertices[4]);
        m_elementCount += 6;
    }

    void Renderer::renderData() {
        glBufferSubData(GL_ARRAY_BUFFER, 0, (long)(m_vertices.size() * sizeof(Vertex)), m_vertices.data());
        glDrawElements(GL_TRIANGLES, (int)m_elementCount, GL_UNSIGNED_INT, nullptr);
    }

    void Renderer::clearData() {
        m_vertices.clear();
        m_elementCount = 0;
    }

} // bgl
