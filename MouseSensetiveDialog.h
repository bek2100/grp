#pragma once


// MouseSensetiveDialog dialog

class MouseSensetiveDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MouseSensetiveDialog)

public:
	MouseSensetiveDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~MouseSensetiveDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_MOUSESENSETIVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_mouse_sensetivity;
};
