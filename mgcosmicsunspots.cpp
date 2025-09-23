#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mgCosmicSunspots(){
    gStyle->SetOptFit(0111);

    TCanvas *c1 = new TCanvas("c1","Raios Cósmicos x Manchas Solares",200,10,800,600);
    c1->SetFillColor(10);
    c1->SetGrid();

    const Int_t nlines = 668;

    // 1) Raios Cósmicos
    Int_t n1 = 0;
    Double_t x1[nlines], y1[nlines], ey1[nlines];
    Double_t fracDate1, uncRate, corRate, press, erro1;
    char line[256], timestamp[64];

    FILE *fp1 = fopen("Oulu_data1.csv","r");
    if (!fp1) { cout << "Erro ao abrir Oulu_data1.csv\n"; return 1; }
    fgets(line,sizeof(line),fp1); // pula cabeçalho

    while (fgets(line,sizeof(line),fp1) && n1 < nlines) {
        if (sscanf(line,"%[^,],%lf,%lf,%lf,%lf,%lf",
                   timestamp, &fracDate1, &uncRate, &corRate, &press, &erro1) == 6) {
            x1[n1] = fracDate1;
            y1[n1] = corRate/10;
            ey1[n1] = erro1;
            n1++;
        }
    }
    fclose(fp1);
    cout << "Pontos Raios Cósmicos: " << n1 << endl;

    TGraphErrors *gr1 = new TGraphErrors(n1,x1,y1,0,ey1);
    gr1->SetMarkerColor(kBlue);
    gr1->SetMarkerStyle(20);
    gr1->SetMarkerSize(0.6);
    gr1->SetTitle("Raios Cósmicos");

    // 2) Manchas Solares
    Int_t n2 = 0;
    Double_t x2[nlines], y2[nlines], ey2[nlines];
    Double_t year, month, fracDate2, manchas, erro2;

    FILE *fp2 = fopen("Sunspots_data1.csv","r");
    if (!fp2) { cout << "Erro ao abrir Sunspots_data1.csv\n"; return 1; }
    fgets(line,sizeof(line),fp2); // pula cabeçalho

    while (fgets(line,sizeof(line),fp2) && n2 < nlines) {
        if (sscanf(line,"%lf,%lf,%lf,%lf,%lf",
                   &year, &month, &fracDate2, &manchas, &erro2) == 5) {
            x2[n2] = fracDate2;
            y2[n2] = manchas;
            ey2[n2] = erro2;
            n2++;
        }
    }
    fclose(fp2);
    cout << "Pontos Manchas Solares: " << n2 << endl;

    TGraphErrors *gr2 = new TGraphErrors(n2,x2,y2,0,ey2);
    gr2->SetMarkerColor(kRed);
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerSize(0.6);
    gr2->SetTitle("Manchas Solares");

    // 3) MultiGráfico
    TMultiGraph *mg = new TMultiGraph();
    mg->Add(gr1);
    mg->Add(gr2);
    mg->SetTitle("Anticorrelação entre Raios Cósmicos e Manchas Solares");
    mg->Draw("AP");
    mg->GetXaxis()->SetTitle("Data fracionária");
    mg->GetYaxis()->SetTitle("Manchas solares/Raios cósmicos");
   

    // Legenda
    TLegend *legend = new TLegend(0.7,0.75,0.9,0.9);
    legend->AddEntry(gr1,"Raios Cósmicos observados divididos por 10","p");
    legend->AddEntry(gr2,"Média mensal de manchas solares","p");
    legend->Draw();

    c1->Update();
}
