#include "stdafx.h"
#include "fsxexport_gui.h"


int main(int argc, char * argv[])
{
	// create QApplication befor QDialog is created
	QApplication app(argc, argv);

	// create a gui window from where everything is controlled
	fsxexport_gui gui;

	return gui.exec();
}

