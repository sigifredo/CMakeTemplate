#ifndef GDBASE_ABOUT_HPP
#define GDBASE_ABOUT_HPP

// Own
#include<GUIExport.hpp>

// Qt
#include<QDialog>

class QLabel;
class QTextEdit;
class QTabWidget;

namespace GUI
{

/**
 * @class About
 * \brief Cuadro de dialogo "Acerca de..."
 *
 * Clase que inplementa un cuadro de dialogo con toda la información que se quiere mostrar al usuario acerca de nuestra aplicación.
 *
 */
class GDGUI_EXPORT About: public QDialog
{
    Q_OBJECT
public:
    /**
     * @enum Licence
     * \brief Tipo de licencia
     *
     */
    enum Licence
    {
        cluf, /** Contrato de Licencia de Usuario Final */
        gpl3, /** Licencia Pública General de GNU */
        lgpl3 /** Licencia Pública General Reducida de GNU */
    };

    /**
     * \brief Constructor de la clase.
     *
     * @param sAppName Nombre de la aplicación.
     * @param sAppVersion Versión de la aplicación.
     * @param sDescription Descripción de la aplicación.
     * @param pParent Puntero al objeto padre.
     *
     */
    About(const QString &sAppName, const QString &sAppVersion, const QString &sDescription, QWidget * pParent = 0);

    /**
     * \brief Agregamos un nuevo autor.
     *
     * @param sName Nombre del autor.
     * @param sTask Tarea/Cargo del autor.
     * @param sEmail Correo electrónico del autor.
     * @param sWebAddress Dirección web del autor.
     *
     */
    void addAuthor(const QString &sName, const QString &sTask, const QString &sEmail, const QString &sWebAddress = QString(""));

    /**
     * \brief Obtenemos el nombre de la aplicación.
     *
     * @return Nombre de la aplicación.
     *
     */
    QString appName() const;

    /**
     * \brief Indicamos la versión de la aplicación.
     *
     * @param licence Enumeración que indica la licencia de la aplicación
     *
     */
    void setLicence(const Licence licence);

    /**
     * \brief Establecemos la versión de la aplicación.
     *
     * @param sVersion Versión de la aplicación.
     *
     */
    void setVersion(const QString sVersion);

    /**
     * \brief Retorna una cadena con la licencia pasada como argumento.
     *
     * @param licence Enumeración que representa la licencia.
     * @param sLicenced Nombre de la aplicación u organización licenciada.
     *
     * @return Cadena con la licencia especificada.
     *
     */
    static QString strLicence(const Licence licence, const QString &sLicenced);

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
    QTextEdit * _pLicenceTextEdit;

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

}

#endif
