

#ifndef DEMO_EXPORT_HPP
#define DEMO_EXPORT_HPP

#ifdef _WIN32
#  ifdef libreria_EXPORTS
#    define DEMO_EXPORT     __declspec( dllexport )
#  else
#    define DEMO_EXPORT     __declspec( dllimport )
#  endif
#else
#  define DEMO_EXPORT
#endif

#endif
