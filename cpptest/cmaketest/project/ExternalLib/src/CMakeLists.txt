set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# link_libraries(/home/zhenkong/cpptest/cmaketest/output/lib/LibraryProperty/liblinear.a)
link_directories(/home/zhenkong/cpptest/cmaketest/output/lib/LibraryProperty)

add_executable(ExternalLib main.cpp)

include_directories(/home/zhenkong/cpptest/cmaketest/output/include/LibraryProperty)

target_link_libraries(ExternalLib linear.a)
