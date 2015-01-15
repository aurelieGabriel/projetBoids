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
      if(perception(data[i], data[p], Agent::R) && !data[i].isObstacle && tabNeighbours[0] != 0)
        {
          vx += (data[i].vx - data[p].vx)/tabNeighbours[0];
          vy += (data[i].vy - data[p].vy)/tabNeighbours[0];
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
  double vx = 0;
  double vy = 0;
  int i;
  for(i=0;i<nb_agents; i++)
    {
      if(perception(data[i], data[p], Agent::R) && !data[i].isObstacle && tabNeighbours[0] != 0)
        {
          vx += (data[i].x - data[p].x)/tabNeighbours[0];
          vy += (data[i].y - data[p].y)/tabNeighbours[0];
        }
    }
  tab[0]= vx;
  tab[1]= vy;
  return tab;
}

double * Boids::velocity3(int p)
{
  double * v3 = new double[2];
  int * voisins = neighbours(p,Agent::C);
  v3[0]=0;
  v3[1]=0;
  int i;
  double v3xa=0,v3xo=0,v3ya=0,v3yo=0; // variables intérmédiaires pour stocker la somme avant de diviser le tout
  for(i=0;i<nb_agents;i++)
    {
          if(perception(data[p],data[i],Agent::C) && !data[i].isObstacle && voisins[0]!=0)
                {
                        v3xa += (data[i].x-data[p].x)/voisins[0];
                        v3ya += (data[i].y-data[p].y)/voisins[0];
                }
          else if(perception(data[p],data[i],Agent::C) && data[i].isObstacle && voisins[1]!=0)
            {
                        v3xo += (data[i].x-data[p].x)/voisins[1];
                        v3yo += (data[i].y-data[p].y)/voisins[1];
            }
        }
  v3[0]= - v3xa - v3xo;
  v3[1]= - v3ya - v3yo;
  
  return v3;
}

double * Boids::velocity4(int p)
{
	double * v4 = new double[2];
	v4[0]=0;
	v4[1]=0;
	double xp;
	double yp;
	int i;
	for(i=0; i<nb_agents; i++)
	{
		if(data[i].isPredateur)
		{
			xp = data[i].x;
			yp = data[i].y;
			
			
		}
	}
	if(sqrt((data[p].x - xp)*(data[p].x - xp) + (data[p].y - yp )*(data[p].y - yp))<Agent::R)
	{
		if(!data[p].isPredateur)
		{
	      v4[0]= -((xp-data[p].x)/sqrt((xp-data[p].x)*(xp-data[p].x)+(yp-data[p].y)*(yp-data[p].y)));
	      v4[1]= -((yp-data[p].y)/sqrt((xp-data[p].x)*(xp-data[p].x)+(yp-data[p].y)*(yp-data[p].y)));
	    }
    }
	return v4;
}

void Boids::totalVelocity(double gamma1, double gamma2, double gamma3, double gamma4, double h)
{

  int i;
  double * v1;
  double * v2;
  double * v3;
  double * v4;
  double k = 0.5;
  double vmax = 50;
  for(i=0; i<nb_agents ; i++)
  {
	  if(!data[i].isObstacle)
	  {
	    v1 = velocity1(i);
	    v2 = velocity2(i);
	    v3 = velocity3(i); 
	    v4 = velocity4(i);
	    if(data[i].y<50)
	    {
	     //data[i].vx += h*(gamma1*v1[0] + gamma2*v2[0] + gamma3*v3[0] + gamma4*v4[0]);
	    
	     data[i].vy = data[i].vy + k ;
	    }
	    else if(data[i].x>1300)
	    {
	     data[i].vx = data[i].vx - k;
	     //data[i].vy += h*(gamma1*v1[1] + gamma2*v2[1] + gamma3*v3[1] +  gamma4*v4[1]);
	    }
	    else if(data[i].y>1000)
	    {
	     //data[i].vx +=h*(gamma1*v1[0] + gamma2*v2[0] + gamma3*v3[0] +  gamma4*v4[0]);
	     data[i].vy = data[i].vy - k ;
	    }
	    else if(data[i].x<50)
	    {
	     data[i].vx = data[i].vx + k;
	     //data[i].vy += h*(gamma1*v1[1] + gamma2*v2[1] + gamma3*v3[1] + gamma4*v4[1]) ;
	    }
	    else
	    {
	    
	 
	    //printf(" dans méthode %d % f %f %f \n",i,v1[0],v2[0],v3[0]);
	    data[i].vx += h*(gamma1*v1[0] + gamma2*v2[0] + gamma3*v3[0] + gamma4*v4[0]);
	    //printf(" dans méthode % f \n",data[i].vx);
	    data[i].vy += h*(gamma1*v1[1] + gamma2*v2[1] + gamma3*v3[1]+ gamma4*v4[1]);   //attention problème on calcule les velocity1 2 et 3 à partir des vx et vy précédents
        }
        
        
        //if()
	    
      }  
  }

}


void Boids::position(double gamma1, double gamma2, double gamma3, double gamma4, double h)
{

  int i;
  this->totalVelocity(gamma1, gamma2, gamma3, gamma4, h);
  for(i=0; i<nb_agents; i++)
    {
	  if(!data[i].isObstacle)
	  {
		data[i].x += h*data[i].vx;
		data[i].y += h*data[i].vy;
	  }
    }
	
}

/*
void Boids::position(double gamma1, double gamma2, double gamma3, double h)
{

  int i;
  this->totalVelocity(gamma1, gamma2, gamma3,h);
  for(i=0; i<nb_agents; i++)
    {
	  if(!data[i].isObstacle)
	  {
	    if(data[i].y<50)
	    {
	     data[i].x += h*(data[i].vx);
	     data[i].y -= h*(data[i].vy/3) ;
	    }
	    else if(data[i].x>1490)
	    {
	     data[i].x -= h*(data[i].vx/3);
	     data[i].y += h*(data[i].vy) ;
	    }
	    else if(data[i].y>1490)
	    {
	     data[i].x += h*(data[i].vx);
	     data[i].y -= h*(data[i].vy/3) ;
	    }
	    else if(data[i].x<50)
	    {
	     data[i].x -= h*(data[i].vx/3);
	     data[i].y += h*(data[i].vy) ;
	    }
	    else
	    {
		  data[i].x += h*data[i].vx;
		  data[i].y += h*data[i].vy;
	    }
	    
	  }
	  printf("%d   %f %f \n",i, data[i].x, data[i].y);
    }
	
}
*/

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
