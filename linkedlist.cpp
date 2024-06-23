/*#include <iostream>

using namespace std;

class Node{
	
	private :
		int data;
		Node *next;
		Node *head;
		Node *tail;
		
		public :
			Node()
			{
				head = NULL;
				tail = NULL;
			}
			
			int insert(int a){
				
				Node *n = new Node();
				n->data = a;
			    n->next = NULL;
				if(head==NULL && tail==NULL){
					head = n;
					tail = n;
				}
				else {
					tail->next = n;
					tail = n;
				}
				
			//	n->next = head;
			//	head = n;
			return a;	
			}
			void print(){
				
				Node *n = head;
				
			while(n!=NULL){
				
				cout<<n->data<<endl;
				n = n->next;
	}
		}
		
		void search(){
			Node *temp = new Node();
			 temp = head;
			 
			 if(temp->next!=NULL){
			 	cout<<"\n"<<temp->data<<" FOUND"<<endl;
			 }
			 else {
			 	temp = temp->next;
			 }
		}
};

int main(int argc, char** argv) {
	
	Node P;
	P.insert(5);
	P.insert(7);
	P.insert(10);
	P.print();
	P.search();
	return 0;
}*/

/*#include<iostream>
using namespace std;

class Node{
	
	private:
	int data;
	Node *next;
	Node *head;
	Node *tail;
	
	public :
		Node(){
			head = NULL;
			tail = NULL;
		}
		
		int insert(int a){
			
			Node *n=new Node();
		    n->data=a;
			n->next=NULL;
			if(head==NULL && tail==NULL){
				head=n;
				tail=n;
			}	
		else {
			tail->next=n;
			tail=n;
		}
		return a;
		
		}
		
		void search(int x){
			Node *temp=new Node();
			temp=head;
			while(temp!=NULL){
				if(temp->data==x){
					cout<<x<<" FOUND"<<endl;
					break;
				}
				else{
					temp=temp->next;
				}
			}
		}
		
		void Delete(int a){
			Node *temp=head;
			Node *curr;
			
			if(head->data==a){
				head=head->next;
				delete temp;
			}
			else{
				while(temp!=NULL){
					if(temp->next->data==a){
						curr=temp->next;
						temp->next=curr->next;
						delete curr;
						break;
					}
					else if(temp->next->data==a && tail->data==a){
						curr==tail;
						tail=temp;
						tail->next=NULL;
						delete curr;
						break;
					}
					else {
						temp=temp->next;
					}
				}
			}
		}
		void print(){
			Node *temp;
			temp=head;
			
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
};

int main(){
	Node N;
	
	N.insert(5);
	N.insert(8);
	N.insert(9);
	N.insert(11);
	N.print();
	N.search(9);
	cout<<"After Deletion"<<endl;
	N.Delete(5);
	N.print();
}*/

#include<iostream>

using  namespace std;

class Node{
	
	private :
	int data;
	Node *next;
	Node *prev;
	Node *head;
	Node *tail;
	
	public : 
	Node(){
		head = NULL;
		tail = NULL;
		
	}
	
	void insert(int a){
		
		Node *n = new Node();
		n->data = a;
		n->next = NULL;
		n->prev = NULL;
		
		if(head==NULL && tail==NULL){
			head = n;
			tail = n;
		}
		
		else {
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
	}
	
	void inserthead(int a){
			Node *n = new Node();
		n->data = a;
		n->next = NULL;
		n->prev = NULL;
		head->prev=n;
		n->next=head;
		head=n;
		
	}
	
	void insertpos(int a , int pos){
		Node *n = new Node();
		Node *temp=head;
		n->data = a;
		n->next = NULL;
		n->prev = NULL;
		int i=1;
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		n->prev=temp;
		n->next=temp->next;
		temp->next=n;
		n->next->prev=n;
	
	}
	/*void search(int x){
			Node *temp=new Node();
			temp=head;
			while(temp!=NULL){
				if(temp->data==x){
					cout<<x<<" FOUND"<<endl;
					break;
				}
				else{
					temp=temp->next;
				}
			}
		}*/
	
	void Delete(int a){
		
		Node *temp;
		
		temp=head;
		
		if(head->data==a){
			
			head = head->next;
			head->prev=NULL;
			delete temp;
		}
		else {
			while(temp!=NULL){
				
				
				
				if(temp->data==a){
					
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					delete(temp);
				    break;
				}
				
				else if(tail->data==a){
					temp=tail;
					temp->prev->next=NULL;
					tail=tail->prev;
					delete(temp);
					break;
				}
				else {
					temp=temp->next;
				}
				
			}
		}
		
	}
	
	void print(){
		
		Node *temp=head;
		
		while(temp!=NULL){
			
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
};

int main(){
	
	Node N;
	N.insert(5);
	N.insert(10);
	N.insert(15);
	N.insert(20);
	N.print();
	cout<<"______"<<endl;
	N.inserthead(2);
	N.print();
	cout<<"_______"<<endl;
	N.insertpos(8,2);
	N.print();
	cout<<"_____"<<endl;
	N.insert(7);
	N.print();
	cout<<"______"<<endl;
	N.Delete(15);
	N.print();
}

/*#include<iostream>
using namespace std;
class Node{
	private :
	int data;
	Node *top;
	Node *next;
	public :
		Node(){
			top=NULL;
		}
		
		bool isEmpty(){
			if(top==NULL)
			return true;
			else 
			return false ;
			
		}
		
		void push(int a){
			Node *n=new Node();
			n->data=a;
			n->next=top;
			top=n;
		}
		
		void pop(){
			if(isEmpty()){
				cout<<"Stack is Empty"<<endl;
			}
			else{
				Node *temp;
				temp=top;
				top=top->next;
				delete(temp);
			}
		}
		void showstack(){
			Node *temp=new Node();
			temp=top;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
	
	
};

int main(){


  Node N ;
  cout<<"Stack After Push : "<<endl;
  N.push(5);
  N.push(10);
  N.push(15);
  N.push(20);
  N.push(25);
  N.showstack();
  cout<<"__________________"<<endl;
  cout<<"Stack After Pop : "<<endl;
  N.pop();
  N.pop();
  N.pop();
  N.showstack();
}*/

/*#include<iostream>
using namespace std;
class Node{
	private:
	int data;
	Node *front;
	Node *rear;
	Node *next;
	public:
		Node(){
			front=NULL;
			rear=NULL;
		}
		
		bool isEmpty(){
			if(front==NULL && rear==NULL)
			return true;
			else
			return false;
			
		}
		
		void Enqueue(int a){
			Node *n=new Node();
			n->data=a;
			n->next=NULL;
			
			if(front==NULL && rear==NULL){
				front=n;
				rear=n;
			}
			else{
				rear->next=n;
				rear=n;
			}
			
		}
		
		void Dequeue(){
			if(!isEmpty()&&front<=rear){
				Node *temp;
					temp=front;
					front=front->next;
					delete(temp);
				
			}
		
				else{
					cout<<"Queue is Empty"<<endl;
				}
			}
		
		void showqueue(){
			Node *temp;
			temp=front;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
};

int main(){
	
	Node N;
	N.Enqueue(4);
	N.Enqueue(8);
	N.Enqueue(12);
	N.Enqueue(16);
	N.Enqueue(20);
	cout<<"Queue After Enqueue : "<<endl;
	N.showqueue();
	cout<<"____________________"<<endl;
	cout<<"Queue After Dequeue  : "<<endl;
	N.Dequeue();
	N.Dequeue();
	N.Dequeue();
	N.showqueue();

}  */
