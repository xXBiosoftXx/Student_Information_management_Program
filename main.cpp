#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h> //clear console

using namespace std;

void view_student_information();
void add_student_information();
void edit_student_information();
void delete_student_information();
void load_data();
void upload_data();

class student
{
public:
    string first_name;
    string last_name;
    double grade;
    int student_ID;
    void get_name(){
        cout << "first_name : " << first_name << endl;
        cout << "last_name : " << last_name << endl;
    }
    void get_grade(){
        cout << "grade : " << grade << endl;
    }
    void set_name_and_grade(string fname, string lname,double new_grade,int id){
        first_name = fname;
        last_name = lname;
        grade = new_grade;
        student_ID = id;//student number in class
    }

    void edit_Full_name_and_grade(string fname,string lname,double new_grade){
        first_name = fname;
        last_name = lname;
        grade = new_grade;
    }

    void edit_full_name(string fname, string lname){
        first_name = fname;
        last_name = lname;
    }

    void edit_first_name(string fname){
        first_name = fname;
    }

    void edit_last_name(string lname){
        last_name = lname;
    }

    void edit_grade(double new_grade){
        grade = new_grade;
    }

    void edit_student_id(int id){
        student_ID = id;
    }

    student(string fname,string lname,double first_grade,int id)
    {
        first_name = fname;
        last_name = lname;
        grade = first_grade;
        student_ID = id;
    }
    student(){

    }
    void display_student(){
        cout << "======================" << endl;
        cout << "Student Number : " << student_ID << endl; 
        cout << "First Name : " << first_name << endl;
        cout << "Last Name : " << last_name << endl;
        cout << "Grade : " << grade << endl;
        cout << "======================" << endl; 
    }
    void push_information(){
        cout << student_ID << endl;
        cout << first_name << endl;
        cout << last_name << endl;
        cout << grade << endl;
    }
    void student_upload_data(){

    }
};

student new_student;
vector<student> head;
int student_number = 0;

int main()
{
    system("cls"); 
    const string username = "admin";
    const string password = "01234";
    string username_input,password_input;//username and password for user
    int user_option = 0;
    bool login_token = false;
    cout << "Welcome to Student Information Management Program" <<endl;
    do{
        cout << "=======================" << endl;
        cout << "Username : ";
        cin >> username_input;
        cout << "Password : ";
        cin >> password_input;
        if(username_input == username){
            if(password_input == password){
                login_token = true;
            }
            else{
                cout << "your Password is incorrect!" << endl;
                cout << "=======================" << endl;
            }
        }
        else{
            cout << "your Username is incorrect!" << endl;
            cout << "=======================" << endl;
        }
    }
    while(!login_token);
    cout << "=======================" << endl;
    cout << "Welcome to Student Information Management Program\n" << endl;
    system("cls"); 
    load_data();
    while(login_token){
        cout << "=======================" << endl;
        cout << "1.View student information" << endl;
        cout << "2.Add new student information" << endl;
        cout << "3.Edit student information" << endl;
        cout << "4.Delete student infotmation" << endl;
        cout << "5.Exit Program" << endl;
        cout << "Select option(1 - 5) : ";
        cin >> user_option;
        cout << "=======================" << endl;
        if(user_option > 5 || user_option < 0){
            cout << "Some thing wrong, Please try again " << endl;
            cout << "=======================" << endl;
            continue;
        }
        else{
            switch (user_option)
            {
            case 1:
                view_student_information();
                break;
            
            case 2:
                add_student_information();
                break;

            case 3:
                edit_student_information();
                break;

            case 4:
                delete_student_information();
                break;

            case 5:
                login_token = false;
                break;
            
            default:
                continue;
            }
        }
    }
    upload_data();
    cout << "=======================" << endl;
    cout << "thank you for use program" << endl;
    return 0;
}

void load_data(){
    ifstream infile;
    int set_student_number;
    int set_student_ID;
    string set_first_name;
    string set_last_name;
    double set_grade;
    infile.open("student_information.txt");
    infile >> set_student_number;
    if(set_student_number > 0){
        for(int i = 0 ;i < set_student_number; i++){
            infile >> set_student_ID;
            infile >> set_first_name;
            infile >> set_last_name;
            infile >> set_grade;
            new_student.set_name_and_grade(set_first_name,set_last_name,set_grade,set_student_ID);
            head.push_back(new_student);
        }
    }
    infile.close();
    student_number = set_student_number;
}

void upload_data(){
    ofstream outfile;
    outfile.open("student_information.txt");
    outfile << student_number << endl;
    for(int i = 0; i < student_number;i++){
        outfile << head[i].student_ID << endl;
        outfile << head[i].first_name << endl;
        outfile << head[i].last_name << endl;
        outfile << head[i].grade << endl;
    }
    outfile.close();
}

void view_student_information(){
    if (head.size()){
        for(int i = 0; i < student_number; i++){
        head[i].display_student();
        }
    }
    else{
        cout << "No information" << endl;
    }
}

void add_student_information(){
    string new_fname;
    string new_lname;
    double new_grade;
    cout << "=======================" << endl;
    cout << "Add student information" << endl;
    cout << "First Name : ";
    cin >> new_fname;
    cout << "Last Name : ";
    cin >> new_lname;
    cout <<"Grade : ";
    cin >> new_grade;
    student_number++;
    new_student.set_name_and_grade(new_fname,new_lname,new_grade,student_number);
    head.push_back(new_student);
    cout << "add new data successfully" << endl;
    cout << "=======================" << endl;
}

void edit_student_information(){
    string new_fname;
    string new_lname;
    double new_grade;
    int user_option;
    int student_NO;
    bool edit_token = true;
    while(edit_token){
        cout << "=======================" << endl;
        cout << "Edit student information" << endl;
        cout << "1.edit full name and grade" << endl;
        cout << "2.edit full name" << endl;
        cout << "3.edit first name" << endl;
        cout << "4.edit last name" << endl;
        cout << "5.edit grade" << endl;
        cout << "6.back to Main page" << endl;
        cout << "Select Option(1 - 6) : ";
        cin >> user_option;
        cout << "=======================" << endl;
        if(user_option < 6 && user_option > 0){
            cout << "=======================" << endl;
            cout << "Enter student number to edit : ";
            cin >> student_NO;
            cout << "=======================" << endl;
            if(student_NO <= student_number && student_NO > 0){
                cout << "current information" << endl;
                head[(student_NO-1)].display_student();
                switch (user_option)
                {
                case 1:
                    cout << "Edit full name and grade" << endl;
                    cout << "First name : ";
                    cin >> new_fname;
                    cout << "Last name : ";
                    cin >> new_lname;
                    cout << "grade : ";
                    cin >> new_grade;
                    head[(student_NO-1)].edit_Full_name_and_grade(new_fname,new_lname,new_grade);
                    edit_token = false;
                    break;
                
                case 2:
                    cout << "Edit full name" << endl;
                    cout << "First name : ";
                    cin >> new_fname;
                    cout << "Last name : ";
                    cin >> new_lname;
                    head[(student_NO-1)].edit_full_name(new_fname,new_lname);
                    edit_token = false;
                    break;

                case 3:
                    cout << "Edit first name";
                    cout << "First name : ";
                    cin >> new_fname;
                    head[(student_NO-1)].edit_first_name(new_fname);
                    edit_token = false;
                    break;

                case 4:
                    cout << "Edit last name";
                    cout << "Last name : ";
                    cin >> new_lname;
                    head[(student_NO-1)].edit_last_name(new_lname);
                    edit_token = false;
                    break;

                case 5:
                    cout << "Edit grade";
                    cout << "Grade : ";
                    cin >> new_grade;
                    head[(student_NO-1)].edit_grade(new_grade);
                    edit_token = false;
                    break;
                
                default:
                    edit_token = false;
                    break;
                }
                cout << "Editing successfully" << endl;
            }
            else if(user_option == 6){
                edit_token = false;
                break;
            }
            else{
                cout << "student number is wrong, Pleas try again." << endl;
            }
        }
        else{
            cout << "something wrong, Pleas try again" << endl;
            
        }
        cout << "=======================" << endl;
    }

}

void delete_student_information(){
    int user_option;
    int student_NO;
    bool delete_token = true;
    do{
        cout << "=======================" << endl;
        cout << "Delete student information" << endl;
        cout << "1.delete all information" << endl;
        cout << "2.delete specific information" << endl;
        cout << "3.back to main page" << endl;
        cout << "Select Option(1 - 3) : ";
        cin >> user_option;
        cout << "=======================" << endl;
        if (user_option < 4 && user_option > 0){
            switch (user_option)
            {
            case 1:
                head.clear();
                student_number = 0;
                break;

            case 2:
                cout << "=======================" << endl;
                cout << "Enter student number to delete : ";
                cin >> student_NO;
                cout << "=======================" << endl;
                if(student_NO == student_number){
                    head.pop_back();
                    student_number--;
                }
                else if(student_NO < student_number && student_NO > 0){
                    head.erase(head.begin()+(student_NO-1));
                    for(int i = student_NO; i < student_number ; i++){
                        head[(i-1)].edit_student_id(i);
                    }
                    student_number--;
                }
                else{
                    cout << "Student number wrong,Pleas try again" << endl;
                }
                break;
            case 3:
                delete_token = false;
                break;
            default:
                break;
            }
        }
        else{
            cout << "something wrong, Pleas try again" << endl;
        }
    }while(delete_token);
}