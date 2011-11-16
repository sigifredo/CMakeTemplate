
#include<About.hpp>

About::About(const QString &sAppName, const QString &sAppVersion, const QString &sDescription, QWidget * pParent):
    QDialog(pParent)
{
    setupUi(this);
    _sAppName = sAppName;
    _pAppInfoLabel->setText("<font size=\"5\">" + sAppName + "</font><br><i>Version " + sAppVersion + "</i><br>Using XOrbit Development Platform 0.1");
    _pDescriptionLabel->setText(sDescription);
    setWindowTitle("About " + sAppName);
}

void About::addAuthor(const QString &sName, const QString &sTask, const QString &sEmail, const QString &sWebAddress)
{
    QString sAuthor = "<br><b>" + sName + "</b><br><i>" + sTask + "</i><br><font color=\"#0000ff\"><u>" + sEmail;
    if(sWebAddress.trimmed() != "")
        sAuthor += "<br>" + sWebAddress + "</u></font><br>";
    else
        sAuthor += "</u></font><br>";
    _pAuthorsLabel->setText(_pAuthorsLabel->text() + sAuthor);
}

void About::setVersion(const QString sVersion)
{
}
