#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 9 
#define DİKEN_SAYİSİ 8

char harita[BOYUT][BOYUT];
int x =4;
int y =8;
int skor=0;
int oyunDevam = 1;
// Matrisi oluşturalim.
void HaritaOlustur() {
for (int i=0; i<BOYUT ;i++) {
for (int j=0; j<BOYUT ;j++) {
harita[i][j]= '.'; }
} }
void yem_diken_yerlestir() // Yem ve dikenleri matrise yerleştirme fonksiyonu
{
srand(time(NULL));
x=BOYUT-1;
y=BOYUT/2;
harita[x][y]='P';

int yemX, yemY;
do {

yemX= rand() % BOYUT;
yemY= rand() % BOYUT;

} while (yemX==x && yemY==y);
harita[yemX][yemY]='*';

int sayac=0;
while (sayac<DİKEN_SAYİSİ) {
int dx= rand() % BOYUT;
int dy= rand() % BOYUT;
if (harita[dx][dy]=='.') {
harita[dx][dy]='#';
sayac++;
}
}
}
void matris_yazdir() // Matrisi yazdırma fonksiyonu
{
printf("Skor: %d , Yukari: w , Asaği: z , Sag: d , sol: a \n",skor);
for (int i=0; i<BOYUT ;i++) {
for ( int j=0; j<BOYUT ;j++) {
printf("%c",harita[i][j]);
}
printf("\n");
}
}
void hareket_komutlari(char komut) // Girilen komuta göre oyuncuyu hareket ettiren fonksiyon 
{
int yeniX=x;
int yeniY=y;
if (komut=='w' || komut=='W') yeniX--;
else if (komut=='z' || komut=='Z') yeniX++;
else if (komut=='a' || komut=='A') yeniY--;
else if (komut=='d' || komut=='D') yeniY++;
else return;

if (yeniX<0 || yeniX>=BOYUT || yeniY<0 || yeniY>=BOYUT) {
printf("Dikkat! Duvara carptiniz... \n");
oyunDevam=0;
return;
}
if (harita[yeniX][yeniY]=='#') {
printf("Dikene carptiniz !!! Oyunu kaybettiniz... \n");
oyunDevam=0;
return;
}
if (harita[yeniX][yeniY]=='*') {
printf("Yemi yedin ;) Tebriklerr...");
skor+=10;
harita[x][y] = '.';
x = yeniX;
y = yeniY;
harita[x][y] = 'P';

// Yemi yedikten sonra tekrar yem yerleştirilir.        
int yeniYemX, yeniYemY; 
do {
    yeniYemX = rand() % BOYUT;
    yeniYemY = rand() % BOYUT;
} while (harita[yeniYemX][yeniYemY] != '.');
harita[yeniYemX][yeniYemY] = '*';
return;
    }
// Yerleştiren yeni konuma işaret bırakılır.
    harita[x][y] = '.'; 
    x = yeniX;
    y = yeniY;
    harita[x][y] = 'P';
}
int main() {
    char hareket;
    HaritaOlustur();
    yem_diken_yerlestir();
    
    while(oyunDevam) {
        matris_yazdir();
        printf("Hareket yönü: (w,a,d,z)\n");
        scanf(" %c", &hareket);
        hareket_komutlari(hareket);
    }
    printf("Oyun bitti ;) Skorun: %d\n", skor);
    return 0;
}

