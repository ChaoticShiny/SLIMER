//  ij2root.C macro
// Converts our imageJ ascii data to root file.  Currently this is for data in the form of
// event number, area, mean, min, max, x, y, intden, raw intden;
// If you change the output of the imageJ results table, you will need to edit the 
// script below to reflect those changes.  Specifically, the definition of the ntuple, 
// the "skip first line" command, the read-in line, and the ntuple->Fill line.

// Also, if your datafile has an extension longer than 3 characters, you'll need to edit 
// the line that is commented "crop the .txt part" (or change your extension!).

// The output file is stored in the same directory as the input file with the same name 
// except with an extension of ".root".  

// run instructions:
// root -l
// .x ij2root.C("/path/to/filename.txt")  


#include <fstream>
#include <string>
#include "Riostream.h"

void ij2root(){
char fileName[200];
string fileroot, ignore;
int rnum, rsuffix;


cout <<" Input the run number: ";
cin >> rnum;
cout <<" Input the run suffix (Usually 1 or 2): ";
cin >> rsuffix;


if (rnum <= 9) sprintf(fileName,"/Volumes/My Passport/Run00%d_%d/Results-00%d_%d-th170.txt",rnum,rsuffix,rnum,rsuffix);
else if (rnum <= 99) sprintf(fileName,"/Volumes/My Passport/Run0%d_%d/Results-0%d_%d-th170.txt",rnum,rsuffix,rnum,rsuffix);
else if (rnum <= 999) sprintf(fileName,"/Volumes/My Passport/Run%d_%d/Results-%d_%d-th170.txt",rnum,rsuffix,rnum,rsuffix);


string filetxt = fileName;

//----------------------------------------------------------------------------------------------------

cout<<"Filename is "<<filetxt<<"\n";  //checking that it got the right filename

int strlength = filetxt.length();  //getting the length of the filename
cout<<"length is "<<strlength<<"\n";  //just checking!

fileroot = filetxt;  //making a copy 
fileroot.replace(fileroot.length()-3, fileroot.length(),"root"); //change "txt" to "root" and store in our copy
cout<<fileroot<<"\n";  //double checking the new filename


   ifstream in;  //here's our read-in file
   in.open(filetxt.c_str());  //open() requires a character array
      
   Float_t num, area, mean, min, max, x, y, intden, intden2;
   Int_t nlines = 0;
   TFile *f = new TFile(fileroot.c_str(),"RECREATE"); //here's our output root file, also wants a char

   TNtuple *ntuple = new TNtuple("ntuple","data from ImageJ","area:mean:min:max:x:y:intden:intden2");

      in >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore; //skip first line

   while (1) {
      in >> num >> area >> mean >> min >> max >> x >> y >> intden >> intden2;
      if (!in.good()) break;
//      cout<<num<<"\t"<< area<<"\t" << mean<<"\t" << min<<"\t" << max<<"\t" << x<<"\t" << y<<"\t" << intden<<"\t" << intden2<<"\n";
      ntuple->Fill(area, mean, min, max, x, y, intden, intden2); //fill the branches
      nlines++;
   }
   printf(" found %d points\n",nlines);

   in.close();

   f->Write();
}