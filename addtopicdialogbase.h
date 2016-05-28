/****************************************************************************
** Form interface generated from reading ui file 'addtopicdialogbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ADDTOPICDIALOGBASE_H
#define ADDTOPICDIALOGBASE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QDateEdit;
class QLineEdit;
class QPushButton;
class QComboBox;

class AddTopicDialogBase : public QDialog
{
    Q_OBJECT

public:
    AddTopicDialogBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AddTopicDialogBase();

    QLabel* textLabel1;
    QLabel* textLabel1_2_2_2;
    QLabel* textLabel1_2_2_2_2;
    QDateEdit* dateDateEdit;
    QLineEdit* topicLineEdit;
    QLineEdit* stampLineEdit;
    QPushButton* cancelButton;
    QPushButton* addButton;
    QLabel* textLabel1_2_2;
    QComboBox* skbComboBox;
    QComboBox* executiveComboBox;
    QLabel* textLabel1_2;

protected:
    QGridLayout* AddTopicDialogBaseLayout;
    QSpacerItem* spacer1;
    QSpacerItem* spacer1_2;

protected slots:
    virtual void languageChange();

};

#endif // ADDTOPICDIALOGBASE_H
