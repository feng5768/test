cmake_minimum_required(VERSION 3.8)
project(CmakeProjects)

add_subdirectory(src bin)

install(FILES copyright readme DESTINATION customInstall)

install(PROGRAMS run_custom_install.sh DESTINATION customInstall/bin)

install(DIRECTORY doc/ DESTINATION customInstall/share/doc)