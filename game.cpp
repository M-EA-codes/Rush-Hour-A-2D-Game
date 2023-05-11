//============================================================================.
// Name        : M Ejaz.cpp
// Author      : FAST CS Department
// Version     : 1.00
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour.
//============================================================================.

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
void moveCar(int &,int &);
void score_deduction(int &, int, int);
void Timer(int m);
void GameDisplay();

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* 
	Function sets canvas size (drawing area) in pixels...
	that is what dimensions (x and y) your game will have
	Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 */
void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

	int xI = 17, yI = 524,incre= 4,score= 0, t=180, o;
	int x2=450, y2=340;
	int x3=250, y3=450;
	int obs_loc_x[5]={125,385,616,416,55};
	int obs_loc_y[5]={435,135,411,253,169};
	int p1x,p1y=492,d1x,d1y=50;
	int p2x,p2y=100,d2x,d2y=650;
	int *ptr1=&p1x;
	string scr;
	
	
	
void drawCar()                        //func for drawing car
{
	DrawSquare(xI, yI, 22, colors[ORANGE]);
	glutPostRedisplay();
}

void other_cars()                      //func used to draw other cars
{
	//c2
	//int x2=450, y2=340;
	DrawSquare(x2, y2, 22, colors[RED]);
	moveCar(x2 ,y2);
	//score_deduction(score, x2, y2);
	
	//c3
	//int x3=250, y3=640;
	DrawSquare(x3, y3, 22, colors[RED]);
	moveCar(x3 ,y3);
	
}

void DrawPassen(int x,int y)                           //function used to draw passenger
{	
	DrawCircle(x,y,8,colors[SLATE_GRAY]);
	glutPostRedisplay();
}

void DrawDest(int x , int y)                  //destination
{
	DrawCircle(x,y,8,colors[GREEN]);
	glutPostRedisplay();

}

void score_deduction(int &score, int xm, int ym)
{
	if(xI==xm+21 && yI==ym)             //
	{
	score -=4;
	}
	if(xm-21==xI &&yI==ym)
	{
	score -=4;
	}
	if(ym+21==yI && xI==xm)
	{
	score -=4;
	}
	if(ym-21==yI && xI==xm)
	{
	score -=4;
	}
	cout<<" score= "<<score<<endl;
}
void draw_obs()
{
		DrawTriangle( 110, 420 , 140, 420 , 125 , 450, colors[GREEN]); 
		DrawTriangle( 370, 110 , 400, 110 , 385 , 140, colors[GREEN]);
		DrawTriangle( 601, 496 , 631, 496 , 616 , 526, colors[GREEN]);
		DrawTriangle( 401, 248 , 431, 248 , 416 , 274, colors[GREEN]);
		DrawTriangle( 40, 144 , 70, 144 , 55 , 174, colors[GREEN]);
		DrawCircle(605,205,10,colors[FIREBRICK]);
}
	bool flag_1 = true;                       //flags for movement 
	bool flag_2 = true;

void moveCar(int &xm ,int &ym)
{
	cout<<"xm "<<xm<<"ym "<<ym<<endl;
	if(xm>=5 && flag_1)
	{
		
		if(xm==681 && ym>=484 && ym<=564)
		{
		xm += 1;
		}
		if(xm==713 && ym>=432 && ym<=488)
		{
		xm += 1;
		}
		if(xm==681 && ym>=392 && ym<=428)
		{
		xm += 1;
		}
		if(xm==721 && ym>=244 && ym<=372)
		{
		xm += 1;
		}
		if(xm==753 && ym>=132 && ym<=184)
		{
		xm += 1;
		}
		if(xm==561 && ym>=184 && ym<=304)
		{
		xm += 1;
		}
		if(xm==513 && ym>=508 && ym<=560)
		{
		xm += 1;
		}
		if(xm==517 && ym>=44 && ym<=96)
		{
		xm += 1;
		}
		if(xm==361 && ym>=92 && ym<=136)
		{
		xm += 1;
		}
		if(xm==433 && ym>=180 && ym<=236)
		{
		xm += 1;
		}
		if(xm==317 && ym>=408 && ym<=448)
		{
		xm += 1;
		}
		if(xm==357 && ym>=352 && ym<=408)
		{
		xm += 1;
		}
		if(xm==317 && ym>=316 && ym<=356)
		{
		xm += 1;
		}
		if(xm==197 && ym>=432 && ym<=484)
		{
		xm += 1;
		}
		if(xm==161 && ym>=164 && ym<=336)
		{
		xm += 1;
		}
		if(xm==237 && ym>=80 && ym<=136)
		{
		xm += 1;
		}
		if(xm==121 && ym>=24 && ym<=84)
		{
		xm += 1;
		}
		
		xm-=1;
		
		if(xm<=6)
		flag_1=false;
		
		for(int i=0;i<6;i++)
		{
		if(xm-5==obs_loc_x[i] && ym==obs_loc_y[i])
		flag_1=false;
		}
	}
	if(xm<=765 && !flag_1)
	{	

/*		
		if(xm>=17 && xm<=33 && ym>=152 && ym<=172)
		{
		score_deduction(score);
		}
*/
		if(xm==137 && ym>=508 && ym<=560)
		{
		xm -= 1;
		}
		if(xm==57 && ym>=432 && ym<=484)
		{
		xm -= 1;
		}		
		if(xm==57 && ym>=284 && ym<=336)
		{
		xm -= 1;
		}
		if(xm==17 && ym>=80 && ym<=136)
		{
		xm -= 1;
		}
		if(xm==97 && ym>=164 && ym<=280)
		{
		xm -= 1;
		}
		if(xm==57 && ym>=24 && ym<=80)
		{
		xm -= 1;
		}
		if(xm==617 && ym>=488 && ym<=564)
		{
		xm -= 1;
		}
		if(xm==337 && ym>=432 && ym<=488)
		{
		xm -= 1;
		}
		if(xm==617 && ym>=392 && ym<=428)
		{
		xm -= 1;
		}
		if(xm==257 && ym>=408 && ym<=448)
		{
		xm -= 1;
		}
		if(xm==177 && ym>=352 && ym<=408)
		{
		xm -= 1;
		}
		if(xm==257 && ym>=316 && ym<=356)
		{
		xm -= 1;
		}
		if(xm==177 && ym>=180 && ym<=236)
		{
		xm -= 1;
		}
		if(xm==297 && ym>=44 && ym<=136)
		{
		xm -= 1;
		}
		if(xm==657 && ym>=244 && ym<=372)
		{
		xm -= 1;
		}
		if(xm==497 && ym>=132 && ym<=304)
		{
		xm -= 1;
		}
		
		xm+=1;
		
		if(xm>=765)
		flag_1=true;
			
		if(xm==257 && ym==257)
		{
		flag_1=true;
		}
		if(xm==57 && ym==76)
		{
		flag_1=true;
		}
		if(xm==617 && ym==541)
		{
		flag_1=true;
		}
		if(xm==617 && ym==492)
		{
		flag_1=true;
		}
	
		for(int i=0;i<6;i++)
		{
		if(xm+5==obs_loc_x[i] && ym==obs_loc_y[i])
		flag_1=true;
		}
	}
	
	if(ym>=8 && flag_2)
	{
		
		if(ym==564 && xm>=141 && xm<=509)
		{
		ym += 1;
		}
		if(ym==568 && xm>=621 && xm<=677)
		{
		ym += 1;
		}
		if(ym==488 && xm>=61 && xm<=193)
		{
		ym += 1;
		}
		if(ym==492 && xm>=341 && xm<=709)
		{
		ym += 1;
		}
		if(ym==412 && xm>=181 && xm<=353)
		{
		ym += 1;
		}
		if(ym==452 && xm>=261 && xm<=313)
		{
		ym += 1;
		}
		if(ym==376 && xm>=661 && xm<=717)
		{
		ym += 1;
		}
		if(ym==340 && xm>=61 && xm<=157)
		{
		ym += 1;
		}
		if(ym==308 && xm>=501 && xm<=557)
		{
		ym += 1;
		}
		if(ym==240 && xm>=181 && xm<=429)
		{
		ym += 1;
		}
		if(ym==140 && xm>=21 && xm<=233)
		{
		ym += 1;
		}
		if(ym==140 && xm>=301 && xm<=357)
		{
		ym += 1;
		}
		if(ym==100 && xm>=361 && xm<=513)
		{
		ym += 1;
		}
		if(ym==188 && xm>=561 && xm<=749)
		{
		ym += 1;
		}
		ym-=1;
		
		if(ym<=9)
		flag_2=false;
		
		if(xm==317 && ym==412)
		{
		flag_2=false;
		}
		if(xm==362 && ym==100)
		{
		flag_2=false;
		}
		if(xm==562 && ym==188)
		{
		flag_2=false;
		}

		for(int i=0;i<6;i++)
		{
		if(ym-5==obs_loc_x[i] && ym==obs_loc_y[i])
		flag_2=false;
		}

	}
	
	if(ym<=540 && !flag_2)
	{
		
		if(ym==504 && xm>=141 && xm<=509)
		{
		ym -= 1;
		}
		if(ym==428 && xm>=61 && xm<=193)
		{
		ym -= 1;
		}
		if(ym==428 && xm>=341 && xm<=709)
		{
		ym -= 1;
		}
		if(ym==388 && xm>=621 && xm<=677)
		{
		ym -= 1;
		}
		if(ym==348 && xm>=181 && xm<=353)
		{
		ym -= 1;
		}
		if(ym==312 && xm>=261 && xm<=313)
		{
		ym -= 1;
		}
		if(ym==280 && xm>=61 && xm<=97)
		{
		ym -= 1;
		}
		if(ym==160 && xm>=101 && xm<=157)
		{
		ym -= 1;
		}
		if(ym==240 && xm>=661 && xm<=717)
		{
		ym -= 1;
		}
		if(ym==176 && xm>=181 && xm<=429)
		{
		ym -= 1;
		}
		if(ym==128 && xm>=501 && xm<=749)
		{
		ym -= 1;
		}
		if(ym==176 && xm>=181 && xm<=429)
		{
		ym -= 1;
		}
		if(ym==40 && xm>=301 && xm<=513)
		{
		ym -= 1;
		}
		if(ym==76 && xm>=21 && xm<=233)
		{
		ym -= 1;
		}
		if(ym==20 && xm>=61 && xm<=117)
		{
		ym -= 1;
		}
		
		ym+=1;
		
		if(ym>=539)
		flag_2=true;
				
		if(xm==318 && ym==348)
		{
		flag_2=true;
		}
		
		if(xm==256 && ym==348)
		{
		flag_2=true;
		}
				
		if(xm==617 && ym==428)
		{
		flag_2=true;
		}
		if(xm==682 && ym==428)
		{
		flag_2=true;
		}

		for(int i=0;i<6;i++)
		{
		if(ym+5==obs_loc_x[i] && ym==obs_loc_y[i])
		flag_2=true;
		}
			
	}
}

void main_menu()
{
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors	
	
	DrawString( 350, 450, "PLAY", colors[BROWN]);
	DrawString( 350, 350, "LEADER BOARD", colors[BROWN]);
	
	DrawString( 350, 250, "Press P to play and L to see leaderboard", colors[YELLOW]);                  //interactive menu
	
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..
}
/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(192/*Red Component*/, 192,	//148.0/255/*Green Component*/,
			192/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Score
	
	DrawString( 5, 580, "Score= ", colors[BROWN]);
	DrawString( 85, 580 ,scr, colors[BROWN]);
		
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	

	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	
	for(int g=40;g<=760;g+=40)
	{
	DrawLine(  g , 1 ,   g , 570 , 2 , colors[BROWN] );
	}


/*	DrawCircle(50,670,10,colors[RED]);
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
*/	

	DrawLine(  0 , 570 ,   800 , 570 , 5 , colors[BROWN] );
	DrawLine(  0 , 3 ,   800 , 3 , 5 , colors[BROWN] );
	DrawLine(  2 , 1 ,   2 , 570 , 5 , colors[BROWN] );
	DrawLine(  798 , 1 ,   798 , 570 , 5 , colors[BROWN] );

	DrawSquare( 80, 450, 40, colors[AQUA]);
	DrawSquare(119, 450, 40, colors[AQUA]);
	DrawSquare(158, 450, 40, colors[AQUA]);

	for(int i=360;i<=700;i+=39)
	{
	DrawSquare(i, 450, 40, colors[AQUA]);
	}
	
	DrawSquare( 80, 300, 40, colors[AQUA]);

	for(int i=183;i<=300;i+=39)
{	
	DrawSquare(119, i, 40, colors[AQUA]);
}

	for(int i=200;i<=317;i+=39)
{
	DrawSquare(i, 372, 40, colors[AQUA]);
}

	for(int i=333;i<=411;i+=39)
{
	DrawSquare(278, i, 40, colors[AQUA]);
}
	for(int i=160;i<=480;i+=39)
{
	DrawSquare(i, 525, 40, colors[AQUA]);
}

	for(int i=40;i<=200;i+=39)
{
	DrawSquare(i, 100, 40, colors[AQUA]);
}

	for(int i=40;i<=100;i+=39)
{
	DrawSquare(80, i, 40, colors[AQUA]);
}
	for(int i=200;i<=400;i+=39)
{
	DrawSquare(i, 200, 40, colors[AQUA]);
}
	for(int i=410;i<=560;i+=39)
{
	DrawSquare(640, i, 40, colors[AQUA]);
}
	for(int i=260;i<=360;i+=39)
{
	DrawSquare(680, i, 40, colors[AQUA]);
}
	for(int i=520;i<=720;i+=39)
{
	DrawSquare(i,150, 40, colors[AQUA]);
}
	for(int i=150;i<=300;i+=39)
{
	DrawSquare(520,i, 40, colors[AQUA]);
}
	for(int i=320;i<=480;i+=39)
{
	DrawSquare(i,60, 40, colors[AQUA]);
}
	for(int i=60;i<=120;i+=39)
{
	DrawSquare(320,i, 40, colors[AQUA]);
}

/*	DrawRoundRect(500,200,50,15,colors[LAVENDER],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);		
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
*/
	other_cars();
	drawCar();
	DrawPassen(p1x,p1y);

	if(p1x>1000)
	{
	DrawDest(d1x , d1y);
	}
	
	DrawPassen(p2x,p2y);
	if(p2x>1000)
	{
	DrawDest(d2x , d2y);
	}
	draw_obs();
	scr=Num2Str(score);
	score_deduction(score, x2, y2);
	score_deduction(score, x3, y3);
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT && xI>=5 && xI-4>=5 /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
	{
		// what to do when left key is pressed...
		if(xI==681 && yI>=484 && yI<=564)
		{
		xI += incre;
		}
		if(xI==713 && yI>=432 && yI<=488)
		{
		xI += incre;
		}
		if(xI==681 && yI>=392 && yI<=428)
		{
		xI += incre;
		}
		if(xI==721 && yI>=244 && yI<=372)
		{
		xI += incre;
		}
		if(xI==753 && yI>=132 && yI<=184)
		{
		xI += incre;
		}
		if(xI==561 && yI>=184 && yI<=304)
		{
		xI += incre;
		}
		if(xI==513 && yI>=508 && yI<=560)
		{
		xI += incre;
		}
		if(xI==517 && yI>=44 && yI<=96)
		{
		xI += incre;
		}
		if(xI==361 && yI>=92 && yI<=136)
		{
		xI += incre;
		}
		if(xI==433 && yI>=180 && yI<=236)
		{
		xI += incre;
		}
		if(xI==317 && yI>=408 && yI<=448)
		{
		xI += incre;
		}
		if(xI==357 && yI>=352 && yI<=408)
		{
		xI += incre;
		}
		if(xI==317 && yI>=316 && yI<=356)
		{
		xI += incre;
		}
		if(xI==197 && yI>=432 && yI<=484)
		{
		xI += incre;
		}
		if(xI==161 && yI>=164 && yI<=336)
		{
		xI += incre;
		}
		if(xI==237 && yI>=80 && yI<=136)
		{
		xI += incre;
		}
		if(xI==121 && yI>=24 && yI<=84)
		{
		xI += incre;
		}

		xI -= incre;
		
		for(int i=0;i<6;i++)
		{
		if(xI-incre==obs_loc_x[i] && yI==obs_loc_y[i])
		xI -= incre;
		}
		cout<<"X-axis= "<<xI<<endl;
	} else if (key== GLUT_KEY_RIGHT && xI<=770 && xI+4<=770/*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		
/*
		if(x>=17 && x<=33 && yI>=152 && yI<=172)
		{
		score_deduction(score);
		}
*/
		if(xI==137 && yI>=508 && yI<=560)
		{
		xI -= incre;
		}
		if(xI==57 && yI>=432 && yI<=484)
		{
		xI -= incre;
		}		
		if(xI==57 && yI>=284 && yI<=336)
		{
		xI -= incre;
		}
		if(xI==17 && yI>=80 && yI<=136)
		{
		xI -= incre;
		}
		if(xI==97 && yI>=164 && yI<=280)
		{
		xI -= incre;
		}
		if(xI==57 && yI>=24 && yI<=80)
		{
		xI -= incre;
		}
		if(xI==617 && yI>=488 && yI<=564)
		{
		xI -= incre;
		}
		if(xI==337 && yI>=432 && yI<=488)
		{
		xI -= incre;
		}
		if(xI==617 && yI>=392 && yI<=428)
		{
		xI -= incre;
		}
		if(xI==257 && yI>=408 && yI<=448)
		{
		xI -= incre;
		}
		if(xI==177 && yI>=352 && yI<=408)
		{
		xI -= incre;
		}
		if(xI==257 && yI>=316 && yI<=356)
		{
		xI -= incre;
		}
		if(xI==177 && yI>=180 && yI<=236)
		{
		xI -= incre;
		}
		if(xI==297 && yI>=44 && yI<=136)
		{
		xI -= incre;
		}
		if(xI==657 && yI>=244 && yI<=372)
		{
		xI -= incre;
		}
		if(xI==497 && yI>=132 && yI<=304)
		{
		xI -= incre;
		}		
		xI += incre;
		cout<<"X-axis= "<<xI<<endl;
	} else if (key== GLUT_KEY_UP && yI<=548 && yI+4<=548/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if(yI==504 && xI>=141 && xI<=509)
		{
		yI -= incre;
		}
		if(yI==428 && xI>=61 && xI<=193)
		{
		yI -= incre;
		}
		if(yI==428 && xI>=341 && xI<=709)
		{
		yI -= incre;
		}
		if(yI==388 && xI>=621 && xI<=677)
		{
		yI -= incre;
		}
		if(yI==348 && xI>=181 && xI<=353)
		{
		yI -= incre;
		}
		if(yI==312 && xI>=261 && xI<=313)
		{
		yI -= incre;
		}
		if(yI==280 && xI>=61 && xI<=97)
		{
		yI -= incre;
		}
		if(yI==160 && xI>=101 && xI<=157)
		{
		yI -= incre;
		}
		if(yI==240 && xI>=661 && xI<=717)
		{
		yI -= incre;
		}
		if(yI==176 && xI>=181 && xI<=429)
		{
		yI -= incre;
		}
		if(yI==128 && xI>=501 && xI<=749)
		{
		yI -= incre;
		}
		if(yI==176 && xI>=181 && xI<=429)
		{
		yI -= incre;
		}
		if(yI==40 && xI>=301 && xI<=513)
		{
		yI -= incre;
		}
		if(yI==76 && xI>=21 && xI<=233)
		{
		yI -= incre;
		}
		if(yI==20 && xI>=61 && xI<=117)
		{
		yI -= incre;
		}
		yI += incre;
		cout<<"Y-axis= "<<yI<<endl;
	}

	else if (key== GLUT_KEY_DOWN  && yI>=8 && yI-4>=8 /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		
		if(yI==564 && xI>=141 && xI<=509)
		{
		yI += incre;
		}
		if(yI==568 && xI>=621 && xI<=677)
		{
		yI += incre;
		}
		if(yI==488 && xI>=61 && xI<=193)
		{
		yI += incre;
		}
		if(yI==492 && xI>=341 && xI<=709)
		{
		yI += incre;
		}
		if(yI==412 && xI>=181 && xI<=353)
		{
		yI += incre;
		}
		if(yI==452 && xI>=261 && xI<=313)
		{
		yI += incre;
		}
		if(yI==376 && xI>=661 && xI<=717)
		{
		yI += incre;
		}
		if(yI==340 && xI>=61 && xI<=157)
		{
		yI += incre;
		}
		if(yI==308 && xI>=501 && xI<=557)
		{
		yI += incre;
		}
		if(yI==240 && xI>=181 && xI<=429)
		{
		yI += incre;
		}
		if(yI==140 && xI>=21 && xI<=233)
		{
		yI += incre;
		}
		if(yI==140 && xI>=301 && xI<=357)
		{
		yI += incre;
		}
		if(yI==100 && xI>=361 && xI<=513)
		{
		yI += incre;
		}
		if(yI==188 && xI>=561 && xI<=749)
		{
		yI += incre;
		}
		yI -= incre;
		cout<<"Y-axis= "<<yI<<endl;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if(key==112)
	{
	glutDisplayFunc(GameDisplay);
	}
	if(key==32)
	{
		if((xI>=p1x-12 && xI<=p1x+12) || xI==p1x+7 || xI==p1x-7 || xI==p1x+19 || xI==p1x-19)
		p1x+=1000;
		
		if((yI==p1y-12 && yI==p1y+12) || yI==p1y+7 || yI==p1y-7 || yI==p1y+19 || yI==p1y-19)
		p1x+=1000;
		
		if((xI==d1x-12 && xI==d1x+12) || xI==d1x+7 || xI==d1x-7 || yI==d1y+19 || yI==d1y-19)
	{
		d1x+=1000;
		score+=10;
	}	
		if((yI>=d1y-12 && yI<=d1y+12) || yI==d1y+7 || yI==d1y-7 || yI==d1y+19 || yI==d1y-19)
	{
		d1x+=1000;
		score+=10;
	}

		if((xI>=p2x-12 && xI<=p2x+12) || xI==p2x+7 || xI==p2x-7 || xI==p2x+19 || xI==p2x-19)
		p2x+=1000;
	
		if((yI>=d2y-12 && yI<=d2y+12) || yI==d2y+7 || yI==d2y-7 || yI==d2y+19 || yI==d2y-19)
	{
		d2x+=1000;
		score+=10;
	}
	
		//space pressed
	}
	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
 
void game_finish(int m)
{

	t--;
	if(t==0);
	{
		exit(1);
	}
	glutTimerFunc(100, Timer, 10);
}

void Timer(int m) 
{

	// implement your functionality here
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000, Timer, 0);
}



/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) 
	{

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 800, height = 600; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Fastian"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	main_menu();
	//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1.0, Timer, 0);
	Timer(1); 
	
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	glutTimerFunc(1000.0, Timer, 0);
	glutTimerFunc(1000.0, Timer, 0);
	
	p1x=GetRandInRange(20, 550);
	p1y=500;
	
	d1x=GetRandInRange(520, 730);
	d1y=50;
	
	p2x=GetRandInRange(20,50);
	p2y=100;
	
	d2x=GetRandInRange(620,650);
	d2y=620;
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
