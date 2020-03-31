project(zdb_test)
aux_source_directory(. CUR_SRC)

add_executable(zdb_test ${CUR_SRC})

target_link_libraries(zdb_test zdb)
