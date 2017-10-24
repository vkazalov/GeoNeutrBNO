//#include "SensitiveDetector.hh"
#include "DetEventAction.hh"
#include "DetHitLS.hh"
#include "DetHitW.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4SDManager.hh"
#include "G4UImanager.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Step.hh"

DetEventAction::DetEventAction()
{ 
  WaterSVlColID = -1; 
  LABScintColID = -1;  
}
DetEventAction::~DetEventAction()
{
	
}

void DetEventAction::BeginOfEventAction(const G4Event* anEvent)
{
  
  

  if(LABScintColID==-1) 
  { 
    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    LABScintColID=SDman->GetCollectionID("LABScintCol");
    //G4cout << fCollID << G4endl; 
  }
  if(WaterSVlColID==-1) 
  { 
    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    WaterSVlColID=SDman->GetCollectionID("WaterSVlCol");
    //G4cout << fCollID << G4endl; 
  }
       
}

void DetEventAction::EndOfEventAction(const G4Event* anEvent)
{
  
  if(LABScintColID<0||WaterSVlColID<0) return;

  DetHitsCollectionLS* LSHC = NULL;
  DetHitsCollectionW*  WHC = NULL;
  G4HCofThisEvent* HCE = anEvent->GetHCofThisEvent();

  if(HCE) 
  {
    LSHC = (DetHitsCollectionLS*)(HCE->GetHC(LABScintColID));
    WHC = (DetHitsCollectionW*)(HCE->GetHC(WaterSVlColID));
  }

  
  
    totEnergyLS = 0;

    if (LSHC)
    {
      LABScint_hits = LSHC->entries();
      //G4cout << LABScint_hits << G4endl;
      for (G4int j=0; j<LABScint_hits; j++) 
      {
        hitEnergyLS = (*LSHC)[j]->GetEdep();
        //G4cout << hitEnergyLS << G4endl;
        totEnergyLS  += hitEnergyLS/keV;
        //G4cout << totEnergyLS << G4endl;
      }
      //G4cout << totEnergyLS << G4endl;
      if (totEnergyLS > 0 && totEnergyLS<SpcL)
      {  
        G4int EnergRawLS = int(totEnergyLS);
        //G4cout << EnergRawLS << G4endl;       
        SpcRawLS[EnergRawLS]++;     
      }

    }

    totEnergyW = 0;

    if (WHC)
    {
      WaterSVl_hits = WHC->entries();
      //G4cout << WaterSVl_hits << G4endl;
      for (G4int j=0; j<WaterSVl_hits; j++) 
      {
        hitEnergyW = (*WHC)[j]->GetEdep();
        //G4cout << hitEnergyW << G4endl;
        totEnergyW  += hitEnergyW/keV;
        //G4cout << totEnergyW << G4endl;
      }
      //G4cout << totEnergyW << G4endl;
      if (totEnergyW > 0 && totEnergyW<SpcL)
      {  
        G4int EnergRawW = int(totEnergyW);
        //G4cout << EnergRawW << G4endl;       
        SpcRawW[EnergRawW]++;     
      }

    }

  
}	

