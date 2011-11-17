
#include<QApplication>
#include<About.hpp>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	About ab("Test", "0.1", QString::fromUtf8("Descripción"));
	ab.exec();

	return app.exec();
}
