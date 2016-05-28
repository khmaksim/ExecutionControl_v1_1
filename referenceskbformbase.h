/****************************************************************************
** Form interface generated from reading ui file 'referenceskbformbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REFERENCESKBFORMBASE_H
#define REFERENCESKBFORMBASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QLineEdit;
class QFrame;
class QPushButton;
class QTable;

class ReferenceSkbFormBase : public QDialog
{
    Q_OBJECT

public:
    ReferenceSkbFormBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ReferenceSkbFormBase();

    QGroupBox* groupBox1;
    QLabel* textLabel1;
    QLineEdit* skbLineEdit;
    QFrame* line1;
    QPushButton* addButton;
    QPushButton* editButton;
    QGroupBox* groupBox2;
    QPushButton* removeButton;
    QTable* table;
    QFrame* line2;
    QPushButton* closeButton;

protected:
    QGridLayout* groupBox1Layout;
    QGridLayout* groupBox2Layout;
    QSpacerItem* spacer18;

protected slots:
    virtual void languageChange();

};

#endif // REFERENCESKBFORMBASE_H
