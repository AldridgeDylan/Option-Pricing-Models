cmake_minimum_required(VERSION 3.15)
project(OptionsPricingModels LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define the library
add_library(OptionsPricingModels STATIC 
    src/Option.cpp
    src/BlackScholesModel.cpp
    src/BinomialModel.cpp
    src/MonteCarloModel.cpp
)

# Include directories
target_include_directories(OptionsPricingModels PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Public headers
set(PUBLIC_HEADERS
    include/OptionsPricingModels/Option.hpp
    include/OptionsPricingModels/BlackScholesModel.hpp
    include/OptionsPricingModels/BinomialModel.hpp
    include/OptionsPricingModels/MonteCarloModel.hpp
    include/OptionsPricingModels/PricingModel.hpp
)

# Set target properties
set_target_properties(OptionsPricingModels PROPERTIES 
    PUBLIC_HEADER "${PUBLIC_HEADERS}"
    VERSION 1.0.0
    SOVERSION 1
)

# Alias target
add_library(OptionsPricingModels::OptionsPricingModels ALIAS OptionsPricingModels)

# Compiler options
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(OptionsPricingModels PRIVATE -O2 -Wall)
elseif(MSVC)
    target_compile_options(OptionsPricingModels PRIVATE /O2 /W4)
endif()

# Installation
install(TARGETS OptionsPricingModels
    EXPORT OptionsPricingModelsTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include/OptionsPricingModels
)

# Export targets
install(EXPORT OptionsPricingModelsTargets
    FILE OptionsPricingModelsTargets.cmake
    NAMESPACE OptionsPricingModels::
    DESTINATION lib/cmake/OptionsPricingModels
)

# Package configuration
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/OptionsPricingModelsConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "package/OptionsPricingModelsConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/OptionsPricingModelsConfig.cmake"
    INSTALL_DESTINATION lib/cmake/OptionsPricingModels
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/OptionsPricingModelsConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/OptionsPricingModelsConfigVersion.cmake"
    DESTINATION lib/cmake/OptionsPricingModels
)

# Testing
enable_testing()
add_subdirectory(tests)
