#include <stdio.h>
#include <stdint.h>
#include "pro.h"




int main(){
    FILE *f=fopen ("swt_data.dat","rb");
    uint32_t header;
    float data;
    int index=(header <<2)>>2;
    int type=header >>30;
    struct v V;

    ord(index,type,data,V);

    imp(V);

}