

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
