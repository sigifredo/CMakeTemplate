

#ifndef GUI_WINDOWNOTIFIER_HPP
#define GUI_WINDOWNOTIFIER_HPP

#ifdef _WIN32

// Own
#include<Export.hpp>

// Qt
#include<QWidget>

namespace GUI
{

/**
 * Internal helper class that notifies windows if the
 * DWM compositing state changes and updates the widget
 * flags correspondingly.
 */
class GUI_EXPORT WindowNotifier : public QWidget
{
    //Q_OBJECT
public:
	WindowNotifier(QWidget * pParent = 0): QWidget(pParent) {
        winId();
    }
    void addWidget(QWidget *widget) {
        widgets.append(widget);
    }
    void removeWidget(QWidget *widget) {
        widgets.removeAll(widget);
    }
    bool winEvent(MSG *message, long *result);

private:
    QWidgetList widgets;
};

}

#endif

#endif
