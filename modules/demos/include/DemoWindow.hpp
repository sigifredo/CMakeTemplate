
#ifndef DEMO_WINDOW_HPP
#define DEMO_WINDOW_HPP

#include<DemoExport.hpp>
#include<QMainWindow>

class QPushButton;

namespace Demo
{

class DEMO_EXPORT Window: public QMainWindow
{
Q_OBJECT
	public:
		Window(QWidget * pParent = 0, Qt::WindowFlags flags = 0);

protected:
	QPushButton * _pAboutPushButton;

	protected slots:
		void about();
};

}

#endif
