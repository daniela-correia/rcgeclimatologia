void mg() {
   //Draw a simple graph
   // To see the output of this macro, click begin_html <a href="gif/graph.gif">here</a>. end_html
   //Author: Rene Brun


   TCanvas *c1 = new TCanvas("c1","Multigráfico:Temperatura virtual em função da altura",200,10,700,500);
   c1->SetFillColor(19);
   c1->SetGrid();
 
   Int_t n=0;
   const Int_t nlines = 1481;
   Double_t h1[nlines], h2[nlines], h3[nlines], h4[nlines], h5[nlines];
   Double_t T1[nlines], T2[nlines], T3[nlines], T4[nlines], T5[nlines];
   Double_t Tv1[nlines], Tv2[nlines], Tv3[nlines], Tv4[nlines], Tv5[nlines];
   Double_t P[nlines], d[nlines];
   Float_t hr,Tr,Pr,dr;

   //Criação do multigráfico
   TMultiGraph *mg = new TMultiGraph(); 
   
   // Rv= constante de gás para 1kg de vapor de água e Rd constante de gás para 1kg de ar seco
    Float_t Rv= 461.51;
    Float_t Rd= 287;
    // eps: 1-(Rd/Rv)
    Float_t eps= 0.378;
    // rho_d densidade parcial da massa de ar seco e rho_v densidade parcial de vapor de água
    Float_t rho_d= 1.275;
  
    //primeiro arquivo
    FILE *fp1 = fopen("Atmosphere.dat","r");
    //primeiro parâmetro de umidade
    Float_t rho_v= 0.00477; 
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
    	Tv1[n]= ((T1[n]*pr)/(pr-e*eps));
    	n++;
   }
   fclose(fp1);
   //Primeiro gráfico
   gr1 = new TGraph(n,h1,Tv1);
   gr1->SetLineColor(1);
   gr1->SetLineWidth(2);
   gr1->SetMarkerColor(1);
   gr1->SetMarkerStyle(1);
   gr1->SetTitle("Temperatura virtual em função da altitude");
   gr1->GetXaxis()->SetTitle("h (km)");
   gr1->GetYaxis()->SetTitle("Tv (K)");  
   mg->Add(gr1);
   //gr1->Draw("AP");
   
    //segundo arquivo
    FILE *fp2 = fopen("Atmosphere.dat","r");
    //segundo parâmetro de umidade
    Float_t rho_v= 0.00477*2; 
    n=0;
	while (n<nlines) {
    	fscanf(fp2, "%f %f %f %f",&hr,&Tr,&Pr,&dr);
    	//cout << xr << " " << yr << " " << wr << " " << zr << endl;
    	//convertendo temperatura para kelvin
    	h2[n]=hr;
    	T2[n]=Tr+273.15;
    	P[n]=Pr;
    	d[n]=dr;
    	// pd é a pressão parcial do ar seco e "e" é a pressão parcial do vapor de água
    	Float_t pd= rho_d*Rd*Tr;
    	Float_t e= rho_v*Rv*Tr;
    	Float_t pr= pd+e;
    	// Temperatura virtual
    	Tv2[n]= ((T2[n]*pr)/(pr-e*eps));
    	n++;
   }
   fclose(fp2);
   //Segundo gráfico
   gr2 = new TGraph(n,h2,Tv2);
   gr2->SetLineColor(2);
   gr2->SetLineWidth(2);
   gr2->SetMarkerColor(2);
   gr2->SetMarkerStyle(1);
   gr2->SetTitle("Temperatura virtual em função da altitude");
   gr2->GetXaxis()->SetTitle("h (km)");
   gr2->GetYaxis()->SetTitle("Tv (K)");   
   mg->Add(gr2);
   //gr2->Draw("AP");   
  
  
    //terceiro arquivo
    FILE *fp3 = fopen("Atmosphere.dat","r");
    //terceiro parâmetro de umidade
    Float_t rho_v= 0.00477*3; 
    n=0;
	while (n<nlines) {
    	fscanf(fp3, "%f %f %f %f",&hr,&Tr,&Pr,&dr);
    	//cout << xr << " " << yr << " " << wr << " " << zr << endl;
    	//convertendo temperatura para kelvin
    	h3[n]=hr;
    	T3[n]=Tr+273.15;
    	P[n]=Pr;
    	d[n]=dr;
    	// pd é a pressão parcial do ar seco e "e" é a pressão parcial do vapor de água
    	Float_t pd= rho_d*Rd*Tr;
    	Float_t e= rho_v*Rv*Tr;
    	Float_t pr= pd+e;
    	// Temperatura virtual
    	Tv3[n]= ((T3[n]*pr)/(pr-e*eps));
    	n++;
   }
   fclose(fp3);
   //terceiro gráfico
   gr3 = new TGraph(n,h3,Tv3);
   gr3->SetLineColor(3);
   gr3->SetLineWidth(2);
   gr3->SetMarkerColor(3);
   gr3->SetMarkerStyle(1);
   gr3->SetTitle("Temperatura virtual em função da altitude");
   gr3->GetXaxis()->SetTitle("h (km)");
   gr3->GetYaxis()->SetTitle("Tv (K)");  
   mg->Add(gr3);
   //gr1->Draw("AP");
   
    //quarto arquivo
    FILE *fp4 = fopen("Atmosphere.dat","r");
    //quarto parâmetro de umidade
    Float_t rho_v= 0.00477*4; 
    n=0;
	while (n<nlines) {
    	fscanf(fp4, "%f %f %f %f",&hr,&Tr,&Pr,&dr);
    	//cout << xr << " " << yr << " " << wr << " " << zr << endl;
    	//convertendo temperatura para kelvin
    	h4[n]=hr;
    	T4[n]=Tr+273.15;
    	P[n]=Pr;
    	d[n]=dr;
    	// pd é a pressão parcial do ar seco e "e" é a pressão parcial do vapor de água
    	Float_t pd= rho_d*Rd*Tr;
    	Float_t e= rho_v*Rv*Tr;
    	Float_t pr= pd+e;
    	// Temperatura virtual
    	Tv4[n]= ((T4[n]*pr)/(pr-e*eps));
    	n++;
   }
   fclose(fp4);
   //quarto gráfico
   gr4 = new TGraph(n,h4,Tv4);
   gr4->SetLineColor(4);
   gr4->SetLineWidth(2);
   gr4->SetMarkerColor(4);
   gr4->SetMarkerStyle(1);
   gr4->SetTitle("Temperatura virtual em função da altitude");
   gr4->GetXaxis()->SetTitle("h (km)");
   gr4->GetYaxis()->SetTitle("Tv (K)");   
   mg->Add(gr4);
   //gr2->Draw("AP");   
  
   
    //quinto arquivo
    FILE *fp5 = fopen("Atmosphere.dat","r");
    //quinto parâmetro de umidade
    Float_t rho_v= 0.00477*5; 
    n=0;
	while (n<nlines) {
    	fscanf(fp5, "%f %f %f %f",&hr,&Tr,&Pr,&dr);
    	//cout << xr << " " << yr << " " << wr << " " << zr << endl;
    	//convertendo temperatura para kelvin
    	h5[n]=hr;
    	T5[n]=Tr+273.15;
    	P[n]=Pr;
    	d[n]=dr;
    	// pd é a pressão parcial do ar seco e "e" é a pressão parcial do vapor de água
    	Float_t pd= rho_d*Rd*Tr;
    	Float_t e= rho_v*Rv*Tr;
    	Float_t pr= pd+e;
    	// Temperatura virtual
    	Tv5[n]= ((T5[n]*pr)/(pr-e*eps));
    	n++;
   }
   fclose(fp5);
   //quinto gráfico
   gr5 = new TGraph(n,h5,Tv5);
   gr5->SetLineColor(5);
   gr5->SetLineWidth(2);
   gr5->SetMarkerColor(5);
   gr5->SetMarkerStyle(1);
   gr5->SetTitle("Temperatura virtual em função da altitude");
   gr5->GetXaxis()->SetTitle("h (km)");
   gr5->GetYaxis()->SetTitle("Tv (K)");   
   mg->Add(gr5);
   //gr2->Draw("AP");   
  

   
   //define os eixos e o título do multigráfico
   mg->Draw("APL");
   mg->GetYaxis()->SetTitle("Temperatura virtual (K)");
   mg->GetXaxis()->SetTitle("Altitude (km)");
   mg->GetHistogram()->SetTitle("Temperatura virtual em função da altitude com diferentes densidades de vapor");
 
 //define a caixa de legendas
   leg = new TLegend(0.7,0.8,0.9,0.9);
   leg->AddEntry(gr1,"#rho_{v}=0.00477","l"); //chutei os valores de beta ok
   leg->AddEntry(gr2,"#rho_{v}=0.00954","l");
   leg->AddEntry(gr3,"#rho_{v}=0.01431","l");
   leg->AddEntry(gr4,"#rho_{v}=0.01908","l");
   leg->AddEntry(gr5,"#rho_{v}=0.02385","l");
   //leg->AddEntry(gr3,"#beta=0.99, r_{L}=436826.528 m","l");
   //leg->AddEntry(gr4,"#beta=0.999, r_{L}=1390783.211 m","l");
   leg->Draw();

 
 
   c1->Update();
   c1->GetFrame()->SetFillColor(0);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
}
