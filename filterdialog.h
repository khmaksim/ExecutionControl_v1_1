#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include "filterdialogbase.h"

class QTable;

class FilterDialog:public FilterDialogBase
{
	Q_OBJECT
	
	public:
		FilterDialog(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		
		void setFilters(QTable*, QString);
		
	public slots:
		void applyClicked();
		void cancelClicked();
		
	protected:
		void keyPressEvent(QKeyEvent*);
	
	private:
		QTable *planTable;
		
		QString currentPlan;
};
#endif