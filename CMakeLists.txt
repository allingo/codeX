cmake_minimum_required(VERSION 2.8.3)

project(codeX)

set(EXECUTABLE_OUTPUT_PATH "install/bin")
set(CMAKE_INSTALL_PREFIX "install")
include_directories(include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Wall -Werror -Wno-deprecated-declarations")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-deprecated-declarations")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
set(OPENGL_LIBS ${GLUT_LIBRARY} ${OPENGL_LIBRARY})

add_executable(${PROJECT_NAME}
    src/codeX_main.cc
    src/codeX_opengl_wrapper.cc
    src/codeX_opengl_wrapper.h)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBS})

install(TARGETS codeX DESTINATION bin)
install(FILES
    src/shader/vertext.vert
    src/shader/fragment.frag
    DESTINATION shader)
