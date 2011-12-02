
#ifndef DEMOEXPORT_HPP
#define DEMOEXPORT_HPP

#ifdef _WIN32
#  ifdef base_EXPORTS
#    define DEMO_EXPORT	__declspec( dllexport )
#  else
#    define DEMO_EXPORT	__declspec( dllimport )
#  endif
#else
#  define DEMO_EXPORT
#endif

#endif
