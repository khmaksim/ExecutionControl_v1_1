#include <qapplication.h>
#include <qtextcodec.h>
#include "mainform.h"
#include "connectdbdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	
	QTextCodec *codec = QTextCodec::codecForName("CP1251");
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);

	//подключение к базе данных
	ConnectDbDialog connectDbDialog(0, 0, false, Qt::WStyle_Customize | Qt::WStyle_Title);
	if(!connectDbDialog.exec())
		return 0;
		
    MainForm mainForm;
	app.setMainWidget(&mainForm);
    mainForm.show();
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
