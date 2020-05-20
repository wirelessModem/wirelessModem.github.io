
// NRsystem_GUI.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CNRsystem_GUIApp:
// See NRsystem_GUI.cpp for the implementation of this class
//

class CNRsystem_GUIApp : public CWinApp
{
public:
	CNRsystem_GUIApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CNRsystem_GUIApp theApp;