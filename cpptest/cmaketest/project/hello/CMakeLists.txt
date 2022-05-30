project(HelloCmake)
set(HELLO test.cpp)
message("This is no parameters")
add_executable(hello_cmake ${HELLO})