
#include<QApplication>
#include<DemoWindow.hpp>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	Demo::Window wn;
	wn.show();

	return app.exec();
}
