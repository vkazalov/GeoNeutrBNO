
#ifndef DetHitLS_h
#define DetHitLS_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4VPhysicalVolume.hh"


class DetHitLS : public G4VHit
{
public:

    DetHitLS();
	  virtual ~DetHitLS();
	  DetHitLS(const DetHitLS& right);
	  const DetHitLS& operator=(const DetHitLS& right);
    G4int operator==(const DetHitLS& right) const;
    	
    inline void *operator new(size_t);
    inline void operator delete(void *aHitLS);
    
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

typedef G4THitsCollection<DetHitLS> DetHitsCollectionLS;
extern G4ThreadLocal G4Allocator<DetHitLS>* DetHitAllocatorLS;


inline void* DetHitLS::operator new(size_t)
{
 if (!DetHitAllocatorLS)
    DetHitAllocatorLS = new G4Allocator<DetHitLS>;
 return (void*) DetHitAllocatorLS->MallocSingle();
  
}

inline void DetHitLS::operator delete(void* aHitLS)
{
  DetHitAllocatorLS->FreeSingle((DetHitLS*) aHitLS);
}



#endif
