cmake_minimum_required(
	VERSION 4.2.0
	FATAL_ERROR
)

project(Dependencies)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	get_filename_component(DEPS_BUILD_NAME "${CMAKE_BINARY_DIR}" NAME)
	set(CMAKE_INSTALL_PREFIX
		"${CMAKE_CURRENT_SOURCE_DIR}/install/${DEPS_BUILD_NAME}"
		CACHE PATH "Install path prefix, prepended onto install directories."
		FORCE
	)
	message(STATUS "Dependencies: defaulting CMAKE_INSTALL_PREFIX to ${CMAKE_INSTALL_PREFIX}")
endif()

add_subdirectory(SDL3)
add_subdirectory(spdlog)
