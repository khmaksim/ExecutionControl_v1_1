#include <qsqlquery.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qmessagebox.h>

#include "openplandialog.h"

OpenPlanDialog::OpenPlanDialog(QWidget *parent, const char *name, bool modal, WFlags f):OpenPlanDialogBase(parent, name, modal, f)
{
	//загрузка списка планов
	planComboBox->insertItem(tr("Не выбран"));
	QSqlQuery query;
	query.exec("SELECT name_plan FROM plan");
	while(query.next())
		planComboBox->insertItem(query.value(0).toString());
		
	connect(planComboBox, SIGNAL(activated(const QString&)), this, SLOT(enableOpenButton(const QString&)));
}

//действия при нажатии кн. <Esc>
void OpenPlanDialog::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}

//разрешить/запретить кнопку "открить"
void OpenPlanDialog::enableOpenButton(const QString &text)
{
	if(text == tr("Не выбран"))
		openButton->setEnabled(false);
	else
		openButton->setEnabled(true);
}