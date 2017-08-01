#include "plotResultsAgain.h"

int plotResultsAgain() {
	PLOTTER plotter;
	cout << plotter.checker << endl;
	
	//comment out or add histogram initializations as necessary
	plotter.hPeakH0 = new TH1D("hPeakH0","C14 Peak Height - Run 104", 500, 0, 1000); //originally 500,0,1000; 250,0,500 is another good setting
	plotter.hArea0 = new TH1D("hArea0","C14 Peak area - Run 104",100, 0, 2000); //originally 100,0,2000
	plotter.hIntDen0 = new TH1D("hIntDen0","C14 intden - Run 104",500, 0, 10000); //originally 200,0,100000
	
	plotter.hPeakH1 = new TH1D("hPeakH1","Sr90 Peak height - Run 123",500, 0, 1000); //originally 500,0,1000; 250,0,500 is another good setting
	plotter.hArea1 = new TH1D("hArea1","Sr90 Peak area - Run 173",100, 0, 2000); //originally 100,0,2000
	plotter.hIntDen1 = new TH1D("hIntDen1","Sr90 intden - Run 173",500, 0, 10000); //originally 200,0,100000
	
	/*
	plotter.hPeakH2 = new TH1D("hPeakH2","10XS 14C subtracted",250, 0, 500); //originally 500,0,1000
	plotter.hArea2 = new TH1D("hArea2","10XS 14C subtracted",100, 0, 2000); //originally 100,0,2000
	plotter.hIntDen2 = new TH1D("hIntDen2","10XS 14C subtracted",200, 0, 100000); //originally 200,0,100000
	*/

	plotter.hPeakH3 = new TH1D("hPeakH3","C14 Peak Height - Run 124",500, 0, 1000);
	plotter.hArea3 = new TH1D("hArea3","C14 Peak Area - Run 124",100, 0, 2000);
	plotter.hIntDen3 = new TH1D("hIntDen3","C14 intden - Run 124",500, 0, 10000);

	plotter.hPeakH4 = new TH1D("hPeakH4","C14 Peak Height - Run 125",500, 0, 1000);
	plotter.hArea4 = new TH1D("hArea4","C14 Peak Area - Run 125",100, 0, 2000);
	plotter.hIntDen4 = new TH1D("hIntDen4","C14 intden - Run 125",500, 0, 10000);
	
	plotter.hPeakH5 = new TH1D("hPeakH5","C14 Peak Height - Run 126",500,0,1000);
	plotter.hArea5 = new TH1D("hArea5","C14 Peak Area - Run 126",100,0,2000);
	plotter.hIntDen5 = new TH1D("hArea5","C14 intden - Run 126",500,0,10000);

	plotter.openFiles();
	plotter.fillHistograms(); //does everything except histogram 2, which contains the subtracted values
//	plotter.subtract(); //fills histogram 2
	plotter.setTitles();
	plotter.doCanvases();

	return 0;


}