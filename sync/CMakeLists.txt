cmake_minimum_required(VERSION 3.20)
project(sync)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(sync
	${CMAKE_SOURCE_DIR}/src/main.cpp
	${CMAKE_SOURCE_DIR}/src/sync/Syncs.cpp
	${CMAKE_SOURCE_DIR}/src/sync/Manager.cpp
)

target_include_directories(sync PUBLIC
	${CMAKE_SOURCE_DIR}/thirdparty
)
