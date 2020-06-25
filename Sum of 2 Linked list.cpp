//Sum of 2 Linked list
#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int d){
		data = d;
		next = NULL;
	}
};

void ReverseLL(node* &head){
	node* c,*p=NULL,*n;
	c = head;
	while(c){
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;
	return;
}

void InsertAtFront(node* &head,int data){
	if(head == NULL){
		head = new node(data);
		return;
	}

	node* n = new node(data);
	n->next = head;
	head = n;
	return;
}

void PrintLL(node* h){
	while(h){
		cout<<h->data<<' ';
		h=h->next;
	}
	cout<<endl;
}

void SumLL(node* h,node* h1,int n,int m){
	if(n<m){
		swap(n,m);
		swap(h,h1);
	}

	int sum = 0,rem=0;
	node* x = h;
	while(h && h1){
		sum  = h->data+h1->data+rem;
		rem = sum/10;
		sum%=10;
		h->data = sum;
		h=h->next;
		h1=h1->next;
	}
     while(h) {
             int sum = h->data + rem;
             h->data = sum % 10;
             rem = sum/10;
             h=h->next;
             }
	if(rem!=0){
		node* temp = x;
		while(temp->next){
			temp=temp->next;
		}
		temp->next = new node(rem);
	}
	ReverseLL(x);
	PrintLL(x);
}

int main(){
	int n,m;
	node* h=NULL;
	node* h1 = NULL; 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int data;cin>>data;
		InsertAtFront(h,data);
	}
	for(int i=0;i<m;i++){
		int data;cin>>data;
		InsertAtFront(h1,data);
	}

	SumLL(h,h1,n,m);

	return 0;
}