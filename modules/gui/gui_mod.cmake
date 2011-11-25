set(GUI_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${GUI_DIR}/include)

set( GUI_HDRS
${GUI_DIR}/include/Export.hpp
${GUI_DIR}/include/Types.hpp
)

set( GUI_MOC_HDRS
${GUI_DIR}/include/About.hpp
)

set( GUI_SRCS
${GUI_DIR}/src/About.cpp
)

set( GUI_RCS
${CMAKE_SOURCE_DIR}/resources/icons.qrc
)

qt4_wrap_cpp( GUI_MOC_SRCS ${GUI_MOC_HDRS} )
qt4_add_resources( GUI_RCS_SRCS ${GUI_RCS} )

set(GUI ${GUI_HDRS} ${GUI_MOC_SRCS} ${GUI_SRCS} ${GUI_RCS_SRCS})

add_library( GDGui SHARED ${GUI} )

target_link_libraries(GDGui ${QT_LIBRARIES})

# EXEC_PROGRAM( regsvr32 
#               ARGS \"/s\" 
#               ARGS \"${file_name}\" 
#               OUTPUT_VARIABLE ov RETURN_VALUE rv )

install( TARGETS GDGui
         RUNTIME DESTINATION bin )
