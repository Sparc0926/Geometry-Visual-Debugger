#include <glew.h>
#include <stdio.h>
#include <malloc.h>


namespace Shader {
	unsigned int Compile(unsigned int type, const char* shaderSrc)
	{
		unsigned int id = glCreateShader(type);
		glShaderSource(id, 1, &shaderSrc, 0);
		glCompileShader(id);
#ifdef DEBUG
		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			printf("%s\n", message);
			return -1;
		}
#endif
		return id;
	}
	unsigned int Link(const unsigned int vtxShaderId, const unsigned int frgShaderId)
	{
		const unsigned int shaderProgramId = glCreateProgram();
		// Attach the vertex and fragment shadear binarie onto the specified shader program for later linkage
		glAttachShader(shaderProgramId, vtxShaderId);
		glAttachShader(shaderProgramId, frgShaderId);
		// Link all shader binaries attached onto the shader program
		glLinkProgram(shaderProgramId);
		// Delete those attached shader binaries
		glDeleteShader(vtxShaderId);
		glDeleteShader(frgShaderId);

		return shaderProgramId;
	}
}