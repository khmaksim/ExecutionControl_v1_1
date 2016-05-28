/****************************************************************************
** Form implementation generated from reading ui file 'connectdbdialogbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "connectdbdialogbase.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a ConnectDbDialogBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ConnectDbDialogBase::ConnectDbDialogBase( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ConnectDbDialogBase" );
    ConnectDbDialogBaseLayout = new QGridLayout( this, 1, 1, 11, 6, "ConnectDbDialogBaseLayout"); 

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    textLabel2_2 = new QLabel( groupBox1, "textLabel2_2" );

    groupBox1Layout->addWidget( textLabel2_2, 1, 0 );

    textLabel2 = new QLabel( groupBox1, "textLabel2" );

    groupBox1Layout->addWidget( textLabel2, 0, 0 );

    textLabel2_3 = new QLabel( groupBox1, "textLabel2_3" );

    groupBox1Layout->addWidget( textLabel2_3, 2, 0 );

    hostNameLineEdit = new QLineEdit( groupBox1, "hostNameLineEdit" );
    hostNameLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    hostNameLineEdit->setFrameShadow( QLineEdit::Sunken );

    groupBox1Layout->addWidget( hostNameLineEdit, 0, 1 );

    userNameLineEdit = new QLineEdit( groupBox1, "userNameLineEdit" );

    groupBox1Layout->addWidget( userNameLineEdit, 1, 1 );

    passwordLineEdit = new QLineEdit( groupBox1, "passwordLineEdit" );
    passwordLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    passwordLineEdit->setFrameShadow( QLineEdit::Sunken );
    passwordLineEdit->setEchoMode( QLineEdit::Password );

    groupBox1Layout->addWidget( passwordLineEdit, 2, 1 );

    saveCheckBox = new QCheckBox( groupBox1, "saveCheckBox" );

    groupBox1Layout->addWidget( saveCheckBox, 2, 2 );
    spacer31 = new QSpacerItem( 20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding );
    groupBox1Layout->addMultiCell( spacer31, 0, 1, 2, 2 );

    ConnectDbDialogBaseLayout->addMultiCellWidget( groupBox1, 0, 0, 0, 2 );

    cancelButton = new QPushButton( this, "cancelButton" );
    cancelButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "block_16.png" ) ) );

    ConnectDbDialogBaseLayout->addWidget( cancelButton, 1, 2 );

    connectButton = new QPushButton( this, "connectButton" );
    connectButton->setEnabled( FALSE );
    connectButton->setDefault( TRUE );
    connectButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "tick_16.png" ) ) );

    ConnectDbDialogBaseLayout->addWidget( connectButton, 1, 1 );
    spacer1 = new QSpacerItem( 170, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ConnectDbDialogBaseLayout->addItem( spacer1, 1, 0 );
    languageChange();
    resize( QSize(403, 149).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );

    // tab order
    setTabOrder( hostNameLineEdit, userNameLineEdit );
    setTabOrder( userNameLineEdit, passwordLineEdit );
    setTabOrder( passwordLineEdit, connectButton );
    setTabOrder( connectButton, cancelButton );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ConnectDbDialogBase::~ConnectDbDialogBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ConnectDbDialogBase::languageChange()
{
    setCaption( trUtf8( "\xd0\x9f\xd0\xbe\xd0\xb4\xd0\xba\xd0\xbb\xd1\x8e\xd1\x87\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb5\x20\xd0\xba\x20\xd0\xb1\xd0\xb0\xd0\xb7\xd0\xb5\x20\xd0\xb4\xd0\xb0\xd0\xbd\xd0\xbd\xd1\x85" ) );
    groupBox1->setTitle( QString::null );
    textLabel2_2->setText( trUtf8( "\xd0\x98\xd0\xbc\xd1\x8f\x20\xd0\xbf\xd0\xbe\xd0\xbb\xd1\x8c\xd0\xb7\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x82\xd0\xb5\xd0\xbb\xd1\x8f\x3a" ) );
    textLabel2->setText( trUtf8( "\xd0\xa5\xd0\xbe\xd1\x81\xd1\x82\x3a" ) );
    textLabel2_3->setText( trUtf8( "\xd0\x9f\xd0\xb0\xd1\x80\xd0\xbe\xd0\xbb\xd1\x8c\x3a" ) );
    saveCheckBox->setText( trUtf8( "\xd0\x97\xd0\xb0\xd0\xbf\xd0\xbe\xd0\xbc\xd0\xbd\xd0\xb8\xd1\x82\xd1\x8c\x3f" ) );
    cancelButton->setText( trUtf8( "\xd0\x9e\xd1\x82\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb0" ) );
    connectButton->setText( trUtf8( "\xd0\x9f\xd0\xbe\xd0\xb4\xd0\xba\xd0\xbb\xd1\x8e\xd1\x87\xd0\xb8\xd1\x82\xd1\x8c\xd1\x81\xd1\x8f" ) );
}

