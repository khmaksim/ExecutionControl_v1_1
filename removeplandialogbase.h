/****************************************************************************
** Form interface generated from reading ui file 'removeplandialogbase.ui'
**
** Created: Ср 2. мар 00:04:48 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REMOVEPLANDIALOGBASE_H
#define REMOVEPLANDIALOGBASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QComboBox;

class RemovePlanDialogBase : public QDialog
{
    Q_OBJECT

public:
    RemovePlanDialogBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RemovePlanDialogBase();

    QPushButton* cancelButton;
    QLabel* textLabel1;
    QPushButton* removeButton;
    QComboBox* planComboBox;

protected:
    QGridLayout* RemovePlanDialogBaseLayout;
    QSpacerItem* spacer10;

protected slots:
    virtual void languageChange();

};

#endif // REMOVEPLANDIALOGBASE_H
