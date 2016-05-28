#include <qpushbutton.h>
#include <qsqlquery.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qmessagebox.h>

#include "edittopicdialog.h"

EditTopicDialog::EditTopicDialog(QWidget *parent, const char *name, bool modal, WFlags f):EditTopicDialogBase(parent, name, modal, f)
{	
	QSqlQuery query;
	query.exec("SELECT surname, name, patronymic FROM executive");
	while(query.next())
		executiveComboBox->insertItem(query.value(0).toString() + " " + query.value(1).toString().left(1) + " " + query.value(2).toString().left(1));
	query.exec("SELECT name_skb FROM skb");
	while(query.next())
		skbComboBox->insertItem(query.value(0).toString());
	
	connect(editButton, SIGNAL(clicked()), this, SLOT(editClicked()));
	connect(topicLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableEditButton(const QString&)));
}

void EditTopicDialog::readEntry(QString nameTopic)
{
	QSqlQuery query;
	query.exec("SELECT id_topic FROM topic WHERE name_topic = '" + nameTopic + "'");
	query.next();
	idTopic = query.value(0).toString();
	query.exec("SELECT topic.name_topic, skb.name_skb, executive.surname, executive.name, executive.patronymic, topic.date_execution, topic.stamp FROM topic, executive, skb WHERE executive.id_executive = topic.id_executive AND skb.id_skb = topic.id_skb AND topic.id_topic = '" + idTopic + "'");
	query.next();
	topicLineEdit->setText(query.value(0).toString());
	skbComboBox->setCurrentText(query.value(1).toString());
	executiveComboBox->setCurrentText(query.value(2).toString() + " " + query.value(3).toString().left(1) + " " + query.value(4).toString().left(1));
	dateDateEdit->setDate(query.value(5).toDate());
	stampLineEdit->setText(query.value(6).toString());
}

//действия при нажатии кн. <Esc>
void EditTopicDialog::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}

//сохранение плана
void EditTopicDialog::editClicked()
{
	QString idSkb;
	QString idExecutive;
	QSqlQuery query;
	
	query.exec("SELECT id_executive FROM executive WHERE surname = '" + executiveComboBox->currentText().left(executiveComboBox->currentText().length() - 4) + "'");
	query.next();
	idExecutive = query.value(0).toString();
	query.exec("SELECT id_skb FROM skb WHERE name_skb = '" + skbComboBox->currentText() + "'");
	query.next();
	idSkb = query.value(0).toString();
	query.prepare("UPDATE topic SET name_topic = '" + topicLineEdit->text() + "', id_executive = '" + idExecutive + "', id_skb = '" + idSkb + "', date_execution = '" + dateDateEdit->date().toString("dd.MM.yyyy") + "', stamp = '" + stampLineEdit->text() + "' WHERE id_topic = '" + idTopic + "'");
	if(!query.exec())
	{
		QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка при обновлении записи в базе данных."));
		query.lastError().showMessage();
	}
	this->accept();
}

//разрешается/запрщается кнопка "редактировать"
void EditTopicDialog::enableEditButton(const QString &text)
{
	editButton->setEnabled(!text.isEmpty());
}