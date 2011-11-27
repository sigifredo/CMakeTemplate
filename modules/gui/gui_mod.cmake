set(GUI_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${GUI_DIR}/include)

set( GUI_HDRS
${GUI_DIR}/include/Export.hpp
${GUI_DIR}/include/Types.hpp
)

set( GUI_MOC_HDRS
${GUI_DIR}/include/About.hpp
)

if(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
    list(APPEND GUI_MOC_HDRS ${GUI_DIR}/include/QtWin.hpp ${GUI_DIR}/include/WindowNotifier.hpp)
endif()

set( GUI_SRCS
${GUI_DIR}/src/About.cpp
${GUI_DIR}/src/QtWin.cpp
)

set( GUI_RCS
${CMAKE_SOURCE_DIR}/resources/icons.qrc
)

qt4_wrap_cpp( GUI_MOC_SRCS ${GUI_MOC_HDRS} )
qt4_add_resources( GUI_RCS_SRCS ${GUI_RCS} )

set(GUI ${GUI_HDRS} ${GUI_MOC_SRCS} ${GUI_SRCS} ${GUI_RCS_SRCS})

add_library( GDGui SHARED ${GUI} )

target_link_libraries(GDGui ${QT_LIBRARIES})

# set(filename ${CMAKE_INSTALL_PREFIX}/GDGui)
# message(" -> ${filename}")

# INSTALL( CODE
#      "EXEC_PROGRAM( regsvr32 ARGS \"/s\" ARGS \"${filename}\"
#      OUTPUT_VARIABLE POST_INST_OUT RETURN_VALUE POST_INST_RES )"
#  )

install( TARGETS GDGui
         ${SHARED_LIB} DESTINATION ${INSTALL_DIR}/bin )

GDINSTALL_H( "Gui" ${GUI_HDRS} ${GUI_MOC_HDRS} )
