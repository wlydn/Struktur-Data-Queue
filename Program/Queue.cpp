//================================//
// Hak Cipta Waliyudin Faturohman //
// Universitas Teknologi Yogyakarta //
//================================//
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int pilih;
int add_pilih();
int add_belakang();
int delete_belakang();
int tampil();



struct simpul
{
   char nama[30], pos[20];
  int no;
   struct simpul *next;
} *baru, *awal=NULL, *akhir=NULL,*hapus,*temp;

int main()
{
   do
   {
     cout <<"---------------------------------------"<<'\n';
     cout << "	QUEUE MENGGUNAKAN LINKED LIST" << '\n';
     cout <<" "<<'\n';
     cout << "1. Enqueue" << '\n';
     cout << "2. Dequeue" << '\n';
     cout << "3. Tampil" << '\n';
     cout << "4. Exit" << '\n';
     cout << "Pilih (1-4) : ";
     cin>>pilih;
     add_pilih();
   }while(pilih!=4);
  return 0;
}

int add_pilih()
{
   if(pilih==1)
       add_belakang();
   else if(pilih==2)
       delete_belakang();
   else if(pilih==3)
       tampil();
   else
       return 0;
}

int add_belakang()
{
   baru=(simpul*)malloc(sizeof(struct simpul));
   cout<<"Data pemain bola"<<endl;
   cout<<"---------------------"<<endl;
   cin.ignore();
   cout<<"No Punggung   : ";
   cin>>baru->no;
   cin.ignore();
   cout<<"Nama  : ";
   cin.getline(baru->nama,30);
   cout<<"Posisi  : ";
   cin.getline(baru->pos,20);
 cin.ignore();
   baru->next=NULL;
   if(awal==NULL)
   {
       awal=baru;
   }
   else
   {
       akhir->next=baru;
   }
   akhir=baru;
   akhir->next=NULL;
   cout<<endl<<endl;

}

int delete_belakang()
{
   if (awal==NULL)
       cout<<"Kosong"<<endl;
   else if(awal==akhir)
   {
        hapus=awal;
        awal=awal->next;
    
   }
   else
   {
       hapus=awal;
       while(hapus->next!=akhir)
            hapus=hapus->next;
       akhir=hapus;
       hapus=akhir->next;
       akhir->next=NULL;
   
   }
   cout<<endl<<endl;

}

int tampil()
{
    if (awal==NULL)
         cout<<"Kosong"<<endl;
    else
    {
        temp=awal;
        while(temp!=NULL)
        {
           	cout<<temp->no<<" -> "<<temp->nama<<" -> "<<temp->pos<<endl;
           temp=temp->next;
        }
    }
    getch();
}
