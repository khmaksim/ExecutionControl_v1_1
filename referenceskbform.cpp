#include <qpushbutton.h>
#include <qsqlquery.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qmessagebox.h>

#include "referenceskbform.h"

ReferenceSkbForm::ReferenceSkbForm(QWidget *parent, const char *name, bool modal, WFlags f):ReferenceSkbFormBase(parent, name, modal, f)
{
	this->refreshTable();
	this->setTable();
	
	connect(addButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(editButton, SIGNAL(clicked()), this, SLOT(editClicked()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(removeClicked()));
	connect(table, SIGNAL(currentChanged(int, int)), this, SLOT(selectEntry(int, int)));
	connect(skbLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableAddButton(const QString&)));
	connect(skbLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableEditButton(const QString&)));
	connect(table, SIGNAL(selectionChanged()), this, SLOT(enableRemoveButton()));
}

//настройка отображения таблицы
void ReferenceSkbForm::setTable()
{
	table->hideColumn(1);
	table->setLeftMargin(0);
}

//обновить список
void ReferenceSkbForm::refreshTable()
{
	//очистка таблицы
	for(int i = table->numRows() - 1; i >= 0; i--)
		table->removeRow(i);
		
	QSqlQuery query;
	query.exec("SELECT name_skb, id_skb FROM skb");	
	int row = 0;
	while(query.next())
	{
		table->insertRows(row, 1);
		table->setText(row, 0, query.value(0).toString());
		table->setText(row, 1, query.value(1).toString());
		row++;
	}
	table->adjustColumn(0);
}

//действия при нажатии кн. <Esc>
void ReferenceSkbForm::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}

//добавить запись
void ReferenceSkbForm::addClicked()
{
	QSqlQuery query;
	query.prepare("INSERT INTO skb(name_skb) VALUES(:name_skb)");
	query.bindValue(":name_skb", skbLineEdit->text());
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка при добавлении записи в базу данных."));
		//query.lastError().showMessage();
	}
	this->refreshTable();
	skbLineEdit->clear();
}

//редактировать запись
void ReferenceSkbForm::editClicked()
{
	QSqlQuery query;
	query.prepare("UPDATE skb SET name_skb = '" + skbLineEdit->text() + "' WHERE id_skb = '" + idEntry + "'");
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка при обновлении записи в базе данных."));
		//query.lastError().showMessage();
	}
	refreshTable();
	skbLineEdit->clear();
}

//удалить запись
void ReferenceSkbForm::removeClicked()
{
	QSqlQuery query;
	query.prepare("DELETE FROM skb WHERE id_skb = '" + table->text(table->currentRow(), 1) + "'");
	if(!query.exec())
	{
		QMessageBox::warning(this, tr("Предупреждение"), tr("Данную запись удалить невозможно. Она используется \n      для сохранения целостности базы данных."));
		//query.lastError().showMessage();
	}
	refreshTable();
	skbLineEdit->clear();
}

//выбор запись
void ReferenceSkbForm::selectEntry(int row, int col)
{
	skbLineEdit->setText(table->text(row, 0));
	idEntry = table->text(row, 1);
}

//запрещение/разрешение кнопки "добавить"
void ReferenceSkbForm::enableAddButton(const QString &text)
{
	addButton->setEnabled(!text.isEmpty());
}

//запрещение/разрешение кнопки "редактировать"
void ReferenceSkbForm::enableEditButton(const QString &text)
{
	if(table->currentSelection() != -1)
		editButton->setEnabled(!text.isEmpty());
}

//запретить/разрешить кнопку "удалить"
void ReferenceSkbForm::enableRemoveButton()
{
	if(table->currentSelection() != -1)
		removeButton->setEnabled(true);
	else
		removeButton->setEnabled(false);
}