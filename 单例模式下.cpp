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
    Student(string id,string name,string age,string sex,string address,string contact,string dormitory){
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
    void print_id_toreturn(){
        cout<<"学号(0 to return):";
    }
    void print_unavalid(){
        cout<<"重复的学号：";
    }
    void print_failedinsert(){
        cout<<"重复的学号，插入失败！\n";
    }
    void print_eraseid(){
        cout<<"输入要删除的学号：";
    }
    void print_feraseid(){
        cout<<"没有招到该学号学生，删除失败！\n";
    }
    void print_erasename(){
        cout<<"输入要删除的姓名：";
    }
    void print_ferasename(){
        cout<<"没有招到该姓名学号学生，删除失败！\n";
    }
    void print_modifyid(){
        cout<<"输入要修改学生的学号：";
    }
    void print_fmodifyid(){
        cout<<"没有招到该学号学生，修改失败！\n";
    }
    void print_modifyname(){
        cout<<"输入要修改学生的姓名：";
    }
    void print_fmodifyname(){
        cout<<"没有招到该姓名学生，修改失败！\n";
    }
    void print_line(){
        cout<<"--------------------------------\n";
    }
    void print_qselect(){
        cout<<"1、按学号查询\n2、按姓名查询\n0、返      回\n";
    }
    void print_default(){
        cout<<"错误操作。\n";
    }
    void print_total(){
        cout<<"学生总人数：";
    }
    void print_boys(){
        cout<<"男生总人数：";
    }
    void print_girls(){
        cout<<"女生总人数：";
    }
    void print_qerase(){
        cout<<"1、按学号删除\n2、按姓名删除\n0、返      回\n";
    }
    void print_cerase(){
        cout<<"操作成功！\n";
    }
    void print_qmodify(){
        cout << "1、按学号修改\n2、按姓名修改\n0、返回\n";
    }
    void print_menu(){
        system("cls");
        cout << "\t****************************\n";
        cout << "\t*   学生基本信息管理系统   *\n";
        cout << "\t*==========================*\n";
        cout << "\t*    1、录入学生信息       *\n";
        cout << "\t*    2、显示学生信息       *\n";
        cout << "\t*    3、查询学生信息       *\n";
        cout << "\t*    4、添加学生信息       *\n";
        cout << "\t*    5、统计学生信息       *\n";
        cout << "\t*    6、删除学生信息       *\n";
        cout << "\t*    7、修改学生信息       *\n";
        cout << "\t*    0、退出管理系统       *\n";
        cout << "\t****************************\n";
        cout << "\n\t请选择:";
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
    string readstring(){
        string str;
        while(cin.get()!='\n');
        cin>>str;
        return str;
    }

};
class Controlor{
private:
    string str;
    View view;
    Model model;
public:
    void failedinsert(){
        view.print_failedinsert();
    }
    Student *read_data(int m){
        Student *tmp = new Student();
//        cout<<"        1"<<&tmp<<endl;
        if(m!=1) {view.print_id();model.read_id(tmp);}
        if(m!=2) {view.print_name();model.read_name(tmp);}
        view.print_age();model.read_age(tmp);
        view.print_sex();model.read_sex(tmp);
        view.print_address();model.read_address(tmp);
        view.print_contact();model.read_contact(tmp);
        view.print_dormitory();model.read_dormitory(tmp);
//        cout<<"        2"<<&tmp<<endl;
        return tmp;
    }
    void entering_front(Student *&tmp){
        view.print_id_toreturn();
        model.read_id(tmp);
    }
    void entering_middle(Student *&tmp){
        view.print_name();model.read_name(tmp);
        view.print_age();model.read_age(tmp);
        view.print_sex();model.read_sex(tmp);
        view.print_address();model.read_address(tmp);
        view.print_contact();model.read_contact(tmp);
        view.print_dormitory();model.read_dormitory(tmp);
    }
    void entering_tail(Student *&tmp){
        view.print_unavalid();
        cout<<tmp->re_id()<<endl;
    }
    string eraseid(){
        string str;
        view.print_eraseid();
        str=model.readstring();
        return str;
    }
    void feraseid(){
        view.print_feraseid();
    }
    string erasename(){
        string str;
        view.print_erasename();
        str=model.readstring();
        return str;
    }
    void ferasename(){
        view.print_ferasename();
    }
    string modifyid(){
        string str;
        view.print_modifyid();
        str=model.readstring();
        return str;
    }
    void fmodifyid(){
        view.print_fmodifyid();
    }
    string modifyname(){
        string str;
        view.print_modifyname();
        str=model.readstring();
        return str;
    }
    void fmodifyname(){
        view.print_fmodifyname();
    }
    void printline(){
        view.print_line();
    }
    void systempause(){
        system("pause");
    }
    int qselect(){
        int str;
        view.print_qselect();
        str=atoi((model.readstring()).c_str());
        return str;
    }
    string qid(){
        string str;
        view.print_id();
        str=model.readstring();
        return str;
    }
    string qname(){
        string str;
        view.print_name();
        str=model.readstring();
        return str;
    }
    int qerase(){
    	int str;
        view.print_qerase();
        str=atoi((model.readstring()).c_str());
        return str;
	}
    void qdefault(){
        view.print_default();
    }
    void ptotal(){
        view.print_total();
    }
    void pboys(){
        view.print_boys();
    }
    void pgirls(){
        view.print_girls();
    }
    void cerase(){
        view.print_cerase();
    }
    int qmodify(){
        int str;
        view.print_qmodify();
        str=atoi((model.readstring()).c_str());
        return str;
    }
    int choice(){
        int c;
        do{
            view.print_menu();
            c=atoi((model.readstring()).c_str());
        }while(c<0||c>7);
        return c;
    }
};

class CStudent{
private:
    vector<Student *> students;
    Controlor conrol;
    static CStudent* instance;
public:
    static CStudent* GetCStudent(){
        return instance;
    }
    static CStudent* Destroy(){
        delete instance;
        instance=NULL;
    }
    CStudent(){
    	students.shrink_to_fit();
    }
    ~CStudent(){
        students.clear();
    }
    bool insert_student(Student *&tmp){
        if(find_id(tmp->re_id())){
            conrol.failedinsert();
            return false;
        }else{
            students.push_back(tmp);
            return true;
        }
    }
    void add_student(int m){
    	Student *tmp;
    	tmp = conrol.read_data(m);
        students.push_back(tmp);
    }
    bool find_id(string id){
    	int k=students.size();
		for(int i=0;i<k;i++){
			if((*students[i]).re_id()==id) {
				return 1;
			}
		}
        return 0;
    }
    bool find_name(string name){
        int k=students.size();
        for(int i=0;i<k;i++){
            if((*students[i]).re_name()==name){
                return 1;
            }
        }
        return 0;
    }
    bool find_sex(string sex){
        int k=students.size();
        for(int i=0;i<k;i++){
            if((*students[i]).re_sex()==sex){
                return 1;
            }
        }
        return 0;
    }
    bool find_dormitory(string dormitory){
        int k=students.size();
        for(int i=0;i<k;i++){
            if((*students[i]).re_dormitory()==dormitory){
                return 1;
            }
        }
        return 0;
    }
    int boys(){
        int cnt=0;
        int k=students.size();
        for(int i=0;i<k;i++){
            if((*students[i]).re_sex()=="男") ++cnt;
        }
        return cnt;
    }
    int girls(){
        int cnt=0;
        int k=students.size();
        for(int i=0;i<k;i++){
            if((*students[i]).re_sex()=="女") ++cnt;
        }
        return cnt;
    }
    int numcount(){
        return students.size();
    }
    void entering(){
        while(1){
        	Student *tmp=new Student();
        	conrol.entering_front(tmp);
        	if((tmp->re_id())=="0") break;
            if(find_id(tmp->re_id())==0){
                conrol.entering_middle(tmp);
                insert_student(tmp);
            }
            else{
                conrol.entering_tail(tmp);
            }
        }
    }
    bool eraseid(){
        string id;
        id=conrol.eraseid();
		for(vector<Student *>::iterator b= students.begin();b!=students.end();++b){
			if((*b)->re_id()==id) {
				students.erase(b);
				return true;
			}
		}
        conrol.feraseid();
        return false;
    }
    bool erasename(){
        string name;
        name = conrol.erasename();
        for(vector<Student *>::iterator b= students.begin();b!=students.end();++b){
			if((*b)->re_name()==name) {
				students.erase(b);
				return true;
			}
		}
        conrol.ferasename();
        return false;
    }
    bool modifyid(){
        string id;
        id=conrol.modifyid();
        for(vector<Student *>::iterator b= students.begin();b!=students.end();++b){
			if((*b)->re_id()==id) {
				(*b)=conrol.read_data(1);
				return true;
			}
		}
		conrol.fmodifyid();
		return false;
    }
    bool modifyname(){
        string name;
        name=conrol.modifyname();
        for(vector<Student *>::iterator b= students.begin();b!=students.end();++b){
			if((*b)->re_id()==name) {
				(*b)=conrol.read_data(2);
				return true;
			}
		}
		conrol.fmodifyname();
		return false;
    }
    void show(Student *&tmp){
            cout<<tmp->re_id()<<" "<<tmp->re_name()<<" ";
            cout<<tmp->re_age()<<" "<<tmp->re_sex()<<" ";
            cout<<tmp->re_address()<<" "<<tmp->re_contact()<<" ";
            cout<<tmp->re_dormitory();
    }
    void showall(){
        int k=students.size();
        conrol.printline();
        for(int i=0;i<k;i++){
            show((students[i]));
        }
        conrol.printline();
        conrol.systempause();
    }
    void query(){
        int select,k;
        string id;
        select=conrol.qselect();
        switch(select){
            case 1:id=conrol.qid();
            	k=students.size();
                for(int i=0;i<k;i++){
                    if((*students[i]).re_id()==id){
                        show((students[i]));
                        break;
                    }
                }
                break;
            case 2:id=conrol.qname();
                k=students.size();
                for(int i=0;i<k;i++){
                    if((*students[i]).re_name()==id){
                        show((students[i]));
                        break;
                    }
                }
                break;
            case 0: return;
            default:conrol.qdefault();
        }
        conrol.systempause();
    }
    void qerase(){
        int select;
        select=conrol.qerase();
        switch(select){
            case 1:
                if(eraseid())
                    conrol.cerase();
                else
                    conrol.qdefault();
                break;
            case 2:
                if(erasename())
                    conrol.cerase();
                else
                    conrol.qdefault();
                break;
            case 0: return;
            default:conrol.qdefault();
        }
        conrol.systempause();
    }
    void modify() {
        int select;
        select=conrol.qmodify();
        switch(select) {
            case 1:
                if(modifyid())
                    conrol.cerase();
                break;
            case 2:
                if(modifyname())
                    conrol.cerase();
                break;
            case 0: return;
            default : conrol.qdefault();
        }
        conrol.systempause();
    }
    void statistic(){
        conrol.ptotal();cout<<numcount()<<endl;
        conrol.pboys();cout<<boys()<<endl;
        conrol.pgirls();cout<<girls()<<endl;
        conrol.systempause();
    }
//    void center(){
//        int c;
//        do{
//            c=conrol.choice();
//            switch(c){
//                case 1 : entering(); break;
//                case 2 : showall(); break;
//                case 3 : query(); break;
//                case 4 : entering(); break;
//                case 5 : statistic(); break;
//                case 6 : qerase(); break;
//                case 7 : modify(); break;
//                case 0 : break;
//                default:conrol.qdefault();break;
//            }
//        }while(c);
//    }
};
CStudent* CStudent::instance = new CStudent();

class housekeeper{
private:
	CStudent* c_student=CStudent::GetCStudent();
public:
	void entering(){
		c_student->entering();
	}
	void showall(){
		c_student->showall();
	}
	void query(){
		c_student->query();
	}
    void statistic(){
    	c_student->statistic();
	}
    void qerase(){
    	c_student->qerase();
	}
    void modify(){
    	c_student->modify();
	}
};
class facade{
private:
	housekeeper* h=new housekeeper();
public:
	void entering(){
		h->entering();
	}
	void showall(){
		h->showall();
	}
	void query(){
		h->query();
	}
    void statistic(){
    	h->statistic();
	}
    void qerase(){
    	h->qerase();
	}
    void modify(){
    	h->modify();
	}
};

//client 
int main(){
//	CStuden* c_student=CStudent::GetCStudent();
//    c_student.center();
    facade* f = new facade();
    f->entering();
    f->statistic();
}








