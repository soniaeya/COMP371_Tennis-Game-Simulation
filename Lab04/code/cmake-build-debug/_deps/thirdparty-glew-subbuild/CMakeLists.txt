# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.25.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(thirdparty-glew-populate NONE)



include(ExternalProject)
ExternalProject_Add(thirdparty-glew-populate
                     "UPDATE_DISCONNECTED" "True" "DOWNLOAD_EXTRACT_TIMESTAMP" "TRUE" "URL" "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/thirdparty/glew-2.1.0.zip"
                    SOURCE_DIR          "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-src"
                    BINARY_DIR          "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


