
#include "DetPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

#include "G4RunManager.hh"
#include "G4ios.hh"

DetPrimaryGeneratorAction::DetPrimaryGeneratorAction()
{
  particleGun = new G4GeneralParticleSource();
}

DetPrimaryGeneratorAction::~DetPrimaryGeneratorAction()
{
  delete particleGun;
}

void DetPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  particleGun -> GeneratePrimaryVertex(anEvent);
}


