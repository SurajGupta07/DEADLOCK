

#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
float mx=300;
float my=900;
int left=0,right=1000,bottom=0,top=1000;
float x,y,e,h,g,t=0,tt=0;
void next();
int i,j,move=1,flag=1,f=1,eye = 0;
int spotdisp=1;
float p=0.0,q=0.0;
GLfloat pp=0.0;
int mxx=100;
int myy=100;
int nx=125,ny=100;
int up=0,down=0;
float sx=0,sy=0;
int carmov=0;
int beandisp=1,bean1disp=1;
int dstate=0,cstate=0,fstate=0,gstate=0,hstate=0,istate=0;
int aa=780,bb=380;
int cc=600,dd=100,nn=100,ni=800,da=10;
int ee=0,ff=0,mmm=700,nnn=200;
int gg=700,hh=250,sss=200,vvv=900,ssss=0;
int xxx=0;

GLubyte Pat[]={
	0x00,0x02,0x00,0x00,
	0x00,0x07,0x00,0x00,
	0x00,0x0F,0x80,0x00,
	0x00,0x1F,0xC0,0x00,
	0x00,0x3F,0xE0,0x00,
	0x00,0x7F,0xF0,0x00,
	0x00,0x3F,0xE0,0x00,
	0x00,0x1F,0xC0,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0xF3,0x3E,0x00,
	0x00,0xF3,0x3F,0x00,
	0x01,0xF3,0x9F,0x80,
	0x03,0xEF,0xCF,0xA0,
	0x07,0xEF,0xCF,0xC0,
	0x0F,0xCF,0xC7,0xE0,
	0x1F,0x8F,0xC3,0xF0,
	0x3F,0x0F,0xC1,0xF8,
	0x7E,0x0F,0xC0,0xFC,
	0x7C,0x0F,0xC0,0x7E,
	0x78,0x0F,0xC0,0x3E,
	0x00,0x0F,0xC0,0x00,
	0x00,0x0F,0xC0,0x00,
	0x00,0x0F,0xC0,0x00,
	0x00,0x0F,0xC0,0x00,
	0x00,0x0F,0xC0,0x00,
	0x00,0x0F,0xC0,0x00,
	0x00,0x0F,0xC0,0x00,
	0x00,0x0F,0xC0,0x00,
        0x00,0x07,0x80,0x00,
        0x00,0x03,0x00,0x00,
        0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00 };
int a=0,b=0;

float angle=0;
int axis=1;



void renderBitmapString(float x,float y,const char *string)
{
	const char *c;
	glRasterPos2f(x,y);
    	//glColor3f(1,0,0);
	for (c=string;*c !='\0';c++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c) ;

}
void BitmapString(float x,float y,const char *string)
{
	const char *c;
	glRasterPos2f(x,y);
	for (c=string;*c !='\0';c++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,*c) ;

}
void myinit()
{
    	glClearColor(0.71875,0.9140625,0.97265625,1.0);
    	glColor3f(0.0,0.0,0.0);
     	glMatrixMode(GL_PROJECTION);
    	gluOrtho2D(0,1000,0,1000);
    	glMatrixMode(GL_MODELVIEW);
}
void SpecialKey(int key,int x,int y){
	switch(key){

	case GLUT_KEY_UP:
	up=1;

	break;

	case GLUT_KEY_DOWN:
	down=1;
	break;
}
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glMatrixMode(GL_MODELVIEW);
	int j;
	float theta, x, y, i;
	glBegin(GL_POLYGON);
	for(j = 0; j < num_segments; j++)
	{

	i = (float)j/(float)num_segments;
	theta = 2.0f*3.1415926f*i;
	x = r * cosf(theta);
	y = r * sinf(theta);
	glVertex2f(x + cx, y + cy);

	}
	glEnd();
	glFlush();
}



void bean(){
	glColor3f(1,1,1);//white shirt
	glBegin(GL_POLYGON);
	glVertex2f(20,90);
	glVertex2f(40,100);
	glVertex2f(40,150);
	glVertex2f(60,150);
	glVertex2f(60,100);
	glVertex2f(80,90);
	glEnd();


	glColor3f(1,0,0);//coat left
	glBegin(GL_POLYGON);
	glVertex2f(20,90);
	glVertex2f(40,100);
	glVertex2f(40,150);
	glVertex2f(20,143);
	glEnd();

	glBegin(GL_POLYGON);//left sleve
	glVertex2f(10,100);
	glVertex2f(20,100);
	glVertex2f(20,143);
	glVertex2f(10,140);
	glEnd();

	glColor3f(0.92, 0.75, 0.53);
	glBegin(GL_POLYGON);//left hand
	glVertex2f(10,100);
	glVertex2f(20,100);
	glVertex2f(20,90);
	glVertex2f(10,90);
	glEnd();

	glColor3f(1,0,0);
	glBegin(GL_POLYGON);//right sleve
	glVertex2f(90,100);
	glVertex2f(80,100);
	glVertex2f(80,143);
	glVertex2f(90,140);
	glEnd();

	glColor3f(0.92, 0.75, 0.53);// right hand
	glBegin(GL_POLYGON);
	glVertex2f(90,100);
	glVertex2f(80,100);
	glVertex2f(80,90);
	glVertex2f(90,90);
	glEnd();

	

	glColor3f(0,0,0);//belt
	glBegin(GL_POLYGON);
	glVertex2f(20,80);
	glVertex2f(20,90);
	glVertex2f(80,90);
	glVertex2f(80,80);
	glEnd();

	

	glColor3f(0,0,0);//pant
	glBegin(GL_POLYGON);
	glVertex2f(20,0);
	glVertex2f(20,80);
	glVertex2f(50,80);
	glVertex2f(40,0);
	glEnd();

	glColor3f(0,0,0);//pant
	glBegin(GL_POLYGON);
	glVertex2f(80,0);
	glVertex2f(80,80);
	glVertex2f(50,80);
	glVertex2f(60,0);
	glEnd();



	glColor3f(0.92, 0.75, 0.53);//face
	glBegin(GL_POLYGON);
	glVertex2f(30,160);
	glVertex2f(40,150);
	glVertex2f(60,150);
	glVertex2f(70,160);

	glVertex2f(70,200);
	glVertex2f(30,200);

	glEnd();

	glColor3f(0.41, 0.24, 0.13);//hair
	glBegin(GL_POLYGON);
	glVertex2f(30,200);


	glVertex2f(70,200);

	glVertex2f(70,230);
	glVertex2f(50,230);

	//glVertex2f(30,245);
	glEnd();
	//eyes
	if(eye == 0)	
	{
	glColor3f(0, 0, 0);
	eye = 1;
	}
	else
	{
	glColor3f(0.92, 0.75, 0.53);	
	eye = 0;
	}	
	 DrawCircle(40,190.0,5.0,100);
	 DrawCircle(60,190.0,5.0,100);
	
	glColor3f(0,0,0);//mouth
	glBegin(GL_LINE_STRIP);
	glVertex2f(40,162);
	glVertex2f(50,159);
	glVertex2f(60,162);
	glVertex2f(40,162);
	glEnd();

	glColor3f(0,0,0);//nose
	glBegin(GL_LINE_STRIP);
	glVertex2f(55,170);	
	glVertex2f(50,170);
	glVertex2f(50,180);
	glEnd();

}


void scene4(){
glColor3f(0,0,0);//floor
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(850,100);
	glVertex2i(150,100);
	glEnd();
glColor3f(1,0,0);//work space
	glBegin(GL_POLYGON);
	glVertex2i(150,100);
	glVertex2i(850,100);
	glVertex2i(850,900);
	glVertex2i(150,900);
	glEnd();
glColor3f(0,0,1);//roof
	glBegin(GL_POLYGON);
	glVertex2i(150,900);
	glVertex2i(850,900);
	glVertex2i(1000,1000);
	glVertex2i(0,1000);
	glEnd();
glColor3f(0,0,0);//board
	glBegin(GL_POLYGON);
	glVertex2i(250,300);
	glVertex2i(600,300);
	glVertex2i(600,600);
	glVertex2i(250,600);
	glEnd();
glColor3f(1,1,1);//board boundary
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2i(250,300);
	glVertex2i(600,300);
	glVertex2i(600,300);
	glVertex2i(600,600);
	glVertex2i(600,600);
	glVertex2i(250,600);
	glVertex2i(250,300);
	glVertex2i(250,600);
	glEnd();
//*****************************
glColor3f(1,1,1);//background stuff
	glBegin(GL_POLYGON);
	glVertex2i(650,100);
	glVertex2i(850,100);
	glVertex2i(850,400);
	glVertex2i(650,400);
	glEnd();

	glColor3f(0,0.3,0);//background
	glBegin(GL_POLYGON);
	glVertex2i(700,140);
	glVertex2i(850,100);
	glVertex2i(850,400);
	glVertex2i(700,360);
	glEnd();

	
}
void door(){
	glColor3f(0.2,0.3,0);//door
	
	glBegin(GL_POLYGON);
	glVertex2i(650,100);
	glVertex2i(850,100);
	glVertex2i(850,400);
	glVertex2i(650,400);
	glEnd();


}

void scene2(){
	
	
	glColor3f(0,0,0);//TEEEEEEEEEEESTTTTTT
	glLineWidth(5);
	glBegin(GL_POLYGON);
	glVertex2i(0,900);
	glVertex2i(300,900);
	glVertex2i(800,20);
	glVertex2i(700,20);
	glVertex2i(200,800);
	glVertex2i(0,800);
	glVertex2i(0,900);
	
	
	glColor3f(1,0,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(700,0);
	glVertex2i(800,20);
	glVertex2i(300,800);
	glVertex2i(0,800);
	
	
	glEnd();
	

}
	
void next()
{	scene2();
	glColor3f(0.16, 0.16, 0.16);//background
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(1000,1000);
	glVertex2i(0,1000);
	glEnd();
	glColor3f(1,1,1);
	 DrawCircle(150,900.0,30.0,100);
	scene2();
	glColor3f(0,1,1);//background
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(1000,75);
	glVertex2i(0,75);
	glEnd();	
	glPushMatrix();
	glTranslatef(sss,vvv,0);

	if(up==1 && sss<500)
{
	sss++;
if(vvv>600)vvv=vvv-.5;

	bean();
	glPopMatrix();}
	
	glFlush();
	//f==3; 
//***********************************************************FOR BOTTOM TO TOP******************
glPushMatrix();
	glTranslatef(mmm,nnn,0);
	
	if(up==1 && nnn<500)
{
	nnn++;
if(mmm>350)mmm--;

	bean();
	glPopMatrix();
	}
if(sss>=490)
{	
	ssss=1;
}


	glFlush();	
}

void scene3(){
               // glClearColor(0.71875,0.9140625,0.97265625,1.0);
glClearColor(1,1,1,1);

	glColor3f(1,0,0);	
glBegin(GL_POLYGON);
	glVertex2i(100,500);
	glVertex2i(150,500);
	glVertex2i(150,550);
	glVertex2i(100,550);
	glEnd();
glBegin(GL_POLYGON);
	glVertex2i(350,500);
	glVertex2i(400,500);
	glVertex2i(400,550);
	glVertex2i(350,550);
	glEnd();
glBegin(GL_POLYGON);
	glVertex2i(600,500);
	glVertex2i(650,500);
	glVertex2i(650,550);
	glVertex2i(600,550);
	glEnd();
glBegin(GL_POLYGON);
	glVertex2i(850,500);
	glVertex2i(900,500);
	glVertex2i(900,550);
	glVertex2i(850,550);
	glEnd();
glBegin(GL_POLYGON);
	glVertex2i(225,800);
	glVertex2i(275,800);
	glVertex2i(275,850);
	glVertex2i(225,850);
	glEnd();
glBegin(GL_POLYGON);
	glVertex2i(725,800);
	glVertex2i(775,800);
	glVertex2i(775,850);
	glVertex2i(725,850);
	glEnd();
glColor3f(0.13, 0.16, 0.39);
 DrawCircle(50,665,25,200);//first
 DrawCircle(250,665,25,200);//second
  DrawCircle(450,665,25,200);//third
 DrawCircle(550,665,25,200);//fourth
 DrawCircle(750,665,25,200);//fifth
 DrawCircle(950,665,25,200);//sixth
	glColor3f(0,1,0);//board boundary
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2i(100,525);
	glVertex2i(50,640);//1
	glColor3f(1,1,0);
	glVertex2i(50,690);
	glVertex2i(225,825);//2
	glVertex2i(150,525);
	glVertex2i(250,640);//3
	glVertex2i(250,640);
	glVertex2i(350,525);//4
	glVertex2i(400,525);
	glVertex2i(450,645);//5
	glColor3f(0,1,0);
	glVertex2i(275,825);
	glVertex2i(450,690);//6
	glColor3f(0,1,0);
	glVertex2i(600,525);
	glVertex2i(550,640);//1
	glColor3f(1,1,0);
	glVertex2i(550,690);
	glVertex2i(725,825);//2
	glColor3f(0,1,0);
	glVertex2i(775,825);
	glVertex2i(950,685);//3
	glColor3f(1,1,0);
	glVertex2i(650,525);
	glVertex2i(750,645);//4
	glVertex2i(750,645);
	glVertex2i(850,525);//5
	glVertex2i(900,525);
	glVertex2i(950,640);//6
//*************************************************
glBegin(GL_LINES);
	glVertex2i(150,500);
	glVertex2i(250,400);//1

	glVertex2i(250,400);
	glVertex2i(400,400);//1


	glVertex2i(400,400);
	glVertex2i(450,500);//1
glVertex2i(450,500);
	glVertex2i(450,645);//1
	//*********************************************
glColor3f(1,0,0);
glBegin(GL_LINES);
	glVertex2i(145,500);
	glVertex2i(245,395);//1

	glVertex2i(245,395);
	glVertex2i(400,394);//1


	glVertex2i(400,394);
	glVertex2i(455,500);//1
glVertex2i(455,500);
	glVertex2i(450,645);//1
//************************************************
glColor3f(1,1,1);
glBegin(GL_LINE_STRIP);
	glVertex2i(650,500);
	glVertex2i(750,400);//1

	glVertex2i(750,400);
	glVertex2i(900,400);//1


	glVertex2i(900,400);
	glVertex2i(950,500);//1
	glVertex2i(950,500);
	glVertex2i(950,645);//1

//**********************************************************
glColor3f(1,0,0);
glVertex2i(100,510);
	glVertex2i(40,645);//1
glVertex2i(275,835);
	glVertex2i(465,690);//6
glVertex2i(40,690);
	glVertex2i(225,840);//2
//************************************
glColor3f(1,0,0);
glBegin(GL_LINES);
	glVertex2i(150,100);
	glVertex2i(250,100);//1
glColor3f(0,0,0);
renderBitmapString(300,100,"LOOP CAUSING DEADLOCK");
glColor3f(1,1,1);
	glVertex2i(150,150);
	glVertex2i(250,150);//1
glColor3f(0,0,0);
renderBitmapString(300,150,"CLAIM EDGE");
glColor3f(0,1,0);
	glVertex2i(150,200);
	glVertex2i(250,200);//1
glColor3f(0,0,0);
renderBitmapString(300,200,"ALLOCATION EDGE");
glColor3f(1,1,0);
	glVertex2i(150,250);
	glVertex2i(250,250);//1
glColor3f(0,0,0);
renderBitmapString(300,250,"REQUEST EDGE");
//****************************************************************
void glRasterPos2i(	GLint x,GLint y);


glEnd();
}

void glutSpecialFunc(void (*func)(int key, int x, int y));

void mydisplay(){
    	glClearColor(0.71,0.91,0.97,1.0);
    	glColor3f(0.0,0.0,0.0);
     	glMatrixMode(GL_PROJECTION);
     	glLoadIdentity();
    	gluOrtho2D(0,1000,0,1000);
    	glMatrixMode(GL_MODELVIEW);
    	glLoadIdentity();
    	glClear(GL_COLOR_BUFFER_BIT);
    	if(f==1){
	//glLoadIdentity();
    	glColor3f(0,0,0);
    	renderBitmapString(300,850,"DEADLOCK REPRESENTATION");
   	renderBitmapString(450,800,"BY");
    	glColor3f(0,0,0);
    	renderBitmapString(750,620,"SUMITH.P.S");
    	renderBitmapString(750,590,"1AT16CS105");
    	glColor3f(0,0,0);
    	renderBitmapString(120,620,"SURAJ.B.G");
    	renderBitmapString(120,590,"1AT16CS109");
    	glColor3f(0,0,0);
    	renderBitmapString(300,350,"ATRIA INSTITUTE OF TECHNOLOGY");
    	BitmapString(700,50,"RIGHT CLICK ANYWHERE TO CONTINUE");
    	glutPostRedisplay();
   	 }
	if(f==2)
	{
	glColor3f(0.16, 0.16, 0.16);//background
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(1000,1000);
	glVertex2i(0,1000);
	glEnd();
	glColor3f(1,1,1);
	// DrawCircle(150,900.0,30.0,100);
	scene2();
	glColor3f(0,1,1);//background
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(1000,75);
	glVertex2i(0,75);
	glEnd();
	glColor3f(0,0,0);
    	
	
	renderBitmapString(850,100,"Press up arrow");
	renderBitmapString(0,37,"DEADLOCK EXAMPLE OF TWO PEOPLE SHARING SAME LADDER");
	if(spotdisp==1)
	
	//************************************************************************************8
	glPushMatrix();
	glTranslatef(cc+300,nn,0);
	if(cc>400)
	cc--;	
	glScalef(0.9,0.9,0);
	bean();
	glPopMatrix();

glPushMatrix();
	glTranslatef(da+50,ni,0);
	if(da<200)
	da++;	
	glScalef(0.9,0.9,0);
	bean();
	glPopMatrix();// ********************************************************************* */


	if(up==1)
	next();
	
	glFlush();
	}

	if(f==3)
	{

	scene3();
	glColor3f(0,1,1);//background
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(1000,75);
	glVertex2i(0,75);
	glEnd();
	
	glColor3f(0,0,0);
	renderBitmapString(250,37,"RESOURSE ALLOCATION GRAPH SHOWING 3 PROCESS AND 3 RESOURCES");
	renderBitmapString(300,100,"LOOP CAUSING DEADLOCK");
	renderBitmapString(300,150,"CLAIM EDGE");
	renderBitmapString(300,200,"ALLOCATION EDGE");
	renderBitmapString(300,250,"REQUEST EDGE");
	glPushMatrix();
	glTranslatef(sx,sy,0);
	if(cstate==1){
	if(carmov==1)
	{
	sx+=0.7;//0.7
	sy+=-0.2;//-0.2
	}
	
	}
	//car();
	if(cstate==1){
	if(carmov==1)
	{
	sx+=0.7;//0.7
	sy+=-0.2;//-0.2
	}
	glRotatef(-2,0,0,1);
	glScalef(0.55,0.5,0);
	glTranslatef(210,715,0);
	bean();
	}
	
	if(tt==1)
	{
	glPushMatrix();
	glTranslatef(mxx,myy,0);
	if(myy<300)
	myy++;
	if(myy==300)
	{
	beandisp = 0;
	carmov=1;
	}
	if(beandisp==1)
	bean();
	glPopMatrix();
	//glutPostRedisplay();
	}
	glFlush();
	}
	if(f==4)
	{
	
	glFlush();
	}
	if(f==5)
	{
	scene4();
	glColor3f(0,1,1);//background
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(1000,75);
	glVertex2i(0,75);
	glEnd();
	glColor3f(0,0,0);
	renderBitmapString(750,850,"'o': Open the door");
	renderBitmapString(750,800,"'w': Walking into the room");
	renderBitmapString(750,750,"'b': display conditions");
	renderBitmapString(150,37,"CONDITIONS TO BE SATISFIED FOR DEADLOCK");
	if(dstate==0){
	door();
	}else{
	glFlush();
	}
	glPushMatrix();
	glTranslatef(570,600,0);
	glScalef(0.6,0.6,0);
	//bean();
	glPopMatrix();
	
	if(fstate==0){
	glFlush();
	}
	else{
glPushMatrix();
	glTranslatef(cc+2,dd,0);
	if(cc>300)
	cc--;	
	glScalef(0.9,0.9,0);
	bean();
	glPopMatrix();


	}
	if(xxx==1)
{
	glColor3f(1,1,1);
	renderBitmapString(300,500,"MUTUAL EXCLUSION");
	renderBitmapString(300,450,"HOLD AND WAIT");
	renderBitmapString(300,400,"NO PREEMPTION");
	renderBitmapString(300,350,"CIRCULAR WAIT");
glBegin(GL_LINES);
	glVertex2i(380,200);
	glVertex2i(460,370);
	
	glEnd();
}
	
	glFlush();
	}
	if(f==6)
	{
	//scene4();
	glColor3f(1,1,1);//background
	glBegin(GL_POLYGON);
	
	glEnd();
	glColor3f(0,0,0);
	
	renderBitmapString(430,500,"THANK YOU");
	//renderBitmapString(250,37,"Mr Bean Entering to his living Room to watch Televison");
	if(gstate==0){
	glFlush();
	}
	else{

	glPushMatrix();
	glTranslatef(cc+200,dd,0);
	if(cc>450)
	cc--;	
	glScalef(2,2,0);
	//bean();
	glPopMatrix();
	}
	
	glFlush();
	}
	
	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
}
void create_menu(int choice){
        switch(choice){
            case 1:
                f=1;
                break;
            case 2:
                f=2;
                break;
            case 3:
                f=3;
                break;
            case 4:
                f=5;
                break;
	    case 5:
		f=6;
	
        }
       

}

//method to handle keyboard inputs keyboard-
void keyboard( unsigned char key, int x, int y )
{
  //handle --> press any key to continue
  	if(key=='o'){
     	dstate=1;
  	}
	if(key=='m'){
	cstate=1;
	}
	if(key=='w'){
	fstate=1;
	}
	if(key=='e'){
	gstate=1;
	}
	if(key=='c'){
	hstate=1;
	}
	if(key=='v'){
	istate=1;
	}
	if(key=='t'){
	t=1;
	}
	if(key=='b'){
	xxx=1;
	}
	if(key=='z'){
	tt=1;
	}
}

int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	
	glutCreateWindow("DEADLOCK REPRESENTATION");
	myinit();

	glutCreateMenu(create_menu);
	glutAddMenuEntry("Introduction",1);
	glutAddMenuEntry("example of deadlock",2);
	glutAddMenuEntry("resourse allocation graph",3);
	//glutAddMenuEntry("*****EXTRA****",4);
	glutAddMenuEntry("deadlock conditions",4);
	glutAddMenuEntry("EXIT",5);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(mydisplay);
	glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(keyboard);
	
	glutMainLoop();
	return 0;
}


