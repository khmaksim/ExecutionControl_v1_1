/****************************************************************************
** Form implementation generated from reading ui file 'referenceexecutionformbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "referenceexecutionformbase.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qgroupbox.h>
#include <qtable.h>
#include <qframe.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a ReferenceExecutionFormBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ReferenceExecutionFormBase::ReferenceExecutionFormBase( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ReferenceExecutionFormBase" );
    ReferenceExecutionFormBaseLayout = new QGridLayout( this, 1, 1, 11, 6, "ReferenceExecutionFormBaseLayout"); 

    textLabel = new QLabel( this, "textLabel" );

    ReferenceExecutionFormBaseLayout->addWidget( textLabel, 0, 2 );

    closeButton = new QPushButton( this, "closeButton" );
    closeButton->setDefault( TRUE );
    closeButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "delete_16.png" ) ) );

    ReferenceExecutionFormBaseLayout->addWidget( closeButton, 2, 1 );
    spacer17 = new QSpacerItem( 490, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ReferenceExecutionFormBaseLayout->addItem( spacer17, 2, 0 );

    groupBox2 = new QGroupBox( this, "groupBox2" );
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
    table->horizontalHeader()->setLabel( table->numCols() - 1, trUtf8( "\xd0\xa4\xd0\xb0\xd0\xbc\xd0\xb8\xd0\xbb\xd0\xb8\xd1\x8f" ) );
    table->setNumCols( table->numCols() + 1 );
    table->horizontalHeader()->setLabel( table->numCols() - 1, trUtf8( "\xd0\x98\xd0\xbc\xd1\x8f" ) );
    table->setNumCols( table->numCols() + 1 );
    table->horizontalHeader()->setLabel( table->numCols() - 1, trUtf8( "\xd0\x9e\xd1\x82\xd1\x87\xd0\xb5\xd1\x81\xd1\x82\xd0\xb2\xd0\xbe" ) );
    table->setNumCols( table->numCols() + 1 );
    table->horizontalHeader()->setLabel( table->numCols() - 1, trUtf8( "\xd0\xa2\xd0\xb5\xd0\xbb\xd0\xb5\xd1\x84\xd0\xbe\xd0\xbd" ) );
    table->setNumCols( table->numCols() + 1 );
    table->horizontalHeader()->setLabel( table->numCols() - 1, trUtf8( "\xd0\x9a\xd0\xb0\xd0\xb1\xd0\xb8\xd0\xbd\xd0\xb5\xd1\x82" ) );
    table->setNumCols( table->numCols() + 1 );
    table->horizontalHeader()->setLabel( table->numCols() - 1, tr( "id" ) );
    table->setNumRows( 0 );
    table->setNumCols( 6 );
    table->setReadOnly( TRUE );
    table->setSelectionMode( QTable::SingleRow );
    table->setFocusStyle( QTable::FollowStyle );

    groupBox2Layout->addMultiCellWidget( table, 0, 1, 0, 0 );

    line2 = new QFrame( groupBox2, "line2" );
    line2->setFrameShape( QFrame::VLine );
    line2->setFrameShadow( QFrame::Sunken );
    line2->setFrameShape( QFrame::VLine );

    groupBox2Layout->addMultiCellWidget( line2, 0, 1, 1, 1 );

    ReferenceExecutionFormBaseLayout->addMultiCellWidget( groupBox2, 0, 0, 0, 1 );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    textLabel1_2_2 = new QLabel( groupBox1, "textLabel1_2_2" );

    groupBox1Layout->addWidget( textLabel1_2_2, 2, 0 );

    textLabel1 = new QLabel( groupBox1, "textLabel1" );

    groupBox1Layout->addWidget( textLabel1, 0, 0 );

    surnameLineEdit = new QLineEdit( groupBox1, "surnameLineEdit" );
    surnameLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    surnameLineEdit->setFrameShadow( QLineEdit::Sunken );

    groupBox1Layout->addWidget( surnameLineEdit, 0, 1 );

    textLabel1_3 = new QLabel( groupBox1, "textLabel1_3" );

    groupBox1Layout->addWidget( textLabel1_3, 0, 2 );

    textLabel1_3_2 = new QLabel( groupBox1, "textLabel1_3_2" );

    groupBox1Layout->addWidget( textLabel1_3_2, 1, 2 );

    textLabel1_2 = new QLabel( groupBox1, "textLabel1_2" );

    groupBox1Layout->addWidget( textLabel1_2, 1, 0 );

    nameLineEdit = new QLineEdit( groupBox1, "nameLineEdit" );
    nameLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    nameLineEdit->setFrameShadow( QLineEdit::Sunken );

    groupBox1Layout->addWidget( nameLineEdit, 1, 1 );

    patronymicLineEdit = new QLineEdit( groupBox1, "patronymicLineEdit" );
    patronymicLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    patronymicLineEdit->setFrameShadow( QLineEdit::Sunken );

    groupBox1Layout->addWidget( patronymicLineEdit, 2, 1 );

    phoneLineEdit = new QLineEdit( groupBox1, "phoneLineEdit" );
    phoneLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    phoneLineEdit->setFrameShadow( QLineEdit::Sunken );

    groupBox1Layout->addWidget( phoneLineEdit, 0, 3 );

    cabinetLineEdit = new QLineEdit( groupBox1, "cabinetLineEdit" );
    cabinetLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    cabinetLineEdit->setFrameShadow( QLineEdit::Sunken );

    groupBox1Layout->addWidget( cabinetLineEdit, 1, 3 );

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

    ReferenceExecutionFormBaseLayout->addMultiCellWidget( groupBox1, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(607, 375).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( closeButton, SIGNAL( clicked() ), this, SLOT( close() ) );

    // tab order
    setTabOrder( table, removeButton );
    setTabOrder( removeButton, surnameLineEdit );
    setTabOrder( surnameLineEdit, nameLineEdit );
    setTabOrder( nameLineEdit, patronymicLineEdit );
    setTabOrder( patronymicLineEdit, phoneLineEdit );
    setTabOrder( phoneLineEdit, cabinetLineEdit );
    setTabOrder( cabinetLineEdit, addButton );
    setTabOrder( addButton, editButton );
    setTabOrder( editButton, closeButton );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReferenceExecutionFormBase::~ReferenceExecutionFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReferenceExecutionFormBase::languageChange()
{
    setCaption( trUtf8( "\xd0\xa1\xd0\xbf\xd1\x80\xd0\xb0\xd0\xb2\xd0\xbe\xd1\x87\xd0\xbd\xd0\xb8\xd0\xba\x20\xd0\xb8\xd1\x81\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb8\xd1\x82\xd0\xb5\xd0\xbb\xd0\xb5\xd0\xb9" ) );
    textLabel->setText( QString::null );
    closeButton->setText( trUtf8( "\xd0\x97\xd0\xb0\xd0\xba\xd1\x80\xd1\x8b\xd1\x82\xd1\x8c" ) );
    groupBox2->setTitle( QString::null );
    removeButton->setText( trUtf8( "\xd0\xa3\xd0\xb4\xd0\xb0\xd0\xbb\xd0\xb8\xd1\x82\xd1\x8c" ) );
    table->horizontalHeader()->setLabel( 0, trUtf8( "\xd0\xa4\xd0\xb0\xd0\xbc\xd0\xb8\xd0\xbb\xd0\xb8\xd1\x8f" ) );
    table->horizontalHeader()->setLabel( 1, trUtf8( "\xd0\x98\xd0\xbc\xd1\x8f" ) );
    table->horizontalHeader()->setLabel( 2, trUtf8( "\xd0\x9e\xd1\x82\xd1\x87\xd0\xb5\xd1\x81\xd1\x82\xd0\xb2\xd0\xbe" ) );
    table->horizontalHeader()->setLabel( 3, trUtf8( "\xd0\xa2\xd0\xb5\xd0\xbb\xd0\xb5\xd1\x84\xd0\xbe\xd0\xbd" ) );
    table->horizontalHeader()->setLabel( 4, trUtf8( "\xd0\x9a\xd0\xb0\xd0\xb1\xd0\xb8\xd0\xbd\xd0\xb5\xd1\x82" ) );
    table->horizontalHeader()->setLabel( 5, tr( "id" ) );
    groupBox1->setTitle( QString::null );
    textLabel1_2_2->setText( trUtf8( "\xd0\x9e\xd1\x82\xd1\x87\xd0\xb5\xd1\x81\xd1\x82\xd0\xb2\xd0\xbe\x3a" ) );
    textLabel1->setText( trUtf8( "\xd0\xa4\xd0\xb0\xd0\xbc\xd0\xb8\xd0\xbb\xd0\xb8\xd1\x8f\x3a" ) );
    textLabel1_3->setText( trUtf8( "\xd0\xa2\xd0\xb5\xd0\xbb\xd0\xb5\xd1\x84\xd0\xbe\xd0\xbd\x3a" ) );
    textLabel1_3_2->setText( trUtf8( "\xd0\x9a\xd0\xb0\xd0\xb1\xd0\xb8\xd0\xbd\xd0\xb5\xd1\x82\x3a" ) );
    textLabel1_2->setText( trUtf8( "\xd0\x98\xd0\xbc\xd1\x8f\x3a" ) );
    addButton->setText( trUtf8( "\xd0\x94\xd0\xbe\xd0\xb1\xd0\xb0\xd0\xb2\xd0\xb8\xd1\x82\xd1\x8c" ) );
    editButton->setText( trUtf8( "\xd0\xa0\xd0\xb5\xd0\xb4\xd0\xb0\xd0\xba\xd1\x82\xd0\xb8\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x82\xd1\x8c" ) );
}

