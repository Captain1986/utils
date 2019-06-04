include_directories(${PROJECT_SOURCE_DIR}/include)

#设置nvcc编译相关选项
#set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++11")
#set(GENCODE -gencode arch=compute_61,code=sm_61)
#list(APPEND CUDA_NVCC_FLAGS ${GENCODE})

#file(GLOB_RECURSE CU_SRCS src/*.cu)
#message(STATUS ${CU_SRCS})
#CUDA_COMPILE(CU_OBJS ${CU_SRCS})

#set(SRC_FILES sdk.cpp)
aux_source_directory(./ SRC_FILES)
#file(GLOB_RECURSE SRC_FILES "*.cpp")
add_library(sdk SHARED ${SRC_FILES} ${CU_OBJS})
#set_target_properties(sdk PROPERTIES OUTPUT_NAME "sdk")

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

install(TARGETS sdk LIBRARY DESTINATION lib)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../include/sdk.h DESTINATION include)
