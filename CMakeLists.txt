cmake_minimum_required(VERSION 2.8.8)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(cld2 CXX)

include_directories(${cld2_SOURCE_DIR})

set(OBJ_LIBS cld2)
set(DIRS cld2 tool)

foreach(dir ${DIRS})
    include_directories(${cld2_SOURCE_DIR}/${dir})
endforeach(dir)

foreach(dir ${DIRS})
    add_subdirectory(${dir})
endforeach(dir)
