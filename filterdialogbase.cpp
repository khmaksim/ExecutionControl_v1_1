/****************************************************************************
** Form implementation generated from reading ui file 'filterdialogbase.ui'
**
** Created: Ср 2. мар 00:04:47 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "filterdialogbase.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a FilterDialogBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FilterDialogBase::FilterDialogBase( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "FilterDialogBase" );
    FilterDialogBaseLayout = new QGridLayout( this, 1, 1, 11, 6, "FilterDialogBaseLayout"); 

    periodGroupBox = new QGroupBox( this, "periodGroupBox" );
    periodGroupBox->setCheckable( TRUE );
    periodGroupBox->setChecked( FALSE );
    periodGroupBox->setColumnLayout(0, Qt::Vertical );
    periodGroupBox->layout()->setSpacing( 6 );
    periodGroupBox->layout()->setMargin( 11 );
    periodGroupBoxLayout = new QGridLayout( periodGroupBox->layout() );
    periodGroupBoxLayout->setAlignment( Qt::AlignTop );

    textLabel1 = new QLabel( periodGroupBox, "textLabel1" );

    periodGroupBoxLayout->addWidget( textLabel1, 0, 0 );

    beginDateEdit = new QDateEdit( periodGroupBox, "beginDateEdit" );
    beginDateEdit->setDate( QDate( 2000, 1, 1 ) );

    periodGroupBoxLayout->addWidget( beginDateEdit, 0, 1 );

    textLabel1_2 = new QLabel( periodGroupBox, "textLabel1_2" );
    textLabel1_2->setAlignment( int( QLabel::AlignCenter ) );

    periodGroupBoxLayout->addWidget( textLabel1_2, 0, 2 );

    endDateEdit = new QDateEdit( periodGroupBox, "endDateEdit" );
    endDateEdit->setDate( QDate( 2000, 1, 1 ) );

    periodGroupBoxLayout->addWidget( endDateEdit, 0, 3 );

    FilterDialogBaseLayout->addWidget( periodGroupBox, 0, 0 );

    skbGroupBox = new QGroupBox( this, "skbGroupBox" );
    skbGroupBox->setCheckable( TRUE );
    skbGroupBox->setChecked( FALSE );
    skbGroupBox->setColumnLayout(0, Qt::Vertical );
    skbGroupBox->layout()->setSpacing( 6 );
    skbGroupBox->layout()->setMargin( 11 );
    skbGroupBoxLayout = new QGridLayout( skbGroupBox->layout() );
    skbGroupBoxLayout->setAlignment( Qt::AlignTop );

    skbComboBox = new QComboBox( FALSE, skbGroupBox, "skbComboBox" );

    skbGroupBoxLayout->addWidget( skbComboBox, 0, 0 );

    FilterDialogBaseLayout->addMultiCellWidget( skbGroupBox, 0, 0, 1, 3 );

    executiveGroupBox = new QGroupBox( this, "executiveGroupBox" );
    executiveGroupBox->setCheckable( TRUE );
    executiveGroupBox->setChecked( FALSE );
    executiveGroupBox->setColumnLayout(0, Qt::Vertical );
    executiveGroupBox->layout()->setSpacing( 6 );
    executiveGroupBox->layout()->setMargin( 11 );
    executiveGroupBoxLayout = new QGridLayout( executiveGroupBox->layout() );
    executiveGroupBoxLayout->setAlignment( Qt::AlignTop );

    executiveComboBox = new QComboBox( FALSE, executiveGroupBox, "executiveComboBox" );

    executiveGroupBoxLayout->addWidget( executiveComboBox, 0, 0 );

    FilterDialogBaseLayout->addMultiCellWidget( executiveGroupBox, 1, 1, 1, 3 );

    yearGroupBox = new QGroupBox( this, "yearGroupBox" );
    yearGroupBox->setCheckable( TRUE );
    yearGroupBox->setChecked( FALSE );
    yearGroupBox->setColumnLayout(0, Qt::Vertical );
    yearGroupBox->layout()->setSpacing( 6 );
    yearGroupBox->layout()->setMargin( 11 );
    yearGroupBoxLayout = new QGridLayout( yearGroupBox->layout() );
    yearGroupBoxLayout->setAlignment( Qt::AlignTop );

    yearComboBox = new QComboBox( FALSE, yearGroupBox, "yearComboBox" );

    yearGroupBoxLayout->addWidget( yearComboBox, 0, 0 );

    FilterDialogBaseLayout->addWidget( yearGroupBox, 1, 0 );

    closeButton = new QPushButton( this, "closeButton" );
    closeButton->setAutoDefault( FALSE );
    closeButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "delete_16.png" ) ) );

    FilterDialogBaseLayout->addWidget( closeButton, 2, 3 );
    spacer2 = new QSpacerItem( 240, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    FilterDialogBaseLayout->addItem( spacer2, 2, 0 );

    applyButton = new QPushButton( this, "applyButton" );
    applyButton->setDefault( TRUE );
    applyButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "tick_16.png" ) ) );

    FilterDialogBaseLayout->addWidget( applyButton, 2, 1 );

    cancelButton = new QPushButton( this, "cancelButton" );
    cancelButton->setAutoDefault( FALSE );
    cancelButton->setIconSet( QIconSet( QPixmap::fromMimeSource( "block_16.png" ) ) );

    FilterDialogBaseLayout->addWidget( cancelButton, 2, 2 );
    languageChange();
    resize( QSize(548, 178).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( closeButton, SIGNAL( clicked() ), this, SLOT( close() ) );

    // tab order
    setTabOrder( beginDateEdit, endDateEdit );
    setTabOrder( endDateEdit, yearComboBox );
    setTabOrder( yearComboBox, skbComboBox );
    setTabOrder( skbComboBox, executiveComboBox );
    setTabOrder( executiveComboBox, applyButton );
    setTabOrder( applyButton, cancelButton );
    setTabOrder( cancelButton, closeButton );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FilterDialogBase::~FilterDialogBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FilterDialogBase::languageChange()
{
    setCaption( trUtf8( "\xd0\xa4\xd0\xb8\xd0\xbb\xd1\x82\xd1\x80" ) );
    periodGroupBox->setTitle( trUtf8( "\xd0\xa1\xd1\x80\xd0\xbe\xd0\xba\xd0\xb8\x20\xd0\xb2\xd1\x8b\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb5\xd0\xbd\xd0\xb8\xd1\x8f" ) );
    textLabel1->setText( trUtf8( "\xd0\x92\x20\xd0\xbf\xd0\xb5\xd1\x80\xd0\xb8\xd0\xbe\xd0\xb4\x20\xd1\x81" ) );
    textLabel1_2->setText( trUtf8( "\xd0\xbf\xd0\xbe" ) );
    skbGroupBox->setTitle( trUtf8( "\xd0\xa1\xd0\x9a\xd0\x91" ) );
    executiveGroupBox->setTitle( trUtf8( "\xd0\x98\xd1\x81\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb8\xd1\x82\xd0\xb5\xd0\xbb\xd0\xb8" ) );
    yearGroupBox->setTitle( trUtf8( "\xd0\x93\xd0\xbe\xd0\xb4" ) );
    closeButton->setText( trUtf8( "\xd0\x97\xd0\xb0\xd0\xba\xd1\x80\xd1\x8b\xd1\x82\xd1\x8c" ) );
    applyButton->setText( trUtf8( "\xd0\x9f\xd1\x80\xd0\xb8\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb8\xd1\x82\xd1\x8c" ) );
    cancelButton->setText( trUtf8( "\xd0\x9e\xd1\x82\xd0\xbc\xd0\xb5\xd0\xbd\xd0\xb0" ) );
}

