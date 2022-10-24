//Gülþen Taþtan_200707028_Bilgisayar Mühendisliði
// Programlamaya Giriþ_BIM-103-50-50 
// 2021-2022 Akademik yýlý -Güz Dönemi-Proje1

#include<stdio.h> // standart giriþ-çýkýþ 
// Fonksiyon Bildirimleri 
void menu(); 

void baslangictaBankot(); 

int paraCek(int x,int y) ; 

int paraYatir(int a,int b); 

void KasaninDurumuCekilen(int cek); 

void KasaninDurumuYatirilan(int yatir); 
// void fonksiyonu geriye bir deðer döndürmez .

int main() //Her C programýnýn bir parçasýdýr ve her C programý yürütülmeye main fonksiyonundan baþlar.
{
	// Deðiþkenler, girdiðimiz deðerleri alan veya programýn çalýþmasýyla bazý deðerlerin atandýðý, veri tutucularýdýr. 
	// Bir program kullanýlmadan önce tüm deðiþkenler bir isim ve bir veri türü ile tanýmlanmalýdýr.
	int secim;
	int bakiye=3750;
	int cek;
	int yatir;
	int beslik=50,onluk=50,yirmilik=50,ellilik=20,yuzluk=10; // deðiþkenlere ilk deðer atama
	int cek1,yatir1;
	
	menu();
	printf("Seciminiz:"); //Ekrana herhangi bir þey yazdýrmak içinse printf() fonksiyonu kullanýlýr.
	scanf("%d",&secim); //C de klavyeden bir deðer alabilmek için scanf() fonksiyonunu kullanýrýz. 
	 // printf ve scanf kullanýcý ve bilgisayar arasýndaki etkileþimi kolaylaþtýrýr 

	
	while(secim!=-1) // Döngünün koþulu
	//Burada secim==4 oluncaya kadar döngü istenildiði kadar çalýþabilir.
	{
	
		switch(secim)
		{
			case 1:
	        {
	    	  printf("Mevcut Bakiye:%d\n",bakiye);
			   printf("Kasanin Durumu:\n");
    	       baslangictaBankot(); // Fonksiyon çaðrýsý
    	       
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
		            KasaninDurumuCekilen(cek); // Fonksiyon Çagrýsý
	                menu();
	                printf("Seciminiz:");
             	    scanf("%d",&secim);		
				 }
			    break;	// Ani sonlandýrýcý,eðer kullanmasaydým sonraki case den otomatikmen devam ederdi
			}
			case 3:
			{
				printf("Mevcut Bakiye:%d\n",paraCek(bakiye,cek));
				printf("Yatirilacak Miktar:");
				scanf("%d",&yatir);
                printf("Yeni Bakiye:%d\n",paraYatir(paraCek(bakiye,cek),yatir)); // Fonksiyon içine fonksiyon parametre olarak verilebilir

       			KasaninDurumuYatirilan(yatir); // Fonksiyon Çaðrýsý
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


// FONKSÝYON TANIMLARI	
void menu()  // Menüyü her seferinde yazmaktansa alt fonksiyondan yararlan.
{
	// Her printf bir önceki printef'in yazmayý býrakrýðý yerden yazmaya devam eder 
 	printf("    MENU");
 	printf("\n1 Kasayi Goster \n");
	printf("2 Para Cekme \n");
	printf("3 Para Yatirma \n");
	printf("4 Cikis \n\n");
     	
}

void baslangictaBankot() // Baþlangýçtaki bankot sayýsýný tutan fonksiyon bildirimi 
{
	    int beslik=50, onluk=50, yirmilik=50, ellilik=20, yuzluk=10;
    	printf("5 TL bankot miktari  :%d\n",beslik);
		printf("10 TL bankot miktari :%d\n",onluk);
		printf("20 TL bankot miktari :%d\n",yirmilik);
		printf("50 TL bankot miktari :%d\n",ellilik);
		printf("100 TL bankot miktari:%d\n",yuzluk);	
}

int paraCek(int x,int y) // Kasadan para çekme sýrasýnda yeni bakiyeyi hesaplar  
{
	return x-y; 
}

int paraYatir(int a,int b) // Kasaya para yatirma sýrasýnda yeni bakiyeyi hesaplar 
{
	return a+b;
}
void KasaninDurumuCekilen(int cek) //  Kasadan çekilen paranýn bankot sayýsýndaki deðiþimini tutan fonksiyon
{
 int beslik=50,onluk=50,yirmilik=50,ellilik=20,yuzluk=10;
 	
 	/*Eðer koþul doðruysa (Koþul saðlanmýþtýr),if'in gövdesindeki ifade yürütülür.Eðer  yanlýþsa (Koþul saðlanmamýþtýr) ,
       gövde ifadesi yürütülmez. Gövde ifadesi yürütülse de yürütülmeses de ,if ifadesi tamamlandýktan sonra yürütme if
	   ifadesinden sonraki ifade ile yoluna devam eder.*/
	   
 	if(cek%5==0 ) // çekilen para beþin bir katý olmalýdýr
	{
		 // En az sayýda bankot çekmek için ilk olarak bunu kontrol etmek gerekir
		 if((cek/100)>=0) // Cekilen sayýnýn yüze bölümünden bölüm sýfýrdan büyükse 
		 {
		 	// En az sayýda bankot çekmek için ilk olarak bunu kontrol etmek gerekir
            yuzluk=yuzluk-(cek/100); // Yüzlük bankotlardan  cekilen sayýnýn yüze bölümünden bölümü çýkar 
        	ellilik=ellilik-((cek%100)/50); //cekilen sayýnýn yüze bölümünden kalanýn elliye bölünce elde edilen bölüm deðerini çýkar 
		 } 
	
         if((cek%100)!=0) // çekilen sayýnýn yüze bölümünden kalan sýfýrdan farklýysa koþulu saðlar
        {
           	if((cek%100)==5) // çekilen sayýnýn yüze bölümünden kalan beþ ise koþulu saðlar
	       	{
		        beslik=beslik-1; // Beþlik bankot sayýsýný azalt 
	        }
            else if((cek%100)==10) // çekilen sayýnýn yüze bölümünden kalan on ise koþulu saðlar
	       	{
		        onluk=onluk-1;
		    }	
		    else if((cek%100)==20)
	       	{
		    	yirmilik=yirmilik-1;
	        }	
		    else if((cek%100)<50) // Çekilen sayýnýn yüze bölümünden kalan elliden küçükse 
	        {
	        	// en az sayýda bankot kullanýlmasý için yirmilik bankot sayýsýnýn kaç olabileceðine bakýlýr
		        yirmilik=yirmilik-((cek%100)/20); //çekilen sayýnýn yüze bölünden kalanýn yirmiye bölümünden bölümü çýkar 
		             
		        if(((cek%100)%20)==10) // cekilen sayýnýn yüze bölümünden kalanýn yirmiye bölümünden kalan 10'a eþitse 
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
   	printf("Cekilen tutar 5'in bir katý olamidir:");
   }
        // En az sayýda bankot için önce yüzlük bankot sayýsý daha sonra buna baðlý olarak ellilik bankot sayýsýna bakýlýr 
        // Bu adýmlardan sonra da sýrasýyla en az sayýda olacak þekilde yimilik ,onluk ve beþlik bankot sayýlarý kontrol edilir.
    printf("\n");
	printf("kasanin durumu\n");
	printf("5 TL Bankot miktari  :%d\n",beslik);
	printf("10 TL Bankot miktari :%d\n",onluk);
	printf("20 TL Bankot miktari :%d\n",yirmilik);
	printf("50 TL Bankot miktari :%d\n",ellilik);
	printf("100 TL Bankot miktari:%d\n\n",yuzluk);
 }	
 	   
void KasaninDurumuYatirilan(int yatir)	// Kasya yatýrýlan paranýn bankot sayýsýndaki deðiþimini tutan fonksiyon
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
   	printf("Cekilen tutar 5'in bir katý olamidir:");
   }
        
    printf("\n");
	printf("kasanin durumu\n");
	printf("5 TL Bankot miktari  :%d\n",beslik);
	printf("10 TL Bankot miktari :%d\n",onluk);
	printf("20 TL Bankot miktari :%d\n",yirmilik);
	printf("50 TL Bankot miktari :%d\n",ellilik);
	printf("100 TL Bankot miktari:%d\n\n",yuzluk);
 }	
 


