#include <stdio.h>
#include <stdint.h>
#include "pro.h"




int main(){
    FILE *f=fopen ("swt_data.dat","rb");
    int index,type,tam=46;
    uint32_t header;
    float data;
    struct v V;
    while(!feof(f)){
        fread(&header,sizeof(uint32_t),1,f);
        fread(&data,sizeof(float),1,f);
        index=(header <<2)>>2;
        type=header >>30;
        
        ord(index,type,data,V,tam);

        imp(V,tam);

    }
    
}