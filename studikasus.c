#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char nama[100];
long long harga;
int dk;
time_t sekarang;
char* string_waktu;

void seluruh_catatan();

void tambah_catatan();

void linear_search();

int main ()
{
    int pilih;
    while(1) 
    {
        printf("BUKU CATATAN TANSAKSI\n");
        printf("1. SELURUH CATATAN TRANSAKSI\n");
        printf("2. TAMBAHAKAN CATATAN TRANSAKSI\n");
        printf("3. CARI BERDASARKAN TANGGAL\n");
        printf("4. EXIT\n");
        
        printf("Silahkan pilih 1 - 4: ");

        scanf(" %d",&pilih);

        switch (pilih)
        {
        case 1:
            seluruh_catatan();
            break;

        case 2:
            tambah_catatan();
            break;

        case 3:
            linear_search();
            break;

        case 4:
            printf("SELESAI\n");
            return 0;

        default:
            break;
        }
    }

}

void seluruh_catatan()
{
   

    FILE *fp;

    fp = fopen("seluruhcatatan.txt","r");

    int total = 0;
    char waktu[100];

    while (1)
    {

      if(fscanf(fp, " %[^#]#%d#%[^#]#%d#\n", waktu, &dk, nama, &harga) != 4)
      {
        break;
      }


      printf("%s", waktu);

      if(dk == 1)
      {
        printf("Tipe: Debit\n");
        total += harga;
      } 
      else 
      {
        printf("Tipe: Credit\n");
        total -= harga;
      }
      printf("Nama: %s\n", nama);
      printf("Nilai: %lld\n", harga);
      printf("----------------------------------------------\n");

    }
    printf("Selisih debit dan kredit: %d\n", total);
    
    
    
    fclose(fp);
    

}

void tambah_catatan()
{

    FILE *fp;

    fp = fopen("seluruhcatatan.txt","a");

    sekarang = time(NULL);

    if (sekarang == ((time_t)-1))
    {
        fprintf(stderr,"gagal menginput waktu\n");
        exit;
    }

    string_waktu = ctime(&sekarang);

    if (string_waktu == NULL)
    {
        fprintf(stderr,"gagal menginput waktu");
        exit;
    }
    
    printf("waktu anda menginput data ini adalah %s\n",string_waktu);

    

    printf("JENIS TRANSAKSI:\n");
    printf("1. DEBIT\n");
    printf("2. KREDIT\n");
    printf("silahkan pilih jenis transaksi 1(debit)/2(kredit):");
    scanf(" %d",&dk);

    

    switch (dk)
    {
    case 1:
        printf("DEBIT\n");
        break;

    case 2:
        printf("KREDIT\n");
        break;
    
    default:
        break;
    }
    

    printf("\nNAMA TRANSAKSI:");
    scanf(" %s",&nama);

    printf("\nNILAI TRANSAKSI:");
    scanf(" %lld",&harga);

    printf("\n");

    

    fprintf(fp,"%s#%d#%s#%lld#\n",string_waktu,dk,nama,harga);
    fclose(fp);
    return;
}

void linear_search()
{
    FILE *fp;

    fp = fopen("seluruhcatatan.txt","r");

    int tahun;
    char waktu[100];

    printf("Cari berdasarkan tahun\n");
    printf("Pilih tahun: ");

    scanf(" %d", &tahun);

    int n = 0;
    while (1)
    {
      if(fscanf(fp, " %[^#]#%d#%[^#]#%d#\n", waktu, &dk, nama, &harga) != 4)
      {
        break;
      }
      n++;
      

    }
    fclose(fp);

    

    fp = fopen("seluruhcatatan.txt","r");

    int found = 0;
    
    for (int i = 0; i < n; i++)
    {
      int tahun1;
      char temp1[10];
      char temp2[10];
      char temp3[10];
      char temp4[10];
      char temp5[10];
      char temp6[100];
      char temp7[100];
      fscanf(fp, "%s %s %s %s %d\n#%[^#]#%[^#]#%[^#]#\n", 
      temp1, temp2, temp3, temp4, &tahun1, temp5, temp6, temp7);

      if(tahun1 == tahun)
      {
        printf("%s %s %s %s %d\nTipe: %s\nNama: %s\nNilai: %s\n",
        temp1, temp2, temp3, temp4, tahun1, temp5, temp6, temp7);
        found++;
      }
    }
    
    if(found == 0)
    {
      printf("tidak ditemukan\n");
    }

    fclose(fp);
    
}