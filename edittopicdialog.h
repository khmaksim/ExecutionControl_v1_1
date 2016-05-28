#ifndef EDITTOPICDIALOG_H
#define EDITTOPICDIALOG_H

#include "edittopicdialogbase.h"

class EditTopicDialog:public EditTopicDialogBase
{
	Q_OBJECT
	
	public:
		EditTopicDialog(QWidget *parent = 0, const char *name = 0, bool modal = false, WFlags f = 0);
		void readEntry(QString);
		
	public slots:
		void editClicked();
		void enableEditButton(const QString&);
		
	protected:
		void keyPressEvent(QKeyEvent*);
		
	private:
		QString idTopic;
};
#endif