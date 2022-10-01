//---------------------------------------------------------------------------
// Projekt wykona³ Przemys³aw Paw³owski ©
#include <vcl.h>
#pragma hdrstop
#include <math.hpp>
#include <time.h>
#include <cstdlib>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PERFGRAP"
#pragma resource "*.dfm"
TForm1 *Form1;
        int tab [40][40];
        int tymczasowa_tab [40][40];
        int tymczasowi_sasiedzi;
        int suma = 0, pamiec;
        int suma_zywych_komorek = 0;
        int warunek1, warunek2, warunek3;
        float czas;
        int ilosc_komorek1, ilosc_komorek2, ilosc_komorek3, ilosc_komorek4, ilosc_komorek5;
        int narodzone_komorki = 0;
        int zabite_komorki = 0;
        float ilosc_sekund = 0, suma2 = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Form1 -> Width = 878;
        Form1 -> Height = 525;
}

//---------------------------------------------------------------
int ile_sasiadow( int x, int y)
{
        suma = tab[x-1][y-1] + tab[x][y-1] +
        tab[x+1][y-1] + tab[x-1][y] +
        tab[x+1][y] + tab[x-1][y+1] +
        tab[x][y+1] + tab[x+1][y+1];
        return suma;
}
//---------------------------------------------------------------

void wypelnienie_tablicy_zerami()
{
        for (int i=0; i<=39; ++i)
        {
                for (int j=0; j<=39; ++j)
                {
                tab [i][j]=0;
                }
        }
}
//---------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        try
        {
        czas = StrToFloat(Edit6 -> Text);
        Timer1 -> Interval = czas*1000;
        Timer2 -> Interval = czas*1000;
        pamiec = StrToFloat(Edit1 -> Text);
        srand( time( NULL ) );
        wypelnienie_tablicy_zerami();

        warunek1 = StrToFloat(Edit3 -> Text);
        warunek2 = StrToFloat(Edit4 -> Text);
        warunek3 = StrToFloat(Edit5 -> Text);
        if (warunek1 <=8 && warunek2 <=8 && warunek3 <=8)
        {
                for (int k=0; k<pamiec; k++)
                {
                int i,j;
                i = rand()%38+1;
                j = rand()%38+1;   // Losowanie ¿ywych komórek
                tab[i][j]=1;
                }
                DrawGrid -> Refresh();
        }
        else
        {
        Application -> MessageBox( "Poda³eœ zbyt du¿¹ liczbê (max 8)", MB_OK);
        }

        }
        catch(...)
        {
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if (Timer1 -> Enabled == true)
        {
        Timer2 -> Enabled = false;
        Timer1 -> Enabled = false;
        CheckBox1 -> Caption = "Stop";
        CheckBox1 -> Color = clRed;
        CheckBox1 -> Checked = true;
        suma_zywych_komorek = 0;
        }
        else
        {
        Timer2 -> Enabled = true;
        Timer1 -> Enabled = true;
        CheckBox1 -> Caption = "Start";
        CheckBox1 -> Color = clLime;
        CheckBox1 -> Checked = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Edit2 -> Text = suma_zywych_komorek;
        ilosc_komorek5 = ilosc_komorek4;
        ilosc_komorek4 = ilosc_komorek3;
        ilosc_komorek3 = ilosc_komorek1;
        ilosc_komorek1 = StrToFloat(Edit2 -> Text);
        suma_zywych_komorek = 0;
        for (int i=1; i<39; ++i)
        {
                for (int j=1; j<39; ++j)
                {
                tymczasowi_sasiedzi = ile_sasiadow(i,j);
                if( tab[i][j] == 1)
                {
                if(  tymczasowi_sasiedzi < warunek1 || tymczasowi_sasiedzi > warunek2)
                tab[i][j] = 0;
                }
                else
                {
                if( tymczasowi_sasiedzi <= warunek3 && tymczasowi_sasiedzi >= warunek3)
                tab[i][j] = 1;
                }
                }
        }
        DrawGrid->Refresh();

        for (int i=0; i<=39; ++i)
        {
                for (int j=0; j<=39; ++j)
                {
                        if (tab[i][j] == 1)
                        {
                        suma_zywych_komorek ++;
                        }
                }
        }
        PerformanceGraph1->DataPoint(clSkyBlue,suma_zywych_komorek);
        PerformanceGraph1->Update();
        Edit2 -> Text = suma_zywych_komorek;
        ilosc_komorek2 = StrToFloat(Edit2 -> Text);

         if (ilosc_komorek1 == ilosc_komorek2 && ilosc_komorek1 == ilosc_komorek3
         && ilosc_komorek1 == ilosc_komorek4 && ilosc_komorek2 == ilosc_komorek5)
        {
         Timer1 -> Enabled = false;
         Timer2 -> Enabled = false;
         narodzone_komorki =suma_zywych_komorek - pamiec ;
         zabite_komorki = pamiec - suma_zywych_komorek ;
         if (zabite_komorki < 0)
         {
         zabite_komorki = 0;
         }
         else if (narodzone_komorki < 0)
         {
          narodzone_komorki = 0;
         }

         ShowMessage("Podany uk³ad uzyska³ stabilnoœæ. \n"
                     "Dane: \n "
                     "\n Iloœæ pocz¹tkowa komórek: "
                     + AnsiString("\"") + Edit1->Text + AnsiString("\"") +
                     "\n Iloœæ narodzonych komórek: "
                     + AnsiString("\"") + narodzone_komorki + AnsiString("\"") +
                     "\n Iloœæ zabitych komórek: "
                     + AnsiString("\"") + zabite_komorki + AnsiString("\"") +
                     "\n Iloœæ koñcowa komórek: "
                     + AnsiString("\"") + Edit2->Text + AnsiString("\"") +
                     "\n Czas po jakim uk³ad uzyska³ stabilnoœæ: "
                     + AnsiString("\"") + RoundTo(suma2, -5) + AnsiString("\"") +
                     " sec"
                     "\n Czêstotliwoœæ odœwie¿ania: 1 proces/"
                     + AnsiString("\"") + Edit6->Text + AnsiString("\"") +
                     "sec"
                     );
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGridDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
        if(tab[ARow][ACol] == 1)                   //Je¿eli komórka ¿yje, to nadaj jej kolor
        {
        DrawGrid -> Canvas -> Brush -> Color = clGreen; //Ustawienie koloru komórek
        DrawGrid -> Canvas -> Rectangle(Rect);        // Wype³nienie pola kolorem
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        wypelnienie_tablicy_zerami();
        DrawGrid -> Refresh();
        PerformanceGraph1->DataPoint(clRed,1000);
        PerformanceGraph1->Update();
        suma_zywych_komorek = 0;
        Timer2 -> Enabled = false;
        suma2 = 0;
        ilosc_sekund = 0; 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
        ilosc_sekund += StrToFloat(Edit6 -> Text);
        suma2 = ilosc_sekund;
        Label1 -> Caption = RoundTo(suma2, -5);
        ilosc_sekund = suma2 ;
}
//---------------------------------------------------------------------------
// Projekt wykona³ Przemys³aw Paw³owski ©











