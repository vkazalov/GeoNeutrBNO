#include "DetHitW.hh"

#include "G4ios.hh"
#include "G4VVisManager.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"


G4ThreadLocal G4Allocator<DetHitW>* DetHitAllocatorW;

DetHitW::DetHitW()
{
  edep=0.;
  pos = G4ThreeVector(0., 0., 0.);
  time = 0.;
  particleEnergy = 0.;
}
DetHitW::~DetHitW() {;}

DetHitW::DetHitW(const DetHitW& right): G4VHit(right)
{
  edep      = right.edep;
  pos       = right.pos;
  time           = right.time;
  particleName   = right.particleName;
  particleEnergy = right.particleEnergy;
}
const DetHitW& DetHitW::operator=(const DetHitW &right)
{
  edep      = right.edep;
  pos       = right.pos;
  time            = right.time;
  particleName    = right.particleName;
  particleEnergy  = right.particleEnergy;
  return *this;
}

G4int DetHitW::operator==(const DetHitW &right) const
{
  return false;
}
void DetHitW::Draw() {}

void DetHitW::Print() {}



