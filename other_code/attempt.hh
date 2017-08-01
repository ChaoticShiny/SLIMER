#ifndef ATTEMPT_H
#define ATTEMPT_H

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

using namespace std;

class HISTS {
public:
	//const char *PREFIX = "/Volumes/My Passport/Data/Run";
	//char *SUFFIX = "_1/Pos0/ResultsMeasured.txt";
	char fileName[200];
	
	char name[25];
	char title[25]; 
	double bins; 
	double xl; 
	double xh;
	
	void defineHist(int rnum);
	bool readMeans(int rnum);
	bool readMeansBlurred(int rnum);
	
	TH1F *means;
	TCanvas *cmeans;
};

void HISTS::defineHist(int rnum) {
	sprintf(name,"Mean_run_%d",rnum);
	sprintf(title,"Mean for run %d",rnum);
	bins = 250;  xl = 0;  xh = 500;
	means = new TH1F(name,title,bins,xl,xh);
}

bool HISTS::readMeans(int rnum) {
	int index = 0; int area = 0; double mean = 0; int min = 0; int max = 0;
	
	ifstream datafile(fileName);
	if (!datafile){ 
		cout << "Couldn't find the file" << endl;
		exit(1); 
	}
	else {
		string ignore;
		getline(datafile,ignore);
		cout << ignore << endl;
		do {
			//if (datafile.eof()) break;
			//cout << index << " " << area << " " << mean << " " << min << " " << max << endl;
			means->SetBinContent(index,mean);
		} while (datafile >> index >> area >> mean >> min >> max);
	}
	
	return true;
}

bool HISTS::readMeansBlurred(int rnum) {
	int index = 0; int area = 0; double mean = 0; int min = 0; int max = 0; int ig = 0;
	
	ifstream datafile(fileName);
	if (!datafile){ 
		cout << "Couldn't find the file" << endl;
		return false; 
	}
	else {
		string ignore;
		getline(datafile,ignore);
		cout << ignore << endl;
		do {
			//if (datafile.eof()) break;
			//cout << index << " " << area << " " << mean << " " << min << " " << max << endl;
			means->SetBinContent(index,mean);
		} while (datafile >> index >> area >> mean >> min >> max >> ig >> ig >> ig >> ig >> ig >> ig);
	}
	
	return true;
}


#endif