
#ifndef GDBASE_ABOUT_HPP
#define GDBASE_ABOUT_HPP

#include<Export.hpp>
#include<QDialog>

class QLabel;
class QTabWidget;

class GDBASE_EXPORT About: public QDialog
{
    Q_OBJECT
public:
    About(const QString &sAppName, const QString &sAppVersion, const QString &sDescription, QWidget * pParent = 0);

    void addAuthor(const QString &sName, const QString &sTask, const QString &sEmail, const QString &sWebAddress = QString(""));

    QString appName() const;

    void setVersion(const QString sVersion);

protected:
    QLabel * _pIconLabel;
    QLabel * _pAppInfoLabel;
    QLabel * _pDescriptionLabel;
    QString _sAppName;
    QTabWidget * _pTabWidget;

private:
    /**
     * \brief Instanciamos el ambiente gráfico.
     *
     */
    void init();
};

inline QString About::appName() const
{
    return _sAppName;
}

#endif
