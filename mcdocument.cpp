/****************************************************************************
**
** Implementation of McDocument class
**
** Created : 12.11.2003
**
** Copyright (C) 2003 Makarenko.  All rights reserved.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
**********************************************************************/

#include "mcdocument.h"
#include <qdom.h>
#include <math.h>
#include <qcolor.h>

char docHeader[] = "{\\rtf1\\ansi\\ansicpg1251\\uc1 \\deff0\\deflang1049\\deflangfe1049";
char docFontTable[] = "{\\fonttbl{\\f0\\froman\\fcharset0\\fprq2{\\*\\panose 02020603050405020304}Times New Roman;}{\\f16\\froman\\fcharset238\\fprq2 Times New Roman CE;}{\\f17\\froman\\fcharset204\\fprq2 Times New Roman Cyr;}\x0d\x0a{\\f19\\froman\\fcharset161\\fprq2 Times New Roman Greek;}{\\f20\\froman\\fcharset162\\fprq2 Times New Roman Tur;}{\\f21\\froman\\fcharset186\\fprq2 Times New Roman Baltic;}}\x0d\x0a";
char docColorTable[] = "{\\colortbl;\\red0\\green0\\blue0;\\red0\\green0\\blue255;\\red0\\green255\\blue255;\x0d\x0a\\red0\\green255\\blue0;\\red255\\green0\\blue255;\\red255\\green0\\blue0;\\red255\\green255\\blue0;\\red255\\green255\\blue255;\\red0\\green0\\blue128;\\red0\\green128\\blue128;\\red0\\green128\\blue0;\\red128\\green0\\blue128;\\red128\\green0\\blue0;\\red128\\green128\\blue0;\x0d\x0a\\red128\\green128\\blue128;\\red192\\green192\\blue192;}";
char docStyleSheetTable[] = "{\\stylesheet{\\widctlpar\\adjustright \\fs20\\lang1049\\cgrid \\snext0 Normal;}{\\*\\cs10 \\additive Default Paragraph Font;}}\x0d\x0a";

char dh1[] = "{\\rtf1\\ansi\\ansicpg1251\\uc1 \\deff0\\deflang1033\\deflangfe1049{\\fonttbl{\\f0\\froman\\fcharset0\\fprq2{\\*\\panose 02020603050405020304}Times New Roman;}{\\f16\\froman\\fcharset238\\fprq2 Times New Roman CE;}{\\f17\\froman\\fcharset204\\fprq2 Times New Roman Cyr;}" ;
char dh2[] = "\x0d\x0a{\\f19\\froman\\fcharset161\\fprq2 Times New Roman Greek;}{\\f20\\froman\\fcharset162\\fprq2 Times New Roman Tur;}{\\f21\\froman\\fcharset186\\fprq2 Times New Roman Baltic;}}{\\colortbl;\\red0\\green0\\blue0;\\red0\\green0\\blue255;\\red0\\green255\\blue255;" ;
char dh3[] = "\x0d\x0a\\red0\\green255\\blue0;\\red255\\green0\\blue255;\\red255\\green0\\blue0;\\red255\\green255\\blue0;\\red255\\green255\\blue255;\\red0\\green0\\blue128;\\red0\\green128\\blue128;\\red0\\green128\\blue0;\\red128\\green0\\blue128;\\red128\\green0\\blue0;\\red128\\green128\\blue0;" ;
char dh4[] = "\x0d\x0a\\red128\\green128\\blue128;\\red192\\green192\\blue192;}{\\stylesheet{\\widctlpar\\adjustright \\fs20\\lang1049\\cgrid \\snext0 Normal;}{\\*\\cs10 \\additive Default Paragraph Font;}}" ;

uint McDocParagraph::type() const
{
    return deParagraph;
}

//Fmt1::Fmt1( const QString & fnt = "Times", int size = 14, int weight = QFont::Normal, bool italic = false, int clr = 0, int bclr = 0xffffff )
Fmt1::Fmt1( const QString & fnt, int size, int weight, bool italic, int clr, int bclr )
	: font( fnt ), size( size ), color( clr ), backColor( bclr ), weight( weight ), italic( italic ), underline(0)
{
}

//Fmt1::Fmt1( const QFont & fnt, int clr = 0, int bclr = 0xffffff )
Fmt1::Fmt1( const QFont & fnt, int clr, int bclr )
	: font( fnt.family() ), size( fnt.pointSize() ), color( clr ), backColor( bclr ), weight( fnt.weight() ), italic( fnt.italic() ), underline( fnt.underline() )
{
}

Fmt1::Fmt1( const Fmt1 & other )
	: font( other.font ), size( other.size ), color( other.color ), backColor( other.backColor ), weight( other.weight ), italic( other.italic ), underline( other.underline )
{
}

Fmt1 & Fmt1::operator= ( const Fmt1 & f )
{
    font = f.font;
    size = f.size;
    color = f.color;
    backColor = f.backColor;
    weight = f.weight;
    italic = f.italic;
    underline = f.underline;
    return *this;
}

QString Fmt1::toRtfOn(const FontList & fl, const ColorList & cl)
{
	QString res;
	if (!font.isEmpty()) res += QString("\\f%1").arg(fl.findIndex(font.lower())+1);
	if (size > 0) res += QString("\\fs%1").arg(size*2);
	if (color) res += QString("\\cf%1 ").arg(cl.findIndex(color|0xff000000)+1);
	if (backColor) res += QString("\\cb%1").arg(cl.findIndex(backColor|0xff000000)+1);
	if (italic) res += "\\i";
	if (weight > 50) res += "\\b";
	if (underline) res += "\\ul";

	return res;
}

QString Fmt1::toRtfOff(const FontList & fl, const ColorList & cl)
{
	QString res;
	return res;
}

QString Fmt1::toRtfDiff(const Fmt1 & nextFormat, const FontList & fl, const ColorList & cl)
{
	QString res;
	if (font != nextFormat.font) res += QString("\\f%1").arg(fl.findIndex(nextFormat.font.lower())+1);
	if (size != nextFormat.size) res += QString("\\fs%1").arg(nextFormat.size*2);
	if (color != nextFormat.color) res += QString("\\cf%1 ").arg(cl.findIndex(nextFormat.color|0xff000000)+1);
	if (backColor != nextFormat.backColor) res += QString("\\cb%1").arg(cl.findIndex(nextFormat.backColor|0xff000000)+1);
	if (italic != italic) if (nextFormat.italic) res += "\\i"; else res += "\\i0";
	if (weight != nextFormat.weight) if (nextFormat.weight > 50) res += "\\b"; else res += "\\b0";
	if (underline != nextFormat.underline) if (nextFormat.underline) res += "\\ul"; else res += "\\ul0";
	return res;
}

Fmt1ListEntry::Fmt1ListEntry()
	: Fmt1(), prev( 0 ), next( 0 ), pos( 0 )
{
}

Fmt1ListEntry::Fmt1ListEntry( const Fmt1 & format )
	: Fmt1( format ), prev( 0 ), next( 0 ), pos( 0 )
{
}

Fmt1ListEntry & Fmt1ListEntry::operator= ( const Fmt1 & f )
{
    font = f.font;
    size = f.size;
    color = f.color;
    backColor = f.backColor;
    weight = f.weight;
    italic = f.italic;
    underline = f.underline;
    return *this;
}

McDocParagraph::McDocParagraph()
	: McDocElement()
{
    pd = new SharedParagraphData;
}

McDocParagraph::McDocParagraph( McDocParagraph & other )
	: McDocElement()
{
//    if ( pd->deref() ) delete pd;
    pd = other.pd;
    pd->ref();
#ifdef DEBUG_MCDOCPARAGRAPH
    qDebug("McDocParagraph::McDocParagraph(other) : pd is 0x%x, reference count is %d", pd, pd->count);
#endif    
}
//{
//    alignment = par.alignment;
//    firstIndent = par.firstIndent;
//    leftIndent = par.leftIndent;
//    rightIndent = par.rightIndent;
//    fText.text = par.fText.text;
//}

McDocParagraph::~McDocParagraph()
{
#ifdef DEBUG_MCDOCPARAGRAPH
    qDebug("McDocParagraph::~McDocParagraph : About to delete. pd is 0x%x", pd);
#endif    
    if ( pd->deref() ) {
#ifdef DEBUG_MCDOCPARAGRAPH
	qDebug("\tno references - delete");
#endif    
	delete pd;
    }
#ifdef DEBUG_MCDOCPARAGRAPH
    else 	qDebug("\tthere are references - can't delete");
#endif    
}

void McDocParagraph::detach()
{
    if ( pd->count > 1 ) {
	pd->deref();
	pd = new SharedParagraphData( *pd );
    }
}

McDocElement * McDocParagraph::copy()
{
    McDocParagraph * res = new McDocParagraph( *this );
    res->detach();
    return res;
}

void McDocParagraph::setAlignment( uint flags )
{
    if ( pd->alignment != flags ) {
	pd->alignment = flags;
	pd->changed = true;
    }
}

void McDocParagraph::setInterval( float i )
{
    pd->interval = i;
}

void McDocParagraph::setIndents( int fi, int li, int ri )
{
    pd->indents[ 0 ] = fi;
    pd->indents[ 1 ] = li;
    pd->indents[ 2 ] = ri;
//    pd->iFirst = fi;
//    pd->iLeft = li;
//    pd->iRight = ri;
}

void McDocParagraph::merge( McDocParagraph * other )
{
    int pos = pd->text.length();
    pd->text.append( other->pd->text );
//    if ( other->pd->format ) other->pd->format
}

void McDocParagraph::setFormat( const Fmt1 & format )//, int pos=0, int length=-1 )
{
//    if ( (pos == 0) && (length == -1) )
    if ( pd->format ) delete pd->format;
    pd->format = new Fmt1ListEntry( format );
}

void McDocParagraph::setFormat( Fmt1 * format, int pos, int length )
{
    Fmt1ListEntry * curFormat, * newFormat;
    if ( curFormat = pd->format ) {
	while( curFormat->next && ( curFormat->next->pos <= pos ) ) curFormat = curFormat->next;
	if ( curFormat->pos < pos ) {
	    newFormat = new Fmt1ListEntry( *format );
	    newFormat->pos = pos;
//	    newFormat->font = format->font;
//	    newFormat->size = format->size;
//	    newFormat->color = format->color;
//	    newFormat->backColor = format->backColor;
	    newFormat->next = curFormat->next;
	    newFormat->prev = curFormat;
	    curFormat->next = newFormat;
	} else {
//	    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!! setFormat !!!" << endl;
	    if (curFormat->next) {
		delete curFormat->next;
		curFormat->next = 0;
	    }
	    *(pd->format) = *format;
//	    pd->format->font = format->font;
//	    pd->format->size = format->size;
//	    pd->format->color = format->color;
//	    pd->format->backColor = format->backColor;
//	    pd->format->weight = format->weight;
//	    pd->format->italic = format->italic;
//	    newFormat = new Fmt1ListEntry( *format );
//	    newFormat->pos = pos;
//	    newFormat->next = curFormat;
//	    newFormat->prev = curFormat->prev;
//	    curFormat->prev = newFormat;
	}
    } else {
	newFormat = new Fmt1ListEntry( *format );
//	newFormat->font = format->font;
//	newFormat->size = format->size;
//	newFormat->color = format->color;
//	newFormat->backColor = format->backColor;
	newFormat->pos = pos;
	pd->format = newFormat;
    }
//    if ( !fe1 ) fe1 = fe1; // to first
//    if ( fe1->pos < charPos )
//	while ( fe1->next && ( fe1->next->pos <= charPos ) ) fe1 = fe1->next;
//    else 
//	while ( ( fe1->pos > charPos ) && fe1->prev ) fe1 = fe1->prev;
    
}

QString 	McDocParagraph::toRTF(const FontList & fl, const ColorList & cl)
{
	int i;
	unsigned char curChar;
    QString res( "\n\\pard " );
    // justify
    switch(alignment()) {
	case Qt::AlignRight : res+= "\\qr"; break;	
	case Qt::AlignHCenter : res+= "\\qc"; break;	
	case Qt::AlignJustify : res+= "\\qj"; break;
	default : res+="\\ql";
    }
    // indent
    if (pd->indents[0]) res += QString( "\\fi%1" ).arg(pd->indents[0]);
    if (pd->indents[1]) res += QString( "\\li%1" ).arg(pd->indents[1]);
    if (pd->indents[2]) res += QString( "\\ri%1" ).arg(pd->indents[2]);
    if ( pd->inCell ) res += "\\intbl";
//    res += "\\widctlpar\\adjustright \\fs20\\f0\\lang1033\\cgrid {";
    res += "\\widctlpar\\adjustright \\lang1033\\cgrid {";
    // text
//    res += pd->text;
	int curFormatPos = 0;
	int nextFormatPos = pd->text.length();
    Fmt1ListEntry * curFmt = pd->format;
	if (curFmt) {
		res += curFmt->toRtfOn(fl, cl);
		for (;curFmt; curFmt = curFmt->next) {
			qDebug("\tformat");
			if (curFmt->next) nextFormatPos = curFmt->next->pos;
			else nextFormatPos = pd->text.length();

			for (i=curFmt->pos; i<nextFormatPos; i++) {
				if ((curChar=pd->text.local8Bit()[i]) > 127) res += QString().sprintf("\\'%2x", curChar);
				else res += curChar;
			}
			if (curFmt->next) {
				res += curFmt->toRtfDiff(*curFmt->next, fl, cl);
			}
		}

	} else {
		qDebug("\tno format");
		res += "\\f0\\fs20 ";

		for (i=0; i<nextFormatPos; i++) {
			if ((curChar=pd->text.local8Bit()[i]) > 127) res += QString().sprintf("\\'%2x", curChar);
			else res += curChar;
		}
	}

    // text
    if ( pd->inCell ) res += "}";
    else res += "\\par}";
    return res;
}

QString McDocParagraph::toXML( unsigned char level )
{
    QString res = QString( "%1<p fi=\"%2\" li=\"%3\" ri=\"%4\" int=\"%5\" al=\"%6\" >\n" ).arg( ' ', level ).arg(firstIndent()).arg(leftIndent()).arg(rightIndent()).arg(interval()).arg(alignment());
    // font
    Fmt1ListEntry * curFmt = pd->format;
    if (!curFmt) qDebug("No format defined for this paragraph !!!");
    else {
	qDebug("Format is 0x%x", curFmt);
	res += QString( "%1<fnt name=\"%2\" size=\"%3\"").arg( ' ', level+1 ).arg(curFmt->font).arg(curFmt->size);
	if (curFmt->underline) res += " ul=\"1\"";
	res += ">" + pd->text + "</fnt>\n";
//    res += QString( "%1</fnt>\n" ).arg( ' ', level+1 );
    }
    res += QString( "%1</p>\n" ).arg( ' ', level );
    return res;
}

void McDocParagraph::setFromXML( QDomElement & e )
{
    if ( !e.isNull() ) {
//	setIndents( e.attribute( "fi" ).toInt(), e.attribute( "li" ).toInt(), e.attribute( "ri" ).toInt() );
	setIndents( MM2TWIPS( e.attribute( "fi" ).toFloat() ), MM2TWIPS( e.attribute( "li" ).toFloat() ), MM2TWIPS( e.attribute( "ri" ).toFloat() ) );
	setAlignment( e.attribute( "al" ).toInt() );
	setInterval( e.attribute( "int", "1" ).toFloat() );
//	setText( e.text() );

	QDomNode dn = e.firstChild();
	for ( ; !dn.isNull(); dn = dn.nextSibling() ) {
	    QDomElement e = dn.toElement();
	    if ( e.tagName() == "fnt" ) {
		setText(e.text());
		QFont fnt;
		fnt.fromString( e.attribute( "name", "times" )+","+e.attribute("size", "10") );
		fnt.setUnderline(e.attribute("ul", "0").toInt());
		qDebug("\tunderline is %x, font is %s", e.attribute("ul","0"), (const char*)fnt.toString());
		setFormat( Fmt1( fnt ) );
	    }
	}
    }
}

void McDocParagraph::saveToXML( QDomElement & e )
{
    QDomElement de = e.ownerDocument().createElement( "p" );
    e.appendChild( de );
//    QDomText dt = 
    de.appendChild( e.ownerDocument().createTextNode( text().local8Bit()+"A" ) ); 
    if ( firstIndent() ) de.setAttribute( "fi", TWIPS2MM( firstIndent() ) );
    if ( leftIndent() ) de.setAttribute( "li", TWIPS2MM( leftIndent() ) );
    if ( rightIndent() ) de.setAttribute( "ri", TWIPS2MM( rightIndent() ) );
    if ( pd->alignment ) de.setAttribute( "al", pd->alignment );
    if ( pd->interval != 1 ) de.setAttribute( "int", pd->interval );
    QFont fnt;
    Fmt1ListEntry * form = format( 0 );
    if ( form ) fnt = QFont( form->font, form->size, form->weight, form->italic );
    de.setAttribute( "font", fnt.toString() );
}

McDocParagraph::SharedParagraphData::SharedParagraphData()
	: QShared(), format(0), iFirst(0), iLeft(0), iRight(0), inCell(false), changed(false), alignment(0), interval(1)
{
    indents[ 0 ] = 0;
    indents[ 1 ] = 0;
    indents[ 2 ] = 0;
}

McDocParagraph::SharedParagraphData::SharedParagraphData( SharedParagraphData & other )
	: QShared(), format( other.format ), iFirst( other.iFirst ), iLeft( other.iLeft ), iRight( other.iRight ), inCell( other.inCell ), changed( other.changed ), alignment( other.alignment ), interval( other.interval )
{
    text = other.text;
    indents[ 0 ] = other.indents[ 0 ];
    indents[ 1 ] = other.indents[ 1 ];
    indents[ 2 ] = other.indents[ 2 ];
}

McDocParagraph::SharedParagraphData::~SharedParagraphData()
{
    if ( format ) delete format;
}

void McDocParagraph::append( const QString & text, const QFont & font )
{
    pd->text.append( text );
    pd->changed = true;
}

void McDocParagraph::insert( uint idx, const QString & text )
{
    pd->text.insert( idx, text );
    Fmt1ListEntry * fmt = format( idx );
    if ( fmt && fmt->next ) fmt->next->movePos( text.length() );
    pd->changed = true;
}

void McDocParagraph::remove( uint idx, uint len )
{
    pd->text.remove( idx, len );
    Fmt1ListEntry * fmt = format( idx );
    if ( fmt ) {
	if ( fmt->pos == idx ) {
	    if ( fmt->prev ) fmt->prev->next = fmt->next;
	    fmt->next = 0;
	    delete fmt;
	}
    }
    pd->changed = true;
}

Fmt1ListEntry * McDocParagraph::format( int pos ) const
{
    Fmt1ListEntry * curFmt;
//    for ( curFmt = pd->format; curFmt && curFmt->next && ( curFmt->next->pos <= pos ); curFmt = curFmt->next );
    for ( curFmt = pd->format; curFmt && curFmt->next && ( curFmt->next->pos < pos ); curFmt = curFmt->next );
    return curFmt;
}

//void McDocParagraph::setText( const QString & text, int from = 0, int len = -1 )
//{
//    fText.text.replace( from, len, text );
//}
//
//QString McDocParagraph::text()
//{
//    return QString( fText.text );
//}

//int 	McDocParagraph::length() const
//{
//    return fText.text.length();
//}
//
//
//McDocElement * McDocParagraph::copy()
//{
//    McDocParagraph * res = new McDocParagraph;
//    res->append( "Copy "+fText.text, QFont() );
//    return res;
//}

#include <math.h>
McDocument::McDocument()
{
//    paper.width = rint( 21 * 1440 / 2.54 );
//    paper.height = rint( 29.7 * 1440 / 2.54 );
//    paper.marginL = rint( 1440 / 2.54 );
//    paper.marginT = rint( 1440 / 2.54 );
//    paper.marginR = rint( 1440 / 2.54 );
//    paper.marginB = rint( 1440 / 2.54 );
//    paper.orientation = poPortrait;
//    paper.orientation = poAlbum;
    docElements.setAutoDelete( true );
    docSections.setAutoDelete( true );
    
    qDebug("Creating Document %x !!! docSections.count=%d, docElements.count=%d", this, docSections.count(), docElements.count());
    
//    docSections.append( new McDocSection() );
    
//    cout << endl << "Paper width = " << paper.width << " height " << paper.height << endl << " margins " << paper.marginL << " " << paper.marginT << " " << paper.marginR << " " << paper.marginB << endl;
    cout << endl << "size of doc is " << sizeof(McDocument) << endl;
//    cout << endl << "size of PageProperties is " << sizeof(McDocument::PaperProperties) << endl;
//    cout << "pp is " << hex << &printMe << dec << endl; //( McDocument::PageProperties::marginL - McDocument::PageProperties::marginL ) << dec << endl;
//    cout << endl << "size of PrintMe is " << sizeof(McDocument::printMe) << endl;
//    pageOrientation = poPortrait;
//    pageSize = QSize( 210, 297 );
}

void 	McDocument::printMe()
{
#ifdef DEBUG    
    qDebug("McDocument::printMe");
#endif    
}

void 	McDocument::insert( McDocSection * s, int idx )
{
    if ( ( idx < 0 ) || ( idx > docSections.count() ) ) docSections.append( s );
    else docSections.insert( idx, s );
}

void 	McDocument::insert( McDocElement * e, int idx )
{
    if ( ( idx < 0 ) || ( idx > docElements.count() ) ) docElements.append( e );
    else docElements.insert( idx, e );
}

void 	McDocument::insert( McDocFragment * fragment, int idx )
{
    QPtrListIterator<McDocElement> it( fragment->elements );
    McDocElement * e;
    for ( e = it.toLast(); e; e = --it ) {
	insert( e, idx );
    }
}

void McDocument::resetLists()
{
	fontList.clear();
	fontList.append("times new roman");

	colorList.clear();
	colorList.append(qRgb(  0,  0,  0));
	colorList.append(qRgb(  0,  0,255));
	colorList.append(qRgb(  0,255,255));
	colorList.append(qRgb(  0,255,  0));
	colorList.append(qRgb(255,  0,255));
	colorList.append(qRgb(255,  0,  0));
	colorList.append(qRgb(255,255,  0));
	colorList.append(qRgb(255,255,255));
	colorList.append(qRgb(  0,  0,128));
	colorList.append(qRgb(  0,128,128));
	colorList.append(qRgb(  0,128,  0));
	colorList.append(qRgb(128,  0,128));
	colorList.append(qRgb(128,  0,  0));
	colorList.append(qRgb(128,128,  0));
	colorList.append(qRgb(128,128,128));
	colorList.append(qRgb(192,192,192));

    QPtrListIterator<McDocSection> its( docSections );
    McDocSection * ds;
    McDocElement * e;
    McDocParagraph * dp;
    McDocTable * dt;
	Fmt1ListEntry * fmt;
	for ( ds = its.toFirst(); ds; ds = ++its ) {
	    QPtrListIterator<McDocElement> ite( ds->docElements );
	    for ( e = ite.toFirst(); e; e = ++ite ) {
			if ( e->type() == McDocElement::deParagraph ) {
				dp = (McDocParagraph *)e;
				qDebug("paragraph");
				for (fmt = dp->format(0); fmt; fmt = fmt->next) {
					qDebug("\tfont %s, forecolor %x, backColor %x", (const char *)fmt->font, fmt->color, fmt->backColor);
					if (fontList.findIndex(fmt->font.lower()) == -1) fontList.append(fmt->font.lower());
					if (colorList.findIndex(fmt->color|0xff000000)==-1) { qDebug("\tappend c %x", fmt->color); colorList.append(fmt->color|0xff000000);}
					if (colorList.findIndex(fmt->backColor|0xff000000)==-1) { qDebug("\tappend bc %x", fmt->backColor); colorList.append(fmt->backColor|0xff000000);}
				}
			} else {
				if ( e->type() == McDocElement::deTable ) {
					dt = (McDocTable *)e;
					qDebug("table");
				    QPtrListIterator<McRow> itR( dt->rows );
				    McRow * curRow;
					McCell * curCell;
//				McDocParagraph * curPar;
					for ( curRow = itR.toFirst(); curRow; curRow = ++itR ) {
//					res += QString("\\trowd \\trgaph0\\trleft%1").arg(curRow->leftIndent);//'+IntToStr(Round(LeftIndent*567/4)))
					    QPtrListIterator<McCell> itC( curRow->cells );
						for ( curCell = itC.toFirst(); curCell; curCell = ++itC ) {
							if (curCell->fillColor != qRgb(255,255,255)) {
								if (colorList.findIndex(curCell->fillColor|0xff000000)==-1) colorList.append(curCell->fillColor|0xff000000);
							}
						    QPtrListIterator<McDocParagraph> it( curCell->paragraphs );
							for ( dp = it.toFirst(); dp; dp = ++it ) {
								for (fmt = dp->format(0); fmt; fmt = fmt->next) {
									qDebug("\tfont %s, forecolor %x, backColor %x", (const char *)fmt->font, fmt->color, fmt->backColor);
									if (fontList.findIndex(fmt->font.lower()) == -1) fontList.append(fmt->font.lower());
									if (colorList.findIndex(fmt->color|0xff000000)==-1) { qDebug("\tappend c %x", fmt->color); colorList.append(fmt->color|0xff000000);}
									if (colorList.findIndex(fmt->backColor|0xff000000)==-1) { qDebug("\tappend bc %x", fmt->backColor); colorList.append(fmt->backColor|0xff000000);}
								}
							}
						}
					}
				}
			}
	    }
    }

	qDebug("-------------font table------------------------");
	int i;
	for (i=0; i < fontList.count(); i++) {
		qDebug("%d\t%s", i, (const char *)fontList[i]);
	}

	qDebug("--------------color table-----------------------");
	int r, g, b;
	for (i=0; i < colorList.count(); i++) {
		QColor(colorList[i]).getRgb(&r,&g,&b);
		qDebug("%d\t%08x\t%03d %03d %03d", i, colorList[i], r, g, b);
	}
}

QString		McDocument::colorListToRtf()
{
	int r, g, b;
	QString res("{\\colortbl;");
	int i;
	for (i=0; i < colorList.count(); i++) {
		QColor(colorList[i]).getRgb(&r,&g,&b);
		res += QString("\\red%1\\green%2\\blue%3;").arg(r).arg(g).arg(b);
	}
	res += "}\x0d\x0a";
	qDebug("%s", (const char *)res);
	return res;
}

QString		McDocument::fontListToRtf()
{
//	QString res("{\\fonttbl{\\f0\\froman\\fcharset204\\fprq2 Times New Roman;}");
	QString res("{\\fonttbl");
	
	int i;
	for (i=0; i < fontList.count(); i++) {
		res += QString("{\\f%1\\fcharset204\\fprq2 %2;}").arg(i).arg(fontList[i]);
    }

	res += "}\0xd\0xa";
	qDebug("%s", (const char *)res);
	return res;
}

QString 	McDocument::toRTF()
{
	resetLists();
    QString res( docHeader );
    res += fontListToRtf();  //docFontTable;
    res += colorListToRtf(); //docColorTable;
    res += docStyleSheetTable;
    QPtrListIterator<McDocSection> it( docSections );
    McDocSection * ds;
//    int offset = 0;
    for ( ds = it.toFirst(); ds; ds = ++it ) {
	res += ds->toRTF(fontList, colorList);
//	res.append( sect->text );
    }
    res += "}";
    return res;
}

McCell::McCell()
//	: McDocElement()
{
    vertAlign = Qt::AlignTop;
    cellWidth = 50;
    paragraphs.setAutoDelete(true);
	fillColor = qRgb(255,255,255);
}

McCell::~McCell()
{
    qDebug("McCell::McCell address is 0x%x, paragraphs.count() is %d", this, paragraphs.count());
    paragraphs.clear();
}

void 	McCell::insert( McDocParagraph * par )
{
    par->setInCell( true );
    paragraphs.append( par );
}

/*McDocElement*/McCell * McCell::copy()
{
#ifdef DEBUG    
    qDebug("McCell::copy");
#endif    
    McCell * newCell = new McCell;
    newCell->cellWidth = cellWidth;
    QPtrListIterator<McDocParagraph> it( paragraphs );
    McDocParagraph * curPar;
    for ( curPar = it.toFirst(); curPar; curPar = ++it ) newCell->insert( (McDocParagraph *)curPar->copy() );
    return newCell;
}

void McCell::setFromXML( QDomElement & e )
{
#ifdef DEBUG    
    qDebug("McCell::setFromXML");
#endif    
    vertAlign = e.attribute( "al" ).toInt();
    if ( !(vertAlign & Qt::AlignVertical_Mask) ) vertAlign = Qt::AlignTop;
    cellWidth = MM2TWIPS( e.attribute( "width", "25" ).toFloat() ); //e.attribute( "width", "50" ).toInt();
    if ( e.attribute( "bl" ).toInt() ) borders[0].shape = bsSingle; else borders[0].shape = bsNone;
    if ( e.attribute( "bt" ).toInt() ) borders[1].shape = bsSingle; else borders[1].shape = bsNone;
    if ( e.attribute( "br" ).toInt() ) borders[2].shape = bsSingle; else borders[2].shape = bsNone;
    if ( e.attribute( "bb" ).toInt() ) borders[3].shape = bsSingle; else borders[3].shape = bsNone;
#ifdef DEBUG    
    qDebug("top cell border is %x", borders[1].shape);
#endif    
    QDomNode dn = e.firstChild();
    for ( ; !dn.isNull(); dn = dn.nextSibling() ) {
	QDomElement e = dn.toElement();
	if ( e.tagName() == "p" ) {
	    McDocParagraph * dp = new McDocParagraph;
	    dp->setFromXML( e );
	    paragraphs.append( dp );
	} else qDebug("McCell::setFromXML : Unwished tag \"%s\" found in cell !");
    }
}

void McCell::saveToXML( QDomElement & e )
{
    QDomElement de = e.ownerDocument().createElement( "cell" );
    e.appendChild( de );
    de.setAttribute( "bl", borders[0].shape ); 
    de.setAttribute( "bt", borders[1].shape ); 
    de.setAttribute( "br", borders[2].shape ); 
    de.setAttribute( "bb", borders[3].shape ); 
    de.setAttribute( "al", vertAlign ); 
    de.setAttribute( "width", TWIPS2MM( cellWidth ) );
    QPtrListIterator<McDocParagraph> it( paragraphs );
    McDocParagraph * curPar;
    for ( curPar = it.toFirst(); curPar; curPar = ++it ) curPar->saveToXML( de );
}

QString McCell::toXML( unsigned char level )
{
    QString res = QString("%1<cell width=\"%2\"").arg(' ', level).arg(TWIPS2MM(cellWidth));
    if (borders[0].shape) res += "bl=\"1\""; 
    if (borders[1].shape) res += "bt=\"1\""; 
    if (borders[2].shape) res += "br=\"1\""; 
    if (borders[3].shape) res += "bb=\"1\""; 
    res += ">\n";
    QPtrListIterator<McDocParagraph> it( paragraphs );
    McDocParagraph * curPar;
    for ( curPar = it.toFirst(); curPar; curPar = ++it ) res += curPar->toXML( level+1 );
    res += QString("%1</cell>\n").arg(' ', level);
    return res;
}

McRow::McRow()
	: leftIndent( 0 ), align( Qt::AlignLeft ), isHeader(0)
{
    cells.setAutoDelete(true);
}

McRow::~McRow()
{
    qDebug("McRow::~McRow address is 0x%x, cells.count() is %d", this, cells.count());
    cells.clear();
}

McRow * McRow::copy()
{
//    cout << "McDocElement: copy ! (Cell)" << endl;
    McRow * newRow = new McRow;
    newRow->leftIndent = leftIndent;
    QPtrListIterator<McCell> it( cells );
    McCell * curCell;
    for ( curCell = it.toFirst(); curCell; curCell = ++it ) newRow->cells.append( ( McCell * )curCell->copy() );
    return newRow;
}

QString McRow::toXML( unsigned char level )
{
    QString res = QString("%1<row>\n").arg(' ', level);
    QPtrListIterator<McCell> it( cells );
    McCell * curCell;
    for ( curCell = it.toFirst(); curCell; curCell = ++it ) res += curCell->toXML(level+1);
    res += QString("%1</row>\n").arg(' ', level);
    return res;
}

McDocTable::McDocTable()
{
    rows.setAutoDelete(true);
}

McDocTable::~McDocTable()
{
    qDebug("McDocTable::~McDocTable address is 0x%x. rows.count() is %d", this, rows.count());
    rows.clear();
}
    
uint McDocTable::type() const
{
    return deTable;
}

McDocElement * McDocTable::copy()
{
    McDocTable * newTable = new McDocTable;
    QPtrListIterator<McRow> it( rows );
    McRow * curRow;
    for ( curRow = it.toFirst(); curRow; curRow = ++it ) newTable->rows.append( ( McRow * )curRow->copy() );
    return newTable;
}

/*QString 	McDocTable::toRTF(ColorList * cl)
{
    QString res;//( "\n\\pard \\widctlpar\\adjustright \\fs20\\f17\\lang1033\\cgrid {really, this is a table, - not a paragraph :-)\\par}" );
    QPtrListIterator<McRow> itR( rows );
    McRow * curRow;
	McCell * curCell;
    McDocParagraph * curPar;
    for ( curRow = itR.toFirst(); curRow; curRow = ++itR ) {
		res += QString("\\trowd \\trgaph0\\trleft%1").arg(curRow->leftIndent);//'+IntToStr(Round(LeftIndent*567/4)))
		if (curRow->isHeader) res += "\\trhdr";
	    QPtrListIterator<McCell> itC( curRow->cells );
		int rightPos = 0;
		for ( curCell = itC.toFirst(); curCell; curCell = ++itC ) {
			res += " \\clvertalt";
		    if (curCell->borders[0].shape) res += "\\clbrdrl\\brdrs\\brdrw15";
			if (curCell->borders[1].shape) res += "\\clbrdrt\\brdrs\\brdrw15"; 
			if (curCell->borders[2].shape) res += "\\clbrdrr\\brdrs\\brdrw15"; 
			if (curCell->borders[3].shape) res += "\\clbrdrb\\brdrs\\brdrw15";
			
			if (curCell->fillColor != qRgb(255,255,255)) res += "\\clcbpat5";

			rightPos += TWIPS2MM(curCell->cellWidth);
			res += QString("\\cltxlrtb \\cellx%1").arg(MM2TWIPS(rightPos));// + IntToStr(Round(FCells[i].RightPos*567/4))
		}
		for ( curCell = itC.toFirst(); curCell; curCell = ++itC ) {
		    QPtrListIterator<McDocParagraph> itP( curCell->paragraphs );
			for ( curPar = itP.toFirst(); curPar; curPar = ++itP ) {
				res += curPar->toRTF(cl);
				if (!itP.atLast()) res += "{\\par}"; // need be removed later
			}
			res += "{\\cell }";
		}
		res += "{\\row }";
	}
	res += " \\pard ";
    return res;
}
*/
QString 	McDocTable::toRTF(const FontList & fl, const ColorList & cl)
{
    QString res;//( "\n\\pard \\widctlpar\\adjustright \\fs20\\f17\\lang1033\\cgrid {really, this is a table, - not a paragraph :-)\\par}" );
    QPtrListIterator<McRow> itR( rows );
    McRow * curRow;
	McCell * curCell;
    McDocParagraph * curPar;
    for ( curRow = itR.toFirst(); curRow; curRow = ++itR ) {
		res += QString("\\trowd \\trgaph0\\trleft%1").arg(curRow->leftIndent);//'+IntToStr(Round(LeftIndent*567/4)))
		if (curRow->isHeader) res += "\\trhdr";
	    QPtrListIterator<McCell> itC( curRow->cells );
		int rightPos = 0;
		for ( curCell = itC.toFirst(); curCell; curCell = ++itC ) {
			res += " \\clvertalt";
		    if (curCell->borders[0].shape) res += "\\clbrdrl\\brdrs\\brdrw15";
			if (curCell->borders[1].shape) res += "\\clbrdrt\\brdrs\\brdrw15"; 
			if (curCell->borders[2].shape) res += "\\clbrdrr\\brdrs\\brdrw15"; 
			if (curCell->borders[3].shape) res += "\\clbrdrb\\brdrs\\brdrw15";
			
			if (curCell->fillColor != qRgb(255,255,255)) res += QString("\\clcbpat%1").arg(cl.findIndex(curCell->fillColor)+1);

			rightPos += TWIPS2MM(curCell->cellWidth);
			res += QString("\\cltxlrtb \\cellx%1").arg(MM2TWIPS(rightPos));// + IntToStr(Round(FCells[i].RightPos*567/4))
		}
		for ( curCell = itC.toFirst(); curCell; curCell = ++itC ) {
		    QPtrListIterator<McDocParagraph> itP( curCell->paragraphs );
			for ( curPar = itP.toFirst(); curPar; curPar = ++itP ) {
				res += curPar->toRTF(fl, cl);
				if (!itP.atLast()) res += "{\\par}"; // need be removed later
			}
			res += "{\\cell }";
		}
		res += "{\\row }";
	}
	res += " \\pard ";
    return res;
}

QString McDocTable::toXML( unsigned char level )
{
    QString res( "<t>\n");
    QPtrListIterator<McRow> it( rows );
    McRow * curRow;
    for ( curRow = it.toFirst(); curRow; curRow = ++it ) res += curRow->toXML( level+1 );
    res += "</t>\n";
    return res;
}

void McDocTable::setFromXML( QDomElement & e )
{
    QDomNode dn = e.firstChild();
    for ( ; !dn.isNull(); dn = dn.nextSibling() ) {
	QDomElement e2 = dn.toElement();
	if ( e2.tagName() == "row" ) {
	    McRow * tr = new McRow;
	    tr->leftIndent = e2.attribute( "li" ).toInt();
//	    tr->setAlignment( e2.attribute( "align" ).toInt() );
	    rows.append( tr );
	    QDomNode dn2 = e2.firstChild();
	    for ( ; !dn2.isNull(); dn2 = dn2.nextSibling() ) {
		QDomElement e3 = dn2.toElement();
		if ( e3.tagName() == "cell" ) {
		    McCell * tc = new McCell;
		    tr->cells.append( tc );
		    tc->setFromXML( e3 );
		}
	    }
	}
    }
}

void McDocTable::saveToXML( QDomElement & e )
{
}

McDocSection::McDocSection()
	: columnCount(55)
{
    paper.width = MM2TWIPS(210);
    paper.height = MM2TWIPS(297);
    paper.marginL = MM2TWIPS(25);
    paper.marginT = MM2TWIPS(10);
    paper.marginR = MM2TWIPS(10);
    paper.marginB = MM2TWIPS(5);
    paper.pageOrientation = 0;
    docElements.setAutoDelete( true );
	header.setAutoDelete( true );
	footer.setAutoDelete( true );
}

void 	McDocSection::insert( McDocElement * e, int idx )
{
    if ( ( idx < 0 ) || ( idx > docElements.count() ) ) docElements.append( e );
    else docElements.insert( idx, e );
}

void 	McDocSection::insert( McDocFragment * fragment, int idx )
{
    QPtrListIterator<McDocElement> it( fragment->elements );
    McDocElement * e;
    for ( e = it.toFirst(); e; e = ++it ) {
	insert( e, idx );
    }
}

QString McDocSection::toXML()
{
    QString res = QString( "<section cols=\"%1\" pw=\"%2\" ph=\"%3\" orient=\"%4\" ml=\"%5\" mt=\"%6\" mr=\"%7\" mb=\"%8\">\n").arg(columnCount).arg(TWIPS2MM(paper.width)).arg(TWIPS2MM(paper.height)).arg(paper.pageOrientation).arg(TWIPS2MM(paper.marginL)).arg(TWIPS2MM(paper.marginT)).arg(TWIPS2MM(paper.marginR)).arg(TWIPS2MM(paper.marginB));
//    res += ">\n";
    QPtrListIterator<McDocElement> it( docElements );
    McDocElement * e;
    bool isTable(false);
    for ( e = it.toFirst(); e; e = ++it ) {
	if ( e->type() == McDocElement::deTable ) {
	    if ( !isTable ) { res += " <t>\n"; isTable = true; }
	    QPtrListIterator<McRow> itr( ((McDocTable *)e)->rows );
	    McRow * curRow;
	    for ( curRow = itr.toFirst(); curRow; curRow = ++itr ) res += curRow->toXML( 2 );	    
	} else {
	    if (isTable) { res += " </t>\n"; isTable = false; }
	    qDebug("paragraph toXML !!!!!!!!!!!!!!!!!!!!!!!");
	    res += e->toXML( 1 );
	}
    }
    if (isTable) res += " </t>\n";
    res += "</section>\n";
    return res;
}

QString McDocSection::toRTF(const FontList & fl, const ColorList & cl)
{
//    QString res = QString( "<section cols=\"%1\">\n" ).arg(columnCount);
    QString res = QString( "\\sectd \\paperw%1\\paperh%2\\margl%3\\margt%4\\margr%5\\margb%6\n").arg(paper.width).arg(paper.height).arg(paper.marginL).arg(paper.marginT).arg(paper.marginR).arg(paper.marginB);
	if (paper.pageOrientation) res += "\\lndscpsxn";
//    res += "<!DOCTYPE McDocument>\n";
//    res += "<McDocument pw=\"210\" ph=\"297\" orient=\"0\" ml=\"1\" mt=\"1\" mr=\"1\" mb=\"1\">\n";
    QPtrListIterator<McDocElement> it( docElements );
    McDocElement * e;
    for ( e = it.toFirst(); e; e = ++it ) {
	res += e->toRTF(fl, cl);
    }
    res += "\\sect \n";
    return res;
}

void McDocSection::setFromXML( QDomElement & e )
{
    paper.marginL = MM2TWIPS( e.attribute( "ml", "25" ).toFloat() );
    paper.marginT = MM2TWIPS( e.attribute( "mt", "10" ).toFloat() );
    paper.marginR = MM2TWIPS( e.attribute( "mr", "15" ).toFloat() );
    paper.marginB = MM2TWIPS( e.attribute( "mb", "10" ).toFloat() );
    paper.width = MM2TWIPS( e.attribute( "pw", "210" ).toFloat() );
    paper.height = MM2TWIPS( e.attribute( "ph", "297" ).toFloat() );
    if ( ( paper.width <=0 ) || ( paper.height <= 0 ) ) {
	paper.width = MM2TWIPS( 210 );
	paper.height = MM2TWIPS( 297 );
    }
    paper.pageOrientation = e.attribute("orient").toInt();
    columnCount = e.attribute("cols").toInt();
    QDomNode dn = e.firstChild();
    for ( ; !dn.isNull(); dn = dn.nextSibling() ) {
	QDomElement ee = dn.toElement();
	if ( ee.tagName() == "p" ) {
	    McDocParagraph * dp = new McDocParagraph;
	    dp->setFromXML( ee );
	    docElements.append( dp );
	} else if ( ee.tagName() == "t" ) {
	    McDocTable * dt = new McDocTable;
	    dt->setFromXML( ee );
	    docElements.append( dt );
	}
    }
}

#include <qfile.h>
void 	McDocument::toXML( const QString & fileName )
{
    QDomDocument doc( "mcd" );
    QDomNode dn = doc.createElement( "mcd" );
    doc.appendChild( dn );

    QFile f( fileName );
    f.open( IO_WriteOnly );
    QString kstr;
//    QString kstr="<?XML version=\"1.0\"?>\n";
//    f.writeBlock(kstr, kstr.length());
//    f.putch('\n');
    kstr = doc.toString().local8Bit();
    f.writeBlock(kstr, kstr.length());
    f.close();    
}

QString McDocument::toXML()
{
    QString res( "<?xml version=\"1.0\" encoding=\"KOI8-R\"?>\n" );
    res += "<!DOCTYPE McDocument>\n";
    res += "<McDocument";
//    if (!name.isEmpty()) res += " name=\"" + name + "\"";
    res += ">\n";
//    QPtrListIterator<McDocElement> it( docElements );
//    McDocElement * e;
//    for ( e = it.toFirst(); e; e = ++it ) {
//	res += e->toXML();
//    }
    cout << "saving sections !!!" << endl;
    QPtrListIterator<McDocSection> its( docSections );
    McDocSection * s;
    for ( s = its.toFirst(); s; s = ++its ) {
	cout << "\tsection " << hex << s << dec;
	res += s->toXML();
	cout << "\t-done!" << endl;
    }
    res += "</McDocument>";
    return res;
}

McDocFragment & McDocFragment::operator=( const McDocFragment & fragment )
{
#ifdef DEBUG
    qDebug("McDocFragment::operator = called");
#endif    
    elements.clear();
    QPtrListIterator<McDocElement> it( fragment.elements );
    McDocElement * e;
    for ( e = it.toFirst(); e; e = ++it ) {
#ifdef DEBUG
	qDebug("\telement type=%d", e->type());
#endif
	elements.append( e->copy() );
//	res += e->toXML( level+1 );
    }
    return *this;
}

QString McDocFragment::toXML( unsigned char level )
{
    QString res;
    QPtrListIterator<McDocElement> it( elements );
    McDocElement * e;
    for ( e = it.toFirst(); e; e = ++it ) {
	res += e->toXML( level+1 );
    }
    return res;
}

void McDocFragment::setFromXML( QDomElement & e )
{
    QDomNode dn = e.firstChild();
    for ( ; !dn.isNull(); dn = dn.nextSibling() ) {
	QDomElement e = dn.toElement();
	if ( e.tagName() == "section" ) {
	    qDebug("McDocFragment::setFromXML : section found !!!");
//	    McDocSection * ds = new McDocSection;
//	    ds->setFromXML();
	} else if ( e.tagName() == "p" ) {
	    McDocParagraph * dp = new McDocParagraph;
	    dp->setFromXML( e );
	    elements.append( dp );
	} else if ( e.tagName() == "t" ) {
	    McDocTable * dt = new McDocTable;
	    dt->setFromXML( e );
	    elements.append( dt );
	} else if ( e.tagName() == "if" ) {
	    qDebug("Condition block. Condition is %s", (const char*)e.attribute("cond").local8Bit());
	}
    }
}

void McDocFragment::saveToXML( QDomElement & e )
{
}

#include <qregexp.h>
void McDocFragment::replace( const QString & s1, const QString & s2 )
{
    QPtrListIterator<McDocElement> it( elements );
    McDocElement * e;
    for ( e = it.toFirst(); e; e = ++it ) {
	if ( e->type() == 0 ) {
	    QString txt = ( ( McDocParagraph * ) e )->text();
	    ( ( McDocParagraph * ) e )->setText(txt.replace( QRegExp( s1 ), s2 ));
	}
	if (e->type() == McDocElement::deTable) {
	    QPtrListIterator<McRow> itr( ((McDocTable*)e)->rows );
	    McRow * r;
	    for ( r = itr.toFirst(); r; r = ++itr ) {
		QPtrListIterator<McCell> itc( r->cells );
		McCell * c;
		for ( c = itc.toFirst(); c; c = ++itc ) {
		    QPtrListIterator<McDocParagraph> itp( c->paragraphs );
		    McDocParagraph * p;
		    for ( p = itp.toFirst(); p; p = ++itp ) {
			QString pt = p->text();
			p->setText(pt.replace( QRegExp( s1 ), s2 ));
		    }
		}
	    }
	    
	}
    }
}

void McDocFragment::append( McDocSection * s )
{
    sections.append( s );
}

void McDocFragment::append( McDocElement * e )
{
    McDocSection * curSect = sections.last();
    if ( !curSect ) {
	curSect = new McDocSection;
	append( curSect );
    }
    curSect->insert( e );
}

#include <qbuffer.h>
McDocPicture::McDocPicture() 
	: McDocElement(), rect(0, 0, 5670, 5670), saveAsJPG(1)
{
}

QString	McDocPicture::toRTF(const FontList & fl, const ColorList & cl)
{
    QString res;

	if (!img.isNull()) {
//		res	= QString( "{\\pict\\picscalex100\\picscaley100\\piccropl0\\piccropr0\\piccropt0\\piccropb0");
		res	= QString( "{\\pict");
		res += QString("\\picw%1\\pich%2").arg(img.width()).arg(img.height());
		res += QString("\\picwgoal%1\\pichgoal%2").arg(5670).arg(5670);
		if (saveAsJPG) res += "\\jpegblip\r\n";
		else res += "\\pngblip\r\n";
		QByteArray ba;
		QBuffer buffer( ba );
		buffer.open( IO_WriteOnly );
		img.save( &buffer, saveAsJPG ? "JPEG" : "PNG" ); // writes pixmap into ba in JPG or PNG format
//		img.save( &buffer, "PNG" ); // writes pixmap into ba in PNG format

		buffer.close();
		qDebug("Array size is %d %x", ba.count(), ba.count());

		int i;
		for (i=0; i< ba.count(); i++) {
//		qDebug("%02x", (unsigned char)ba[i]);

			QString charStr;
			unsigned char ch = ba[i];
			if ((ch / 0x10) < 0xa) charStr = QChar(ch / 0x10 + 0x30);
			else charStr = QChar(ch / 0x10 + 0x37);
			if ((ch & 0xf) < 0xa) charStr += QChar((ch & 0xf) + 0x30);
			else charStr += QChar((ch & 0xf) + 0x37);

//  qDebug("%s", (const char *)charStr);
			res += charStr;
		}
		res += "}";
	}
	return res;
}

McDocShape::McDocShape()
	: McDocElement(), rect(0, 0, 567, 567), behindText(0), zPos(0)
{
}

QString	McDocShape::toRTF(const FontList & fl, const ColorList & cl)
{
    QString res;

	res	= QString("{\\shp");

	res += QString("{\\*\\shpinst\\shpleft%1\\shptop%2\\shpright%3\\shpbottom%4").arg(rect.left()).arg(rect.top()).arg(rect.right()).arg(rect.bottom());
	res += "\\shpbxpage\\shpbxignore\\shpbypage\\shpbyignore";
	res += QString("\\shpfblwtxt%1").arg(behindText);
	res += "{\\sp{\\sn posrelh}{\\sv 1}}{\\sp{\\sn posrelv}{\\sv 1}}";
	res += "{\\sp{\\sn fFilled}{\\sv 0}}";
	res += QString("{\\sp{\\sn fBehindDocument}{\\sv %1}}").arg(behindText);
//   \shpwr2\shpwrk0
	res += "{\\sp{\\sn shapeType}{\\sv 3}}";
	res += "}";
	res += "{\\shprslt{\\*\\do\\dobxpage\\dobypage\\dodhgt8192\\dpellipse\\dpx2835\\dpy2835\\dpxsize1440\\dpysize1440\\dpfillfgcr255\\dpfillfgcg255\\dpfillfgcb255\\dpfillbgcr255\\dpfillbgcg255\\dpfillbgcb255\\dpfillpat1\\dplinew15\\dplinecor0\\dplinecog0\\dplinecob0}}";
	res += "}";
	return res;
}

