
#ifndef DetEventAction_h
#define DetEventAction_h 1

#define SpcL 16384


#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
extern G4int SpcRawLS[SpcL];
extern G4int SpcRawW[SpcL];
// G4int SpcBlur[SpcL];


class G4Event;


class DetEventAction : public G4UserEventAction
{
  public:
    DetEventAction();
    virtual ~DetEventAction();

  public:
    virtual void   BeginOfEventAction(const G4Event*);
    virtual void   EndOfEventAction(const G4Event*);

	private:
	 G4int WaterSVlColID; 
   G4int LABScintColID;               
   G4int LABScint_hits;
   G4int WaterSVl_hits;
   G4double totEnergyLS;
   G4double totEnergyW;
	 G4double hitEnergyLS;
   G4double hitEnergyW;
     	
    	
};
 
#endif