#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student{
  char fNm[46];
  char lNm[46];
  int id;
  float gpa;
};

void add(vector<Student*>* stuList);
void getRid(vector<Student*>* stuList);
void print(vector<Student*>* stuList);
void quit(bool &running);

void add(vector<Student*>* stuList){
  
  cout << "Please enter the first name of the student." << endl;

  stuList->push_back(new Student());
      
  while(true){
    cin.get(stuList->at(stuList->size()-1)->fNm, 50);
    cin.clear();
    cin.ignore(999, '\n');

    if(stuList->at(stuList->size()-1)->fNm != NULL){
      break;
    }

    cout << "The student's first name is empty..." << endl;
  }

  cout << "Please enter the last name of the student" << endl;
      
  while(true){
	
    cin.get(stuList->at(stuList->size()-1)->lNm, 50);
    cin.clear();
    cin.ignore(999, '\n');

    if(stuList->at(stuList->size()-1)->lNm != NULL){
      break;
    }

    cout << "At least put \"snow\" or something" << endl;
  }

  cout << "Please enter the ID of the student" << endl;

  while(true){

    bool sixlen = false;
    char in[8] = "";
    cin.get(in, 8);
    cin.clear();
    cin.ignore(999, '\n');

    for(int a = 0; a < strlen(in); a++){
      
    }
    
    if(stuList->at(stuList->size()-1)->lNm != NULL){
      break;
    }
    int a;
    cin >> a;
    cin.clear();
    cin.ignore(69420, '\n');
    
    cout << "Please enter a six digit number" << endl;
  }
  
}

void getRid(vector<Student*>* stuList){
  
}

void print(vector<Student*>* stuList){
  for(int a = 0; a < stuList->size(); a++){
    cout << "First Name: " << stuList->at(a)->fNm << "." << "Last Name: " << stuList->at(a)->lNm << "." << "ID: " << stuList->at(a)->id << "." << "GPA: " << stuList->at(a)->gpa << endl;  
  }
}

void quit(bool &running){
  cout << "Program Will Now Exit." << endl;
  running = false;
}



int main(){

  char commandIn[8] = "";
  
  bool running = true;

  vector<Student*> stuL;
  vector<Student*>* stuList = &stuL;
  
  while(running){
  
  cout << "Please enter a command. Type \"HELP\" for help." << endl;

    while(true){
      cin.get(commandIn, 8);
      cin.clear();
      cin.ignore(999, '\n');

      for(int a = 0; a < strlen(commandIn); a++){
	commandIn[a] = toupper(commandIn[a]);
      }
      
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
      getRid(stuList);
    }
    else if(strcmp(commandIn, "QUIT") == 0){
      quit(running);
    }
    else if(strcmp(commandIn, "HELP") == 0){
      cout << "Type \"ADD\" to add a new student. Type \"DELETE\" to delete a student. Type \"QUIT\" to exit the program." << endl;
    } 
    
    
  }
}
