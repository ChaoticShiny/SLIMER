{
	#include "TCanvas.h"
	#include "TRandom.h"
	#include "TH2.h"
	#include "TF2.h"
	#include "TMath.h"
	#include "TROOT.h"
	#include <fstream>
	#include <string>
	
	
	//C14
	
	TCanvas *c1 = new TCanvas("c1","14C",200,10,700,500);
	c1->SetGrid();
	
	const Int_t n = 4;
	Double_t x[n] = {984.9,6.857,45.15,109.9};
	Double_t ex[n] = {49.245,0.34285,2.2575,5.495};
	Double_t y[n] = {4969.,295.,452.,1208.};
	Double_t ey[n] = {70.4911341943,17.1755640373,21.2602916255,34.756294394};
	
	TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
	gr->SetLineColor(2);
	gr->SetLineWidth(3);
	gr->SetMarkerColor(4);
	gr->SetMarkerStyle(21);
	gr->SetTitle("14C");
	gr->GetXaxis()->SetTitle("Activity (nCi)");
	gr->GetYaxis()->SetTitle("Events per 10000 images");
	gr->GetXaxis()->SetLimits(-100,1100);
	gr->Draw("AP");
	gr->Fit("pol1","","",-100,1100);

	// TCanvas::Update() draws the frame, after which one can change it
	c1->Update();
	c1->GetFrame()->SetBorderSize(12);
	c1->Modified();
	
	
	//Am241
	
	TCanvas *c2 = new TCanvas("c2","241Am",200,10,700,500);
	c2->SetGrid();
	
	const Int_t n2 = 3;
	Double_t x2[n2] = {4.313,0.0299,0.4789};
	Double_t ex2[n2] = {0.21565,0.001495,0.023945};
	Double_t y2[n2] = {536,258,285};
	Double_t ey2[n2] = {23.1516738056,16.0623784042,16.8819430161};
	
	TGraphErrors *gr2 = new TGraphErrors(n2,x2,y2,ex2,ey2);
	gr2->SetLineColor(2);
	gr2->SetLineWidth(3);
	gr2->SetMarkerColor(4);
	gr2->SetMarkerStyle(21);
	gr2->SetTitle("241Am");
	gr2->GetXaxis()->SetTitle("Activity (nCi)");
	gr2->GetYaxis()->SetTitle("Events per 10000 images");
	gr2->GetXaxis()->SetLimits(-0.5,5);
	gr2->Draw("AP");
	gr2->Fit("pol1","","",-0.5,5);
	
	c2->Update();
	c2->GetFrame()->SetBorderSize(12);
	c2->Modified();
	
	
	//both
	
	TCanvas *c3 = new TCanvas("c3","both",200,10,700,500);
	c3->SetGrid();
	
	const Int_t n3 = 7;
	Double_t x3[n3] = {984.9,6.857,45.15,109.9,4.313,0.0299,0.4789};
	Double_t ex3[n3] = {49.245,0.34285,2.2575,5.495,0.21565,0.001495,0.023945};
	Double_t y3[n3] = {4969.,295.,452.,1208.,536,258,285};
	Double_t ey3[n3] = {70.4911341943,17.1755640373,21.2602916255,34.756294394,23.1516738056,16.0623784042,16.8819430161};
	
	TGraphErrors *gr3 = new TGraphErrors(n3,x3,y3,ex3,ey3);
	gr3->SetLineColor(2);
	gr3->SetLineWidth(3);
	gr3->SetMarkerColor(4);
	gr3->SetMarkerStyle(21);
	gr3->SetTitle("both");
	gr3->GetXaxis()->SetTitle("Activity (nCi)");
	gr3->GetYaxis()->SetTitle("Events per 10000 images");
	gr3->GetXaxis()->SetLimits(-100,1100);
	gr3->Draw("AP");
	gr3->Fit("pol1","","",-100,1100);
	
	c3->Update();
	c3->GetFrame()->SetBorderSize(12);
	c3->Modified();
}