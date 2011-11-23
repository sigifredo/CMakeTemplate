project( gdbase )
cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED QtCore QtGui)

include( ${QT_USE_FILE} )

include_directories( ${QT_INCLUDES} ${CMAKE_BINARY_DIR} include )

# Diviciones que puede contener la librería
set(DIVS "conf" "mod")

foreach(it ${DIVS})
  message("-> Buscando archivos ${it}")
  file(GLOB_RECURSE MODULOS "*_${it}.cmake")
  foreach(jt ${MODULOS})
    message(STATUS "Módulo: ${jt} encontrado")
    include(${jt})
  endforeach(jt)
endforeach(it)

#ADD_DEFINITIONS( -Wall )

set( GDBASE_HDRS
include/Export.hpp
include/Types.hpp
)

set( GDBASE_MOC_HDRS
include/About.hpp
)

set( GDBASE_SRCS
src/About.cpp
)

set(GDBASE_RCS
resources/icons.qrc
)

qt4_wrap_cpp( GDBASE_MOC_SRCS ${GDBASE_MOC_HDRS} )
qt4_add_resources( GDBASE_RCS_SRCS ${GDBASE_RCS} )

add_library(GDBase SHARED
${GDBASE_HDRS}
${GDBASE_MOC_SRCS}
${GDBASE_SRCS}
${GDBASE_RCS_SRCS}
)

target_link_libraries(GDBase ${QT_LIBRARIES})

#GDINSTALL_H("gui" ${GDBASE_HDRS} ${GDBASE_MOC_HDRS})
#GDINSTALL_LIB("SHARED" GDBase)
