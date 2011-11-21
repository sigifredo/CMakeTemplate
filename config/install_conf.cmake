
# macro pensado para instalar librerías.
# Los tipos de librerías son:
#     - SHARED
#     - STATIC
macro(GDINSTALL_LIB TYPE)
    foreach(VAL ${ARGN})
        if(${CMAKE_HOST_SYSTEM} MATCHES "Linux")
            install(TARGETS ${VAL} LIBRARY DESTINATION /usr/lib/)
        elseif(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
            message("mejorar condición")
            if(${TYPE} MATCHES "SHARED")
                install(TARGETS ${VAL} LIBRARY DESTINATION bin COMPONENT libraries)
            else()
                install(TARGETS ${VAL} LIBRARY DESTINATION lib COMPONENT libraries)
            endif()
        endif()
    endforeach(VAL)
endmacro(GDINSTALL_LIB)

# macro pensado para instalar cabeceras.
macro(GDINSTALL_H DIR)
    foreach(VAL ${ARGN})
        if(${CMAKE_HOST_SYSTEM} MATCHES "Linux")
            install(FILES ${VAL} DESTINATION /usr/include/GfifDev/${DIR})
        elseif(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
            install(FILES ${VAL} DESTINATION include/${DIR} COMPONENT headers)
        endif()
    endforeach(VAL)
endmacro(GDINSTALL_H)
