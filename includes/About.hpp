
#ifndef GUI_ABOUT_HPP
#define GUI_ABOUT_HPP

#include<Export.hpp>
#include<ui_About.h>

class GDBASE_EXPORT About: public QDialog, Ui::About
{
    Q_OBJECT
public:
    About(const QString &sAppName, const QString &sAppVersion, const QString &sDescription, QWidget * pParent = 0);

    void addAuthor(const QString &sName, const QString &sTask, const QString &sEmail, const QString &sWebAddress = QString(""));

    QString appName() const;

    void setVersion(const QString sVersion);

protected:
    QString _sAppName;
};

inline QString About::appName() const
{
    return _sAppName;
}

#endif
