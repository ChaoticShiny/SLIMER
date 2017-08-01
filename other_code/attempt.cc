#include "attempt.hh"

int attempt () {
	HISTS hists;
	int rnum;
	int rsuffix; //In Run008_1, this would be 1, for example. In other runs it might be 2. It's always supposed to be 1.
	char reassurance;
	int regOrBlur;
	
	cout << "Input the run number: ";
	cin >> rnum;
	cout << "Input the run suffix (usually 1 or 2): ";
	cin >> rsuffix; 
	cout << "Is this set of pictures regular or blurred?" << endl;
	cout << "0. Regular\n1. Blurred\n(enter a number): ";
	cin >> regOrBlur;
	
	if (regOrBlur == 0) {
		cout << "You have selected a regular run.\n";
		if (rnum <= 9) sprintf(hists.fileName,"/Volumes/My Passport/Run00%d_%d/Pos0/ResultsMeasured.txt",rnum,rsuffix);
		else if (rnum <= 99) sprintf(hists.fileName,"/Volumes/My Passport/Run0%d_%d/Pos0/ResultsMeasured.txt",rnum,rsuffix);
		else if (rnum <= 999) sprintf(hists.fileName,"/Volumes/My Passport/Run%d_%d/Pos0/ResultsMeasured.txt",rnum,rsuffix);
	}
	else if (regOrBlur == 1) {
		cout << "You have selected a blurred run.\n";
		if (rnum <= 9) sprintf(hists.fileName,"/Volumes/My Passport/Run00%d_%d/blur/ResultsMeasured.txt",rnum,rsuffix);
		else if (rnum <= 99) sprintf(hists.fileName,"/Volumes/My Passport/Run0%d_%d/blur/ResultsMeasured.txt",rnum,rsuffix);
		else if (rnum <= 999) sprintf(hists.fileName,"/Volumes/My Passport/Run%d_%d/blur/ResultsMeasured.txt",rnum,rsuffix);
	}
	else {
		cout << "You have not selected an available option.\n";
		return rnum;
	}
	
	cout << "You have selected " << hists.fileName << ". Is this correct? (y/n)" << endl;
	cin >> reassurance;
	if (reassurance == 'y' | reassurance == 'Y') {
		cout << "Continuing..." << endl;
	
		hists.defineHist(rnum);
		
		if (regOrBlur == 0) { hists.readMeans(rnum); }
		if (regOrBlur == 1) { hists.readMeansBlurred(rnum); }
		
		hists.cmeans = new TCanvas("means","means");
		hists.means->Draw();
	}
	else{
		cout << "Finishing..." << endl;
		return rnum;
	}
	
	return rnum;
}