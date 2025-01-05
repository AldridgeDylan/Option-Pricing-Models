from conan import ConanFile
from conan.tools.cmake import CMake

class OptionsPricingModelsConan(ConanFile):
    name = "OptionsPricingModels"
    version = "1.0.0"
    license = "MIT" 
    url = "https://github.com/AldridgeDylan/OptionsPricingModels"
    description = "A library for pricing derivative options with various models"
    topics = ("finance", "options", "pricing")
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include/OptionsPricingModels", src="include/OptionsPricingModels")
        self.copy("*.hpp", dst="include/OptionsPricingModels", src="include/OptionsPricingModels")
        self.copy("*.a", dst="lib", keep_path=False)
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["OptionsPricingModels"]
