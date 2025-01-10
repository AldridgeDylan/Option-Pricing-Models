from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout

class OptionsPricingModelsConan(ConanFile):
    name = "OptionsPricingModels"
    version = "1.0"
    license = "MIT"
    author = "Dylan Aldridge"
    url = "https://github.com/AldridgeDylan/Options-Pricing-Models"
    description = "Option Pricing Models using C++ and CMake"
    topics = ("finance", "option-pricing", "black-scholes")
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("gtest/1.13.0")

    def build_requirements(self):
        self.tool_requires("cmake/3.25.0")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate_single_config = True
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["OptionsPricingModels"]
