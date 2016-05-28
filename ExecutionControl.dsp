# Microsoft Developer Studio Project File - Name="ExecutionControl" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86)  Application" 0x0101

CFG=ExecutionControl - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ExecutionControl.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ExecutionControl.mak" CFG="ExecutionControl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ExecutionControl - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ExecutionControl - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "tmp\obj\release_mt_shared"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "tmp\obj\release_mt_shared"
# PROP Target_Dir ""
# ADD CPP -MD /W3 /I "$(QTDIR)\include" /I "C:\Qt\3.3.3\projects\ExecutionControl_v1_1" /I "tmp\moc\release_mt_shared" /I "C:\Qt\3.3.3\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D UNICODE /D QT_DLL /D QT_THREAD_SUPPORT /D QT_ACCESSIBILITY_SUPPORT /D "QT_NO_DEBUG" /FD /c -nologo -Zm200 -O1 
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt333.lib"  "qtmain.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "qaxcontainer.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"   /NOLOGO /DELAYLOAD:opengl32.dll /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" delayimp.lib /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll 


!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD CPP -MDd /W3 /GZ /ZI /Od /I "$(QTDIR)\include" /I "C:\Qt\3.3.3\projects\ExecutionControl_v1_1" /I "tmp\moc\release_mt_shared" /I "C:\Qt\3.3.3\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D UNICODE /D QT_DLL /D QT_THREAD_SUPPORT /D QT_ACCESSIBILITY_SUPPORT /FD /c -nologo -Zm200 -Zi  
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt333.lib"  "qtmain.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "qaxcontainer.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"   /NOLOGO /DELAYLOAD:opengl32.dll /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" /pdbtype:sept /DEBUG 


!ENDIF 

# Begin Target

# Name "ExecutionControl - Win32 Release"
# Name "ExecutionControl - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=mainform.cpp
# End Source File
# Begin Source File

SOURCE=newplandialog.cpp
# End Source File
# Begin Source File

SOURCE=removeplandialog.cpp
# End Source File
# Begin Source File

SOURCE=addtopicdialog.cpp
# End Source File
# Begin Source File

SOURCE=edittopicdialog.cpp
# End Source File
# Begin Source File

SOURCE=referenceexecutionform.cpp
# End Source File
# Begin Source File

SOURCE=referenceskbform.cpp
# End Source File
# Begin Source File

SOURCE=openplandialog.cpp
# End Source File
# Begin Source File

SOURCE=connectdbdialog.cpp
# End Source File
# Begin Source File

SOURCE=mcdocument.cpp
# End Source File
# Begin Source File

SOURCE=filterdialog.cpp
# End Source File
# Begin Source File

SOURCE=ExecutionControl.rc
# End Source File

# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=mainform.h

USERDEP_mainform=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing mainform.h...
InputPath=.\mainform.h


BuildCmds= \
	$(QTDIR)\bin\moc mainform.h -o tmp\moc\release_mt_shared\moc_mainform.cpp \

"tmp\moc\release_mt_shared\moc_mainform.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing mainform.h...
InputPath=.\mainform.h


BuildCmds= \
	$(QTDIR)\bin\moc mainform.h -o tmp\moc\release_mt_shared\moc_mainform.cpp \

"tmp\moc\release_mt_shared\moc_mainform.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=newplandialog.h

USERDEP_newplandialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing newplandialog.h...
InputPath=.\newplandialog.h


BuildCmds= \
	$(QTDIR)\bin\moc newplandialog.h -o tmp\moc\release_mt_shared\moc_newplandialog.cpp \

"tmp\moc\release_mt_shared\moc_newplandialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing newplandialog.h...
InputPath=.\newplandialog.h


BuildCmds= \
	$(QTDIR)\bin\moc newplandialog.h -o tmp\moc\release_mt_shared\moc_newplandialog.cpp \

"tmp\moc\release_mt_shared\moc_newplandialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=removeplandialog.h

USERDEP_removeplandialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing removeplandialog.h...
InputPath=.\removeplandialog.h


BuildCmds= \
	$(QTDIR)\bin\moc removeplandialog.h -o tmp\moc\release_mt_shared\moc_removeplandialog.cpp \

"tmp\moc\release_mt_shared\moc_removeplandialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing removeplandialog.h...
InputPath=.\removeplandialog.h


BuildCmds= \
	$(QTDIR)\bin\moc removeplandialog.h -o tmp\moc\release_mt_shared\moc_removeplandialog.cpp \

"tmp\moc\release_mt_shared\moc_removeplandialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=addtopicdialog.h

USERDEP_addtopicdialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing addtopicdialog.h...
InputPath=.\addtopicdialog.h


BuildCmds= \
	$(QTDIR)\bin\moc addtopicdialog.h -o tmp\moc\release_mt_shared\moc_addtopicdialog.cpp \

"tmp\moc\release_mt_shared\moc_addtopicdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing addtopicdialog.h...
InputPath=.\addtopicdialog.h


BuildCmds= \
	$(QTDIR)\bin\moc addtopicdialog.h -o tmp\moc\release_mt_shared\moc_addtopicdialog.cpp \

"tmp\moc\release_mt_shared\moc_addtopicdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=edittopicdialog.h

USERDEP_edittopicdialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing edittopicdialog.h...
InputPath=.\edittopicdialog.h


BuildCmds= \
	$(QTDIR)\bin\moc edittopicdialog.h -o tmp\moc\release_mt_shared\moc_edittopicdialog.cpp \

"tmp\moc\release_mt_shared\moc_edittopicdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing edittopicdialog.h...
InputPath=.\edittopicdialog.h


BuildCmds= \
	$(QTDIR)\bin\moc edittopicdialog.h -o tmp\moc\release_mt_shared\moc_edittopicdialog.cpp \

"tmp\moc\release_mt_shared\moc_edittopicdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=referenceexecutionform.h

USERDEP_referenceexecutionform=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing referenceexecutionform.h...
InputPath=.\referenceexecutionform.h


BuildCmds= \
	$(QTDIR)\bin\moc referenceexecutionform.h -o tmp\moc\release_mt_shared\moc_referenceexecutionform.cpp \

"tmp\moc\release_mt_shared\moc_referenceexecutionform.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing referenceexecutionform.h...
InputPath=.\referenceexecutionform.h


BuildCmds= \
	$(QTDIR)\bin\moc referenceexecutionform.h -o tmp\moc\release_mt_shared\moc_referenceexecutionform.cpp \

"tmp\moc\release_mt_shared\moc_referenceexecutionform.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=referenceskbform.h

USERDEP_referenceskbform=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing referenceskbform.h...
InputPath=.\referenceskbform.h


BuildCmds= \
	$(QTDIR)\bin\moc referenceskbform.h -o tmp\moc\release_mt_shared\moc_referenceskbform.cpp \

"tmp\moc\release_mt_shared\moc_referenceskbform.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing referenceskbform.h...
InputPath=.\referenceskbform.h


BuildCmds= \
	$(QTDIR)\bin\moc referenceskbform.h -o tmp\moc\release_mt_shared\moc_referenceskbform.cpp \

"tmp\moc\release_mt_shared\moc_referenceskbform.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=openplandialog.h

USERDEP_openplandialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing openplandialog.h...
InputPath=.\openplandialog.h


BuildCmds= \
	$(QTDIR)\bin\moc openplandialog.h -o tmp\moc\release_mt_shared\moc_openplandialog.cpp \

"tmp\moc\release_mt_shared\moc_openplandialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing openplandialog.h...
InputPath=.\openplandialog.h


BuildCmds= \
	$(QTDIR)\bin\moc openplandialog.h -o tmp\moc\release_mt_shared\moc_openplandialog.cpp \

"tmp\moc\release_mt_shared\moc_openplandialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=connectdbdialog.h

USERDEP_connectdbdialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing connectdbdialog.h...
InputPath=.\connectdbdialog.h


BuildCmds= \
	$(QTDIR)\bin\moc connectdbdialog.h -o tmp\moc\release_mt_shared\moc_connectdbdialog.cpp \

"tmp\moc\release_mt_shared\moc_connectdbdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing connectdbdialog.h...
InputPath=.\connectdbdialog.h


BuildCmds= \
	$(QTDIR)\bin\moc connectdbdialog.h -o tmp\moc\release_mt_shared\moc_connectdbdialog.cpp \

"tmp\moc\release_mt_shared\moc_connectdbdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=mcdocument.h

# End Source File
# Begin Source File

SOURCE=filterdialog.h

USERDEP_filterdialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Moc'ing filterdialog.h...
InputPath=.\filterdialog.h


BuildCmds= \
	$(QTDIR)\bin\moc filterdialog.h -o tmp\moc\release_mt_shared\moc_filterdialog.cpp \

"tmp\moc\release_mt_shared\moc_filterdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Moc'ing filterdialog.h...
InputPath=.\filterdialog.h


BuildCmds= \
	$(QTDIR)\bin\moc filterdialog.h -o tmp\moc\release_mt_shared\moc_filterdialog.cpp \

"tmp\moc\release_mt_shared\moc_filterdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group

# Begin Group "Forms"
# Prop Default_Filter "ui"
# Begin Source File

SOURCE=mainformbase.ui
USERDEP_mainformbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing mainformbase.ui...
InputPath=.\mainformbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic mainformbase.ui -o mainformbase.h \
	$(QTDIR)\bin\uic mainformbase.ui -i mainformbase.h -o mainformbase.cpp \
	$(QTDIR)\bin\moc  mainformbase.h -o tmp\moc\release_mt_shared\moc_mainformbase.cpp \

"mainformbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"mainformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_mainformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing mainformbase.ui...
InputPath=.\mainformbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic mainformbase.ui -o mainformbase.h \
	$(QTDIR)\bin\uic mainformbase.ui -i mainformbase.h -o mainformbase.cpp \
	$(QTDIR)\bin\moc  mainformbase.h -o tmp\moc\release_mt_shared\moc_mainformbase.cpp \

"mainformbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"mainformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_mainformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=newplandialogbase.ui
USERDEP_newplandialogbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing newplandialogbase.ui...
InputPath=.\newplandialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic newplandialogbase.ui -o newplandialogbase.h \
	$(QTDIR)\bin\uic newplandialogbase.ui -i newplandialogbase.h -o newplandialogbase.cpp \
	$(QTDIR)\bin\moc  newplandialogbase.h -o tmp\moc\release_mt_shared\moc_newplandialogbase.cpp \

"newplandialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"newplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_newplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing newplandialogbase.ui...
InputPath=.\newplandialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic newplandialogbase.ui -o newplandialogbase.h \
	$(QTDIR)\bin\uic newplandialogbase.ui -i newplandialogbase.h -o newplandialogbase.cpp \
	$(QTDIR)\bin\moc  newplandialogbase.h -o tmp\moc\release_mt_shared\moc_newplandialogbase.cpp \

"newplandialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"newplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_newplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=removeplandialogbase.ui
USERDEP_removeplandialogbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing removeplandialogbase.ui...
InputPath=.\removeplandialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic removeplandialogbase.ui -o removeplandialogbase.h \
	$(QTDIR)\bin\uic removeplandialogbase.ui -i removeplandialogbase.h -o removeplandialogbase.cpp \
	$(QTDIR)\bin\moc  removeplandialogbase.h -o tmp\moc\release_mt_shared\moc_removeplandialogbase.cpp \

"removeplandialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"removeplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_removeplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing removeplandialogbase.ui...
InputPath=.\removeplandialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic removeplandialogbase.ui -o removeplandialogbase.h \
	$(QTDIR)\bin\uic removeplandialogbase.ui -i removeplandialogbase.h -o removeplandialogbase.cpp \
	$(QTDIR)\bin\moc  removeplandialogbase.h -o tmp\moc\release_mt_shared\moc_removeplandialogbase.cpp \

"removeplandialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"removeplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_removeplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=addtopicdialogbase.ui
USERDEP_addtopicdialogbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing addtopicdialogbase.ui...
InputPath=.\addtopicdialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic addtopicdialogbase.ui -o addtopicdialogbase.h \
	$(QTDIR)\bin\uic addtopicdialogbase.ui -i addtopicdialogbase.h -o addtopicdialogbase.cpp \
	$(QTDIR)\bin\moc  addtopicdialogbase.h -o tmp\moc\release_mt_shared\moc_addtopicdialogbase.cpp \

"addtopicdialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"addtopicdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_addtopicdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing addtopicdialogbase.ui...
InputPath=.\addtopicdialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic addtopicdialogbase.ui -o addtopicdialogbase.h \
	$(QTDIR)\bin\uic addtopicdialogbase.ui -i addtopicdialogbase.h -o addtopicdialogbase.cpp \
	$(QTDIR)\bin\moc  addtopicdialogbase.h -o tmp\moc\release_mt_shared\moc_addtopicdialogbase.cpp \

"addtopicdialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"addtopicdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_addtopicdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=edittopicdialogbase.ui
USERDEP_edittopicdialogbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing edittopicdialogbase.ui...
InputPath=.\edittopicdialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic edittopicdialogbase.ui -o edittopicdialogbase.h \
	$(QTDIR)\bin\uic edittopicdialogbase.ui -i edittopicdialogbase.h -o edittopicdialogbase.cpp \
	$(QTDIR)\bin\moc  edittopicdialogbase.h -o tmp\moc\release_mt_shared\moc_edittopicdialogbase.cpp \

"edittopicdialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"edittopicdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_edittopicdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing edittopicdialogbase.ui...
InputPath=.\edittopicdialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic edittopicdialogbase.ui -o edittopicdialogbase.h \
	$(QTDIR)\bin\uic edittopicdialogbase.ui -i edittopicdialogbase.h -o edittopicdialogbase.cpp \
	$(QTDIR)\bin\moc  edittopicdialogbase.h -o tmp\moc\release_mt_shared\moc_edittopicdialogbase.cpp \

"edittopicdialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"edittopicdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_edittopicdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=referenceexecutionformbase.ui
USERDEP_referenceexecutionformbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing referenceexecutionformbase.ui...
InputPath=.\referenceexecutionformbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic referenceexecutionformbase.ui -o referenceexecutionformbase.h \
	$(QTDIR)\bin\uic referenceexecutionformbase.ui -i referenceexecutionformbase.h -o referenceexecutionformbase.cpp \
	$(QTDIR)\bin\moc  referenceexecutionformbase.h -o tmp\moc\release_mt_shared\moc_referenceexecutionformbase.cpp \

"referenceexecutionformbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"referenceexecutionformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_referenceexecutionformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing referenceexecutionformbase.ui...
InputPath=.\referenceexecutionformbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic referenceexecutionformbase.ui -o referenceexecutionformbase.h \
	$(QTDIR)\bin\uic referenceexecutionformbase.ui -i referenceexecutionformbase.h -o referenceexecutionformbase.cpp \
	$(QTDIR)\bin\moc  referenceexecutionformbase.h -o tmp\moc\release_mt_shared\moc_referenceexecutionformbase.cpp \

"referenceexecutionformbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"referenceexecutionformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_referenceexecutionformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=openplandialogbase.ui
USERDEP_openplandialogbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing openplandialogbase.ui...
InputPath=.\openplandialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic openplandialogbase.ui -o openplandialogbase.h \
	$(QTDIR)\bin\uic openplandialogbase.ui -i openplandialogbase.h -o openplandialogbase.cpp \
	$(QTDIR)\bin\moc  openplandialogbase.h -o tmp\moc\release_mt_shared\moc_openplandialogbase.cpp \

"openplandialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"openplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_openplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing openplandialogbase.ui...
InputPath=.\openplandialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic openplandialogbase.ui -o openplandialogbase.h \
	$(QTDIR)\bin\uic openplandialogbase.ui -i openplandialogbase.h -o openplandialogbase.cpp \
	$(QTDIR)\bin\moc  openplandialogbase.h -o tmp\moc\release_mt_shared\moc_openplandialogbase.cpp \

"openplandialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"openplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_openplandialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=referenceskbformbase.ui
USERDEP_referenceskbformbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing referenceskbformbase.ui...
InputPath=.\referenceskbformbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic referenceskbformbase.ui -o referenceskbformbase.h \
	$(QTDIR)\bin\uic referenceskbformbase.ui -i referenceskbformbase.h -o referenceskbformbase.cpp \
	$(QTDIR)\bin\moc  referenceskbformbase.h -o tmp\moc\release_mt_shared\moc_referenceskbformbase.cpp \

"referenceskbformbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"referenceskbformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_referenceskbformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing referenceskbformbase.ui...
InputPath=.\referenceskbformbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic referenceskbformbase.ui -o referenceskbformbase.h \
	$(QTDIR)\bin\uic referenceskbformbase.ui -i referenceskbformbase.h -o referenceskbformbase.cpp \
	$(QTDIR)\bin\moc  referenceskbformbase.h -o tmp\moc\release_mt_shared\moc_referenceskbformbase.cpp \

"referenceskbformbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"referenceskbformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_referenceskbformbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=connectdbdialogbase.ui
USERDEP_connectdbdialogbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing connectdbdialogbase.ui...
InputPath=.\connectdbdialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic connectdbdialogbase.ui -o connectdbdialogbase.h \
	$(QTDIR)\bin\uic connectdbdialogbase.ui -i connectdbdialogbase.h -o connectdbdialogbase.cpp \
	$(QTDIR)\bin\moc  connectdbdialogbase.h -o tmp\moc\release_mt_shared\moc_connectdbdialogbase.cpp \

"connectdbdialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"connectdbdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_connectdbdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing connectdbdialogbase.ui...
InputPath=.\connectdbdialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic connectdbdialogbase.ui -o connectdbdialogbase.h \
	$(QTDIR)\bin\uic connectdbdialogbase.ui -i connectdbdialogbase.h -o connectdbdialogbase.cpp \
	$(QTDIR)\bin\moc  connectdbdialogbase.h -o tmp\moc\release_mt_shared\moc_connectdbdialogbase.cpp \

"connectdbdialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"connectdbdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_connectdbdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=filterdialogbase.ui
USERDEP_filterdialogbase.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Uic'ing filterdialogbase.ui...
InputPath=.\filterdialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic filterdialogbase.ui -o filterdialogbase.h \
	$(QTDIR)\bin\uic filterdialogbase.ui -i filterdialogbase.h -o filterdialogbase.cpp \
	$(QTDIR)\bin\moc  filterdialogbase.h -o tmp\moc\release_mt_shared\moc_filterdialogbase.cpp \

"filterdialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"filterdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_filterdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Uic'ing filterdialogbase.ui...
InputPath=.\filterdialogbase.ui

BuildCmds= \
	$(QTDIR)\bin\uic filterdialogbase.ui -o filterdialogbase.h \
	$(QTDIR)\bin\uic filterdialogbase.ui -i filterdialogbase.h -o filterdialogbase.cpp \
	$(QTDIR)\bin\moc  filterdialogbase.h -o tmp\moc\release_mt_shared\moc_filterdialogbase.cpp \

"filterdialogbase.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"filterdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"tmp\moc\release_mt_shared\moc_filterdialogbase.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group




# Begin Group "Images"
# Prop Default_Filter "png jpeg bmp xpm"
# Begin Source File

SOURCE=images/block_16.png
USERDEP_images/block_16.png="images/block_16.png"\
"images/tick_16.png"\
"images/delete_16.png"\
"images/plus_16.png"\
"images/pencil_16.png"\
"images/document_16.png"\
"images/user_16.png"\
"images/gear_16.png"\
"images/folder_16.png"\
"images/office_16.png"\
"images/shutdown_16.png"\
"images/funnel_16.png"

!IF  "$(CFG)" == "ExecutionControl - Win32 Release"

# Begin Custom Build - Creating image collection...
InputPath=.\images/block_16.png

"qmake_image_collection.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\uic -embed ExecutionControl -f images.tmp -o qmake_image_collection.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "ExecutionControl - Win32 Debug"

# Begin Custom Build - Creating image collection...
InputPath=.\images/block_16.png

"qmake_image_collection.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\uic -embed ExecutionControl -f images.tmp -o qmake_image_collection.cpp

# End Custom Build

!ENDIF 


# End Source File
# Begin Source File

SOURCE=images/tick_16.png
# End Source File
# Begin Source File

SOURCE=images/delete_16.png
# End Source File
# Begin Source File

SOURCE=images/plus_16.png
# End Source File
# Begin Source File

SOURCE=images/pencil_16.png
# End Source File
# Begin Source File

SOURCE=images/document_16.png
# End Source File
# Begin Source File

SOURCE=images/user_16.png
# End Source File
# Begin Source File

SOURCE=images/gear_16.png
# End Source File
# Begin Source File

SOURCE=images/folder_16.png
# End Source File
# Begin Source File

SOURCE=images/office_16.png
# End Source File
# Begin Source File

SOURCE=images/shutdown_16.png
# End Source File
# Begin Source File

SOURCE=images/funnel_16.png
# End Source File

# End Group


# Begin Group "Generated"
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_mainform.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_newplandialog.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_removeplandialog.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_addtopicdialog.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_edittopicdialog.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_referenceexecutionform.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_referenceskbform.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_openplandialog.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_connectdbdialog.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_filterdialog.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_mainformbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_newplandialogbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_removeplandialogbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_addtopicdialogbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_edittopicdialogbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_referenceexecutionformbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_openplandialogbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_referenceskbformbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_connectdbdialogbase.cpp
# End Source File
# Begin Source File

SOURCE=tmp\moc\release_mt_shared\moc_filterdialogbase.cpp
# End Source File

# Begin Source File

SOURCE=mainformbase.cpp
# End Source File
# Begin Source File

SOURCE=newplandialogbase.cpp
# End Source File
# Begin Source File

SOURCE=removeplandialogbase.cpp
# End Source File
# Begin Source File

SOURCE=addtopicdialogbase.cpp
# End Source File
# Begin Source File

SOURCE=edittopicdialogbase.cpp
# End Source File
# Begin Source File

SOURCE=referenceexecutionformbase.cpp
# End Source File
# Begin Source File

SOURCE=openplandialogbase.cpp
# End Source File
# Begin Source File

SOURCE=referenceskbformbase.cpp
# End Source File
# Begin Source File

SOURCE=connectdbdialogbase.cpp
# End Source File
# Begin Source File

SOURCE=filterdialogbase.cpp
# End Source File

# Begin Source File

SOURCE=mainformbase.h
# End Source File
# Begin Source File

SOURCE=newplandialogbase.h
# End Source File
# Begin Source File

SOURCE=removeplandialogbase.h
# End Source File
# Begin Source File

SOURCE=addtopicdialogbase.h
# End Source File
# Begin Source File

SOURCE=edittopicdialogbase.h
# End Source File
# Begin Source File

SOURCE=referenceexecutionformbase.h
# End Source File
# Begin Source File

SOURCE=openplandialogbase.h
# End Source File
# Begin Source File

SOURCE=referenceskbformbase.h
# End Source File
# Begin Source File

SOURCE=connectdbdialogbase.h
# End Source File
# Begin Source File

SOURCE=filterdialogbase.h
# End Source File

# Begin Source File

SOURCE=qmake_image_collection.cpp
# End Source File



# Prop Default_Filter "moc"
# End Group
# End Target
# End Project

