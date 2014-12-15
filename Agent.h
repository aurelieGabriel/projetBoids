//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __AGENT_H__
#define __AGENT_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================



class Agent
{
  public :
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Agent(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Agent(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================

    inline double GetX(void) const;
    inline double GetY(void) const;
    inline double GetVx(void) const;
    inline double GetVy(void) const;

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================


    // =======================================================================
    //                             Public Attributes
    // =======================================================================

    



  public:

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Agent(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };
    Agent(const Agent &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================

    double x;
    double y;
    double vx;
    double vy;
    static const double R;

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================


// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================
inline double Agent::GetX(void) const
  {
    return x;
  }
inline double Agent::GetY(void) const
  {
    return y;
  }
inline double Agent::GetVx(void) const
  {
    return vx;
  }
inline double Agent::GetVy(void) const
  {
    return vy;
  }

#endif // __AGENT_H__