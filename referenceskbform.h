#ifndef REFERENCESKBFORM_H
#define REFERENCESKBFORM_H

#include "referenceskbformbase.h"

class ReferenceSkbForm:public ReferenceSkbFormBase
{
	Q_OBJECT
	
	public:
		ReferenceSkbForm(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		
	public slots:
		void addClicked();
		void editClicked();
		void removeClicked();
		void selectEntry(int, int);
		void enableAddButton(const QString&);
		void enableEditButton(const QString&);
		void enableRemoveButton();
		
	protected:
		void keyPressEvent(QKeyEvent*);
		
	private:
		QString idEntry;
		void setTable();
		void refreshTable();
};
#endif