#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student{
  char firstName[46];
  char lastName[46];
  int id;
  float gpa;
};

int main(){

  char commandIn[8] = "";
  
  bool running = true;

  vector<Student> students;
  
  while(running){
  
  cout << "Please enter a command. Type \"HELP\" for help." << endl;

    while(true){
      cin.get(commandIn, 8);
      cin.clear();
      cin.ignore(999, '\n');
      
      if(strcmp(commandIn, "ADD") == 0 || strcmp(commandIn, "DELETE") == 0 || strcmp(commandIn, "QUIT") == 0 || strcmp(commandIn, "HELP") == 0){ 
	break;
      }
      
      cout << "Please enter a valid command, and type \"HELP\" for help. :)" << endl;
      
    }

    if(strcmp(commandIn, "ADD") == 0){
      
      cout << "Please enter the first name of the student." << endl;

      char fName[50];

      while(true){
        cin.get(fName, 50);
        cin.clear();
        cin.ignore(999, '\n');

	if(fName != null){
	  break;
	}

	cout << "The student's first name is empty..." << endl;
      }

      char lName[50];

      while(true){
        cin.get(lName, 50);
        cin.clear();
        cin.ignore(999, '\n');

	if(lName != null){
	  break;
	}

	cout << "At least put \"snow\" or something" << endl;
      }

      int

      

      
      
    }
    else if(strcmp(commandIn, "DELETE") == 0){

    }
    else if(strcmp(commandIn, "QUIT") == 0){
      cout << "Program Will Now Exit." << endl;
      running = false;
    }
    else if(strcmp(commandIn, "HELP") == 0){
      cout << "Type \"ADD\" to add a new student. Type \"DELETE\" to delete a student. Type \"QUIT\" to exit the program." << endl;
    } 
    
    
  }
}
