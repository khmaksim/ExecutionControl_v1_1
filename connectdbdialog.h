#ifndef CONNECTDBDIALOG_H
#define CONNECTDBDIALOG_H

#include "connectdbdialogbase.h"

class ConnectDbDialog:public ConnectDbDialogBase
{
	Q_OBJECT
	
	public:
		ConnectDbDialog(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		
	protected:
		void keyPressEvent(QKeyEvent*);
	
	private slots:
		void connectDbClicked();
		void enableConnectButton();
		
	private:
		void readSettings();
		void writeSettings();
};
#endif