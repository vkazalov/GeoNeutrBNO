#include "DetHit.hh"
#include "G4ios.hh"
#include "G4VVisManager.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"


G4ThreadLocal G4Allocator<DetHit>* DetHitAllocator;

DetHit::DetHit()
{
  edep=0.;
  pos = G4ThreeVector(0., 0., 0.);
  time = 0.;
  particleEnergy = 0.;
}
DetHit::~DetHit() {;}

DetHit::DetHit(const DetHit& right): G4VHit(right)
{
  edep      = right.edep;
  pos       = right.pos;
  time           = right.time;
  particleName   = right.particleName;
  particleEnergy = right.particleEnergy;
}
const DetHit& DetHit::operator=(const DetHit &right)
{
  edep      = right.edep;
  pos       = right.pos;
  time            = right.time;
  particleName    = right.particleName;
  particleEnergy  = right.particleEnergy;
  return *this;
}

G4int DetHit::operator==(const DetHit &right) const
{
  return false;
}
void DetHit::Draw() {}

void DetHit::Print() {}



