
// Own
#include<About.hpp>
#include<QtWin.hpp>

// Qt
#include<QGridLayout>
#include<QLabel>
#include<QLineEdit>
#include<QTabWidget>
#include<QDialogButtonBox>

About::About(const QString &sAppName, const QString &sAppVersion, const QString &sDescription, QWidget * pParent):
    QDialog(pParent)
{
    init();

    _sAppName = sAppName;
    _pAppInfoLabel->setText("<font size=\"5\">" + sAppName + "</font><br><i>Version " + sAppVersion + "</i><br>Using GfifDev Development Platform 0.2");
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
    {
        QWidget * pAboutTab = new QWidget(_pTabWidget);
        QGridLayout * pAboutLayout = new QGridLayout(pAboutTab);
        _pDescriptionLabel = new QLabel(pAboutTab);
        pAboutLayout->addWidget(_pDescriptionLabel, 0, 0, 1, 1);
        _pTabWidget->addTab(pAboutTab, "About");
    }

    QDialogButtonBox * pButtonBox = new QDialogButtonBox(this);
    pButtonBox->setObjectName(QString::fromUtf8("buttonBox"));
    pButtonBox->setOrientation(Qt::Horizontal);
    pButtonBox->setStandardButtons(QDialogButtonBox::Close);

    pLayout->addWidget(pButtonBox, 2, 1, 1, 1);

    // Pestaña de autores
    {
        QWidget * pAuthorTab = new QWidget(_pTabWidget);
        QGridLayout * pAuthorsLayout = new QGridLayout(pAuthorTab);
        _pAuthorsLabel = new QLabel(pAuthorTab);
        addAuthor("GfifDev Development Team", "Developers", "info@gfifdev.com", "www.gfifdev.com");
        pAuthorsLayout->addWidget(_pAuthorsLabel, 0, 0, 1, 1);
        _pTabWidget->addTab(pAuthorTab, "Authors");
    }

    // Pestaña de licencia
    {
        QWidget * pLicenceTab = new QWidget(_pTabWidget);
        QGridLayout * pLicenceLayout = new QGridLayout(pLicenceTab);
        _pLicenceLineEdit = new QLineEdit(pLicenceTab);
        _pLicenceLineEdit->setReadOnly(true);
        pLicenceLayout->addWidget(_pLicenceLineEdit, 0, 0, 1, 1);
        _pTabWidget->addTab(pLicenceTab, "Licence");
    }

    pLayout->addWidget(_pTabWidget, 1, 0, 1, 2);

    connect(pButtonBox, SIGNAL(rejected()), this, SLOT(reject()));

	// Transparencia (Solo Windows 7)
#ifdef _WIN32
	this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground, false);
	QPalette pal = this->palette();
    QColor bg = pal.window().color();
    bg.setAlpha(0x0);
    pal.setColor(QPalette::Window, bg);
    this->setPalette(pal);
    this->ensurePolished(); // workaround Oxygen filling the background
    this->setAttribute(Qt::WA_StyledBackground, false);
#endif

	if(QtWin::isCompositionEnabled())
	{
        QtWin::extendFrameIntoClientArea(this);
        this->setContentsMargins(0, 0, 0, 0);
    }
}
