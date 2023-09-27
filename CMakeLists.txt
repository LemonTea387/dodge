cmake_minimum_required(VERSION 3.19)

project(
  dodge-platformer
  VERSION 0.1
  DESCRIPTION "A simple platformer... just to test your reflex."
  LANGUAGES CXX
  )

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(dodge-platformer
  src/main.cpp
  src/DodgeGame.cpp
  src/Scene/GameScene.cpp
  )

include_directories(include)
include_directories(SDL2::Headers)
include_directories(SDL2_image::Headers)
target_link_libraries( dodge-platformer PRIVATE
  SDL2::SDL2 SDL2_image::SDL2_image)
