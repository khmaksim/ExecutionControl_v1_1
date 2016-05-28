/****************************************************************************
** Form interface generated from reading ui file 'openplandialogbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef OPENPLANDIALOGBASE_H
#define OPENPLANDIALOGBASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QComboBox;
class QLabel;
class QPushButton;

class OpenPlanDialogBase : public QDialog
{
    Q_OBJECT

public:
    OpenPlanDialogBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~OpenPlanDialogBase();

    QComboBox* planComboBox;
    QLabel* textLabel1;
    QPushButton* cancelButton;
    QPushButton* openButton;

protected:
    QGridLayout* OpenPlanDialogBaseLayout;
    QSpacerItem* spacer10;

protected slots:
    virtual void languageChange();

};

#endif // OPENPLANDIALOGBASE_H
