#include <stdio.h>
#include "bwindow.h"
#include "Agent.h"
#include "Boids.h"
#include "Predateur.h"
#include<typeinfo>

int main()
{

   Boids b;
  /* Agent o1 = Agent(true);
   Agent o2 = Agent(true);
   Agent o3 = Agent(true);
   Agent o4 = Agent(true);
   b.addAgent(o1);
   b.addAgent(o2);
   b.addAgent(o3);
   b.addAgent(o4);
   
 
   Agent o1=Agent(true);
   b.addAgent(o1);
   Agent o2 =Agent(true);
   b.addAgent(o2);*/

    
    bwindow win(1500,1500);
    printf("%d\n",win.init());
    win.map();
    for(;;)
    {
	int ev = win.parse_event();
	switch(ev)
	{
	    case BKPRESS :
		printf("keypressed\n"); 
		printf("key : %s\n",win.get_lastkey());
		break;
	    case BBPRESS:
		printf("buttonpressed\n"); break;
	    case BEXPOSE:
		printf("expose\n"); break;
	    case BCONFIGURE:
		printf("configure\n"); break;
	}
	int i;
	win.draw_fsquare(0,0,1500,1500,0xFEFEFE);
	
	for(i=0; i<b.nb_agents;i++)
	{
		if(!b.data[i].isObstacle && !b.data[i].isPredateur)
		{
		win.draw_fsquare(b.data[i].x-2,b.data[i].y-2,b.data[i].x+2,b.data[i].y+2,0x3DB600);	
	    }else if(b.data[i].isObstacle){
		win.draw_fsquare(b.data[i].x-3,b.data[i].y-3,b.data[i].x+3,b.data[i].y+3,0x000000);	
		}
	}
	for(i=0;i<1;i++)
	{
		win.draw_fsquare(b.datap[i].x-5,b.datap[i].y-5,b.datap[i].x+5,b.datap[i].y+5,0xDB001D);
	}
	
	
	usleep(3000);
	b.position(0.3,0.3,2,5,0.2);
	
	
	
	
    }
    
    return 0;
}
