#include <stdio.h>
#include "bwindow.h"
#include "Agent.h"
#include "Boids.h"


int main()
{

   
    Agent a1;
    printf("xa1 : %f  ya1 : %f\n",a1.GetX(),a1.GetY());
    Agent a2;
    printf("xa2 : %f ya2 : %f\n",a2.GetX(),a2.GetY());
    Agent a3 = Agent(true);	
	printf("xa3 : %f ya3: %f\n",a3.GetX(),a3.GetY());
    Agent a4;
    printf("xa4 : %f ya4 : %f\n",a4.GetX(),a4.GetY());
    Agent a5;
    Agent a6;
    Agent a7;
    Agent a8;
    Agent a9;
    Agent a10;

    Boids b;
    b.addAgent(a1);
    b.addAgent(a2);
    b.addAgent(a3);
    b.addAgent(a4);
    b.addAgent(a5);
    b.addAgent(a6);
    b.addAgent(a7);
    b.addAgent(a8);
    b.addAgent(a8);
    b.addAgent(a9);
    b.addAgent(a10);

       
    //printf("%d \n",b.neighbours(0,Agent::R));
    
    /*	
	int * tab = b.neighbours(0,Agent::R);
	printf("%d \n",tab[0]);
	*/
	
	
	//test of the velocity methods
	
	/*
    double * v1 =b.velocity1(0);
    printf("a1v1x : %f v1y : %f \n", v1[0] , v1[1]); //avec velocity1 on obtient  0,0 c'est normal car les deux agents ont la même vitesse
	
	
    double * v2 =b.velocity2(0);
    printf("a1v2x : %f v2y : %f \n", v2[0] , v2[1]); 
    
    double * v3 =b.velocity3(0);
    printf("a1v3x : %f v3y : %f \n", v3[0] , v3[1]); 
    
    b.totalVelocity(1,2,3,1);
    printf("vxa1 : %f  vya1 : %f\n ",b.data[0].vx,b.data[0].vy);  //ATTENTION !!!! QUAND ON MET QUELQUE CHOSE DANS UN TABLEAU ON MET SA COPIE DANS LE TABLEAU PAS L'OBJET LUI MÊME
    */
    /*
    b.position(1,2,3,1);
    printf("a1x : %f  a1y : %f\n ",b.data[0].x,b.data[0].y);  
    */  
    
    /*
	delete [] tab;
    delete [] v1;
    delete [] v2;
    delete [] v3;
    */

    
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
		if(!b.data[i].isObstacle)
		{
		win.draw_fsquare(b.data[i].x-5,b.data[i].y-5,b.data[i].x+5,b.data[i].y+5,0xFF00);	
	    }else{
		win.draw_fsquare(b.data[i].x-5,b.data[i].y-5,b.data[i].x+5,b.data[i].y+5,0x000000);	
		}
	    	
	}
	usleep(10000);
	b.position(1,2,3,0.03);
	
	
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
