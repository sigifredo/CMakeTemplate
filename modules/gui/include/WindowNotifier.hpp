
#ifndef WINDOWNOTIFIER_HPP
#define WINDOWNOTIFIER_HPP

#ifdef _WIN32

#include<QWidget>

/**
 * Internal helper class that notifies windows if the
 * DWM compositing state changes and updates the widget
 * flags correspondingly.
 */
class WindowNotifier : public QWidget
{
    Q_OBJECT
public:
    WindowNotifier() {
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

#endif

#endif
