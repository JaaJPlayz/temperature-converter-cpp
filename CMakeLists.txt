cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    temperature-converter
    VERSION 0.1.0
    DESCRIPTION "A simple temperature converter made using c++"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    temperature-converter_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    temperature-converter_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(temperature-converter_lib PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(temperature-converter_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(temperature-converter_exe source/main.cpp)
add_executable(temperature-converter::exe ALIAS temperature-converter_exe)

set_property(TARGET temperature-converter_exe PROPERTY OUTPUT_NAME temperature-converter)

target_compile_features(temperature-converter_exe PRIVATE cxx_std_17)

target_link_libraries(temperature-converter_exe PRIVATE temperature-converter_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT temperature-converter_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of temperature-converter"
  )
endif()

include(cmake/dev-mode.cmake)
