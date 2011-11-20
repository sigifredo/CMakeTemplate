
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
    /**
     * \brief Constructor de la clase.
    *
    * @param sAppName Nombre de la aplicación.
    * @param sAppVersion Versión de la aplicación.
    * @param sDescription Descripción de la aplicación.
    * @param pParent Puntero al objeto padre.
    *
    *
     */
    About(const QString &sAppName, const QString &sAppVersion, const QString &sDescription, QWidget * pParent = 0);

    void addAuthor(const QString &sName, const QString &sTask, const QString &sEmail, const QString &sWebAddress = QString(""));

    QString appName() const;

    void setVersion(const QString sVersion);

protected:

    /**
     * Etiqueta con el icono de la empresa.
     */
    QLabel * _pIconLabel;

    /**
     * Etiqueta con la información de la aplicación, como la versión e información de la plataforma de desarrollo.
     */
    QLabel * _pAppInfoLabel;

    /**
     * Descripción de la aplicación, que estará en la pestaña "About".
     */
    QLabel * _pDescriptionLabel;

    /**
     * Información sobre los autores, que estará en la pestaña "Authors".
     */
    QLabel * _pAuthorsLabel;

    /**
     * Licencia de la aplicación.
     */
#ifndef _WIN32
#  warning "Cambiar QLabel por QLineEdit"
#endif
    QLabel * _pLicenceLabel;

    /**
     * Nombre de la aplicación.
     */
    QString _sAppName;

    /**
     * QTabWidget con toda la información del dialogo.
     */
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
