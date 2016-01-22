#ifndef FSXEXPORT_GUI_H
#define FSXEXPORT_GUI_H

#include <QtWidgets\qdialog.h>
#include <QtCore\qdebug.h>
#include <QtCore\qobject.h>
#include <QtCore\qthread.h>
#include <QtCore\qfile.h>
#include <QtCore\qtimer.h>
#include <QtNetwork\qtcpsocket.h>
#include <QtCore\qstringlist.h>
#include <QtCore\qstring.h>
#include <QtWidgets\qmessagebox.h>

#include "ui_fsxexport_gui.h"
#include "fsx_export.h"

class fsxexport_gui : public QDialog
{
	Q_OBJECT

public:
	fsxexport_gui(QWidget *parent = 0);
	~fsxexport_gui();

	fsx_export *export_app;
	QThread fsxThread;

	void readDataFromFile();
    QStringList readFlightPlan(const QString &fileName);

private:
	Ui::fsxexport_gui ui;

	QTcpSocket *socket;
    QTimer *timer;

    QString STATUS;
    QString ATC_ID;
    QString AIRLINE;
    QString FLIGHT_NUMBER;
    QString TITLE;
    QString data_export;

private slots:
	void slot_started_slot();

	void readyRead();
    void connected();
    void login_clicked();
    void timeOut();

    QString selectedData(const QString &text);
};

#endif // FSXEXPORT_GUI_H
