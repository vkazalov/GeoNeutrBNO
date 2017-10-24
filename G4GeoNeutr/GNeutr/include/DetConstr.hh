#ifndef DetConstr_h
#define DetConstr_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Box;
class G4Tubs;
class G4Cons;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
//class DetectorMessenger;

class DetConstr : public G4VUserDetectorConstruction
{
	public:
  
    DetConstr();
    ~DetConstr();
    G4VPhysicalVolume* Construct();
	//G4VPhysicalVolume* DefineVolumes();
	//DefineMaterials();
	
	private:
    //void DefineMaterials();
    G4Box* world;
	G4Tubs* Tub11;
	G4Tubs* Tub12;
	G4Tubs* Tub13;
	G4Tubs* Tub14;
	G4Tubs* Tub15;
	//G4Torus
	//G4Tubs* stenkaSsteel;
	//G4Tubs* stenkaQuartz;
	//G4Tubs* NaIcrystall;
	//G4Cons* banka;
	//G4Cons* chrompik;
	
	
	// Logical Volume	
    G4LogicalVolume* world_log;
	G4LogicalVolume* MTk_log;
	G4LogicalVolume* WateR_log;
	G4LogicalVolume* NylonSp_log;
	G4LogicalVolume* LABScint_log;
	G4LogicalVolume* PMTglass_log;
	G4LogicalVolume* PMTvacuum_log;
	G4LogicalVolume* PMTPhCth_log;
	G4LogicalVolume* PMTmirror_log;
	G4LogicalVolume* PMTdynodes_log;
	
	
	// Physical volumes
    //
    G4VPhysicalVolume* world_phys;
	G4VPhysicalVolume* MTk_phys;
	G4VPhysicalVolume* WateR_phys;
	G4VPhysicalVolume* NylonSp_phys;
	G4VPhysicalVolume* LABScint_phys;
	G4VPhysicalVolume* PMTglass_phys;
	G4VPhysicalVolume* PMTvacuum_phys;
	G4VPhysicalVolume* PMTPhCth_phys;
	G4VPhysicalVolume* PMTmirror_phys;
	G4VPhysicalVolume* PMTdynodes_phys;
	
	//G4VPhysicalVolume* DefineVolumes();
	/*G4Material* SiO2;
	G4Material* Vacuum;
	G4Material* LAB;
	G4Material* Air;
	G4Material* OrgSteclo;
	G4Material* VM2000;
	G4Material* Copper;
	G4Material* Ssteel;
	G4Material* NaI;
	G4Material* PolyBankaMat;
	G4Material* PotDich;
	G4Material* Lead;*/
    ////---------------
	//G4VisAttributes* worldVisAtt;
	//G4VisAttributes* quartzVisAtt;
	//G4VisAttributes* quartzWALLVisAtt;
	//G4VisAttributes* LABVisAtt;
	
	
   
};
#endif