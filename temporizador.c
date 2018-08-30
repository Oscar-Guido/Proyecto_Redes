#include<sys/time.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

long cad_a_ent(const char *cad);
long a_milisegundos(long hora,long minuto,long segundo,long microseg,long duracion);

int main(int argc, char *argv[]){
	char hr[10],min[10],seg[10];
	struct timeval tv;
	time_t curtime;

	gettimeofday(&tv, NULL); 
	curtime=tv.tv_sec;

	strftime(hr,10,"%H",localtime(&curtime));
	strftime(min,10,"%M",localtime(&curtime));
	strftime(seg,10,"%S",localtime(&curtime));

	long hora=cad_a_ent(hr);
	long minuto=cad_a_ent(min);
	long segundo=cad_a_ent(seg);
	long microseg=tv.tv_usec;	
	long duracion=cad_a_ent(argv[1]);


	long total=a_milisegundos(hora,minuto,segundo,microseg,duracion);
	long actual=a_milisegundos(hora,minuto,segundo,microseg,0);
	
	while(actual<total){
		gettimeofday(&tv, NULL); 
		curtime=tv.tv_sec;

		strftime(hr,10,"%H",localtime(&curtime));
		strftime(min,10,"%M",localtime(&curtime));
		strftime(seg,10,"%S",localtime(&curtime));

		hora=cad_a_ent(hr);
		minuto=cad_a_ent(min);
		segundo=cad_a_ent(seg);		
		microseg=tv.tv_usec;	

		actual=a_milisegundos(hora,minuto,segundo,microseg,0);
	}
	return 0;
}

long cad_a_ent(const char *cad){
    long num=0,digito,i;
    int tam  = strlen(cad);  /* Longitud de la cadena recibida */
    for(i=tam;i>0;--i){
        digito=(int)(cad[i-1]-48);
        num+=digito*pow(10.0,tam-i);
    }
    return num;
}

long a_milisegundos(long hora,long minuto,long segundo,long microseg,long duracion){
	long total=0;
	total=(microseg/1000)+duracion;
	total+=segundo*1000;
	total+=minuto*1000*60;
	total+=hora*1000*3600;
	return total;
}
