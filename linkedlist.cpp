#include "iostream"
using namespace std;

class Node{
	public :
	char id;
	Node *next;
	
	Node(){
		next = NULL;
	}
	
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
	
		LinkedList(){
			head = tail = NULL;
		}
		
		void insertToHead(char data)
		{
            Node *node = new Node;
            node -> id = data;

            if(head == NULL)
			{
                head = tail = node;
            }else
			{
                Node *tmp = head;
                head = node;
                head -> next = tmp;
            }
        }
        
        void insertToTail(char data)
		{
            Node *node = new Node;
            node -> id = data;

            if(head == NULL)
			{
                head = tail = node;
            }else
			{
                tail -> next = node;
                tail = node;
            }
            
        }
        
        void insertDataAfter(char data, char after)
		{
			if (head == NULL)
			{
				cout << "Error: empty data";
			
			}else if(tail->id == after)
			{
				insertToTail(data);	
			}else
			{
				Node *tmp = head;
			
				while(tmp != NULL && tmp->id != after)
				{
					tmp = tmp->next;
				}
			
				if(tmp == NULL)
				{
					cout << "After data not found" << endl;
				}else
				{
					Node *newNode = new Node();
					newNode->id = data;
				
					newNode->next = tmp->next;
					tmp->next = newNode;
				}
			}
		}
		
		 void DeleteTail()
		{
			if(head == NULL)
			{//data kosong
				cout << "Data kosong!!" << endl;
			
			}else if(head == tail)
			{//1 node
				Node *tmp = head;
				delete tmp;
				head = tail = NULL;
			
			}else
			{//lebih dari 1 node
				Node *current = head;
				Node *prev = NULL;
				Node *tmp = tail;
			
				while(current != NULL && current != tail)
				{//mencari data sebelum tail
					prev = current;
					current = current->next;
				}
				prev->next = NULL;
				tail = prev;//menjadikan prev = tail
				delete tmp;
				cout << "Deleted tail " << endl;
			}
		}
		
		void insertWEmpty(char data)
		{
			Node *node = new Node;
			node->id = data;
			node->next = NULL;
			head = tail = node;
		}
		
		void printAll()
		{
            Node *tmp = head;
            while(tmp != NULL)
			{
                cout << tmp -> id << " > ";
                tmp = tmp -> next;
            }
        }
};



int main(int argc, char **argv){
	
	
	LinkedList *list1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'A';
	
	
	list1->head = node1;
	list1->tail = node1;
	cout << list1 << endl;
	cout << list1->head->id<< endl;
	cout << list1->head << endl;
	cout << list1->tail->id << endl;
	
	Node *node2 = new Node();
	node2->id = 'B';
	list1->tail->next = node2;
	list1->tail = node2;
	cout << list1->tail->id << endl;
	
//	insert to head
	Node *node3 = new Node();
	node3->id = 'C';
	
	Node *tmp = list1->head;
	list1->head = node3;
	list1->tail = node3;
	list1->head->next = NULL;
	
	cout << list1->head->id<<endl;
	cout << list1->tail->id<<endl;
	cout << list1->tail->next<<endl;
	
//	insert to head using function
	list1->insertToHead('F');
	cout << list1->head->id<<endl;
		cout << list1->tail->id<<endl;
	
//	insert to tail
	list1->insertToTail('P');
	cout << list1->tail->id<<endl;
	
//	insert data after
	list1->insertDataAfter('z', 'C');
	list1->printAll();
	cout << endl;
	
//	delete tail
	list1->DeleteTail();
	list1->printAll(); cout << endl;
	cout <<	list1->tail->id << endl;
	
//	insert when empty
	list1->insertWEmpty('A');
	list1->printAll(); cout << endl;
	cout <<	list1->head->id << endl;
	cout <<	list1->tail->id << endl;
	
	return 0;
}
