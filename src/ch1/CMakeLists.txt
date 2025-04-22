cmake_minimum_required(VERSION 3.20)

project(fundation)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_FLAGS_DEBUG '-g')
set(CMAKE_BUILD_TYPE Debug)

# 这个是全局设置,对当前CMake中所有的可执行文件都是用
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(argument_deduction src/argument_deduction.cc)
add_executable(return_type src/return_type.cc)

# 这个单个文件设置,只对当前可执行文件使用
# 设置为 PUBLIC 表示,这个头文件引入不光传递给 max,还会在链接时传递给max依赖的其它目标
# 设置为 PRIVATE 表示仅用于编译max或INTERFACE,仅用于依赖者
# target_include_directories(max PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

