#pragma once
#include <glm/vec2.hpp>
#include <string>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
namespace nano
{
    namespace framework
    {
        class Vertex
        {
        public:
            Vertex() 
            {
                
            }
            Vertex(const glm::vec3& pos, const glm::vec3& col)
                :position(pos)
                , color(col)
            {

            }
        private:
            glm::vec3 position;
            glm::vec3 color;


        };

    }
}
