cmake_minimum_required(
        VERSION 4.2.0
        FATAL_ERROR
)

include(CMake/UniversalAppleBuild.cmake)

project(
        Photopsin
        LANGUAGES CXX
        VERSION 1.0.0
)

include(CMake/StandardProjectSettings.cmake)
include(GNUInstallDirs)
include(CMake/StaticAnalyzers.cmake)
include(CMake/PreventInSourceBuilds.cmake)

find_package(SDL3 REQUIRED)
find_package(spdlog REQUIRED)

set(NAME Photopsin)

set(
    Header_Files
    "include/Render.hpp"
    "include/Maths.hpp"
)

set(
    Source_Files
    "source/Render.cpp"
)

add_library(${NAME})

target_sources(
    ${NAME}
    PRIVATE
    ${Source_Files}
    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES ${Header_Files}
)

target_link_libraries(
    ${NAME}
    PUBLIC
    SDL3::SDL3-static
)

enable_strict_warnings(${NAME})
enable_clang_tidy_for_targets(${NAME})

mark_imported_includes_as_system(
    ${NAME}
    SDL3::SDL3-static
)

add_subdirectory(Example)