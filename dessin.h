#ifndef DESSIN_H
#define DESSIN_H


class dessin{
public:
    friend class figure;
    dessin();
int* rotate(int a[8], int n, int xc,int yc, float angle);
float chek_theta(float delta_x0,float delta_y0);
void calcule();
void affiche();
    float Xobs[8],Dx,Dy,Yobs[8],Robs[8];    
    float x;
    float y;
    int Rr;
    float alpha;
    int tringle[8];
    int segment1[4];
    int segment2[4];
    
    // float x=600;
    // float y=350;
    // int Rr=40;
    // float alpha=0;
    // int tringle[8] = {x-Rr, y,x+Rr, y,x,y-Rr,x-Rr,y};
    // int segment1[4] = {x-Rr/2,y+Rr/4,x-Rr/2,y-Rr/4};
    // int segment2[4] = {x+Rr/2,y+Rr/4,x+Rr/2,y-Rr/4};
    
    int w0Max;
    int Dw0Max;
    float Dr,Dg,Dd,Rc,Dalpha,wg,wd,wr,Vr,R0,Dt,D,Xc,Yc;
    float DistG;
    float DistO[8];
    int b[8];
    int b1[4];
    int b2[4];
    float c_alpha;
    float o_alpha;
    float def_angle,def_angle_obs;
    int cont;
    int m,Nc;
char mode;
};

#endif // DESSIN_H
