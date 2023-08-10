//Sonia LI
//Yasser Ameer 40212780
//Peter Abou Kassam 40157317
//phong lighting from the TA lab session code
//sphere from TA lab session
//Arm hierarchy accomplished
//assignmenent 1 code put all in one model
// shadow from the lab session
// texture from the lab session
//


#include <iostream>
#include <list>

#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL

#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler

#include <GLFW/glfw3.h> // cross-platform interface for creating a graphical context,
// initializing OpenGL and binding inputs

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp> // include this to create transformation matrices
#include <glm/common.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <cstdlib>
//#include <OpenGL/gl.h>#include <stb_image.h> // for image loading
//#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // for image loading
#include <string>
#include "OBJloader.h"    //For loading .obj files
#include "OBJloaderV2.h"  //For loading .obj files using a polygon list format
#include "shaderloader.h"

using namespace glm;
using namespace std;
//LIGHTING
//


const char* getVertexShaderSource();

const char* getFragmentShaderSource();

void DrawGrid(GLuint worldmatrix, GLuint colorLocation, int shader_id);

void DrawCoordinates(GLuint worldmatrix, GLuint colorLocation, float worldXAngle, float worldYAngle);

int compileAndLinkShaders();

bool initContext();

struct TexturedColoredVertex
{
    TexturedColoredVertex(vec3 _position, vec3 _color, vec2 _uv, vec3 _light)
            : position(_position), color(_color), uv(_uv), light(_light) {}

    vec3 position;
    vec3 color;
    vec2 uv;
    vec3 light;
};

// Textured Cube model
const TexturedColoredVertex texturedCubeVertexArray[] = {  // position,                            NORMAL
        TexturedColoredVertex(vec3(-0.5f,-0.5f,-0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f),vec3(-1.0f, 0.0f, 0.0f)), //left - red
        TexturedColoredVertex(vec3(-0.5f,-0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(-1.0f, 0.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(-1.0f, 0.0f, 0.0f)),

        TexturedColoredVertex(vec3(-0.5f,-0.5f,-0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(-1.0f, 0.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(-1.0f, 0.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f,-0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(-1.0f, 0.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f,-0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, -1.0f)), // far - blue
        TexturedColoredVertex(vec3(-0.5f,-0.5f,-0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, -1.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f,-0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, -1.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f,-0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, -1.0f)),
        TexturedColoredVertex(vec3(0.5f,-0.5f,-0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, -1.0f)),
        TexturedColoredVertex(vec3(-0.5f,-0.5f,-0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, -1.0f)),

        TexturedColoredVertex(vec3(0.5f,-0.5f, 0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f),vec3(0.0f, -1.0f, 0.0f)), // bottom - turquoise
        TexturedColoredVertex(vec3(-0.5f,-0.5f,-0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(0.0f, 0.0f),vec3(0.0f, -1.0f, 0.0f)),
        TexturedColoredVertex(vec3(0.5f,-0.5f,-0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(1.0f, 0.0f),vec3(0.0f, -1.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f,-0.5f, 0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f),vec3(0.0f, -1.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f,-0.5f, 0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(0.0f, 1.0f),vec3(0.0f, -1.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f,-0.5f,-0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(0.0f, 0.0f),vec3(0.0f, -1.0f, 0.0f)),

        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 1.0f)), // near - green
        TexturedColoredVertex(vec3(-0.5f,-0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f)),
        TexturedColoredVertex(vec3(0.5f,-0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 1.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 1.0f)),
        TexturedColoredVertex(vec3(0.5f,-0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f), vec3(1.0f, 0.0f, 0.0f)), // right - purple
        TexturedColoredVertex(vec3(0.5f,-0.5f,-0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f)),
        TexturedColoredVertex(vec3(0.5f, 0.5f,-0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f,-0.5f,-0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f)),
        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f), vec3(1.0f, 0.0f, 0.0f)),
        TexturedColoredVertex(vec3(0.5f,-0.5f, 0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f), vec3(1.0f, 0.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 1.0f, 0.0f)), // top - yellow
        TexturedColoredVertex(vec3(0.5f, 0.5f,-0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f,-0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 1.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f,-0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 1.0f, 0.0f))
};

int createTexturedCubeVertexArrayObject()
{
    // Create a vertex array
    GLuint vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    // Upload Vertex Buffer to the GPU, keep a reference to it (vertexBufferObject)
    GLuint vertexBufferObject;
    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texturedCubeVertexArray), texturedCubeVertexArray, GL_STATIC_DRAW);

    glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
                          3,                   // size
                          GL_FLOAT,            // type
                          GL_FALSE,            // normalized?
                          sizeof(TexturedColoredVertex), // stride - each vertex contain 2 vec3 (position, color)
                          (void*)0             // array buffer offset
    );
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(TexturedColoredVertex),
                          (void*)sizeof(vec3)      // color is offseted a vec3 (comes after position)
    );
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2,                            // attribute 2 matches aUV in Vertex Shader
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(TexturedColoredVertex),
                          (void*)(2 * sizeof(vec3))      // uv is offseted by 2 vec3 (comes after position and color)
    );
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3,                            // attribute normal in Vertex Shader
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(TexturedColoredVertex),
                          (void*)(2 * sizeof(vec3) + sizeof(vec2))      // color is offseted a vec3 (comes after position)
    );
    glEnableVertexAttribArray(3);

    return vertexArrayObject;
}



GLFWwindow* window = NULL;
GLuint loadTexture(const std::string& path) {
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return texture;
}




const char* getDepthVertexShaderSource() {
    return
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;"
            "uniform mat4 worldMatrix;"
            "uniform mat4 lightSpaceMatrix;"
            "void main(){"
            " gl_Position=lightSpaceMatrix * worldMatrix *  vec4(aPos.x, aPos.y, aPos.z, 1.0);"


            "}"
            ;
}


const char* getDepthFragmentShaderSource() {

    return
            "  #version 330 core\n"

            "void main()"
            "{"
            "}";

}

const char* getVertexShaderSource() {
    // For now, you use a string for your shader code, in the assignment, shaders will be stored in .glsl files
    return
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;"
            "layout (location = 1) in vec3 aColor;"
            "layout (location = 2) in vec2 aUV;"
            "layout (location = 3) in vec3 aNormal;"
            ""
            "uniform mat4 worldMatrix;"
            "uniform mat4 viewMatrix = mat4(1.0);"  // default value for view matrix (identity)
            "uniform mat4 projectionMatrix = mat4(1.0);"
            "uniform mat4 worldOrientationMatrix;"
            "uniform mat4 lightSpaceMatrix;"
            "uniform vec3 color;"
            "uniform vec3 lightPos;"
            ""
            "out vec3 objectColor;"
            "out vec2 vertexUV;"
            "out vec4 fragPosLightSpace;"
            "out vec3 pos;"
            "out vec3 normal;"
            "out vec3 eyeDir;"
            "out vec3 lightDir;"
            "void main()"
            "{"
            "   objectColor = aColor;"
            "   mat4 modelViewProjection = projectionMatrix * viewMatrix * worldOrientationMatrix * worldMatrix;"
            "   gl_Position = modelViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0);"
            "   vertexUV = aUV;"
            ""

            ""
            "  pos = (worldMatrix * vec4(aPos, 1)).xyz;"
            "  vec3 vertexPosition_cameraspace = ( viewMatrix * worldMatrix * vec4(aPos,1)).xyz;"
            "  eyeDir = vec3(0,0,0) - vertexPosition_cameraspace;"
            ""
            "  vec3 lightPosCamera = (viewMatrix * vec4(lightPos, 1)).xyz;"
            "  lightDir = lightPosCamera + eyeDir;"
            "  normal = (transpose(inverse(viewMatrix * worldMatrix)) * vec4(aNormal, 1)).xyz;"

            " fragPosLightSpace=lightSpaceMatrix* vec4(pos,1.0);"
            "}";
}



const char* getFragmentShaderSource() {
    return
            "#version 330 core\n"
            "in vec3 vertexColor;"
            "in vec3 pos;"
            "in vec3 normal;"
            "in vec3 eyeDir;"
            "in vec3 lightDir;"
            "out vec4 FragColor;"
            //   "in vec3 FragColor1;"
            "in vec4 fragPosLightSpace;"
            "uniform vec3 objectColor;"
            "in vec2 vertexUV;"
            "uniform sampler2D textureSampler;"
            "uniform sampler2D shadowMap;"
            "uniform int useTexture = 0;"
            "uniform int useTexture1 = 0;"
            "uniform vec3 lightPos;"
            "void main()"
            "{"
            "   vec4 textureColor = texture( textureSampler, vertexUV );"

            "  vec3 lightColor = vec3(1,1,1);"
            "  float lightPower = 100.0f;"
            ""
            "  vec3 diffuseColor = objectColor;"
            "  vec3 specularColor = vec3(0.5,0.5,0.5);"
            "  vec3 ambientColor = vec3(0.5,0.5,0.5) * objectColor;"
            ""
            "  float dist = length(lightPos - pos);"
            "  vec3 n = normalize(normal);"
            "  vec3 l = normalize(lightDir);"
            ""
            "  float cosTheta = clamp(dot(n,l), 0, 1);"
            ""
            "  vec3 E = normalize(eyeDir);"
            "  vec3 R = reflect(-l, n);"
            ""
            "  float cosAlpha = clamp(dot(E, R), 0, 1);"
            ""
            " vec3 shadowTextureCoord = fragPosLightSpace.xyz * 0.5 + 0.5; "
            "   float shadow = 1.0f;"
            "   float bias = 0.005;"
            "   if (shadowTextureCoord.z - bias > texture(shadowMap, shadowTextureCoord.xy).r)"
            "   {"
            "       shadow = 0.2f;"
            "   }"
            " vec3 L ="
            "     ambientColor +"
            "     shadow * (diffuseColor * lightColor * lightPower * cosTheta / (1 + dist * 0.5 + dist * dist * 0.05) +"
            "     specularColor * lightColor * lightPower * pow(cosAlpha,5) / (1 + dist * 0.5 + dist * dist * 0.05)); "
            " vec3 P ="
            "     ambientColor +"
            "     (diffuseColor * lightColor * lightPower * cosTheta / (1 + dist * 0.5 + dist * dist * 0.05) +"
            "     specularColor * lightColor * lightPower * pow(cosAlpha,5) / (1 + dist * 0.5 + dist * dist * 0.05)); "
            " vec4 M = vec4 (L,1.0f);"
            " vec4 B = vec4 (P,1.0f);"
            "   if (useTexture == 0 && useTexture1==0){"
            "    FragColor = B* vec4(objectColor.r, objectColor.g, objectColor.b, 1.0f); }"
            "   if (useTexture == 0 && useTexture1==1){"
            "    FragColor = M* vec4(objectColor.r, objectColor.g, objectColor.b, 1.0f); }"
            "   if (useTexture == 1 && useTexture1==0){"
            "    FragColor = B*textureColor; }"
            "   if (useTexture == 1 && useTexture1==1){"
            "    FragColor = M*textureColor; }"


            "}";
}

int compileAndLinkShaders() {
    // compile and link shader program
    // return shader program id
    // ------------------------------------

    // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = getVertexShaderSource();
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = getFragmentShaderSource();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
int compileAndLinkTexturedShaders(const char* vertexShaderSource, const char* fragmentShaderSource)
{
    // compile and link shader program
    // return shader program id
    // ------------------------------------

    // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
int compileAndLinkDepthShaders(const char* vertexShaderSource, const char* fragmentShaderSource)
{
    // compile and link shader program
    // return shader program id
    // ------------------------------------

    // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void DrawGrid(GLuint worldmatrix, GLuint colorLocation, int shader_id) {
    glGetUniformLocation(shader_id, "objectColor");
    mat4 gridWorldMatrix;
    for (int i = 0; i < 51; ++i) {
        gridWorldMatrix = translate(mat4(1.0f), vec3(i * 1.0f, 0.0f, 0.0f))
                          * rotate(mat4(1.0f), radians(90.0f), vec3(1.0f, 0.0f, 0.0f)) *
                          scale(mat4(1.0f), vec3(0.02f, 100.0f, 0.02f));
        glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &gridWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0f, 1.0f, 0.0f)));
        glDrawArrays(GL_TRIANGLES, 0, 36);

        gridWorldMatrix = translate(mat4(1.0f), vec3(i * -1.0f, 0.0f, 0.0f))
                          * rotate(mat4(1.0f), radians(90.0f), vec3(1.0f, 0.0f, 0.0f)) *
                          scale(mat4(1.0f), vec3(0.02f, 100.0f, 0.02f));
        glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &gridWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0f, 1.0f, 0.0f)));
        glDrawArrays(GL_TRIANGLES, 0, 36);

        gridWorldMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, i * 1.0f))
                          * rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                          scale(mat4(1.0f), vec3(0.02f, 100.0f, 0.02f));
        glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &gridWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0f, 1.0f, 0.0f)));
        glDrawArrays(GL_TRIANGLES, 0, 36);

        gridWorldMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, i * -1.0f))
                          * rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                          scale(mat4(1.0f), vec3(0.02f, 100.0f, 0.02f));
        glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &gridWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0f, 1.0f, 0.0f)));
        glDrawArrays(GL_TRIANGLES, 0, 36);

    }
}

void DrawCoordinates(GLuint worldmatrix, GLuint colorLocation, float worldXAngle, float worldYAngle) {
    // Draw X axis, colored red
    mat4 xAxis = rotate(mat4(1.0), radians(worldXAngle), vec3(1.0f, 0.0f, 0.0f)) *
                 rotate(mat4(1.0), radians(worldYAngle), vec3(0.0f, 1.0f, 0.0f));
    xAxis = xAxis * translate(mat4(1.0f), vec3(2.5f, 0.0f, 0.0f)) * scale(mat4(1.0f), vec3(5.0f, 0.1f, 0.1f));
    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &xAxis[0][0]);
    glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0f, 0.0f, 0.0f)));
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // Draw Y axis, colored green
    mat4 yAxis = rotate(mat4(1.0), radians(worldXAngle), vec3(1.0f, 0.0f, 0.0f)) *
                 rotate(mat4(1.0), radians(worldYAngle), vec3(0.0f, 1.0f, 0.0f));
    yAxis = yAxis * translate(mat4(1.0f), vec3(0.0f, 2.5f, 0.0f)) * scale(mat4(1.0f), vec3(0.1f, 5.0f, 0.1f));
    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &yAxis[0][0]);
    glUniform3fv(colorLocation, 1, value_ptr(vec3(0.0f, 1.0f, 0.0f)));
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // Draw Z axis, colored blue
    mat4 zAxis = rotate(mat4(1.0), radians(worldXAngle), vec3(1.0f, 0.0f, 0.0f)) *
                 rotate(mat4(1.0), radians(worldYAngle), vec3(0.0f, 1.0f, 0.0f));
    zAxis = zAxis * translate(mat4(1.0f), vec3(0.0f, 0.0f, 2.5f)) * scale(mat4(1.0f), vec3(0.1f, 0.1f, 5.0f));
    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &zAxis[0][0]);
    glUniform3fv(colorLocation, 1, value_ptr(vec3(0.0f, 0.0f, 1.0f)));
    glDrawArrays(GL_TRIANGLES, 0, 36);

}

bool initContext() {     // Initialize GLFW and OpenGL version
    glfwInit();

#if defined(PLATFORM_OSX)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    // On windows, we set OpenGL version to 2.1, to support more hardware
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
#endif

    // Create Window and rendering context using GLFW, resolution is 800x600
    window = glfwCreateWindow(1024, 768, "Comp371 - A1 (40193803)", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to create GLEW" << std::endl;
        glfwTerminate();
        return false;
    }
    return true;
}


#include <vector>
#include <cmath>
void MidSectionCreation(GLuint worldmatrix, GLuint colorLocation) {

    //creating the middle

    mat4 LeftBar = translate(mat4(1.0f), vec3(-18.0f, 4.0f, 0.0f)) * scale(mat4(1.0f), vec3(0.5f, 8.0f, 0.5f));
    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &LeftBar[0][0]);
    glUniform3fv(colorLocation, 1, value_ptr(vec3(0.212, 0.212, 0.212)));
    glDrawArrays(GL_TRIANGLES, 0, 36);

    mat4 RightBar = translate(mat4(1.0f), vec3(+18.0f, 4.0f, 0.0f)) * scale(mat4(1.0f), vec3(0.5f, 8.0f, 0.5f));
    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &RightBar[0][0]);
    glUniform3fv(colorLocation, 1, value_ptr(vec3(0.212, 0.212, 0.212)));
    glDrawArrays(GL_TRIANGLES, 0, 36);

    mat4 MiddleBar = translate(mat4(1.0f), vec3(0.0f, 8.0f, 0.0f)) * scale(mat4(1.0f), vec3(37.0f, 0.5f, 0.5f));
    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &MiddleBar[0][0]);
    glUniform3fv(colorLocation, 1, value_ptr(vec3(0.212, 0.212, 0.212)));
    glDrawArrays(GL_TRIANGLES, 0, 36);

    //creating the NET

    for (float i = 0; i < 3.5; i = i + 0.8)
    {
        mat4 HLinesMatrix = translate(mat4(1.0f), vec3(0.0f, i + 4.5f, 0.0f)) * scale(mat4(1.0f), vec3(36.0f, 0.09f, 0.09f));
        glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &HLinesMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    //vertical lines
    for (float i = 0; i < 36; i = i + 1)
    {
        mat4 VLinesMatrix = translate(mat4(1.0f), vec3(i - 18.0f, 6.0f, 0.0f)) * rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 0.0f, 1.0f)) * scale(mat4(1.0f), vec3(0.06f, 3.0f, 0.06f));
        glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &VLinesMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }



}
class Ball {
public:
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    GLuint vao, vbo, ebo;
    GLuint texture;
    unsigned indexCount;

    Ball() { }

    int createSphereObject()
    {
        // A vertex is a point on a polygon, it contains positions and other data (eg: colors)
        unsigned int sphereVAO;
        glGenVertexArrays(1, &sphereVAO);

        unsigned int vbo, ebo;
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        std::vector<glm::vec3> positions;
        std::vector<glm::vec2> uv;
        std::vector<glm::vec3> normals;
        std::vector<unsigned int> indices;
        std::vector<glm::vec3> colors;

        const unsigned int X_SEGMENTS = 64;
        const unsigned int Y_SEGMENTS = 64;
        const float PI = 3.14159265359;
        for (unsigned int y = 0; y <= Y_SEGMENTS; ++y)
        {
            for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
            {
                float xSegment = (float)x / (float)X_SEGMENTS;
                float ySegment = (float)y / (float)Y_SEGMENTS;
                float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
                float yPos = std::cos(ySegment * PI);
                float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);

                positions.push_back(glm::vec3(xPos, yPos, zPos));
                colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
                uv.push_back(glm::vec2(xSegment, ySegment));
                normals.push_back(glm::vec3(xPos, yPos, zPos));
            }
        }

        bool oddRow = false;
        for (unsigned int y = 0; y < Y_SEGMENTS; ++y)
        {
            if (!oddRow) // even rows: y == 0, y == 2; and so on
            {
                for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
                {
                    indices.push_back(y * (X_SEGMENTS + 1) + x);
                    indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                }
            }
            else
            {
                for (int x = X_SEGMENTS; x >= 0; --x)
                {
                    indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                    indices.push_back(y * (X_SEGMENTS + 1) + x);
                }
            }
            oddRow = !oddRow;
        }
        indexCount = indices.size();

        std::vector<float> data;
        for (unsigned int i = 0; i < positions.size(); ++i)
        {
            data.push_back(positions[i].x);
            data.push_back(positions[i].y);
            data.push_back(positions[i].z);
            if (colors.size() > 0) {
                data.push_back(colors[i].x);
                data.push_back(colors[i].y);
                data.push_back(colors[i].z);
            }
            if (uv.size() > 0)
            {
                data.push_back(uv[i].x);
                data.push_back(uv[i].y);
            }
            if (normals.size() > 0)
            {
                data.push_back(normals[i].x);
                data.push_back(normals[i].y);
                data.push_back(normals[i].z);
            }
        }
        glBindVertexArray(sphereVAO);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
        float stride = (3 + 2 + 3 + 3) * sizeof(float);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, stride, (void*)(8 * sizeof(float)));

        glBindBuffer(GL_ARRAY_BUFFER, 0); // VAO already stored the state we just defined, safe to unbind buffer
        glBindVertexArray(0); // Unbind to not modify the VAO

        return sphereVAO;
    }

    void Render(const glm::mat4& groupTranslationMatrix, const glm::mat4& groupRotationMatrix,
                const glm::mat4& groupScalingMatrix, GLint worldLocationMatrix, GLint colorLocation,
                GLenum renderingMode, GLint textureSamplerLocation, int shaderprogram) {

        //        glUseProgram(shaderprogram);
        //        glActiveTexture(GL_TEXTURE0);
        //        glBindTexture(GL_TEXTURE_2D, texture);
        //        glUniform1i(textureSamplerLocation, 0);

        glm::mat4 sphereMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(7.5f, 10.0f, 0.0f));
        glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 4.0f, 1.0f));
        glm::mat4 modelMatrix = groupTranslationMatrix * groupRotationMatrix * groupScalingMatrix * sphereMatrix * scaleMatrix;

        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
        glUniform3fv(colorLocation, 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 0.0f)));

        glBindVertexArray(vao);
        glDrawElements(renderingMode, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glUseProgram(0);
    }

    ~Ball() {
        glDeleteTextures(1, &texture);
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
    }
};

GLuint setupModelVBO(string path, int& vertexCount);

// Sets up a model using an Element Buffer Object to refer to vertex data
GLuint setupModelEBO(string path, int& vertexCount);

class Tennis
{
#include <glm/gtc/matrix_transform.hpp>
public:

    Tennis() {};

    Tennis(GLuint worldmatrix, GLuint colorLocation, GLenum polygonMode, int texturedshader, int ID, char letter)
    {
        this->worldmatrix = worldmatrix;
        this->colorLocation = colorLocation;
        this->polygonMode = polygonMode;
        this->letter = letter;
        this->texturedshader = texturedshader;
        this->ID = ID;
    }
    void changeWorldMatrix(GLuint newWorldMatrix) {
        this->worldmatrix = newWorldMatrix;

    }

    //Call this function to DRAW everything
    void Draw(GLuint upperarmtexture, GLuint lowerarmtexture, GLuint rackettexture) {
        this->Draw_UpperArm(this->letter, upperarmtexture);
        this->Draw_LowerArm(this->letter, lowerarmtexture);
        this->Draw_Racket(this->letter, rackettexture);
    }

    void Draw_UpperArm(char letter, GLuint upperarmtexture) {
        glUseProgram(this->texturedshader);
        glBindTexture(GL_TEXTURE_2D, upperarmtexture);
        switch (letter)
        {
            case 'p': {
                mat4 UpperArmMatrix = translate(mat4(1.0f), vec3(1.0f, 1.0f, 0.0f)) *
                                      rotate(mat4(1.0f), radians(45.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                      scale(mat4(1.0f), vec3(2.0f, 1.0f, 1.0f));
                UpperArmGroupMatrix =
                        UpperarmgroupTransferMatrix * UpperarmgroupRotationMatrix * UpperarmgroupScaleMatrix;
                modelMatrix = UpperArmGroupMatrix * UpperArmMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
                glDrawArrays(polygonMode, 0, 36);
                UpperArmCurrentPosition = translate(mat4(1.0f), vec3(1.0f, 1.0f, 0.0f));
                CurrentPosition = translate(mat4(1.0f), vec3(1.0f, 1.0f, 0.0f));
                break;
            }

            case 'y': {
                mat4 upperarmWorldMatrix = scale(mat4(1.0f), vec3(6.0f, 1.0f, 2.0f));
                UpperArmGroupMatrix =
                        UpperarmgroupTransferMatrix * UpperarmgroupRotationMatrix * UpperarmgroupScaleMatrix;
                modelMatrix = UpperArmGroupMatrix * upperarmWorldMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.99, 0.88)));
                glDrawArrays(polygonMode, 0, 36);
                CurrentPosition = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
                break;
            }

            case 's': {
                mat4 UpperArmMatrixSonia = translate(mat4(1.0f), vec3(1.0f, 1.0f, 0.0f)) *
                                           rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                           scale(mat4(1.0f), vec3(1.5f, 1.0f, 1.0f));
                UpperArmGroupMatrix =
                        UpperarmgroupTransferMatrix * UpperarmgroupRotationMatrix * UpperarmgroupScaleMatrix;
                modelMatrix = UpperArmGroupMatrix * UpperArmMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
                glUniform3fv(colorLocation, 1, glm::value_ptr(glm::vec3(0.87f, 0.72f, 0.53f)));
                glDrawArrays(polygonMode, 0, 36);
                CurrentPosition = translate(mat4(1.0f), vec3(1.0f, 1.0f, 0.0f));
                break;
            }
            default: {
                break;
            }
        }



    }

    void Draw_LowerArm(char letter, GLuint upperarmtexture) {
        glUseProgram(this->texturedshader);
        glBindTexture(GL_TEXTURE_2D, upperarmtexture);
        switch (letter)
        {
            case 'p': {
                mat4 LowerArmMatrix = translate(mat4(1.0f), vec3(2.0f, 2.5f, 0.0f)) *
                                      rotate(mat4(1.0f), radians(70.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                      scale(mat4(1.0f), vec3(2.0f, 1.0f, 1.0f));
                LowerArmGroupMatrix = UpperArmGroupMatrix * LowerarmgroupTransferMatrix * LowerarmgroupRotationMatrix *
                                      LowerarmgroupScaleMatrix;
                modelMatrix = LowerArmGroupMatrix * LowerArmMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
                glDrawArrays(polygonMode, 0, 36);
                break;
            }

            case 'y': {
                mat4 lowerarmWorldMatrix =
                        translate(mat4(1.0f), vec3(3.0f, 2.5f, 0.0f)) * scale(mat4(1.0f), vec3(1.0f, 5.0f, 2.0f));
                LowerArmGroupMatrix = UpperArmGroupMatrix * LowerarmgroupTransferMatrix * LowerarmgroupRotationMatrix *
                                      LowerarmgroupScaleMatrix;
                modelMatrix = LowerArmGroupMatrix * lowerarmWorldMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.99, 0.88)));

                glDrawArrays(polygonMode, 0, 36);
                break;
            }

            case's': {
                mat4 LowerArmMatrixSonia = translate(mat4(1.0f), vec3(2.0f, 2.5f, 0.0f)) *
                                           rotate(mat4(1.0f), radians(72.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                           scale(mat4(1.0f), vec3(2.2f, 1.0f, 1.0f));
                LowerArmGroupMatrix = UpperArmGroupMatrix * LowerarmgroupTransferMatrix * LowerarmgroupRotationMatrix *
                                      LowerarmgroupScaleMatrix;
                modelMatrix = LowerArmGroupMatrix * LowerArmMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.87f, 0.72f, 0.53f)));
                glDrawArrays(polygonMode, 0, 36);
                break;
            }

            default: {
                break;
            }
        }

    }
    void Draw_Racket(char letter, GLuint rackettexture) {
        glUseProgram(this->texturedshader);
        glBindTexture(GL_TEXTURE_2D, rackettexture);
        switch (letter)
        {
            case 'p': {                // the handle
                mat4 handleMatrix = translate(mat4(1.0f), vec3(2.3f, 4.0f, 0.25f)) *
                                    rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                    scale(mat4(1.0f), vec3(2.5f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * handleMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.5, 0.5)));
                glDrawArrays(polygonMode, 0, 36);

                // the base
                mat4 baserightMatrix = translate(mat4(1.0f), vec3(3.0f, 5.5f, 0.25f)) *
                                       rotate(mat4(1.0f), radians(35.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                       scale(mat4(1.0f), vec3(1.5f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * baserightMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.5, 0.5)));
                glDrawArrays(polygonMode, 0, 36);

                mat4 baseleftMatrix = translate(mat4(1.0f), vec3(1.6f, 5.5f, 0.25f)) *
                                      rotate(mat4(1.0f), radians(145.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                      scale(mat4(1.0f), vec3(1.5f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * baseleftMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.5, 0.5)));
                glDrawArrays(polygonMode, 0, 36);

                //lower right side
                mat4 lowerrightMatrix = translate(mat4(1.0f), vec3(3.5f, 6.5f, 0.25f)) *
                                        rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                        scale(mat4(1.0f), vec3(1.5f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * lowerrightMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.5, 0.5)));
                glDrawArrays(polygonMode, 0, 36);

                //lower left side
                mat4 lowerleftMatrix = translate(mat4(1.0f), vec3(1.1f, 6.5f, 0.25f)) *
                                       rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                       scale(mat4(1.0f), vec3(1.5f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * lowerleftMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.5, 0.5)));
                glDrawArrays(polygonMode, 0, 36);


                //upper left side
                mat4 upperleftMatrix = translate(mat4(1.0f), vec3(3.0f, 7.5f, 0.25f)) *
                                       rotate(mat4(1.0f), radians(145.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                       scale(mat4(1.0f), vec3(1.5f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * upperleftMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.5, 0.5)));
                glDrawArrays(polygonMode, 0, 36);

                //upper right side
                mat4 upperrightMatrix = translate(mat4(1.0f), vec3(1.6f, 7.5f, 0.25f)) *
                                        rotate(mat4(1.0f), radians(35.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                        scale(mat4(1.0f), vec3(1.5f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * upperrightMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.5, 0.5)));
                glDrawArrays(polygonMode, 0, 36);


                //upperbase
                mat4 upperbaseMatrix = translate(mat4(1.0f), vec3(2.3f, 8.0f, 0.25f)) *
                                       rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                       scale(mat4(1.0f), vec3(0.3f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * upperbaseMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.5, 0.5)));
                glDrawArrays(polygonMode, 0, 36);


                // horiztonal lines
                for (float i = 0; i < 2; i = i + 0.2) {
                    mat4 HLinesMatrix = translate(mat4(1.0f), vec3(2.3f, i + 5.6f, 0.0f)) *
                                        scale(mat4(1.0f), vec3(2.0f, 0.05f, 0.05f));
                    RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                        RacketgroupScaleMatrix;
                    modelMatrix = RacketGroupMatrix * HLinesMatrix;
                    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                    glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
                    glDrawArrays(polygonMode, 0, 36);
                }

                //vertical lines
                for (float i = 0; i < 1.8; i = i + 0.2) {
                    mat4 VLinesMatrix = translate(mat4(1.0f), vec3(i + 1.5f, 6.5f, 0.0f)) *
                                        rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                        scale(mat4(1.0f), vec3(0.05f, 2.5f, 0.05f));
                    RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                        RacketgroupScaleMatrix;
                    modelMatrix = RacketGroupMatrix * VLinesMatrix;
                    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                    glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
                    glDrawArrays(polygonMode, 0, 36);
                }
                break;
            }

            case 'y': {
                mat4 handle1WorldMatrix =
                        translate(mat4(1.0f), vec3(3.0f, 9.0f, 0.0f)) * scale(mat4(1.0f), vec3(2.0f, 8.0f, 2.0f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * handle1WorldMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.99, 0.0)));// adding the color desired
                glDrawArrays(polygonMode, 0, 36);
                //  *rotate(mat4(1.0f), radians(testangle), vec3(0.0f, 1.0f, 0.0f))
                mat4 rackWorldMatrix =
                        translate(mat4(1.0f), vec3(3.0f, 14.0f, 0.0f)) * scale(mat4(1.0f), vec3(1.0f, 1.0f, 10.0f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * rackWorldMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.99, 0.0)));
                glDrawArrays(polygonMode, 0, 36);

                rackWorldMatrix = translate(mat4(1.0f), vec3(3.0f, 17.5f, -4.5f)) *
                                  rotate(mat4(1.0f), radians(90.0f), vec3(1.0f, 0.0f, 0.0f)) *
                                  scale(mat4(1.0f), vec3(1.0f, 1.0f, 8.0f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * rackWorldMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.99, 0.0)));
                glDrawArrays(polygonMode, 0, 36);

                rackWorldMatrix = translate(mat4(1.0f), vec3(3.0f, 17.5f, 4.5f)) *
                                  rotate(mat4(1.0f), radians(90.0f), vec3(1.0f, 0.0f, 0.0f)) *
                                  scale(mat4(1.0f), vec3(1.0f, 1.0f, 8.0f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * rackWorldMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.99, 0.0)));
                glDrawArrays(polygonMode, 0, 36);

                rackWorldMatrix =
                        translate(mat4(1.0f), vec3(3.0f, 21.0f, 0.0f)) * scale(mat4(1.0f), vec3(1.0f, 1.0f, 10.0f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * rackWorldMatrix;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.99, 0.0)));
                glDrawArrays(polygonMode, 0, 36);
                for (int i = 16; i < 22; ++i) {
                    rackWorldMatrix = translate(mat4(1.0f), vec3(3.0f, i * 1.0f, 0.0f))
                                      * rotate(mat4(1.0f), radians(90.0f), vec3(1.0f, 0.0f, 0.0f)) *
                                      scale(mat4(1.0f), vec3(0.1f, 10.0f, 0.1f));
                    RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                        RacketgroupScaleMatrix;
                    modelMatrix = RacketGroupMatrix * rackWorldMatrix;
                    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                    glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.0, 0.0)));
                    glDrawArrays(polygonMode, 0, 36);

                }
                for (int i = -4; i < 4; ++i) {
                    rackWorldMatrix = translate(mat4(1.0f), vec3(3.0f, 17.5f, i * 1.0f))
                                      * rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 1.0f, 0.0f)) *
                                      scale(mat4(1.0f), vec3(0.1f, 8.0f, 0.1f));
                    RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                        RacketgroupScaleMatrix;
                    modelMatrix = RacketGroupMatrix * rackWorldMatrix;
                    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                    glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 0.0, 0.0)));
                    glDrawArrays(polygonMode, 0, 36);

                }
                break;
            }

            case 's': {
                //Racket Head upper right side
                mat4 upperrightMatrixSonia = translate(mat4(1.0f), vec3(1.6f, 7.5f, 0.25f)) *
                                             rotate(mat4(1.0f), radians(35.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                             scale(mat4(1.0f), vec3(1.5f, 0.35f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * upperrightMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.3725f, 0.6196f, 0.6275f)));
                glDrawArrays(polygonMode, 0, 36);

                //Racket Head upper left side
                mat4 upperleftMatrixSonia = translate(mat4(1.0f), vec3(2.3f, 8.0f, 0.25f)) *
                                            rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                            scale(mat4(1.0f), vec3(0.3f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * upperleftMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.3725f, 0.6196f, 0.6275f)));
                glDrawArrays(polygonMode, 0, 36);

                //Racket Head lower right side
                mat4 lowerrightMatrixSonia = translate(mat4(1.0f), vec3(3.5f, 6.5f, 0.25f)) *
                                             rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                             scale(mat4(1.0f), vec3(1.5f, 0.35f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * lowerrightMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.3725f, 0.6196f, 0.6275f)));
                glDrawArrays(polygonMode, 0, 36);

                //Racket Head lower left side
                mat4 lowerleftMatrixSonia = translate(mat4(1.0f), vec3(1.1f, 6.5f, 0.25f)) *
                                            rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                            scale(mat4(1.0f), vec3(1.5f, 0.35f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * lowerleftMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.3725f, 0.6196f, 0.6275f)));
                glDrawArrays(polygonMode, 0, 36);

                //Racket Head upperbase

                mat4 upperbaseMatrixSonia = translate(mat4(1.0f), vec3(3.0f, 7.5f, 0.25f)) *
                                            rotate(mat4(1.0f), radians(145.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                            scale(mat4(1.0f), vec3(1.5f, 0.35f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * upperbaseMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.3725f, 0.6196f, 0.6275f)));
                glDrawArrays(polygonMode, 0, 36);

                mat4 handleMatrixSonia = translate(mat4(1.0f), vec3(2.3f, 4.0f, 0.25f)) *
                                         rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                         scale(mat4(1.0f), vec3(2.5f, 0.5f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * handleMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.3725f, 0.6196f, 0.6275f)));
                glDrawArrays(polygonMode, 0, 36);

                mat4 baserightMatrixSonia = translate(mat4(1.0f), vec3(3.0f, 5.5f, 0.25f)) *
                                            rotate(mat4(1.0f), radians(35.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                            scale(mat4(1.0f), vec3(1.5f, 0.35f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * baserightMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.3725f, 0.6196f, 0.6275f)));
                glDrawArrays(polygonMode, 0, 36);

                mat4 baseleftMatrixSonia = translate(mat4(1.0f), vec3(1.6f, 5.5f, 0.25f)) *
                                           rotate(mat4(1.0f), radians(145.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                           scale(mat4(1.0f), vec3(1.5f, 0.35f, 0.5f));
                RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                    RacketgroupScaleMatrix;
                modelMatrix = RacketGroupMatrix * baseleftMatrixSonia;
                glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                glUniform3fv(colorLocation, 1, value_ptr(vec3(0.3725f, 0.6196f, 0.6275f)));
                glDrawArrays(polygonMode, 0, 36);

                // horiztonal lines
                for (float i = 0; i < 2; i = i + 0.2) {
                    mat4 HLinesMatrixSonia = translate(mat4(1.0f), vec3(2.3f, i + 5.6f, 0.0f)) *
                                             scale(mat4(1.0f), vec3(2.0f, 0.05f, 0.05f));
                    RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                        RacketgroupScaleMatrix;
                    modelMatrix = RacketGroupMatrix * HLinesMatrixSonia;
                    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                    glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
                    glDrawArrays(polygonMode, 0, 36);
                }

                //vertical lines
                for (float i = 0; i < 1.8; i = i + 0.2) {
                    mat4 VLinesMatrixSonia = translate(mat4(1.0f), vec3(i + 1.5f, 6.5f, 0.0f)) *
                                             rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 0.0f, 1.0f)) *
                                             scale(mat4(1.0f), vec3(0.05f, 2.5f, 0.05f));
                    RacketGroupMatrix = LowerArmGroupMatrix * RacketgroupTransferMatrix * RacketgroupRotationMatrix *
                                        RacketgroupScaleMatrix;
                    modelMatrix = RacketGroupMatrix * VLinesMatrixSonia;
                    glUniformMatrix4fv(worldmatrix, 1, GL_FALSE, &modelMatrix[0][0]);
                    glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
                    glDrawArrays(polygonMode, 0, 36);
                }

                break;
            }
            default: {
                break;
            }
        }


    }


    void ChangeTennisPosition(mat4 grouptranslate) {
        UpperarmgroupTransferMatrix = grouptranslate;
    }

    void ChangeTennisRotation(mat4 grouprotation) {
        UpperarmgroupRotationMatrix = grouprotation;
    }

    void ChangeTennisScale(mat4 groupscale) {
        UpperarmgroupScaleMatrix = groupscale;
    }

    void ChangeTennisColor(float R, float G, float B) {
        color[0] = R;
        color[1] = G;
        color[2] = B;
    }
    void setPolygoneMode(GLenum polygoneMode) {
        this->polygonMode = polygoneMode;
    }

    void changeShader(int shader_id) {
        this->texturedshader = shader_id;
    }

    mat4 UpperarmgroupTransferMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));;
    mat4 UpperarmgroupRotationMatrix = rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 1.0f, 0.0f));
    mat4 UpperarmgroupScaleMatrix = scale(mat4(1.0f), vec3(1.0f, 1.0f, 1.0f));


    mat4 LowerarmgroupTransferMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));;
    mat4 LowerarmgroupRotationMatrix = rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 1.0f, 0.0f));
    mat4 LowerarmgroupScaleMatrix = scale(mat4(1.0f), vec3(1.0f, 1.0f, 1.0f));

    mat4 RacketgroupTransferMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));;
    mat4 RacketgroupRotationMatrix = rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 1.0f, 0.0f));
    mat4 RacketgroupScaleMatrix = scale(mat4(1.0f), vec3(1.0f, 1.0f, 1.0f));

    mat4 UpperArmCurrentPosition = mat4(1.0f);
    mat4 CurrentPosition = mat4(1.0f);
    char letter;
private:

    mat4 UpperArmGroupMatrix = mat4(1.0f);
    mat4 LowerArmGroupMatrix = mat4(1.0f);
    mat4 RacketGroupMatrix = mat4(1.0f);

    GLuint worldmatrix;
    GLuint colorLocation;
    GLenum polygonMode = GL_TRIANGLES;
    mat4 modelMatrix;
    mat4 MiddleCoord;
    float color[3] = { 0.0,0.0,0.0 };

    int texturedshader;
    int ID;
};



int main(int argc, char* argv[]) {
    if (!initContext()) return -1;
    // Load Textures
    GLuint clayTextureID = loadTexture("../Assets/textures/clay.jpg");
    GLuint glossyTextureID = loadTexture("../Assets/textures/glossy.jpg");
    GLuint greenTextureID = loadTexture("../Assets/textures/green.jpg");

    GLuint metalTextureID = loadTexture("../Assets/textures/metal.jpg");
    GLuint treeTextureID = loadTexture("../Assets/textures/tree.jpg");


    GLuint racket1TextureID = loadTexture("../Assets/textures/letter1.png");
    GLuint racket2TextureID = loadTexture("../Assets/textures/letter2.jpg");
    GLuint racket3TextureID = loadTexture("../Assets/textures/letter4.jpg");
    // Setup models
#if defined(PLATFORM_OSX)
    string heraclesPath = "Models/heracles.obj";
    string cubePath = "Models/cube.obj";
#else
    string heraclesPath = "../Assets/Models/trees.obj";
    string cubePath = "../Assets/Models/cube.obj";
#endif




    // Background Color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    int heraclesVertices;
    GLuint heraclesVAO = setupModelEBO(heraclesPath, heraclesVertices);

    int activeVertices = heraclesVertices;
    GLuint activeVAO = heraclesVAO;
    int shaderProgram = compileAndLinkShaders();
    int depthShaderProgram = compileAndLinkDepthShaders(getDepthVertexShaderSource(), getDepthFragmentShaderSource());
    int texturedShaderProgram = shaderProgram;
    //compileAndLinkTexturedShaders(getVertexShaderSource(), getFragmentShaderSource());
    GLuint textureswitch = glGetUniformLocation(texturedShaderProgram, "useTexture");
    GLuint textureswitch1 = glGetUniformLocation(texturedShaderProgram, "useTexture1");
    int istextureinuse = 0;
    int istextureinuse1 = 0;
    // We can set the shader once, since we have only one
    glEnable(GL_CULL_FACE);
    glUseProgram(texturedShaderProgram);
    glUseProgram(depthShaderProgram);
    glUseProgram(shaderProgram);


    glUseProgram(texturedShaderProgram);

    // We can set the shader once, since we have only one
    glEnable(GL_CULL_FACE);
    glUseProgram(shaderProgram);
    GLuint colorLocation = glGetUniformLocation(shaderProgram, "objectColor");
    // Camera parameters for view transform
    vec3 cameraPosition(10.0f, 10.0f, 10.0f);
    vec3 cameraLookAt(0.0f, 0.0f, -1.0f); // Set the look at position to the origin
    vec3 cameraUp(0.0f, 1.0f, 0.0f);
    vec3 lightPos(20.0f, 50.0f, 0.0f);
    GLuint lightLocation = glGetUniformLocation(shaderProgram, "lightPos");
    glUniform3fv(lightLocation, 1, &lightPos[0]);

    // Other camera parameters
    float cameraSpeed = 1.0f;
    float cameraFastSpeed = 2 * cameraSpeed;
    float cameraHorizontalAngle = 90.0f;
    float cameraVerticalAngle = 0.0f;
    float fov = 100.0f;

    mat4 projectionMatrix1 = glm::perspective(fov, // field of view in degrees
                                              1024.0f / 768.0f,  // aspect ratio
                                              0.01f, 100.0f);   // near and far (near > 0)
    // Set projection matrix for shader, this won't change
    GLuint projectionMatrixLocation1 = glGetUniformLocation(shaderProgram, "projectionMatrix1");
    glUniformMatrix4fv(projectionMatrixLocation1, 1, GL_FALSE, &projectionMatrix1[0][0]);
    mat4 projectionMatrix = glm::perspective(70.0f,            // field of view in degrees
                                             1024.0f / 768.0f,  // aspect ratio
                                             0.01f, 100.0f);   // near and far (near > 0)

    GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");

    GLuint projectionMatrixLocation_t = glGetUniformLocation(texturedShaderProgram, "projectionMatrix");
    glUniformMatrix4fv(projectionMatrixLocation_t, 1, GL_FALSE, &projectionMatrix[0][0]);

    mat4 viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);


    glUseProgram(shaderProgram);
    GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

    glUseProgram(texturedShaderProgram);
    GLuint viewMatrixLocation_t = glGetUniformLocation(texturedShaderProgram, "viewMatrix");
    glUniformMatrix4fv(viewMatrixLocation_t, 1, GL_FALSE, &viewMatrix[0][0]);


    //modifications
    mat4 WorldRotation = rotate(mat4(1.0f), radians(0.0f), vec3(1.0f, 1.0f, 1.0f));
    mat4 WorldRotationDeffault = WorldRotation;

    GLuint worldMatrixLocation = glGetUniformLocation(shaderProgram, "worldMatrix");
    GLuint WorldMatrixRotation = glGetUniformLocation(shaderProgram, "WorldRotationMatrix");
    GLenum polygonMode = GL_TRIANGLES;
    // create sphere object
    Ball b1;



    //Create Tennis Objects

    Tennis T1(worldMatrixLocation, colorLocation, polygonMode, texturedShaderProgram, 1, 'p');
    Tennis T2(worldMatrixLocation, colorLocation, polygonMode, texturedShaderProgram, 2, 'y');
    Tennis T3(worldMatrixLocation, colorLocation, polygonMode, texturedShaderProgram, 3, 's');

    T1.ChangeTennisPosition(translate(mat4(1.0f), vec3(0.0f, 0.0f, 3.0f)));
    T2.ChangeTennisPosition(translate(mat4(1.0f), vec3(6.0f, 0.0f, 3.0f)) * scale(mat4(1.0f), vec3(0.35f, 0.35f, 0.35f)));
    T3.ChangeTennisPosition(translate(mat4(1.0f), vec3(-6.0f, 0.0f, 3.0f))) ;

    Tennis* TCurrent = new Tennis();
    TCurrent = &T1;
    mat4* CurrentTranslationMatrix = &TCurrent->UpperarmgroupTransferMatrix;
    mat4* CurrentRotationMatrix = &TCurrent->UpperarmgroupRotationMatrix;
    mat4* CurrentScaleMatrix = &TCurrent->UpperarmgroupScaleMatrix;

    // Define and upload geometry to the GPU here ...
//    int vao = createVertexArrayObject();
    int texturedCubeVAO = createTexturedCubeVertexArrayObject();
    int sphereVAO = b1.createSphereObject();
    int previousSpaceState = GLFW_RELEASE;
    int previousMouseRightState = GLFW_RELEASE;
    int previousMouseLeftState = GLFW_RELEASE;
    int previousMouseMiddleState = GLFW_RELEASE;
    int previousXState = GLFW_RELEASE;
    int previousBState = GLFW_RELEASE;
    double previousMousePosX, previousMousePosY;
    glfwGetCursorPos(window, &previousMousePosX, &previousMousePosY);
    // For frame time
    float previousFrameTime = glfwGetTime();

    // Other OpenGL states to set once before the Game Loop
    // Enable Backface culling
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    float worldXAngle = 0.0f;
    float worldYAngle = 0.0f;

    //World Orientation
    mat4 worldOrientation = rotate(mat4(1.0f), radians(0.0f), vec3(1.0f, 1.0f, 1.0f));
    mat4 worldOrientationInitial = worldOrientation;
    GLuint depthMapFBO;// store the depth value
    glGenFramebuffers(1, &depthMapFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    GLuint depthTexture;
    glGenTextures(1, &depthTexture);
    glBindTexture(GL_TEXTURE_2D, depthTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);
    glDrawBuffer(GL_NONE);
    GLint frameBufferWidth, frameBufferHeight;
    glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
    GLuint worldLocationMatrix = glGetUniformLocation(shaderProgram, "worldMatrix");
    GLuint lightSpaceMatrixLocation = glGetUniformLocation(shaderProgram, "lightSpaceMatrix");
    GLuint lightSpaceMatrixDepthLocation = glGetUniformLocation(depthShaderProgram, "lightSpaceMatrix");
    while (!glfwWindowShouldClose(window)) {



        // Frame time calculation
        float dt = glfwGetTime() - previousFrameTime;
        previousFrameTime += dt;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /// first pass
        glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
        glBindVertexArray(texturedCubeVAO);
        glViewport(0, 0, 1024, 1024);
        glClear(GL_DEPTH_BUFFER_BIT);
        glUseProgram(depthShaderProgram);

        GLuint depthWorldMatrixLocation = glGetUniformLocation(depthShaderProgram, "worldMatrix");

        //        glActiveTexture(GL_TEXTURE0);
        //        glBindTexture(GL_TEXTURE_2D, depthTexture);

        //        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        mat4 lightViewMatrix, lightProjectionMatrix;
        lightViewMatrix = lookAt(lightPos, vec3(0.0f), vec3(0.0f, 1.0f, 0.0f));
        lightProjectionMatrix = ortho(-50.0f, 50.0f, -50.0f, 50.0f, 0.1f, 200.0f);
        mat4 lightSpaceMatrix = lightProjectionMatrix * lightViewMatrix;
        glUniformMatrix4fv(lightSpaceMatrixDepthLocation, 1, GL_FALSE, &lightSpaceMatrix[0][0]);

        //draw first pass
//        glBindVertexArray(texturedCubeVAO);
        mat4 groundTennisMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)) * scale(mat4(1.0f), vec3(36.0f, 0.02f, 78.0f));
        glUniformMatrix4fv(depthWorldMatrixLocation, 1, GL_FALSE, &groundTennisMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(0.39, 0.67, 0.15)));
        glDrawArrays(GL_TRIANGLES, 0, 36); // 36 vertices, starting at index 0

        glBindVertexArray(sphereVAO);
        mat4 SphereWorldMatrix = translate(mat4(1.0f), vec3(0.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(depthWorldMatrixLocation, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);

        SphereWorldMatrix = translate(mat4(1.0f), vec3(6.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(depthWorldMatrixLocation, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);

        SphereWorldMatrix = translate(mat4(1.0f), vec3(-6.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(depthWorldMatrixLocation, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);
        // Set light and material properties here, before drawing the mesh
        // You might set these once per frame, or even multiple times per frame if your light or material properties change

        glBindVertexArray(texturedCubeVAO);
        MidSectionCreation(depthWorldMatrixLocation, colorLocation);

        T1.changeWorldMatrix(depthWorldMatrixLocation);
        T1.changeShader(depthShaderProgram);
        T1.Draw(metalTextureID, metalTextureID, racket1TextureID);
        T1.changeWorldMatrix(worldMatrixLocation);

        T2.changeWorldMatrix(depthWorldMatrixLocation);
        T2.changeShader(depthShaderProgram);
        T2.Draw(metalTextureID, metalTextureID, racket2TextureID);
        T2.changeWorldMatrix(worldMatrixLocation);

        T3.changeWorldMatrix(depthWorldMatrixLocation);
        T3.changeShader(depthShaderProgram);
        T3.Draw(metalTextureID, metalTextureID, racket3TextureID);
        T3.changeWorldMatrix(worldMatrixLocation);


        ///// second passs

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(texturedShaderProgram);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, depthTexture);
        glUniform1i(glGetUniformLocation(texturedShaderProgram, "shadowMap"), 0);

        glUniformMatrix4fv(lightSpaceMatrixLocation, 1, GL_FALSE, &lightSpaceMatrix[0][0]);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, glossyTextureID);
        GLuint textureLocation = glGetUniformLocation(texturedShaderProgram, "textureSampler");
        GLuint textureshaderworld = glGetUniformLocation(texturedShaderProgram, "worldMatrix");

        glUniform1i(textureLocation, 1);
        glBindVertexArray(texturedCubeVAO);

        T1.changeShader(texturedShaderProgram);
        T1.Draw(metalTextureID, metalTextureID, racket1TextureID);
        T2.changeShader(texturedShaderProgram);
        T2.Draw(metalTextureID, metalTextureID, racket2TextureID);
        T3.changeShader(texturedShaderProgram);
        T3.Draw(metalTextureID, metalTextureID, racket3TextureID);


        glBindTexture(GL_TEXTURE_2D, greenTextureID);
        glBindVertexArray(sphereVAO);
        SphereWorldMatrix = translate(mat4(1.0f), vec3(0.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);

        SphereWorldMatrix = translate(mat4(1.0f), vec3(6.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);

        SphereWorldMatrix = translate(mat4(1.0f), vec3(-6.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);
        // Set light and material properties here, before drawing the mesh
        // You might set these once per frame, or even multiple times per frame if your light or material properties change



        //

        glUseProgram(shaderProgram);
        glBindTexture(GL_TEXTURE_2D, clayTextureID);
        glBindVertexArray(texturedCubeVAO);
        mat4 groundWorldMatrix = translate(mat4(1.0f), vec3(0.0f, -0.01f, 0.0f)) * scale(mat4(1.0f), vec3(100.0f, 0.02f, 100.0f));
        GLuint worldLocationMatrix = glGetUniformLocation(shaderProgram, "worldMatrix");
        GLuint WorldMatrixRotation = glGetUniformLocation(shaderProgram, "worldOrientationMatrix");



        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, &groundWorldMatrix[0][0]);
        glUniformMatrix4fv(WorldMatrixRotation, 1, GL_FALSE, &worldOrientation[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawArrays(GL_TRIANGLES, 0, 36); // 36 vertices, starting at index 0


        //DrawGrid

        glBindVertexArray(texturedCubeVAO);
        glUseProgram(texturedShaderProgram);
        textureLocation = glGetUniformLocation(texturedShaderProgram, "textureSampler");
        textureshaderworld = glGetUniformLocation(texturedShaderProgram, "worldMatrix");
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, clayTextureID);

        glUniform1i(textureLocation, 1);
        mat4 tempworldmatrix = mat4(1.0f);
        glUniformMatrix4fv(textureshaderworld, 1, GL_FALSE, &tempworldmatrix[0][0]);

        DrawGrid(worldLocationMatrix, colorLocation, texturedShaderProgram);
        DrawCoordinates(worldLocationMatrix, colorLocation, worldXAngle, worldYAngle);

        glBindVertexArray(texturedCubeVAO);
        glBindTexture(GL_TEXTURE_2D, clayTextureID);
        groundTennisMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)) * scale(mat4(1.0f), vec3(36.0f, 0.02f, 78.0f));
        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, &groundTennisMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(0.0, 0.0, 0.0)));
        //  glDrawArrays(GL_TRIANGLES, 0, 36); // 36 vertices, starting at index 0

        glBindVertexArray(texturedCubeVAO);
        glUseProgram(texturedShaderProgram);
        textureLocation = glGetUniformLocation(texturedShaderProgram, "textureSampler");
        textureshaderworld = glGetUniformLocation(texturedShaderProgram, "worldMatrix");
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, greenTextureID);
        glUniform1i(textureLocation, 1);
        tempworldmatrix = mat4(1.0f);
        glUniformMatrix4fv(textureshaderworld, 1, GL_FALSE, &tempworldmatrix[0][0]);

        glBindVertexArray(sphereVAO);
        SphereWorldMatrix = translate(mat4(1.0f), vec3(0.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);

        SphereWorldMatrix = translate(mat4(1.0f), vec3(6.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);

        SphereWorldMatrix = translate(mat4(1.0f), vec3(-6.0f, 8.0f, 6.0f));
        glUniformMatrix4fv(worldLocationMatrix, 1, GL_FALSE, &SphereWorldMatrix[0][0]);
        glUniform3fv(colorLocation, 1, value_ptr(vec3(1.0, 1.0, 1.0)));
        glDrawElements(GL_TRIANGLE_STRIP, b1.indexCount, GL_UNSIGNED_INT, 0);

        glBindVertexArray(texturedCubeVAO);
        glBindTexture(GL_TEXTURE_2D, glossyTextureID);

        T1.changeShader(texturedShaderProgram);
        T1.Draw(metalTextureID, metalTextureID, glossyTextureID);
        T2.Draw(metalTextureID, metalTextureID, metalTextureID);
        T3.Draw(metalTextureID, metalTextureID, metalTextureID);

        //Create BALL
        glBindVertexArray(texturedCubeVAO);
        glUseProgram(texturedShaderProgram);
        glActiveTexture(GL_TEXTURE1);
        textureLocation = glGetUniformLocation(texturedShaderProgram, "textureSampler");
        textureshaderworld = glGetUniformLocation(texturedShaderProgram, "worldMatrix");

        glUniform1i(textureLocation, 1);

        tempworldmatrix = mat4(1.0f);
        glUniformMatrix4fv(textureshaderworld, 1, GL_FALSE, &worldOrientation[0][0]);

        glBindTexture(GL_TEXTURE_2D, greenTextureID);
        glBindVertexArray(texturedCubeVAO);
        glUseProgram(texturedShaderProgram);
        textureLocation = glGetUniformLocation(texturedShaderProgram, "textureSampler");
        textureshaderworld = glGetUniformLocation(texturedShaderProgram, "worldMatrix");
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, metalTextureID);
        glUniform1i(textureLocation, 1);
        tempworldmatrix = mat4(1.0f);
        glUniformMatrix4fv(textureshaderworld, 1, GL_FALSE, &tempworldmatrix[0][0]);

        MidSectionCreation(worldLocationMatrix, colorLocation);


        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, greenTextureID);
        glUniform1i(textureLocation, 1);
        tempworldmatrix = translate(mat4(1.0f), vec3(0.0f, 10.0f, 0.0f))* glm::rotate(mat4(1.0f), glm::radians(180.0f), glm::vec3(0,-1,0))*scale(mat4(1.0f), vec3(0.05f, 0.05f, 0.05f));;
        glUniformMatrix4fv(textureshaderworld, 1, GL_FALSE, &tempworldmatrix[0][0]);



        glBindVertexArray(activeVAO);
        // Draw geometry
        glDrawElements(GL_TRIANGLE_STRIP, activeVertices, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, activeVertices);
        // Unbind geometry
        glBindVertexArray(0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, greenTextureID);
        tempworldmatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 30.0f)) * glm::rotate(mat4(1.0f), glm::radians(180.0f), glm::vec3(0, 1, 0)) * scale(mat4(1.0f), vec3(0.90f, 0.90f, 0.90f));;
        glUniformMatrix4fv(textureshaderworld, 1, GL_FALSE, &tempworldmatrix[0][0]);



        glBindVertexArray(activeVAO);
        // Draw geometry
        //  glDrawElements(GL_TRIANGLES, activeVertices, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, activeVertices);
        // Unbind geometry
        glBindVertexArray(0);














        glUseProgram(shaderProgram);

        // CLose with escape
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }


        // Pressing the spacebar: re-position the model at a random location on the grid.

        if (previousSpaceState == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) // move camera to the left
        {
            int ub = 20;
            int lb = -20;
            int random[3];
            for (int i = 0; i < 3; i++) {
                random[i] = (rand() % (ub - lb + 1)) + lb;
            }
            *CurrentTranslationMatrix = translate(mat4(1.0f), vec3(random[0] + 0.0f, random[1] + 0.0f, random[2] + 0.0f));
        }
        previousSpaceState = glfwGetKey(window, GLFW_KEY_SPACE);

        //Getting which Tennis to move
        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) // move left
        {
            TCurrent = &T1;

        }
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) // move left
        {
            TCurrent = &T2;
        }
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) // move left
        {
            TCurrent = &T3;
        }


        //Getting to pick Wich part to move

        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) // move left
        {
            CurrentTranslationMatrix = &TCurrent->UpperarmgroupTransferMatrix;
            CurrentRotationMatrix = &TCurrent->UpperarmgroupRotationMatrix;
            CurrentScaleMatrix = &TCurrent->UpperarmgroupScaleMatrix;

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) // move left
        {
            CurrentTranslationMatrix = &TCurrent->LowerarmgroupTransferMatrix;
            CurrentRotationMatrix = &TCurrent->LowerarmgroupRotationMatrix;
            CurrentScaleMatrix = &TCurrent->LowerarmgroupScaleMatrix;

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) // move left
        {
            CurrentTranslationMatrix = &TCurrent->RacketgroupTransferMatrix;
            CurrentRotationMatrix = &TCurrent->RacketgroupRotationMatrix;
            CurrentScaleMatrix = &TCurrent->RacketgroupScaleMatrix;

        }
        //The user can control the model position and orientation using keyboard input i.e.
        // A → move left
        // D → move right
        // W → move up
        // S → move down,
        // a → rotate left 5 degrees about Y axi
        // d → rotate right 5 degrees about Y axis.

        //Translations
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) // move left
        {
            *CurrentTranslationMatrix = *CurrentTranslationMatrix * translate(mat4(1.0f), vec3(-0.05f, 0.0f, 0.0f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) // move right
        {
            *CurrentTranslationMatrix = *CurrentTranslationMatrix * translate(mat4(1.0f), vec3(+0.05f, 0.0f, 0.0f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) // move up
        {
            *CurrentTranslationMatrix = *CurrentTranslationMatrix * translate(mat4(1.0f), vec3(0.0f, 0.05f, 0.0f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) // move down
        {
            *CurrentTranslationMatrix = *CurrentTranslationMatrix * translate(mat4(1.0f), vec3(0.0f, -0.05f, 0.0f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) // move forward
        {
            *CurrentTranslationMatrix = *CurrentTranslationMatrix * translate(mat4(1.0f), vec3(0.0f, 0.0f, -0.05f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) // move backward
        {
            *CurrentTranslationMatrix = *CurrentTranslationMatrix * translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.05f));

        }

        //Rotations
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) // rotate left on y-axis
        {
            *CurrentRotationMatrix = *CurrentRotationMatrix * rotate(mat4(1.0f), radians(1.0f), vec3(0.0f, 1.0f, 0.0f)) * translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) // rotate right on y-axis
        {
            *CurrentRotationMatrix = *CurrentRotationMatrix * rotate(mat4(1.0f), radians(-1.0f), vec3(0.0f, 1.0f, 0.0f)) * translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) // rotate left on z-axis
        {
            *CurrentRotationMatrix = *CurrentRotationMatrix * rotate(mat4(1.0f), radians(1.0f), vec3(0.0f, 0.0f, 1.0f)) * translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) // rotate right on z-axis
        {
            *CurrentRotationMatrix = *CurrentRotationMatrix * rotate(mat4(1.0f), radians(-1.0f), vec3(0.0f, 0.0f, 1.0f)) * translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));

        }

        //The user can incrementally size up the model
        // - pressing ‘U’ for scale-up
        //- ‘J’ for scale-down. Each key press should result in a small size change.
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) // rotate left
        {
            *CurrentScaleMatrix = *CurrentScaleMatrix * scale(mat4(1.0f), vec3(1.1f, 1.1f, 1.1f));

        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) // rotate right
        {
            *CurrentScaleMatrix = *CurrentScaleMatrix * scale(mat4(1.0f), vec3(0.99f, 0.99f, 0.99f));

        }

        //- The world orientation is changed by using keyboard input i.e.
        //    - left arrow → Rx
        //    - right arrow → R-x
        //    - up arrow → Ry
        //    - down arrow → R-y
        //    - (Rx denotes a small anti-clockwise rotation about positive x axis, R-x about negative x axis, etc.)
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        {
            worldOrientation = worldOrientation * rotate(mat4(1.0f), radians(1.5f), vec3(1.0f, 0.0f, 0.0f));
            glUniformMatrix4fv(WorldMatrixRotation, 1, GL_FALSE, &worldOrientation[0][0]);
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        {
            worldOrientation = worldOrientation * rotate(mat4(1.0f), radians(-1.5f), vec3(1.0f, 0.0f, 0.0f));
            glUniformMatrix4fv(WorldMatrixRotation, 1, GL_FALSE, &worldOrientation[0][0]);
        }
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        {
            worldOrientation = worldOrientation * rotate(mat4(1.0f), radians(1.5f), vec3(0.0f, 1.0f, 0.0f));
            glUniformMatrix4fv(WorldMatrixRotation, 1, GL_FALSE, &worldOrientation[0][0]);
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        {
            worldOrientation = worldOrientation * rotate(mat4(1.0f), radians(-1.5f), vec3(0.0f, 1.0f, 0.0f));
            glUniformMatrix4fv(WorldMatrixRotation, 1, GL_FALSE, &worldOrientation[0][0]);
        }
        if (glfwGetKey(window, GLFW_KEY_HOME) == GLFW_PRESS)
        {
            worldOrientation = WorldRotationDeffault;
            glUniformMatrix4fv(WorldMatrixRotation, 1, GL_FALSE, &worldOrientation[0][0]);

            *CurrentTranslationMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
            *CurrentRotationMatrix = rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 1.0f, 0.0f));
            *CurrentScaleMatrix = scale(mat4(1.0f), vec3(1.0f, 1.0f, 1.0f));
        }


        //Polygone view

        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) // move camera to the left
        {
            polygonMode = GL_POINTS;
            TCurrent->setPolygoneMode(polygonMode);
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) // move camera to the left
        {
            polygonMode = GL_LINES;
            TCurrent->setPolygoneMode(polygonMode);
        }
        if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) // move camera to the left
        {
            polygonMode = GL_TRIANGLES;
            TCurrent->setPolygoneMode(polygonMode);
        }
        float displacement = 0.0;

        if (previousXState == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) // scale down
        {
            glUseProgram(texturedShaderProgram);
            if (istextureinuse == 0) {
                istextureinuse = 1;
                glUniform1i(textureswitch, istextureinuse);
            }
            else {
                istextureinuse = 0;
                glUniform1i(textureswitch, istextureinuse);
            }
            glUseProgram(0);
            shaderProgram = texturedShaderProgram;

        }
        previousXState = glfwGetKey(window, GLFW_KEY_X);


        if (previousBState == GLFW_RELEASE && glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) // scale down
        {
            glUseProgram(texturedShaderProgram);
            if (istextureinuse1 == 0) {
                istextureinuse1 = 1;
                glUniform1i(textureswitch1, istextureinuse1);
            }
            else {
                istextureinuse1 = 0;
                glUniform1i(textureswitch1, istextureinuse1);
            }
            glUseProgram(0);
            shaderProgram = texturedShaderProgram;

        }
        previousBState = glfwGetKey(window, GLFW_KEY_B);



        glBindVertexArray(0);

        // End Frame
        glfwSwapBuffers(window);
        glfwPollEvents();


        double mousePosX, mousePosY;
        glfwGetCursorPos(window, &mousePosX, &mousePosY);

        double dx = mousePosX - previousMousePosX;
        double dy = mousePosY - previousMousePosY;

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
        {
            dy = 0;
        }

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS)
        {
            dx = 0;
        }

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            if (dy > 0)
            {
                fov += 0.1;
                projectionMatrix = glm::perspective(glm::radians(fov),
                                                    1024.0f / 768.0f,
                                                    0.01f, 100.0f);

                GLuint projectionMatriLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
                glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]);
                dy = 0;
                dx = 0;
            }

            if (dy < 0)
            {
                fov -= 0.1;
                projectionMatrix = glm::perspective(glm::radians(fov),
                                                    1024.0f / 768.0f,
                                                    0.01f, 100.0f);

                GLuint projectionMatriLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
                glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]);
                dy = 0;
                dx = 0;
            }
        }
        previousMouseLeftState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        previousMouseRightState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
        previousMouseMiddleState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE);

        previousMousePosX = mousePosX;
        previousMousePosY = mousePosY;

        // Convert to spherical coordinates
        const float cameraAngularSpeed = 60.0f;
        cameraHorizontalAngle -= dx * cameraAngularSpeed * dt;
        cameraVerticalAngle -= dy * cameraAngularSpeed * dt;

        // Clamp vertical angle to [-85, 85] degrees
        cameraVerticalAngle = std::max(-85.0f, std::min(85.0f, cameraVerticalAngle));
        if (cameraHorizontalAngle > 360)
        {
            cameraHorizontalAngle -= 360;
        }
        else if (cameraHorizontalAngle < -360)
        {
            cameraHorizontalAngle += 360;
        }

        float theta = radians(cameraHorizontalAngle);
        float phi = radians(cameraVerticalAngle);

        cameraLookAt = vec3(cosf(phi) * cosf(theta), sinf(phi), -cosf(phi) * sinf(theta));
        vec3 cameraSideVector = glm::cross(cameraLookAt, vec3(0.0f, 1.0f, 0.0f));

        glm::normalize(cameraSideVector);

        viewMatrix = lookAt(cameraPosition, cameraPosition + cameraLookAt, cameraUp);

        GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

        // Create a point light


        // ... (Initialize your shaders and objects here)

        // Before rendering, update the light properties in the shader



        glUseProgram(shaderProgram);
        GLuint viewMatrixLocation_m = glGetUniformLocation(shaderProgram, "viewMatrix");
        glUniformMatrix4fv(viewMatrixLocation_m, 1, GL_FALSE, &viewMatrix[0][0]);
        glUseProgram(texturedShaderProgram);
        GLuint viewMatrixLocation_mt = glGetUniformLocation(texturedShaderProgram, "viewMatrix");
        glUniformMatrix4fv(viewMatrixLocation_mt, 1, GL_FALSE, &viewMatrix[0][0]);
        glUseProgram(0);

    }


    // Shutdown GLFW
    glfwTerminate();

    return 0;
}

GLuint setupModelVBO(string path, int& vertexCount) {
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> UVs;

    // read the vertex data from the model's OBJ file
    loadOBJ(path.c_str(), vertices, normals, UVs);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);  // Becomes active VAO
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and
    // attribute pointer(s).

    // Vertex VBO setup
    GLuint vertices_VBO;
    glGenBuffers(1, &vertices_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertices_VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
                 &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                          (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Normals VBO setup
    GLuint normals_VBO;
    glGenBuffers(1, &normals_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, normals_VBO);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3),
                 &normals.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                          (GLvoid*)0);
    glEnableVertexAttribArray(1);

    // UVs VBO setup
    GLuint uvs_VBO;
    glGenBuffers(1, &uvs_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, uvs_VBO);
    glBufferData(GL_ARRAY_BUFFER, UVs.size() * sizeof(glm::vec2), &UVs.front(),
                 GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat),
                          (GLvoid*)0);
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
    // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent
    // strange bugs, as we are using multiple VAOs)
    vertexCount = vertices.size();
    return VAO;
}

GLuint setupModelEBO(string path, int& vertexCount) {
    vector<int> vertexIndices;
    // The contiguous sets of three indices of vertices, normals and UVs, used to
    // make a triangle
    vector<glm::vec3> vertices;
    vector<glm::vec3> normals;
    vector<glm::vec2> UVs;

    // read the vertices from the cube.obj file
    // We won't be needing the normals or UVs for this program
    loadOBJ2(path.c_str(), vertexIndices, vertices, normals, UVs);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);  // Becomes active VAO
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and
    // attribute pointer(s).

    // Vertex VBO setup
    GLuint vertices_VBO;
    glGenBuffers(1, &vertices_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertices_VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
                 &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                          (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Normals VBO setup
    GLuint normals_VBO;
    glGenBuffers(1, &normals_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, normals_VBO);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3),
                 &normals.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                          (GLvoid*)0);
    glEnableVertexAttribArray(1);

    // UVs VBO setup
    GLuint uvs_VBO;
    glGenBuffers(1, &uvs_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, uvs_VBO);
    glBufferData(GL_ARRAY_BUFFER, UVs.size() * sizeof(glm::vec2), &UVs.front(),
                 GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat),
                          (GLvoid*)0);
    glEnableVertexAttribArray(2);

    // EBO setup
    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexIndices.size() * sizeof(int),
                 &vertexIndices.front(), GL_STATIC_DRAW);

    glBindVertexArray(0);
    // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent
    // strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO
    vertexCount = vertexIndices.size();
    return VAO;
}