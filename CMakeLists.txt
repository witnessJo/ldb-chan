cmake_minimum_required (VERSION 3.10)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(ldb-chan)

set (LDB_DIR "leveldb")
set (LDB_VER "v1.10")

set (LOG4_DIR "log4cpp")
set (LOG4_VER "v2.9.1")

set (LDBCHAN_DIR "ldb-chan")


find_package(Git)

# Git initializing Submodules
if(${Git_FOUND} AND (EXISTS "${PROJECT_SOURCE_DIR}/.git"))
  option(GIT_SUBMODULE "Check submodules during build" ON)
  
  message(STATUS "\n===== Git Submodule update =====")
  execute_process(
	  COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
	  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	  RESULT_VARIABLE RET)

  if(NOT RET EQUAL "0")
	  message(FATAL_ERROR "git submodule update --init failed with ${RET}, please checkout submodules")
	  return()
  endif()
  
  #leveldb init
  message(STATUS "\n===== LevelDB checkout =====")
  execute_process(
	  COMMAND "${GIT_EXECUTABLE} checkout ${LDB_VER} && make"
	  INPUT_*
	  OUTPUT_*
	  ERROR_*
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${LDB_DIR}
	  RESULT_VARIABLE RET)


  message(STATUS "\n===== Log4cpp checkout =====")
  execute_process(
	  COMMAND "${GIT_EXECUTABLE} checkout ${LOG4} && make"
	  INPUT_*
	  OUTPUT_*
	  ERROR_*
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${LDB4}
	  RESULT_VARIABLE RET)
  
else()
  message(FATAL_ERROR "Couldn't found git or the .git directory...")
  return()
endif()

message(STATUS "\n===== Start making cmake =====")

add_subdirectory(${LDB_DIR})
add_subdirectory(${LOG4})
add_subdirectory(${LDBCHAN_DIR})


enable_testing()

