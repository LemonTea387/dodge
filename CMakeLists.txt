cmake_minimum_required(VERSION 3.19)

project(
  dodge-platformer
  VERSION 0.1
  DESCRIPTION "A simple platformer... just to test your reflex."
  LANGUAGES CXX
  )

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include(FetchContent)
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(glm)

add_executable(dodge-platformer
  src/main.cpp
  src/DodgeGame.cpp
  src/Scene/GameScene.cpp
  src/Player.cpp
  )

include_directories(include)
include_directories(src)
include_directories(SDL2::Headers)
include_directories(SDL2_image::Headers)
target_include_directories(${PROJECT_NAME} PRIVATE "${glm_SOURCE_DIR}")
target_link_libraries( dodge-platformer PRIVATE
  SDL2::SDL2 SDL2_image::SDL2_image)
