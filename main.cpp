#include "dessin.h"
//#include "figure.h"
#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main()
{
/*	 FILE *fp;
    fp = fopen("obs.txt","r");
    if(fp == NULL){
    	printf("There has been an Error ! ");
    	exit(1);
	}
	//fprintf(fp,"Les Obs Robot");
*/	
    DWORD w=GetSystemMetrics(SM_CXSCREEN);
    DWORD h=GetSystemMetrics(SM_CYSCREEN);
    h=730;
    w=1200;
    initwindow(w,h,"");
    dessin robot;
    cout<<" Choisir SVP le mode de fonctionement: "<<endl;
    cout<<" Clique sur 'M' pour le mode Manual "<<endl;
    cout<<" Clique sur 'A' pour le mode Automatique "<<endl;
    cout<<" Clique sur 'F' pour aboutir "<<endl;


    while(robot.mode !='M'&& robot.mode !='A'){
    cin>>robot.mode;
    delay(10);
    }


    while(1){
    robot.calcule();
    cleardevice();
    robot.affiche();
    delay(120);

    }
    
    getch();
    closegraph();
   // fclose(fp);

    return 0;
}
