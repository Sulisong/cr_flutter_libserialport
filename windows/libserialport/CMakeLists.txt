cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME "serialport")
project(${PROJECT_NAME} LANGUAGES C)

set(SOURCE_PATH "../../third_party/libserialport")

add_library(${PROJECT_NAME} SHARED
  "${SOURCE_PATH}/serialport.c"
  "${SOURCE_PATH}/timing.c"
  "${SOURCE_PATH}/windows.c"
)

#target_compile_options(${PROJECT_NAME} PRIVATE
#  -std=c99 -Wall -Wextra -pedantic -Wmissing-prototypes -Wshadow)
target_compile_definitions(${PROJECT_NAME} PRIVATE LIBSERIALPORT_MSBUILD)
target_include_directories(${PROJECT_NAME} PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_PATH}")
target_link_libraries(${PROJECT_NAME} PRIVATE cfgmgr32 SetupAPI)

# 动态库的输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
# 安装动态库的目标目录
set(INSTALL_BUNDLE_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib")
# 安装动态库，到执行目录
install(FILES "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/lib${PROJECT_NAME}.so" DESTINATION "${INSTALL_BUNDLE_LIB_DIR}" COMPONENT Runtime)
