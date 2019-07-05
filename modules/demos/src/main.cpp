

// Own
#include<Window.hpp>

// Qt
#include<QApplication>
#include<QCommandLineParser>

// std
#include <iostream>

#define APPLICATION_NAME                "Demo"

#define STR_HELPER(x)   #x
#define STR3(x, y, z)   STR_HELPER(x) "." STR_HELPER(y) "." STR_HELPER(z)
#define STR1(x)         STR_HELPER(x)

#define GCC_VERSION     STR3(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#define CPP_VERSION     STR1(__cplusplus)

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    app.setApplicationName(APPLICATION_NAME);
    app.setApplicationDisplayName(APPLICATION_NAME);
    app.setApplicationVersion(CMAKETEMPLATE_VERSION_STR);

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.setApplicationDescription("Plantilla de un proyecto en Qt5.");

    QCommandLineOption versionOption({"v", "version"}, QCoreApplication::translate("main", "Versión de la aplicación."));

    parser.addOption(versionOption);
    parser.process(app);

    if (parser.isSet(versionOption))
    {
        std::cout << "Version\n\tApp:\t" CMAKETEMPLATE_VERSION_STR "\n";
        std::cout << "\tQt:\t" QT_VERSION_STR "\n";
        std::cout << "\tC++:\t" CPP_VERSION "\n";
        std::cout << "\tgcc:\t" GCC_VERSION "\n";
        std::cout << "\nBuild date: " CMAKETEMPLATE_VERSION_DATE "\n";

        return 0;
    }
    else
    {
        Demo::Window wn;
        wn.show();

        return app.exec();
    }
}
