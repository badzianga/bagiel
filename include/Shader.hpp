#ifndef BAGIEL_SHADER_HPP
#define BAGIEL_SHADER_HPP

#include <cstdint>
#include <unordered_map>
#include <string>

#include <glm/glm.hpp>

namespace bgl {

    class Shader {
    public:
        Shader();
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();
        void use() const;
        void compile(const char* vertexPath, const char* fragmentPath);
        void setBool(const char* name, bool value);
        void setInt(const char* name, int value);
        void setFloat(const char* name, float value);
        void setVector2(const char* name, float x, float y);
        void setVector3(const char* name, float x, float y, float z);
        void setVector4(const char* name, float x, float y, float z, float w);
        void setMatrix2(const char* name, const glm::mat2& matrix);
        void setMatrix3(const char* name, const glm::mat3& matrix);
        void setMatrix4(const char* name, const glm::mat4& matrix);
    private:
        uint32_t m_id;
        std::unordered_map<const char*, int32_t> m_uniformLocationCache;

        std::string readFile(const char* path);
        int32_t getUniformLocation(const char* name);
        void checkCompileErrors(uint32_t shaderID, const std::string& type);
    };

} // bgl

#endif //BAGIEL_SHADER_HPP
