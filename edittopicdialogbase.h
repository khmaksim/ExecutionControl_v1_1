/****************************************************************************
** Form interface generated from reading ui file 'edittopicdialogbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EDITTOPICDIALOGBASE_H
#define EDITTOPICDIALOGBASE_H

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

class EditTopicDialogBase : public QDialog
{
    Q_OBJECT

public:
    EditTopicDialogBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~EditTopicDialogBase();

    QLabel* textLabel1;
    QLabel* textLabel1_2_2_2;
    QLabel* textLabel1_2_2_2_2;
    QDateEdit* dateDateEdit;
    QLineEdit* topicLineEdit;
    QLineEdit* stampLineEdit;
    QPushButton* cancelButton;
    QPushButton* editButton;
    QLabel* textLabel1_2;
    QComboBox* executiveComboBox;
    QComboBox* skbComboBox;
    QLabel* textLabel1_2_2;

protected:
    QGridLayout* EditTopicDialogBaseLayout;
    QSpacerItem* spacer1;
    QSpacerItem* spacer1_2;

protected slots:
    virtual void languageChange();

};

#endif // EDITTOPICDIALOGBASE_H
