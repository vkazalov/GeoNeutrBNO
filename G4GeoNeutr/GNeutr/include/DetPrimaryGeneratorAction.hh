
#ifndef DetPrimaryGeneratorAction_h
#define DetPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include <vector>

class G4GeneralParticleSource;
class G4Event;

class DetPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    DetPrimaryGeneratorAction();
    ~DetPrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event* anEvent);

  private:
    G4GeneralParticleSource* particleGun;
};
#endif


