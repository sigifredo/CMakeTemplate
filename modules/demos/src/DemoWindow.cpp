
// Own
#include<DemoWindow.hpp>
#include<About.hpp>

// Qt
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>

using namespace Demo;

Window::Window(QWidget * pParent, Qt::WindowFlags flags):
	QMainWindow(pParent, flags)
{
	QWidget * pContent = new QWidget(this);
	QGridLayout * pLayout = new QGridLayout(pContent);

	QWidget * pButtons = new QWidget(pContent);
	{
		QVBoxLayout * pVerticalLayout = new QVBoxLayout(pButtons);

		_pAboutPushButton = new QPushButton("About", pButtons);
		connect(_pAboutPushButton, SIGNAL(clicked()), this, SLOT(about()));

		pVerticalLayout->addWidget(_pAboutPushButton);
	}
	pLayout->addWidget(pButtons, 0, 0, 1, 1);

	QWidget * pDescription = new QWidget(pContent);

	pLayout->addWidget(pDescription, 0, 1, 1, 1);

	this->setCentralWidget(pContent);
}

	void Window::about()
	{
		About ab("Demo", "0.1", "Description", this);
		ab.exec();
	}