project(zdb_test)
aux_source_directory(. CUR_SRC)

include_directories(${ZDB_INCLUDE})

message(${ZDB_INCLUDE})
link_directories(${ZDB_LIB})



add_executable(zdb_test ${CUR_SRC})

target_link_libraries(zdb_test zdb pthread)
