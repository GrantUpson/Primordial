#ifndef PRIMORDIAL_SHADER_H
#define PRIMORDIAL_SHADER_H


#include "utility/Utility.h"

class Shader {
public:
    Shader(const std::string& source);
    ~Shader();

    void Bind() const;
    void Unbind() const;

private:
    uint32 rendererID;
};


#endif
