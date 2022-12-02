/********************************************************************************
** Form generated from reading UI file 'notifydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFYDIALOG_H
#define UI_NOTIFYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NotifyDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *InformationIcon;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *NotifyDialog)
    {
        if (NotifyDialog->objectName().isEmpty())
            NotifyDialog->setObjectName("NotifyDialog");
        NotifyDialog->resize(265, 182);
        QPalette palette;
        QBrush brush(QColor(138, 179, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        NotifyDialog->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Historic")});
        NotifyDialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/Images/InformationIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        NotifyDialog->setWindowIcon(icon);
        NotifyDialog->setSizeGripEnabled(true);
        NotifyDialog->setModal(false);
        buttonBox = new QDialogButtonBox(NotifyDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(178, 156, 80, 24));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        InformationIcon = new QLabel(NotifyDialog);
        InformationIcon->setObjectName("InformationIcon");
        InformationIcon->setGeometry(QRect(30, 50, 50, 50));
        InformationIcon->setPixmap(QPixmap(QString::fromUtf8(":/Resources/Images/InformationIcon.png")));
        InformationIcon->setScaledContents(true);
        plainTextEdit = new QPlainTextEdit(NotifyDialog);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(100, 40, 151, 81));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        plainTextEdit->setPalette(palette1);
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        InformationIcon->raise();
        buttonBox->raise();
        plainTextEdit->raise();

        retranslateUi(NotifyDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NotifyDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NotifyDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NotifyDialog);
    } // setupUi

    void retranslateUi(QDialog *NotifyDialog)
    {
        NotifyDialog->setWindowTitle(QCoreApplication::translate("NotifyDialog", "Input Error", nullptr));
        InformationIcon->setText(QString());
        plainTextEdit->setPlainText(QCoreApplication::translate("NotifyDialog", "You did not insert the FEN notation, please try again.\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotifyDialog: public Ui_NotifyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFYDIALOG_H
