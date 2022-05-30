set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(custome_install main.cpp)

install(TARGETS custome_install DESTINATION customInstall/bin)