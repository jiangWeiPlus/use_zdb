cmake_minimum_required(VERSION 2.8)
project("project1") 

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON) 

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE ON)

set(PROJECT_PATH /home/jiang/smb/cpp_demo/project1)

set(THIRD_PATH ${PROJECT_PATH}/third)
set(ZDB_INCLUDE ${THIRD_PATH}/zdb/include/zdb)
set(ZDB_LIB ${THIRD_PATH}/zdb/lib) 

# -I 
include_directories(${ZDB_INCLUDE}) 

# -L 
link_directories(${ZDB_LIB}) 

# -l 
#target_link_libraries(zdb)

add_subdirectory(src)



