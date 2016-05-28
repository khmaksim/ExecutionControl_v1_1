#ifndef REMOVEPLANDIALOG_H
#define REMOVEPLANDIALOG_H

#include "removeplandialogbase.h"

class RemovePlanDialog:public RemovePlanDialogBase
{
	Q_OBJECT
	
	public:
		RemovePlanDialog(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		
	public slots:
		void removeClicked();
		void enableRemoveButton(const QString&);
		
	protected:
		void keyPressEvent(QKeyEvent*);
};
#endif