#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Basic.h"

int main(void)
{
    Window window("Gui test");
    window.setOpenGlVersion(4, 4, GLFW_OPENGL_CORE_PROFILE);


    Shader shader("Basic.glsl");
    shader.bind();

    float positions[] = 
    { 
        0.f, 0.f,
        1.f, 0.f,
        1.f, 1.f,
        0.f, 1.f,
    };

    float color[] =
    {
        0.2f, 0.4f, 0.3f, 1.f,
        0.2f, 0.4f, 0.3f, 1.f,
        0.2f, 0.4f, 0.3f, 1.f,
        0.2f, 0.4f, 0.3f, 1.f,
    };

    unsigned int indices[] = 
    {
        0, 1, 2, 3
    };

    VertexArray vao;
    VertexBuffer pos(positions, sizeof(positions), 0, 2);
    VertexBuffer col(color, sizeof(color), 1, 4);
    IndexBuffer ibo(indices, sizeof(indices));

    vao.unbind();
    pos.unbind();
    col.unbind();
    ibo.unbind();

    glm::mat4 model = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, 0));
    glm::mat4 projection = glm::ortho(0.f, 1.f, 0.f, 1.f);
    glm::mat4 scale = glm::scale(glm::mat4(1.f), glm::vec3(0.5f, 0.5f, 1.f));
    glm::mat4 mvp = projection * model * scale;

    while (!glfwWindowShouldClose(window.windowID)) 
    {
        /* update uniforms */
        shader.setUniformMat4f("MVP", mvp);

        /* Render here */
        Renderer::clear();

        Renderer::draw(&vao, GL_POLYGON, sizeof(indices) / sizeof(unsigned int));

        /* Swap front and back buffers */
        glfwSwapBuffers(window.windowID);

        /* Poll for and process events */
        glfwPollEvents();
        vao.unbind();
    }

    glfwTerminate();
    return 0;
}