#include <stdio.h>
#include <string.h>
#include <locale.h>

#define limit 1000
 
void sifrele(char[], int);
void sifreCoz(char[], int);
int arabul(char[], char);

char metin[limit];
int k,denenen,secA,secB,karakterBoyutu;
// Yukar�da de�i�kenleri tan�mlad�m.
int main() {
 
	setlocale(LC_ALL, "Turkish");
	//karakterler tan�mlad�m
    char karakter[] = "abc�defg�h�ijklmno�prs�tu�vyzABC�DEFG�HI�JKLMNO�PRS�TU�VYZ";
    int parola = 3;
    karakterBoyutu = strlen(karakter);
    //Program�n men� k�sm� hangi i�lemin yap�laca��n� se�iyorum. se�ilen de�er if ile kol�ulu sa�l�yorsa o i�lemi ger�ekle�tiriyorum
	printf("-------------------------------------\n");
    printf("Yapaca��n�z i�lemi se�in:\n");
    printf("[1]-Sezar �ifresini k�r (brute force)\n");
    printf("[2]-Sezar �ifresi ile metini �ifrele \n");
    printf("[3]-Kapat \n");
    printf("-------------------------------------\n");
    scanf("%d",&secA);
    if(secA<=1){
	       
          printf("K�r�lacak �ifreli metni ba�ka bir �ifreli metinle de�i�tirmek i�in ilgili yeri d�zenleyin:\n");		  
          printf("-------------------------------------\n");
          printf("------ K�r�lacak �ifreli Metin -----------\n");
        strcpy(metin, "�tgri�p Izo�f");   //�ifrelenmi� metin
          printf("[+]%s\n", &metin);
          printf("-------------------------------------\n");;
          for (k = 0; k < strlen(karakter); k++) {
          printf("-------------------------------------\n");
          sifreCoz(karakter, k);
          printf("[+] K:%d ",k);
          printf("[+]: %s\n", metin);           
           }
      }

	   // e�er secilen de�er 1 ise yani �ifrele ise
	   // �nce metin ve parola giri�i istiecek daha sonra sifrele(karakter, sifre); i�lemi ile alttaki fonksiyonu �a��r�p
	   // �ifreleme i�lemini ger�ekle�tirecektir.
	  else if(secA==2){
          printf("-------------------------------------\n");
          printf("------ �ifrelenecek Metin -----------\n");
 	   	  strcpy(metin, "Erdo�an G�le�"); //�ifrelenecek metin
 	   	  printf("[+]%s\n", &metin);
          printf("-------------------------------------\n");;
          sifrele(karakter, parola);
          printf("--------- �ifrelendi... --------------\n");
          printf("�ifrelenmi� hali:[+]\n%s\n", &metin);
          
      }
      //e�er 2 se�ilirse  �ncelikli �ifreli metin ve parola giri�i ister daha sonra �ifre ��zme fonksiyonu �a��r�larak �ifre ��z�l�r
     else{
        printf("Program Sonland� ");
       
	  }
    
	system("pause");
    return 0;
}
// �ifreleme i�leminin yap�ld��� fonksiyon. karakter say�s� verilen deger kadar kayd�r�l�yor daha sonra tekrar
//karaktere d�n��t�r�l�yor.
void sifrele(char karakter[], int parola) {
    int i;
    int harfSirasi;
    int metinBoyut = strlen(metin);
    for (i = 0; i < metinBoyut; i++) {
        harfSirasi = arabul(karakter, metin[i]);
        if (harfSirasi != -1) {
            harfSirasi = (harfSirasi + parola) % karakterBoyutu;
            if (harfSirasi < 0)
                harfSirasi += karakterBoyutu;
            metin[i] = karakter[harfSirasi];
        }
    }
 
}
//�ifreleme i�leminin tam tersi yap�l�yor karakter say�s� ile verilen parola degeri ��kart�l�yor daha sonra mod i�lemi yap�l�p ��kan
//say� karakter'e d�n��t�r�l�yor.
void sifreCoz(char karakter[], int parola) {
    int i;
    int harfSirasi;
    int metinBoyut = strlen(metin);
    for (i = 0; i < metinBoyut; i++) {
        harfSirasi = arabul(karakter, metin[i]);
        if (harfSirasi != -1) {
            harfSirasi = (harfSirasi - parola) % karakterBoyutu;
            if (harfSirasi < 0)
                harfSirasi += karakterBoyutu;
            metin[i] = karakter[harfSirasi];
        }
    }
 
}
//Karakterin ka��nc� s�rada oldugu arabulunuyor.
int arabul(char karakter[], char arananHarf) {
 
    int i, sayac = -1;
 
    for (i = 0; i < strlen(karakter); i++) {
        if (arananHarf == karakter[i])
            sayac = i;
    }
    return sayac;
}
