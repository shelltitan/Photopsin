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

#add_library(Photopsin)

add_subdirectory(Example)