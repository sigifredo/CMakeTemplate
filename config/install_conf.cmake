

SET(QT_LIBS ${QT_LIBRARIES})
LIST(REMOVE_ITEM QT_LIBS  "optimized" )
LIST(REMOVE_ITEM QT_LIBS  "debug" )
FOREACH(next_ITEM ${QT_LIBS})
    STRING(REPLACE ".lib" ".dll"  QTLIB_  ${next_ITEM} )
    STRING(REPLACE "/lib/" "/bin/" QTLIB   ${QTLIB_} )
    LIST(APPEND QT_LIBS_TO_INSTALL ${QTLIB})
ENDFOREACH()

INSTALL(FILES ${QT_LIBS_TO_INSTALL} DESTINATION bin)

set(CPACK_PACKAGE_NAME "gdbase")
set(CPACK_PACKAGE_VENDOR "GfifDev S.A.S")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Falta")
set(CPACK_PACKAGE_VERSION "0.1.2")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "2")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "GfifDev")

# set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE-CLUF)

# set(CPACK_NSIS_MENU_LINKS "./bin/slide.exe" "Diapositiva")

# macro pensado para instalar cabeceras.
# macro( GDINSTALL_H DIR )
#     foreach(VAL ${ARGN})
#         if(${CMAKE_HOST_SYSTEM} MATCHES "Linux")
#             install(FILES ${VAL} DESTINATION /usr/include/GfifDev/${DIR})
#         elseif(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
#             install(FILES ${VAL} DESTINATION include/${DIR} COMPONENT headers)
#         endif()
#     endforeach(VAL)
# endmacro(GDINSTALL_H)

include(CPack)