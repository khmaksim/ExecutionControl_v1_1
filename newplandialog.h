#ifndef NEWPLANDIALOG_H
#define NEWPLANDIALOG_H

#include "newplandialogbase.h"

class NewPlanDialog:public NewPlanDialogBase
{
	Q_OBJECT
	
	public:
		NewPlanDialog(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		
	public slots:
		void newClicked();
		void enableNewButton(const QString&);
		
	protected:
		void keyPressEvent(QKeyEvent*);
};
#endif