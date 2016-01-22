#include <QtWidgets\qdialog.h>
#include <QtCore\qobject.h>
#include <QtCore\qthread.h>
#include <QtCore\qwaitcondition.h>
#include <QtCore\qcoreapplication.h>

#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#include <string>
#include <iomanip>      // std::setprecision
#include <iostream>
#include <fstream>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <windows.h>
#include "SimConnect.h"


#pragma once
class fsx_export : public QObject
{
	Q_OBJECT
	
public:
	fsx_export(void);
	~fsx_export(void);

	void DoSetup(QThread & fsxThread);

signals:
	void slot_started();

public slots:
	void doWork();
};

