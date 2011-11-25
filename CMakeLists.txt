project( gdbase )
cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED QtCore QtGui)

# IF(NOT CMAKE_BUILD_TYPE )
#    SET( CMAKE_BUILD_TYPE "Release" )
# ENDIF()

include( ${QT_USE_FILE} )

include_directories( ${QT_INCLUDES} ${CMAKE_BINARY_DIR} include )

#MESSAGE("$ENV{PATH}")
#message("${CMAKE_INSTALL_PREFIX}")

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

include(CPack)