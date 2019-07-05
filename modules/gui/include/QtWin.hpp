

#ifndef GUI_QTWIN_HPP
#define GUI_QTWIN_HPP

#ifdef _WIN32

// Own
#include<Export.hpp>

class QWidget;
class QColor;

namespace GUI
{

class WindowNotifier;

class GUI_EXPORT QtWin
{
public:
    static bool enableBlurBehindWindow(QWidget *widget, bool enable = true);
    static bool extendFrameIntoClientArea(QWidget *widget,
                                          int left = -1, int top = -1,
                                          int right = -1, int bottom = -1);
    static bool isCompositionEnabled();
    static QColor colorizatinColor();

private:
    static WindowNotifier *windowNotifier();
};

}

#endif

#endif
