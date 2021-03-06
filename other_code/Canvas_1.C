{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Sun Aug  7 14:51:14 2016) by ROOT version5.34/14
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",1060,71,534,682);
   Canvas_1->Range(-96.25001,-1.057611,866.25,6.508201);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetLogy();
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *htemp__1 = new TH1F("htemp__1","AddedEabs",100,0,770);
   htemp__1->SetBinContent(1,297900);
   htemp__1->SetBinContent(2,13691);
   htemp__1->SetBinContent(3,11635);
   htemp__1->SetBinContent(4,10713);
   htemp__1->SetBinContent(5,9843);
   htemp__1->SetBinContent(6,8740);
   htemp__1->SetBinContent(7,7477);
   htemp__1->SetBinContent(8,6049);
   htemp__1->SetBinContent(9,5019);
   htemp__1->SetBinContent(10,4018);
   htemp__1->SetBinContent(11,3341);
   htemp__1->SetBinContent(12,2688);
   htemp__1->SetBinContent(13,2185);
   htemp__1->SetBinContent(14,1891);
   htemp__1->SetBinContent(15,1551);
   htemp__1->SetBinContent(16,1435);
   htemp__1->SetBinContent(17,1222);
   htemp__1->SetBinContent(18,1028);
   htemp__1->SetBinContent(19,1014);
   htemp__1->SetBinContent(20,852);
   htemp__1->SetBinContent(21,738);
   htemp__1->SetBinContent(22,685);
   htemp__1->SetBinContent(23,612);
   htemp__1->SetBinContent(24,567);
   htemp__1->SetBinContent(25,538);
   htemp__1->SetBinContent(26,448);
   htemp__1->SetBinContent(27,401);
   htemp__1->SetBinContent(28,366);
   htemp__1->SetBinContent(29,345);
   htemp__1->SetBinContent(30,314);
   htemp__1->SetBinContent(31,271);
   htemp__1->SetBinContent(32,276);
   htemp__1->SetBinContent(33,220);
   htemp__1->SetBinContent(34,233);
   htemp__1->SetBinContent(35,189);
   htemp__1->SetBinContent(36,156);
   htemp__1->SetBinContent(37,141);
   htemp__1->SetBinContent(38,130);
   htemp__1->SetBinContent(39,127);
   htemp__1->SetBinContent(40,101);
   htemp__1->SetBinContent(41,82);
   htemp__1->SetBinContent(42,77);
   htemp__1->SetBinContent(43,76);
   htemp__1->SetBinContent(44,70);
   htemp__1->SetBinContent(45,60);
   htemp__1->SetBinContent(46,58);
   htemp__1->SetBinContent(47,47);
   htemp__1->SetBinContent(48,37);
   htemp__1->SetBinContent(49,34);
   htemp__1->SetBinContent(50,31);
   htemp__1->SetBinContent(51,30);
   htemp__1->SetBinContent(52,15);
   htemp__1->SetBinContent(53,20);
   htemp__1->SetBinContent(54,19);
   htemp__1->SetBinContent(55,18);
   htemp__1->SetBinContent(56,21);
   htemp__1->SetBinContent(57,13);
   htemp__1->SetBinContent(58,15);
   htemp__1->SetBinContent(59,10);
   htemp__1->SetBinContent(60,7);
   htemp__1->SetBinContent(61,13);
   htemp__1->SetBinContent(62,18);
   htemp__1->SetBinContent(63,7);
   htemp__1->SetBinContent(64,4);
   htemp__1->SetBinContent(65,7);
   htemp__1->SetBinContent(66,4);
   htemp__1->SetBinContent(67,3);
   htemp__1->SetBinContent(68,3);
   htemp__1->SetBinContent(69,3);
   htemp__1->SetBinContent(70,2);
   htemp__1->SetBinContent(71,2);
   htemp__1->SetBinContent(72,5);
   htemp__1->SetBinContent(73,5);
   htemp__1->SetBinContent(74,4);
   htemp__1->SetBinContent(75,1);
   htemp__1->SetBinContent(76,1);
   htemp__1->SetBinContent(77,1);
   htemp__1->SetBinContent(78,6);
   htemp__1->SetBinContent(80,4);
   htemp__1->SetBinContent(81,2);
   htemp__1->SetBinContent(82,3);
   htemp__1->SetBinContent(83,1);
   htemp__1->SetBinContent(84,1);
   htemp__1->SetBinContent(85,2);
   htemp__1->SetBinContent(86,1);
   htemp__1->SetBinContent(87,2);
   htemp__1->SetBinContent(88,2);
   htemp__1->SetBinContent(89,1);
   htemp__1->SetBinContent(91,1);
   htemp__1->SetBinContent(93,1);
   htemp__1->SetEntries(400000);
   htemp__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 400000 ");
   text = ptstats->AddText("Mean  =  15.87");
   text = ptstats->AddText("RMS   =  40.49");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__1);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   htemp__1->SetLineColor(ci);
   htemp__1->GetXaxis()->SetTitle("AddedEabs");
   htemp__1->GetXaxis()->SetRange(1,100);
   htemp__1->GetXaxis()->SetLabelFont(42);
   htemp__1->GetXaxis()->SetLabelSize(0.035);
   htemp__1->GetXaxis()->SetTitleSize(0.035);
   htemp__1->GetXaxis()->SetTitleFont(42);
   htemp__1->GetYaxis()->SetLabelFont(42);
   htemp__1->GetYaxis()->SetLabelSize(0.035);
   htemp__1->GetYaxis()->SetTitleSize(0.035);
   htemp__1->GetYaxis()->SetTitleFont(42);
   htemp__1->GetZaxis()->SetLabelFont(42);
   htemp__1->GetZaxis()->SetLabelSize(0.035);
   htemp__1->GetZaxis()->SetTitleSize(0.035);
   htemp__1->GetZaxis()->SetTitleFont(42);
   htemp__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.349434,0.94,0.650566,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("AddedEabs");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
