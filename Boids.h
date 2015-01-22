//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __BOIDS_H__
#define __BOIDS_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include "Agent.h"
#include "Predateur.h"




// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================



class Boids
{
  public :
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Boids(void);
    

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Boids(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================


    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================

    void addAgent(Agent a);
    bool perception(Agent a1, Agent a2 , double distance);
    int * neighbours( int position, double distance);  // car dépend si le rayon de proximité c'est r ou c
    double * velocity1(int p);
    double * velocity2(int p);
    double * velocity3(int p);
    double * velocity4(int p);
    void totalVelocity(double gamma1, double gamma2, double gamma3, double gamma4, double h);
    void position(double gamma1, double gamma2, double gamma3, double gamma4, double h);
    Agent predateurVoitProie(Predateur p);
    int proiePresDePredateur(Predateur p);
    void mangerProie(Agent a, Predateur p);
    void nouveauPredateur();
    // =======================================================================
    //                             Public Attributes
    // =======================================================================

    
  public :


    Predateur * datap;
    Agent * data;
    int nb_agents;


};



#endif // __BOIDS_H__
