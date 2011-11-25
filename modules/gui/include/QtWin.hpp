
#ifndef QTWIN_HPP
#define	QTWIN_HPP

#include <Export.hpp>

class WindowNotifier;

class GDGUI_EXPORT QtWin
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

#endif