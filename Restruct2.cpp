#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include<stdlib.h>

using namespace std;

class Student{
private:
    string m_id;
    string m_name;
    string m_age;
    string m_sex;
    string m_address;
    string m_contact;
    string m_dormitory;
public:
	Student(){
	}
    Student(int id,string name,int age,string sex,string address,string contact,string dormitory){
        this->m_id=id;
        this->m_name=name;
        this->m_age=age;
        this->m_sex=sex;
        this->m_address=address;
        this->m_contact=contact;
        this->m_dormitory=dormitory;
    }
    void e_id(string id){
        this->m_id=id;
    }
    void e_name(string name){
        this->m_name=name;
    }
    void e_age(string age){
        this->m_age=age;
    }
    void e_sex(string sex){
        this->m_sex=sex;
    }
    void e_address(string address){
        this->m_address=address;
    }
    void e_contact(string contact){
        this->m_contact=contact;
    }
    void e_dormitory(string dormitory){
        this->m_dormitory=dormitory;
    }
    string re_id(){
        return this->m_id;
    }
    string re_name(){
        return this->m_name;
    }
    string re_age(){
        return this->m_age;
    }
    string re_sex(){
        return this->m_sex;
    }
    string re_address(){
        return this->m_address;
    }
    string re_contact(){
        return this->m_contact;
    }
    string re_dormitory(){
        return this->m_dormitory;
    }
};

class View{
private:
public:
    void print_id(){
        cout<<"学    号：";
    }
    void print_name(){
        cout<<"姓    名：";
    }
    void print_age(){
        cout<<"年    龄：";
    }
    void print_sex(){
        cout<<"性    别：";
    }
    void print_address(){
        cout<<"住    址：";
    }
    void print_contact(){
        cout<<"联系方式：";
    }
    void print_dormitory(){
        cout<<"寝    室：";
    }
};
class Model{
private:
public:
    void read_id(Student *&tmp){
    	string str;
        cin>>str;
        tmp->e_id(str);
    }
    void read_name(Student *&tmp){
    	string str;
        cin>>str;
        tmp->e_name(str);
    }
    void read_age(Student *&tmp){
    	string str;
        cin>>str;
        tmp->e_age(str);
    }
    void read_sex(Student *&tmp){
    	string str;
        cin>>str;
        tmp->e_sex(str);
    }
    void read_address(Student *&tmp){
    	string str;
        cin>>str;
        tmp->e_address(str);
    }
    void read_contact(Student *&tmp){
    	string str;
        cin>>str;
        tmp->e_contact(str);
    }
    void read_dormitory(Student *&tmp){
    	string str;
        cin>>str;
        tmp->e_dormitory(str);
    }
};
class Controlor{
private:
    string str;
    View view;
    Model model;
public:
    string readstring(){
        while(cin.get()!='\n');
        cin>>this->str;
        return str;
    }
    Student *read_data(int m){
        Student *tmp = new Student();
//        cout<<"        1"<<&tmp<<endl;
        if(m!=1) {view.print_id();model.read_id(tmp);}
        if(m!=2) {view.print_name();model.read_name(tmp);}
        view.print_age();model.read_age(tmp);
        view.print_address();model.read_address(tmp);
        view.print_contact();model.read_contact(tmp);
        view.print_dormitory();model.read_dormitory(tmp);
//        cout<<"        2"<<&tmp<<endl;

        return tmp;
    }
};
class CStudent{
private:
    vector<Student *> students;
    Controlor conrol;
public:
    CStudent(){
    	students.shrink_to_fit();
    }
    ~CStudent(){
        students.clear();
    }
    void add_student(int m){
    	Student *tmp;
    	tmp = conrol.read_data(m);
//    	cout<<tmp->re_id()<<endl;
//    	cout<<&tmp<<endl;
        students.push_back(tmp);
    }
    bool find_id(string id){
    	int k=students.size();
		for(int i=0;i<k;i++){
//			string f = (*students[i]).re_id();
			if((*students[i]).re_id()==id) {
//				cout<<"-"<<(*students[i]).re_id()<<endl;
				return 1;
			}
//			cout<<students.size()<<"-"<<(*students[0]).re_id()<<endl;
//			cout<<students.size()<<"-"<<(*students[1]).re_id()<<endl;
		}
        return 0;
    }
};

int main(){
	CStudent c_student;
	c_student.add_student(2);
	c_student.add_student(2);
//	c_student.find_id("123");
	cout<<c_student.find_id("123")<<endl;
}








