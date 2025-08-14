cmake_minimum_required(VERSION 3.16)
project(dsa_playground LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/bin)
foreach(cfg IN ITEMS Debug Release RelWithDebInfo MinSizeRel)
  string(TOUPPER "${cfg}" CFG)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CFG} ${CMAKE_SOURCE_DIR}/out/lib/${cfg})
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CFG} ${CMAKE_SOURCE_DIR}/out/lib/${cfg})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CFG} ${CMAKE_SOURCE_DIR}/out/bin/${cfg})
endforeach()

add_library(dsa_core STATIC)
target_include_directories(dsa_core PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(dsa_core PUBLIC cxx_std_17)

file(GLOB_RECURSE DSA_SOURCES
     CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/data_structures/*.cpp
     ${CMAKE_SOURCE_DIR}/algorithms/*.cpp
     ${CMAKE_SOURCE_DIR}/src/*.cpp
     ${CMAKE_SOURCE_DIR}/include/*.cpp)
target_sources(dsa_core PRIVATE ${DSA_SOURCES})

file(GLOB APP_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/apps/*.cpp)
if (APP_SOURCES)
  foreach(app_src IN LISTS APP_SOURCES)
    get_filename_component(app_name "${app_src}" NAME_WE)
    add_executable(${app_name} "${app_src}")
    target_link_libraries(${app_name} PRIVATE dsa_core)
    target_include_directories(${app_name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
  endforeach()
else()
  message(WARNING "No apps/*.cpp found. Create apps/source.cpp with a main().")
endif()

include(CTest)
