#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student{
  char fNm[46];
  char lNm[46];
  char id[8];
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
    bool noSpace = true;
    
    cin.get(stuList->at(stuList->size()-1)->fNm, 50);
    cin.clear();
    cin.ignore(999, '\n');

    if(strlen(stuList->at(stuList->size()-1)->fNm) != 0){
      for(int a = 0; a < strlen(stuList->at(stuList->size()-1)->fNm); a++){
	if(stuList->at(stuList->size()-1)->fNm[a] == ' '){
	  noSpace = false;
	}
      }
      if(noSpace){
	noSpace = true;
	break;
      }
    }

    cout << "The student's first name is empty..." << endl;
  }

  cout << "Please enter the last name of the student" << endl;
      
  while(true){
    bool noSpace = true;
    
    cin.get(stuList->at(stuList->size()-1)->lNm, 50);
    cin.clear();
    cin.ignore(999, '\n');

    if(strlen(stuList->at(stuList->size()-1)->lNm) != 0){
      for(int a = 0; a < strlen(stuList->at(stuList->size()-1)->lNm); a++){
	if(stuList->at(stuList->size()-1)->lNm[a] == ' '){
	  noSpace = false;
	}
      }
      if(noSpace){
	break;
      }
    }

    cout << "At least put \"Joe\" or something" << endl;
  }

  cout << "Please enter the ID of the student" << endl;

  while(true){

    bool sixlen = false;
    bool alldigit = true;
    char in[8] = "";
    cin.get(in, 8);
    cin.clear();
    cin.ignore(999, '\n');

    for(int a = 0; a < strlen(in); a++){
      if(!isdigit(in[a])){
	alldigit = false;
      }
    }
    
    if(alldigit && strlen(in) == 6){
      /* Dropped this since an input of 000001 would just result in 1, might conve
      for(int a = 0; a < strlen(in); a++){
	numIn += (in[a]-48);
	numIn *= 10;
      }
      numIn/=10;
      */
      strcpy(stuList->at(stuList ->size()-1)->id, in);  
      break;
    }
    cout << "Please enter a six digit number" << endl;
  }

  cout << "Please enter the GPA of the student" << endl;

  while(true){
    float gpaNum = 0;
    float gpaNumL = 0;
    char gpaIn[34];
    int decInd = 0;
    bool allDig = true;
    bool onePeriod = false;
    cin.get(gpaIn, 34);
    cin.clear();
    cin.ignore(999, '\n');
    for(int a = 0; a < strlen(gpaIn); a++){
      if(gpaIn[a]=='.' && onePeriod == false){
	onePeriod = true;
	if(gpaIn[a+1]==0){
	  allDig = false;
	  break;
	}
      }else if(!isdigit(gpaIn[a])){
	allDig = false;
	break;
      }
    }
    if(allDig){
      for(int a = 0; a < strlen(gpaIn); a++){
	if(gpaIn[a]!='.'){
	  gpaNum += (gpaIn[a]-48);
	  gpaNum *= 10;
	}else{
	  gpaNum /= 10;
	  decInd = a;
	  break;
	}
      }
      for(int a = strlen(gpaIn)-1; a > decInd; a--){
	gpaNumL += (gpaIn[a]-48);
	gpaNumL /= 10;
      }
      stuList->at(stuList ->size()-1)->gpa = (int)((gpaNum+gpaNumL+.005)*100)/100.0;
      break;
    }
    cout << "That GPA does not exist..." << endl;
  }
}

void getRid(vector<Student*>* stuList){
  
}

void print(vector<Student*>* stuList){
  for(int a = 0; a < stuList->size(); a++){
    cout << "First Name: " << stuList->at(a)->fNm << " " << "Last Name: " << stuList->at(a)->lNm << " " << "ID: " << stuList->at(a)->id << " " << "GPA: " << stuList->at(a)->gpa << endl;  
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
      
      if(strcmp(commandIn, "ADD") == 0 || strcmp(commandIn, "PRINT") == 0 || strcmp(commandIn, "DELETE") == 0 || strcmp(commandIn, "QUIT") == 0 || strcmp(commandIn, "HELP") == 0){ 
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
