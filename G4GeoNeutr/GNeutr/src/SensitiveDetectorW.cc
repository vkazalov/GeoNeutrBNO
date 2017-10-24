#include "DetConstr.hh"
#include "DetHitW.hh"
#include "SensitiveDetectorW.hh"


#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4VPhysicalVolume.hh"




SensitiveDetectorW::SensitiveDetectorW(G4String name)
:G4VSensitiveDetector(name)
{
	G4String HCname="WaterSVlCol";
	collectionName.insert(HCname);
	
}

SensitiveDetectorW::~SensitiveDetectorW()
{
  
}


void SensitiveDetectorW::Initialize(G4HCofThisEvent* HCE)
{
  WaterSVlCol= new DetHitsCollectionW(SensitiveDetectorName,collectionName[0]);
	G4String HCname = collectionName[0];
	static G4int HCID = -1;
	if(HCID<0) HCID = G4SDManager::GetSDMpointer()->GetCollectionID(HCname);
	HCE->AddHitsCollection(HCID,WaterSVlCol);
}


G4bool SensitiveDetectorW::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
  
  //need to know if this is an optical photon and exclude it:
  //if(aStep->GetTrack()->GetDefinition()
  //   == G4OpticalPhoton::OpticalPhotonDefinition()) return false;

  
  G4double edep = aStep->GetTotalEnergyDeposit();
  
  //G4cout << G4endl << "edep : " << G4endl << G4endl;
  //G4cout<< edep << G4endl;
  
  
  G4ParticleDefinition* particleType = aStep->GetTrack()->GetDefinition();
  G4String particleName = particleType->GetParticleName();
  
  
  G4double stepl = 0.;
  if (particleType->GetPDGCharge() != 0.)
    stepl = aStep->GetStepLength();
  
  //if ((edep==0.)&&(stepl==0.)) return false;   
  
  
  
  // fill in hit
  DetHitW* newHit = new DetHitW();
  newHit->SetEdep(edep);
  newHit->SetPos(aStep->GetPostStepPoint()->GetPosition());
  newHit->SetTime(aStep->GetPreStepPoint()->GetGlobalTime());
  newHit->SetParticle(particleName);
  newHit->SetParticleEnergy(aStep->GetPreStepPoint()->GetKineticEnergy() );

  WaterSVlCol->insert(newHit);
  
  return true;
      
}

void SensitiveDetectorW::EndOfEvent(G4HCofThisEvent*)
{}
void SensitiveDetectorW::clear()
{} 
void SensitiveDetectorW::DrawAll()
{} 
void SensitiveDetectorW::PrintAll()
{} 

