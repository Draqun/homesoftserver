cmake_minimum_required(VERSION 3.13)

set(CMAKE_VERBOSE_MAKEFILE on)

project(HomeSoftServer C)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SOURCE_FILES_LIST
    src/camera.c
    src/command_io.c
    src/devices.c
    src/hsserver.c
    src/inspection.c
    src/logs.c
)

set(HEADER_FILES_LIST
    include/camera.h
    include/command_io.h
    include/commands.h
    include/delay.h
    include/device_core.h
    include/devices.h
    include/hsserver.h
    include/inspection.h
    include/logs.h
)

add_executable(${PROJECT_NAME}
    ${SOURCE_FILES_LIST}
    ${HEADER_FILES_LIST}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Threads::Threads
)

target_include_directories(${PROJECT_NAME}
    PRIVATE include
)
