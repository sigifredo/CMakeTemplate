
#ifndef EXPORT_HPP
#define ESPORT_HPP

#ifdef _WIN32
#  ifdef gdBase_EXPORTS
#    define GDBASE_EXPORT	__declspec( dllexport )
#  else
#    define GDBASE_EXPORT	__declspec( dllimport )
#  endif
#else
#  define GDBASE_EXPORT
#endif

#endif

