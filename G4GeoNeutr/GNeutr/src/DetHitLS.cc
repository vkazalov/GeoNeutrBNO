#include "DetHitLS.hh"

#include "G4ios.hh"
#include "G4VVisManager.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"


G4ThreadLocal G4Allocator<DetHitLS>* DetHitAllocatorLS;

DetHitLS::DetHitLS()
{
  edep=0.;
  pos = G4ThreeVector(0., 0., 0.);
  time = 0.;
  particleEnergy = 0.;
}
DetHitLS::~DetHitLS() {;}

DetHitLS::DetHitLS(const DetHitLS& right): G4VHit(right)
{
  edep      = right.edep;
  pos       = right.pos;
  time           = right.time;
  particleName   = right.particleName;
  particleEnergy = right.particleEnergy;
}
const DetHitLS& DetHitLS::operator=(const DetHitLS &right)
{
  edep      = right.edep;
  pos       = right.pos;
  time            = right.time;
  particleName    = right.particleName;
  particleEnergy  = right.particleEnergy;
  return *this;
}

G4int DetHitLS::operator==(const DetHitLS &right) const
{
  return false;
}
void DetHitLS::Draw() {}

void DetHitLS::Print() {}



