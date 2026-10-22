/*
Avani Lakhotia

This program is made using mainly sturctures and pointers.

 */
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct student{
  char first_name[50];
  char last_name[50];
  int student_id;
  float gpa;
};

void add_student (vector<student*>  &students);
void print_student (vector<student*> &students);
void del_student (vector<student*> &students);


int main(){
  vector <student*> students;
  string user;
  
  while (true){
    cout << " " << endl;
    cout << "Welcome! Choose what you want to do:\n"
      <<"1] ADD\n"
      <<"2] PRINT\n"
      <<"3] DELETE\n"
      <<"4] QUIT\n" << endl;

    cin >> user;
    
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

void add_student (vector<student*> &students){
  student* new_stu = new student();
  
  cout << "Enter your first name: " << endl;
  cin >> new_stu->first_name;  
  cout << "Enter your last name: " << endl;
  cin >> new_stu->last_name;
  cout << "Enter your student id: " << endl;
  cin >> new_stu->student_id;
  cout << "Enter your GPA: " << endl;
  cin >> new_stu->gpa;
  cout << "added student" <<endl;
  cout << " " << endl;
  // cout << stu1.first_name << " " << stu1.last_name << " " << stu1.student_id << "\n";

  students.push_back(new_stu);
  

}

void print_student (vector<student*> &students){
  for (int i = 0; i < students.size(); i++){
    cout << students[i] -> first_name<< " "
	 << students[i] -> last_name << ","
	 << students[i] -> student_id << ","
	 << fixed << setprecision(2) << students[i] -> gpa
	 << endl;}
  if (students.empty()){
    cout << "No one is added into the directory right now. Add people first! " << endl;
    return;
  }

  


}
void del_student (vector<student*> &students){
  int id;
  bool found_it = false;
  cout << "enter the id of the student you want to delete" << endl;
  cin >> id;
  for (int i = 0; i <students.size(); i++){
    if (id == students[i] -> student_id){
      delete students [i];
      students.erase(students.begin() + i);
      found_it = true;
      break;}
  }
  if (found_it == false){
    cout << "that id doesn't exists, please try again"<<endl;}
  

}
