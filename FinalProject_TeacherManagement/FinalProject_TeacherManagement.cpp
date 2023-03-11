#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    // Assume UNIX/Linux/MacOS
    system("clear");
#endif
}

class Teacher {
private:
    string id;
    string name;
    string sex;
    string phoneNumber;
    string address;
    string dateOfEmployed;
    string dateOfBirth;
    float salary;
    string teachingSubject;
    string password;

public:
    Teacher(string id, string name, string sex, string phoneNumber, string address, string dateOfEmployed, string dateOfBirth, float salary, string teachingSubject, string password)
        : id(id), name(name), sex(sex), phoneNumber(phoneNumber), address(address), dateOfEmployed(dateOfEmployed), dateOfBirth(dateOfBirth), salary(salary), teachingSubject(teachingSubject), password(password) {}

    virtual void viewInfo() {
        cout << "ID: " << id << "\t";
        cout << "Name: " << name << "\t";
        cout << "Sex: " << sex << "\t";
        cout << "Phone: " << phoneNumber << "\t";
        cout << "Address: " << address << "\t";
        cout << "DOE: " << dateOfEmployed << "\t";
        cout << "DOB: " << dateOfBirth << "\t";
        cout << "Salary: " << salary << "\t";
        cout << "Subject: " << teachingSubject << endl;
    }

    void changePassword() {
        string tempPass;
        cout << "Old password: ";
        cin >> tempPass;
        if (tempPass == password) {
            cout << "New password: ";
            cin >> password;
        }
        else {
            cout << "Incorrect password!";
        }
    }

    string getId() {
        return id;
    }
    void setId(string newId) {
        id = newId;
    }
    string getName() {
        return name;
    }
    void setName(string newName) {
        name = newName;
    }
    string getSex() {
        return sex;
    }
    void setSex(string newSex) {
        sex = newSex;
    }
    string getPhoneNumber() {
        return phoneNumber;
    }
    void setPhoneNumber(string newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
    string getAddress() {
        return address;
    }
    void setAddress(string newAddress) {
        address = newAddress;
    }
    string getDateOfEmployed() {
        return dateOfEmployed;
    }
    void setDateOfEmployed(string newDateOfEmployed) {
        dateOfEmployed = newDateOfEmployed;
    }
    string getDateOfBirth() {
        return dateOfBirth;
    }
    void setDateOfBirth(string newDateOfBirth) {
        dateOfBirth = newDateOfBirth;
    }
    float getSalary() {
        return salary;
    }
    void setSalary(float newSalary) {
        salary = newSalary;
    }
    string getTeachingSubject() {
        return teachingSubject;
    }
    void setTeachingSubject(string newTeachingSubject) {
        teachingSubject = newTeachingSubject;
    }
    string getPassword() {
        return password;
    }
    void setPassword(string newPassword) {
        password = newPassword;
    }
};

class FulltimeTeacher : public Teacher {
public:
    string manageClass;
    float bonusPercent;

    FulltimeTeacher(string id, string name, string sex, string phoneNumber, string address, string dateOfEmployed, string dateOfBirth, float salary, string teachingSubject, string password, string manageClass, float bonusPercent)
        : Teacher(id, name, sex, phoneNumber, address, dateOfEmployed, dateOfBirth, salary, teachingSubject, password), manageClass(manageClass), bonusPercent(bonusPercent) {}

    void viewInfo() override {
        Teacher::viewInfo();
        cout << "Manage Class: " << manageClass << "'t";
        cout << "Bonus: " << bonusPercent << "%" << endl;
    }
};

class PartimeTeacher : public Teacher {
public:
    string teachingClass;
    float teachingHours;
    string substituteTeacher;
    string shift;

    PartimeTeacher(string id, string name, string sex, string phoneNumber, string address, string dateOfEmployed, string dateOfBirth, float salary, string teachingSubject, string password, string teachingClass, float teachingHours, string substituteTeacher, string shift)
        : Teacher(id, name, sex, phoneNumber, address, dateOfEmployed, dateOfBirth, salary, teachingSubject, password), teachingClass(teachingClass), teachingHours(teachingHours), substituteTeacher(substituteTeacher), shift(shift) {}

    void viewInfo() override {
        Teacher::viewInfo();
        cout << "Class: " << teachingClass << "\t";
        cout << "Hours: " << teachingHours << "\t";
        cout << "Substitute: " << substituteTeacher << "\t";
        cout << "Shift: " << shift << endl;
    }
};

class TeacherManagementSystem {
private:
    vector<Teacher*> teachers;

public:
    vector<Teacher*> getTeachers() {
        return teachers;
    }
    void createTeachers() {
        clearScreen();
        char userChoice;
        while (1) {
            cout << "Which teacher you want to create?\n\t[1] Part time teacher\n\t[2] Full time teacher\n\t[0] Cancel\n\nYour Choice: ";
            cin >> userChoice;
            cout << endl << endl;
            if (userChoice == '1') {
                createPartimeTeacher();
            }
            else if (userChoice == '2') {
                createFulltimeTeacher();
            }
            else if (userChoice == '0') {
                break;
            }
        }
    }
    void createFulltimeTeacher() {
        string id, name, sex, phoneNumber, address, dateOfEmployed, dateOfBirth, teachingSubject, password;
        float salary;
        cout << "Enter teacher ID: ";
        cin >> id;
        cout << "Enter teacher name: ";
        cin >> name;
        cout << "Enter teacher sex: ";
        cin >> sex;
        cout << "Enter teacher phone number: ";
        cin >> phoneNumber;
        cout << "Enter teacher address: ";
        cin >> address;
        cout << "Enter dateof employed: ";
        cin >> dateOfEmployed;
        cout << "Enter date of birth: ";
        cin >> dateOfBirth;
        cout << "Enter teacher salary: ";
        cin >> salary;
        cout << "Enter teaching subject: ";
        cin >> teachingSubject;
        string manageClass;
        float bonusPercent;
        cout << "Enter manage class: ";
        cin >> manageClass;
        cout << "Enter bonus percent: ";
        cin >> bonusPercent;
        cout << "\nEnter password for that teacher: ";
        cin >> password;

        FulltimeTeacher* newTeacher = new FulltimeTeacher(id, name, sex, phoneNumber, address, dateOfEmployed, dateOfBirth, salary, teachingSubject, password, manageClass, bonusPercent);
        teachers.push_back(newTeacher);
        cout << "Full-time teacher created successfully!\n\n" << endl;
    }

    void createPartimeTeacher() {
        string id, name, sex, phoneNumber, address, dateOfEmployed, dateOfBirth, teachingSubject, password;
        float salary;
        cout << "Enter teacher ID: ";
        cin >> id;
        cout << "Enter teacher name: ";
        cin >> name;
        cout << "Enter teacher sex: ";
        cin >> sex;
        cout << "Enter teacher phone number: ";
        cin >> phoneNumber;
        cout << "Enter teacher address: ";
        cin >> address;
        cout << "Enter dateof employed: ";
        cin >> dateOfEmployed;
        cout << "Enter date of birth: ";
        cin >> dateOfBirth;
        cout << "Enter teacher salary: ";
        cin >> salary;
        cout << "Enter teaching subject: ";
        cin >> teachingSubject;
        // cout << "Enter teacher type (1: Full-time, 2: Part-time): ";

        string teachingClass, substituteTeacher, shift;
        float teachingHours;
        cout << "Enter teaching class: ";
        cin >> teachingClass;
        cout << "Enter teaching hours: ";
        cin >> teachingHours;
        cout << "Enter substitute teacher: ";
        cin >> substituteTeacher;
        cout << "Enter shift: ";
        cin >> shift;
        cout << "\nEnter password for that teacher: ";
        cin >> password;

        PartimeTeacher* newTeacher = new PartimeTeacher(id, name, sex, phoneNumber, address, dateOfEmployed, dateOfBirth, salary, teachingSubject, password, teachingClass, teachingHours, substituteTeacher, shift);
        teachers.push_back(newTeacher);
        cout << "Part-time teacher created successfully!\n\n" << endl;
    }

    void deleteTeacher() {
        clearScreen();
        string id;
        cout << "Enter teacher ID to delete: ";
        cin >> id;
        for (int i = 0; i < teachers.size(); i++) {
            if (teachers[i]->getId() == id) {
                int choiceChoosed;
                teachers[i]->viewInfo();
                cout << "Are you sure?\n1. Yes\n2. No\nchoice: ";
                cin >> choiceChoosed;
                if (choiceChoosed == 1) {
                    delete teachers[i];
                    teachers.erase(teachers.begin() + i);
                    cout << "Teacher deleted successfully!" << endl;
                }
                else {
                    cout << "Cancled delete teacher!" << endl;
                }
                return;
            }
        }
        cout << "Teacher not found!" << endl;
    }

    void searchTeacher() {
        clearScreen();
        string id;
        cout << "Enter teacher ID to search: ";
        cin >> id;
        for (int i = 0; i < teachers.size(); i++) {
            if (teachers[i]->getId() == id) {
                teachers[i]->viewInfo();
                return;
            }
        }
        cout << "Teacher not found!" << endl;
    }

    void editTeacher() {
        clearScreen();
        string id;
        cout << "Enter teacher ID to edit: ";
        cin >> id;
        for (int i = 0; i < teachers.size(); i++) {
            if (teachers[i]->getId() == id) {
                teachers[i]->viewInfo();
                int field;
                cout << "Enter field to edit (1: Name, 2: Sex, 3: Phone Number, 4: Address, 5: Date of Employed, 6: Date of Birth, 7: Salary, 8: Teaching Subject): ";
                cin >> field;
                if (field == 1) {
                    string name;
                    cout << "Enter new name: ";
                    cin >> name;
                    teachers[i]->setName(name);
                    break;
                }
                else if (field == 2) {
                    string sex;
                    cout << "Enter new sex: ";
                    cin >> sex;
                    teachers[i]->setSex(sex);
                    break;
                }
                else if (field == 3) {
                    string phoneNumber;
                    cout << "Enter new phone number: ";
                    cin >> phoneNumber;
                    teachers[i]->setPhoneNumber(phoneNumber);
                    break;
                }
                else if (field == 4) {
                    string address;
                    cout << "Enter new address: ";
                    cin >> address;
                    teachers[i]->setAddress(address);
                    break;
                }
                else if (field == 5) {
                    string dateOfEmployed;
                    cout << "Enter new date of employed: ";
                    cin >> dateOfEmployed;
                    teachers[i]->setDateOfEmployed(dateOfEmployed);
                    break;
                }
                else if (field == 6) {
                    string dateOfBirth;
                    cout << "Enter new date of birth: ";
                    cin >> dateOfBirth;
                    teachers[i]->setDateOfBirth(dateOfBirth);
                    break;
                }
                else if (field == 7) {
                    float salary;
                    cout << "Enter new salary: ";
                    cin >> salary;
                    teachers[i]->setSalary(salary);
                    break;
                }
                else if (field == 8) {
                    string teachingSubject;
                    cout << "Enter new teaching subject: ";
                    cin >> teachingSubject;
                    teachers[i]->setTeachingSubject(teachingSubject);
                    break;
                }
                else {
                    cout << "Invalid field!" << endl;
                    return;
                }
                cout << "Teacher information updated successfully!" << endl;
                return;
            }
        }
        cout << "Teacher not found!" << endl;
    }
    void showAllTeacher() {
        clearScreen();
        if (teachers.size() <= 0) {
            cout << "There is no teacher yet!\n\n\n\n";
        }
        else {
            for (int i = 0; i < teachers.size(); i++) {
                clearScreen();
                cout << "\n==================================================\n";
                teachers[i]->viewInfo();
                cout << "\n==================================================\n\n\n\n";
            }
        }
    }
};

class AuthenticationManager {
public:
    tuple<int, int> login(vector<Teacher*> teachers) {
        string username, password;
        cout << "\n>> Authentication\n[!] Please sign in to use this software\n\tUsername: ";
        cin >> username;
        cout << "\tPassword: ";
        cin >> password;
        if (username == "heng" && password == "1234") {
            cout << "Login successful!" << endl << endl;
            return make_tuple(1, 0);
        }
        else {
            for (int i = 0; i < teachers.size(); i++) {
                if (teachers[i]->getId() == username) {
                    if (teachers[i]->getId() == username) {
                        cout << "Login successful!" << endl << endl;
                        return make_tuple(2, i);
                    }
                }
            }
            clearScreen();
            cout << "[!] Invalid username or password. Please try again.\n" << endl;
            return make_tuple(0, 0);;
        }
    }
    void loginAsAdmin(vector<Teacher*> teachers) {
        clearScreen();
        char choiceChar;
        TeacherManagementSystem tManageSystem;
        AuthenticationManager authh;
        while (1) {
            cout << ">> Welcome, Admin\n";
            cout << "Here what you can do:"
                << "\n\t[1] -> Create Teachers"
                << "\n\t[2] -> Edit Teachers"
                << "\n\t[3] -> Delete Teachers"
                << "\n\t[4] -> Search Teachers"
                << "\n\t[5] -> Show All Teachers"
                << "\n\t[6] -> Sign out(change account)"
                << "\n\t[0] -> Quit this system\n";
            cout << "\n[!] note: choose an action above and type a single number then click Enter.\n\tYour choice: ";
            cin >> choiceChar;
            if (choiceChar == '0') {
                exit(0);
            } else if (choiceChar == '1') {
                tManageSystem.createTeachers();
            }
            else if (choiceChar == '2') {
                tManageSystem.editTeacher();
            }
            else if (choiceChar == '3') {
                tManageSystem.deleteTeacher();
            }
            else if (choiceChar == '4') {
                tManageSystem.searchTeacher();
            }
            else if (choiceChar == '5') {
                tManageSystem.showAllTeacher();
            }
            else if (choiceChar == '6') {
                clearScreen();
                cout << "signed out!\n";
                break;
            }
        }
    }
    void loginAsTeacher(Teacher* teacher) {
        clearScreen();
        char choiceChar;
        TeacherManagementSystem tManageSystem;
        AuthenticationManager authh;
        while (1) {
            cout << ">> Welcome, Teacher\n";
            cout << "Here what you can do:"
                << "\n\t[1] -> view your info"
                << "\n\t[2] -> Sign out(change account)"
                << "\n\t[0] -> Quit this system\n";
            cout << "\n[!] note: choose an action above and type a single number then click Enter.\n\tYour choice: ";
            cin >> choiceChar;
            if (choiceChar == '0') {
                exit(0);
            }
            else if (choiceChar == '1') {
                teacher->viewInfo();
            }
            else if (choiceChar == '2') {
                clearScreen();
                cout << "signed out!\n";
                break;
            }
        }
    }
};

int main() {
    TeacherManagementSystem teacherSystem;
    AuthenticationManager auth;
    while (1) {
        tuple<int, int> loginNumber = auth.login(teacherSystem.getTeachers());
        if (get<0>(loginNumber) == 1) {
            auth.loginAsAdmin(teacherSystem.getTeachers());
        }
        else if (get<0>(loginNumber) == 2) {
            vector<Teacher*> tempTeachers = teacherSystem.getTeachers();
            auth.loginAsTeacher(tempTeachers[get<1>(loginNumber)]);
        }
    }
    return 0;
}
