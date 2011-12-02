
#ifndef _WIN32_WINNT            // Especifica que la plataforma mínima requerida es Windows Vista.
#define _WIN32_WINNT 0x0600     // Cambiar al valor apropiado correspondiente a otras versiones de Windows.
#endif

#include <stdio.h>
#include <tchar.h>

#include<QApplication>
#include<DemoWindow.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
	QApplication app(argc, argv);

    Demo::Window wn;
    wn.show();

    return app.exec();
}