cmake_minimum_required(VERSION 3.0)
project(StaringContest)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
find_package(OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(StaringContest "src/Main.cpp"
							  "src/Game.cpp"
							  "src/Game.hpp"
							  "src/ScoreLoader.cpp"
							  "src/ScoreLoader.hpp")

target_link_libraries(StaringContest sfml-graphics)
target_link_libraries(StaringContest ${OpenCV_LIBS})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
