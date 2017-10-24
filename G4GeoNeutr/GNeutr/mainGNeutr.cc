#include "DetConstr.hh"
#include "DetEventAction.hh"
#include "DetHitLS.hh"
#include "DetHitW.hh"
#include "DetPhysicsList.hh"
#include "DetPrimaryGeneratorAction.hh"
#include "SensitiveDetectorLS.hh"
#include "SensitiveDetectorW.hh"

#include "G4Run.hh"
#include "G4UIterminal.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4RunManager.hh"
#include "G4VSteppingVerbose.hh"
#include "G4UserRunAction.hh"

//#include "G4Allocator.hh"
//#include <time.h>


int main(int argc,char** argv)
//void main()
{
          
 
  
  //choose the Random engine
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  
  G4RunManager* runManager = new G4RunManager;
  runManager->SetUserInitialization(new DetConstr());
  runManager->SetUserInitialization(new DetPhysicsList());
  runManager->SetUserAction(new DetPrimaryGeneratorAction);
  runManager->SetUserAction(new DetEventAction);
 
  
  
  
  
  runManager->Initialize();
  //size_t a;
  //a= LABDetHitAllocator->GetAllocatedSize();
  //printf( "%d\n",a);
  			
  /*G4cout<<"===============================================================";
  G4cout<<G4endl;
  G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
  G4cout<< *(G4Material::GetMaterialTable()) << G4endl;
  G4cout<<"===============================================================";
  G4cout<<G4endl;*/
   
  G4UImanager* UImanager = G4UImanager::GetUIpointer(); 
  G4UIExecutive* ui = 0;
  if ( argc == 1 ) 
  {
    ui = new G4UIExecutive(argc, argv);
  }
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  if ( ! ui ) { 
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else { 
    // interactive mode
    UImanager->ApplyCommand("/control/execute vis1.mac");//vis4.mac
    ui->SessionStart();
    delete ui;
  }
   
  
  delete visManager;
  
  
  //G4int  numberOfEvent= 2147483647;
  //G4int  numberOfEvent= 1000;
  //runManager->BeamOn(numberOfEvent);
  //printf( "%d\n",numberOfEvent);
 // runManager->BeamOn(1000000);
  
  delete runManager;
  return 0;  
}

