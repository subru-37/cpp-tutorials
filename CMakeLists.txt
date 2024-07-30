cmake_minimum_required(VERSION 3.5.0)
project(ImageStitching VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# find_package( OpenCV REQUIRED )
# include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable("Cpptutorials" 1.Cp.cpp)

# target_link_libraries(ImageStitching ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
