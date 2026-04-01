cmake_minimum_required(VERSION 3.16)
project(HelloAlgoReplica LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_WARNINGS "Enable strict compiler warnings" ON)
option(ENABLE_ASAN "Enable address sanitizer for GCC/Clang" OFF)

# Keep source and runtime string encoding consistent as UTF-8.
if(MSVC)
    add_compile_options(/utf-8)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

function(enable_project_warnings target_name)
    if(NOT ENABLE_WARNINGS)
        return()
    endif()

    if(MSVC)
        target_compile_options(${target_name} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

function(enable_project_asan target_name)
    if(NOT ENABLE_ASAN)
        return()
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target_name} PRIVATE -fsanitize=address -fno-omit-frame-pointer)
        target_link_options(${target_name} PRIVATE -fsanitize=address)
    endif()
endfunction()

file(GLOB chapter_candidates RELATIVE ${PROJECT_SOURCE_DIR} "chapter_*")
list(SORT chapter_candidates)

foreach(chapter_dir IN LISTS chapter_candidates)
    if(IS_DIRECTORY "${PROJECT_SOURCE_DIR}/${chapter_dir}")
        if(EXISTS "${PROJECT_SOURCE_DIR}/${chapter_dir}/CMakeLists.txt")
            add_subdirectory(${chapter_dir})
        else()
            message(WARNING "Skip ${chapter_dir}: missing CMakeLists.txt")
        endif()
    endif()
endforeach()
