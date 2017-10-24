#include "DetPhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4EmLowEPPhysics.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetPhysicsList::DetPhysicsList() 
: G4VModularPhysicsList(){
  SetVerboseLevel(1);

  // Default physics
  RegisterPhysics(new G4DecayPhysics());

  // Radioactive decay
  RegisterPhysics(new G4RadioactiveDecayPhysics());

  // EM physics
  //RegisterPhysics(new G4EmStandardPhysics());
  //RegisterPhysics(new G4EmStandardPhysics_option4());
  RegisterPhysics(new G4EmLowEPPhysics());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetPhysicsList::~DetPhysicsList()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetPhysicsList::SetCuts()
{
  
  //defaultCutValue     = 1.0*micrometer; //
  //defaultCutValue     = 1 * mm;
  //cutForGamma         = defaultCutValue;
  //cutForElectron      = 1.0*nanometer;
  //cutForPositron      = defaultCutValue;
  
  G4VUserPhysicsList::SetCuts();
}  
