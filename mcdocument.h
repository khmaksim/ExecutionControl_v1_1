/****************************************************************************
**
** Definition of McDocument class
**
** Created : 12.11.2003
**
** Copyright (C) 2003 Makarenko.  All rights reserved.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
**********************************************************************/

#ifndef MCDOCUMENT_H
#define MCDOCUMENT_H

#include <iostream.h>
#include <qstring.h>
#include <qptrlist.h>
#include <qtextstream.h>
#include <qmemarray.h>
#include <qpoint.h>
#include <qrect.h>
#include <qshared.h>
#include <qfont.h>
#include <qfontmetrics.h>
#include <math.h>
#include <qimage.h>

class QPainter;
class QDomElement;
class McConfigFile;

//#define PRINTRECT( str, r )   cout << QString(str).local8Bit() << QString(" : x=%1, y=%2, w=%3, h=%4").arg(r.x()).arg(r.y()).arg( r.width() ).arg(r.height()) << (r.isValid() ? " Valid !" : " InValid !!!") << endl
#define PRINTRECT( str, r ) qDebug("%s : x=%d, y=%d, w=%d, h=%d (%s)", (const char*)QString(str).local8Bit(), r.x(), r.y(), r.width(), r.height(), (r.isValid() ? " Valid !" : " InValid !!!"))
#define MM2TWIPS( mm ) ceil((mm)*144/2.54)
#ifdef Q_WS_WIN
#define TWIPS2MM( twips ) floor(((double)(twips))*2.54/14.4+0.5)/10
#define TWIPS2PIXELS( twips, dpi ) floor(((double)(twips))*dpi/1440+0.5)
#elif Q_WS_X11
#define TWIPS2MM( twips ) rint( ((double)(twips)) * 2.54 / 14.4 )/10
#define TWIPS2PIXELS( twips, dpi ) rint( ((double)(twips)) * dpi / 1440 )
#endif

typedef QValueList<QRgb> ColorList;
typedef QValueList<QString> FontList;

class McDocElement {
    public:
    enum Type { deParagraph, deTable, deShape, dePicture, deUnknown };
    McDocElement() {};
    virtual ~McDocElement() {};
    virtual uint type() const=0;
    virtual McDocElement * copy() { cout << "McDocElement: copy ! " << endl; return 0; };
    virtual QString toRTF(const FontList & fl, const ColorList & cl)=0;
    virtual QString toXML( unsigned char level = 0 )=0;
    virtual void setFromXML( QDomElement & e )=0;
    virtual void saveToXML( QDomElement & e )=0;
};

class Fmt1
{
    public:
//	enum {italic=1; subscript=4; superscript=6; };
    Fmt1( const QString & fnt = "Times", int size = 14, int weight = QFont::Normal, bool italic = false, int clr = 0, int bclr = 0xffffff );
    Fmt1( const QFont & fnt, int clr = 0, int bclr = 0xffffff );
    Fmt1( const Fmt1 & other );

	QString toRtfOn(const FontList & fl, const ColorList & cl);
	QString toRtfOff(const FontList & fl, const ColorList & cl);
	QString toRtfDiff(const Fmt1 & nextFormat, const FontList & fl, const ColorList & cl);

    QString font;
    int size;	// unsigned short
    int color;
    int backColor;
    int weight; // uchar
	unsigned short scale;
	unsigned short expansion;
    uint italic : 1;
    uint underline : 1;
    Fmt1 & operator= ( const Fmt1 & f );
//    bool operator== ( const Fmt1 & f );
};

class Fmt1ListEntry : public Fmt1 {
    public:
    Fmt1ListEntry();
    Fmt1ListEntry( const Fmt1 & format );
    ~Fmt1ListEntry() { if ( next ) delete next; };
    void movePos( int count ) { pos += count; if ( next ) next->movePos( count ); };
    Fmt1ListEntry * prev, * next;
    int pos;
    Fmt1ListEntry & operator= ( const Fmt1 & f ); 
};

class McDocPicture : public McDocElement
{
public:
	McDocPicture();
    QString 	toRTF(const FontList & fl, const ColorList & cl);
    QString 	toXML( unsigned char level = 0 ) { return QString(); };
    virtual void setFromXML( QDomElement & e ) {};
    virtual void saveToXML( QDomElement & e ) {};
	QImage img;
    virtual uint type() const { return deUnknown; };
	bool saveAsJPG;
	QRect rect;
};

class McDocShape : public McDocElement
{
public:
	McDocShape();
    QString 	toRTF(const FontList & fl, const ColorList & cl);
    QString 	toXML( unsigned char level = 0 ) { return QString(); };
    virtual void setFromXML( QDomElement & e ) {};
    virtual void saveToXML( QDomElement & e ) {};
	int shapeType;
    virtual uint type() const { return deUnknown; };
	QRect rect;
	bool behindText;
	int zPos;
};

//class McDP
class McDocParagraph : public McDocElement
{
    public:
    McDocParagraph();
    McDocParagraph( McDocParagraph & other );
    virtual ~McDocParagraph();
    void detach();
    virtual uint type() const;
    McDocElement * copy();
    const QString & text() const { return pd->text; };
    void setText( const QString & txt ) { pd->text = txt; pd->changed = true; };
    const uint alignment() const { return pd->alignment; };
    virtual void setAlignment( uint flags );
    float interval() const { return pd->interval; };
    virtual void setInterval( float i );
    inline const int firstIndent() const { return pd->indents[ 0 ]; };
    inline const int leftIndent() const { return pd->indents[ 1 ]; };
    inline const int rightIndent() const { return pd->indents[ 2 ]; };
    inline const int firstIndentMM() const { return pd->indents[ 0 ] * 2.54 / 144; };
    inline const int leftIndentMM() const { return pd->indents[ 1 ] * 2.54 / 144; };
    inline const int rightIndentMM() const { return pd->indents[ 2 ] * 2.54 / 144; };
    virtual void setIndents( int fi, int li, int ri );
    inline void setIndentsMM( int fi, int li, int ri );
    void setFormat( Fmt1 * format, int pos=0, int length=-1 );
    void setFormat( const Fmt1 & format);//, int pos=0, int length=-1 );
    Fmt1ListEntry * format( int pos ) const;
    bool changed() const { return pd->changed; };
    virtual void merge( McDocParagraph * other );
    virtual void setFromXML( QDomElement & e );
    virtual void saveToXML( QDomElement & e );
	void setInCell(bool inCell) { pd->inCell = inCell; };
    
    QString 	toRTF(const FontList & fl, const ColorList & cl);
    QString 	toXML( unsigned char level = 0 );
    void 		append( const QString & text, const QFont & font );
//    virtual void 	append( const McDocParagraph * other );
    void 		insert( uint idx, const QString & text );
    void 		remove( uint idx, uint len = 1 );
    
    protected:
    struct SharedParagraphData : public QShared
    {
	SharedParagraphData();
	SharedParagraphData( SharedParagraphData & other );
	~SharedParagraphData();
	QString text;
	Fmt1ListEntry * format;
	int indents[ 3 ];
	int iFirst, iLeft, iRight;
	bool inCell;
	bool changed;
	uint alignment;
	float interval;
	float spaceBefore, space, spaceAfter, spaceMul;
	bool newPage;
    } * pd;
};

class MyClass {
    protected:
    QString str;
    
    public:
    MyClass(){ str = "My Class String !"; };
//    QDataStream & operator<< ( QDataStream & s, const QString & str );
//    QTextStream & operator<< ( QTextStream & s, const MyClass & mc ) { s << "MyClass" ; return s; };
    QTextStream & operator<< ( QTextStream & s ) { s << "MyClass" ; return s; };
    ostream & operator<< ( ostream & s ) { s << "MyClass" ; return s; };
};

struct FormatEntry {
    int 		position;
    QString 	fontName;
    unsigned char  fontSize;
    uint		bold : 1;
    uint 		italic	: 1;
    uint		strikeout	: 1;
    uint 		underlined	: 1;
    uint 		subsuper		: 2;
    uint 		color : 24;
};

enum BorderShape { bsNone, bsSingle, bsDouble, bsTriple, bsWavy, bsEngrave };
enum BorderPos { bpLeft, bpTop, bpRight, bpBottom };
enum CellMerge { cmNone, cmDown, cmUp };
struct Border {
    Border() : shape( bsSingle ), width( 1 ) {};
    BorderShape	shape;
    int		width;
};
//typedef Borders Border[ 4 ];

class McCell /*: public McDocElement */{
    public:
    McCell();
//    McCell( McCell & other );
    virtual ~McCell();
    Border 	borders[4];
    CellMerge 	merge;
    uint 		vertAlign;
    uint 		cellWidth;
//    uint 		cellWidthV;
	QRgb	fillColor;
    void 	insert( McDocParagraph * par );
// from element
//    virtual uint type() const { return deCell; };
    virtual McCell * copy();
    virtual QString toRTF() { return QString( "RTF of CELL" ); };
    virtual QString toXML( unsigned char level = 0 );
    virtual void setFromXML( QDomElement & e );
    virtual void saveToXML( QDomElement & e );
//    
    
//    protected:
    QPtrList<McDocParagraph> 	paragraphs;
};

class McRow {
    public:
    McRow();
    virtual ~McRow();
    McRow * copy();
    const uint alignment() const { return align; };
    void setAlignment( const uint flags ) { align = flags; };
    const int indent() const { return leftIndent; };
    void setIndent( const int ind ) { leftIndent = ind; };
    virtual QString toXML( unsigned char level = 0 );
//    protected:
	bool isHeader;
    int leftIndent;
    uint align;
    QPtrList<McCell> 	cells;
};

class McDocTable : public McDocElement {
    public:
    McDocTable();
    ~McDocTable();
    QString 	toRTF();
    virtual uint type() const;
    virtual QString toXML( unsigned char level = 0 );
    virtual void setFromXML( QDomElement & e );
    virtual void saveToXML( QDomElement & e );
    virtual McDocElement * copy();
    QString 	toRTF(const FontList & fl, const ColorList & cl);
    
//    protected:
    QPtrList<McRow> 	rows;
};

class McDocSection;
class McDocFragment {
    public:
//    McDocFragment();
//    McDocFragment( const McDocFragment & fragment );
    McDocFragment & operator=( const McDocFragment & fragment );
    QPtrList<McDocElement> elements;
    QPtrList<McDocSection> sections;
    bool isEmpty() const { return elements.isEmpty(); };
    virtual QString toRTF(){ return QString();};
    virtual QString toXML( unsigned char level = 0 );
    void replace( const QString & s1, const QString & s2 );
    virtual void setFromXML( QDomElement & e );
    virtual void saveToXML( QDomElement & e );
    virtual void append( McDocElement * e );
    virtual void append( McDocSection * s );
};

class McRepCond : public McDocFragment {
    public:
    QString condition;
    
    virtual void setFromXML( QDomElement & e );
};

class McDocSection {
    public:
    McDocSection();
    struct PaperProperties {
	int 	width, height;
	int 	marginL, marginR, marginT, marginB;
	int 	pageOrientation;
    } paper;
//    int pageOrientation;
    int columnCount;
    
    void 	insert( McDocElement * e, int idx = -1 );
    void 	insert( McDocFragment * fragment, int idx = -1 );
    QString 	toRTF(const FontList & fl, const ColorList & cl);
    QString 	toXML();
    void setFromXML( QDomElement & e );
    QPtrList<McDocElement> docElements;
    QPtrList<McDocElement> header;
    QPtrList<McDocElement> footer;
};

class McDocument {
    public:
    enum 	PageOrientation { poPortrait, poLandscape };
	enum	SectionBreak { sbNone=1, sbNewPage, sbOddPage, sbEvenPage };
	enum	Break { brNewPage, brNewColumn, brNewLine };
    enum	FileFormat {ffXML, ffRTF};
    McDocument();
    ~McDocument(){ qDebug("Deleting Document %x !!! docSections.count()=%d, docElements.count()=%d", this, docSections.count(), docElements.count()); docSections.clear(); docElements.clear();};
    void 	insert( McDocSection * s, int idx = -1 );
    void 	insert( McDocElement * e, int idx = -1 );
    void 	insert( McDocFragment * fragment, int idx = -1 );
    QString 	toRTF();
    QString 	toXML();
    void 		toXML( const QString & fileName );
    void 		printMe();
    
    QPtrList<McDocElement> docElements;
    QPtrList<McDocSection> docSections;
	ColorList colorList;
	FontList  fontList;

	protected:
	void		resetLists();
	QString		colorListToRtf();
	QString		fontListToRtf();
}; 

void McDocParagraph::setIndentsMM( int fi, int li, int ri )
{
//    cout << "setting indents in mm !" << endl;
    setIndents( ceil( fi * 144 / 2.54 ), ceil( li * 144 / 2.54 ), ceil( ri * 144 / 2.54 ) );
//    cout << "First indent " << fi << " is " << pd->indents[0] << " and back is " << (pd->indents[0] * 2.54 / 144) << endl;
//    cout << "Left  indent " << li << " is " << pd->indents[1] << " and back is " << (pd->indents[1] * 2.54 / 144) << endl;
//    cout << "Right indent " << ri << " is " << pd->indents[2] << " and back is " << (pd->indents[2] * 2.54 / 144) << endl;
}

#endif // MCDOCUMENT_H