set(NAME Example)

set(
    Header_Files
    "include/Application.hpp"
    "include/Window.hpp"
)

set(
    Source_Files
    "source/main.cpp"
    "source/Application.cpp"
    "source/Window.cpp"
)

add_executable(${NAME})

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
    PRIVATE
    Photopsin
    spdlog::spdlog
)

enable_strict_warnings(${NAME})
enable_clang_tidy_for_targets(${NAME})

mark_imported_includes_as_system(
    ${NAME}
    spdlog::spdlog
)

target_compile_features(${NAME} PUBLIC cxx_std_23)
set_target_properties(${NAME} PROPERTIES CXX_EXTENSIONS OFF)