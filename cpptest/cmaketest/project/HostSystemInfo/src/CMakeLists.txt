cmake_host_system_information(RESULT logic_cpu_number QUERY NUMBER_OF_LOGICAL_CORES)
message(STATUS "number of logical cores = ${logical_cpu_number}")

cmake_host_system_information(RESULT physical_cpu_number QUERY NUMBER_OF_PHYSICAL_CORES)
message(STATUS "number of physical cores = ${physical_cpu_number}")

cmake_host_system_information(RESULT host_name QUERY HOSTNAME FQDN)
message(STATUS "Host name fqdn = ${host_name}")

cmake_host_system_information(RESULT virtual_memory QUERY TOTAL_VIRTUAL_MEMORY AVAILABLE_VIRTUAL_MEMORY)
message(STATUS " TOTAL_VIRTUAL_MEMORY,AVAILABLE_VIRTUAL_MEMORY = ${virtual_memory}")

cmake_host_system_information(RESULT physical_memory QUERY TOTAL_PHYSICAL_MEMORY AVAILABLE_PHYSICAL_MEMORY)
message(STATUS " TOTAL_PHYSICAL_MEMORY,AVAILABLE_PHYSICAL_MEMORY = ${physical_memory}")

cmake_host_system_information(RESULT is_64bit QUERY IS_64BIT)
message(STATUS "IS64BIT = ${is_64bit}")

cmake_host_system_information(RESULT OS QUERY OS_NAME OS_RELEASE OS_VERSION OS_PLATFORM)
message(STATUS "OS_NAME OS_RELEASE OS_VERSION OS_PLATFORM = ${OS}")

cmake_host_system_information(RESULT process_name QUERY PROCESSOR_NAME)
message(STATUS "PROCESS_NAME = ${process_name}")

cmake_host_system_information(RESULT process_description QUERY PROCESSOR_DESCRIPTION)
message(STATUS "PROCESSOR_DESCRIPTION = ${process_description}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(hostSysInfo main.cpp)