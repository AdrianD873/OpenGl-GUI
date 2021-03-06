#ifndef TEXT_H
#define TEXT_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <ft2build.h>
#include <freetype/freetype.h>
#include <map>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

#include "Shader.h"
#include "Window.h"

namespace GUI
{

class Text
{
private:
    // settings
    int SCR_WIDTH = 800;
    int SCR_HEIGHT = 600;

    /// Holds all state information relevant to a character as loaded using FreeType
    struct Character {
        unsigned int TextureID; // ID handle of the glyph texture
        glm::ivec2   Size;      // Size of glyph
        glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
        unsigned int Advance;   // Horizontal offset to advance to next glyph
    };

    std::map<GLchar, Character> Characters;
    unsigned int VAO, VBO;

public:
	Text(GLFWwindow* windowID, std::string pathToThisFile = __FILE__);
	~Text();

    unsigned int RenderText(Shader& shader, std::string text, float x, float y, float scaleX, float scaleY, glm::vec3 color);
    unsigned int getAdvancment(std::string);
    unsigned int getMaxHight(std::string text);
};

}//end namespace
#endif