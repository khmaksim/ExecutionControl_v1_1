/****************************************************************************
** Form implementation generated from reading ui file 'openplandialogbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "openplandialogbase.h"

#include <qvariant.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a OpenPlanDialogBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
OpenPlanDialogBase::OpenPlanDialogBase( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "OpenPlanDialogBase" );
    OpenPlanDialogBaseLayout = new QGridLayout( this, 1, 1, 11, 6, "OpenPlanDialogBaseLayout"); 

    planComboBox = new QComboBox( FALSE, this, "planComboBox" );

    OpenPlanDialogBaseLayout->addMultiCellWidget( planComboBox, 0, 0, 1, 3 );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    textLabel1->setAlignment( int( QLabel::AlignVCenter ) );

    OpenPlanDialogBaseLayout->addWidget( textLabel1, 0, 0 );

    cancelButton = new QPushButton( this, "cancelButton" );
    cancelButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "block_16.png" ) ) );

    OpenPlanDialogBaseLayout->addWidget( cancelButton, 1, 3 );

    openButton = new QPushButton( this, "openButton" );
    openButton->setEnabled( FALSE );
    openButton->setDefault( TRUE );
    openButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "tick_16.png" ) ) );

    OpenPlanDialogBaseLayout->addWidget( openButton, 1, 2 );
    spacer10 = new QSpacerItem( 340, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    OpenPlanDialogBaseLayout->addMultiCell( spacer10, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(543, 76).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( openButton, SIGNAL( clicked() ), this, SLOT( accept() ) );

    // tab order
    setTabOrder( planComboBox, openButton );
    setTabOrder( openButton, cancelButton );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OpenPlanDialogBase::~OpenPlanDialogBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OpenPlanDialogBase::languageChange()
{
    setCaption( trUtf8( "\xd0\x9e\xd1\x82\xd0\xba\xd1\x80\xd1\x8b\xd1\x82\xd1\x8c\x20\xd0\xbf\xd0\xbb\xd0\xb0\xd0\xbd" ) );
    textLabel1->setText( trUtf8( "\xd0\x92\xd1\x8b\xd0\xb1\xd0\xb5\xd1\x80\xd0\xb8\xd1\x82\xd0\xb5\x20\xd0\xbd\xd0\xb0\xd0\xb8\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd0\xb5\x20\xd0\xbf\xd0\xbb\xd0\xb0\xd0\xbd\xd0\xb0\x3a" ) );
    cancelButton->setText( trUtf8( "\xd0\x9e\xd1\x82\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb0" ) );
    openButton->setText( trUtf8( "\xd0\x92\xd1\x8b\xd0\xb1\xd1\x80\xd0\xb0\xd1\x82\xd1\x8c" ) );
}

