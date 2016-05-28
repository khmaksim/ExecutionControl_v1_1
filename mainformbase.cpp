/****************************************************************************
** Form implementation generated from reading ui file 'mainformbase.ui'
**
** Created: Ср 2. мар 00:04:48 2011
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "mainformbase.h"

#include <qvariant.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a MainFormBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
MainFormBase::MainFormBase( QWidget* parent, const char* name, WFlags fl )
    : QMainWindow( parent, name, fl )
{
    (void)statusBar();
    if ( !name )
	setName( "MainFormBase" );
    setCentralWidget( new QWidget( this, "qt_central_widget" ) );
    MainFormBaseLayout = new QGridLayout( centralWidget(), 1, 1, 11, 6, "MainFormBaseLayout"); 

    planTable = new QTable( centralWidget(), "planTable" );
    planTable->setNumCols( planTable->numCols() + 1 );
    planTable->horizontalHeader()->setLabel( planTable->numCols() - 1, trUtf8( "\xd0\xa2\xd0\xb5\xd0\xbc\xd0\xb0" ) );
    planTable->setNumCols( planTable->numCols() + 1 );
    planTable->horizontalHeader()->setLabel( planTable->numCols() - 1, trUtf8( "\xd0\xa1\xd0\x9a\xd0\x91" ) );
    planTable->setNumCols( planTable->numCols() + 1 );
    planTable->horizontalHeader()->setLabel( planTable->numCols() - 1, trUtf8( "\xd0\x98\xd1\x81\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb8\xd1\x82\xd0\xb5\xd0\xbb\xd1\x8c" ) );
    planTable->setNumCols( planTable->numCols() + 1 );
    planTable->horizontalHeader()->setLabel( planTable->numCols() - 1, trUtf8( "\xd0\xa1\xd1\x80\xd0\xbe\xd0\xba\x20\xd0\xb2\xd1\x8b\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb5\xd0\xbd\xd0\xb8\xd1\x8f" ) );
    planTable->setNumCols( planTable->numCols() + 1 );
    planTable->horizontalHeader()->setLabel( planTable->numCols() - 1, trUtf8( "\xd0\x9e\xd1\x82\xd0\xbc\xd0\xb5\xd1\x82\xd0\xba\xd0\xb0\x20\xd0\xbe\xd0\xb1\x20\xd0\xb8\xd1\x81\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb8" ) );
    planTable->setNumRows( 0 );
    planTable->setNumCols( 5 );
    planTable->setReadOnly( TRUE );
    planTable->setSelectionMode( QTable::SingleRow );
    planTable->setFocusStyle( QTable::FollowStyle );

    MainFormBaseLayout->addWidget( planTable, 0, 0 );

    // toolbars

    languageChange();
    resize( QSize(638, 363).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MainFormBase::~MainFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MainFormBase::languageChange()
{
    setCaption( tr( "Form1" ) );
    planTable->horizontalHeader()->setLabel( 0, trUtf8( "\xd0\xa2\xd0\xb5\xd0\xbc\xd0\xb0" ) );
    planTable->horizontalHeader()->setLabel( 1, trUtf8( "\xd0\xa1\xd0\x9a\xd0\x91" ) );
    planTable->horizontalHeader()->setLabel( 2, trUtf8( "\xd0\x98\xd1\x81\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb8\xd1\x82\xd0\xb5\xd0\xbb\xd1\x8c" ) );
    planTable->horizontalHeader()->setLabel( 3, trUtf8( "\xd0\xa1\xd1\x80\xd0\xbe\xd0\xba\x20\xd0\xb2\xd1\x8b\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb5\xd0\xbd\xd0\xb8\xd1\x8f" ) );
    planTable->horizontalHeader()->setLabel( 4, trUtf8( "\xd0\x9e\xd1\x82\xd0\xbc\xd0\xb5\xd1\x82\xd0\xba\xd0\xb0\x20\xd0\xbe\xd0\xb1\x20\xd0\xb8\xd1\x81\xd0\xbf\xd0\xbe\xd0\xbb\xd0\xbd\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb8" ) );
}

