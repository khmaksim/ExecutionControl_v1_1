/****************************************************************************
** Form implementation generated from reading ui file 'removeplandialogbase.ui'
**
** Created: Ср 2. мар 00:04:48 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "removeplandialogbase.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a RemovePlanDialogBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RemovePlanDialogBase::RemovePlanDialogBase( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RemovePlanDialogBase" );
    RemovePlanDialogBaseLayout = new QGridLayout( this, 1, 1, 11, 6, "RemovePlanDialogBaseLayout"); 

    cancelButton = new QPushButton( this, "cancelButton" );
    cancelButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "block_16.png" ) ) );
    cancelButton->setFlat( FALSE );

    RemovePlanDialogBaseLayout->addWidget( cancelButton, 1, 3 );
    spacer10 = new QSpacerItem( 340, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    RemovePlanDialogBaseLayout->addMultiCell( spacer10, 1, 1, 0, 1 );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    textLabel1->setAlignment( int( QLabel::AlignVCenter ) );

    RemovePlanDialogBaseLayout->addWidget( textLabel1, 0, 0 );

    removeButton = new QPushButton( this, "removeButton" );
    removeButton->setEnabled( FALSE );
    removeButton->setDefault( TRUE );
    removeButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "delete_16.png" ) ) );
    removeButton->setFlat( FALSE );

    RemovePlanDialogBaseLayout->addWidget( removeButton, 1, 2 );

    planComboBox = new QComboBox( FALSE, this, "planComboBox" );

    RemovePlanDialogBaseLayout->addMultiCellWidget( planComboBox, 0, 0, 1, 3 );
    languageChange();
    resize( QSize(542, 76).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( removeButton, SIGNAL( clicked() ), this, SLOT( accept() ) );

    // tab order
    setTabOrder( planComboBox, removeButton );
    setTabOrder( removeButton, cancelButton );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RemovePlanDialogBase::~RemovePlanDialogBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RemovePlanDialogBase::languageChange()
{
    setCaption( trUtf8( "\xd0\xa3\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xb8\xd1\x82\xd1\x8c\x20\xd0\xbf\xd0\xbb\xd0\xb0\xd0\xbd" ) );
    cancelButton->setText( trUtf8( "\xd0\x9e\xd1\x82\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb0" ) );
    textLabel1->setText( trUtf8( "\xd0\x92\xd1\x8b\xd0\xb1\xd0\xb5\xd1\x80\xd0\xb8\xd1\x82\xd0\xb5\x20\xd0\xbd\xd0\xb0\xd0\xb8\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd0\xb5\x20\xd0\xbf\xd0\xbb\xd0\xb0\xd0\xbd\xd0\xb0\x3a" ) );
    removeButton->setText( trUtf8( "\xd0\xa3\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xb8\xd1\x82\xd1\x8c" ) );
}

