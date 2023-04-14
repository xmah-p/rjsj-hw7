cmake_minimum_required(VERSION 3.2.0)

project(hw7 VERSION 0.1.0)

aux_source_directory(src SOURCES)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE includes)
target_link_libraries(${PROJECT_NAME} PRIVATE rjsjai)
target_link_directories(${PROJECT_NAME} PRIVATE lib)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE -lws2_32)
endif()

if (MSVC)
    target_compile_options(${PROJECT_NAME PRIVATE /MT})
endif()

# 如果你使用 MSVC 编译器，请添加 /MT 参数以正确链接到我们提供的库。
# 如果你使用 MinGW，请添加库 ws2_32 的链接（链接选项写作 -lws2_32）。