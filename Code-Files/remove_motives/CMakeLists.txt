cmake_minimum_required(VERSION 3.17)
project(remove_motives)

set(bin_dest "bin")

add_executable(${PROJECT_NAME} )
target_include_directories(${PROJECT_NAME} PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/include" )
target_sources(${PROJECT_NAME} PRIVATE
   src/main
   src/remove_motives

   include/remove_motives/remove_motives.h
   )
target_link_libraries(${PROJECT_NAME} PRIVATE  stdc++)
install(TARGETS ${PROJECT_NAME} DESTINATION "${bin_dest}")
