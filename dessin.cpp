#include "dessin.h"
#include "figure.h"
#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<fstream>


using namespace std;
int pas=1;
int* dessin::rotate(int a[8], int n, int xc,int yc, float angle)
{
    angle=angle+3.14/2;
	    
int i = 0;
    while (i < n)
    {
        float i0=a[i];
        float i1=a[i+1];
        // Shifting the pivot point to the origin
        // and the given points accordingly
        int x_shifted = i0 - xc;
        int y_shifted = i1 - yc;
        // Calculating the rotated point co-ordinates
        // and shifting it back
        i0= (x_shifted*cos(angle)- y_shifted*sin(angle));
        i1 = (x_shifted*sin(angle)+ y_shifted*cos(angle));
        i0=i0+xc;
        i1=i1+yc;
        a[i]=rint(i0);
        a[i+1]=rint(i1);
        i=i+2;
           }
    return a;
}
void dessin::affiche()
{
        if(Nc==6)
    {
    delay(1000);
    cleardevice();
    setcolor(GREEN);
    settextstyle(BOLD_FONT,HORIZ_DIR,8);
    outtextxy(350,300,(char*)"You Win");
    delay(5000);
    exit(1);
    }
    setcolor(YELLOW);
    circle(x,y,Rr);
    setcolor(WHITE);
    circle(x,y,Rr-1);

    drawpoly(4,b);
    drawpoly(2,b1);
    drawpoly(2,b2);
    //setcolor(WHITE);
    //circle(Xc,Yc,5);
    setcolor(GREEN);
    circle(Xc,Yc,Rr);
    circle(Xc,Yc,Rr-1);
    circle(Xc,Yc,Rr-2);
    char inf[100];
    sprintf(inf,"Cible %2d",Nc);
    outtextxy(Xc-20-Nc/5,Yc-6,inf);

    setcolor(RED);
             for (int i=0;i<8;i++){


                    circle(Xobs[i],Yobs[i],Robs[i]);
                    circle(Xobs[i],Yobs[i],Robs[i]-1);
                    sprintf(inf,"Obs %d",i+1);
                    outtextxy(Xobs[i]-20,Yobs[i]-6,inf);
                    if (i==m)circle(Xobs[m],Yobs[m],Robs[i]-10);

             }
    setcolor(WHITE);

    sprintf(inf,"wg= %.1f   wd= %.1f   Alpha= %.2f  C_apha= %.2f",wg,wd,alpha*180/3.14,c_alpha*180/3.14);
    outtextxy(10,640,inf);
    sprintf(inf,"C_apha-alpha= %.2f   Distance Goal= %.2f",(def_angle)*180/3.14,DistG);
    outtextxy(20,660,inf);
    sprintf(inf,"O_apha-alpha= %.2f   Distance Obs= %.2f",(def_angle_obs)*180/3.14,DistO[m]);
    outtextxy(20,680,inf);
        setcolor(WHITE);
  /*  for(int i=0;i<=cont;i+=3)
    circle(xstok[i],ystok[i],1);*/

    return;
}

dessin::dessin(){
	
/*		 FILE *fp;
    fp = fopen("obs.txt","r");
    if(fp == NULL){
    	printf("There has been an Error ! ");
    	exit(1);
	}
*/
// position de robot
    x=150;
    y=432;

//position de but
    Xc=((rand() % 1100) + 50);
    Yc=((rand() % 600) + 50);


//position de 1 er  obstacle
    Xobs[0]=1100;
    Yobs[0]=500;
    Robs[0]=70;

//position de 2 ème obstacle
    Xobs[1]=400;
    Yobs[1]=600;
    Robs[1]=60;

//position de 3 ème obstacle
    Xobs[2]=500;
    Yobs[2]=150;
    Robs[2]=60;

//position de 4 ème obstacle
    Xobs[3]=900;
    Yobs[3]=150;
    Robs[3]=80;

//position de 5 ème obstacle
    Xobs[4]=750;
    Yobs[4]=550;
    Robs[4]=60;

//position de 6 ème obstacle
    Xobs[5]=250;
    Yobs[5]=250;
    Robs[5]=60;

//position de 7 ème obstacle
    Xobs[6]=550;
    Yobs[6]=360;
    Robs[6]=50;

//position de 8 ème obstacle
    Xobs[7]=150;
    Yobs[7]=550;
    Robs[7]=40;

    Rr=50;
    R0=0.020;
    Dt=0.1;
    D=0.050;
    w0Max=10;
    Dw0Max=2;
    alpha=0;
    //---------------------
                wg=0;
                wd=0;
    //--------------------

    tringle[0]=x-Rr ;
    tringle[1]=y;
    tringle[2]=x+Rr ;
    tringle[3]=y;
    tringle[4]=x ;
    tringle[5]=y-Rr;
    tringle[6]=x-Rr ;
    tringle[7]=y;
    segment1[0] =x-Rr/2;
    segment1[1] =y+Rr/4;
    segment1[2] =x-Rr/2;
    segment1[3] =y-Rr/4;
    segment2[0] =x+Rr/2;
    segment2[1] =y+Rr/4;
    segment2[2] =x+Rr/2;
    segment2[3] =y-Rr/4;
    float def_angle=0;
    float def_angle_obs=0;
    float c_alpha=1;
     cont=0;
     m=0;
     Nc=0;
    }
void dessin::calcule(){

   if(DistG<=100){
       /* for (int i=0;i<=2000;i++){

            xstok[i]=0;
            ystok[i]=0;
        }*/
cont=0;

Nc++;
    Xc=((rand() % 1100) + 50);
    Yc=((rand() % 600) + 50);


//-----position obstacle
    }
bool repeat=false;
    for (int i=0;i<8;i++)
    {
        if (abs(Xc-Xobs[i])<Robs[i]||abs(Yc-Yobs[i])<Robs[i])
        {repeat=true;i=8;
        cout<<"i= "<<i<<endl;
        cout<<"dx= "<<abs(Xc-Xobs[i])<<endl;
        cout<<"dy= "<<abs(Yc-Yobs[i])<<endl;

        }
    }

int k=0;


while(repeat){
k++;
repeat=false;
cout<<"K= "<<k<<endl;
    //position de but
    Xc=((rand() % 1100) + 50);
    Yc=((rand() % 600) + 50);


for (int i=0;i<8;i++)
{
    if (abs(Xc-Xobs[i])<Robs[i]||abs(Yc-Yobs[i])<Robs[i])
        {repeat=true;i=8;
        cout<<"i= "<<i<<endl;
        cout<<"dx= "<<abs(Xc-Xobs[i])<<endl;
        cout<<"dy= "<<abs(Yc-Yobs[i])<<endl;

        }
    else
        repeat=false;
}

}
for (int i=0;i<8;i++){
    Dd=wd*Dt*R0;
    Dg=wg*Dt*R0;
    if(Dg!=Dd)
    Rc=D*(Dg+Dd)/(2*(Dg-Dd));
    Dr=(Dg+Dd)/2;
    Dalpha=(Dg-Dd)/D;
    Vr=Dr/Dt;
    wr=Dalpha/Dt;
    float pi=3.1416;

    DistG=sqrt((x-Xc)*(x-Xc)+(y-Yc)*(y-Yc));

    for(int j=0;j<8;j++){
    DistO[j]=sqrt((x-Xobs[j])*(x-Xobs[j])+(y-Yobs[j])*(y-Yobs[j])); }

    alpha=alpha+Dalpha;
    while(alpha>2*pi)alpha-=2*pi;
    while(alpha<-2*pi)alpha+=2*pi;
    float x1=x;
    float y1=y;
    float  delta_x0=x;
    float  delta_y0=y;

   if (Dg==Dd)
   {
    x=x+Dd*cos(alpha)*1000;
    y=y+Dg*sin(alpha)*1000;
   }
   else
   {x=x+Rc*(sin(alpha)-sin(alpha-Dalpha))*1000;
   y=y+Rc*(-cos(alpha)+cos(alpha-Dalpha))*1000;
   }
  // xstok[cont]=x;
   //ystok[cont]=y;
   cont++;
    cout<<"Dalpha="<<Dalpha*180/3.14<<endl;
    cout<<"alpha="<<alpha*180/3.14<<endl<<endl;
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;

    int *p,*p1,*p2;
    float sx=0;
    float sy=0;
    float sxo=0;
    float syo=0;

//commande manual
//=================================================================================================
if (mode=='M'){


            if(GetAsyncKeyState(VK_LEFT)){
                wg=wg+0.1;delay(100);}
            if(GetAsyncKeyState(VK_RIGHT)){
                 wd=wd+0.1;delay(100);}
            if(GetAsyncKeyState(VK_UP))
                {wd=wd-0.1;delay(100);}
            if(GetAsyncKeyState(VK_DOWN))
                {wg=wg-0.1;delay(100);}


 if (DistO[m]<=Rr+Robs[m]){
if(pas==1){
  wg=-wg*0.1;
  wd=-wd*0.1;
  pas=0;
  }
}

if (DistO[m]>=10+Rr+Robs[m]){
  pas=1;
}


}
//=================================================================================================

    tringle[0]=x-Rr ;
    tringle[1]=y;
    tringle[2]=x+Rr ;
    tringle[3]=y;
    tringle[4]=x ;
    tringle[5]=y-Rr;
    tringle[6]=x-Rr ;
    tringle[7]=y;
    segment1[0] =x-Rr/2;
    segment1[1] =y+Rr/4;
    segment1[2] =x-Rr/2;
    segment1[3] =y-Rr/4;
    segment2[0] =x+Rr/2;
    segment2[1] =y+Rr/4;
    segment2[2] =x+Rr/2;
    segment2[3] =y-Rr/4;
    p=rotate(tringle,8,x,y,alpha);
    p1=rotate(segment1,4,x,y,alpha);
    p2=rotate(segment2,4,x,y,alpha);


    for (int i=0;i<8;i++)
    b[i]=*(p+i);
    for (int i=0;i<4;i++)
    {
    b1[i]=*(p1+i);
    b2[i]=*(p2+i);
    }
//-----go to the goal

    m=0;
    float mi_n=DistO[0];
    for (int j=1;j<8;j++)
    {
        if (DistO[j]<mi_n){
            mi_n=DistO[j];
            m=j;}
             }

 sx=Xc-x;
 sy=Yc-y;
 sxo=Xobs[m]-x;
 syo=Yobs[m]-y;
 c_alpha=chek_theta(sx,sy);
 o_alpha=chek_theta(sxo,syo);


   def_angle =c_alpha-alpha;
   def_angle_obs =o_alpha-alpha;
    while(def_angle>2*pi)def_angle-=2*pi;
    while(def_angle<-2*pi)def_angle+=2*pi;
    while(def_angle_obs>2*pi)def_angle_obs-=2*pi;
    while(def_angle_obs<-2*pi)def_angle_obs+=2*pi;


// commande Automatique
//=================================================================================================
if (mode=='A'){

if(DistG>100)
{

//-------------- start évité obstacles--------------------------------------------
         if (DistO[m]<=80+Robs[m]){


             if (def_angle_obs*180/3.14>-100 && def_angle_obs*180/3.14<-80||def_angle_obs*180/3.14>-290 && def_angle_obs*180/3.14<-250 || def_angle_obs*180/3.14>80 && def_angle_obs*180/3.14<100  ) {
                                           wd=wg=2;
                                                          }
             else {
                    if((def_angle_obs<0 && def_angle_obs>-pi/2)|| (def_angle_obs*180/pi>-270 && def_angle_obs<-pi) ) {
                        // if (wd>Dw0Max)wd-=1.5;
                        if (wg>Dw0Max)wg=0.5;
                            wd=0;
                            wg+=0.1;}
                    if((def_angle_obs>0 && def_angle_obs<pi/2)|| (def_angle_obs>-2*pi && def_angle_obs*180/pi<-270) )
                    {

                       // if (wg>Dw0Max)wg-=1.5;
                       if (wd>Dw0Max)wd=0.5;
                            wd+=0.1;
                            wg=0;}
            }
    }
//---------------Fin évité obstacles---------------------------------------------------


//---------------Go to the Goal--------------------------------------------------------

    else{

            if (def_angle*180/3.14<2 && def_angle*180/3.14>-2) {
               wd=wg=w0Max*0.3;
            }
            else {
                    if (DistG<100 && DistG>50)if(wg>1 ||wd>1)
                    {
                       wd=0.5*wd;
                       wg=0.5*wg;
                    }
                    if((def_angle<0 && def_angle>-pi)|| (def_angle>pi && def_angle<2*pi) ) {

                         if (wg>Dw0Max)wg-=2;
                            wd+=0.05;}
                    if((def_angle>0 && def_angle<pi)|| (def_angle<-pi && def_angle>-2*pi) ) {

                        if (wd>Dw0Max)wd-=2;
                            wg+=0.05;}
         }

    }
}
//---------------End Go to the Goal--------------------------------------------------------

else {wg=0;wd=0;}
}
//=================================================================================================
}
if(GetAsyncKeyState('F') & 0x8000)
{
    exit (1);
}

 return;
}
float dessin::chek_theta(float delta_x0,float delta_y0)
{
    float tita;
    if(delta_x0>0){
    tita=atan(delta_y0/delta_x0)+3.14/2;
    cout<<"1"<<endl;}
    else if (delta_x0<0){
    tita=atan(delta_y0/delta_x0)-3.14/2;}
    else if (delta_x0==0 &delta_y0>0){
    tita=3.14;
    cout<<"3"<<endl;}
    else if (delta_x0==0 &delta_y0<0){
    tita=0;
    cout<<"3"<<endl;}
return tita-3.14/2; }

