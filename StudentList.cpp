#include <iostream>
#include <vector>
#include <cstring>

void add(vector<Student*>* stuList);
void delete(vector<Student*>* stuList);
void print(vector<Student*>* stuList);

using namespace std;

struct Student{
  char fNm[46];
  char lNm[46];
  int id;
  float gpa;
};

void add(vector<Student*>* stuList){
      cout << "Please enter the first name of the student." << endl;

      stuList.push_back(Student());
      
      while(true){
        cin.get(stuList.at(stuList.size()-1).fNm, 50);
        cin.clear();
        cin.ignore(999, '\n');

	if(stuList.at(stuList.size()-1).fNm != null){
	  break;
	}

	cout << "The student's first name is empty..." << endl;
      }

      cout << "Please enter the last name of the student" << endl;
      
      while(true){
	
        cin.get(stuList.at(stuList.size()-1).lNm, 50);
        cin.clear();
        cin.ignore(999, '\n');

	if(stuList.at(stuList.size()-1).lNm != null){
	  break;
	}

	cout << "At least put \"snow\" or something" << endl;
      }
}

void print(vector<Student*>* stuList){
  for(int a = 0; a < stuList.size(); a++){
    cout << "First Name: " << stuList.at(a).fNm << "." << "Last Name: " << stuList.at(a).lNm << "." << "ID: " << stuList.at(a).id << "." << "GPA: " << stuList.at(a).gpa << endl;  
  }
}

void delete(vector<Student*>* stuList){

}

int main(){

  char commandIn[8] = "";
  
  bool running = true;

  vector <Student*>* stuList;
  
  while(running){
  
  cout << "Please enter a command. Type \"HELP\" for help." << endl;

    while(true){
      cin.get(commandIn, 8);
      cin.clear();
      cin.ignore(999, '\n');
      
      if(strcmp(commandIn, "ADD") == 0 || strcmp(commandIn, "PRINT") || strcmp(commandIn, "DELETE") == 0 || strcmp(commandIn, "QUIT") == 0 || strcmp(commandIn, "HELP") == 0){ 
	break;
      }
      
      cout << "Please enter a valid command, and type \"HELP\" for help. :)" << endl;
      
    }

    if(strcmp(commandIn, "ADD") == 0){
      add(stuList);      
    }else if(strcmp(commandIn, "PRINT") == 0){
      print(stuList);
    }
    else if(strcmp(commandIn, "DELETE") == 0){
      delete(stuList);
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
