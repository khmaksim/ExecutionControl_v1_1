#include <qpushbutton.h>
#include <qsqlquery.h>
#include <qtextedit.h>
#include <qcombobox.h>
#include <qmessagebox.h>

#include "removeplandialog.h"

RemovePlanDialog::RemovePlanDialog(QWidget *parent, const char *name, bool modal, WFlags f):RemovePlanDialogBase(parent, name, modal, f)
{
	//�������� ������ ������ �� ���� ������
	planComboBox->insertItem(tr("�� ������"));
	QSqlQuery query;
	query.exec("SELECT name_plan FROM plan");
	while(query.next())
		planComboBox->insertItem(query.value(0).toString());
		
	connect(removeButton, SIGNAL(clicked()), this, SLOT(removeClicked()));
	connect(planComboBox, SIGNAL(activated(const QString&)), this, SLOT(enableRemoveButton(const QString&)));
}

//�������� ��� ������� ��. <Esc>
void RemovePlanDialog::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}

//�������� �����
void RemovePlanDialog::removeClicked()
{
	QSqlQuery query;
	query.exec("SELECT id_plan FROM plan WHERE name_plan = '" + planComboBox->currentText() + "'");
	query.next();
	QString idPlan = query.value(0).toString();
	query.prepare("DELETE FROM topic WHERE id_plan = '" + idPlan + "'");
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("������"), tr("������ ��� �������� ������ �� ���� ������."));
		//query.lastError().showMessage();
	}
	query.prepare("DELETE FROM plan WHERE id_plan = '" + idPlan +"'");
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("������"), tr("������ ��� �������� ������ �� ���� ������."));
		//query.lastError().showMessage();
	}
}

//���������/��������� ������ "�������"
void RemovePlanDialog::enableRemoveButton(const QString &text)
{
	if(text == tr("�� ������"))
		removeButton->setEnabled(false);
	else
		removeButton->setEnabled(true);
}