/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "DetectorConstruction.hh"
//#include "SteppingAction.hh"
   // use of stepping action to set the accounting volume

#include "G4RunManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"
#include "G4Isotope.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4UnitsTable.hh"

#include "G4OpticalSurface.hh"
#include "G4MaterialPropertyVector.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction()
{ }

DetectorConstruction::~DetectorConstruction()
{ }

G4VPhysicalVolume* DetectorConstruction::Construct()
{	
	//Option to switch on/off checking of volumes overlaps
	G4bool checkOverlaps = true;

// ------------- Materials -------------

	G4double a, z, density;
	G4int nelements;

	// Air
	// 
	G4Element* N = new G4Element("Nitrogen","N",z=7,a=14.01*g/mole);
	G4Element* O = new G4Element("Oxygen","O",z=8,a=16.00*g/mole);

	G4Material* Air = new G4Material("Air",density=1.29*mg/cm3,nelements=2);
	Air->AddElement(N, 0.70);
	Air->AddElement(O, 0.30);

	// CsI
	// 
	G4Element* Cs = new G4Element("Cesium","Cs",z=55,a=132.91*g/mole);
	G4Element* I = new G4Element("Iodine","I",z=53,a=126.90*g/mole);

	G4Material* CesiumIodide = new G4Material("CesiumIodide",density=4.51*g/cm3,nelements=2);
	CesiumIodide->AddElement(Cs,1);
	CesiumIodide->AddElement(I,1);
	
	// Al
	//
	G4Element* Al = new G4Element("Aluminum","Al",z=13,a=26.98*g/mole);
	
	G4Material* Aluminum = new G4Material("Aluminum",density=2.70*g/cm3,nelements=1);
	Aluminum->AddElement(Al,1);



	// Glass
	//
	G4Element* Si = new G4Element("Silicon","Si",z=14,a=28.09*g/mole);
	
	G4Material* Silicate = new G4Material("Silicate",density=2.65*g/cm3,nelements=2);
	Silicate->AddElement(Si,1);
	Silicate->AddElement(O,2);

	G4Element* B = new G4Element("Boron","B",z=5,a=10.81*g/mole);
	
	G4Material* BoronTrioxide = new G4Material("BoronTrioxide",density=2.46*g/cm3,nelements=2);
	BoronTrioxide->AddElement(B,2);
	BoronTrioxide->AddElement(O,3);

G4cout<<"Made it to constructing glass\n";

	G4Material* Glass = new G4Material("Glass",density=2.587*g/cm3,nelements=2);
	Glass->AddMaterial(Silicate, 0.85);
	Glass->AddMaterial(BoronTrioxide, 0.15);
	
	G4cout<<"Constructed glass\n";


// ------------ Generate & Add Material Properties Table ------------

	const G4int nEntries = 5;
	
	G4double PhotonEnergy[nEntries] = {2.761*eV,2.485*eV,2.258*eV,2.071*eV,1.911*eV};

// Cesium iodide
	
	G4double RefractiveIndexCsI[nEntries] = {1.79,1.79,1.79,1.79,1.79};
	G4double AbsorptionCsI[nEntries] = {39.0*m,39.0*m,39.0*m,39.0*m,39.0*m};
	G4double ScintilFast[nEntries] = {1.00,1.00,1.00,1.00,1.00};
	G4double ScintilSlow[nEntries] = {0.01,1.00,2.00,3.00,4.00};
	
	G4MaterialPropertiesTable* mptCsI = new G4MaterialPropertiesTable();
	
	mptCsI->AddProperty("RINDEX",PhotonEnergy,RefractiveIndexCsI,nEntries)->SetSpline(true);
	mptCsI->AddProperty("ABSLENGTH",PhotonEnergy,AbsorptionCsI,nEntries)->SetSpline(true);
	mptCsI->AddProperty("FASTCOMPONENT",PhotonEnergy,ScintilFast,nEntries)->SetSpline(true);
	mptCsI->AddProperty("SLOWCOMPONENT",PhotonEnergy,ScintilSlow,nEntries)->SetSpline(true);
	
	mptCsI->AddConstProperty("SCINTILLATIONYIELD",0.5/keV);  //SHOULD BE 54 // used this to turn off OP for a while
	mptCsI->AddConstProperty("RESOLUTIONSCALE",1.0);
	mptCsI->AddConstProperty("FASTTIMECONSTANT",1.*ns);
	mptCsI->AddConstProperty("SLOWTIMECONSTANT",100.*ns);
	mptCsI->AddConstProperty("YIELDRATIO",0.45);
	
	// Energy and MIE stuff??
	
	CesiumIodide->SetMaterialPropertiesTable(mptCsI);
	
// Air
	
	G4double RefractiveIndexAir[nEntries] = {1.00,1.00,1.00,1.00,1.00};
	
	G4MaterialPropertiesTable* mptAir = new G4MaterialPropertiesTable();
	mptAir->AddProperty("RINDEX",PhotonEnergy,RefractiveIndexAir,nEntries);
	
	Air->SetMaterialPropertiesTable(mptAir);



// Glass
	G4double RefractiveIndexGlass[nEntries] = {1.517,1.517,1.517,1.517,1.517};
	G4MaterialPropertiesTable* mptGlass = new G4MaterialPropertiesTable();
	mptGlass->AddProperty("RIndex",PhotonEnergy,RefractiveIndexGlass,nEntries);

	Glass->SetMaterialPropertiesTable(mptGlass);

// ------------- Volumes --------------
	
// The world
	
	G4double worldx = 10.0*cm;
	G4double worldy = 10.0*cm;
	G4double worldz = 10.0*cm;
	
	G4Box* solidWorld = new G4Box("World",worldx,worldy,worldz);
	
	G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld,Air,"World",0,0,0);
	
	G4VPhysicalVolume* physWorld = new G4PVPlacement(0,G4ThreeVector(),logicWorld,"World",0,false,0);
	G4cout<<"Just made physWorld\n";
	
// The cylinders
	
	G4double innerRadius = 0.0*um;
	G4double outerRadius = 5.0*um;
//	G4double hz = 2.5*um; int Hz = 2.5;
//	G4double hz = 5*um; int Hz = 5;
//	G4double hz = 22.5*um; int Hz = 22.5;
//	G4double hz = 67.5*um; int Hz = 67.5;
	G4double hz = 75*um; int Hz = 75;
//	G4double hz = 300*um; int Hz = 300;
	G4double startAngle = 0.0*deg;
	G4double spanningAngle = 360.0*deg;
	
	G4Tubs* solidCylinder = new G4Tubs("Cylinder",innerRadius,outerRadius,hz,startAngle,spanningAngle);
	
	G4LogicalVolume* logicCylinder = new G4LogicalVolume(solidCylinder,CesiumIodide,"Cylinder");
	
	G4VPhysicalVolume* physCylinder = new G4PVPlacement(0,G4ThreeVector(),logicCylinder,"Cylinder",0,false,0,checkOverlaps);
	
	G4ThreeVector positionCyl = G4ThreeVector();
//	new G4PVPlacement(0,position,logicCylinder,"cylinder",logicWorld,false,0);
	
	int k = 0;
	//do these loops for all the cylinders
	for (int i = -10; i < 10; i++) {
		for (int j = -5; j < 5; j++) {
			positionCyl = G4ThreeVector(10*i*um,17.5*j*um,0.0);
			new G4PVPlacement(0,positionCyl,logicCylinder,"CsI",logicWorld,false,k);
			k++;
		}
	}

	for (int i = -10; i < 10; i++) {
		for (int j = -5; j < 5; j++) {
			positionCyl = G4ThreeVector(10*i*um + 5.0*um,17.5*j*um + 8.75*um,0.0);
			new G4PVPlacement(0,positionCyl,logicCylinder,"CsI",logicWorld,false,k);
			k++;
		}
	}

// Add Cones on top of all cylinders (to more closely match the experiment)

	G4double baseInnerRadius = 0.0*um;
	G4double baseOuterRadius = 5.0*um;
	G4double tipInnerRadius = 0.0*um;
	G4double tipOuterRadius = 0.0*um;
	G4double hzCone = 1.45*um; int HzCone = 1.45;
	G4double startAngleCone = 0.0*deg;
	G4double spanningAngleCone = 360*deg;

	G4Cons* solidCone = new G4Cons("Cone",baseInnerRadius,baseOuterRadius,tipInnerRadius,tipOuterRadius,hzCone,startAngleCone,spanningAngleCone);

	G4LogicalVolume* logicCone = new G4LogicalVolume(solidCone,CesiumIodide,"Cone");

	G4VPhysicalVolume* physCone = new G4PVPlacement(0,G4ThreeVector(),logicCone,"Cone",0,false,0,checkOverlaps);

	G4ThreeVector positionCone = G4ThreeVector();
// new G4PVPlacement(0,positionCone,logicCone,"Cone",logicworld,false,0);

	int l = 0;
	//do these loops for all of the cones
	for (int i = -10; i < 10; i++) {
		for (int j = -5; j < 5; j++) {
			positionCone = G4ThreeVector(10*i*um,17.5*j*um,Hz*um + HzCone*um);
			new G4PVPlacement(0,positionCone,logicCone,"CsI",logicWorld,false,l);
			l++;
		}
	}

	for (int i = -10; i < 10; i++) {
		for (int j = -5; j < 5; j++) {
			positionCone = G4ThreeVector(10*i*um + 5.0*um,17.5*j*um + 8.75*um, Hz*um + HzCone*um);
			new G4PVPlacement(0,positionCone,logicCone,"CsI",logicWorld,false,l);
			l++;
		}
	}


// Glass Slide
	G4double px = 300*um; int Px = 300;
	G4double py = 300*um; int Py = 300;
	G4double pz = 500*um; int Pz = 500;
	
	G4Box* solidBox = new G4Box("Box", px, py, pz);

	G4LogicalVolume* logicBox = new G4LogicalVolume(solidBox,Glass,"Box");

	G4VPhysicalVolume* physBox = new G4PVPlacement(0,G4ThreeVector(),logicBox,"Box",0,false,0,checkOverlaps);

	G4ThreeVector positionBox = G4ThreeVector();
// new G4PVPlacement (0,positionBox,logicBox,"Box",logicWorld,false,0);
	positionBox = G4ThreeVector(0*um,0*um,- Hz*um -Pz*um);
	new G4PVPlacement(0,positionBox,logicBox,"Glass",logicWorld,false,1);

// The camera
	
	G4double cameraInner = 0.0*mm;
	G4double cameraOuter = 1.0*mm;
	G4double camerahz = 20*um;
	G4double cameraStartAngle = 0.0*deg;
	G4double cameraSpanningAngle = 360.0*deg;
	
	G4Tubs* solidCamera = new G4Tubs("Camera",cameraInner,cameraOuter,camerahz,cameraStartAngle,cameraSpanningAngle);
	
	G4LogicalVolume* logicCamera = new G4LogicalVolume(solidCamera,Aluminum,"Camera");
	
	G4VPhysicalVolume* physCamera = new G4PVPlacement(0,G4ThreeVector(),logicCamera,"Camera",0,false,0,checkOverlaps);
	
	G4ThreeVector cameraPosition = G4ThreeVector(0,0,-2.0*mm);
	new G4PVPlacement(0,cameraPosition,logicCamera,"camera",logicWorld,false,0);
	
	
// ------------- Surfaces --------------

	G4OpticalSurface* OpCsISurface = new G4OpticalSurface("CsISurface");
	OpCsISurface->SetType(dielectric_dielectric);
	OpCsISurface->SetFinish(polished);
	OpCsISurface->SetModel(glisur);
/*
	G4OpticalSurface* OpCsISurfaceCone = new G4OpticalSurface("CsISurfaceCone");
	OpCsISurfaceCone->SetType(dielectric_dielectric);
	OpCsISurfaceCone->SetFinish(polished);
	OpCsISurfaceCone->SetModel(glisur);
*/
	new G4LogicalBorderSurface("CsISurface",physCylinder,physWorld,OpCsISurface);
	// maybe try it with G4LogicalSkinSurface

//	new G4LogicalBorderSurface("CsISurfaceCone",physCone,physWorld,OpCsISurfaceCone);
	// maybe try it with G4LogicalSkinSurface
	
// Generate & Add Material Properties Table attached to the optical surface
	
	G4double RefractiveIndex[nEntries] = {1.79,1.79,1.79,1.79,1.79};
	G4double Backscatter[nEntries] = {0.0,0.0,0.0,0.0,0.0};
	
	G4MaterialPropertiesTable* mptSurface = new G4MaterialPropertiesTable();
	
	mptSurface->AddProperty("RINDEX",PhotonEnergy,RefractiveIndex,nEntries);
	mptSurface->AddProperty("BACKSCATTERCONSTANT",PhotonEnergy,Backscatter,nEntries);
	
	OpCsISurface->SetMaterialPropertiesTable(mptSurface);

//	OpCsISurfaceCone->SetMaterialPropertiesTable(mptSurface);
	
	
        return physWorld;      




 //THIS FILE MIGHT NEED TO BE ADJUSTED IN ORDER TO MORE ACCURATELY REPRESENT THE CONSTRUCTION OF THE SCINTILLATOR!!!       
}
