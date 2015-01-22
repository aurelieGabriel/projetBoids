#include <stdio.h>
#include "bwindow.h"
#include "Agent.h"
#include "Boids.h"
#include "Predateur.h"
#include<typeinfo>

int main()
{

   Boids b;
   Agent o1 = Agent(true);
   Agent o2 = Agent(true);
   Agent o3 = Agent(true);
   Agent o4 = Agent(true);
   b.addAgent(o1);
   b.addAgent(o2);
   b.addAgent(o3);
   b.addAgent(o4);


    
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
		win.draw_fsquare(b.data[i].x-2,b.data[i].y-2,b.data[i].x+2,b.data[i].y+2,0x000000);	
		}
	}
	for(i=0;i<1;i++)
	{
		win.draw_fsquare(b.datap[i].x-5,b.datap[i].y-5,b.datap[i].x+5,b.datap[i].y+5,0xDB001D);
	}
	/*
	for(i=0; i<b.nb_agents;i++)
	{
		if((!b.data[i].isObstacle) )
		{
		  if((typeid(Predateur)!=typeid(b.data[i])))
		  {
		    win.draw_fsquare(b.data[i].x-2,b.data[i].y-2,b.data[i].x+2,b.data[i].y+2,0xFF00);	
		  }
		  else
		  {
			  win.draw_fsquare(b.data[i].x-2,b.data[i].y-2,b.data[i].x+2,b.data[i].y+2,0x8DD9E2);
		  }
	    }
	    else 
	    {
		win.draw_fsquare(b.data[i].x-5,b.data[i].y-5,b.data[i].x+5,b.data[i].y+5,0x000000);	
		}
	    	
	}*/
	
	usleep(10000);
	b.position(0.1,0.1,1.5,2.5,0.1);
	
	
	//win.draw_fsquare(90,90,110,110,0xFF00);
	//win.draw_fsquare(b.data[0].x-10,b.data[0].y-10,b.data[0].x+10,b.data[0].y+10,0x8DD9E2);
	
	/*
	win.draw_fsquare(90,90,110,110,0xFF00);
	win.draw_fsquare(0,0,640,480,0xFEFEFE);
	win.draw_fsquare(b.data[1].x-5,b.data[1].y-5,b.data[1].x+5,b.data[1].y+5,0xFF00);
	*/
	
	 
	
	//win.draw_point(100,100,0xFF00);
	//win.draw_line(100,100,200,200,0xFF0000);
	//win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));    
	//win.draw_square(200,200,220,220,0xFF00);  //carré vide
	//win.draw_fsquare(400,400,440,440,0xFF00);  //carré plein
	
    }
    
    return 0;
}
