project( CMakeTemplate )
cmake_minimum_required(VERSION 3.1.0)

include("config/cmaketemplate.cmake")
include("config/deps.cmake")
include("config/install.cmake")

add_subdirectory("modules")
