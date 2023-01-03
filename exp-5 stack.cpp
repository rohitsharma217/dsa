#include <iostream>
using namespace std;

class Stack_Node {
public:
  int data;
  Stack_Node *next;
};

class StackNew {
private:
  Stack_Node *top;
  int size;

public:
  int isempty();
  int pop();
  void push(int element);
  int GetTop();
  void display();
  StackNew() {
    top = NULL;
    size = 0;
  }
};

int StackNew::isempty() {
  if (top == NULL)
    return 1;
  else
    return 0;
}

int StackNew::GetTop() {
  if (!isempty())
    return (top->data);
}

void StackNew::push(int value) {
  Stack_Node *NewNode;
  NewNode = new Stack_Node;
  NewNode->data = value;
  NewNode->next = top;
  top = NewNode;
}

int StackNew::pop() {
  int data;
  Stack_Node *temp = top;
  data = temp->data;
  if (isempty()) {
    cout << "Stack Underflow" << endl;
  } else {
    top = top->next;
    delete (temp);
    return data;
  }
}

void StackNew::display() {
  Stack_Node *temp;
  if (top == NULL) {
    cout << "\nStack Underflow" << endl;
  } else {
    temp = top;
    cout << "\nDisplaying Stack...\n" << endl;
    while (temp != NULL) {
      cout << temp->data;
      temp = temp->next;
      if (temp != NULL) {
        cout << "->";
      }
    }
    cout << endl;
  }
}

int main() {
  int ch;
  StackNew S;
  int element;
  int choice;
  do {
    cout << "\n1.Push\n2.Pop\n3.Get Top\n4.Display\n5.Exit" << endl;
    cout << "\nEnter your choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
      do {
        cout << "\nEnter Element: ";
        cin >> element;
        S.push(element);
        cout << "\n\nDo you want to continue(1/0): ";
        cin >> choice;
      } while (choice !=0);
      break;
    case 2:
      cout << "\nPoped Element: " << S.pop() << endl;
      break;
    case 3:
      cout << "\nTop Element: " << S.GetTop() << endl;
      break;
    case 4:
      S.display();
      break;
    case 5:
      break;
    default:
      cout << "Invalid Choice..." << endl;
    }
  } while (ch != 5);
  return 0;
}