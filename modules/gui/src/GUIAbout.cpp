
// Own
#include<GUIAbout.hpp>
#include<GUIQtWin.hpp>

// Qt
#include<QGridLayout>
#include<QLabel>
#include<QTextEdit>
#include<QTabWidget>
#include<QDialogButtonBox>

using namespace GUI;

About::About(const QString &sAppName, const QString &sAppVersion, const QString &sDescription, QWidget * pParent):
    QDialog(pParent)
{
    init();

    _sAppName = sAppName;
    _pAppInfoLabel->setText("<font size=\"5\">" + sAppName + "</font><br><i>" + QString::fromUtf8("Versión") + sAppVersion + "</i><br>Usando la plataforma de desarrollo de GfifDev 0.3<br>Y la biblioteca de desarrollo Qt 4.7.4.0");
    _pDescriptionLabel->setText(sDescription);
    setWindowTitle("Acerca de " + sAppName);
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

void About::setImage(const QString &sImagePath)
{
    _pIconLabel->setPixmap(QPixmap(sImagePath));
}

void About::setLicence(const Licence licence)
{
    _pLicenceTextEdit->setText(strLicence(lgpl3, "Demo"));
}

void About::setVersion(const QString sVersion)
{
}

QString About::strLicence(const Licence licence, const QString &sLicenced)
{
#ifndef _WIN32
#warning "Faltan licencias"
#endif
    switch(licence)
    {
        case lgpl3: return sLicenced + QString::fromUtf8(" es software libre: usted lo puede redistribuir y modificar \nbajo los términos de la licencia pública general reducida gnu\n(lgpl) como es publicado por la fundación de software libre\n(fsf), la versión 3 o cualquier versión posterior.\n\n") + sLicenced + QString::fromUtf8(" es distribuido en la espera de que será util,\npero sin alguna garantía; ni siquiera la garantía implícita de\ncomercialización o idoneidad para un propósito\nparticular. vease la licencia pública general reduciada gnu\npara más detalles.\n\nusted debe haber recibido una copia de la licencia pública\ngeneral reducida gnu junto con ") + sLicenced + ".\nSino, vea <http://www.gnu.org/licenses/>."; break;
		default: return QString("Licencia no encontrada"); break;
    }
}

void About::init()
{
    QGridLayout * pLayout = new QGridLayout(this);

    // Label donde estará el icono.
    _pIconLabel = new QLabel(this);
    _pIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/GfifDev/logo90.png")));
    pLayout->addWidget(_pIconLabel, 0, 0, 1, 1);

    // Donde estará la información de la aplicación.
    _pAppInfoLabel = new QLabel(this);
    pLayout->addWidget(_pAppInfoLabel, 0, 1, 1, 1);

    // QTabWidget que tendrá la aplicación.
    _pTabWidget = new QTabWidget(this);

    // Pestaña de "Acerca de...". Aquí va la descripción.
    {
        QWidget * pAboutTab = new QWidget(_pTabWidget);
        QVBoxLayout * pAboutLayout = new QVBoxLayout(pAboutTab);
        _pDescriptionLabel = new QLabel(pAboutTab);
        pAboutLayout->addWidget(_pDescriptionLabel);
QSpacerItem * pSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
pAboutLayout->addItem(pSpacer);
        _pTabWidget->addTab(pAboutTab, "Acerca de...");
    }

    QDialogButtonBox * pButtonBox = new QDialogButtonBox(this);
    pButtonBox->setOrientation(Qt::Horizontal);
    pButtonBox->setStandardButtons(QDialogButtonBox::Close);

    pLayout->addWidget(pButtonBox, 2, 1, 1, 1);

    // Pestaña de autores
    {
        QWidget * pAuthorTab = new QWidget(_pTabWidget);
        QVBoxLayout * pAuthorsLayout = new QVBoxLayout(pAuthorTab);
        _pAuthorsLabel = new QLabel(pAuthorTab);
        addAuthor("Equipo de desarrollo de GfifDev", "Desarrollador", "info@gfifdev.com", "www.gfifdev.com");
        pAuthorsLayout->addWidget(_pAuthorsLabel);
        QSpacerItem * pSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
        pAuthorsLayout->addItem(pSpacer);
        _pTabWidget->addTab(pAuthorTab, "Autores");
    }

    // Pestaña de licencia
    {
        QWidget * pLicenceTab = new QWidget(_pTabWidget);
        QVBoxLayout * pLicenceLayout = new QVBoxLayout(pLicenceTab);
        _pLicenceTextEdit = new QTextEdit(pLicenceTab);
        _pLicenceTextEdit->setReadOnly(true);
        pLicenceLayout->addWidget(_pLicenceTextEdit);
        _pTabWidget->addTab(pLicenceTab, "Licencia");
    }

    pLayout->addWidget(_pTabWidget, 1, 0, 1, 2);

    connect(pButtonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Transparencia (Solo Windows 7)
#ifdef _WIN32
	// verificamos que esté activada la transparencia en el sistema
    if(QtWin::isCompositionEnabled())
	{
        this->setAttribute(Qt::WA_TranslucentBackground);
        this->setAttribute(Qt::WA_NoSystemBackground, false);
        QPalette pal = this->palette();
        QColor bg = pal.window().color();
        bg.setAlpha(0x0);
        pal.setColor(QPalette::Window, bg);
        this->setPalette(pal);
        this->ensurePolished(); // workaround Oxygen filling the background
        this->setAttribute(Qt::WA_StyledBackground, false);

	    QtWin::extendFrameIntoClientArea(this);
	    this->setContentsMargins(0, 0, 0, 0);
	}
#endif
}
