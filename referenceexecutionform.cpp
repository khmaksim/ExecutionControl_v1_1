#include <qpushbutton.h>
#include <qsqlquery.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qmessagebox.h>

#include "referenceexecutionform.h"

ReferenceExecutionForm::ReferenceExecutionForm(QWidget *parent, const char *name, bool modal, WFlags f):ReferenceExecutionFormBase(parent, name, modal, f)
{
	this->refreshTable();
	this->setTable();		//��������� �������
	
	connect(addButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(editButton, SIGNAL(clicked()), this, SLOT(editClicked()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(removeClicked()));
	connect(table, SIGNAL(currentChanged(int, int)), this, SLOT(selectEntry(int, int)));
	connect(surnameLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableAddButton(const QString&)));
	connect(surnameLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableEditButton(const QString&)));
	connect(table, SIGNAL(selectionChanged()), this, SLOT(enableRemoveButton()));
}

//��������� ����������� �������
void ReferenceExecutionForm::setTable()
{
	table->hideColumn(5);
	table->setLeftMargin(0);
}

//�������� ��� ����
void ReferenceExecutionForm::clearLineEdit()
{
	surnameLineEdit->clear();
	nameLineEdit->clear();
	patronymicLineEdit->clear();
	phoneLineEdit->clear();
	cabinetLineEdit->clear();
}

//�������� ������
void ReferenceExecutionForm::refreshTable()
{
	//������� �������
	for(int i = table->numRows() - 1; i >= 0; i--)
		table->removeRow(i);
		
	QSqlQuery query;
	query.exec("SELECT surname, name, patronymic, phone, cabinet, id_executive FROM executive");
	int row = 0;
	while(query.next())
	{
		table->insertRows(row, 1);
		table->setText(row, 0, query.value(0).toString());
		table->setText(row, 1, query.value(1).toString());
		table->setText(row, 2, query.value(2).toString());
		table->setText(row, 3, query.value(3).toString());
		table->setText(row, 4, query.value(4).toString());
		table->setText(row, 5, query.value(5).toString());
		row++;				
	}
	table->adjustColumn(0);
	table->adjustColumn(1);
	table->adjustColumn(2);
	table->adjustColumn(3);
	table->adjustColumn(4);
}

//�������� ��� ������� ��. <Esc>
void ReferenceExecutionForm::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}

//�������� ������
void ReferenceExecutionForm::addClicked()
{
	QSqlQuery query;
	
	query.prepare("INSERT INTO executive(surname, name, patronymic, phone, cabinet) VALUES(:surname, :name, :patronymic, :phone, :cabinet)");
	query.bindValue(":surname", surnameLineEdit->text());
	query.bindValue(":name", nameLineEdit->text());
	query.bindValue(":patronymic", patronymicLineEdit->text());
	query.bindValue(":phone", phoneLineEdit->text());
	query.bindValue(":cabinet", cabinetLineEdit->text());
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("������"), tr("������ ��� ���������� ������ � ���� ������."));
		//query.lastError().showMessage();
	}
	refreshTable();
	clearLineEdit();
}

//������������� ������
void ReferenceExecutionForm::editClicked()
{
	QSqlQuery query;
	query.prepare("UPDATE executive SET surname = '" + surnameLineEdit->text() + "', name = '" + nameLineEdit->text() + "', patronymic = '" + patronymicLineEdit->text() + "', phone = '" + phoneLineEdit->text() + "', cabinet = '" + cabinetLineEdit->text() + "' WHERE id_executive = '" + idEntry + "'");
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("������"), tr("������ ��� ���������� ������ � ���� ������."));
		//query.lastError().showMessage();
	}
	refreshTable();
	clearLineEdit();
}

//������� ������
void ReferenceExecutionForm::removeClicked()
{
	if(table->currentSelection() == -1)
	{
		QMessageBox::information(this, tr("����������"), tr("�������� �� ������ ������ ��� ��������."));
		return;
	}
	QSqlQuery query;
	query.prepare("DELETE FROM executive WHERE id_executive = '" + table->text(table->currentRow(), 5) + "'");
	if(!query.exec())
	{
		QMessageBox::warning(this, tr("��������������"), tr("������ ������ ������� ����������. ��� ������������ \n      ��� ���������� ����������� ���� ������."));
		//query.lastError().showMessage();
	}
	refreshTable();
	clearLineEdit();
}

//����� ������
void ReferenceExecutionForm::selectEntry(int row, int col)
{
	surnameLineEdit->setText(table->text(row, 0));
	nameLineEdit->setText(table->text(row, 1));
	patronymicLineEdit->setText(table->text(row, 2));
	phoneLineEdit->setText(table->text(row, 3));
	cabinetLineEdit->setText(table->text(row, 4));
	idEntry = table->text(row, 5);
}

//����������/���������� ������ "��������"
void ReferenceExecutionForm::enableAddButton(const QString &text)
{
	addButton->setEnabled(!text.isEmpty());
}

//����������/���������� ������ "�������������"
void ReferenceExecutionForm::enableEditButton(const QString &text)
{
	if(table->currentSelection() != -1)
		editButton->setEnabled(!text.isEmpty());
}
//���������/��������� ������ "�������"
void ReferenceExecutionForm::enableRemoveButton()
{
	if(table->currentSelection() != -1)
		removeButton->setEnabled(true);
	else
		removeButton->setEnabled(false);
}