#include <iostream>
using namespace std;

struct intList{
	int num;	
	intList * next;
};

intList * head;
intList * revhead;

void insert(){ 
	intList * newNum = new intList;
	intList * temp;

	cin >> newNum->num;
	newNum->next = 0;
		
	if(head==0) 
		head=newNum;
	else{
		temp = head;
		while(temp->next != 0)
			temp = temp->next;
					
		temp->next = newNum;
		revhead = temp->next;

	}
}

void reverse(){
	intList * revtemp = head;
	intList * revnext; 
	intList * revprev = 0;

	while(revtemp != 0){
		
		revnext = revtemp->next;
		revtemp->next = revprev;
		revprev = revtemp;
		revtemp = revnext;
	}

}

void print(){

	intList * temp;
	temp = revhead;

	while(temp != 0){
		cout << temp->num<<" -> ";	
		temp = temp->next;	
	}	
	cout << "NULL"<<endl;
}

void main(){
	int n;
	cout << "Enter number of integers: ";
	cin >> n;
	for(int i = 0; i < n; i++)
		insert();
			
	reverse();
	print();
}