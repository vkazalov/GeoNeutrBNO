
#ifndef DetHit_h
#define DetHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4VPhysicalVolume.hh"


class DetHit : public G4VHit
{
public:

    DetHit();
	virtual ~DetHit();
	DetHit(const DetHit& right);
	const DetHit& operator=(const DetHit& right);
    G4int operator==(const DetHit& right) const;
    	
    inline void *operator new(size_t);
    inline void operator delete(void *aHit);
    
    virtual void Draw();
    virtual void Print();
	public:
  
      void SetEdep           (G4double de)       { edep = de; };
      void SetPos            (G4ThreeVector xyz) { pos = xyz; };
      void SetParticle       (G4String name)     { particleName = name; };
      void SetParticleEnergy (G4double e1)       { particleEnergy = e1; };
      void SetTime           (G4double t2)       { time = t2; };


      G4double GetEdep()                         { return edep; };      
      G4ThreeVector GetPos()                     { return pos; };
      G4String GetParticle()                     { return particleName;};
      G4double GetParticleEnergy()               { return particleEnergy;};
      G4double GetTime()                         { return time; };      
	private:
      G4double      edep;
      G4ThreeVector pos;
      G4double      time;
      G4String      particleName;
      G4double      particleEnergy;
};

typedef G4THitsCollection<DetHit> DetHitsCollection;
extern G4ThreadLocal G4Allocator<DetHit>* DetHitAllocator;


inline void* DetHit::operator new(size_t)
{
 if (!DetHitAllocator)
    DetHitAllocator = new G4Allocator<DetHit>;
 return (void*) DetHitAllocator->MallocSingle();
  
}

inline void DetHit::operator delete(void* aHit)
{
  DetHitAllocator->FreeSingle((DetHit*) aHit);
}



#endif
