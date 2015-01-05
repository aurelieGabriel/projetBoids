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
#include<typeinfo>
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

bool Boids::perception(Agent a1, Agent a2, double d)
{
  double distance = sqrt((a2.x - a1.x)*(a2.x - a1.x) + (a2.y - a1.y )*(a2.y - a1.y));
  if(distance<d)
    {
      return true;
    }
  else
    {
      return false;
    }

}


int * Boids::neighbours( int position, double distance)
{

  int i;
  int * tab = new int[2];
  int nbObstacles, nbAgents = 0;
  for(i=0; i<nb_agents; i++)
    {
        if(perception(data[i], data[position], distance))
	   {		   
		   if(!data[i].isObstacle)
		   {
             nbAgents++;
		   }
		   else
		   {
			 nbObstacles++;
		   }
	   }
    }
  nbAgents --;
  nbObstacles --;
  tab[0]=nbAgents;
  tab[1]=nbObstacles;
  
  return tab;
}


double * Boids::velocity1(int p) //int p et pas Agent a car si l'utilisateur envoie un agent qui n'est pas dans le tableau ça ne va pas
{

  double * tab = new double[2];
  int * tabNeighbours = neighbours(p,Agent::R);
  double vx = 0;
  double vy = 0;
  int i;
  for(i=0;i<nb_agents; i++)
    {
      if(perception(data[i], data[p], Agent::R))
        {
          vx = (data[i].vx - data[p].vx)/tabNeighbours[0];
          vy = (data[i].vy - data[p].vy)/tabNeighbours[0];
        }
    }
  tab[0]= vx;
  tab[1]=vy;
  return tab;

}

double * Boids::velocity2(int p)
{
  double * tab = new double[2];
  int * tabNeighbours = neighbours(p,Agent::R);
  double x = 0;
  double y = 0;
  int i;
  for(i=0;i<nb_agents; i++)
    {
      if(perception(data[i], data[p], Agent::R))
        {
          x = (data[i].x - data[p].x)/tabNeighbours[0];
          y = (data[i].y - data[p].y)/tabNeighbours[0];
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
