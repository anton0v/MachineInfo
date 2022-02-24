cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(MachineInfo)
add_executable(MachineInfo main.cpp)
add_library(MILib STATIC SystemInfoGenerator.h SystemInfoGenerator.cpp
						 SystemInfo.h SystemInfo.cpp
						 MachineInfo.h MachineInfo.cpp
						 ProcessorInfoGenerator.h ProcessorInfoGenerator.cpp
						 ProcessorInfo.h ProcessorInfo.cpp
						 )
target_link_libraries(MachineInfo MILib)