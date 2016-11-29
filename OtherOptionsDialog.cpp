// OtherOptionsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CGWork.h"
#include "OtherOptionsDialog.h"
#include "afxdialogex.h"
#include <vector>
#include "model.h"

extern std::vector<model> models;
// OtherOptionsDialog dialog

IMPLEMENT_DYNAMIC(OtherOptionsDialog, CDialogEx)

OtherOptionsDialog::OtherOptionsDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(OtherOptionsDialog::IDD, pParent)
{

}

OtherOptionsDialog::OtherOptionsDialog(double def_finess, CString _models_list, CWnd* pParent /*=NULL*/)
	: CDialogEx(OtherOptionsDialog::IDD, pParent)
{
	finess = def_finess;
	models_list = _models_list;
}

OtherOptionsDialog::~OtherOptionsDialog()
{
}

void OtherOptionsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	double past_finess = finess;

	DDX_Text(pDX, IDC_EDIT_FINESS, finess);
	if (finess < 2){
		CString er("Error, finess must be larger than 2, using old value.");
		finess = past_finess;
		this->MessageBox(er);
	}

	CString input_models;
	DDX_Text(pDX, IDC_EDIT_MODEL_LIST, input_models);
	int n_tokens_pos = 0;
	CString model = input_models.Tokenize(_T(","), n_tokens_pos);

	//assume all models are inactive
	for (int m = 0; m < models.size(); m++){
		active_modules.push_back(false);
	}


	while (!model.IsEmpty())
	{
		for (int m = 0; m < models.size(); m++){
			if (models[m].model_name == model)
				active_modules[m] = true;
		}
		model = input_models.Tokenize(_T(","), n_tokens_pos);
	}
}


BEGIN_MESSAGE_MAP(OtherOptionsDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &OtherOptionsDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


void OtherOptionsDialog::OnBnClickedButton1()
{
	this->MessageBox(models_list);
}
