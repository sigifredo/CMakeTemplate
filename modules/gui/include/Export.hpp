

#ifndef GUI_EXPORT_HPP
#define GUI_EXPORT_HPP

#ifdef _WIN32
#  ifdef gui_EXPORTS
#    define GUI_EXPORT      __declspec( dllexport )
#  else
#    define GUI_EXPORT      __declspec( dllimport )
#  endif
#else
#  define GUI_EXPORT
#endif

#endif
