{
	#include "TCanvas.h"
	#include "TRandom.h"
	#include "TH2.h"
	#include "TF2.h"
	#include "TMath.h"
	#include "TROOT.h"
	#include <fstream>
	#include <string>

	TFile *f = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/20k-runs/Y-150-gap.root");
	TFile *f2 = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/20k-runs/Sr-150-gap.root");
	
	TFile *f3 = new TFile("/Users/alexchaney/Desktop/SLIMER-master/root_files/Sr+Y/40k-runs/Sr+Y-150-gap.root","new"); //creates a new file to put the three histograms into
	
	TTree *t1 = (TTree*)f->Get("file");
	TTree *t2 = (TTree*)f2->Get("file");


	int n1 = t1->GetEntries();

	double pEn1, eabs1;
	double pEn2, eabs2;

	t1->SetBranchAddress("PrimaryEn", &pEn1);
	t2->SetBranchAddress("PrimaryEn", &pEn2);
	
	t1->SetBranchAddress("Eabs", &eabs1);
	t2->SetBranchAddress("Eabs", &eabs2);

	TH1D *hEn = new TH1D("hEn","Added PrimaryEnergies",500,0,3000);
	TH1D *YEn = new TH1D("YEn","Y PrimaryEn",500,0,3000);
	TH1D *SrEn = new TH1D("SrEn","Sr PrimaryEn",500,0,3000);

	TH1D *hEabs = new TH1D("hEabs","Added Energy Absorbed",500,0,1000);
	TH1D *YEabs = new TH1D("YEabs","Y Energy Absorbed",500,0,1000);
	TH1D *SrEabs = new TH1D("SrEabs","Sr Energy Absorbed",500,0,1000);
	
	for (int i = 0; i < n1; i++) {
		t1->GetEntry(i);
		t2->GetEntry(i);
		YEn->Fill(pEn1);
		SrEn->Fill(pEn2);
		YEabs->Fill(eabs1);
		SrEabs->Fill(eabs2);
	}

//-------------------------------------------------------------
	
	hEn->Add(YEn);
	hEn->Add(SrEn);

	hEabs->Add(YEabs);
	hEabs->Add(SrEabs);

	f3->Write();

//-------------------------------------------------------------
/*
	new TCanvas();
	hEn->SetLineColor(1);
	hEn->Draw();
	
	SrEn->SetLineColor(3);
	SrEn->Draw("same");
	
	YEn->SetLineColor(2);
	YEn->Draw("same");

	gPad->SetLogy();

//-------------------------------------------------------------
	
	new TCanvas();

	hEabs->SetLineColor(1);
	YEabs->SetLineColor(2);
	SrEabs->SetLineColor(3);

	hEabs->Draw();
	YEabs->Draw("same");
	SrEabs->Draw("same");

	gPad->SetLogy();
*/
}
