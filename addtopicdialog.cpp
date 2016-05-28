#include <qpushbutton.h>
#include <qsqlquery.h>
#include <qcombobox.h>
#include <qdatetimeedit.h>
#include <qlineedit.h>
#include <qmessagebox.h>

#include "addtopicdialog.h"

AddTopicDialog::AddTopicDialog(QWidget *parent, const char *name, bool modal, WFlags f):AddTopicDialogBase(parent, name, modal, f)
{
	QSqlQuery query;
	query.exec("SELECT surname, name, patronymic FROM executive");
	while(query.next())
		executiveComboBox->insertItem(query.value(0).toString() + " " + query.value(1).toString().left(1) + " " + query.value(2).toString().left(1));
	query.exec("SELECT name_skb FROM skb");
	while(query.next())
		skbComboBox->insertItem(query.value(0).toString());
		
	connect(addButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(topicLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableAddButton(const QString&)));
}

//определение плана
void AddTopicDialog::setIdPlan(QString namePlan)
{
	QSqlQuery query;
	query.exec("SELECT id_plan FROM plan WHERE name_plan = '" + namePlan + "'");
	query.next();
	idPlan = query.value(0).toInt();
}

//действия при нажатии кн. <Esc>
void AddTopicDialog::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}

//сохранение плана
void AddTopicDialog::addClicked()
{
	if(topicLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, tr("Информация"), tr("Введите название темы."));
		return;
	}
	QSqlQuery query;
	query.exec("SELECT id_executive FROM executive WHERE surname = '" + executiveComboBox->currentText().left(executiveComboBox->currentText().length() - 4) + "'");
	query.next();
	int idExecutive = query.value(0).toInt();
	query.exec("SELECT id_skb FROM skb WHERE name_skb = '" + skbComboBox->currentText() + "'");
	query.next();
	int idSkb = query.value(0).toInt();
	
	query.prepare("INSERT INTO topic(id_plan, name_topic, id_executive, id_skb, date_execution, stamp)"
				"VALUES(:id_plan, :name_topic, :id_executive, :id_skb, :date_execution, :stamp)");
	query.bindValue(":id_plan", idPlan);
	query.bindValue(":name_topic", topicLineEdit->text());
	query.bindValue(":id_executive", idExecutive);
	query.bindValue(":id_skb", idSkb);
	query.bindValue(":date_execution", dateDateEdit->date());
	query.bindValue(":stamp", stampLineEdit->text());
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка при добавлении записи в базу данных."));
		//query.lastError().showMessage();
	}
	this->accept();
}

//запрещение/разрешение кнопки "добавить"
void AddTopicDialog::enableAddButton(const QString &text)
{
	addButton->setEnabled(!text.isEmpty());
}