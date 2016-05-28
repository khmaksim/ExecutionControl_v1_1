#include <qpushbutton.h>
#include <qsqlquery.h>
#include <qlineedit.h>
#include <qmessagebox.h>

#include "newplandialog.h"

NewPlanDialog::NewPlanDialog(QWidget *parent, const char *name, bool modal, WFlags f):NewPlanDialogBase(parent, name, modal, f)
{
	connect(newButton, SIGNAL(clicked()), this, SLOT(newClicked()));
	connect(planLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableNewButton(const QString&)));
}

//действия при нажатии кн. <Esc>
void NewPlanDialog::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}

//сохранение плана
void NewPlanDialog::newClicked()
{
	QSqlQuery query;
	query.prepare("INSERT INTO plan(name_plan) VALUES(:name_plan)");
	query.bindValue(":name_plan", planLineEdit->text());
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка при добавлении записи в базу данных."));
		//query.lastError().showMessage();
	}
}

//разрешение/запрещение кнопки "добавить"
void NewPlanDialog::enableNewButton(const QString &text)
{
	newButton->setEnabled(!text.isEmpty());
}