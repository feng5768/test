set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(SayHello helloLib.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(OutputPath main.cpp)

target_link_libraries(OutputPath SayHello)
