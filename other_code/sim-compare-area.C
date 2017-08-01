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

TFile *f = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/5k-runs/Y-45.root");
TFile *ff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/5k-runs/Y-150.root");
TFile *fff = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/10k-runs/Sr+Y-150.root");
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
float area2, area3, area4;

t->SetBranchAddress("PrimaryEn", &pEn);
t->SetBranchAddress("Eabs", &eAbsorbed);

tt->SetBranchAddress("PrimaryEn", &pEn2);
tt->SetBranchAddress("Eabs", &eAbsorbed2);

t2->SetBranchAddress("area", &area2);
t3->SetBranchAddress("area", &area3);
t4->SetBranchAddress("area", &area4);

//-------------------------------------------------------------------------------------------

	TH1D *hEn = new TH1D("hEn","Energy Absorbed",500,0,1500);
	TH1D *hEn2 = new TH1D("hEn2","Energy Absorbed",500,0,1500);
//	TH1D *hEn3 = (TH1D*)fff->Get("hEn");
	TH1D *hEn3 = (TH1D*)fff->Get("hEabs");
	
	TH1F *hArea2 = new TH1F("hArea2","Area of Events in Data Set 1",200,0,5000);
	TH1F *hAreaCal2 = new TH1F("hAreaCal2","Calibrated Area of Events in Data Set 1",180,0,180);
	
	TH1F *hArea3 = new TH1F("hArea3","Area of Events in Data Set 2",200,0,5000);
	TH1F *hAreaCal3 = new TH1F("hAreaCal3","Calibrated Area of Events in Data Set 2",180,0,180);

	TH1F *hArea4 = new TH1F("hArea4","Area of Events in Data Set 3",200,0,5000);
	TH1F *hAreaCal4 = new TH1F("hAreaCal4","Calibrated Area of Events in Data Set 3",180,0,180);


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
		hArea2->Fill(area2);
		}
	
	Double_t res[1500];
	//cout << hEn->Chi2Test(hMaxCal_1,"UW CHI2/NDF",res) << endl; //this is the chi2/ndf value
		
//----------------------------------------------------------------------------------


	for (int x = 0; x < n3; x++) {
		t3->GetEntry(x);
		hArea3->Fill(area3);
		}

	Double_t res_2[1500];

//----------------------------------------------------------------------------------


	for (int x = 0; x < n4; x++) {
		t4->GetEntry(x);
		hArea4->Fill(area4);
		}

	Double_t res_3[1500];
	
//----------------------------------------------------------------------------------
	

	for(int i = 0; i<n2; i++) {
		t2->GetEntry(i);
		hAreaCal2->Fill(area2*0.145/2776.);
	}	

//----------------------------------------------------------------------------------
	

	for(int i = 0; i<n3; i++) {
		t3->GetEntry(i);
		hAreaCal3->Fill(area3*0.145/2776.);
	}

//----------------------------------------------------------------------------------

	
	for(int i = 0; i<n4; i++) {
		t4->GetEntry(i);
		hAreaCal4->Fill(area4*0.145/2776.);
	}
	
//----------------------------------------------------------------------------------

	new TCanvas();

	hEn->SetLineWidth(2);
	hEn2->SetLineWidth(2);
	hEn3->SetLineWidth(2);

	hArea2->SetLineWidth(1);
	hAreaCal2->SetLineWidth(1);
	hArea3->SetLineWidth(1);
	hAreaCal3->SetLineWidth(1);
	hArea4->SetLineWidth(1);
	hAreaCal4->SetLineWidth(1);

	hEn->SetXTitle("Energy (keV)");
	hEn->SetYTitle("Counts per 3 keV");
	hEn->SetLineColor(3);
	hEn->Draw();
	//hEn->Fit(function,"W","SAME",0,400);
	
	hEn2->SetLineColor(11);
	hEn2->Draw("same");

	hEn3->SetLineColor(3);
//	hEn3->Draw("same");

	hArea2->SetLineColor(4);
//	hArea2->Draw("same");

//	hAreaCal2->SetLineColor(12);
//	hAreaCal2->Draw("same");

	hArea3->SetLineColor(6);
//	hArea3->Draw("same");

//	hAreaCal3->SetLineColor(7);
//	hAreaCal3->Draw("same");

	hArea4->SetLineColor(13);
//	hArea4->Draw("same");

//	hAreaCal4->SetLineColor(9);
//	hAreaCal4->Draw("same");


	TLegend *legend2 = new TLegend(.75,.80,.95,.95);
	legend2->AddEntry(hEn,"Simulation - Y - 45");
	legend2->AddEntry(hEn2,"Simulation - Y - 150");
//	legend2->AddEntry(hEn3,"Simulation - Sr+Y");
//	legend2->AddEntry(hArea2,"Run 173");
//	legend2->AddEntry(hAreaCal2,"Calibrated experimental data #1");
//	legend2->AddEntry(hArea3,"Run 104");
//	legend2->AddEntry(hAreaCal3,"Calibrated experimental data #2");
//	legend2->AddEntry(hArea4,"Run 159");
//	legend2->AddEntry(hAreaCal4,"Calibrated 8x8 binning");
	legend2->SetFillColor(0);
	legend2->Draw("same");

/*
	double integral5 = hArea2->Integral(0,1500);
//	double integral6 = hAreaCal2->Integral(0,1500);
	double integral7 = hArea3->Integral(0,1500);
//	double integral8 = hAreaCal3->Integral(0,1500);

	cout << "Integral of hArea2: " << integral5 << endl;
//	cout << "Integral of hAreaCal2: " << integral6 << endl;	
	cout << "Integral of hArea3: " << integral7 << endl;
//	cout << "Integral of hAreaCal3: " << integral8 << endl;
*/

	gPad->SetLogy();


}