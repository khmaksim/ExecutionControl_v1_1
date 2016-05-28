#ifndef OPENPLANDIALOG_H
#define OPENPLANDIALOG_H

#include "openplandialogbase.h"

class OpenPlanDialog:public OpenPlanDialogBase
{
	Q_OBJECT
	
	public:
		OpenPlanDialog(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		
	public slots:
		void enableOpenButton(const QString&);
		
	protected:
		void keyPressEvent(QKeyEvent*);
};
#endif