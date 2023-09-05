//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BitBtn1Click(TObject *Sender)
{
	 Form1 -> i1 = LabeledEdit1 -> Text;
	 Form1 -> i2 = LabeledEdit2 -> Text;
     Form3 -> Close();
}
//---------------------------------------------------------------------------
