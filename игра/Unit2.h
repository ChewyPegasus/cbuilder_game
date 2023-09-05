//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Unit1.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSpinEdit *SpinEdit1;
	TSpinEdit *SpinEdit2;
	TPanel *Panel2;
	TSpinEdit *SpinEdit3;
	TSpinEdit *SpinEdit4;
	TBitBtn *BitBtn1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
template <class T> void swap ( T& a, T& b );
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
