set(DEMO_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${DEMO_DIR}/include)

set(DEMO_MOC_HDRS
${DEMO_DIR}/include/Window.hpp
)

qt4_wrap_cpp(DEMO_MOC_SRCS ${DEMO_MOC_HDRS})

add_library( ldemo ${DEMO_MOC_SRCS})

add_executable(demo ${DEMO_DIR}/src/demo.cpp)
target_link_libraries(demo ldemo)
