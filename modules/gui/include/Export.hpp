
#ifndef EXPORT_HPP
#define EXPORT_HPP

#ifdef _WIN32
#  ifdef GDGui_EXPORTS
#    define GDGUI_EXPORT	__declspec( dllexport )
#  else
#    define GDGUI_EXPORT	__declspec( dllimport )
#  endif
#else
#  define GDGUI_EXPORT
#endif

#endif
