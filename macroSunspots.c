#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Sunspots(){
    gStyle -> SetOptFit (0111);

    TCanvas* c = new TCanvas();
    c->SetGrid();
    FILE *fpi = fopen("Sunspots_data1.csv", "r");

    const Int_t nlines = 668;
    Int_t n = 0; 
    Float_t x[nlines]; // eixo x = FractionalDate
    Float_t y[nlines]; // eixo y = manchas solares
    Float_t ey[nlines]; // erro em y = raiz das contagens

    Float_t year, month, datafrac, manchas, erro;
    char line[256];

    fgets(line, sizeof(line), fpi); // pula cabeçalho

    while (n < nlines) {
        if (!fgets(line, sizeof(line), fpi)) break;

        // Lê as 5 colunas
        if (sscanf(line, "%f,%f,%f,%f,%f",
                   &year, &month, &datafrac, &manchas, &erro) == 5) {

            cout << year << " "
                 << month << " "
                 << datafrac << " "
                 << manchas << " "
                 << erro << endl;

            x[n]  = datafrac;
            y[n]  = manchas;
            ey[n] = erro;
            n++;
        }
    }

    TGraphErrors *gr = new TGraphErrors(n, x, y, 0, ey);
    gr->SetLineColor(95);
    gr->SetLineWidth(1);
    gr->SetMarkerColor(95);
    gr->SetMarkerStyle(20); 
    gr->SetMarkerSize(0.6);
    gr->SetTitle("Número de manchas solares");
    gr->GetXaxis()->SetTitle("Data fracionária");
    gr->GetXaxis()->SetTitleSize(0.04);
    gr->GetYaxis()->SetTitle("Média mensal de manchas solares");
    gr->GetYaxis()->SetTitleSize(0.04);

    gr->Draw("AP");
}
