cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES test.cpp includes/base.h includes/recorder.h includes/solver.h includes/model.h test.cpp)
#add_executable(testapp ${SOURCE_FILES})
set(SOURCE_FILES tetzlaff.cpp includes/base.h includes/recorder.h includes/solver.h includes/model.h)
add_executable(tetzlaff ${SOURCE_FILES})