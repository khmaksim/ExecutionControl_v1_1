/****************************************************************************
** Form interface generated from reading ui file 'filterdialogbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FILTERDIALOGBASE_H
#define FILTERDIALOGBASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QDateEdit;
class QComboBox;
class QPushButton;

class FilterDialogBase : public QDialog
{
    Q_OBJECT

public:
    FilterDialogBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FilterDialogBase();

    QGroupBox* periodGroupBox;
    QLabel* textLabel1;
    QDateEdit* beginDateEdit;
    QLabel* textLabel1_2;
    QDateEdit* endDateEdit;
    QGroupBox* skbGroupBox;
    QComboBox* skbComboBox;
    QGroupBox* executiveGroupBox;
    QComboBox* executiveComboBox;
    QGroupBox* yearGroupBox;
    QComboBox* yearComboBox;
    QPushButton* closeButton;
    QPushButton* applyButton;
    QPushButton* cancelButton;

protected:
    QGridLayout* FilterDialogBaseLayout;
    QSpacerItem* spacer2;
    QGridLayout* periodGroupBoxLayout;
    QGridLayout* skbGroupBoxLayout;
    QGridLayout* executiveGroupBoxLayout;
    QGridLayout* yearGroupBoxLayout;

protected slots:
    virtual void languageChange();

};

#endif // FILTERDIALOGBASE_H
