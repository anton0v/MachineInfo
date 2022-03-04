cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(MachineInfo)
add_executable(MachineInfo main.cpp)
add_library(MILib STATIC SystemInfoGenerator.h SystemInfoGenerator.cpp
						 SystemInfo.h SystemInfo.cpp
						 MachineInfo.h MachineInfo.cpp
						 ProcessorInfoGenerator.h ProcessorInfoGenerator.cpp
						 ProcessorInfo.h ProcessorInfo.cpp
						 OperatingSystemInfoGenerator.h OperatingSystemInfoGenerator.cpp
						 OperatingSystemInfo.h OperatingSystemInfo.cpp
						 DisplayDeviceInfo.h DisplayDeviceInfo.cpp
						 GPUInfoGenerator.h GPUInfoGenerator.cpp
						 GPUInfo.h GPUInfo.cpp
						 MonitorInfoGenerator.h MonitorInfoGenerator.cpp
						 MonitorInfo.h MonitorInfo.cpp
						 DriveInfoGenerator.h DriveInfoGenerator.cpp
						 DriveInfo.h DriveInfo.cpp
						 MemoryInfoGenerator.h MemoryInfoGenerator.cpp
						 MemoryInfo.h MemoryInfo.cpp
						 MD5Hash.h MD5Hash.cpp
						 )
target_link_libraries(MachineInfo MILib wbemuuid.lib)