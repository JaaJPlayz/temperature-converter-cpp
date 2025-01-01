# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(temperature-converterTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(temperature-converter_test source/temperature-converter_test.cpp)
target_link_libraries(
    temperature-converter_test PRIVATE
    temperature-converter_lib
    Catch2::Catch2WithMain
)
target_compile_features(temperature-converter_test PRIVATE cxx_std_17)

catch_discover_tests(temperature-converter_test)

# ---- End-of-file commands ----

add_folders(Test)
