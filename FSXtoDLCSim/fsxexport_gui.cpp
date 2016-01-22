#include "stdafx.h"
#include "fsxexport_gui.h"

#define DEFAULT_PORT 4200


fsxexport_gui::fsxexport_gui(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	export_app = new fsx_export();

	ui.TranssCode_checkBox->setChecked(true);
    ui.HDG_checkBox->setChecked(true);
    ui.GPS_LAT_checkBox->setChecked(true);
    ui.GPS_LON_checkBox->setChecked(true);
    ui.GPS_ALT_checkBox->setChecked(true);
    ui.RADAR_ALT_checkBox->setChecked(true);
    ui.GS_checkBox->setChecked(true);
    ui.TAS_checkBox->setChecked(true);
    ui.IAS_checkBox->setChecked(true);
    ui.DME_GPS_DIST_checkBox->setChecked(true);
    ui.BEARING_checkBox->setChecked(true);
    ui.DME_GPS_SPEED_checkBox->setChecked(true);
    ui.WP_ETE_checkBox->setChecked(true);
    ui.WP_ID_checkBox->setChecked(true);
    ui.FlightPlan_checkBox->setChecked(true);
    ui.FlightPlan_lineEdit->setText("FllightPlan.pln");
    ui.hostAdressEdit->setText("192.168.1.24");

    STATUS = "";
    ATC_ID = "";
    AIRLINE = "";
    FLIGHT_NUMBER = "";
    TITLE = "";
    data_export = "";

    socket = new QTcpSocket(this);
    timer = new QTimer(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(ui.loginButton, SIGNAL(clicked()), this, SLOT(login_clicked()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOut()));
    connect(ui.hostAdressEdit, SIGNAL(returnPressed()), ui.loginButton, SIGNAL(clicked()));


	connect(export_app, SIGNAL(slot_started()), this, SLOT(slot_started_slot()));

	// do setup of created thread, so GUI can work at the same time, doesn't freeze
	export_app->DoSetup(fsxThread);
}

fsxexport_gui::~fsxexport_gui()
{

}

void fsxexport_gui::login_clicked()
{
	// start the thread and create connection with FSX
	export_app->moveToThread(&fsxThread);
	fsxThread.start();

	// connect to SERVER and start to send data
	readDataFromFile();
    QString loginMessage = "Pilot:" + ATC_ID + ":ALL Ready to communicate";
    socket->connectToHost(ui.hostAdressEdit->text(), DEFAULT_PORT);
    socket->write(loginMessage.toUtf8());
    timer->start(5000);
}

void fsxexport_gui::slot_started_slot()
{
	//qDebug() << "funguje singnal slot";
}

void fsxexport_gui::readyRead()
{
	QString line = QString::fromUtf8(socket->readAll());
}

void fsxexport_gui::connected()
{
	QString loginMessage;
    QString connectedMessage = "connected to server on IP: " + ui.hostAdressEdit->text();
    //ui.statusBar->showMessage(connectedMessage);
}

void fsxexport_gui::timeOut()
{
	readDataFromFile();

    QString message;

    if(ui.FlightPlan_checkBox->isChecked())
    {
        QStringList waypointList = readFlightPlan(ui.FlightPlan_lineEdit->text());
        QString FlightPlan = "\tFlightPlan=" + waypointList.join("+");
        message = "Pilot:" + ATC_ID + ":ALL " + "FLIGHTSIM_DATA{" + data_export + FlightPlan +"}";
    }
    else
    {
        message = "Pilot:" + ATC_ID + ":ALL " + "FLIGHTSIM_DATA{" + data_export + "}";
    }

    socket->write(message.toUtf8());
}

void fsxexport_gui::readDataFromFile()
{
	QFile file("FSX_data.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        timer->stop();
    }
    else
    {
        QTextStream stream(&file);
        QStringList streamList;

        while(!stream.atEnd()) {
            QString line = stream.readLine();
            streamList.append(line);
        }

        file.close();

        QStringList firstLine;
        firstLine = streamList.at(0).split("\t");
        data_export = streamList.at(1);

        QListIterator<QString> iter(firstLine);
        while(iter.hasNext())
        {
            QString expression = iter.next();
            if(expression.contains("STATUS"))
            {
                STATUS = expression.split("=").at(1);
            }
            else if(expression.contains("ATC_ID"))
            {
                ATC_ID = expression.split("=").at(1);
            }
            else if(expression.contains("AIRLINE"))
            {
                AIRLINE = expression.split("=").at(1);
            }
            else if(expression.contains("FLIGHT_NUMBER"))
            {
                FLIGHT_NUMBER = expression.split("=").at(1);
            }
            else if(expression.contains("TITLE"))
            {
                TITLE = expression.split("=").at(1);
            }
        }

        QString outputDataText = selectedData(data_export);

        data_export = "STATUS=" + STATUS + "\t" + outputDataText;
    }
}

QStringList fsxexport_gui::readFlightPlan(const QString &fileName)
{
	QStringList FlightPlanList;

    QFile file(fileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }
    else
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            QString line = stream.readLine();
            if(line.contains("<ATCWaypoint id="))
            {
                QStringList WPList = line.split("\"");
                FlightPlanList << WPList.at(1);
            }
        }
    }
    file.close();

    return FlightPlanList;
}


QString fsxexport_gui::selectedData(const QString &text)
{
	QString outputText;
    QStringList outputList;

    QStringList dataList;

    if(ui.TranssCode_checkBox->isChecked())
        dataList << ui.TranssCode_checkBox->text();
    if(ui.HDG_checkBox->isChecked())
        dataList << ui.HDG_checkBox->text();
    if(ui.GPS_LAT_checkBox->isChecked())
        dataList << ui.GPS_LAT_checkBox->text();
    if(ui.GPS_LON_checkBox->isChecked())
        dataList << ui.GPS_LON_checkBox->text();
    if(ui.GPS_ALT_checkBox->isChecked())
        dataList << ui.GPS_ALT_checkBox->text();
    if(ui.RADAR_ALT_checkBox->isChecked())
        dataList << ui.RADAR_ALT_checkBox->text();
    if(ui.GS_checkBox->isChecked())
        dataList << ui.GS_checkBox->text();
    if(ui.TAS_checkBox->isChecked())
        dataList << ui.TAS_checkBox->text();
    if(ui.IAS_checkBox->isChecked())
        dataList << ui.IAS_checkBox->text();
    if(ui.DME_GPS_DIST_checkBox->isChecked())
        dataList << ui.DME_GPS_DIST_checkBox->text();
    if(ui.BEARING_checkBox->isChecked())
        dataList << ui.BEARING_checkBox->text();
    if(ui.DME_GPS_SPEED_checkBox->isChecked())
        dataList << ui.DME_GPS_SPEED_checkBox->text();
    if(ui.WP_ETE_checkBox->isChecked())
        dataList << ui.WP_ETE_checkBox->text();
    if(ui.WP_ID_checkBox->isChecked())
        dataList << ui.WP_ID_checkBox->text();

    //qDebug() << dataList;

    QStringList textList = text.split("\t");
    QListIterator<QString> iter(textList);
    while(iter.hasNext())
    {
        QString expression = iter.next();

        for(int i=0; i< dataList.size(); i++)
        {
            if(expression.contains(dataList.at(i)))
            {
                outputList.append(expression);
            }
        }
    }

    outputText = outputList.join("\t");
    return outputText;
}