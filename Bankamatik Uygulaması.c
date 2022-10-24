//G�l�en Ta�tan_200707028_Bilgisayar M�hendisli�i
// Programlamaya Giri�_BIM-103-50-50 
// 2021-2022 Akademik y�l� -G�z D�nemi-Proje1

#include<stdio.h> // standart giri�-��k�� 
// Fonksiyon Bildirimleri 
void menu(); 

void baslangictaBankot(); 

int paraCek(int x,int y) ; 

int paraYatir(int a,int b); 

void KasaninDurumuCekilen(int cek); 

void KasaninDurumuYatirilan(int yatir); 
// void fonksiyonu geriye bir de�er d�nd�rmez .

int main() //Her C program�n�n bir par�as�d�r ve her C program� y�r�t�lmeye main fonksiyonundan ba�lar.
{
	// De�i�kenler, girdi�imiz de�erleri alan veya program�n �al��mas�yla baz� de�erlerin atand���, veri tutucular�d�r. 
	// Bir program kullan�lmadan �nce t�m de�i�kenler bir isim ve bir veri t�r� ile tan�mlanmal�d�r.
	int secim;
	int bakiye=3750;
	int cek;
	int yatir;
	int beslik=50,onluk=50,yirmilik=50,ellilik=20,yuzluk=10; // de�i�kenlere ilk de�er atama
	int cek1,yatir1;
	
	menu();
	printf("Seciminiz:"); //Ekrana herhangi bir �ey yazd�rmak i�inse printf() fonksiyonu kullan�l�r.
	scanf("%d",&secim); //C de klavyeden bir de�er alabilmek i�in scanf() fonksiyonunu kullan�r�z. 
	 // printf ve scanf kullan�c� ve bilgisayar aras�ndaki etkile�imi kolayla�t�r�r 

	
	while(secim!=-1) // D�ng�n�n ko�ulu
	//Burada secim==4 oluncaya kadar d�ng� istenildi�i kadar �al��abilir.
	{
	
		switch(secim)
		{
			case 1:
	        {
	    	  printf("Mevcut Bakiye:%d\n",bakiye);
			   printf("Kasanin Durumu:\n");
    	       baslangictaBankot(); // Fonksiyon �a�r�s�
    	       
    		   printf("\n\n");
               menu();
	   	       printf("Seciminiz:");
     	       scanf("%d",&secim);
     	       break;
	    	}	
	    	case 2:
	    	{
	    		printf("Mevcut Bakiye:%d\n",bakiye);
    	        printf("Cekilecek Miktar:");
	        	scanf("%d",&cek);
	             if(cek>bakiye)
	             {
	             	printf("Yetersiz Bakiye\n");
				 }
				 else
				 {
				    printf("Yeni Bakiye:%d\n",paraCek(bakiye,cek));	
		            KasaninDurumuCekilen(cek); // Fonksiyon �agr�s�
	                menu();
	                printf("Seciminiz:");
             	    scanf("%d",&secim);		
				 }
			    break;	// Ani sonland�r�c�,e�er kullanmasayd�m sonraki case den otomatikmen devam ederdi
			}
			case 3:
			{
				printf("Mevcut Bakiye:%d\n",paraCek(bakiye,cek));
				printf("Yatirilacak Miktar:");
				scanf("%d",&yatir);
                printf("Yeni Bakiye:%d\n",paraYatir(paraCek(bakiye,cek),yatir)); // Fonksiyon i�ine fonksiyon parametre olarak verilebilir

       			KasaninDurumuYatirilan(yatir); // Fonksiyon �a�r�s�
       	 		menu();
	    		printf("Seciminiz:");
     			scanf("%d",&secim);	
     			
     			if(secim==2)
     			{
     				printf("Mevcut Bakiye:%d\n",paraYatir(paraCek(bakiye,cek),yatir))	;
     				printf("Cekilecek Miktar:");
	        	    scanf("%d",&cek1);
	        	    printf("Yeni Bakiye:%d\n",paraCek(paraYatir(paraCek(bakiye,cek),yatir),cek1));	
	        	    
	        	    KasaninDurumuCekilen(cek1);
	        	    menu();
	                printf("Seciminiz:");
                    scanf("%d",&secim);	 
				 }
				
     			break;
			}
			case 4:
			{
				   if(secim==4)
			     	break;
			}	
	   }
	}
	
	   	return 0;
}


// FONKS�YON TANIMLARI	
void menu()  // Men�y� her seferinde yazmaktansa alt fonksiyondan yararlan.
{
	// Her printf bir �nceki printef'in yazmay� b�rakr��� yerden yazmaya devam eder 
 	printf("    MENU");
 	printf("\n1 Kasayi Goster \n");
	printf("2 Para Cekme \n");
	printf("3 Para Yatirma \n");
	printf("4 Cikis \n\n");
     	
}

void baslangictaBankot() // Ba�lang��taki bankot say�s�n� tutan fonksiyon bildirimi 
{
	    int beslik=50, onluk=50, yirmilik=50, ellilik=20, yuzluk=10;
    	printf("5 TL bankot miktari  :%d\n",beslik);
		printf("10 TL bankot miktari :%d\n",onluk);
		printf("20 TL bankot miktari :%d\n",yirmilik);
		printf("50 TL bankot miktari :%d\n",ellilik);
		printf("100 TL bankot miktari:%d\n",yuzluk);	
}

int paraCek(int x,int y) // Kasadan para �ekme s�ras�nda yeni bakiyeyi hesaplar  
{
	return x-y; 
}

int paraYatir(int a,int b) // Kasaya para yatirma s�ras�nda yeni bakiyeyi hesaplar 
{
	return a+b;
}
void KasaninDurumuCekilen(int cek) //  Kasadan �ekilen paran�n bankot say�s�ndaki de�i�imini tutan fonksiyon
{
 int beslik=50,onluk=50,yirmilik=50,ellilik=20,yuzluk=10;
 	
 	/*E�er ko�ul do�ruysa (Ko�ul sa�lanm��t�r),if'in g�vdesindeki ifade y�r�t�l�r.E�er  yanl��sa (Ko�ul sa�lanmam��t�r) ,
       g�vde ifadesi y�r�t�lmez. G�vde ifadesi y�r�t�lse de y�r�t�lmeses de ,if ifadesi tamamland�ktan sonra y�r�tme if
	   ifadesinden sonraki ifade ile yoluna devam eder.*/
	   
 	if(cek%5==0 ) // �ekilen para be�in bir kat� olmal�d�r
	{
		 // En az say�da bankot �ekmek i�in ilk olarak bunu kontrol etmek gerekir
		 if((cek/100)>=0) // Cekilen say�n�n y�ze b�l�m�nden b�l�m s�f�rdan b�y�kse 
		 {
		 	// En az say�da bankot �ekmek i�in ilk olarak bunu kontrol etmek gerekir
            yuzluk=yuzluk-(cek/100); // Y�zl�k bankotlardan  cekilen say�n�n y�ze b�l�m�nden b�l�m� ��kar 
        	ellilik=ellilik-((cek%100)/50); //cekilen say�n�n y�ze b�l�m�nden kalan�n elliye b�l�nce elde edilen b�l�m de�erini ��kar 
		 } 
	
         if((cek%100)!=0) // �ekilen say�n�n y�ze b�l�m�nden kalan s�f�rdan farkl�ysa ko�ulu sa�lar
        {
           	if((cek%100)==5) // �ekilen say�n�n y�ze b�l�m�nden kalan be� ise ko�ulu sa�lar
	       	{
		        beslik=beslik-1; // Be�lik bankot say�s�n� azalt 
	        }
            else if((cek%100)==10) // �ekilen say�n�n y�ze b�l�m�nden kalan on ise ko�ulu sa�lar
	       	{
		        onluk=onluk-1;
		    }	
		    else if((cek%100)==20)
	       	{
		    	yirmilik=yirmilik-1;
	        }	
		    else if((cek%100)<50) // �ekilen say�n�n y�ze b�l�m�nden kalan elliden k���kse 
	        {
	        	// en az say�da bankot kullan�lmas� i�in yirmilik bankot say�s�n�n ka� olabilece�ine bak�l�r
		        yirmilik=yirmilik-((cek%100)/20); //�ekilen say�n�n y�ze b�l�nden kalan�n yirmiye b�l�m�nden b�l�m� ��kar 
		             
		        if(((cek%100)%20)==10) // cekilen say�n�n y�ze b�l�m�nden kalan�n yirmiye b�l�m�nden kalan 10'a e�itse 
		        {
				    onluk=onluk-1;
		        }
	            else if((cek%100)%20==5)
	            {
			   	    beslik=beslik-1;
	       	    }
	       	    else if((cek%100)%20==15)
	       	    {
	       	         onluk=onluk-1;
	       	          beslik=beslik-1;
			    }
			}
            else if(((cek%100)-50)%20==0)
    	    {
	            yirmilik=yirmilik-(((cek%100)-50)/20);	
		    } 
		    else if(((cek%100)-50)%20!=0)
	        {
		        yirmilik=yirmilik-(((cek%100)-50)/20);
		        if((((cek%100)-50)%20)==10)
		       	{
				    onluk=onluk-1;
		        }
	         	else if(((cek%100)-50)%10==5)
	            {
	                onluk=onluk-((((cek%100)-50)%20)/10);
			   	    beslik=beslik-1;
	       	    }
	         	}
            }		
    }
   else
   {
   	printf("Cekilen tutar 5'in bir kat� olamidir:");
   }
        // En az say�da bankot i�in �nce y�zl�k bankot say�s� daha sonra buna ba�l� olarak ellilik bankot say�s�na bak�l�r 
        // Bu ad�mlardan sonra da s�ras�yla en az say�da olacak �ekilde yimilik ,onluk ve be�lik bankot say�lar� kontrol edilir.
    printf("\n");
	printf("kasanin durumu\n");
	printf("5 TL Bankot miktari  :%d\n",beslik);
	printf("10 TL Bankot miktari :%d\n",onluk);
	printf("20 TL Bankot miktari :%d\n",yirmilik);
	printf("50 TL Bankot miktari :%d\n",ellilik);
	printf("100 TL Bankot miktari:%d\n\n",yuzluk);
 }	
 	   
void KasaninDurumuYatirilan(int yatir)	// Kasya yat�r�lan paran�n bankot say�s�ndaki de�i�imini tutan fonksiyon
{
    int beslik=50,onluk=50,yirmilik=50,ellilik=20,yuzluk=10;

 	if(yatir%5==0 )
	{
		 if((yatir/100)>=0)
		 {
            yuzluk=yuzluk+(yatir/100);
        	ellilik=ellilik+((yatir%100)/50);
		 } 
	
         if((yatir%100)!=0)
        {
        	if((yatir%100)==5)
	       	{
		        beslik=beslik+1;
	        }
            else if((yatir%100)==10)
	        {
		       	onluk=onluk+1;
		    }	
		    else if((yatir%100)==20)
	       	{
		    	yirmilik=yirmilik+1;
	        }	
		    else if((yatir%100)<50)
	        {
		         yirmilik=yirmilik+((yatir%100)/20);
		             
		        if(((yatir%100)%20)==10)
		        {
				    onluk=onluk+1;
		        }
	         	else if((yatir%100)%20==5)
	            {
			   	     beslik=beslik+1;
	       	    }
	       	    else if((yatir%100)%20==15)
	       	    {
	       	          onluk=onluk+1;
	       	          beslik=beslik+1;
			    }
			}
            else if(((yatir%100)-50)%20==0)
    	    {
	               yirmilik=yirmilik+(((yatir%100)-50)/20);	
		    } 
		    else if(((yatir%100)-50)%20!=0)
	        {
		        yirmilik=yirmilik+(((yatir%100)-50)/20);
		        if((((yatir%100)-50)%20)==10)
		      	{
				    onluk=onluk+1;
		       	}
	           else if(((yatir%100)-50)%10==5)
	            {
	                 onluk=onluk+((((yatir%100)-50)%20)/10);
			   	     beslik=beslik+1;
	       	    }
	       	}
       }		
    }
   else
   {
   	printf("Cekilen tutar 5'in bir kat� olamidir:");
   }
        
    printf("\n");
	printf("kasanin durumu\n");
	printf("5 TL Bankot miktari  :%d\n",beslik);
	printf("10 TL Bankot miktari :%d\n",onluk);
	printf("20 TL Bankot miktari :%d\n",yirmilik);
	printf("50 TL Bankot miktari :%d\n",ellilik);
	printf("100 TL Bankot miktari:%d\n\n",yuzluk);
 }	
 


