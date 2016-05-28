#include <qpushbutton.h>
#include <qtable.h>
#include <qcombobox.h>
#include <qdatetime.h>
#include <qgroupbox.h>
#include <qdatetimeedit.h>
#include <qsqlquery.h>

#include "filterdialog.h"

FilterDialog::FilterDialog(QWidget *parent, const char *name, bool modal, WFlags f):FilterDialogBase(parent, name, modal, f)
{
	connect(applyButton, SIGNAL(clicked()), this, SLOT(applyClicked()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));
}

void FilterDialog::applyClicked()
{
	int row;
	
	if(periodGroupBox->isChecked())
		for(row = planTable->numRows() - 1; row >= 0; row--)
		{	
			QDate date(planTable->text(row, 3).right(4).toInt(), planTable->text(row, 3).mid(3, 2).toInt(), planTable->text(row, 3).left(2).toInt());
			if(date < beginDateEdit->date() || date > endDateEdit->date())
				planTable->removeRow(row);
		}
		
	if(yearGroupBox->isChecked() && yearComboBox->currentItem() != 0)
		for(row = planTable->numRows() - 1; row >= 0; row--)
		{	
			if(planTable->text(row, 3).right(4) != yearComboBox->currentText())
				planTable->removeRow(row);
		}
	
	if(skbGroupBox->isChecked() && skbComboBox->currentItem() != 0)
		for(row = planTable->numRows() - 1; row >= 0; row--)
		{	
			if(planTable->text(row, 1) != skbComboBox->currentText())
				planTable->removeRow(row);
		}
	
	if(executiveGroupBox->isChecked() && executiveComboBox->currentItem() != 0)
		for(row = planTable->numRows() - 1; row >= 0; row--)
		{	
			if(planTable->text(row, 2) != executiveComboBox->currentText())
				planTable->removeRow(row);
		}
	setFilters(planTable, currentPlan);
}

void FilterDialog::cancelClicked()
{
	//удаление строк таблицы
	for(int row = planTable->numRows() - 1; row >= 0; row--)
		planTable->removeRow(row);
		
	QSqlQuery query;
	QString idPlan = "";
	query.exec("SELECT id_plan FROM plan WHERE name_plan = '" + currentPlan + "'");
	query.next();
	idPlan = query.value(0).toString();
	query.exec("SELECT topic.name_topic, skb.name_skb, executive.surname, executive.name, executive.patronymic, topic.date_execution, topic.stamp FROM topic, executive, skb WHERE executive.id_executive = topic.id_executive AND skb.id_skb = topic.id_skb AND topic.id_plan = '" + idPlan + "'");
	row = 0;
	while(query.next())
	{
		planTable->insertRows(row, 1);
		planTable->setText(row, 0, query.value(0).toString());
		planTable->setText(row, 1, query.value(1).toString());
		planTable->setText(row, 2, query.value(2).toString() + " " + query.value(3).toString().left(1) + " " + query.value(4).toString().left(1));
		planTable->setText(row, 3, query.value(5).toDate().toString("dd.MM.yyyy"));
		planTable->setText(row, 4, query.value(6).toString());
	}
}

//настройка фильтров
void FilterDialog::setFilters(QTable *table, QString plan)
{
	planTable = table;
	currentPlan = plan;
	int row, i;
	
	executiveComboBox->clear();
	executiveComboBox->insertItem(tr("Не выбран"));
	for(row = 0; row < planTable->numRows(); row++)
		if(executiveComboBox->count() == 0)
			executiveComboBox->insertItem(planTable->text(row, 2));
		else
		{
			for(i = 0; i < executiveComboBox->count(); i++)
				if(planTable->text(row, 2) != executiveComboBox->text(i))
				{
					if(i == executiveComboBox->count() - 1)
						executiveComboBox->insertItem(planTable->text(row, 2));
				}
				else
					break;
		}
	
	skbComboBox->clear();
	skbComboBox->insertItem(tr("Не выбран"));
	for(row = 0; row < planTable->numRows(); row++)
		if(skbComboBox->count() == 0)
			skbComboBox->insertItem(planTable->text(row, 1));
		else
		{
			for(i = 0; i < skbComboBox->count(); i++)
				if(planTable->text(row, 1) != skbComboBox->text(i))
				{
					if(i == skbComboBox->count() - 1)
						skbComboBox->insertItem(planTable->text(row, 1));
				}
				else
					break;
		}
	
	yearComboBox->clear();
	yearComboBox->insertItem(tr("Не выбран"));
	for(row = 0; row < planTable->numRows(); row++)
		if(yearComboBox->count() == 0)
			yearComboBox->insertItem(planTable->text(row, 3).right(4));
		else
		{
			for(i = 0; i < yearComboBox->count(); i++)
				if(planTable->text(row, 3).right(4) != yearComboBox->text(i))
				{
					if(i == yearComboBox->count() - 1)
						yearComboBox->insertItem(planTable->text(row, 3).right(4));
				}
				else
					break;
		}
}

//действия при нажатии кн. <Esc>
void FilterDialog::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}