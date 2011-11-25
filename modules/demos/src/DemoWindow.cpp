
// Own
#include<DemoWindow.hpp>
#include<About.hpp>
#include<QtWin.hpp>

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

#ifdef _WIN32
	ab.setAttribute(Qt::WA_TranslucentBackground);
    ab.setAttribute(Qt::WA_NoSystemBackground, false);
	QPalette pal = ab.palette();
    QColor bg = pal.window().color();
    bg.setAlpha(0x0);
    pal.setColor(QPalette::Window, bg);
    ab.setPalette(pal);
    ab.ensurePolished(); // workaround Oxygen filling the background
    ab.setAttribute(Qt::WA_StyledBackground, false);
#endif

	if(QtWin::isCompositionEnabled()) {
        QtWin::extendFrameIntoClientArea(&ab);
        ab.setContentsMargins(0, 0, 0, 0);
    }

		ab.exec();
	}