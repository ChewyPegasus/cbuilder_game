//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct pos
{
	int i , j;
	pos(){i = 0; j = 0;}
	pos(int i_ , int j_){i = i_; j = j_;}
	void preobr()
	{
		i = i / (Form1 -> DrawGrid1 -> DefaultRowHeight + Form1 -> DrawGrid1 -> GridLineWidth); j = j / (Form1 -> DrawGrid1 -> DefaultColWidth + Form1 -> DrawGrid1 -> GridLineWidth);
		if(i < 0) i = 0;
		if(j < 0) j = 0;
		if(i >= Form1 -> m) i = Form1 -> m - 1;
		if(j >= Form1 -> n) j = Form1 -> n - 1;
	}
};

pos start , finish;

vector <vector <char> > pole;
vector <pos> v(8);
Graphics::TBitmap *red = new Graphics::TBitmap(),
				  *blue = new Graphics::TBitmap(),
				  *white = new Graphics::TBitmap(),
				  *purple = new Graphics::TBitmap();
char hod;
//'b' - blue
//'r' - red


bool ok(pos a)
{
	return(a.i < Form1 -> m && a.i >= 0 && a.j < Form1 -> n && a.j >= 0 && (pole[a.i][a.j] == -1 || pole[a.i][a.j] == 0));
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

template <class T> void swap ( T& a, T& b )
{
  T c(a); a=b; b=c;
}

int random(int a , int b)
{
	int x;
	x = rand() % (b-a+1) + a;
    return x;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	m = 50;
	n = 50;
	minr = 1;
	maxr = 6;
	red -> LoadFromFile("red.bmp");
	blue -> LoadFromFile("blue.bmp");
	white -> LoadFromFile("white.bmp");
    purple -> LoadFromFile("purple.bmp");
	hod = 'r';
	pole.resize(m);
	for(int i = 0 ; i < m ; i++)
	{
		pole[i].resize(n , -1);
	}
	pole[0][0] = 'r';
	pole[m-1][n-1] = 'b';
	srand(time(NULL));
    Form1 -> DrawGrid1 -> Width = (Form1 -> n + 1) * 10;
	Form1 -> DrawGrid1 -> Height = (Form1 -> m + 1) * 10;
    Form1 -> Panel1 -> Left = Form1 -> DrawGrid1 -> Left + Form1 -> DrawGrid1 -> Width + 10;
	Form1 -> ClientWidth = Form1 -> Panel1 -> Left + Form1 -> Panel1 -> Width + 10;
	Form1 -> ClientHeight = fmax(Form1 -> Panel1 -> Top + Form1 -> Panel1 -> Height , Form1 -> DrawGrid1 -> Top + Form1 -> DrawGrid1 -> Height) + 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int a , b;
	a = random(Form1 -> minr , Form1 -> maxr);
	//ShowMessage(IntToStr(Form1 -> minr) + " " + IntToStr(Form1 -> maxr));
	b = random(Form1 -> minr , Form1 -> maxr);
	Edit1 -> Text = IntToStr(a);
	Edit2 -> Text = IntToStr(b);
	Button1 -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	start.j = X;
	start.i = Y;
    start.preobr();
	if(Edit2 -> Text == "")
	{
		ShowMessage("������� ������������ �������!");
		return;
	}
    int a , b;
	a = StrToInt(Edit1 -> Text);
	b = StrToInt(Edit2 -> Text);
	v[0] = pos(start.i - a + 1 , start.j - b + 1);
	v[1] = pos(start.i - b + 1 , start.j - a + 1);
	v[2] = pos(start.i - a + 1 , start.j + b - 1);
	v[3] = pos(start.i - b + 1 , start.j + a - 1);
	v[4] = pos(start.i + b - 1 , start.j + a - 1);
	v[5] = pos(start.i + a - 1 , start.j + b - 1);
	v[6] = pos(start.i + a - 1 , start.j - b + 1);
	v[7] = pos(start.i + b - 1 , start.j - a + 1);
	for(int i = 0 ; i < 8 ; i++)
	{
		if(ok(v[i]))
		{
			pole[v[i].i][v[i].j] = 0;
		}
	}
	DrawGrid1 -> Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	finish.j = X;
	finish.i = Y;
	for(int i = 0 ; i < 8 ; i++)
	{
        if(ok(v[i]))
		{
			pole[v[i].i][v[i].j] = -1;
		}
	}
    DrawGrid1 -> Refresh();
	//start.preobr();
	finish.preobr();
	int a , b;
	if(Edit2 -> Text == "")
	{
		ShowMessage("������� ������������ �������!");
        return;
    }
	a = StrToInt(Edit1 -> Text);
	b = StrToInt(Edit2 -> Text);
	if(start.i > finish.i) swap(start.i , finish.i);
	if(start.j > finish.j) swap(start.j , finish.j);
	bool u = true;
	if(!((finish.i - start.i + 1 == a && finish.j - start.j + 1 == b) ||
		(finish.i - start.i + 1 == b && finish.j - start.j + 1 == a)))
	{
		ShowMessage("������������ �������!");
		return;
	}
	else
	{
		u = false;
		//Button1 -> Enabled = true;
		//Edit1 -> Text = "";
		//Edit2 -> Text = "";
    }
	//ofstream fout("log.txt");
	//fout << start.i << ' ' << start.j << '\n' << finish.i << ' ' << finish.j;
	if(check_fill(start , finish , hod))
	{
		fill(start , finish , hod);
	}
	else
	{
		u = false;
		ShowMessage("�����������!");
        return;
	}
	switch(hod)
	{
		case 'b':
		{
			hod = 'r';
			break;
		}
		case 'r':
		{
			hod = 'b';
			break;
		}
	}
	if(hod == 'r')
	{
		LabeledEdit1 -> Text = Form1 -> i1;
	}
	else
	{
        LabeledEdit1 -> Text = Form1 -> i2;
	}
	if(!u)
	{
       Button1 -> Enabled = true;
	   Edit1 -> Text = "";
	   Edit2 -> Text = "";
	}
	DrawGrid1 -> Refresh();
}

bool check_fill(pos s , pos f , char z)
{
	bool u = true;
	//�������� �� ����������� ����������
	for(int i = s.i ; i <= f.i ; i++)
	{
		for(int j = s.j ; j <= f.j ; j++)
		{
			u = u && (pole[i][j] == -1 || pole[i][j] == 0);
			if(!u) break;
		}
		if(!u) break;
	}
	if(!u) return false;
	//�������� �� �������������
	pos a , b;
	u = false;
	a = pos(s.i-1 , s.j-1);
	b = pos(f.i+1 , f.j+1);
	if(a.i >= 0)
	{
		for(int j = a.j+1 ; j < b.j ; j++)
		{
			 u = u || (pole[a.i][j] == z);
		}
		if(u) return true;
	}
	if(a.j >= 0)
	{
		for(int i = a.i+1 ; i < b.i ; i++)
		{
			u = u || (pole[i][a.j] == z);
		}
		if(u) return true;
	}
	if(b.i < Form1 -> m)
	{
		for(int j = a.j+1 ; j < b.j ; j++)
		{
			u = u || (pole[b.i][j] == z);
		}
		if(u) return true;
	}
	if(b.j < Form1 -> n)
	{
		for(int i = a.i+1 ; i < b.i ; i++)
		{
			u = u || (pole[i][b.j] == z);
		}
        if(u) return true;
    }
    return u;
}

void fill(pos s , pos f , char z)
{
	for(int i = s.i ; i <= f.i ; i++)
	{
		for(int j = s.j ; j <= f.j ; j++)
		{
			pole[i][j] = z;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	switch(pole[ARow][ACol])
	{
		case 'b':
		{
			DrawGrid1 -> Canvas -> StretchDraw(Rect , blue);
			break;
		}
		case 'r':
		{
			DrawGrid1 -> Canvas -> StretchDraw(Rect , red);
			break;
		}
		case -1:
		{
			DrawGrid1 -> Canvas -> StretchDraw(Rect , white);
			break;
		}
		case 0:
		{
			DrawGrid1 -> Canvas -> StretchDraw(Rect , purple);
			break;
		}
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	for(int i = 0 ; i < Form1 -> m ; i++)
	{
		for(int j = 0 ; j < Form1 -> n ; j++)
		{
            pole[i][j] = -1;
        }
	}
	pole[0][0] = 'r';
	pole[m-1][n-1] = 'b';
    hod = 'r';
	DrawGrid1 -> Refresh();
    LabeledEdit1 -> Text = Form1 -> i1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
	int cr = 0 , cb = 0;
	for(int i = 0 ; i < Form1 -> m ; i++)
	{
		for(int j = 0 ; j < Form1 -> n ; j++)
		{
			switch(pole[i][j])
			{
				case 'b':
				{
					cb++;
					break;
				}
				case 'r':
				{
					cr++;
					break;
                }
            }
        }
	}
	if(cr > cb)
	{
		ShowMessage(i1 + " �������");
	}
	else if(cr < cb)
		{
			ShowMessage(i2 + " �������");
		}
		else
		{
			ShowMessage("�����!");
		}
	if (MessageDlg("������ ����������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrNo)
	{
        BitBtn1 -> Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
	 Form2 -> Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
    Form3 -> Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
	if(DataModule4 -> SaveTextFileDialog1 -> Execute())
	{
		String s = DataModule4 -> SaveTextFileDialog1 -> FileName;
		ofstream fout(s.c_str());
        fout << Form1 -> m << ' ' << Form1 -> n << '\n';
		for(int i = 0 ; i < Form1 -> m ; i++)
		{
			for(int j = 0 ; j < Form1 -> n ; j++)
			{
				fout << pole[i][j] << ' ';
			}
			fout << '\n';
		}
		fout << hod;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
	if(DataModule4 -> OpenTextFileDialog1 -> Execute())
	{
		String s = DataModule4 -> OpenTextFileDialog1 -> FileName;
		ifstream fin(s.c_str());
		fin >> Form1 -> m >> Form1 -> n;
		for(int i = 0 ; i < Form1 -> m ; i++)
		{
			for(int j = 0 ; j < Form1 -> n ; j++)
			{
				fin >> pole[i][j];
            }
		}
		fin >> hod;
        DrawGrid1 -> Refresh();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
	Button1 -> Enabled = true;
    switch(hod)
	{
		case 'b':
		{
			hod = 'r';
			break;
		}
		case 'r':
		{
			hod = 'b';
			break;
		}
	}
}
//---------------------------------------------------------------------------

