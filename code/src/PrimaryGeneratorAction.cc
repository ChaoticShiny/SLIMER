#include "PrimaryGeneratorAction.hh"
//#include "gamma.hh"
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"



PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  particleGun(0)
{
	G4cout << "Constructing PrimaryGeneratorAction\n";
  
  particleGun = new G4GeneralParticleSource();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  //delete particleGun;
  if (particleGun) delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  particleGun->GeneratePrimaryVertex(anEvent);
//  G4cout << "Generated primary vertex\n";
}

