/****************************************************************************
** Form implementation generated from reading ui file 'referenceskbformbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "referenceskbformbase.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qframe.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a ReferenceSkbFormBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ReferenceSkbFormBase::ReferenceSkbFormBase( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ReferenceSkbFormBase" );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setGeometry( QRect( 10, 230, 588, 90 ) );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    textLabel1 = new QLabel( groupBox1, "textLabel1" );

    groupBox1Layout->addWidget( textLabel1, 0, 0 );

    skbLineEdit = new QLineEdit( groupBox1, "skbLineEdit" );
    skbLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    skbLineEdit->setFrameShadow( QLineEdit::Sunken );

    groupBox1Layout->addWidget( skbLineEdit, 0, 1 );

    line1 = new QFrame( groupBox1, "line1" );
    line1->setFrameShape( QFrame::VLine );
    line1->setFrameShadow( QFrame::Sunken );
    line1->setFrameShape( QFrame::VLine );

    groupBox1Layout->addMultiCellWidget( line1, 0, 2, 4, 4 );

    addButton = new QPushButton( groupBox1, "addButton" );
    addButton->setEnabled( FALSE );
    addButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "plus_16.png" ) ) );

    groupBox1Layout->addWidget( addButton, 0, 5 );

    editButton = new QPushButton( groupBox1, "editButton" );
    editButton->setEnabled( FALSE );
    editButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "pencil_16.png" ) ) );

    groupBox1Layout->addWidget( editButton, 1, 5 );

    groupBox2 = new QGroupBox( this, "groupBox2" );
    groupBox2->setGeometry( QRect( 10, 10, 588, 209 ) );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    removeButton = new QPushButton( groupBox2, "removeButton" );
    removeButton->setEnabled( FALSE );
    removeButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "delete_16.png" ) ) );

    groupBox2Layout->addWidget( removeButton, 0, 2 );
    spacer18 = new QSpacerItem( 20, 150, QSizePolicy::Minimum, QSizePolicy::Expanding );
    groupBox2Layout->addItem( spacer18, 1, 2 );

    table = new QTable( groupBox2, "table" );
    table->setNumCols( table->numCols() + 1 );
    table->horizontalHeader()->setLabel( table->numCols() - 1, trUtf8( "\xd0\x9d\xd0\xb0\xd0\xb8\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd0\xb5\x20\xd0\xa1\xd0\x9a\xd0\x91" ) );
    table->setNumCols( table->numCols() + 1 );
    table->horizontalHeader()->setLabel( table->numCols() - 1, tr( "id" ) );
    table->setNumRows( 0 );
    table->setNumCols( 2 );
    table->setReadOnly( TRUE );
    table->setSelectionMode( QTable::SingleRow );
    table->setFocusStyle( QTable::FollowStyle );

    groupBox2Layout->addMultiCellWidget( table, 0, 1, 0, 0 );

    line2 = new QFrame( groupBox2, "line2" );
    line2->setFrameShape( QFrame::VLine );
    line2->setFrameShadow( QFrame::Sunken );
    line2->setFrameShape( QFrame::VLine );

    groupBox2Layout->addMultiCellWidget( line2, 0, 1, 1, 1 );

    closeButton = new QPushButton( this, "closeButton" );
    closeButton->setGeometry( QRect( 516, 326, 82, 28 ) );
    closeButton->setDefault( TRUE );
    closeButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "delete_16.png" ) ) );
    languageChange();
    resize( QSize(608, 374).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( closeButton, SIGNAL( clicked() ), this, SLOT( close() ) );

    // tab order
    setTabOrder( table, removeButton );
    setTabOrder( removeButton, skbLineEdit );
    setTabOrder( skbLineEdit, addButton );
    setTabOrder( addButton, editButton );
    setTabOrder( editButton, closeButton );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReferenceSkbFormBase::~ReferenceSkbFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReferenceSkbFormBase::languageChange()
{
    setCaption( trUtf8( "\xd0\xa1\xd0\xbf\xd1\x80\xd0\xb0\xd0\xb2\xd0\xbe\xd1\x87\xd0\xbd\xd0\xb8\xd0\xba\x20\xd0\xa1\xd0\x9a\xd0\x91" ) );
    groupBox1->setTitle( QString::null );
    textLabel1->setText( trUtf8( "\xd0\x9d\xd0\xb0\xd0\xb8\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd0\xb5\x20\xd0\xa1\xd0\x9a\xd0\x91\x3a" ) );
    addButton->setText( trUtf8( "\xd0\x94\xd0\xbe\xd0\xb1\xd0\xb0\xd0\xb2\xd0\xb8\xd1\x82\xd1\x8c" ) );
    editButton->setText( trUtf8( "\xd0\xa0\xd0\xb5\xd0\xb4\xd0\xb0\xd0\xba\xd1\x82\xd0\xb8\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x82\xd1\x8c" ) );
    groupBox2->setTitle( QString::null );
    removeButton->setText( trUtf8( "\xd0\xa3\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xb8\xd1\x82\xd1\x8c" ) );
    table->horizontalHeader()->setLabel( 0, trUtf8( "\xd0\x9d\xd0\xb0\xd0\xb8\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd0\xb5\x20\xd0\xa1\xd0\x9a\xd0\x91" ) );
    table->horizontalHeader()->setLabel( 1, tr( "id" ) );
    closeButton->setText( trUtf8( "\xd0\x97\xd0\xb0\xd0\xba\xd1\x80\xd1\x8b\xd1\x82\xd1\x8c" ) );
}

