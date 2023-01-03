#include <iostream>
using namespace std;

class QueueNode
{
  public:
    int data;
    QueueNode *next;
};
class QueueNew
{
  private:
    QueueNode *front,*rear;
  public:
    int empty();
    void insert(int);
    int Delete();
    int Getfront();
    void display();
    QueueNew()
    {
      front=rear=NULL;
    }
};

int QueueNew::empty()
{
  if (front==NULL)
    return 1;
  else
    return 0;
}

void QueueNew::insert(int value)
{
  QueueNode *Newnode;
  Newnode= new QueueNode;
  Newnode->data=value;
  Newnode->next=NULL;
  if (rear==NULL)
  {
    front=Newnode;
    rear=Newnode;
  }
  else
  {
    rear->next=Newnode;
    rear=Newnode;
  }
}

int QueueNew::Delete()
{
  int temp;
  QueueNode *current=NULL;
  if(!empty())
  {
    temp=front->data;
    current=front;
    front=front->next;
    delete current;
    return temp;
  }
}

int QueueNew::Getfront()
{
  if (!empty())
  {
    return (front->data);
  }
}

void QueueNew::display()
{
  QueueNode *temp=front;
  if (empty())
    cout<<"\nQueue is empty...\n";
  else
  {
    cout<<"\n";
    while(temp!=NULL)
      {
        cout<<temp->data<<"\t";
        temp=temp->next;
      }
    cout<<"\n";
  }
}

int main()
{
  QueueNew Q;
  int ch;
  do
    {
      cout<<"\n1.Insert\n2.Delete\n3.Get Front\n4.Display\n5.Exit"<<endl;
      cout<<"\nEnter your choice: ";
      cin>>ch;
      switch(ch)
        {
          case 1:
            char choice;
            do
              {
                int element;
                cout<<"\nEnter data: ";
                cin>>element;
                Q.insert(element);
                cout<<"\nDo you want to continue(Y/N): ";
                cin>>choice;
              }while(choice!='N');
            break;
          case 2:
            cout<<"\nDeleted element: "<<Q.Delete()<<endl;
            break;
          case 3:
            cout<<"\nFont element: "<<Q.Getfront()<<endl;
            break;
          case 4:
            Q.display();
            break;
          case 5:
            break;
          default:
            cout<<"\nInvalid Choice...."<<endl;
            break;
        }
    }while(ch!=5);
  return 0;
}