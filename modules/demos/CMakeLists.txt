include_directories(${MODULES_GLOBAL_INCLUDE_DIR} include)

set(DEMO_HDRS
include/Export.hpp
)

set(DEMO_MOC_HDRS
include/Window.hpp
)

set(DEMO_SRCS
src/Window.cpp
)

qt5_wrap_cpp(DEMO_MOC_SRCS ${DEMO_MOC_HDRS})

add_library(libreria SHARED ${DEMO_HDRS} ${DEMO_MOC_SRCS} ${DEMO_SRCS})

add_executable(demo src/main.cpp)

qt5_use_modules(libreria Core Widgets)

target_link_libraries(libreria gui ${QT_LIBRARIES})
target_link_libraries(demo libreria)

install(TARGETS demo libreria RUNTIME DESTINATION bin LIBRARY DESTINATION bin)
