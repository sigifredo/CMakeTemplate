include_directories(${MODULES_GLOBAL_INCLUDE_DIR} include)

set(GUI_HDRS
include/Export.hpp
include/WindowNotifier.hpp
include/QtWin.hpp
)

set(GUI_MOC_HDRS
include/About.hpp
)

set(GUI_SRCS
src/About.cpp
src/QtWin.cpp
)

qt5_wrap_cpp(GUI_MOC_SRCS ${GUI_MOC_HDRS})
qt5_add_resources(GUI_RCS_SRCS ${GUI_RCS})

add_library(gui SHARED ${GUI_HDRS} ${GUI_MOC_SRCS} ${GUI_SRCS} ${GUI_RCS_SRCS})

qt5_use_modules(gui Core Widgets)

target_link_libraries(gui ${QT_LIBRARIES})

install( TARGETS gui ${SHARED_LIB} DESTINATION ${INSTALL_DIR}/bin)
