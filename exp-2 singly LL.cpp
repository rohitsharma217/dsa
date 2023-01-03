#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};
class singlylinkedlist {
  Node *head;

public:
  singlylinkedlist() { 
    head = NULL;
    }
  void insert(int new_data);
  void insertatend(int v);
  void insertatbeg(int v);
  void insertatpos(int v, int pos);
  void insertaftervalue(int v, int aftervalue);
  void deletevalue(int v);

  void diplayvalue();
};
void singlylinkedlist::insert(int v)
 {
   Node *nn = new Node;
  nn->data = v;
  nn->next = NULL;
  if (head == NULL)
    head = nn;
  else {
    Node *t = head;
    while (t->next != NULL) {
      t = t->next;
    }
    t->next = nn;
  }     
}
void singlylinkedlist::insertatend(int v) {
  Node *nn = new Node;
  nn->data = v;
  nn->next = NULL;
  if (head == NULL)
    head = nn;
  else {
    Node *t = head;
    while (t->next != NULL) {
      t = t->next;
    }
    t->next = nn;
  }
}
void singlylinkedlist::insertatbeg(int v) {
  Node *nn = new Node;
  nn->data = v;
  if (head == NULL) {
    head = nn;
    nn->next = NULL;
  } else {
    nn->next = head;
    head = nn;
  }
  
}
void singlylinkedlist::insertatpos(int v, int pos) {
  int p=pos;
  Node *t = head;
  Node *nn = new Node;
  Node *sn ;
  nn->data = v;
  while(t->data!= p)
    {
      t=t->next;
  }
  sn=t->next;
  t->next=nn;
  nn->next=sn;
}
void singlylinkedlist::insertaftervalue(int v, int aftervalue) {
  Node *t = head;
  Node *nn = new Node;
  nn->data = v;
  nn->next = NULL;
  while (t->data != aftervalue) {
    t = t->next;
  }
  nn->next = t->next;
  t->next = nn;
}

void singlylinkedlist::deletevalue(int v) {
  Node *t = head;
  Node *temp=head->next;
  Node *sn;
  while (temp->data != v) {
    temp=temp->next;
    t = t->next;
  }
  sn=temp->next;
  t->next=sn;
  delete(temp);
}
void singlylinkedlist::diplayvalue() {
  Node *p = head;
  while (p != NULL) {
    cout << p->data;
    p = p->next;
  }
}

int main() {
  singlylinkedlist s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);
  int ch;
  do{
        cout << "\n\n1.Insert_end\n2.Insert_Beg\n3.insert\n4.insert after 4.\n5.Delete\n6."
            "Display\n7.Exit\n";
    cin>>ch;
    
    switch(ch)
      {
        case 1:
          int n;
          cout<<"Enter the value you want to insert"<<endl;
          cin>>n;
          s.insertatend(n);
          break;
        case 2:
           int x;
          cout<<"Enter the value you want to insert"<<endl;
          cin>>x;
            s.insertatbeg(x);
          break; 
        case 3:
           int y,t;
          cout<<"Enter the value you want to insert"<<endl;
          cin>>y;
          cin>>t;
            s.insertatpos(y, t);
          break; 
        case 4:
           int z;
          cout<<"Enter the value you want to insert"<<endl;
          cin>>z;
            s.insertaftervalue(z,4);
          break; 
       case 5:
          int a;
          cout<<"Enter the value you want to delete"<<endl;
         cin>>a;
            s.deletevalue(a);
          break; 
      case 6:
            s.diplayvalue();
          break; 
        case 7:
        exit(0);
        break;
    }
    }while(1);
  return 0;
  }

