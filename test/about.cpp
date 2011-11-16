
#include<QApplication>
#include<About.hpp>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	About ab("Test", "0.1", "Descripción");
	ab.exec();

	return app.exec();
}
