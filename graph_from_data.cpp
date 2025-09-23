void graph_from_data() {
   //Draw a simple graph
   // To see the output of this macro, click begin_html <a href="gif/graph.gif">here</a>. end_html
   //Author: Rene Brun
   
   TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

   c1->SetFillColor(10);
   c1->SetGrid();

   Int_t n=0;
   const Int_t nlines = 1481;
   Double_t h1[nlines],T1[nlines],Tv1[nlines]; 
   Double_t P[nlines], d[nlines];
   Float_t hr,Tr,Pr,dr;
   
   // Rv= constante de gás para 1kg de vapor de água e Rd constante de gás para 1kg de ar seco
    Float_t Rv= 461.51;
   	Float_t Rd= 287;
    // eps: Rd/Rv
    Float_t eps= 0.622;
    // rho_d densidade parcial da massa de ar seco e rho_v densidade parcial de vapor de água
    Float_t rho_d= 1.275;


    //primeiro parâmetro de umidade
    Float_t rho_v= 0.00477;
 
    FILE *fp1 = fopen("Atmosphere.dat","r");

	while (n<nlines) {

    fscanf(fp1, "%f %f %f %f",&hr,&Tr,&Pr,&dr);
    //cout << xr << " " << yr << " " << wr << " " << zr << endl;
    //convertendo temperatura para kelvin
    h1[n]=hr;
    T1[n]=Tr+273.15;
    P[n]=Pr;
    d[n]=dr;
    // pd é a pressão parcial do ar seco e "e" é a pressão parcial do vapor de água
    Float_t pd= rho_d*Rd*Tr;
    Float_t e= rho_v*Rv*Tr;
    Float_t pr= pd+e;
    // Temperatura virtual
    Tv1[n]= (T1[n])/(1-(e/pr)*(1-eps));
    n++;
   }
   fclose(fp1);
	   
   //Primeiro gráfico
   gr1 = new TGraph(n,h1,Tv1);
   gr1->SetLineColor(1);
   gr1->SetLineWidth(3);
   gr1->SetMarkerColor(kRed);
   gr1->SetMarkerStyle(6);
   gr1->SetTitle("Gráfico: Temperatura Virtual em função da altitude com densidade de vapor = 0.00477");
   gr1->GetXaxis()->SetTitle("Altitude (km)");
   gr1->GetYaxis()->SetTitle("Temperatura Virtual (K)");
   
   gr1->Draw("ALP"); 
   // TCanvas::Update() draws the frame, after which one can change it
   c1->Update();
   c1->GetFrame()->SetFillColor(10);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
}
