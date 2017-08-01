{
gROOT->SetStyle("Plain");
gStyle->SetOptStat(0000000);
gStyle->SetOptTitle(kFALSE);


#include "TCanvas.h"
#include "TRandom.h"
#include "TH2.h"
#include "TF2.h"
#include "TMath.h"
#include "TROOT.h"
#include <fstream>
#include <string>

// Tfile "f" and "ff" are for comparing standard simulation runs. File "fff" is to be used for Sr+Y runs.

TFile *f = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/10k-runs/C-150.root");
TFile *ff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/5k-runs/Cs-150.root");
//TFile *fff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/10k-runs/Sr+Y-45.root");
//TFile *ffff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/10k-runs/Sr+Y-150.root");
TFile *fff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/Sr+Y/10k-runs/Sr+Y-150-regular.root");
TFile *ffff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/Sr+Y/10k-runs/Sr+Y-150-gap.root");
TFile *f2 = new TFile("/Volumes/MY PASSPORT/Run175_1/Results-175_1+176_1+177_1+178_1-th170.root");
TFile *f3 = new TFile("/Volumes/MY PASSPORT/Run104_1/Results-104_1-th170.root");
TFile *f4 = new TFile("/Volumes/MY PASSPORT/Run159_1/Results-159_1-th170.root");


TTree *t = (TTree*)f->Get("file");  //simulation
TTree *tt = (TTree*)ff->Get("file"); //simulation
TTree *t2 = (TTree*)f2->Get("ntuple");  //data
TTree *t3 = (TTree*)f3->Get("ntuple");  //data
TTree *t4 = (TTree*)f4->Get("ntuple");  //data


int n = t->GetEntries();
int nn = tt->GetEntries(); 
int n2 = t2->GetEntries();
int n3 = t3->GetEntries();
int n4 = t4->GetEntries();


double pEn, eAbsorbed, pEn2, eAbsorbed2;
float intden_2, intden_3, intden_4;

t->SetBranchAddress("PrimaryEn", &pEn);
t->SetBranchAddress("Eabs", &eAbsorbed);

tt->SetBranchAddress("PrimaryEn", &pEn2);
tt->SetBranchAddress("Eabs", &eAbsorbed2);

t2->SetBranchAddress("intden2",&intden_2);
t3->SetBranchAddress("intden2", &intden_3);
t4->SetBranchAddress("intden2", &intden_4);
//-------------------------------------------------------------------------------------------

	TH1D *hEn = new TH1D("hEn","Energy Absorbed",500,0,3500);
	TH1D *hEn2 = new TH1D("hEn2","Energy Absorbed",500,0,3500);
	TH1D *hEn3 = (TH1D*)fff->Get("hEabs");
	TH1D *hEn4 = (TH1D*)ffff->Get("hEabs");
	
	TH1F *hIntden2 = new TH1F("hIntden2","Intden of Event Peak in Data Set 1",500,0,65000);
	TH1F *hIntdenCal2 = new TH1F("hIntdenCal2","Cal Intden of Event Peak in Data Set 1",500,0,1500);
	
	TH1F *hIntden3 = new TH1F("hIntden3","Intden of Event Peak in Data Set 2",500,0,65000);
	TH1F *hIntdenCal3 = new TH1F("hIntdenCal3","Cal Intden of Event Peak in Data Set 2",500,0,1500);
	
	TH1F *hIntden4 = new TH1F("hIntden4","Intden of Event Peak in Data Set 3",500,0,65000);
	TH1F *hIntdenCal4 = new TH1F("hIntdenCal4","Cal Intden of Event Peak in Data Set 3",500,0,1500);	


//-------------------------------------------------------------------------------------------
	
	for(int i = 0; i<n; i++) {
		t->GetEntry(i);
		if (eAbsorbed > 0) 
			hEn->Fill(eAbsorbed);
	}


	for (int i=0; i<nn; i++) {
		tt->GetEntry(i);
		if (eAbsorbed2 > 0)
			hEn2->Fill(eAbsorbed2);
	}

//-------------------------------------------------------------------------------------------

	
	for (int x = 0; x < n2; x++) {
		t2->GetEntry(x);
		hIntden2->Fill(intden_2);
//		hIntdenCal2->Fill(intden2*2+.5);
		}
	
//-------------------------------------------------------------------------------------------


	for (int x = 0; x < n3; x++) {
		t3->GetEntry(x);
		hIntden3->Fill(intden_3);
//		hIntdenCal3->Fill(intden3*2+.5);
		}

//-------------------------------------------------------------------------------------------

	
	for (int x = 0; x < n4; x++) {
		t4->GetEntry(x);
		hIntden4->Fill(intden_4);
//		hIntdenCal4->Fill(intden4*2+.5);
		}
	
//-------------------------------------------------------------------------------------------

	// This segment compares simulation to peak base area

	new TCanvas();

	hEn->SetLineWidth(2);
	hEn2->SetLineWidth(2);
	hEn3->SetLineWidth(2);

	hIntden2->SetLineWidth(1);
	hIntdenCal2->SetLineWidth(1);
	hIntden3->SetLineWidth(1);
	hIntdenCal3->SetLineWidth(1);
	hIntden4->SetLineWidth(1);
	hIntdenCal4->SetLineWidth(1);

	hEn->SetXTitle("Energy (keV)");
	hEn->SetYTitle("Counts per 3 keV");
	hEn->SetLineColor(3);
//	hEn->Draw();
	//hEn->Fit(function,"W","SAME",0,400);
	
	hEn2->SetLineColor(11);
//	hEn2->Draw("same");

	hEn3->SetLineColor(3);
	hEn3->Draw("same");

	hEn4->SetLineColor(14);
	hEn4->Draw("same");

	hIntden2->SetLineColor(4);
//	hIntden2->Draw("same");

//	hIntdenCal2->SetLineColor(12);
//	hIntdenCal2->Draw("same");

	hIntden3->SetLineColor(6);
//	hIntden3->Draw("same");

//	hIntdenCal3->SetLineColor(7);
//	hIntdenCal3->Draw("same");

	hIntden4->SetLineColor(13);
//	hIntden4->Draw("same");

//	hIntdenCal4->SetLineColor(9);
//	hIntdenCal4->Draw("same");


	TLegend *legend3 = new TLegend(.75,.80,.95,.95);
//	legend3->AddEntry(hEn,"Simulation - C");
//	legend3->AddEntry(hEn2,"Simulation - Cs");
	legend3->AddEntry(hEn3,"Simulation - Sr+Y - 45 um");
	legend3->AddEntry(hEn4,"Simulation - Sr+Y - 150 um");
//	legend3->AddEntry(hIntden2,"Run 175 + 176 + 178 + 179");
//	legend3->AddEntry(hIntdenCal2,"Calibrated experimental data #1");
//	legend3->AddEntry(hIntden3,"Run 104");
//	legend3->AddEntry(hIntdenCal3,"Calibrated experimental data #2");
//	legend3->AddEntry(hIntden4,"Run 159");
//	legend3->AddEntry(hIntdenCal4,"Calibrated 8x8 binning");
	legend3->SetFillColor(0);
	legend3->Draw("same");

/*
	double integral9 = hIntden2->Integral(0,1500);
//	double integral10 = hIntdenCal2->Integral(0,1500);
	double integral11 = hIntden3->Integral(0,1500);
//	double integral12 = hIntdenCal3->Integral(0,1500);

	cout << "Integral of hIntden2: " << integral9 << endl;
//	cout << "Integral of hIntdenCal2: " << integral10 << endl;	
	cout << "Integral of hIntden3: " << integral11 << endl;
//	cout << "Integral of hIntdenCal3: " << integral12 << endl;
*/	

	gPad->SetLogy();

}