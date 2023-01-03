#include <iostream>
using namespace std;
struct node {
  int data;
  node *next;
  node *prev;
};
class double_LL {
private:
  node *head = NULL;

public:
  void insert_at_beg();
  void insert_at_pos(int pos);
  void insert_at_end();
  void delete_at_beg();
  void delete_at_pos(int pos);
  void delete_at_end();
  void display();
};
void double_LL::insert_at_beg() {
  int no;
  cout << "Enter the data: ";
  cin >> no;
  struct node *newnode = new node;
  newnode->data = no;
  if (head == NULL) {
    head = newnode;
    newnode->next = NULL;
    newnode->prev = NULL;
  } else {
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
  }
}
void double_LL::insert_at_end() {
  int no;
  cout << "Enter the data: ";
  cin >> no;
  struct node *newnode = new node;
  newnode->data = no;
  if (head == NULL) {
    head = newnode;
    newnode->next = NULL;
    newnode->prev = NULL;
  } else {
    struct node *temp;
    temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;
    newnode->next = NULL;
  }
}
void double_LL::delete_at_beg() {
  if (head == NULL) {
    cout << "LL is empty";
  } else {
    struct node *p = head;
    head = p->next;
    head->prev = NULL;
    delete (p);
  }
}
void double_LL::delete_at_end() {
  if (head == NULL) {
    cout << "LL is empty";
  } else {
    struct node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->prev->next = NULL;
    delete (temp);
  }
}
void double_LL::display() {
  struct node *temp = head;
  while (temp != 0) {
    cout << temp->data;
    temp = temp->next;
  }
}
/*void double_LL::insert_at_pos(int pos) {

  cout << "Enter the data: ";
  cin >> no;
  struct node *newnode = new node, *temp;
  newnode->data = no;
  while (temp->data)
}*/
int main() {
  double_LL DLL;
  int choice;
  do {
    cout << "\n\n1.Insert_Begin\n2.Insert_end\n3.Delete_beg\n4.Delete_end\n5."
            "Display\n6.Exit\n";
    cin >> choice;
    switch (choice) {
    case 1:
      DLL.insert_at_beg();
      break;
    case 2:
      DLL.insert_at_end();
      break;
    case 3:
      DLL.delete_at_beg();
      break;
    case 4:
      DLL.delete_at_end();
      break;
    case 5:
      DLL.display();
      break;
    case 6:
      exit(0);
    }
  } while (1);
  return 0;
}