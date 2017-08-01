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

// Get Simulation files
TFile *f = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/20k-runs/C-150.root");
TFile *f2 = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/10k-runs/Cs-150.root");
TFile *f3 = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/Sr+Y/40k-runs/Sr+Y-45-gap.root");
TFile *f4 = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/Sr+Y/40k-runs/Sr+Y-150-gap.root");
TFile *f5 = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/Am-150.root");

// Get Data files
TFile *ff = new TFile("/Volumes/MY PASSPORT/Run107_1/Results-107_1-th170.root");
TFile *ff2 = new TFile("/Volumes/MY PASSPORT/Run098_1/Results-098_1-th170.root");
TFile *ff3 = new TFile("/Volumes/MY PASSPORT/Run173_1/Results-173_1-partial-th170.root");
TFile *ff4 = new TFile("/Volumes/MY PASSPORT/Run180_1/Results-180_1+181_1+182_1-th170.root");


TTree *t = (TTree*)f->Get("file");
TTree *t2 = (TTree*)f2->Get("file");
TTree *t5 = (TTree*)f5->Get("file");
TTree *tt = (TTree*)ff->Get("ntuple");
TTree *tt2 = (TTree*)ff2->Get("ntuple");
TTree *tt3 = (TTree*)ff3->Get("ntuple");
TTree *tt4 = (TTree*)ff4->Get("ntuple");

int n = t->GetEntries();
int n2 = t2->GetEntries();
int n5 = t5->GetEntries();
int nn = tt->GetEntries();
int nn2 = tt2->GetEntries();
int nn3 = tt3->GetEntries();
int nn4 = tt4->GetEntries();

double pEn, eAbsorbed, pEn2, eAbsorbed2, pEn5, eAbsorbed5;
float max, max2, max3, max4;

t->SetBranchAddress("PrimaryEn", &pEn);
t->SetBranchAddress("Eabs", &eAbsorbed);

t2->SetBranchAddress("PrimaryEn", &pEn2);
t2->SetBranchAddress("Eabs", &eAbsorbed2);

t5->SetBranchAddress("PrimaryEn", &pEn5);
t5->SetBranchAddress("Eabs", &eAbsorbed5);

tt->SetBranchAddress("max", &max);
tt2->SetBranchAddress("max", &max2);
tt3->SetBranchAddress("max", &max3);
tt4->SetBranchAddress("max", &max4);

//-----------------------------------------------------------------------------------

// Create histograms
	TH1D *hEn = new TH1D("hEn","Energy absorbed - Carbon", 500,0,1500);
	TH1D *hEn2 = new TH1D("hEn2","Energy absorbed - Cesium", 500,0,1500);
	TH1D *hEn3 = (TH1D*)f3->Get("hEabs");
	TH1D *hEn4 = (TH1D*)f4->Get("hEabs");
	TH1D *hEn5 = new TH1D("hEn5","Energy absorbed - Americium",500,0,1500);

	TH1D *hEnThresh = new TH1D("hEnThresh", "Energy absorbed - threshold - Carbon", 500,0,1500);
	TH1D *hEnThresh2 = new TH1D("hEnThresh2", "Energy absorbed - threshold - Cesium", 500,0,1500);
	TH1D *hEnThresh3 = new TH1D("hEnThresh3", "Energy absorbed - threshold - Strontium", 500,0,1500);
	TH1D *hEnThresh4 = new TH1D("hEnThresh4", "Energy absorbed - threshold - Strontium", 500,0,1500);
	TH1D *hEnThresh5 = new TH1D("hEnThresh5", "Energy absorbed - threshold - Americium", 500,0,1500);

	TH1D *hEnCal = new TH1D("hEnCal", "Energy absorbed - calibrated - Carbon", 500,0,1500);
	TH1D *hEnCal2 = new TH1D("hEnCal2", "Energy absorbed - calibrated - Cesium", 500,0,1500);
	TH1D *hEnCal3 = new TH1D("hEnCal3", "Energy absorbed - calibrated - Strontium", 500,0,1500);
	TH1D *hEnCal4 = new TH1D("hEnCal4", "Energy absorbed - calibrated - Strontium", 500,0,1500);
	TH1D *hEnCal5 = new TH1D("hEnCal5", "Energy absorbed - calibrated - Americium", 500,0,1500);

	TH1D *hEnScale = new TH1D("hEnScale", "Calibrated energy absorbed - Scaled - Carbon", 500,0,1500);
	TH1D *hEnScale2 = new TH1D("hEnScale2","Calibrated energy absorbed - Scaled - Cesium", 500,0,1500);
	TH1D *hEnScale3 = new TH1D("hEnScale3","Calibrated energy absorbed - Scaled - Strontium", 500,0,1500);
	TH1D *hEnScale4 = new TH1D("hEnScale4","Calibrated energy absorbed - Scaled - Strontium", 500,0,1500);
	TH1D *hEnScale5 = new TH1D("hEnScale5","Calibrated energy absorbed - Scaled - Americium", 500,0,1500);

	TH1F *hMax = new TH1F("hMax","Peak height of carbon events",500,0,1500);
	TH1F *hMax2 = new TH1F("hMax2","Peak height of Cesium events",500,0,1500);
	TH1F *hMax3 = new TH1F("hMax3","Peak height of Strontium events", 500,0,1500);
	TH1F *hMax4 = new TH1F("hMax4","Peak height of Americium events", 500,0,1500);

//-----------------------------------------------------------------------------------

// Fill base energy histograms
	for(int i = 0; i < n; i++) {
		t->GetEntry(i);
		if(eAbsorbed > 0)
			hEn->Fill(eAbsorbed);
	}

	for(int i = 0; i < n2; i++) {
		t2->GetEntry(i);
		if(eAbsorbed2 > 0)
			hEn2->Fill(eAbsorbed2);
	}

	for(int i = 0; i < n5; i++) {
		t5->GetEntry(i);
		if(eAbsorbed5 > 0)
			hEn5->Fill(eAbsorbed5);
	}

//-----------------------------------------------------------------------------------

// Fill energy-threshold histograms
	
	// Set Energy Threshold
	double EnergyThreshold = 6;

	for(int i = 0; i < hEn->GetNbinsX(); i++) {
		if(hEn->GetBinCenter(i) < EnergyThreshold) continue;
		else hEnThresh->SetBinContent(i-EnergyThreshold, hEn->GetBinContent(i));
	}

	for(int i = 0; i < hEn2->GetNbinsX(); i++) {
		if(hEn2->GetBinCenter(i) < EnergyThreshold) continue;
		else hEnThresh2->SetBinContent(i-EnergyThreshold, hEn2->GetBinContent(i));
	}

	for(int i = 0; i < hEn3->GetNbinsX(); i++) {
		if(hEn3->GetBinCenter(i) < EnergyThreshold) continue;
		else hEnThresh3->SetBinContent(i-EnergyThreshold, hEn3->GetBinContent(i));
	}

	for(int i = 0; i < hEn4->GetNbinsX(); i++) {
		if(hEn4->GetBinCenter(i) < EnergyThreshold) continue;
		else hEnThresh4->SetBinContent(i-EnergyThreshold, hEn4->GetBinContent(i));
	}

	for(int i = 0; i < hEn5->GetNbinsX(); i++) {
		if(hEn5->GetBinCenter(i) < EnergyThreshold) continue;
		else hEnThresh5->SetBinContent(i-EnergyThreshold, hEn5->GetBinContent(i));
	}

//-----------------------------------------------------------------------------------

// Fill calibrated energy histograms

	// Set Calibration Constants
	double A = 1.2;
	double B = 57;

	for(int i = 0; i < hEnThresh->GetNbinsX(); i++) {
		hEnCal->SetBinContent(A*i + B, hEnThresh->GetBinContent(i));
	}

	for(int i = 0; i < hEnThresh2->GetNbinsX(); i++) {
		hEnCal2->SetBinContent(A*i + B, hEnThresh2->GetBinContent(i));
	}

	for(int i = 0; i < hEnThresh3->GetNbinsX(); i++) {
		hEnCal3->SetBinContent(A*i + B, hEnThresh3->GetBinContent(i));
	}

	for(int i = 0; i < hEnThresh4->GetNbinsX(); i++) {
		hEnCal4->SetBinContent(A*i + B, hEnThresh4->GetBinContent(i));
	}

	for(int i = 0; i < hEnThresh5->GetNbinsX(); i++) {
		hEnCal5->SetBinContent(A*i +B, hEnThresh5->GetBinContent(i));
	}

//-----------------------------------------------------------------------------------

// Fill data histograms
	for(int i = 0; i < nn; i++) {
		tt->GetEntry(i);
		hMax->Fill(max);
	}

	for(int i = 0; i < nn2; i++) {
		tt2->GetEntry(i);
		hMax2->Fill(max2);
	}

	for(int i = 0; i < nn3; i++) {
		tt3->GetEntry(i);
		hMax3->Fill(max3);
	}

	for (int i = 0; i < nn4; i++) {
		tt4->GetEntry(i);
		hMax4->Fill(max4);
	}

//-----------------------------------------------------------------------------------

// evaluate integrals and find scaling constants
	double integral1 = hEnCal->Integral(0,1500);
	double integral2 = hEnCal2->Integral(0,1500);
	double integral3 = hEnCal3->Integral(0,1500);
	double integral4 = hMax->Integral(0,1500);
	double integral5 = hMax2->Integral(0,1500);
	double integral6 = hMax3->Integral(0,1500);
	double integral10 = hEnCal4->Integral(0,1500);
	double integral12 = hEnCal5->Integral(0,1500);
	double integral13 = hMax4->Integral(0,1500);
/*
	cout << "Integral of EnCal: " << integral1 << endl;
	cout << "Integral of EnCal2: " << integral2 << endl;
	cout << "Integral of EnCal3: " << integral3 << endl;
	cout << "Integral of EnCal4: " << integral10 << endl;
	cout << "Integral of EnCal5: " << integral12 << endl;
	cout << "Integral of Max: " << integral4 << endl;
	cout << "Integral of Max2: " << integral5 << endl;
	cout << "Integral of Max3: " << integral6 << endl;
	cout << "Integral of Max4: " << integral13 << endl;
*/
	double scale1 = integral4/integral1;
	double scale2 = integral5/integral2;
	double scale3 = integral6/integral3;
	double scale4 = integral6/integral10;
	double scale5 = integral13/integral12;
/*
	cout << " " << endl;
	cout << "Scaling constant for Carbon simulation: " << scale1 << endl;
	cout << "Scaling constant for Cesium simulation: " << scale2 << endl;
	cout << "Scaling constant for Strontium simulation - 45 um: " << scale3 << endl;
	cout << "Scaling constant for Strontium simulation - 150 um: " << scale4 << endl;
	cout << "Scaling constant for Americium simulation: " << scale5 << endl;
	cout << " " << endl;
*/
//-----------------------------------------------------------------------------------

// Scaling

	for(int i = 0; i < hEnCal->GetNbinsX(); i++) {
		int x = hEnCal->GetBinContent(i);
		hEnScale->SetBinContent(i, x*scale1);
	}

	for(int i = 0; i < hEnCal2->GetNbinsX(); i++) {
		int x = hEnCal2->GetBinContent(i);
		hEnScale2->SetBinContent(i, x*scale2);
	}

	for(int i = 0; i < hEnCal3->GetNbinsX(); i++) {
		int x = hEnCal3->GetBinContent(i);
		hEnScale3->SetBinContent(i, x*scale3);
	}

	for(int i = 0; i < hEnCal4->GetNbinsX(); i++) {
		int x = hEnCal4->GetBinContent(i);
		hEnScale4->SetBinContent(i, x*scale4);
	}

	for(int i = 0; i < hEnCal5->GetNbinsX(); i++) {
		int x = hEnCal5->GetBinContent(i);
		hEnScale5->SetBinContent(i, x*scale5);
	}

//-----------------------------------------------------------------------------------

	double integral7 = hEnScale->Integral(0,1500);
	double integral8 = hEnScale2->Integral(0,1500);
	double integral9 = hEnScale3->Integral(0,1500);
	double integral11 = hEnScale4->Integral(0,1500);
	double integral14 = hEnScale5->Integral(0,1500);
/*
	cout << "Integral of Scaled Energy: " << integral7 << endl;
	cout << "Integral of Scaled Energy 2: " << integral8 << endl;
	cout << "Integral of Scaled Energy 3: " << integral9 << endl;
	cout << "Integral of Scaled Energy 4: " << integral11 << endl;
	cout << "Integral of Scaled Energy 5: " << integral14 << endl;
*/
//-----------------------------------------------------------------------------------
/*
// Draw Histograms

	new TCanvas();
	hEnScale->SetLineWidth(2);
	hMax->SetLineWidth(1);

	hMax->SetXTitle("Greyscale");
	hMax->SetYTitle("Counts per greyscale");

	hEnScale->SetLineColor(2);
	hEnScale->Draw();
	hMax->SetLineColor(4);
	hMax->Draw("same");

	TLegend *legend = new TLegend(.75,.80,.95,.95);
	legend->AddEntry(hEnScale, "Simulation - Carbon - 10k runs");
	legend->AddEntry(hMax, "Data - Carbon - 10k images");
	legend->SetFillColor(0);
	legend->Draw("same");

	gPad->SetLogy();
*/
//-----------------------------------------------------------------------------------

/*
	new TCanvas();
	hEnScale2->SetLineWidth(2);
	hMax2->SetLineWidth(1);

	hMax2->SetXTitle("Greyscale");
	hMax2->SetYTitle("Counts per greyscale");

	hEnScale2->SetLineColor(2);
	hEnScale2->Draw();
	hMax2->SetLineColor(4);
	hMax2->Draw("same");

	TLegend *legend2 = new TLegend(.75,.80,.95,.95);
	legend2->AddEntry(hEnScale2, "Simulation - Cesium - 5k runs");
	legend2->AddEntry(hMax2, "Data - Cesium - 10k images");
	legend2->SetFillColor(0);
	legend2->Draw("same");

	gPad->SetLogy();
*/
//-----------------------------------------------------------------------------------
/*
	new TCanvas();
	gPad->SetLogy();
	hEnScale3->SetLineWidth(2);
	hEnScale4->SetLineWidth(2);
	hMax3->SetLineWidth(1);

	hMax3->SetXTitle("Greyscale");
	hMax3->SetYTitle("Counts per greyscale");
	
	hEnScale3->SetLineColor(2);
//	hEnScale3->Draw();
	hEnScale4->SetLineColor(7);
	hEnScale4->Draw("same");
	hMax3->SetLineColor(4);
	hMax3->Draw("same");

	TLegend *legend3 = new TLegend(.75,.8,.95,.95);
//	legend3->AddEntry(hEnScale3, "Simulation - Strontium - gap - 45 um");
	legend3->AddEntry(hEnScale4, "Simulation - Strontium - gap - 150 um");
	legend3->AddEntry(hMax3, "Data - Strontium - 2000 images");
	legend3->SetFillColor(0);
	legend3->Draw("same")
*/
//-----------------------------------------------------------------------------------

	new TCanvas();
	gPad->SetLogy();
	hEnScale5->SetLineWidth(2);
	hMax4->SetLineWidth(1);

	hMax4->SetXTitle("Greyscale");
	hMax4->SetYTitle("Counts per greyscale");

	hEnScale5->SetLineColor(2);
	hEnScale5->Draw();
	hMax4->SetLineColor(4);
	hMax4->Draw("same");

	TLegend *legend4 = new TLegend(.75,.80,.95,.95);
	legend4->SetFillColor(0);
	legend4->AddEntry(hEnScale5, "Simulation - Americium");
	legend4->AddEntry(hMax4, "Data - Americium");
	legend4->Draw("same");

};