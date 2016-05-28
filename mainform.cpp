#include <qaction.h>
#include <qtoolbar.h>
#include <qpopupmenu.h>
#include <qsettings.h>
#include <qmessagebox.h>
#include <qmenubar.h>
#include <qapplication.h>
#include <qsqlquery.h>
#include <qsqldatabase.h>
#include <qfile.h>
#include <qtable.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qaxobject.h>
#include <qaxbase.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qdir.h>

#include "mainform.h"
#include "newplandialog.h"
#include "removeplandialog.h"
#include "addtopicdialog.h"
#include "edittopicdialog.h"
#include "referenceexecutionform.h"
#include "referenceskbform.h"
#include "openplandialog.h"
#include "connectdbdialog.h"
#include "mcdocument.h"
#include "filterdialog.h"

MainForm::MainForm(QWidget *parent, const char *name):MainFormBase(parent, name)
{
	createActions();
	createMenus();
	createToolBars();
	readSettings();		//чтение настроек
	setCaption(tr("Контроль исполнения"));
	setPlanTable();
	referenceExecutionForm = 0;
	referenceSkbForm =0;
	filterDialog = 0;
	currentPlan = "";
}

//создания действий
void MainForm::createActions()
{
	newPlanAct = new QAction(tr("Новый"), 0, this);
	newPlanAct->setIconSet(QPixmap::fromMimeSource("document_16.png"));
	openPlanAct = new QAction(tr("Открыть"), 0, this);
	openPlanAct->setIconSet(QPixmap::fromMimeSource("folder_16.png"));
	removePlanAct = new QAction(tr("Удалить"), 0, this);
	removePlanAct->setIconSet(QPixmap::fromMimeSource("delete_16.png"));
	quitAct = new QAction(tr("Выход"), 0, this);
	quitAct->setIconSet(QPixmap::fromMimeSource("shutdown_16.png"));
	addTopicAct = new QAction(tr("Добавить"), 0, this);
	addTopicAct->setIconSet(QPixmap::fromMimeSource("plus_16.png"));
	addTopicAct->setEnabled(false);
	editTopicAct = new QAction(tr("Редактировать"), 0, this);
	editTopicAct->setIconSet(QPixmap::fromMimeSource("pencil_16.png"));
	editTopicAct->setEnabled(false);
	removeTopicAct = new QAction(tr("Удалить"), 0, this);
	removeTopicAct->setIconSet(QPixmap::fromMimeSource("delete_16.png"));
	removeTopicAct->setEnabled(false);
	filterAct = new QAction(tr("Фильтр"), 0, this);
	filterAct->setIconSet(QPixmap::fromMimeSource("funnel_16.png"));
	filterAct->setEnabled(false);
	refExecutiveAct = new QAction(tr("Исполнители"), 0, this);
	refExecutiveAct->setIconSet(QPixmap::fromMimeSource("user_16.png"));
	refSkbAct = new QAction(tr("СКБ"), 0, this);
	refSkbAct->setIconSet(QPixmap::fromMimeSource("gear_16.png"));
	outAct = new QAction(tr("Вывод в MS Word"), 0, this);
	outAct->setIconSet(QPixmap::fromMimeSource("office_16.png"));
	outAct->setEnabled(false);
	
	connect(newPlanAct, SIGNAL(activated()), this, SLOT(newPlanActivated()));
	connect(openPlanAct, SIGNAL(activated()), this, SLOT(openPlanActivated()));
	connect(removePlanAct, SIGNAL(activated()), this, SLOT(removePlanActivated()));
	connect(quitAct, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));
	connect(addTopicAct, SIGNAL(activated()), this, SLOT(addTopicActivated()));
	connect(editTopicAct, SIGNAL(activated()), this, SLOT(editTopicActivated()));
	connect(removeTopicAct, SIGNAL(activated()), this, SLOT(removeTopicActivated()));
	connect(filterAct, SIGNAL(activated()), this, SLOT(filterActivated()));
	connect(refExecutiveAct, SIGNAL(activated()), this, SLOT(openReferenceExecutiveActivated()));
	connect(refSkbAct, SIGNAL(activated()), this, SLOT(openReferenceSkbActivated()));
	connect(outAct, SIGNAL(activated()), this, SLOT(outInWordActivated()));
}

//создание меню
void MainForm::createMenus()
{
	planMenu = new QPopupMenu(this);
	newPlanAct->addTo(planMenu);
	openPlanAct->addTo(planMenu);
	removePlanAct->addTo(planMenu);
	planMenu->insertSeparator();
	quitAct->addTo(planMenu);
	
	topicMenu = new QPopupMenu(this);
	addTopicAct->addTo(topicMenu);
	editTopicAct->addTo(topicMenu);
	removeTopicAct->addTo(topicMenu);
	topicMenu->insertSeparator();
	filterAct->addTo(topicMenu);
	
	referenceMenu = new QPopupMenu(this);
	refExecutiveAct->addTo(referenceMenu);
	refSkbAct->addTo(referenceMenu);
	
	reportMenu = new QPopupMenu(this);
	outAct->addTo(reportMenu);
	
	menuBar()->insertItem(tr("План"), planMenu);
	menuBar()->insertItem(tr("Тема"), topicMenu);
	menuBar()->insertItem(tr("Справочники"), referenceMenu);
	menuBar()->insertItem(tr("Отчет"), reportMenu);
}

//создание тулбара
void MainForm::createToolBars()
{
	topicToolBar = new QToolBar(tr("Тема"), this);
	setDockEnabled(topicToolBar, DockLeft, false);
	setDockEnabled(topicToolBar, DockRight, false);
	setDockEnabled(topicToolBar, DockBottom, false);

	addTopicAct->addTo(topicToolBar);
	editTopicAct->addTo(topicToolBar);
	removeTopicAct->addTo(topicToolBar);	
}

//чтение настроек
void MainForm::readSettings()
{
	QSettings settings;
	settings.setPath("pku.ru", "ExecutionControl");
	settings.beginGroup("/ExecutionControl");
		settings.beginGroup("/geometry");
			int x = settings.readNumEntry("/x", 200);
			int y = settings.readNumEntry("/y", 200);
			int w = settings.readNumEntry("/width", 400);
			int h = settings.readNumEntry("/height", 200);
			move(x, y);
			resize(w, h);
		settings.endGroup();
		settings.beginGroup("/widthColumn");
			for(int col = 0; col < planTable->numCols(); col++)
				planTable->setColumnWidth(col, settings.readNumEntry("/" + QString::number(col), 150));
		settings.endGroup();
	settings.endGroup();
}

//запись настроек
void MainForm::writeSettings()
{
	QSettings settings;
	settings.setPath("pku.ru", "ExecutionControl");
	settings.beginGroup("/ExecutionControl");
		settings.beginGroup("/geometry");
			settings.writeEntry("/x", x());
			settings.writeEntry("/y", y());
			settings.writeEntry("/width", width());
			settings.writeEntry("/height", height());
		settings.endGroup();
		settings.beginGroup("/widthColumn");		//сохранение ширины столбцов таблицы
			for(int col = 0; col < planTable->numCols(); col++)
				settings.writeEntry("/" + QString::number(col), planTable->columnWidth(col));
			settings.endGroup();
	settings.endGroup();
}

//настройка таблицы отображения
void MainForm::setPlanTable()
{
	planTable->setLeftMargin(0);
}

//обновление таблицы
void MainForm::refreshPlanTable(QString currentPlan)
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

//новый план
void MainForm::newPlanActivated()
{
	NewPlanDialog newPlanDialog(this, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
	newPlanDialog.exec();
}

void MainForm::enableActivatedButton()
{
	addTopicAct->setEnabled(!currentPlan.isEmpty());
	editTopicAct->setEnabled(!currentPlan.isEmpty());
	removeTopicAct->setEnabled(!currentPlan.isEmpty());
	filterAct->setEnabled(!currentPlan.isEmpty());
	outAct->setEnabled(!currentPlan.isEmpty());
}

//открыть плана
void MainForm::openPlanActivated()
{
	OpenPlanDialog openPlanDialog(this, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
	if(openPlanDialog.exec())
	{	
		currentPlan = openPlanDialog.planComboBox->currentText();
		refreshPlanTable(currentPlan);
		enableActivatedButton();
		setCaption(tr("Контроль исполнения") + tr(" - ") + openPlanDialog.planComboBox->currentText());			//заголовок окна
	}
}

//удалить план
void MainForm::removePlanActivated()
{	
	RemovePlanDialog removePlanDialog(this, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
	if(removePlanDialog.exec())
	{
		if(currentPlan == removePlanDialog.planComboBox->currentText())
		{
			currentPlan = "";
			refreshPlanTable(currentPlan);
			enableActivatedButton();
			setCaption(tr("Контроль исполнения"));
		}
	}
}

//добавить задачу в план
void MainForm::addTopicActivated()
{
	AddTopicDialog addTopicDialog(this, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
	addTopicDialog.setIdPlan(currentPlan);
	if(addTopicDialog.exec())
		refreshPlanTable(currentPlan);
}

//редактировать тему
void MainForm::editTopicActivated()
{
	if(planTable->currentSelection() != -1)
	{
		EditTopicDialog editTopicDialog(this, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
		editTopicDialog.readEntry(planTable->text(planTable->currentRow(), 0));
		if(editTopicDialog.exec())
			this->refreshPlanTable(currentPlan);
	}
	else
		QMessageBox::information(this, tr("Информация"), tr("Выделите редактируемую тему."));
}

//удалить тему
void MainForm::removeTopicActivated()
{
	if(planTable->currentSelection() != -1)
	{
		QSqlQuery query;
		query.exec("SELECT id_topic FROM topic WHERE name_topic = '" + planTable->text(planTable->currentRow(), 0) + "'");
		query.next();
		QString idTopic = query.value(0).toString();
		query.prepare("DELETE FROM topic WHERE id_topic = '" + idTopic + "'");
		if(!query.exec())
		{
			QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка при удалении записи из базы данных."));
			//query.lastError().showMessage();
		}
		refreshPlanTable(currentPlan);
	}
	else
		QMessageBox::information(this, tr("Информация"), tr("Выделите удаляемую тему."));
}

//фильтр
void MainForm::filterActivated()
{
	if(!filterDialog)
		filterDialog = new FilterDialog(this, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
	filterDialog->setFilters(planTable, currentPlan);
	filterDialog->show();
	filterDialog->raise();
	filterDialog->setActiveWindow();
}

void MainForm::outInWordActivated()
{
	//if(md)
		//delete md;
	md = new McDocument();
	
	McDocSection *ds = new McDocSection;
	ds->columnCount = 1;
	ds->paper.pageOrientation = 1;
	ds->paper.height = MM2TWIPS(210);
	ds->paper.width = MM2TWIPS(297);
	md->insert(ds);
	
	McDocParagraph *dp = new McDocParagraph;
	dp->setText(currentPlan);
	dp->setFormat(new Fmt1("Times new", 10, 75, false, 0), 0);
	dp->setAlignment(Qt::AlignHCenter);
	ds->insert(dp);
	
	ds->insert(new McDocParagraph);		//пустая сторока
	
	McDocTable *curTable;
	McRow *curRow;
	McCell * curCell;
	
	curTable = new McDocTable;
	ds->insert(curTable);
	
	curRow = new McRow();
	curTable->rows.append(curRow);
	
	for(int col = 0; col < planTable->numCols(); col++)
	{
		curCell = new McCell();
		curRow->cells.append(curCell);
		curCell->cellWidth = MM2TWIPS(50);
		dp = new McDocParagraph;
		dp->setText(planTable->horizontalHeader()->label(col));
		dp->setFormat(new Fmt1("Times new", 10, 75, false, 0), 0);
		dp->setAlignment(Qt::AlignHCenter);
		curCell->insert(dp);
	}
		
	for(int row = 0; row < planTable->numRows(); row++)
	{
		curRow = new McRow();
		curTable->rows.append(curRow);
		for(col = 0; col < planTable->numCols(); col++)
		{
			curCell = new McCell();
			curRow->cells.append(curCell);
			curCell->cellWidth = MM2TWIPS(50);
			dp = new McDocParagraph;
			dp->setText(planTable->text(row, col));
			curCell->insert(dp);
		}
	}
	QString krtf = md->toRTF();
	QFile f1(QTime::currentTime().toString("hhmmss") + ".rtf");
	f1.open(IO_WriteOnly);
	f1.writeBlock(krtf, krtf.length());
	f1.close();
	
	QAxObject *word = new QAxObject("Word.Application", this);
	word->dynamicCall("Activate()");
	word->querySubObject("Documents")->querySubObject("Open(const QString&)", QDir::currentDirPath().replace("/", "\\\\") + "\\\\" + f1.name());
	word->dynamicCall("SetVisible(bool)", true); 
}

//справочник исполнителей
void MainForm::openReferenceExecutiveActivated()
{
	if(!referenceExecutionForm)
		referenceExecutionForm = new ReferenceExecutionForm(this, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
	referenceExecutionForm->show();
	referenceExecutionForm->raise();
	referenceExecutionForm->setActiveWindow();
}

//справочник СКБ
void MainForm::openReferenceSkbActivated()
{
	if(!referenceSkbForm)
		referenceSkbForm = new ReferenceSkbForm(this, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
	referenceSkbForm->show();
	referenceSkbForm->raise();
	referenceSkbForm->setActiveWindow();
}

//действия при закрытии
void MainForm::closeEvent(QCloseEvent *event)
{
	switch(QMessageBox::question(this, tr("Выход"), tr("Вы действительно желаете завершить работу?"), tr("Да"), tr("Нет"), QString::null, 0, 1))
	{
		case 0: writeSettings(); event->accept(); break;
		case 1: event->ignore(); break;
	}
}

//вызов контекстного меню для таблицы
void MainForm::contextMenuEvent(QContextMenuEvent *event)
{
	if(planTable->currentSelection() != -1)
	{
		QPopupMenu *contextMenu = new QPopupMenu(this);
		addTopicAct->addTo(contextMenu);
		editTopicAct->addTo(contextMenu);
		removeTopicAct->addTo(contextMenu);
		contextMenu->exec(event->globalPos());
		delete contextMenu;
	}
}