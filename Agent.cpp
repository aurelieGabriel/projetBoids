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
#include <math.h>




//############################################################################
//                                                                           #
//                           Class Agent                                     #
//                                                                           #
//############################################################################

const double Agent::R = 70;
const double Agent::C = 30;

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Agent::Agent(void)
{
 
  x=(rand()/(double)RAND_MAX)*640;
  y=(rand()/(double)RAND_MAX)*480;
  isObstacle = false;
  isPredateur = false;
  vx=0;
  vy=0;

}

Agent::Agent(bool b)
{

  x=(rand()/(double)RAND_MAX)*900;
  y=(rand()/(double)RAND_MAX)*900;
  isObstacle = true;
  isPredateur = false;
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
