set(DEMO_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${DEMO_DIR}/include)

set(DEMO_HDRS
${DEMO_DIR}/include/DemoExport.hpp
)

set(DEMO_MOC_HDRS
${DEMO_DIR}/include/DemoWindow.hpp
)

set(DEMO_SRCS
${DEMO_DIR}/src/DemoWindow.cpp
)

qt4_wrap_cpp(DEMO_MOC_SRCS ${DEMO_MOC_HDRS})

add_library( ldemo SHARED
${DEMO_HDRS}
${DEMO_MOC_SRCS}
${DEMO_SRCS}
)
set(DEMO ${DEMO_DIR}/src/demo.cpp)

if(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
  LIST(APPEND DEMO ${CMAKE_SOURCE_DIR}/resources/icon.rc)
endif()

add_executable(demo ${DEMO})

target_link_libraries(ldemo GDGui ${QT_LIBRARIES})
target_link_libraries(demo ldemo)
