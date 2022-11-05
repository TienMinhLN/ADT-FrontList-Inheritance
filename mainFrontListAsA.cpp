/** Implementation file for the class FrontListAsA.
@File: mainFrontListAsA.cpp
*@Author: Tien Nguyen
*StarID: op8466gn
*@Due Date: Nov. 4, 2022
*Instructor: Jie Meichsner */

#include "FrontListAsA.cpp"
#include "FrontListAsA.h"
#include "LinkedList.cpp"
#include "LinkedList.h"
#include "Node.cpp"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include <iostream>
#include <string>
using namespace std;

void copyConstructorTester() {
  FrontListAsA<string> list;
  string items[] = {"zero", "one", "two", "three", "four", "five"};
  for (int i = 0; i < 6; i++) {
    cout << "Adding " << items[i] << endl;
    list.insertFront(items[i]);
  }
  // copy of the list
  
  FrontListAsA<string> copyList(list);
  cout << "\nThe copy list is " << endl;
  for (int i = 0; i < 6; i++) {
    list.insertFront(items[i]);
    cout << list.retrieve() << endl;
    list.removeFront();
  } // end for

} // end copyConstructorTester

void FrontListTester(FrontListAsA<string> *listPtr) {

  string name[] = {"Luke", "Brent", "Donna", "Tom", "Sue", "Jerry"};
  for (int i = 0; i < 6; i++) {
    cout << "Adding " << name[i] << endl;
    listPtr->insertFront(name[i]);
  }
  // display the list
  cout << "\nList should contain\nLuke, Brent, "
       << "Donna, Tom, Sue, Cherry" << endl;
  cout << "\nList actually contains:" << endl;
  for (int i = 0; i < 6; i++) {
    cout << listPtr->retrieve() << endl;
    listPtr->removeFront();
  } // end for
  cout << endl;
  cout << "Test insert front and retrieve:" << endl;
  cout << "Insert item named Student. The list should contain Student" << endl;
  listPtr->insertFront("Student");
  cout << "\nList actually contains: " << listPtr->retrieve() << endl;
  cout << "\nTest remove front: " << endl;
  cout << "Removing the front item; it should be " << listPtr->removeFront() << " (true)" << endl;
  
  cout << "\nclear: " << endl;
  listPtr->clear();
  try {
    cout << "Attempt an illegal retrieval from front position: " << endl;
    listPtr->retrieve();
  } catch (PrecondViolatedExcep e) {
    cout << e.what() << endl;
  } // end try/catch

  cout << endl;

}; 

int main() {
  copyConstructorTester();
  cout << "======================================" << endl;
  FrontListAsA<string> *listPtr = new FrontListAsA<string>();
  cout << "\nTesting the Link-Based List:" << endl;
  FrontListTester(listPtr);

  return 0;
} // end main
