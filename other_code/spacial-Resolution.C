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

TFile *f = new TFile("/Volumes/MY PASSPORT/Run189_1/Results-189_1-th170.root");
TFile *f2 = new TFile("/Volumes/MY PASSPORT/Run187_1/Results-187_1-th170.root");
TFile *f3 = new TFile("/Volumes/MY PASSPORT/Run188_1/Results-188_1-th170.root");

TTree *t = (TTree*)f->Get("ntuple");
TTree *t2 = (TTree*)f2->Get("ntuple");
TTree *t3 = (TTree*)f3->Get("ntuple");

//-------------------------------------------------------------------------------------

int n = t->GetEntries();
int n2 = t2->GetEntries();
int n3 = t3->GetEntries();

float x, x2, x3, y, y2, y3;

t->SetBranchAddress("x",&x);
t->SetBranchAddress("y",&y);

t2->SetBranchAddress("x",&x2);
t2->SetBranchAddress("y",&y2);

t3->SetBranchAddress("x",&x3);
t3->SetBranchAddress("y",&y3);

//-------------------------------------------------------------------------------------

TH2F *hColumn = new TH2F("hColumn","X and Y for first data set",100,0,515,100,0,515);
TH2F *hColumn2 = new TH2F("hColumn2","X and Y for second data set",100,0,515,100,0,515);
TH2F *hColumn3 = new TH2F("hColumn3","X and Y for third data set",100,0,515,100,0,515);

//-------------------------------------------------------------------------------------

float hX, hY;

for(int i=0; i<n; i++) {
	t->GetEntry(i);
	hColumn->Fill(x,y);
}

for(int i=0; i<n2; i++) {
	t2->GetEntry(i);
	hColumn2->Fill(x2,y2);
}

for(int i=0; i<n3; i++) {
	t3->GetEntry(i);
	hColumn3->Fill(x3,y3);
}

//-------------------------------------------------------------------------------------

new TCanvas();
hColumn->Draw();

TLegend *legend = new TLegend(.75,.80,.95,.95);
legend->SetFillColor(0);
legend->AddEntry(hColumn,"light + Cs - Small Column");
legend->Draw("same");

//-------------------------------------------------------------------------------------

new TCanvas();
hColumn2->SetFillColor(1);
hColumn2->Draw();
hColumn3->SetFillColor(2);
hColumn3->Draw("same");

TLegend *legend2 = new TLegend(.75,.80,.95,.95);
legend2->SetFillColor(0);
legend2->AddEntry(hColumn2,"Cs - Small Column - Data Set 1");
legend2->AddEntry(hColumn3,"Cs - Small Column - Data Set 2");
legend2->Draw("same");

//-------------------------------------------------------------------------------------
/*
new TCanvas();
hColumn3->Draw();

TLegend *legend3 = new TLegend(.75,.80,.95,.95);
legend3->SetFillColor(0);
legend3->AddEntry(hColumn3,"Cs - Large Column - Data Set 2");
legend3->Draw("same");
*/
}