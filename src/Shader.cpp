#include "Shader.h"

enum ShaderType {
    vertexShader,
    fragmentShader
};

GLuint LoadSingleShader(const char* filePath, ShaderType type) {
    GLuint id;
    if (type == vertexShader) {
        id = glCreateShader(GL_VERTEX_SHADER);
    } else if (type == fragmentShader) {
        id = glCreateShader(GL_FRAGMENT_SHADER);
    }

    std::string shaderCode;

    std::ifstream codeStream(filePath);
    if (codeStream.is_open()) {
        std::string line = "";

        while (getline(codeStream, line)) {
            shaderCode += line + "\n";
        }
        codeStream.close();
    } else {
        std::cerr << "Unable to open shader files at " << filePath << std::endl;
        return 0;
    }

    char const * sourceCode = shaderCode.c_str();
    glShaderSource(id, 1, &sourceCode, NULL);
    glCompileShader(id);

    // verify that the shader compiled correctly
    GLint isCompiled;

    glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);

    if (isCompiled == GL_FALSE) {
        int logLength;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> shaderErrorMessage(logLength + 1);
		glGetShaderInfoLog(id, logLength, NULL, shaderErrorMessage.data());
        glDeleteShader(id);
		std::string msg(shaderErrorMessage.begin(), shaderErrorMessage.end());
		std::cerr << msg << std::endl;
		return 0;
	}

    return id;
}

GLuint loadShaders(const char* vertexPath, const char* fragmentPath) {
    GLuint vertexID = LoadSingleShader(vertexPath, vertexShader);
    GLuint fragmentID = LoadSingleShader(fragmentPath, fragmentShader);

    if (vertexID == 0 || fragmentID == 0) {
        return 0;
    }

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexID);
    glAttachShader(programID, fragmentID);
    glLinkProgram(programID);

    // verify program linked correctly
    GLint success = 0;
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (success == GL_FALSE) {
        GLint logLength;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<char> programErrorMessage(logLength + 1);
		glGetProgramInfoLog(programID, logLength, NULL, programErrorMessage.data());
        std::string msg(programErrorMessage.begin(), programErrorMessage.end());
		std::cerr << msg << std::endl;
        
        glDeleteProgram(programID);
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
		return 0;
    }

    glValidateProgram(programID);
    glGetProgramiv(programID, GL_VALIDATE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint logLength;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<char> programErrorMessage(logLength + 1);
		glGetProgramInfoLog(programID, logLength, NULL, programErrorMessage.data());
        std::string msg(programErrorMessage.begin(), programErrorMessage.end());
		std::cerr << msg << std::endl;

    }

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
    return programID;
}