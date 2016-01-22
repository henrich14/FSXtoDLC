/********************************************************************************
** Form generated from reading UI file 'fsxexport_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FSXEXPORT_GUI_H
#define UI_FSXEXPORT_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_fsxexport_gui
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QCheckBox *TAS_checkBox;
    QCheckBox *IAS_checkBox;
    QCheckBox *DME_GPS_SPEED_checkBox;
    QCheckBox *BEARING_checkBox;
    QCheckBox *DME_GPS_DIST_checkBox;
    QCheckBox *GS_checkBox;
    QCheckBox *TranssCode_checkBox;
    QCheckBox *HDG_checkBox;
    QCheckBox *GPS_LAT_checkBox;
    QCheckBox *GPS_LON_checkBox;
    QCheckBox *GPS_ALT_checkBox;
    QCheckBox *RADAR_ALT_checkBox;
    QCheckBox *WP_ETE_checkBox;
    QCheckBox *WP_ID_checkBox;
    QLineEdit *FlightPlan_lineEdit;
    QCheckBox *FlightPlan_checkBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *hostAdressEdit;
    QPushButton *loginButton;

    void setupUi(QDialog *fsxexport_gui)
    {
        if (fsxexport_gui->objectName().isEmpty())
            fsxexport_gui->setObjectName(QStringLiteral("fsxexport_gui"));
        fsxexport_gui->resize(211, 287);
        verticalLayout = new QVBoxLayout(fsxexport_gui);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        TAS_checkBox = new QCheckBox(fsxexport_gui);
        TAS_checkBox->setObjectName(QStringLiteral("TAS_checkBox"));

        gridLayout->addWidget(TAS_checkBox, 1, 1, 1, 1);

        IAS_checkBox = new QCheckBox(fsxexport_gui);
        IAS_checkBox->setObjectName(QStringLiteral("IAS_checkBox"));

        gridLayout->addWidget(IAS_checkBox, 2, 1, 1, 1);

        DME_GPS_SPEED_checkBox = new QCheckBox(fsxexport_gui);
        DME_GPS_SPEED_checkBox->setObjectName(QStringLiteral("DME_GPS_SPEED_checkBox"));

        gridLayout->addWidget(DME_GPS_SPEED_checkBox, 3, 1, 1, 1);

        BEARING_checkBox = new QCheckBox(fsxexport_gui);
        BEARING_checkBox->setObjectName(QStringLiteral("BEARING_checkBox"));

        gridLayout->addWidget(BEARING_checkBox, 4, 1, 1, 1);

        DME_GPS_DIST_checkBox = new QCheckBox(fsxexport_gui);
        DME_GPS_DIST_checkBox->setObjectName(QStringLiteral("DME_GPS_DIST_checkBox"));

        gridLayout->addWidget(DME_GPS_DIST_checkBox, 5, 1, 1, 1);

        GS_checkBox = new QCheckBox(fsxexport_gui);
        GS_checkBox->setObjectName(QStringLiteral("GS_checkBox"));

        gridLayout->addWidget(GS_checkBox, 0, 1, 1, 1);

        TranssCode_checkBox = new QCheckBox(fsxexport_gui);
        TranssCode_checkBox->setObjectName(QStringLiteral("TranssCode_checkBox"));

        gridLayout->addWidget(TranssCode_checkBox, 0, 0, 1, 1);

        HDG_checkBox = new QCheckBox(fsxexport_gui);
        HDG_checkBox->setObjectName(QStringLiteral("HDG_checkBox"));

        gridLayout->addWidget(HDG_checkBox, 1, 0, 1, 1);

        GPS_LAT_checkBox = new QCheckBox(fsxexport_gui);
        GPS_LAT_checkBox->setObjectName(QStringLiteral("GPS_LAT_checkBox"));

        gridLayout->addWidget(GPS_LAT_checkBox, 2, 0, 1, 1);

        GPS_LON_checkBox = new QCheckBox(fsxexport_gui);
        GPS_LON_checkBox->setObjectName(QStringLiteral("GPS_LON_checkBox"));

        gridLayout->addWidget(GPS_LON_checkBox, 3, 0, 1, 1);

        GPS_ALT_checkBox = new QCheckBox(fsxexport_gui);
        GPS_ALT_checkBox->setObjectName(QStringLiteral("GPS_ALT_checkBox"));

        gridLayout->addWidget(GPS_ALT_checkBox, 4, 0, 1, 1);

        RADAR_ALT_checkBox = new QCheckBox(fsxexport_gui);
        RADAR_ALT_checkBox->setObjectName(QStringLiteral("RADAR_ALT_checkBox"));

        gridLayout->addWidget(RADAR_ALT_checkBox, 5, 0, 1, 1);

        WP_ETE_checkBox = new QCheckBox(fsxexport_gui);
        WP_ETE_checkBox->setObjectName(QStringLiteral("WP_ETE_checkBox"));

        gridLayout->addWidget(WP_ETE_checkBox, 6, 0, 1, 1);

        WP_ID_checkBox = new QCheckBox(fsxexport_gui);
        WP_ID_checkBox->setObjectName(QStringLiteral("WP_ID_checkBox"));

        gridLayout->addWidget(WP_ID_checkBox, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        FlightPlan_lineEdit = new QLineEdit(fsxexport_gui);
        FlightPlan_lineEdit->setObjectName(QStringLiteral("FlightPlan_lineEdit"));

        verticalLayout->addWidget(FlightPlan_lineEdit);

        FlightPlan_checkBox = new QCheckBox(fsxexport_gui);
        FlightPlan_checkBox->setObjectName(QStringLiteral("FlightPlan_checkBox"));

        verticalLayout->addWidget(FlightPlan_checkBox);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(fsxexport_gui);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        hostAdressEdit = new QLineEdit(fsxexport_gui);
        hostAdressEdit->setObjectName(QStringLiteral("hostAdressEdit"));

        horizontalLayout->addWidget(hostAdressEdit);


        verticalLayout->addLayout(horizontalLayout);

        loginButton = new QPushButton(fsxexport_gui);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        verticalLayout->addWidget(loginButton);


        retranslateUi(fsxexport_gui);

        QMetaObject::connectSlotsByName(fsxexport_gui);
    } // setupUi

    void retranslateUi(QDialog *fsxexport_gui)
    {
        fsxexport_gui->setWindowTitle(QApplication::translate("fsxexport_gui", "fsxexport_gui", 0));
        TAS_checkBox->setText(QApplication::translate("fsxexport_gui", "TAS", 0));
        IAS_checkBox->setText(QApplication::translate("fsxexport_gui", "IAS", 0));
        DME_GPS_SPEED_checkBox->setText(QApplication::translate("fsxexport_gui", "DME/GPS_SPEED", 0));
        BEARING_checkBox->setText(QApplication::translate("fsxexport_gui", "BEARING", 0));
        DME_GPS_DIST_checkBox->setText(QApplication::translate("fsxexport_gui", "DME/GPS_DIST", 0));
        GS_checkBox->setText(QApplication::translate("fsxexport_gui", "GS", 0));
        TranssCode_checkBox->setText(QApplication::translate("fsxexport_gui", "TRANSP", 0));
        HDG_checkBox->setText(QApplication::translate("fsxexport_gui", "HDG", 0));
        GPS_LAT_checkBox->setText(QApplication::translate("fsxexport_gui", "GPS_LAT", 0));
        GPS_LON_checkBox->setText(QApplication::translate("fsxexport_gui", "GPS_LON", 0));
        GPS_ALT_checkBox->setText(QApplication::translate("fsxexport_gui", "GPS_ALT", 0));
        RADAR_ALT_checkBox->setText(QApplication::translate("fsxexport_gui", "RADAR_ALT", 0));
        WP_ETE_checkBox->setText(QApplication::translate("fsxexport_gui", "WP_ETE", 0));
        WP_ID_checkBox->setText(QApplication::translate("fsxexport_gui", "WP_ID", 0));
        FlightPlan_checkBox->setText(QApplication::translate("fsxexport_gui", "Flight Plan:", 0));
        label->setText(QApplication::translate("fsxexport_gui", "Host Address:", 0));
        loginButton->setText(QApplication::translate("fsxexport_gui", "LOGIN", 0));
    } // retranslateUi

};

namespace Ui {
    class fsxexport_gui: public Ui_fsxexport_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSXEXPORT_GUI_H
