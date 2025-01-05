cmake_minimum_required(VERSION 3.10)
project(OptionsPricingModels LANGUAGES CXX)

set(PROJECT_VERSION "1.0.0")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE LIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(OptionsPricingModels STATIC ${LIB_SOURCES})
set_target_properties(OptionsPricingModels PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

install(TARGETS OptionsPricingModels
    EXPORT OptionsPricingModelsTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/OptionsPricingModels/
    DESTINATION include/OptionsPricingModels
)

include(CMakePackageConfigHelpers)
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/package/OptionsPricingModelsConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/OptionsPricingModelsConfig.cmake"
    @ONLY
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/OptionsPricingModelsConfig.cmake"
    DESTINATION lib/cmake/OptionsPricingModels
)

install(EXPORT OptionsPricingModelsTargets
    FILE OptionsPricingModelsTargets.cmake
    DESTINATION lib/cmake/OptionsPricingModels
)

option(BUILD_TESTS "Build test executable" ON)
if(BUILD_TESTS)
    add_executable(test_pricer tests/main.cpp)
    target_link_libraries(test_pricer PRIVATE OptionsPricingModels)
endif()
