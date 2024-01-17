#include <Shader.hpp>

#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>

namespace bgl {

    Shader::Shader() {
        m_id = glCreateProgram();
    }

    Shader::Shader(const char* vertexPath, const char* fragmentPath) {
        m_id = glCreateProgram();
        compile(vertexPath, fragmentPath);
    }

    Shader::~Shader() {
        glDeleteProgram(m_id);
    }

    void Shader::use() const {
        glUseProgram(m_id);
    }

    void Shader::compile(const char* vertexPath, const char* fragmentPath) {
        std::string vertexShaderString = readFile(vertexPath);
        const char* vertexShaderSource = vertexShaderString.c_str();
        uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        checkCompileErrors(vertexShader, "VERTEX");

        std::string fragmentShaderString = readFile(fragmentPath);
        const char* fragmentShaderSource = fragmentShaderString.c_str();
        uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        checkCompileErrors(fragmentShader, "FRAGMENT");

        glAttachShader(m_id, vertexShader);
        glAttachShader(m_id, fragmentShader);
        glLinkProgram(m_id);
        checkCompileErrors(m_id, "PROGRAM");

        glUseProgram(m_id);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Shader::setBool(const char* name, bool value) {
        glUniform1i(getUniformLocation(name), (int)value);
    }

    void Shader::setInt(const char* name, int value) {
        glUniform1i(getUniformLocation(name), value);
    }

    void Shader::setFloat(const char* name, float value) {
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::setVector2(const char* name, float x, float y) {
        glUniform2f(getUniformLocation(name), x, y);
    }

    void Shader::setVector3(const char* name, float x, float y, float z) {
        glUniform3f(getUniformLocation(name), x, y, z);
    }

    void Shader::setVector4(const char* name, float x, float y, float z, float w) {
        glUniform4f(getUniformLocation(name), x, y, z, w);
    }

    void Shader::setMatrix2(const char* name, const glm::mat2& matrix) {
        glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
    }

    void Shader::setMatrix3(const char* name, const glm::mat3& matrix) {
        glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
    }

    void Shader::setMatrix4(const char* name, const glm::mat4& matrix) {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
    }

    std::string Shader::readFile(const char* path) {
        std::ifstream file;
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        std::stringstream stream;
        try {
            file.open(path, std::ios::in);
            stream << file.rdbuf();
            file.close();
        }
        catch (std::ifstream::failure& error) {
            std::cerr << "[SHADER ERROR] Shader file " << path << " not successfully read: " << error.what() << '\n';
            exit(-1);
        }
        return stream.str();
    }

    int32_t Shader::getUniformLocation(const char* name) {
        auto locationIterator = m_uniformLocationCache.find(name);
        if (locationIterator != m_uniformLocationCache.end()) {
            return locationIterator->second;
        }
        int32_t location = glGetUniformLocation(m_id, name);
        m_uniformLocationCache[name] = location;
        return location;
    }

    void Shader::checkCompileErrors(uint32_t shaderID, const std::string& type) {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM") {
            glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shaderID, 1024, nullptr, infoLog);
                std::cerr << "[SHADER ERROR] Shader compilation error of type: " << type << '\n' << infoLog << '\n';
                exit(-1);
            }
        }
        else {
            glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shaderID, 1024, nullptr, infoLog);
                std::cerr << "[SHADER ERROR] Program linking error of type: " << type << '\n' << infoLog << '\n';
                exit(-1);
            }
        }
    }

} // bgl
