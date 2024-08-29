#pragma once

namespace Shader {
	/// <summary>
	/// Compile "shaderSrc" of type "type" into binaries 
	/// </summary>
	/// <returns> id of the compiled shader </returns>
	unsigned int Compile(unsigned int type, const char* shaderSrc);
	// <summary>
	/// Link "vtxShaderId" and "frgShaderId"
	/// </summary>
	/// <returns> id of the shader program created </returns>
	unsigned int Link(unsigned int vtxShaderId, unsigned int frgShaderId);
}