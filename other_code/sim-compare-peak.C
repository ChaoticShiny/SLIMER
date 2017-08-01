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

TFile *f = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/5k-runs/Sr-45.root");
TFile *ff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/Am-150.root");
TFile *fff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/10k-runs/Sr+Y-150.root");
TFile *f2 = new TFile("/Volumes/MY PASSPORT/Run173_1/Results-173_1-th170.root");
TFile *f3 = new TFile("/Volumes/MY PASSPORT/Run180_1/Results-180_1-th170.root");
TFile *f4 = new TFile("/Volumes/MY PASSPORT/Run098_1/Results-098_1-th170.root");


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
float max2, max3, max4;

t->SetBranchAddress("PrimaryEn", &pEn);
t->SetBranchAddress("Eabs", &eAbsorbed);

tt->SetBranchAddress("PrimaryEn", &pEn2);
tt->SetBranchAddress("Eabs", &eAbsorbed2);

t2->SetBranchAddress("max", &max2);
t3->SetBranchAddress("max", &max3);
t4->SetBranchAddress("max", &max4);

//-------------------------------------------------------------------------------------------

	TH1D *hEn = new TH1D("hEn","Energy Absorbed",500,0,2500);
	TH1D *hEn2 = new TH1D("hEn2","Energy Absorbed",500,0,2500);
//	TH1D *hEn3 = (TH1D*)fff->Get("hEn");
	TH1D *hEn3 = (TH1D*)fff->Get("hEabs");
	
	TH1F *hMax2 = new TH1F("hMax2","Peak Height of Events in Data Set 1",500,0,2500);
	TH1F *hMaxCal2 = new TH1F("hMaxCal2","Cal Peak Height of Events in Data Set 1",500,0,1500);

	TH1F *hMax3 = new TH1F("hMax3","Peak Height of Events in Data Set 2",500,0,2500);
	TH1F *hMaxCal3 = new TH1F("hMaxCal3","Cal Peak Height of Events in Data Set 2",500,0,1500);

	TH1F *hMax4 = new TH1F("hMax4","Peak Height of events in Data Set 3",500,0,2500);
	TH1F *hMaxCal4 = new TH1F("hMaxCal4","Cal Peak Height of Events in Data Set 3",500,0,1500);
	

/*
	TF1 *function = new TF1("function","[0]*exp(-x/[1])+[2]*exp(-x/[3])+[4]*exp(-x/[5])+[6]",0,1500);
	TF1 *function2 = new TF1("function2","[0]*exp(-x/[1])+[2]*exp(-x/[3])+[4]*exp(-x/[5])+[6]",0,1500);
	TF1 *function3 = new TF1("function3","[0]*exp(-x/[1])+[2]*exp(-x/[3])+[4]*exp(-x/[5])+[6]",0,1500);
	function->SetParameters(5783,9,3283,43,1194,100,-18);
	function2->SetParameters(270,2,51000,45,4883,153,-9);
	function3->SetParameters(1945,69,1945,69,4710,9,-9);
*/

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

//----------------------------------------------------------------------------------

	
	double a = 141.834;
	double b = .635325;
	for (int x = 0; x < n2; x++) {
		t2->GetEntry(x);
		hMax2->Fill(max2);
		hMaxCal2->Fill(b*max2 - a);  //first value: energy from spectrum; second value: x-value from data
		}
	
	Double_t res[1500];
	//cout << hEn->Chi2Test(hMaxCal_1,"UW CHI2/NDF",res) << endl; //this is the chi2/ndf value
	
//----------------------------------------------------------------------------------


	for (int x = 0; x < n3; x++) {
		t3->GetEntry(x);
		hMax3->Fill(max3);
		hMaxCal3->Fill(b*max3 - a);  //first value: energy from spectrum; second value: x-value from data
		}

	Double_t res_2[1500];

	
//----------------------------------------------------------------------------------


	for (int x = 0; x < n3; x++) {
		t4->GetEntry(x);
		hMax4->Fill(max4);
		hMaxCal4->Fill(b*max4 - a);  //first value: energy from spectrum; second value: x-value from data
		}
	
	Double_t res_3[1500];

//----------------------------------------------------------------------------------
	

	//scaling
	int temp_2 = 0;
	for (int i = 0; i < n2; i++) {
		temp_2 = hMax2->GetBinContent(i);
	}		

//----------------------------------------------------------------------------------


	//scaling
	int temp_3 = 0;
	for (int i = 0; i < n3; i++) {
		temp_3 = hMax3->GetBinContent(i);
	}

//----------------------------------------------------------------------------------


	//scaling
	int temp_4 = 0;
	for (int i = 0; i < n3; i++) {
		temp_4 = hMax4->GetBinContent(i);
	}

//----------------------------------------------------------------------------------

	// This segment compares simulation to peak height

	new TCanvas();	
	
	hEn->SetLineWidth(2);
	hEn2->SetLineWidth(2);
	hEn3->SetLineWidth(2);

	hMax2->SetLineWidth(1);
	hMaxCal2->SetLineWidth(1);
	hMax3->SetLineWidth(1);
	hMaxCal3->SetLineWidth(1);
	hMax4->SetLineWidth(1);
	hMaxCal4->SetLineWidth(1);

	hEn2->SetXTitle("Energy (keV)");
	hEn2->SetYTitle("Counts per 3 keV");
	hEn2->SetLineColor(3);
//	hEn->Draw();
	//hEn->Fit(function,"W","SAME",0,400);
	
	hEn2->SetLineColor(11);
	hEn2->Draw("same");

	hEn3->SetLineColor(3);
//	hEn3->Draw("same");

	hMax2->SetLineColor(4);
//	hMax2->Draw("same");
	
//	hMaxCal2->SetLineColor(12);
//	hMaxCal2->Draw("same");

	hMax3->SetLineColor(6);
	hMax3->Draw("same");

//	hMaxCal3->SetLineColor(7);
//	hMaxCal3->Draw("same");

	hMax4->SetLineColor(13);
//	hMax4->Draw("same");

//	hMaxCal4->SetLineColor(9);
//	hMaxCal4->Draw("same");


	TLegend *legend = new TLegend(.75,.80,.95,.95);
//	legend->AddEntry(hEn,"Simulation - Sr - 45 um");
	legend->AddEntry(hEn2,"Simulation - Gamma");
//	legend->AddEntry(hEn3,"Simulation - Strontium + Yttrium");
//	legend->AddEntry(hMax2,"Data - Run 173 - Strontium + Yttrium");
//	legend->AddEntry(hMaxCal2,"Calibrated experimental data #1");
//	legend->AddEntry(hMax3,"Data - Run 180 - Americium");
//	legend->AddEntry(hMaxCal3,"Calibrated experimental data #2");
//	legend->AddEntry(hMax4,"Data - Run 098 - Cesium");
//	legend->AddEntry(hMaxCal4,"Calibrated 8x8 binning");
	legend->SetFillColor(0);
	legend->Draw("same");

/*
	double integral0 = hEn->Integral(0,1500);
	double integral1 = hMax2->Integral(0,1500);
//	double integral2 = hMaxCal2->Integral(0,1500);
	double integral3 = hMax3->Integral(0,1500);
//	double integral4 = hMaxCal3->Integral(0,1500);

	cout << "Integral of hEn: " << integral0 << endl;
	cout << "Integral of hMax2: " << integral1 << endl;
//	cout << "Integral of hMaxCal2: " << integral2 << endl;	
	cout << "Integral of hMax3: " << integral3 << endl;
//	cout << "Integral of hMaxCal3: " << integral4 << endl;
*/


	gPad->SetLogy(); //a log scale is useful on the y axis

}