#ifndef REFERENCEEXECUTIONFORM_H
#define REFERENCEEXECUTIONFORM_H

#include "referenceexecutionformbase.h"

class ReferenceExecutionForm:public ReferenceExecutionFormBase
{
	Q_OBJECT
	
	public:
		ReferenceExecutionForm(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		
	protected:
		void keyPressEvent(QKeyEvent*);
	
	private slots:
		void addClicked();
		void editClicked();
		void removeClicked();
		void selectEntry(int, int);
		void enableAddButton(const QString&);
		void enableEditButton(const QString&);
		void enableRemoveButton();
		
	private:
		QString idEntry;
		void setTable();
		void refreshTable();
		void clearLineEdit();
};
#endif