cmake_minimum_required(VERSION 3.19)
add_subdirectory(third_party)
project(SampleProject)


set(SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} glew_s glfw glm)


install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)