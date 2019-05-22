include_directories(${PROJECT_SOURCE_DIR}/include)

#set(SRC_FILES sdk.cpp)
aux_source_directory(./ SRC_FILES)
#file(GLOB_RECURSE SRC_FILES "*.cpp")
add_library(sdk SHARED ${SRC_FILES})
#set_target_properties(sdk PROPERTIES OUTPUT_NAME "sdk")

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

install(TARGETS sdk LIBRARY DESTINATION lib)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../include/sdk.h DESTINATION include)
