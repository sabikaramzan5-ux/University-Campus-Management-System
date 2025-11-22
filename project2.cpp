#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Student{
private:
    int rollno;
    float gpa;
    string cnic;
public:
    string name;
    int semester;
    string deptname;
  
    Student():rollno(0),gpa(0.0),cnic(""),name(""),semester(0),deptname("")
    {}
    Student(int r,float gpa_,string c,string nm,int sem,string dept):rollno(r),gpa(gpa_),cnic(c),name(nm),semester(sem),deptname(dept)
    {}
    void setrollno(int r){
        rollno=r;
    }  
    int getrollno(){
        return rollno;
    }
    void setgpa(float gpa_){
        gpa=gpa_;
    }
    float getgpa(){
        return gpa;
    }
    void displayStudentInfo(){
        cout<<"RollNo: "<<rollno<<" Name: "<<name<<" GPA: "<<gpa<<" CNIC: "<<cnic<<" Semester: "<<semester<<endl;
    }
};
class Faculty{
    private:
      double salary;
      string cnic;
    public:
      string name;
      string designation;
      string deptname;
      Faculty():salary(0.0),cnic(""),name(""),designation(""),deptname("")
      {}
      Faculty(double sal,string c,string nm,string des,string dname):salary(sal),cnic(c),name(nm),designation(des),deptname(dname)
      {}
      void setSalary(double sal){
        salary=sal;
      }
      double getsalary(){
        return salary;
      }
      void displayFacultyInfo(){
        cout<<"Name: "<<name<<" CNIC: "<<cnic<<" Salary: "<<salary<<" Designation: "<<designation<<" DepartmentName: "<<deptname<<endl;
      }
};
class Course{
private:
   int coursecode;
   int credithours;
public:
   string courseName;
   string instructorName;
   Course():coursecode(0),credithours(0),courseName(""),instructorName("")
   {}
   Course(int ccode,int crhours,string cname,string instname):coursecode(ccode),credithours(crhours),courseName(cname),instructorName(instname)
   {}
   void setcoursecode(int ccode){
    coursecode=ccode;
   }
   int getcoursecode(){
    return coursecode;
   }
   void setcredithours(int cr){
    credithours=cr;
   }
   int getcredithours(){
    return credithours;
   }
   void displayCourseInfo(){
   cout<<"CourseCode: "<<coursecode<<" CourseName: "<<courseName<<" CreditHours: "<<credithours<<" InstructorName: "<<instructorName<<endl;
   }
};
class Department{
    private:
    vector<Student>students;
    vector<Faculty>faculties;
    vector<Course>courses;
    public:
    string deptname;
    string hodname;
    Department():deptname(""),hodname("")
    {}
    Department(string dname,string hname):deptname(dname),hodname(hname)
    {}
    void addStudent(const Student& s){
        students.push_back(s);
    }
    void addFaculty(const Faculty& f){
        faculties.push_back(f);
    }
    void addCourse(const Course& c){
        courses.push_back(c);
    }
    Student* getStudentByRoll(int roll){
        for(auto &st: students){
            if(roll == st.getrollno())
            return &st;
        }
        return nullptr;
    }

    int getStudentsCount() const { return students.size();}
    int getFacultyCount() const { return faculties.size();}
    int getCoursesCount() const { return courses.size();}
    
    void displayDeptInfo(){
        cout<<"Department name: "<<deptname<<"  "<<"HOD name: "<<hodname<<endl;
        cout<<"Students: "<<endl;
        for(int i=0;i<students.size();i++){
            students[i].displayStudentInfo();
        }
        cout<<"Faculties: "<<endl;
        for(int i=0;i<faculties.size();i++){
             faculties[i].displayFacultyInfo();
        }
        cout<<"Courses: "<<endl;
        for(int i=0;i<courses.size();i++){
            courses[i].displayCourseInfo();
        }
    }
};
class Book{
    private:
    string bookname;
    int bookid;
    public:
    Book():bookname(""),bookid(0){}
    Book(string bname,int bid):bookname(bname),bookid(bid){}
    string getbookname(){ return bookname;}
    int getbookid(){ return bookid;};
    void displaybookinfo(){
        cout<<"BookName: "<<bookname<<"  "<<"BookId: "<<bookid<<endl;
    }
};
class Library{
    private:
    vector<Book>issuedBooks;
    public:
    string libraryname;
    Library():libraryname("") {}
    Library(string lib):libraryname(lib){}
    void issueBook(Student& s,const Book& b){
        issuedBooks.push_back(b);
        cout<<"Book issued to stuent "<<s.getrollno()<<endl;
    }
    void returnBook(Student& s,Book& b){
       
        for(auto it=issuedBooks.begin();it!=issuedBooks.end();it++){
            if(b.getbookid()==(*it).getbookid()){
            issuedBooks.erase(it);
            return;
        }
    }
        cout<<"Given book is not issued to anyone"<<endl;
}
    void displayLibraryInfo(){
        cout<<"Library Name: "<<libraryname<<endl;
        cout<<"List of issued Books: "<<endl;
        for(int i=0;i<issuedBooks.size();i++){
            issuedBooks[i].displaybookinfo();
        }
    }
};
class Hostel{
private:
  vector<Student>studentstaying;
public:
  string hostelName;
  int capacity;

  Hostel():hostelName(""),capacity(0){}
  Hostel(string hname,int c):hostelName(hname),capacity(c) {}
  void assignRoom(Student& s){
    if(studentstaying.size() >= capacity){
        cout<<"Not enough space in hostel.Cannot assign room"<<endl;
        return;
    }
    else{
        studentstaying.push_back(s);
    }
  }
  void vacateRoom(Student& s){
    for(auto it=studentstaying.begin();it!=studentstaying.end();it++){
        if(s.getrollno()==(*it).getrollno()){
        studentstaying.erase(it);
        return;
        }
        cout<<"Room is not allocated to the given student"<<endl;
    }
  }
  void displayHostelInfo(){
    cout<<"HostelName: "<<hostelName<<"  "<<"Capacity: "<<capacity<<endl;
    cout<<"Students staying in hostel: "<<endl;
    for(int i=0;i<studentstaying.size();i++){
        studentstaying[i].displayStudentInfo();
    }
  }
  int gethostelOccupancy() const { return studentstaying.size();}
};
class Campus{
private:
       vector<Department>departments;
       vector<Hostel>hostels;
       Library lib;
public:
       string campusName;
       string location;

      
       Campus(string cname,string loc):campusName(cname),location(loc){}
       void addDepartment(Department& d){
        departments.push_back(d);
       }
       void addHostel(Hostel& h){
        hostels.push_back(h);
       }
       void setLibrary(Library& l){
       lib=l;
       }
       Department& getDepartment(int index) {return departments[index];}
       Hostel& getHostel(int index) {return hostels[index];}
       Library& getLibrary() {return lib;}
       void displayCampusInfo(){
       cout<<"CampusName: "<<campusName<<"   "<<"Location: "<<location<<endl;
        for(int i=0;i<departments.size();i++){
            departments[i].displayDeptInfo();
        }
        for(int i=0;i<hostels.size();i++){
            hostels[i].displayHostelInfo();
        }
        cout<<endl;
        lib.displayLibraryInfo();
       }
       int gettotalDepartments(){ return departments.size();}
       int gettotalHostels(){ return hostels.size();}
};
class University{
    private:
    vector<Campus>campuses;
    public:
    string uniname;
    University():uniname(""){}
    University(string uname):uniname(uname){}
    void addCampus(Campus& c){
        campuses.push_back(c);
    }
    Campus& getCampus(int index){ return campuses[index];}
    int getTotalCampuses() {return campuses.size(); }
    void displayUniInfo(){
        cout<<"University Name: "<<uniname<<endl;
        cout<<"Campuses: "<<endl;
        for(int i=0;i<campuses.size();i++){
        cout<<i+1<<" ";
        campuses[i].displayCampusInfo();
        }
    }
};
   void showMenu(){
    cout << "\n--------- University Menu --------" << endl;
    cout << "1 - Add Student" << endl;
    cout << "2 - Add Faculty" << endl;
    cout << "3 - Add Course" << endl;
    cout << "4 - Assign Hostel Room" << endl;
    cout << "5 - Issue Book from Library" << endl;
    cout << "6 - View Department details" << endl;
    cout << "7 - View Campus details" << endl;
    cout << "8 - View University details" << endl;
    cout << "9 - Exit" << endl;
    cout << "Enter choice: ";
}
int main(){
    University u1("Punjab University");
    Campus c1("Quaid-e-Azam campus","Old lahore");
    Campus c2("New campus","New Lahore");
    
    Department d1("Software Engineering","Waqar ul Qonain");
    d1.addStudent(Student(513,3.9,"1234","Sabika",3,"Software Engineering"));
    d1.addStudent(Student(514,3.6,"2341","Maham",3,"Software Engineering"));
    d1.addStudent(Student(515,3.5,"4567","Abdullah",3,"Software Engineering"));
    d1.addFaculty(Faculty(50000,"111","Ahmad","Professor","SE"));
    d1.addFaculty(Faculty(20000,"112","Ali Muhammad","Professor","SE"));
    d1.addCourse(Course(101,3,"OOP","Sir Mubashar"));
    Department d2("Computer Science","Essa Abdullah");
    Hostel h1("Ayesha hall",500);
    Library l1("Main library");
    c1.addDepartment(d1);
    c1.addDepartment(d2);
    c1.addHostel(h1);
    c1.setLibrary(l1);
    Department d3("Chemical Engineering","Sabika");
    Department d4("Data Science","Umer");
    Hostel h2("Ruqia hall",500);
    Library l2("New library");
    c2.addDepartment(d3);
    c2.addDepartment(d4);
    c2.addHostel(h2);
    c2.setLibrary(l2);
    u1.addCampus(c1);
    u1.addCampus(c2);
    int choice=0;
    while(true){
        showMenu();
       
        cin>>choice;
        if(choice==9){
            break;
        }
    
    switch (choice){
    case 1: { 
        int campusChoice, deptChoice;
        int roll; float gpa; string cnic; string nm; int sem; string deptName;
        cout << "Enter student's rollNo gpa cnic name semester departmentName (space separated):\n";
        cin >> roll >> gpa >> cnic >> nm >> sem >> deptName;
        Student s(roll,gpa,cnic,nm,sem,deptName);

        for(int i=0; i<u1.getTotalCampuses(); i++){
        cout << i+1 << " - " << u1.getCampus(i).campusName << endl;
        }
        cout << "Choose campus number: ";
        cin >> campusChoice;
        if (campusChoice < 1 || campusChoice > u1.getTotalCampuses()){
            cout << "Invalid campus choice\n";
            break;
            }
        Campus &sel = u1.getCampus(campusChoice-1);
        if (sel.gettotalDepartments() == 0){
            cout << "No departments in selected campus\n";
            break;
        }
        cout << "Departments:\n";
        for (size_t i=0;i<sel.gettotalDepartments();++i){
           cout << (i+1) << "-" << sel.getDepartment(i).deptname << endl;
                }
                cout << "Choose department number: ";
                cin >> deptChoice;
                if (deptChoice < 1 || deptChoice > sel.gettotalDepartments()){
                    cout << "Invalid dept choice\n";
                    break;
                }
                Department &deptRef = sel.getDepartment(deptChoice-1);
                deptRef.addStudent(s);
                cout << "Student added successfully to " << deptRef.deptname << " in " << sel.campusName << endl;
                break;
            }

        case 2: { 
                int campusChoice, deptChoice;
                double sal; string cnic; string nm; string des; string deptName;
                cout << "Enter faculty salary cnic name designation departmentName (space separated):\n";
                cin >> sal >> cnic >> nm >> des >> deptName;
                Faculty f(sal, cnic, nm, des, deptName);

                for(int i=0; i<u1.getTotalCampuses(); i++){
                cout << i+1 << " - " << u1.getCampus(i).campusName << endl;
                }
                cout << "Choose campus number: ";
                cin >> campusChoice;
                if (campusChoice < 1 || campusChoice > u1.getTotalCampuses()){
                    cout << "Invalid campus choice\n";
                    break;
                }
                Campus &sel = u1.getCampus(campusChoice-1);

                if (sel.gettotalDepartments() == 0){
                    cout << "No departments in selected campus\n";
                    break;
                }
                cout << "Departments:\n";
                for (size_t i=0;i<sel.gettotalDepartments();++i){
                    cout << (i+1) << "-" << sel.getDepartment(i).deptname << endl;
                }
                cout << "Choose department number: ";
                cin >> deptChoice;
                if (deptChoice < 1 || deptChoice > sel.gettotalDepartments()){
                    cout << "Invalid dept choice\n";
                    break;
                }
                Department &deptRef = sel.getDepartment(deptChoice-1);
                deptRef.addFaculty(f);
                cout << "Faculty added successfully to " << deptRef.deptname << " in " << sel.campusName << endl;
                break;
            }

            case 3: { 
                int campusChoice, deptChoice;
                int ccode, chours; string cname, instname;
                cout << "Enter courseCode creditHours courseName instructorName (space separated):\n";
                cin >> ccode >> chours >> cname >> instname;
                Course c(ccode, chours, cname, instname);

                for(int i=0; i<u1.getTotalCampuses(); i++){
                cout << i+1 << " - " << u1.getCampus(i).campusName << endl;
                }
                cout << "Choose campus number: ";
                cin >> campusChoice;
                if (campusChoice < 1 || campusChoice > u1.getTotalCampuses()){
                    cout << "Invalid campus choice\n";
                    break;
                }
                Campus &sel = u1.getCampus(campusChoice-1);

                if (sel.gettotalDepartments() == 0){
                    cout << "No departments in selected campus\n";
                    break;
                }
                cout << "Departments:\n";
                for (size_t i=0;i<sel.gettotalDepartments();++i){
                    cout << (i+1) << "-" << sel.getDepartment(i).deptname << endl;
                }
                cout << "Choose department number: ";
                cin >> deptChoice;
                if (deptChoice < 1 || deptChoice > (int)sel.gettotalDepartments()){
                    cout << "Invalid dept choice\n";
                    break;
                }
                Department &deptRef = sel.getDepartment(deptChoice-1);
                deptRef.addCourse(c);
                cout << "Course added successfully to " << deptRef.deptname << " in " << sel.campusName << endl;
                break;
            }

            case 4: { 
                int campusChoice, hostelChoice;
                int targetRoll;
                cout << "Enter roll number of student to assign room: ";
                cin >> targetRoll;

               for(int i=0; i<u1.getTotalCampuses(); i++){
               cout << i+1 << " - " << u1.getCampus(i).campusName << endl;
               }
                cout << "Choose campus number: ";
                cin >> campusChoice;
                if (campusChoice < 1 || campusChoice > u1.getTotalCampuses()){
                    cout << "Invalid campus choice\n";
                    break;
                }
                Campus &sel = u1.getCampus(campusChoice-1);

                if (sel.gettotalHostels() == 0){
                    cout << "No hostels in selected campus\n";
                    break;
                }
                cout << "Hostels:\n";
                for (size_t i=0;i<sel.gettotalHostels();++i){
                    cout << (i+1) << "-" << sel.getHostel(i).hostelName << endl;
                }
                cout << "Choose hostel number: ";
                cin >> hostelChoice;
                if (hostelChoice < 1 || hostelChoice > (int)sel.gettotalHostels()){
                    cout << "Invalid hostel choice\n";
                    break;
                }
                
                Student* found = nullptr;
                for (size_t d = 0; d < sel.gettotalDepartments(); ++d){
                    Student* sPtr = sel.getDepartment(d).getStudentByRoll(targetRoll);
                    if (sPtr != nullptr) { found = sPtr; break; }
                }
                if (!found){
                    cout << "Student with roll " << targetRoll << " not found in this campus departments\n";
                    break;
                }
                Hostel &hst = sel.getHostel(hostelChoice-1);
                hst.assignRoom(*found);
                break;
            }

            case 5: { 
                int campusChoice;
                int roll;
                int bookid;
                string bookname;
                cout << "Enter student roll (who will be issued book): ";
                cin >> roll;
                for(int i=0; i<u1.getTotalCampuses(); i++){
                cout << i+1 << " - " << u1.getCampus(i).campusName << endl;
                }
                cout << "Choose campus number: ";
                cin >> campusChoice;
                if (campusChoice < 1 || campusChoice > (int)u1.getTotalCampuses()){
                    cout << "Invalid campus choice\n";
                    break;
                }
                Campus &sel = u1.getCampus(campusChoice-1);

                
                Student* found = nullptr;
                for (size_t d = 0; d < sel.gettotalDepartments(); ++d){
                    Student* sPtr = sel.getDepartment(d).getStudentByRoll(roll);
                    if (sPtr != nullptr){ found = sPtr; break; }
                }
                if (!found){
                    cout << "Student not found in selected campus departments\n";
                    break;
                }

                cout << "Enter book id and book name (space separated): ";
                cin >> bookid >> bookname;
                Book bk(bookname, bookid);
                sel.getLibrary().issueBook(*found, bk);
                break;
            }

            case 6: { 
                int campusChoice, deptChoice;
                for(int i=0; i<u1.getTotalCampuses(); i++){
                cout << i+1 << " - " << u1.getCampus(i).campusName << endl;
                }
                cout << "Choose campus number: ";
                cin >> campusChoice;
                if (campusChoice < 1 || campusChoice > (int)u1.getTotalCampuses()){
                    cout << "Invalid campus choice\n";
                    break;
                }
                Campus &sel = u1.getCampus(campusChoice-1);
                if (sel.gettotalDepartments() == 0){
                    cout << "No departments in selected campus\n";
                    break;
                }
                cout << "Departments:\n";
                for (size_t i=0;i<sel.gettotalDepartments();++i){
                    cout << (i+1) << "-" << sel.getDepartment(i).deptname << endl;
                }
                cout << "Choose department number to view details: ";
                cin >> deptChoice;
                if (deptChoice < 1 || deptChoice > sel.gettotalDepartments()){
                    cout << "Invalid dept choice\n";
                    break;
                }
                sel.getDepartment(deptChoice-1).displayDeptInfo();
                break;
            }

            case 7: { 
               for(int i=0; i<u1.getTotalCampuses(); i++){
               cout << i+1 << " - " << u1.getCampus(i).campusName << endl;
               }
                int campusChoice;
                cout << "Choose campus number to view details: ";
                cin >> campusChoice;
                if (campusChoice < 1 || campusChoice > u1.getTotalCampuses()){
                    cout << "Invalid campus choice\n";
                    break;
                }
                u1.getCampus(campusChoice-1).displayCampusInfo();
                break;
            }

            case 8: { 
                u1.displayUniInfo();
                break;
            }

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }
        return 0; 
    }