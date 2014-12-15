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
#include "Boids.h"
#include "bwindow.h"
#include<math.h>




//############################################################################
//                                                                           #
//                           Class Boids                                     #
//                                                                           #
//############################################################################


// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Boids::Boids(void)
{

  nb_agents = 0;
  data = new Agent[50];

}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Boids::~Boids(void)
{

  delete [] data;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================



void Boids::addAgent(Agent a)
{

  data[nb_agents] = a;
  nb_agents ++;

}

bool Boids::perception(Agent a1, Agent a2)
{
  double distance = sqrt((a2.x - a1.x)*(a2.x - a1.x) + (a2.y - a1.y )*(a2.y - a1.y));
  if(distance<Agent::R)
    {
      return true;
    }
  else
    {
      return false;
    }

}


int Boids::neighbours( int position)
{

  int i;
  int k = 0;
  for(i=0; i<nb_agents; i++)
    {
        if(perception(data[i], data[position]))
	{
           k++;
        }
    }
  return k--;
}

double * Boids::velocity1(int p) //int p et pas Agent a car si l'utilisateur envoie un agent qui n'est pas dans le tableau ça ne va pas
{

  double * tab = new double[2];
  double vx = 0;
  double vy = 0;
  int i;
  for(i=0;i<nb_agents; i++)
    {
      if(perception(data[i], data[p]))
        {
          vx = (data[i].vx - data[p].vx)/neighbours(p);
          vy = (data[i].vy - data[p].vy)/neighbours(p);
        }
    }
  tab[0]= vx;
  tab[1]=vy;
  return tab;

}

double * Boids::velocity2(int p)
{
  double * tab = new double[2];
  double x = 0;
  double y = 0;
  int i;
  for(i=0;i<nb_agents; i++)
    {
      if(perception(data[i], data[p]))
        {
          x = (data[i].x - data[p].x)/neighbours(p);
          y = (data[i].y - data[p].y)/neighbours(p);
        }
    }
  tab[0]= x;
  tab[1]= y;
  return tab;
}

void Boids::totalVelocity(int p)
{

}


// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
