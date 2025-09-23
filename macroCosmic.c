#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int macroCosmic(){
    gStyle -> SetOptFit (0111);

    TCanvas* c=new TCanvas();
    c->SetGrid();
    FILE *fpi = fopen ("Oulu_data1.csv", "r");

    const Int_t nlines = 668;
    Int_t n = 0; 
    Float_t x[nlines];
    Float_t y[nlines];
    Float_t ey[nlines];
    Float_t FractionalDate, UncorrectedCountRate, CorrectedCountRate, Pressure, erro;
    char line[256];
    char timestamp[64];

    fgets(line,sizeof(line),fpi); // pula cabeçalho

    while (n < nlines) {
        if (!fgets(line, sizeof(line), fpi)) break;

        if (sscanf(line, "%[^,],%f,%f,%f,%f,%f,%f", 
                   timestamp, 
                   &FractionalDate, 
                   &UncorrectedCountRate, 
                   &CorrectedCountRate, 
                   &Pressure, 
                   &erro) == 6) {   // garante que leu tudo certo

            cout << timestamp << " " 
                 << FractionalDate << " " 
                 << UncorrectedCountRate << " " 
                 << CorrectedCountRate << " " 
                 << Pressure << " " 
                 << erro << endl;

            x[n]  = FractionalDate;
            y[n]  = CorrectedCountRate;
            ey[n] = erro;
            n++;
        }
    }
    TGraphErrors *gr = new TGraphErrors (n, x, y, 0, ey);
    gr->SetLineColor(54);
    gr->SetLineWidth(1);
    gr->SetMarkerColor(54);
    gr->SetMarkerStyle(1);
    gr->SetTitle("Gráfico de raios cósmicos observados entre 1964 e 2019");
    gr->GetXaxis()-> SetTitle("Data fracionária");
    gr->GetXaxis()-> SetTitleSize(0.04);
    gr->GetYaxis()-> SetTitle("média mensal de RCG [cts/min]");
    gr->GetYaxis()-> SetTitleSize(0.04);

    gr->Draw("AP"); // desenha o gráfico
}
