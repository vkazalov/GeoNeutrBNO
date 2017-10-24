#include "DetConstr.hh"
#include "DetEventAction.hh"


#include "SensitiveDetectorLS.hh"
#include "SensitiveDetectorW.hh"
#include "DetEventAction.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"    
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
 
#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Isotope.hh"
#include "G4Element.hh"

#include "G4UnitsTable.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4Torus.hh"
#include "G4Sphere.hh"
#include "G4Ellipsoid.hh"
#include "G4Polycone.hh"
#include "G4Polyhedra.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4UnitsTable.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"

#include <stdlib.h>
#include <time.h>
#include <fstream>

G4int SpcRawLS[SpcL];
G4int SpcRawW[SpcL];




DetConstr::DetConstr():G4VUserDetectorConstruction(),
world_log(0),world_phys(0),MTk_log(0),MTk_phys(0),
WateR_log(0),WateR_phys(0), NylonSp_log(0),NylonSp_phys(0),
LABScint_log(0),LABScint_phys(0),PMTglass_log(0), PMTglass_phys(0),
PMTvacuum_log(0), PMTvacuum_phys(0),PMTPhCth_log(0),PMTPhCth_phys(0),
PMTmirror_log(0),PMTmirror_phys(0),PMTdynodes_log(0),PMTdynodes_phys(0)


{;}
DetConstr::~DetConstr()
{
  FILE *outputFile1 = fopen("GNeutr.dat", "wt");
  		
	for (G4int ii=0; ii<SpcL; ii++)
	{ 
		
		//G4int ChanValKeV = ii;
		//fprintf(outputFile1, " %6i\t", ChanValKeV );
		fprintf(outputFile1, "%i\t", SpcRawLS[ii]);
		fprintf(outputFile1, "%i\n", SpcRawW[ii]);
		
				
	}
   fclose(outputFile1);
   
}




G4VPhysicalVolume* DetConstr::Construct()

{
		////-----defineMaterials-----------
		G4String name, symbol;             // a=mass of a mole;
		G4double A, z, density;            // z=mean number of protons;  
		G4int nel;
		
		//G4int iz, n;                       // iz=nb of protons  in an isotope; 
                                   // n=nb of nucleons in an isotope; G4int ncomponents, natoms;
		G4double abundance, fractionmass;
		G4double temperature, pressure;

        ///oooooooooooooooooooowork materials-----oooooooooo
		G4NistManager* nist = G4NistManager::Instance();
		G4Element* elH = nist->FindOrBuildElement(1);
		G4Element* elLi = nist->FindOrBuildElement(3);
	    G4Element* elB = nist->FindOrBuildElement(5);
		G4Element* elC = nist->FindOrBuildElement(6);
		G4Element* elN = nist->FindOrBuildElement(7);
		G4Element* elO = nist->FindOrBuildElement(8);
		G4Element* elAl = nist->FindOrBuildElement(13);
		G4Element* elSi = nist->FindOrBuildElement(14);
		G4Element* elK = nist->FindOrBuildElement(19);
		G4Element* elCa = nist->FindOrBuildElement(20);
		G4Element* elCr = nist->FindOrBuildElement(24);
		G4Element* elMn = nist->FindOrBuildElement(25);
		G4Element* elFe = nist->FindOrBuildElement(26);
		G4Element* elNi = nist->FindOrBuildElement(28);
		G4Element* elCu = nist->FindOrBuildElement(29);
		G4Element* elGe = nist->FindOrBuildElement(32);
		G4Element* elNd = nist->FindOrBuildElement(41);
		G4Element* elMo = nist->FindOrBuildElement(42);
		G4Element* elCs = nist->FindOrBuildElement(55);
		G4Element* elPb = nist->FindOrBuildElement(82);
		   
		G4Material* Vacuum = nist->FindOrBuildMaterial("G4_Galactic");
		G4Material* OrgSteclo = nist->FindOrBuildMaterial("G4_PLEXIGLASS"); 
		G4Material* Copper = nist->FindOrBuildMaterial("G4_Cu"); 
		G4Material* Germanium = nist->FindOrBuildMaterial("G4_Ge");
		G4Material* Lead = nist->FindOrBuildMaterial("G4_Pb");
		G4Material* Air = nist->FindOrBuildMaterial("G4_AIR");
		G4Material* NaI = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
		G4Material* PolyBankaMat = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
		G4Material* Lavsan = nist->FindOrBuildMaterial("G4_MYLAR");
		G4Material* Nylon = nist->FindOrBuildMaterial("G4_NYLON-6/6");
		G4Material* Caesium = nist->FindOrBuildMaterial("G4_Cs");
	

		//quartz
		G4Material* Qtz = new G4Material(name="quartz", density = 2.200*g/cm3, nel=2);
		Qtz->AddElement(elSi, 1);
		Qtz->AddElement(elO , 2);
		G4Material* SiO2   = nist->FindOrBuildMaterial("quartz");
		
		// photocathode material, approximated as elemental cesium// from KamLAND (K instead Cs????)
  		G4Material* Photocathode_mat = new G4Material(name="photocathode",density =5. *g/cm3,nel=1);
  		Photocathode_mat->AddElement(elK, 1);
	
		// PMT mirror material -- aluminum, maybe/// from KamLAND
  		// (not actually used, just placeholder for material properties used
  		// for optical surface)
  		//density= 5. *g/cm3; // true??
  		G4Material* PMT_Mirror_mat= new G4Material(name="PMT_Mirror", density = 5. *g/cm3, nel=1);
  		PMT_Mirror_mat->AddElement(elAl, 1);
		
		// Stainless steel (Medical Physics, Vol 25, No 10, Oct 1998)	
		G4Material* Ssteel = new G4Material(name="Stainless steel", density = 8.02*g/cm3, nel=5);
		Ssteel->AddElement(elMn, 0.02);
		Ssteel->AddElement(elSi, 0.01);
		Ssteel->AddElement(elCr, 0.19);
		Ssteel->AddElement(elNi, 0.10);
		Ssteel->AddElement(elFe, 0.68);
	
		// Scintillator LAB.
		G4Material* LAB = new G4Material(name="LAB", density = 0.856*g/cm3, nel=2);
		LAB->AddElement(elC, 18);
		LAB->AddElement(elH, 30);
		 
        /////VM2000         
        G4Material* VM2000 = new G4Material(name="VM2000",density=0.9*g/cm3, nel=2); 
        VM2000->AddElement(elC, 2); 
        VM2000->AddElement(elH,4);

        ////Water
        G4Material* water = new G4Material(name="Water", density=1.0*g/cm3, nel=2);
  		water->AddElement(elH, 2);
  		water->AddElement(elO, 1);

		
		
		
		///\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
		
		///volume of world
		   
		G4double world_x = 10.0*m;
		G4double world_y = 10.0*m;
		G4double world_z = 10.0*m;
		G4Box* world= new G4Box("World",world_x,world_y,world_z);
		world_log = new G4LogicalVolume(world,Air,"World",0,0,0);
		world_phys = new G4PVPlacement(0,G4ThreeVector(),world_log,"World",0,false,0);   
						
		///// Main Tank

		G4double innerRadiusMTk = 0.0*cm;
		G4double outerRadiusMTk = 202.0*cm;
		G4double hightMTk = 202.0*cm;
		G4double startAngleMTk = 0.*deg;
		G4double spanningAngleMTk = 360.*deg;
		G4Tubs* MTk = new G4Tubs("MTk",innerRadiusMTk,outerRadiusMTk,hightMTk,startAngleMTk,spanningAngleMTk);
		
		MTk_log = new G4LogicalVolume(MTk,Ssteel,"MTk",0,0,0);		
		G4double MTk_Pos_x = 0.*cm;
		G4double MTk_Pos_y = 0.*cm;
		G4double MTk_Pos_z = 0.*cm;
		MTk_phys = new G4PVPlacement(0,G4ThreeVector(MTk_Pos_x,MTk_Pos_y,MTk_Pos_z),MTk_log,"MTk",world_log,false,0);
		///// Water

		G4double innerRadiusWateR = 0.0*cm;
		G4double outerRadiusWateR = 200.0*cm;
		G4double hightWateR = 200.0*cm;
		G4double startAngleWateR = 0.*deg;
		G4double spanningAngleWateR = 360.*deg;
		G4Tubs* WateR = new G4Tubs("WateR",innerRadiusWateR,outerRadiusWateR,hightWateR,startAngleWateR,spanningAngleWateR);
		
		WateR_log = new G4LogicalVolume(WateR,water,"WateR",0,0,0);		
		G4double WateR_Pos_x = 0.*cm;
		G4double WateR_Pos_y = 0.*cm;
		G4double WateR_Pos_z = 0.*cm;
		WateR_phys = new G4PVPlacement(0,G4ThreeVector(WateR_Pos_x,WateR_Pos_y,WateR_Pos_z),WateR_log,"WateR",MTk_log,false,0);
		
		////Nylon sphere (or Acrile)
		G4double   pRminNylonSp = 0.*cm;
        G4double   pRmaxNylonSp = 50.00625*cm;
        G4double   pSPhiNylonSp = 0.*deg;
        G4double   pDPhiNylonSp = 360.*deg;
        G4double   pSThetaNylonSp = 0.*deg;
        G4double   pDThetaNylonSp = 360.*deg;

        G4Sphere* NylonSp= new G4Sphere("NylonSp", pRminNylonSp, pRmaxNylonSp, pSPhiNylonSp, pDPhiNylonSp, pSThetaNylonSp, pDThetaNylonSp);

		NylonSp_log = new G4LogicalVolume(NylonSp,Nylon,"NylonSp",0,0,0);		
		G4double NylonSp_Pos_x = 0.*cm;
		G4double NylonSp_Pos_y = 0.*cm;
		G4double NylonSp_Pos_z = 0.*cm;
		NylonSp_phys = new G4PVPlacement(0,G4ThreeVector(NylonSp_Pos_x,NylonSp_Pos_y,NylonSp_Pos_z),NylonSp_log,"NylonSp",WateR_log,false,0);
		
		///LAB sphere
		G4double   pRminLABScint = 0.*cm;
        G4double   pRmaxLABScint = 50.*cm;
        G4double   pSPhiLABScint = 0.*deg;
        G4double   pDPhiLABScint = 360.*deg;
        G4double   pSThetaLABScint = 0.*deg;
        G4double   pDThetaLABScint = 360.*deg;

        G4Sphere* LABScint= new G4Sphere("LABScint", pRminLABScint, pRmaxLABScint, pSPhiLABScint, pDPhiLABScint, pSThetaLABScint, pDThetaLABScint);

		LABScint_log = new G4LogicalVolume(LABScint,LAB,"LABScint",0,0,0);		
		G4double LABScint_Pos_x = 0.*cm;
		G4double LABScint_Pos_y = 0.*cm;
		G4double LABScint_Pos_z = 0.*cm;
		LABScint_phys = new G4PVPlacement(0,G4ThreeVector(LABScint_Pos_x,LABScint_Pos_y,LABScint_Pos_z),LABScint_log,"LABScint",NylonSp_log,false,0);
	
		////*******************************************
		////**********Model of PMT by G4Policone********
		
		//G4int  nmbRZ = 14; //old version
		//G4double rInner[] = { 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm};
	    //G4double rOuter[] = { 1*mm, 10*mm, 40*mm, 60*mm, 80*mm, 90*mm, 110*mm, 120*mm, 126.6*mm, 120*mm, 100*mm, 80*mm, 42.25*mm,42.25*mm}; 
		//G4double zPlane[] = { 1*mm, 2*mm, 10*mm, 20*mm, 30*mm, 40*mm, 56.7*mm, 76.7*mm, 96.7*mm, 116.7*mm, 136.7*mm, 150*mm, 161*mm, 245*mm};
	
		// PMT body-glass
		G4int  nmbRZ = 16;
		G4double rInner[] = { 0*mm, 1*mm, 18*mm, 38*mm, 58*mm, 78*mm, 93*mm, 108*mm,  118*mm,  124.5*mm, 118*mm,   98*mm,    78*mm,  40.25*mm, 40.25*mm, 0*mm};
	    G4double rOuter[] = { 2*mm, 5*mm, 20*mm, 40*mm, 60*mm, 80*mm, 95*mm, 110*mm,  120*mm,  126.5*mm, 120*mm,   100*mm,   80*mm,  42.25*mm, 42.25*mm, 42.25*mm}; 
		G4double zPlane[] = { 2*mm, 2*mm, 5*mm,  10*mm, 20*mm, 30*mm, 40*mm, 56.7*mm, 76.7*mm, 96.7*mm,  116.7*mm, 136.7*mm, 150*mm, 161*mm,   245*mm,   246*mm};
	
		//G4RotationMatrix* rot1 = new G4RotationMatrix();
		//rot1->rotateX(0.*deg);
	
		G4Polycone* PMTglass = new G4Polycone("PMTglass",0.0 * deg, 360.0 * deg, nmbRZ, zPlane,rInner, rOuter);
									 
		PMTglass_log = new G4LogicalVolume(PMTglass,SiO2,"PMTglass",0,0,0);
		PMTglass_phys = new G4PVPlacement(0,G4ThreeVector(0.0*mm,0.0*mm,0.0*mm),PMTglass_log,"PMTglass",WateR_log,false,0);
		
		// PMT vacuum
		G4int  VnmbRZ = 15;
		G4double VrInner[] = { 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm, 0*mm};
	    G4double VrOuter[] = { 0*mm, 3*mm, 18*mm, 38*mm, 58*mm, 78*mm, 93*mm, 108*mm, 118*mm, 124.5*mm, 118*mm, 98*mm, 78*mm, 40.25*mm,40.25*mm}; 
		G4double VzPlane[] = { 2*mm, 2*mm, 5*mm, 10*mm, 20*mm, 30*mm, 40*mm, 56.7*mm, 76.7*mm, 96.7*mm, 116.7*mm, 136.7*mm, 150*mm, 161*mm, 245*mm};
	
		G4Polycone* PMTvacuum = new G4Polycone("PMTvacuum",0.0 * deg, 360.0 * deg, VnmbRZ, VzPlane, VrInner, VrOuter);
									 
		PMTvacuum_log = new G4LogicalVolume(PMTvacuum,Vacuum,"PMTvacuum",0,0,0);
		PMTvacuum_phys = new G4PVPlacement(0,G4ThreeVector(0.0*mm,0.0*mm,0.0*mm),PMTvacuum_log,"PMTvacuum",PMTglass_log,false,0);
	
		// PMT photocathode
		G4int  PhCthnmbRZ = 9;
		G4double PhCthrInner[] = { 0*mm, 2.75*mm, 17.75*mm, 37.75*mm, 57.75*mm, 77.75*mm, 92.75*mm, 107.75*mm, 117.75};
	    G4double PhCthrOuter[] = { 3*mm, 3*mm,    18*mm,    38*mm,    58*mm,    78*mm,    93*mm,    108*mm,    118*mm}; 
		G4double PhCthzPlane[] = { 3*mm, 3*mm,    6*mm,     11*mm,    21*mm,    31*mm,    41*mm,    57.7*mm,   76.7*mm };
	
		G4Polycone* PMTPhCth = new G4Polycone("PMTPhCth",0.0 * deg, 360.0 * deg, PhCthnmbRZ, PhCthzPlane, PhCthrInner, PhCthrOuter);
									 
		PMTPhCth_log = new G4LogicalVolume(PMTPhCth,Photocathode_mat,"PMTPhCth",0,0,0);
		PMTPhCth_phys = new G4PVPlacement(0,G4ThreeVector(0.0*mm,0.0*mm,0.0*mm),PMTPhCth_log,"PMTPhCth",PMTvacuum_log,false,0);
	
		/// PMT mirror on glass body (maybe on outside surface)
		G4int  MnmbRZ = 5;
		G4double MrInner[] = { 124.25*mm, 117.75*mm, 97.75*mm, 77.75*mm, 42*mm};
	    G4double MrOuter[] = { 124.5*mm,  118*mm,    98*mm,    78*mm,  	42.25*mm}; 
		G4double MzPlane[] = { 96.7*mm,   116.7*mm, 136.7*mm, 150*mm, 	161*mm};
	
		G4Polycone* PMTmirror = new G4Polycone("PMTmirror",0.0 * deg, 360.0 * deg, MnmbRZ, MzPlane, MrInner, MrOuter);
									 
		PMTmirror_log = new G4LogicalVolume(PMTmirror,PMT_Mirror_mat,"PMTmirror",0,0,0);
		PMTmirror_phys = new G4PVPlacement(0,G4ThreeVector(0.0*mm,0.0*mm,0.0*mm),PMTmirror_log,"PMTmirror",PMTvacuum_log,false,0);
	
		// PMT dynodes system
		G4int  DnmbRZ = 5;
		G4double DrInner[] = { 0*mm,     0*mm,     0*mm,   0*mm,   0*mm};
	    G4double DrOuter[] = { 30*mm,    30*mm,    30*mm,  30*mm,  30*mm}; 
		G4double DzPlane[] = { 116.7*mm, 136.7*mm, 150*mm, 161*mm, 244*mm};
	
		G4Polycone* PMTdynodes = new G4Polycone("PMTdynodes",0.0 * deg, 360.0 * deg, DnmbRZ, DzPlane, DrInner, DrOuter);
									 
		PMTdynodes_log = new G4LogicalVolume(PMTdynodes,Caesium,"PMTdynodes",0,0,0);
		PMTdynodes_phys = new G4PVPlacement(0,G4ThreeVector(0.0*mm,0.0*mm,0.0*mm),PMTdynodes_log,"PMTdynodes",PMTvacuum_log,false,0);
		
		///************///////////////
		//\/\/\/\/\/ Sensitive detectors\/\/\/\/\/\/\/\/\/\/
		  		  
		G4SDManager* sdmanLS=G4SDManager::GetSDMpointer();
		G4String Det_SDnameLS = "Liquid scintillator";		  
		SensitiveDetectorLS* Det_SD_LS = new SensitiveDetectorLS(Det_SDnameLS);
		sdmanLS->AddNewDetector (Det_SD_LS);
		LABScint_log->SetSensitiveDetector(Det_SD_LS);

		G4SDManager* sdmanW=G4SDManager::GetSDMpointer();
		G4String Det_SDnameW = "WaterSVl";		  
		SensitiveDetectorW* Det_SD_W = new SensitiveDetectorW(Det_SDnameW);
		sdmanW->AddNewDetector (Det_SD_W);
		WateR_log->SetSensitiveDetector(Det_SD_W);
		  
		  
		  
	  
    return world_phys; 
}