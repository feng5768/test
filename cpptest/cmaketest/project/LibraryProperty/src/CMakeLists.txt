set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
message(STATUS "PROJECT_BINARY_DIR is: ${PROJECT_BINARY_DIR}")

add_library(linear SHARED helloLib.cpp)

add_library(linear_static STATIC helloLib.cpp)

set_target_properties(linear_static PROPERTIES OUTPUT_NAME "linear")

get_target_property(OUTPUT_VALUE linear_static OUTPUT_NAME)
message(STATUS "OUTPUT_NAME = ${OUTPUT_VALUE}")

get_target_property(UNDEFINE_VALUE linear_static UNDEFINE_NAME)
message(STATUS "UNDEFINE_NAME = ${UNDEFINE_NAME}")

set_target_properties(linear PROPERTIES VERSION 1.0 SOVERSION 1)

install(TARGETS linear linear_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib/${PROJECT_NAME})

install(FILES helloLib.h DESTINATION include/${PROJECT_NAME})

