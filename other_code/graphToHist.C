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
	
	TFile *f = new TFile("/home/gwendolyn/Things/Fall2015_Research/code_build/YExample.root");
	//TFile *f = new TFile("/home/gwendolyn/Things/Fall2015_Research/code_build/SrExample.root");
	TTree *t = (TTree*)f->Get("YExample");
	//TTree *t = (TTree*)f->Get("SrExample");
	
	double pEn, eAbsorbed;
	int n = t->GetEntries();
	t->SetBranchAddress("PrimaryEn", &pEn);
	t->SetBranchAddress("Eabs", &eAbsorbed);
	
	TH2D* hist = new TH2D("h","h",600,0,600,1000,0,1000);
	
	hist->SetMarkerStyle(7);
	
	for (int i = 0; i < n; i++) {
		t->GetEntry(i);
		h->Fill(pEn,eAbsorbed);
	}
}