#include <qpushbutton.h>
#include <qsqlquery.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qsettings.h>
#include <qsqldatabase.h>
#include <qcheckbox.h>
#include <qmessagebox.h>

#include "connectdbdialog.h"

ConnectDbDialog::ConnectDbDialog(QWidget *parent, const char *name, bool modal, WFlags f):ConnectDbDialogBase(parent, name, modal, f)
{
	readSettings();
	
	connect(connectButton, SIGNAL(clicked()), this, SLOT(connectDbClicked()));
	connect(hostNameLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableConnectButton()));
	connect(userNameLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableConnectButton()));
	connect(passwordLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableConnectButton()));
}

void ConnectDbDialog::connectDbClicked()
{
	QSqlDatabase *db = QSqlDatabase::addDatabase("QPSQL7");
	db->setHostName(hostNameLineEdit->text());
	db->setDatabaseName("dbexecutioncontrol");
	db->setUserName(userNameLineEdit->text());
	db->setPassword(passwordLineEdit->text());
	if(!db->open())
	{
		//db->lastError().showMessage();
		QMessageBox::warning(this, tr("Внимание"), tr("Не удалось подключиться к базе данных.\n  Проверьте имя пользователя и пароль."));
		return;
	}
	writeSettings();
	this->accept();
}

//действия при нажатии кн. <Esc>
void ConnectDbDialog::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Key_Escape)
	{
		event->ignore();
		return;
	}
	QDialog::keyPressEvent(event);
}

//чтение настроек
void ConnectDbDialog::readSettings()
{
	QSettings settings;
	settings.setPath("pku.ru", "ExecutionControl");
	settings.beginGroup("/ExecutionControl");
		settings.beginGroup("/connectDatabase");
			hostNameLineEdit->setText(settings.readEntry("/hostname", "localhost"));
			userNameLineEdit->setText(settings.readEntry("/username"));
			passwordLineEdit->setText(settings.readEntry("/password"));
			saveCheckBox->setChecked(settings.readBoolEntry("/savecheck", false));
		settings.endGroup();
	settings.endGroup();
	if(!hostNameLineEdit->text().isEmpty() && !userNameLineEdit->text().isEmpty() && !passwordLineEdit->text().isEmpty())
		connectButton->setEnabled(true);
}

//запись настроек
void ConnectDbDialog::writeSettings()
{
	QSettings settings;
	settings.setPath("pku.ru", "ExecutionControl");
	settings.beginGroup("/ExecutionControl");
		settings.beginGroup("/connectDatabase");
			settings.writeEntry("/hostname", hostNameLineEdit->text());
			if(saveCheckBox->isChecked())
			{
				settings.writeEntry("/username", userNameLineEdit->text());
				settings.writeEntry("/password", passwordLineEdit->text());
			}
			settings.writeEntry("/savecheck", saveCheckBox->isChecked());
		settings.endGroup();
	settings.endGroup();
}

//разрешение/запрещение кнопки "подключиться"
void ConnectDbDialog::enableConnectButton()
{
	connectButton->setEnabled(!hostNameLineEdit->text().isEmpty() && !userNameLineEdit->text().isEmpty() && !passwordLineEdit->text().isEmpty());
}