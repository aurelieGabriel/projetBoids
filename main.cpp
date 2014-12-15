#include <stdio.h>
#include "bwindow.h"
#include "Agent.h"
#include "Boids.h"


int main()
{

   
    Agent a1;
    printf("%f %f\n ",a1.GetX(),a1.GetY());

    Agent a2;
    printf("%f %f\n",a2.GetX(),a2.GetY());

    Boids b;
    b.addAgent(a1);
    b.addAgent(a2);
   
    printf("%d \n",b.perception(a1,a2));
    int k = b.neighbours(0);
    printf("%d \n",k);


    //test of the velocity methods

    double * v1 =b.velocity2(0);
    printf("%f %f \n", v1[0] , v1[1]); //avec velocity1 on obtient  0,0 c'est normal car les deux agents ont la même vitesse

    delete [] v1;


    /*
    bwindow win(640,480);
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
	win.draw_point(100,100,0xFF00);
	win.draw_line(100,100,200,200,0xFF0000);
	win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));

        
	win.draw_square(200,200,220,220,0xFF00);
	win.draw_fsquare(400,400,440,440,0xFF00);
	
    }
    */
    return 0;
}
