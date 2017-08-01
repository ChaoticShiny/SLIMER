#ifndef PLOTRESULTSAGAIN_H
#define PLOTRESULTSAGAIN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "TH1I.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TFile.h"
#include "TLine.h"
#include "TF1.h"
#include "TH2.h"
#include "TF2.h"
#include "TMath.h"
#include "TROOT.h"
#include "TRandom.h"

// COMMENT HERE ABOUT WHAT RUN IS SET UP
//Ignoring the subtracted histogram (not commenting it out everywhere because that's too much trouble, but not drawing it). The first histogram is Run 046, a dark run with black cloth in place of the source. It uses the 10XS objective. The second histogram is Run 015, a dark run with no black cloth. It uses the 20XS objective. Run 046 was taken with 10000 images, while Run 015 was taken with 500. The purpose of this comparison is to see if the objectives are substantially different when one has a cloth and the other does not.  


using namespace std;

class PLOTTER {
public:
	//comment out or add variable sets as necessary
	ifstream infile0; double area0, intden0, peakH0, frame0, x0, y0; int counter0 = 0;
	ifstream infile1; double area1, intden1, peakH1, frame1, x1, y1; int counter1 = 0;
	//ifstream infile2; double area2, intden2, peakH2, frame2, x2, y2; int counter2 = 0; //subtracted values; shouldn't need an infile
	ifstream infile3; double area3, intden3, peakH3, frame3, x3, y3; int counter3 = 0;
	ifstream infile4; double area4, intden4, peakH4, frame4, x4, y4; int counter4 = 0;
	ifstream infile5; double area5, intden5, peakH5, frame5, x5, y5; int counter5 = 0;

	//comment out or add histogram allocations as necessary
	//remember that the second value in quotations needs to change for different runs
	TH1D *hPeakH0; TH1D *hArea0; TH1D *hIntDen0;
	TH1D *hPeakH1; TH1D *hArea1; TH1D *hIntDen1;
	//TH1D *hPeakH2; TH1D *hArea2; TH1D *hIntDen2; //subtracted
	TH1D *hPeakH3; TH1D *hArea3; TH1D *hIntDen3;
	TH1D *hPeakH4; TH1D *hArea4; TH1D *hIntDen4;
	TH1D *hPeakH5; TH1D *hArea5; TH1D *hIntDen5;

	int counter = 0; //different from counter0, counter1, and so on
	bool checker;
	string ignore;
	float ig;
	
	void openFiles();
	void fillHistograms();
	void subtract(); //this function takes the difference between two histograms and puts it in a third histogram
	void setTitles();
	void doCanvases();
	
	void plotter();
	~PLOTTER();

};


void PLOTTER::plotter() {
	checker = true;
}

PLOTTER::~PLOTTER() {}

void PLOTTER::openFiles() { 
	checker = true; 
	
	//comment out or add file openings as necessary
	infile0.open("/Volumes/My Passport/Run173_1/Results-173_1-th170.txt");
	if(!infile0) {
		cout << "File 0 not found.\n";
		checker = false;
	}
	
	

	infile1.open("/Volumes/My Passport/Run104_1/Results-104_1-th170.txt");
	if(!infile1) {
		cout << "File 1 not found.\n";
		checker = false;
	}
	
	

	//shouldn't need to open an infile2, since histogram 2 has the subtracted values
	
	infile3.open("/Volumes/My Passport/Run159_1/Results-159_1-th170.txt");
	if(!infile3) {
		cout << "File 2 not found.\n";
		checker = false;
	}

	infile4.open("/Volumes/My Passport/Run158_1/Results-158_1-th170.txt");
	if(!infile4) {
		cout << "File 3 not found!\n";
		checker = false;
	}

	infile5.open("/Volumes/My Passport/Run159_1/Results-159_1-th170.txt");
	if(!infile5) {
		cout << "File 4 not found.\n";
		checker = false;
	}

	cout << checker << endl;
}

void PLOTTER::fillHistograms() {
	if (checker != true) {
		cout << "Missing too many files! Aborting...\n";
		return;
	}
	else {
		//comment out or add line ignores as necessary
		getline(infile0,ignore);     //each one of these ignores the first line of the file
		getline(infile1,ignore);
		//shouldn't need an infile2, since histogram 2 is the subtracted values
		getline(infile3,ignore);
		getline(infile4,ignore);
		getline(infile5,ignore);

		//comment out or add do-while loops to fill the histograms as necessary
/*file0*/	do {
				infile0 >> frame0 >> area0 >> ig >> ig >> peakH0 >> x0 >> y0 >> intden0 >> ig;
				counter0++;
				hArea0->Fill(area0);
				hPeakH0->Fill(peakH0);
				hIntDen0->Fill(intden0);
			}while(!infile0.eof());
			infile0.close();

/*file1*/	do {
				infile1 >> frame1 >> area1 >> ig >> ig >> peakH1 >> x1 >> y1 >> intden1 >> ig;
				counter1++;
				hArea1->Fill(area1);
				hPeakH1->Fill(peakH1);
				hIntDen1->Fill(intden1);
			}while(!infile1.eof());
			infile1.close();
		
		//this loop scales a histogram
		/*int temp = 0; int tem = 0;
		for (int i = 0; i < 500; i++) {
			temp = (hPeakH0->GetBinContent(i))*4.9353;
			hPeakH0->SetBinContent(i,temp);
			
			tem = (hArea0->GetBinContent(i))*4.9353;
			hArea0->SetBinContent(i,tem);
	*/	}

//SKIP HISTOGRAM 2, because it's supposed to have the subtracted values	
	
		
/*file3*/	do {
				infile3 >> frame3 >> area3 >> ig >> ig >> peakH3 >> x3 >> y3 >> intden3 >> ig;
				counter3++;
				hArea3->Fill(area3);
				hPeakH3->Fill(peakH3);
				hIntDen3->Fill(intden3);
			}while(!infile3.eof());
			infile3.close();

/*file4*/	do {
				infile4 >> frame4 >> area4 >> ig >> ig >> peakH4 >> x4 >> y4 >> intden4 >> ig;
				counter4++;
				hArea4->Fill(area4);
				hPeakH4->Fill(peakH4);
				hIntDen4->Fill(intden4);
			}while(!infile4.eof());
			infile4.close();

/*file5*/	do {
				infile5 >> frame5 >> area5 >> ig >> ig >> peakH5 >> x5 >> y5 >> intden5 >> ig;
				counter5++;
				hArea5->Fill(area5);
				hPeakH5->Fill(peakH5);
				hIntDen5->Fill(intden5);
			}while(!infile5.eof());
			infile5.close();
	}


/*
//This function subtracts one histogram from another and puts it in HISTOGRAM 2. 
void PLOTTER::subtract() {
	double temp0, temp1, temp2;
	for(int i = 0; i<100; i++) {
		temp0 = hArea0->GetBinContent(i);
		temp1 = hArea1->GetBinContent(i);	
		temp2 = temp0 - temp1;
		hArea2->SetBinContent(i, temp2);
	}

	for(int i = 0; i<200; i++) {
		temp0 = hPeakH0->GetBinContent(i);
		temp1 = hPeakH1->GetBinContent(i);	
		temp2 = (temp0 - temp1);
		hPeakH2->SetBinContent(i, temp2);
	}

	for(int i = 0; i<200; i++) {
		temp0 = hIntDen0->GetBinContent(i);
		temp1 = hIntDen1->GetBinContent(i);	
		temp2 = temp0 - temp1;
		hIntDen2->SetBinContent(i, temp2);
	}*/


void PLOTTER::setTitles() {
	//again with the commenting/adding
	hIntDen0->GetXaxis()->SetTitle("Integrated Density");
	hIntDen1->GetXaxis()->SetTitle("Integrated Density"); 
//	hIntDen2->GetXaxis()->SetTitle("Integrated Density");
	hIntDen3->GetXaxis()->SetTitle("Integrated Density");
	hIntDen4->GetXaxis()->SetTitle("Integrated Density");
	hIntDen5->GetXaxis()->SetTitle("Integrated Density");
	
	hPeakH0->GetXaxis()->SetTitle("Peak Height");
	hPeakH1->GetXaxis()->SetTitle("Peak Height");
//	hPeakH2->GetXaxis()->SetTitle("Peak Height");
	hPeakH3->GetXaxis()->SetTitle("Peak Height");
	hPeakH4->GetXaxis()->SetTitle("Peak Height");
	hPeakH5->GetXaxis()->SetTitle("Peak Height");
}

void PLOTTER::doCanvases() {
	//makes the lenged show up instead of the RMS junk it usually puts
	gROOT->SetStyle("Plain");
	gStyle->SetOptStat(0000000);
	gStyle->SetOptTitle(kFALSE);
	
	

//--------------------------------------------------------------------------------------------------------
/*
	
	//this segment draws height
	
	new TCanvas();
	hPeakH0->Draw("");

	hPeakH1->SetLineColor(2);
	hPeakH1->Draw("same");

	hPeakH3->SetLineColor(3);
//	hPeakH3->Draw("same");

	hPeakH4->SetLineColor(5);
//	hPeakH4->Draw("same");

	hPeakH5->SetLineColor(6);
//	hPeakH5->Draw("same");


	TLegend *legend1 = new TLegend(.75,.80,.95,.95);
	legend1->AddEntry(hPeakH0,"Peak height - C @ 10 XS - 10,000");
	legend1->AddEntry(hPeakH1,"Peak height - Sr @ 10 XS - 50,000");
//	legend1->AddEntry(hPeakH3,"Run 159");
//	legend1->AddEntry(hPeakH4,"Peak height - 150 um #1");
//	legend1->AddEntry(hPeakH5,"Peak height - 150 um #2");
	legend1->SetFillColor(0);
	legend1->Draw("same");
	gPad->SetLogy();

//-------------------------------------------------------------------------------------------------------



	//This segment draws Area
	
	new TCanvas();
	hArea0->Draw();

	hArea1->SetLineColor(2);
	hArea1->Draw("same");

	hArea3->SetLineColor(3);
//	hArea3->Draw("same");

	hArea4->SetLineColor(5);
//	hArea4->Draw("same");

	hArea5->SetLineColor(6);
//	hArea5->Draw("same");


	TLegend *legend2 = new TLegend(.75,.80,.95,.95);
	legend2->AddEntry(hArea0, "Peak base area - C @ 10 XS - 10,000 ");
	legend2->AddEntry(hArea1, "Peak base area - Sr @ 10 XS - 50,000 ");
//	legend2->AddEntry(hArea3, "Peak base area -3 ");
//	legend2->AddEntry(hArea4, "Peak base area -4 ");
//	legend2->AddEntry(hArea5, "Peak base Area -5 ");
	legend2->SetFillColor(0);
	legend2->Draw("same");
	gPad->SetLogy();


*/
//-------------------------------------------------------------------------------------------------------



	//This segment draws Volume
	
	new TCanvas();
	hIntDen0->Draw();

	hIntDen1->SetLineColor(2);
	hIntDen1->Draw("same");

	hIntDen3->SetLineColor(3);
//	hIntDen3->Draw("same");

	hIntDen4->SetLineColor(5);
//	hIntDen4->Draw("same");

	hIntDen5->SetLineColor(6);
//	hIntDen5->Draw("same");


	TLegend *legend3 = new TLegend(.75,.80,.95,.95);
	legend3->AddEntry(hIntDen0, "Peak volume - C @ 10 XS - 10,000 ");
	legend3->AddEntry(hIntDen1, "Peak volume - Sr @ 10 XS - 50,000 ");
//	legend3->AddEntry(hIntDen3, "Peak volume -3 ");
//	legend3->AddEntry(hIntDen4, "Peak volume -4 ");
//	legend3->AddEntry(hIntDen5, "Peak volume -5 ");
	legend3->SetFillColor(0);
	legend3->Draw("same");
	gPad->SetLogy();





}

#endif