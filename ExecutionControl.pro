TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release consol

LIBS	+= -lqaxcontainer

HEADERS	+= mainform.h \
	newplandialog.h \
	removeplandialog.h \
	addtopicdialog.h \
	edittopicdialog.h \
	referenceexecutionform.h \
	referenceskbform.h \
	openplandialog.h \
	connectdbdialog.h \
	mcdocument.h \
	filterdialog.h

SOURCES	+= main.cpp \
	mainform.cpp \
	newplandialog.cpp \
	removeplandialog.cpp \
	addtopicdialog.cpp \
	edittopicdialog.cpp \
	referenceexecutionform.cpp \
	referenceskbform.cpp \
	openplandialog.cpp \
	connectdbdialog.cpp \
	mcdocument.cpp \
	filterdialog.cpp

FORMS	= mainformbase.ui \
	newplandialogbase.ui \
	removeplandialogbase.ui \
	addtopicdialogbase.ui \
	edittopicdialogbase.ui \
	referenceexecutionformbase.ui \
	openplandialogbase.ui \
	referenceskbformbase.ui \
	connectdbdialogbase.ui \
	filterdialogbase.ui

IMAGES	= images/block_16.png \
	images/tick_16.png \
	images/delete_16.png \
	images/plus_16.png \
	images/pencil_16.png \
	images/document_16.png \
	images/user_16.png \
	images/gear_16.png \
	images/folder_16.png \
	images/office_16.png \
	images/shutdown_16.png \
	images/funnel_16.png

RC_FILE = ExecutionControl.rc
	
	

