#include <iostream>
#include <math.h>

using namespace std;

class node
{
	public:
		int key;
		int data;
		node *next;
		node *prev;

		node()
		{
			key =0;
			data= 0;
			next = NULL;
			prev = NULL;
			
		}
		node (int pos ,int val)
		{
			key = pos;
			data = val;
			next = NULL;
			prev = NULL;
		}
};
class linked
{
	public:
		node *head;
	linked()
	{
		head = NULL;
		prev = NULL;
		
	}
	linked(node *n)
	{
		head = n;
	}
	
	node *nodeexists(int k)
	{
		node *temp=NULL;
		node *ptr = head;
		while (ptr ! NULL)
		{
			if(ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;	
	}
	void append(node *n)
	{
		if(nodeexists(n->key)!=NULL)
		{
			cout<< "node is already there" << endl;
		}
		else 
		{
			if(head == NULL)
			{
				head =n;
				cout<< "node apppended"<< endl;
			}
			else 
			{
			    node* ptr = head;
			    while (ptr!=NULL)
			    {
			    	ptr =ptr->next; 
				}
				n->prev = ptr;
				ptr->next= n;
				n->next = NULL;
			}
		}
	}
	void prepend(node *n)
	{
		if(nodeexists(n->key)!= NULL)
		{
			cout<< "node already exists"<< endl;
		}
		else
		{
			if(head==NULL)
			{
				head=n;
				cout<< "node appended"<< endl;
			}
			else 
			{
			    head ->prev = n;
				n->next = head;
				head = n;
				cout<< "node prepended"<< endl;
			}
		}
	}
	void insert(int k,node *n)
	{
		node *ptr = nodeexists(k);
		if(ptr== NULL)
		{
			cout<< "node does not exist"<< endl;
		}
		else 
		{
			node* nodenext = ptr->next;
		    if(nodenext == NULL)
		    {
		    	ptr->next =n;
		    	n->prev= ptr;
				cout<< "node appended at last"<< endl; 
			}
			else 
			{
			    ptr->next = n;
			    n->prev =ptr;
			    n->next = nodenext;
			    nodenext ->prev=n;
			    cout<< "node is inserted in between"<< endl;
			}	
		}
	}
    void deletenode(int k)
	{
		node *ptr=nodeexists(k);
		node* ptr1 = head;
		node *temp;
		if(ptr==NULL)
		{
			cout<<"no node is present inside linked list with the given value"<< endl;
		}
		else 
		{
			if(head->key = k)
			{
				head->prev
				head = head ->next;
				cout<< "node deleted"<< endl;
				
			}
			else {
				while (ptr1->next != ptr)
				{
					ptr1= ptr1->next;
				}
				if(ptr->next ==NULL)
				{
					ptr1->next = NULL;
					cout<< "node deleted"<< endl;
				}
				else 
				{
					temp = ptr->next;
					ptr1->next=temp;
					cout<< "node deleted"<< endl;
					
				}
			}
			
		}
    }
	void updatenode(int k,int val)
		{
			node* ptr=nodeexists(k);
			if (ptr==NULL)
			{
				cout<< "no node is present with given value"<< endl;
			}
			else
			{
				ptr->data = val;
				cout<< "data updated"<< endl;
			}	
		}	
    void printList() 
	{
      if (head == NULL) {
      cout << "No Nodes in Doubly Linked List";
    } else {
      cout << endl << "Doubly Linked List Values : ";
      node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp-> key << "," << temp-> data << ") <--> ";
        temp = temp -> next;
      }
    }
	
 }
};

int main()
{
	linked obj;
	int ch;
	int val,key,k1,d1;
	do
	{
		cout<< "choose operation you wnat to do "<< endl;
		cout<< " 1.node exists\n 2. append node\n 3.prepend node \n 4.delete node\n 5.update \n 6.print list"<< endl;
		cin>> ch;
		node* n1= new node();
		switch (ch)
		{
			case 1:
				cout<< "enter key value"<< endl;
				cin>> key;
				if(obj.nodeexists(key)!=NULL)
				{
					cout<< "node exists"<< endl;
				}
				else
				cout<< "node do not exist"<< endl;
				break;
			case 2:
				cout<< "enter the key and data values"<<endl;
				cin >> k1;
				cin>> d1;
				n1->key=k1;
				n1->data =d1;
				obj.append(n1);
				break;
			case 3:
				cout<< "enter the keya and data values"<< endl;
				cin>>k1;
				cin>> d1;
				n1->key=k1;
				n1->data =d1;
				obj.prepend(n1);
				break;
			case 4:
				cout<< " enter the key value "<< endl;
				cin>> key;
				obj.deletenode(key);
				break;
			case 5:
				cout<<"enter the key and new data"<< endl;
				cin >>k1;
				cin>> d1;

				obj.updatenode(k1,d1);
				break;
			case 6:
				obj.printList();
				break;
			default :
				cout<< "enter the correct choice"<< endl;
				break;
		}

	}while (ch!=7);

}
