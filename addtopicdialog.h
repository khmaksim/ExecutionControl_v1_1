#ifndef ADDTOPICDIALOG_H
#define ADDTOPICDIALOG_H

#include "addtopicdialogbase.h"

class AddTopicDialog:public AddTopicDialogBase
{
	Q_OBJECT
	
	public:
		AddTopicDialog(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		
		void setIdPlan(QString);
		
	protected:
		void keyPressEvent(QKeyEvent*);
		
	private slots:
		void addClicked();
		void enableAddButton(const QString&);
	
	private:
		int idPlan;
};
#endif