
#include<About.hpp>

// Qt
#include<QGridLayout>
#include<QLabel>
#include<QTabWidget>
#include<QDialogButtonBox>

About::About(const QString &sAppName, const QString &sAppVersion, const QString &sDescription, QWidget * pParent):
    QDialog(pParent)
{
    init();

    _sAppName = sAppName;
    _pAppInfoLabel->setText("<font size=\"5\">" + sAppName + "</font><br><i>Version " + sAppVersion + "</i><br>Using GfifDev Development Platform 0.1");
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
    // _pAuthorsLabel->setText(_pAuthorsLabel->text() + sAuthor);
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
    pLayout->addWidget(_pTabWidget, 1, 0, 1, 2);

    QDialogButtonBox * pButtonBox = new QDialogButtonBox(this);
    pButtonBox->setObjectName(QString::fromUtf8("buttonBox"));
    pButtonBox->setOrientation(Qt::Horizontal);
    pButtonBox->setStandardButtons(QDialogButtonBox::Close);

    pLayout->addWidget(pButtonBox, 2, 1, 1, 1);

    connect(pButtonBox, SIGNAL(rejected()), this, SLOT(reject()));
}
