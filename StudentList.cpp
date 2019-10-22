#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>

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
      /* dropped this since an input of 000001 would just result in 1, might conve
      for(int a = 0; a < strlen(in); a++){
	numin += (in[a]-48);
	numin *= 10;
      }
      numin/=10;
      */
      strcpy(stulist->at(stulist ->size()-1)->id, in);  
      break;
    }
    cout << "please enter a six digit number" << endl;
  }

  cout << "please enter the gpa of the student" << endl;

  while(true){
    float gpanum = 0;
    float gpanuml = 0;
    char gpain[34];
    int decind = 0;
    bool alldig = true;
    bool oneperiod = false;
    cin.get(gpain, 34);
    cin.clear();
    cin.ignore(999, '\n');
    for(int a = 0; a < strlen(gpain); a++){
      if(gpain[a]=='.' && oneperiod == false){
	oneperiod = true;
	if(gpain[a+1]==0){
	  alldig = false;
	  break;
	}
      }else if(!isdigit(gpain[a])){
	alldig = false;
	break;
      }
    }
    if(alldig){
      for(int a = 0; a < strlen(gpain); a++){
	if(gpain[a]!='.'){
	  gpanum += (gpain[a]-48);
	  gpanum *= 10;
	}else{
	  gpanum /= 10;
	  decind = a;
	  break;
	}
      }
      for(int a = strlen(gpain)-1; a > decind; a--){
	gpanuml += (gpain[a]-48);
	gpanuml /= 10;
      }
      stulist->at(stulist ->size()-1)->gpa = gpanum+gpanuml;
      break;
    }
    cout << "that gpa does not exist..." << endl;
  }
}

void getrid(vector<student*>* stulist){
  cout << "please enter the id of the student" << endl;

  while(true){

    bool exists = false;
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

      vector<student*>::iterator stulistiterator;

      for(stulistiterator=stulist->begin(); stulistiterator!=stulist->end(); ++stulistiterator){
	if(strcmp((*stulistiterator)->id, in) == 0){
	  delete *stulistiterator;
	  stulist->erase(stulistiterator);
	  return;
	}
      }

      cout << "that id does not exist. please enter something else..." << endl;
    }
    cout << "please enter a six digit number" << endl;
  }
}

void print(vector<student*>* stulist){
  vector<student*>::iterator stulistiterator;

  for(stulistiterator=stulist->begin(); stulistiterator!=stulist->end(); ++stulistiterator){
    cout << (*stulistiterator)->fnm << ", " << (*stulistiterator)->lnm << ", " << (*stulistiterator)->id << ", " << (*stulistiterator)->gpa << endl;
  }

  if(stulist->begin() == stulist->end()){
    cout << "no students found!" << endl;
  }
}

void quit(bool &running){
  cout << "program will now exit." << endl;
  running = false;
}



int main(){

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  char commandin[8] = "";
  
  bool running = true;

  vector<student*> stul;
  vector<student*>* stulist = &stul;
  
  while(running){
  
    cout << "Please enter a command. Type \"help\" for help." << endl;

    while(true){
      cin.get(commandin, 8);
      cin.clear();
      cin.ignore(999, '\n');

      for(int a = 0; a < strlen(commandin); a++){
	commandin[a] = toupper(commandin[a]);
      }
      
      if(strcmp(commandin, "add") == 0 || strcmp(commandin, "print") == 0 || strcmp(commandin, "delete") == 0 || strcmp(commandin, "quit") == 0 || strcmp(commandin, "help") == 0){ 
	break;
      }
      
      cout << "please enter a valid command, and type \"help\" for help. :)" << endl;
      
    }

    if(strcmp(commandin, "add") == 0){
      add(stulist);      
    }else if(strcmp(commandin, "print") == 0){
      print(stulist);
    }
    else if(strcmp(commandin, "delete") == 0){
      getrid(stulist);
    }
    else if(strcmp(commandin, "quit") == 0){
      quit(running);
    }
    else if(strcmp(commandin, "help") == 0){
      cout << "Type \"add\" to add a new student. Type \"delete\" to delete a student. type \"quit\" to exit the program.\n" << endl;
    } 
    
    
  }
}
