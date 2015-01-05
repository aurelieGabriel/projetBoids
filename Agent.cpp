//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Agent.h"
#include "bwindow.h"




//############################################################################
//                                                                           #
//                           Class Agent                                     #
//                                                                           #
//############################################################################

const double Agent::R = 270;
const double Agent::C = 200;

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Agent::Agent(void)
{
 
  x=(rand()/(double)RAND_MAX)*480;
  y=(rand()/(double)RAND_MAX)*640;
  isObstacle = false;
  vx=0;
  vy=0;

}

Agent :: Agent(bool b)
{
  x=(rand()/(double)RAND_MAX)*480;
  y=(rand()/(double)RAND_MAX)*640;
  isObstacle = b;
  vx=0;
  vy=0;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
