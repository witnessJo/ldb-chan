cmake_minimum_required (VERSION 3.10)

include_directories(
  ${PROJECT_SOURCE_DIR}/ldb-chan
  ${PROJECT_SOURCE_DIR}/leveldb/include)

add_executable(ldb-chan LDBChan.cpp)
target_link_libraries(ldb-chan boost_program_options)




