include_directories(${PROJECT_SOURCE_DIR}/include)

set(APP_SRC main.cpp)
add_executable(main ${APP_SRC})
target_link_libraries(main ${OpenCV_LIBS} sdk)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

install(TARGETS main RUNTIME DESTINATION bin)
