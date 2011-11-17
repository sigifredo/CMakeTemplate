project( gdBase )
cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED QtCore QtGui)

include( ${QT_USE_FILE} )

include_directories( ${QT_INCLUDES} ${CMAKE_BINARY_DIR} includes )

#ADD_DEFINITIONS( -Wall )

set( GDBASE_HDRS
includes/Export.hpp
)

set( GDBASE_MOC_HDRS
includes/About.hpp
)

set( GDBASE_SRCS
src/About.cpp
)

set( GDBASE_UIS
uis/About.ui
)

set(GDBASE_RCS
resources/icons.qrc
)

qt4_wrap_ui( GDBASE_HDRS_UIS ${GDBASE_UIS} )
qt4_wrap_cpp( GDBASE_MOC_SRCS ${GDBASE_MOC_HDRS} )
qt4_add_resources( GDBASE_RCS_SRCS ${GDBASE_RCS} )

add_library(GDBase SHARED
${GDBASE_HDRS_UIS}
${GDBASE_HDRS}
${GDBASE_MOC_SRCS}
${GDBASE_SRCS}
${GDBASE_HDRS_UIS}
${GDBASE_RCS_SRCS}
)

add_executable(about test/about.cpp)

target_link_libraries(GDBase ${QT_LIBRARIES})

target_link_libraries( about GDBase )
