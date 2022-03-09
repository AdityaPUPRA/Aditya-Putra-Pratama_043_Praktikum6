#include <iostream>
using namespace std;

struct Node{
	int k;
	char h;
	int pang;
	Node *next;
};

class poli{
	public :
	Node *head;
	Node *tail;
	
	void infirst(int x,char y,int z){
		Node *baru = new Node();
		head = baru;
		tail = baru;
		baru->k=x;
		baru->h=y;
		baru->pang=z;
		baru->next=NULL;
	}

void input(int x, char y, int z){
	Node *baru = new Node();
	Node *cari = new Node();
	Node *before = new Node();
	baru->k=x;
	baru->h=y;
	baru->pang=z;
	cari=head;

	if(baru->pang>cari->pang){
		baru->next=cari;
		head=baru;
	}else {
		while(cari!=NULL&&baru->pang<cari->pang){
			before=cari;
			cari=cari->next;
	}
		before->next=baru;
		baru->next=cari;
	}
}

void hapus(int x,int y){
	Node *hapus = new Node();
	Node *cari = new Node();
	cari=head;
	
	if(cari->k==x && cari->pang==y){
		head=cari->next;
		delete cari;
	} else {
		while(cari->k!=x && cari->pang!=y){
			hapus=cari;
			cari=cari->next;
			if(cari==NULL)break;
	}
	
	if(cari==NULL){
	} else if(cari->next==NULL){
		hapus->next=NULL;
		delete cari;
	} else {
		hapus->next=cari->next;
		delete cari;
	}
	}
}

	void print(){
		Node *baru = new Node();
		baru=head;
		
		while(baru!=NULL){
			if(baru->pang!=0 && baru->k!=1) {
				cout<<baru->k<<baru->h<<"^"<<baru->pang;
		} else if(baru->k==1) {
			cout<<baru->h<<"^"<<baru->pang;
		} 
		else cout<<baru->k;
		if(baru->next!=NULL){
			cout<<" + ";
		}
		baru=baru->next;
		}
		if(baru==NULL){
			cout<<"";
		}
		cout<<endl;
		}
};

poli p[3];
void ubah(int x){
	int a,b,c;
	cout<<"Pilih operasi yang diinginkan : "<<endl;
	cout<<"1. Memasukkan data"<<endl;
	cout<<"2. Menghapus data"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"Pilihan : "; cin>>a;
	
	if(a==1){
		cout<<"Masukkan Koefesien dan Pangkat :"<<endl;
		cout<<"Koefesien : "; cin>>b;
		cout<<"Pangkat : "; cin>>c;
		if(c==0){
			p[x].input(b,'0',c);
	} else {
		p[x].input(b,'x',c);
	}
	} else if (a==2){
		cout<<"Masukkan Koefesien dan Pangkat yang mau dihapus :"<<endl;
		cout<<"Koefesien : "; cin>>b;
		cout<<"Pangkat : "; cin>>c;
		p[x].hapus(b,c);
	} else if (a==3) {
		} else {
			cout<<"Pilihan Tidak ada"<<endl;
		}
}

int main(){
	int a,c,d;
	char b;
	p[0].infirst(6,'x',8);
	p[0].input(8,'x',7);
	p[0].input(5,'x',5);
	p[0].input(1,'x',3);
	p[0].input(15,'0',0);
	cout<<"P1 = ";
	p[0].print();
	p[1].infirst(3,'x',9);
	p[1].input(4,'x',7);
	p[1].input(3,'x',4);
	p[1].input(2,'x',3);
	p[1].input(2,'x',2);
	p[1].input(10,'0',0);
	cout<<"P2 = ";
	p[1].print();
	p[2].infirst(1,'x',2);
	p[2].input(5,'0',0);
	cout<<"P3 = ";
	p[2].print();
	
	do{
	cout<<"Pilih polinom yang akan dioperasikan:"<<endl;
	cout<<"1. P1"<<endl;
	cout<<"2. P2"<<endl;
	cout<<"3. P3"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"Pilihan : "; cin>>a;
	ubah(a-1);cout<<endl;
	cout<<"P1 = ";p[0].print();
	cout<<"P2 = ";p[1].print();
	cout<<"P3 = ";p[2].print();
	}while(a!=4);
}