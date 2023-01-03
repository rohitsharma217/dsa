#include <iostream>
using namespace std;

struct emp {
  int id;
  int key;
};
class HT {
  int size;
  emp table[10];

public:
  HT() { // default constructor to set the -1 value at empty space
    for (int i = 0; i < 10; i++) {
      table[i].key = -1;
      table[i].id = -1;
    }
  }
  int hashFunction(int key) // use to find index value for that key
  {
    return (key % 10);
  }
  void insert() // insert function use to search the value in hash table
  {
    int id = 0;
    cout << "Enter the employee ID:" << id << endl;
    cin >> id;
    int index;
    index = hashFunction(id); // use function to put the value in index
    int c;
    c = index;
    while (table[index].key != -1) {
      index = (index + 1) % 10;
    }

    table[index].id = id;
    table[index].key = c;
  }
  void displayHT() {
    cout << "id"
         << "  "
         << "key" << endl;
    for (int i = 0; i < 10; i++) {
      cout << table[i].id << "  " << table[i].key << endl;
    }
  }
  void delete_HT() {//delete function use to delete id value
    long int id;
    cout << "Enter the employee ID you want to delete:" << endl;
    cin >> id;
    int index;
    index = hashFunction(id);
    int c;
    c = index;
    for (int i = 0; i < 10; i++) {
      if (table[i].id == id) {
        table[i].key = -1;
        table[i].id = 0;
        cout << "id of " << i << " is deleted" << endl;
      }
    }
  }
  void search() {//search function that linearly search
    long int id;
    cout << "Enter the employee ID:" << endl;
    cin >> id;
    for (int i = 0; i < 10; i++) {
      if (table[i].id == id) {
        cout << "id found at index" << i;
      }
    }
  }
};

int main() {
  HT obj1;//Object is created
  int ch;
  cout << "Choose what you would like to do:" << endl;
  cout << "\n1.insert\n2.delete\n3.search\n4.display\n5.exit\n";
  do {
    cin >> ch;
    switch (ch) {

    case 1:
      cout << "1.Insert Data:" << endl;
      obj1.insert();
      cout << "Single insertion done.." << endl;
      break;
    case 2:
      cout << "2.Delete Data:" << endl;
      obj1.delete_HT();
      break;
    case 3:
      cout << "3.Search Data:" << endl;
      obj1.search();
      break;
    case 4:
      cout << "4.HashTable:" << endl;
      obj1.displayHT();
      break;
    case 5:
      cout << "Exit";
      exit(0);
      break;
    }
  } while (1);
  return 0;
}
