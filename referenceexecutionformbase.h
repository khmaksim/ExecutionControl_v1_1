/****************************************************************************
** Form interface generated from reading ui file 'referenceexecutionformbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REFERENCEEXECUTIONFORMBASE_H
#define REFERENCEEXECUTIONFORMBASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QPushButton;
class QGroupBox;
class QTable;
class QFrame;
class QLineEdit;

class ReferenceExecutionFormBase : public QDialog
{
    Q_OBJECT

public:
    ReferenceExecutionFormBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ReferenceExecutionFormBase();

    QLabel* textLabel;
    QPushButton* closeButton;
    QGroupBox* groupBox2;
    QPushButton* removeButton;
    QTable* table;
    QFrame* line2;
    QGroupBox* groupBox1;
    QLabel* textLabel1_2_2;
    QLabel* textLabel1;
    QLineEdit* surnameLineEdit;
    QLabel* textLabel1_3;
    QLabel* textLabel1_3_2;
    QLabel* textLabel1_2;
    QLineEdit* nameLineEdit;
    QLineEdit* patronymicLineEdit;
    QLineEdit* phoneLineEdit;
    QLineEdit* cabinetLineEdit;
    QFrame* line1;
    QPushButton* addButton;
    QPushButton* editButton;

protected:
    QGridLayout* ReferenceExecutionFormBaseLayout;
    QSpacerItem* spacer17;
    QGridLayout* groupBox2Layout;
    QSpacerItem* spacer18;
    QGridLayout* groupBox1Layout;

protected slots:
    virtual void languageChange();

};

#endif // REFERENCEEXECUTIONFORMBASE_H
