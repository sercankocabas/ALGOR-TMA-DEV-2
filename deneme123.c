#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
int no; 
char ad[30]; 
char soyad[30]; 
int final; 
int vize; 

struct node *pre; 
struct node *nex; 

};


typedef struct node ogren;
ogren *root=NULL;

int cnt=0;


void Sil()
{
system("cls");
if (root==NULL)
{
printf("Listede Kayıtlı Ogrenci Yok, Silme Işlemi Yapılamadı \n"); } 
else 
{ int ogrNo; 
printf("\nSilinecek Ogrencinin Numarasini Yaziniz \n ") ; 
scanf ("%d", &ogrNo); 

if(cnt==1 && root->no == ogrNo)
{
printf("Kayitli Son Ogrenci Silindi, Liste Bos \n"); 
free(root); 
root==NULL;
cnt--; 
}
else if (cnt!=1 && root->no == ogrNo)
{
printf("%d Numarali Ogrenci Silindi \n", root->no);
ogren *p = root;
while(p->nex!=root)
p= p->nex;

ogren *p2 = root->nex;
free(root);
root=p2;

root->pre= p;
p->nex= root;
cnt--;
}
else
{
ogren *z = root; 
ogren *z2 = root; 
ogren *z3 = root; 

while(z->nex!=root)
{
if(z->no==ogrNo)
{
printf("%d Nummarali Ogrenci Silindi \n", z->no );
z3= z->nex;
free(z);
z2->nex= z3;
z3->pre= z2;
cnt--;
break;
}

z2= z;
z= z->nex;
}
if(z->no==ogrNo)
{
printf("%d Nummarali Ogrenci Silindi \n", z->no );
free(z);
z2->nex= root;
root->pre= z2;
cnt--;
}
} } }

void Ekle (int n, char *a, char *s, int v, int f) 
{ 
system("cls"); 

ogren *ogr= (ogren*) malloc(sizeof(ogren));
ogr->no= n; 
strcpy(ogr->ad, a); 
strcpy(ogr->soyad, s); 
ogr->vize= v; 
ogr->final= f;

if (root==NULL) 
{
root=ogr; 
root->nex= root;
root->pre= root; 
cnt++;
printf("%d Numarali Ilk Ogrenci Eklendi \n", root->no); 
}

else 
{
ogren * p= root;
while(p->nex!=root)
p= p->nex;


ogr->nex= root;
root->pre= ogr;  
root=ogr;    
p->nex= root;
root->pre= p;
cnt++;
printf("%d Numarali Ogrenci Listeye Eklendi \n", root->no); 
}
}

void Kaydet()
{
if(root==NULL)
{
printf("Liste Bostur, Dosyaya Kaydedilecek Bilgi Yok \n"); 
}
else 
{
ogren * p= root;    
FILE *dosya = fopen("ogrenci.txt", "w"); 
while(p->nex!=root) {   
fprintf( dosya, "%d %s %s %d %d \n", p->no, p->ad, p->soyad, p->vize, p->final); 
p= p->nex;
}
fprintf( dosya, "%d %s %s %d %d ", p->no, p->ad, p->soyad, p->vize, p->final);  
fclose(dosya); 
printf("Girilen Bilgiler Basarili Bir Sekilde Dosyaya Kaydedildi\n");   
}
}

void Listele() 
{
system("cls"); 
if(root==NULL)
{
printf("Liste Bos, Listelenecek Ogrenci Yok \n"); 
}
else
{
ogren * p= root;
while(p->nex!=root)
{
printf("%d Numarali Ogrencinin Adi: %s Soyadi: %s Vize Notu: %d Final Notu: %d \n", p->no, p->ad, p->soyad, p->vize, p->final);
p= p->nex;
}
printf("%d Numarali Ogrencinin Adi: %s Soyadi: %s Vize Notu: %d Final Notu: %d \n", p->no, p->ad, p->soyad, p->vize, p->final); 
}
}

void Aktar()
{

FILE *dosya = fopen("ogrenci.txt", "r");
while(!feof(dosya))
{
int n, v, f;
char a[30], s[30];
fscanf(dosya, "%d%s%s%d%d", &n,a,s,&v,&f);
Ekle( n,a,s,v,f);
}
fclose(dosya); 
system("cls"); 
}

int main() 
{

Aktar(); 
int secim; 
int no,  vize, final; 
char ad[30], soyad[30]; 
while(1)
{
printf("\n OGRENCI SISTEM MENU \n"); 

 
printf("\t 1*  EKLE \n"); 
printf("\t 2* SIL \n"); 
printf("\t 3* LISTELE \n"); 
printf("\t 4* DOSYAYA YAZDIR \n"); 
printf("\t 0* CIKIS \n");


scanf("%d", &secim);
switch(secim) { 
case 1: 

printf("ogrenci no  :"); 
scanf("%d", &no); 
printf("ogrenci ad  :"); 
scanf("%s", &ad); 
printf("ogrenci soyad :"); 
scanf("%s", &soyad); 
printf("ogrenci vize  :"); 
scanf("%d", &vize); 
printf("ogrenci final :");  
scanf("%d", &final); 
Ekle(no, ad, soyad, vize, final); 
break; 

case 2: Sil(); 
break;

case 3: Listele(); 
break; 

case 4: Kaydet(); 
break; 


case 0: return 0; 
   default : printf("\n YANLIS ISLEM \n"); 
}
}
}