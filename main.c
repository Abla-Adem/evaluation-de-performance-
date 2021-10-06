#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
typedef struct sh{
    int temps;
    int type;
    int adresse;
    int taille;

}bench;
int time_type(int t0,int t_min,int t_max,int type_time)
{
    if(type_time==0)
    {
        return t0+t_min;
    }
    int aleatoire;
    aleatoire=(rand()/(RAND_MAX+1.))*(t_max+1-t_min)+t_min;
    return t0+aleatoire;
}
int operation_type(double p,int nr,int nw,int *type_operation)
{
    if(*type_operation==0)
    {
        double aleatoire_requette=0;
        aleatoire_requette=(double )(rand())/RAND_MAX;
        if(aleatoire_requette<=p)
        {
            return 1;
        }

        return 0;
    }
    else
    {
        if(*type_operation<nw )
        {
            *type_operation=*type_operation+1;
            return 1;
        }
        else
        {
            if(*type_operation==nr+nw)
            {
                *type_operation=1;
                return 1;
            }

            *type_operation=*type_operation+1;
            return 0;

        }
    }
}
int adresse_type(int adresse,int h,int c,double ph,int s,int type_adresse)
{
    if(type_adresse==0)
    {
        return adresse+s;
    }
    else if(type_adresse==1)
    {
        double aleatoire_requette=(double )(rand())/RAND_MAX;
        if(aleatoire_requette<=ph)
        {
            return (rand()/(RAND_MAX+1.))*(h+1)+adresse;
        }
        else
        {
            return (rand()/(RAND_MAX+1.))*(c+1-h)+adresse+h;
        }
    }
    else
    {
        return (rand()/(RAND_MAX+1.))*(c+1)+adresse;
    }
}
int taille_type(int s,int s_min,int s_max,int type_taille)
{
    if(type_taille==0)
    {
        return s;
    }
    else if(type_taille==1)
    {
        return (rand()/(RAND_MAX+1.))*(s_max+1-s_min)+s_min;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char *argv[]) {
    FILE *f=fopen("trace.txt","w");

    //nombre requette
    int n=strtol(argv[1], NULL, 10);
    //argument de temps
    int t0=strtol(argv[2], NULL, 10);
    int t_min=strtol(argv[3], NULL, 10);
    int t_max=strtol(argv[4], NULL, 10);
    //probabilite de ecriture
    double p= strtod(argv[5], NULL);
    int nr=strtol(argv[7], NULL, 10);
    int nw=strtol(argv[6], NULL, 10);
    //argument d'adresse
    int adresse=strtol(argv[8], NULL, 10);
    int h=strtol(argv[9], NULL, 10);
    double ph= strtod(argv[10], NULL);
    int c=strtol(argv[11], NULL, 10);

    //argument de taille
    int s=strtol(argv[12], NULL, 10);
    int s_min=strtol(argv[13], NULL, 10);
    int s_max=strtol(argv[14], NULL, 10);

    int time,type,adres,length;
    //time
    if(t_min==t_max)
    {
        time=0;
    }
    else
    {
        time=1;
    }

    //type
    if(p==0.0)
    {
        type=1;
    }
    else
    {
        type=0;
    }


    //taille
    if(s>0)
    {
        length=0;
    }
    else if(s==0)
    {
        length=1;
    }
    else
    {
        length=2;
    }
    //adresse
    if(adresse>0)
    {
        adres=0;
    }
    else if(adresse==0)
    {
        adres=1;
        //adresse=(rand()/(RAND_MAX+1.))*INT_MAX-(c+s+s_max);
        adresse=0;
    }
    else
    {
        //adresse=(rand()/(RAND_MAX+1.))*INT_MAX-(c+s+s_max);
        adresse=0;
        adres=2;
    }
    struct sh benshmarck;
    benshmarck.temps=t0;
    benshmarck.adresse=adresse;
    if(type==1)
    {
        benshmarck.taille= taille_type(s,s_min,s_max,length);
        fprintf(f,"%d %d %d %d %d\n",0,benshmarck.temps,1,benshmarck.adresse,benshmarck.taille);
    }
    else
    {
        benshmarck.type= operation_type(p,nr,nw,&type);
        benshmarck.taille= taille_type(s,s_min,s_max,length);
        fprintf(f,"%d %d %d %d %d\n",0,benshmarck.temps,benshmarck.type,benshmarck.adresse,benshmarck.taille);
    }
    for (int i = 1; i < n; ++i) {

        benshmarck.type= operation_type(p,nr,nw,&type);
        benshmarck.taille= taille_type(s,s_min,s_max,length);
        benshmarck.temps= time_type(benshmarck.temps,t_min,t_max,time);
        benshmarck.adresse= adresse_type(benshmarck.adresse,h,c,ph,benshmarck.taille,adres);
        fprintf(f,"%d %d %d %d %d\n",i,benshmarck.temps,benshmarck.type,benshmarck.adresse,benshmarck.taille);
        if(adres!=0)
        {
            benshmarck.adresse=adresse;
        }
    }
}
