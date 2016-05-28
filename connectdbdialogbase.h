/****************************************************************************
** Form interface generated from reading ui file 'connectdbdialogbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONNECTDBDIALOGBASE_H
#define CONNECTDBDIALOGBASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;

class ConnectDbDialogBase : public QDialog
{
    Q_OBJECT

public:
    ConnectDbDialogBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ConnectDbDialogBase();

    QGroupBox* groupBox1;
    QLabel* textLabel2_2;
    QLabel* textLabel2;
    QLabel* textLabel2_3;
    QLineEdit* hostNameLineEdit;
    QLineEdit* userNameLineEdit;
    QLineEdit* passwordLineEdit;
    QCheckBox* saveCheckBox;
    QPushButton* cancelButton;
    QPushButton* connectButton;

protected:
    QGridLayout* ConnectDbDialogBaseLayout;
    QSpacerItem* spacer1;
    QGridLayout* groupBox1Layout;
    QSpacerItem* spacer31;

protected slots:
    virtual void languageChange();

};

#endif // CONNECTDBDIALOGBASE_H
