# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-src"
  "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-build"
  "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix"
  "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/tmp"
  "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp"
  "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src"
  "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
