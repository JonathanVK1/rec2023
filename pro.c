#include "pro.h"
#include <stdio.h>
#include <stdint.h>
#define MAX 46

static struct v V[MAX];


void ord(int index,int type, float data,struct v V[MAX],int tam){
    for(int i=0;i<=tam;i++){
        if(i==index){
            if(type==0){
                V[i].T=data;
            }
            if(type==1){
                V[i].V=data;
            }
            if(type==2){
                V[i].P=data;
            }
            i=tam+1;
        }
    }
};

void imp(struct v V[MAX],int tam){
    int Pm,a=0;
    float PMRPM[2];
    for(int i=0;i<=tam;i++){
        printf("index : %d\n",i);
        printf("Vel : %f rad/s\n",V[i].V);
        printf("Power : %f W\n",V[i].P);
        printf("Torque : %f Nm\n",V[i].T);

        if(V[i].P>=1){
            Pm=V[i].T * V[i].V;
            Pm=Pm-V[i].P;
            if(Pm>=0){
                Pm=Pm/V[i].P;
                Pm=Pm*100;
            }
            else{
                Pm=Pm/V[i].P;
                Pm=Pm*(-100);
            }
            V[i].E=Pm;
        }
        else{
            V[i].E=0;
        }
        printf("Erol : %f\n",V[i].E);
        if(a==0){
            a=1;
            PMRPM[1]=V[i].P;
            PMRPM[2]=V[i].V*60/(2*3.14159265);
        }
        else{
            if(PMRPM[1]<=V[i].P){
                PMRPM[1]=V[i].P;
                PMRPM[2]=V[i].V*60/(2*3.14159265);
            }
        }
    }
    printf("PowerM : %f W\n",PMRPM[1]);
    printf("VelM : %f RPM\n",PMRPM[2]);
};


