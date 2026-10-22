/*
Avani Lakhotia
10/21/2026
This program is made using mainly sturctures and pointers. It asks the students for 4 options: adding, printing, deleting or quiting the game. Each one then does its designated roles to make this game!

 */


#include <iostream>
#include <vector>
#include <string>
#include <iomanip> //to make the decimals 2 digit

using namespace std;

//struct that stores in all the info
struct student{
  char first_name[50];
  char last_name[50];
  int student_id;
  float gpa;
};

// function prototypes and i make the refrence pointers so it can be used throught the program 
void add_student (vector<student*>  &students);
void print_student (vector<student*> &students);
void del_student (vector<student*> &students);

//main
int main(){
  vector <student*> students; //creating vector and poitner
  string user;
  //while loop asking all the options
  while (true){
    cout << " " << endl;
    cout << "Welcome! Choose what you want to do:\n"
      <<"1] ADD\n"
      <<"2] PRINT\n"
      <<"3] DELETE\n"
      <<"4] QUIT\n" << endl;

    cin >> user;
    // depending on the answer it calls the function
    
    if (user == "ADD" || user ==  "1"){
      add_student(students);}
    
    else if (user == "PRINT" || user == "2"){
    print_student (students);}
    
    else if (user == "DELETE" || user == "3"){
      del_student (students);}
    
    else if (user == "QUIT"|| user == "4" ){
      cout << "thanks for playing!" << endl;
      break;}
    
    else {
    cout << "enter a valid response" << endl;} 

  }
    
  return 0;
  
}

//adding function: asks for first, last, id and gpa and adds that entry to our vector
void add_student (vector<student*> &students){
  student* new_stu = new student(); //making dynamic poitner to store 
  
  cout << "Enter your first name: " << endl; 
  cin >> new_stu->first_name;  //this way it stores it into the pointer
  cout << "Enter your last name: " << endl;
  cin >> new_stu->last_name;
  cout << "Enter your student id: " << endl;
  cin >> new_stu->student_id;
  cout << "Enter your GPA: " << endl;
  cin >> new_stu->gpa;
  cout << "added student" <<endl;
  cout << " " << endl;

  students.push_back(new_stu); // adds new student into the vector
  

}

//print function: prints all the entries, if there are none it lets the user know
void print_student (vector<student*> &students){
    if (students.empty()){
    cout << "No one is added into the directory right now. Add people first! " << endl\
;
    return;
  } // if there are no entries it lets the user know      

    for (int i = 0; i < students.size(); i++){ //loops throuhg all the entries and prints them out 
    cout << students[i] -> first_name<< " "
	 << students[i] -> last_name << ","
	 << students[i] -> student_id << ","
	 << fixed << setprecision(2) << students[i] -> gpa
	 << endl;}
 
}

//delete function: asks for id, if the id exists it deletes the entry from memory and erases it from the vector, if not then it lets the user know this id isn't valid

void del_student (vector<student*> &students){
  int id;
  bool found_it = false;
// this is created so that later if there is no id then i can let hte user know that the id wasn't found
  cout << "enter the id of the student you want to delete" << endl;
  cin >> id;
  for (int i = 0; i <students.size(); i++){ //loops through all the data again to check for id
    if (id == students[i] -> student_id){
      delete students [i]; //deletes the student from the memory
      students.erase(students.begin() + i); //removes poitner from vector
      found_it = true;
      break;}
  }
  if (found_it == false){
    cout << "that id doesn't exists, please try again"<<endl;} // if id doesn't exist then it lets the user know
  

}
