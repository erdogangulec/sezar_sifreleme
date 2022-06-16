#include <stdio.h>
#include <string.h>
#include <locale.h>

#define limit 1000
 
void sifrele(char[], int);
void sifreCoz(char[], int);
int arabul(char[], char);

char metin[limit];
int k,denenen,secA,secB,karakterBoyutu;
// Yukarýda deðiþkenleri tanýmladým.
int main() {
 
	setlocale(LC_ALL, "Turkish");
	//karakterler tanýmladým
    char karakter[] = "abcçdefgðhýijklmnoöprsþtuüvyzABCÇDEFGÐHIÝJKLMNOÖPRSÞTUÜVYZ";
    int parola = 3;
    karakterBoyutu = strlen(karakter);
    //Programýn menü kýsmý hangi iþlemin yapýlacaðýný seçiyorum. seçilen deðer if ile kolþulu saðlýyorsa o iþlemi gerçekleþtiriyorum
	printf("-------------------------------------\n");
    printf("Yapacaðýnýz iþlemi seçin:\n");
    printf("[1]-Sezar þifresini kýr (brute force)\n");
    printf("[2]-Sezar þifresi ile metini þifrele \n");
    printf("[3]-Kapat \n");
    printf("-------------------------------------\n");
    scanf("%d",&secA);
    if(secA<=1){
	       
          printf("Kýrýlacak þifreli metni baþka bir þifreli metinle deðiþtirmek için ilgili yeri düzenleyin:\n");		  
          printf("-------------------------------------\n");
          printf("------ Kýrýlacak Þifreli Metin -----------\n");
        strcpy(metin, "Ðtgriçp Izoðf");   //þifrelenmiþ metin
          printf("[+]%s\n", &metin);
          printf("-------------------------------------\n");;
          for (k = 0; k < strlen(karakter); k++) {
          printf("-------------------------------------\n");
          sifreCoz(karakter, k);
          printf("[+] K:%d ",k);
          printf("[+]: %s\n", metin);           
           }
      }

	   // eðer secilen deðer 1 ise yani þifrele ise
	   // önce metin ve parola giriþi istiecek daha sonra sifrele(karakter, sifre); iþlemi ile alttaki fonksiyonu çaðýrýp
	   // þifreleme iþlemini gerçekleþtirecektir.
	  else if(secA==2){
          printf("-------------------------------------\n");
          printf("------ Þifrelenecek Metin -----------\n");
 	   	  strcpy(metin, "Erdoðan Güleç"); //þifrelenecek metin
 	   	  printf("[+]%s\n", &metin);
          printf("-------------------------------------\n");;
          sifrele(karakter, parola);
          printf("--------- Þifrelendi... --------------\n");
          printf("Þifrelenmiþ hali:[+]\n%s\n", &metin);
          
      }
      //eðer 2 seçilirse  öncelikli þifreli metin ve parola giriþi ister daha sonra þifre çözme fonksiyonu çaðýrýlarak þifre çözülür
     else{
        printf("Program Sonlandý ");
       
	  }
    
	system("pause");
    return 0;
}
// Þifreleme iþleminin yapýldýðý fonksiyon. karakter sayýsý verilen deger kadar kaydýrýlýyor daha sonra tekrar
//karaktere dönüþtürülüyor.
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
//þifreleme iþleminin tam tersi yapýlýyor karakter sayýsý ile verilen parola degeri çýkartýlýyor daha sonra mod iþlemi yapýlýp çýkan
//sayý karakter'e dönüþtürülüyor.
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
//Karakterin kaçýncý sýrada oldugu arabulunuyor.
int arabul(char karakter[], char arananHarf) {
 
    int i, sayac = -1;
 
    for (i = 0; i < strlen(karakter); i++) {
        if (arananHarf == karakter[i])
            sayac = i;
    }
    return sayac;
}
