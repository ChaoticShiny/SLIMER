{
	//NOTE: When fitting an exponential function to a graph, root gives two parameters. They fit into an equation like this: y = exp(a + bx). 
	
	
	#include "TCanvas.h"
	#include "TRandom.h"
	#include "TH2.h"
	#include "TF2.h"
	#include "TMath.h"
	#include "TROOT.h"
	#include <fstream>
	#include <string>
	
/*	TCanvas *c1 = new TCanvas("c1","primaryEn",200,10,700,500);
	c1->SetGrid();
	
	const Int_t n = 3;
	Double_t x[n] = {350.,1020.,1358.}; //endpoint gray value for C, Cs, Sr-Y
	Double_t ex[n] = {20.,34.641,32.404};
	Double_t y[n] = {156.,500.,2260}; //endpoint energy for C, Cs, Sr-Y (Cs is an estimate)
	Double_t ey[n] = {12.490,34.059,47.539};
	
	TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
	gr->SetLineColor(2);
	gr->SetLineWidth(3);
	gr->SetMarkerColor(4);
	gr->SetMarkerStyle(21);
	gr->SetTitle("primaryEn");
	gr->GetXaxis()->SetTitle("Gray value (data)");
	gr->GetYaxis()->SetTitle("primaryEn (keV) (simulation)");
	gr->GetXaxis()->SetLimits(0,1600);
	gr->GetYaxis()->SetLimits(0,5500);
	gr->Draw("AP");
	//gr->Fit("pol1","","",0,1600);

	// TCanvas::Update() draws the frame, after which one can change it
	c1->Update();
	c1->GetFrame()->SetBorderSize(12);
	c1->Modified();
*/
	
	
	
	TCanvas *c2 = new TCanvas("c2","eAbs, endpoint by eye, data set 1",200,10,700,500);
	c2->SetGrid();
	
	const Int_t n2 = 3;
	Double_t x2[n2] = {350.,1020.,1358.}; //endpoint gray value for C, Cs, Sr-Y
	Double_t ex2[n2] = {20.,34.641,32.404};
	Double_t y2[n2] = {143.,518.5,796.}; //endpoint energy for C, Cs, Sr-Y
	Double_t ey2[n2] = {11.958,22.771,28.213};
	
	TGraphErrors *gr2 = new TGraphErrors(n2,x2,y2,ex2,ey2);
	gr2->SetLineColor(2);
	gr2->SetLineWidth(3);
	gr2->SetMarkerColor(4);
	gr2->SetMarkerStyle(21);
	gr2->SetTitle("eAbs, endpoint by eye, data set 1");
	gr2->GetXaxis()->SetTitle("Gray value (data)");
	gr2->GetYaxis()->SetTitle("eAbs (keV) (simulation)");
	gr2->GetXaxis()->SetLimits(0,1400);
	gr2->Draw("AP");
	gr2->Fit("pol1","","",0,1400);
	
	c2->Update();
	c2->GetFrame()->SetBorderSize(12);
	c2->Modified();
	
	
	
	TCanvas *c3 = new TCanvas("c3","eAbs, endpoint by fit, data set 1",200,10,700,500);
	c3->SetGrid();
	
	const Int_t n3 = 3;
	Double_t x3[n3] = {450.148,1577.528,1332.300}; //endpoint gray value for C, Cs, Sr-Y
	Double_t ex3[n3] = {21.217,39.718,36.501};
	Double_t y3[n3] = {151.5,452.,716.}; //endpoint energy for C, Cs, Sr-Y
	Double_t ey3[n3] = {12.308,21.260,28.758};
	
	TGraphErrors *gr3 = new TGraphErrors(n3,x3,y3,ex3,ey3);
	gr3->SetLineColor(2);
	gr3->SetLineWidth(3);
	gr3->SetMarkerColor(4);
	gr3->SetMarkerStyle(21);
	gr3->SetTitle("eAbs, endpoint by fit, data set 1");
	gr3->GetXaxis()->SetTitle("Gray value (data)");
	gr3->GetYaxis()->SetTitle("eAbs (keV) (simulation)");
//	gr3->GetXaxis()->SetLimit(0,1400);
	gr3->Draw("AP");
	gr3->Fit("pol1","","",0,1600);
	
	c3->Update();
	c3->GetFrame()->SetBorderSize(12);
	c3->Modified();
	
	
	
	TCanvas *c4 = new TCanvas("c4","eAbs, endpoint by fit, data set 2",200,10,700,500);
	c4->SetGrid();
	
	const Int_t n4 = 3;
	Double_t x4[n4] = {421.072,1024.241,1574.439}; //endpoint gray value for C, Cs, Sr-Y
	Double_t ex4[n4] = {20.520,32.004,36.679};
	Double_t y4[n4] = {151.5,452.,716.}; //endpoint energy for C, Cs, Sr-Y
	Double_t ey4[n4] = {12.308,21.260,28.758};
	
	TGraphErrors *gr4 = new TGraphErrors(n4,x4,y4,ex4,ey4);
	gr4->SetLineColor(2);
	gr4->SetLineWidth(3);
	gr4->SetMarkerColor(4);
	gr4->SetMarkerStyle(21);
	gr4->SetTitle("eAbs, endpoint by fit, data set 2");
	gr4->GetXaxis()->SetTitle("Gray value (data)");
	gr4->GetYaxis()->SetTitle("eAbs (keV) (simulation)");
//	gr4->GetXaxis()->SetLimit(0,1400);
	gr4->Draw("AP");
	gr4->Fit("pol1","","",0,1600);
	
	c4->Update();
	c4->GetFrame()->SetBorderSize(12);
	c4->Modified();
	
	
	
	TCanvas *c5 = new TCanvas("c5","eAbs, endpoint by fit, data set 3",200,10,700,500);
	c5->SetGrid();
	
	const Int_t n5 = 3;
	Double_t x5[n5] = {474.700,922.262,1395.243}; //endpoint gray value for C, Cs, Sr-Y
	Double_t ex5[n5] = {21.788,30.369,37.353};
	Double_t y5[n5] = {151.5,452.,716.}; //endpoint energy for C, Cs, Sr-Y
	Double_t ey5[n5] = {12.308,21.260,28.758};
	
	TGraphErrors *gr5 = new TGraphErrors(n5,x5,y5,ex5,ey5);
	gr5->SetLineColor(2);
	gr5->SetLineWidth(3);
	gr5->SetMarkerColor(4);
	gr5->SetMarkerStyle(21);
	gr5->SetTitle("eAbs, endpoint by fit, data set 3");
	gr5->GetXaxis()->SetTitle("Gray value (data)");
	gr5->GetYaxis()->SetTitle("eAbs (keV) (simulation)");
//	gr5->GetXaxis()->SetLimit(0,1400);
	gr5->Draw("AP");
	gr5->Fit("pol1","","",0,1600);
	
	c5->Update();
	c5->GetFrame()->SetBorderSize(12);
	c5->Modified();
}