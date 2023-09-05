//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
	Form1 -> m = SpinEdit1 -> Value;
	Form1 -> n = SpinEdit2 -> Value;
	Form1 -> minr = SpinEdit3 -> Value;
	Form1 -> maxr = SpinEdit4 -> Value;
	if(Form1 -> minr > Form1 -> maxr) swap(Form1 -> minr , Form1 -> maxr);
	Form1 -> DrawGrid1 -> ColCount = Form1 -> n;
	Form1 -> DrawGrid1 -> RowCount = Form1 -> m;
	Form1 -> DrawGrid1 -> Width = (Form1 -> n + 1) * 10;
	Form1 -> DrawGrid1 -> Height = (Form1 -> m + 1) * 10;
	Form1 -> BitBtn1 -> Click();

	Form1 -> Panel1 -> Left = Form1 -> DrawGrid1 -> Left + Form1 -> DrawGrid1 -> Width + 10;
	Form1 -> ClientWidth = Form1 -> Panel1 -> Left + Form1 -> Panel1 -> Width + 10;
	Form1 -> ClientHeight = fmax(Form1 -> Panel1 -> Top + Form1 -> Panel1 -> Height , Form1 -> DrawGrid1 -> Top + Form1 -> DrawGrid1 -> Height) + 10;
	Form2 -> Close();
}
//---------------------------------------------------------------------------

