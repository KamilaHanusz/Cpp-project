#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Tworker.h"
#include "Ttrainee.h"
#include "Tadministrator.h"
#include "Tprogrammer.h"
#include "Tanalyst.h"
#include "Taccountant.h"

struct Tnegative_value_exception : exception {
};
struct Ttoo_low_value_exception : exception {
};

void hire(vector<Tworker *> &vec, istream *stream);
void showthelist(vector<Tworker *> &vec);
void showthelist_info(vector<Tworker *> &vec);
void writetofile(vector<Tworker *> &vec, unsigned int i);
void dismiss(vector<Tworker *> &vec, istream *stream);
void updatefile(vector<Tworker *> &vec);
void readfromfile();
bool isEmpty(fstream &f);
void drink(vector<Tworker *> &vec, istream *stream);
void job(vector<Tworker *> &vec, istream *stream);
void sick_leave(vector<Tworker *> &vec, istream *stream);
void w_remotly(vector<Tworker *> &vec, istream *stream);
void vacation(vector<Tworker *> &vec, istream *stream);
void calculate_salary_b(vector<Tworker *> &vec, istream *stream);
void calculate_salary_n(vector<Tworker *> &vec, istream *stream);
void calculate_bonus(vector<Tworker *> &vec, istream *stream);
void compare_salary(vector<Tworker *> &vec, istream *stream);
void compare_vacation_days(vector<Tworker *> &vec, istream *stream);
void hire_trainee(vector<Tworker *> &vec, istream *stream);
void hire_administrator(vector<Tworker *> &vec, istream *stream);
void hire_programmer(vector<Tworker *> &vec, istream *stream);
void hire_analyst(vector<Tworker *> &vec, istream *stream);
void hire_accountant(vector<Tworker *> &vec, istream *stream);

int readint(istream *stream);
double readdouble(istream *stream);
string readstring(istream *stream);

template<typename T>
void calculate(T variable, int m) {
    cout << "\n|--==== Welcome to the variable calculator! ====--|\n"
            "Thanks to this tool you can calculate any variable\n"
            "(e.g. salary or vacation days) on an multiple months basis" << endl;
    T sum = m * variable;
    cout << "The value equals: " << sum;
}

template<typename T>
bool maximum(T a, T b) {
    return a > b;
}


int main(int argc, char *argv[]) {
    if (argc >= 0) {
        istream *mystream;
        ifstream stdin_file;
        stdin_file.open(argv[1]);
        mystream = &stdin_file;
        int choice;
        vector<Tworker *> hired;

        cout << "\n|---====== Welcome to Your favourite IT company! =====---|" << endl;
        do {
            cout << "\n|---====== MENU =====---|\n"
                    "Press 1 to hire a new employee\n"
                    "Press 2 to dismiss an employee\n"
                    "Press 3 to show the list of current employees and information about them\n"
                    "Press 4 to make an employee drink coffee\n"
                    "Press 5 to make an employee work\n"
                    "Press 6 to put the employee on a sick leave\n"
                    "Press 7 to make an employee work remotely\n"
                    "Press 8 to make an employee go on vacations\n"
                    "Press 9 to calculate salary brutto for multiple months\n"
                    "Press 10 to calculate salary netto for multiple months\n"
                    "Press 11 to calculate expected bonus for multiple months\n"
                    "Press 12 to check which employee gets higher salary\n"
                    "Press 13 to check which employee has more vacation days to use\n"
                    "Press 14 to exit the menu\n"
                    "Your choice: ";
            choice = readint(mystream);
            switch (choice) {
                case 1:
                    try {
                        hire(hired, mystream);
                    }
                    catch (Tnegative_value_exception &error) {
                        cout << "Invalid choice! The amount cannot be negative! Try again." << endl;
                    }
                    catch (Ttoo_low_value_exception &error) {
                        cout << "Invalid choice! The amount cannot be lower than 3000PLN! Try again." << endl;
                    }
                    cin.clear();
                    cin.sync();
                    break;
                case 2:
                    dismiss(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 3:
                    showthelist_info(hired);
                    cin.clear();
                    cin.sync();
                    break;
                case 4:
                    drink(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 5:
                    job(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 6:
                    sick_leave(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 7:
                    w_remotly(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 8:
                    vacation(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 9:
                    calculate_salary_b(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 10:
                    calculate_salary_n(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 11:
                    calculate_bonus(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 12:
                    compare_salary(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 13:
                    compare_vacation_days(hired, mystream);
                    cin.clear();
                    cin.sync();
                    break;
                case 14:
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    cin.clear();
                    cin.sync();
            }
        } while (choice != 14);

        for (auto &i: hired)
            delete i;
    }
    return 0;
}

void hire(vector<Tworker *> &vec, istream *stream) {
    int choice;
    cout << "\n|---====== ADDING A NEW EMPLOYEE =====---|\n";
    cout << "Choose a job position:\n"
            "Trainee - 1\n"
            "Administrator - 2\n"
            "Programmer - 3\n"
            "Analyst - 4\n"
            "Accountant - 5\n"
            "Your choice: " << endl;
    choice = readint(stream);
    switch (choice) {
        case 1:
            hire_trainee(vec, stream);
            break;
        case 2:
            hire_administrator(vec, stream);
            break;
        case 3:
            hire_programmer(vec, stream);
            break;
        case 4:
            hire_analyst(vec, stream);
            break;
        case 5:
            hire_accountant(vec, stream);
            break;
        default:
            cout << "Invalid choice! Try again" << endl;
            break;
    }
    cin.clear();
    cin.sync();
}

void showthelist(vector<Tworker *> &vec) {
    if (vec.empty())
        cout << "List is empty!" << endl;
    else {
        cout << "\n|---====== LIST OF CURRENT EMPLOYEES =====---|\n";
        for (int i = 0; i < vec.size(); i++) {
            cout << i + 1 << ". ";
            cout << *vec[i];
        }
    }
}

void showthelist_info(vector<Tworker *> &vec) {
    if (vec.empty())
        cout << "List is empty!" << endl;
    else {
        cout << "\n|---====== LIST OF CURRENT EMPLOYEES =====---|\n";
        for (int i = 0; i < vec.size(); i++) {
            cout << i + 1 << ". ";
            vec[i]->print_all();
        }
    }
}

void writetofile(vector<Tworker *> &vec, unsigned int i) {
    fstream file("list.txt", ios::out | ios::app);
    if (file) {
        file << *vec[i - 1] << endl;
        file.close();
    } else
        cout << "Error!";
}

void dismiss(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty()) {
        cout << "You cannot dismiss any employee because no employee is hired!" << endl;
    } else {
        int i;
        showthelist(vec);
        cout << "Enter the number of the employee that you would like to dismiss: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "It's not possible to dismiss an employee nr." << i << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            cout << "You're dismissing the employee nr." << i << endl;
            vec.erase(vec.begin() + i - 1);
            cout << "Employee dismissed successfully!" << endl;
            cout << "Now the documentation in the file will be updated." << endl;
            updatefile(vec);
            cout << "Documentation updated!" << endl;
            cout << "List of employees in the file looks this way now: " << endl;
            readfromfile();
        }
    }
}

void updatefile(vector<Tworker *> &vec) {
    fstream file("list.txt", ios::out);
    if (file)
        for (auto i: vec)
            file << *i << endl;
    else
        cout << "Error!" << endl;

    file.close();

}

void readfromfile() {
    fstream file("list.txt", ios::in);
    if (!file)
        cout << "Error!" << endl;
    else if (isEmpty(file))
        cout << "(Documentation is empty)" << endl;
    else {
        char row[10000];
        while (file.getline(row, 10000))
            cout << row << endl;
    }
    file.close();
}

bool isEmpty(fstream &f) {
    return f.peek() == ifstream::traits_type::eof();
}

void drink(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty()) {
        cout << "There is no employee that can drink coffee because no employee is hired!" << endl;
    } else {
        int i;
        showthelist(vec);
        cout << "Choose the employee who should drink coffee: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot make the person nr." << i << " drink coffee." << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            vec[i - 1]->drink_coffee();
            cout << "Given that every coffee that had been drunk may influence the employee's bonus,\n"
                    "the documentation in the file will be updated now." << endl;
            updatefile(vec);
            cout << "Documentation updated!" << endl;
            cout << "List of employees in the file looks this way now: " << endl;
            readfromfile();
        }
    }
}

void job(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There is no employee that can do their job because no employee is hired!" << endl;
    else {
        int i;
        showthelist(vec);
        cout << "Choose the employee who should do their job: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot make the person nr." << i << " do their job." << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            vec[i - 1]->do_your_job();
            cout << "Given that every job that had been done influences the employee's bonus,\n"
                    "the documentation in the file will be updated now." << endl;
            updatefile(vec);
            cout << "Documentation updated!" << endl;
            cout << "List of employees in the file looks this way now: " << endl;
            readfromfile();
        }
    }
}

void sick_leave(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There is no employee that You can put on a sick leave because no employee is hired!" << endl;
    else {
        int i;
        showthelist(vec);
        cout << "Choose the employee who has been on a sick leave: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot put the person nr." << i << " on a sick leave." << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            int d_in_m;
            int d_on_l;
            cout << "Enter the number of days in this month: ";
            d_in_m = readint(stream);
            cout << "\n";
            cout << "Enter the number of days the\nemployee has been on a sick leave this month: ";
            d_on_l = readint(stream);
            cout << "\n";
            if (d_in_m == 30 || d_in_m == 31 || d_in_m == 28 || d_in_m == 29) {
                if (d_on_l > d_in_m)
                    cout
                            << "The number of days spent on a sick leave\ncannot exceed the number of days in a month"
                            << endl;
                else {
                    vec[i - 1]->L4(d_in_m, d_on_l);
                    cout
                            << "Given that every sick leave that had been used influences the employee's salary,\n"
                               "the documentation in the file will be updated now." << endl;
                    updatefile(vec);
                    cout << "Documentation updated!" << endl;
                    cout << "List of employees in the file looks this way now: " << endl;
                    readfromfile();
                }
            } else
                cout << "Incorrect number of days in a month! Try again" << endl;
        }
    }
}

void w_remotly(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There is no employee that can work remotely because no employee is hired!" << endl;
    else {
        int i;
        showthelist(vec);
        cout << "Choose the employee who should work remotely"
                "(remember that only programmers and analysts can work remotely): ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot make the person nr." << i << " work remotely." << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else
            vec[i - 1]->work_remotely();
    }
}

void vacation(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There is no employee that can go on vacations because no employee is hired!" << endl;
    else {
        int i;
        showthelist(vec);
        cout << "Choose the employee who should go on vacations"
                "(remember that trainees cannot go on vacations): ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot make the person nr." << i << " go on vacations." << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            vec[i - 1]->vacation_leave();
            cout
                    << "Given that every holiday leave that had been taken influences the employee's remaining vacation days,\n"
                       "the documentation in the file will be updated now." << endl;
            updatefile(vec);
            cout << "Documentation updated!" << endl;
            cout << "List of employees in the file looks this way now: " << endl;
            readfromfile();
        }
    }
}

void calculate_salary_b(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There is no employee that you can calculate the salary for\n"
                "because no employee is hired!" << endl;
    else {
        int i;
        showthelist(vec);
        cout << "Choose the employee that you would like to calculate the salary for: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot calculate the salary for the person nr." << i << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            int m;
            cout << "Enter the number of months: ";
            m = readint(stream);
            cout << "\n";
            if (m > 0) {
                double s_b = vec[i - 1]->get_salary_brutto();
                cout << "You will be taken to the variable calculator" << endl;
                calculate<double>(s_b, m);
                cout << "PLN" << endl;
            } else
                cout << "Invalid choice! Try again." << endl;
        }
    }
}

void calculate_salary_n(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There is no employee that you can calculate the salary for\n"
                "because no employee is hired!" << endl;
    else {
        int i;
        showthelist(vec);
        cout << "Choose the employee that you would like to calculate the salary for: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot calculate the salary for the person nr." << i << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            int m;
            cout << "Enter the number of months: ";
            m = readint(stream);
            cout << "\n";
            if (m > 0) {
                double s_n = vec[i - 1]->get_salary_netto();
                cout << "You will be taken to the variable calculator" << endl;
                calculate<double>(s_n, m);
                cout << "PLN" << endl;
            } else
                cout << "Invalid choice! Try again." << endl;
        }
    }
}

void calculate_bonus(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There is no employee that you can calculate the bonus for\n"
                "because no employee is hired!" << endl;
    else {
        int i;
        showthelist(vec);
        cout << "Choose the employee that you would like to calculate the bonus for: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot calculate the bonus for the person nr." << i << endl;
            if (vec.size() == 1)
                cout << "There is only " << vec.size() << " employee hired!" << endl;
            else
                cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            int m;
            cout << "Enter the number of months: ";
            m = readint(stream);
            cout << "\n";
            if (m > 0) {
                int b = vec[i - 1]->get_bonus();
                cout << "You will be taken to the variable calculator" << endl;
                calculate<int>(b, m);
                cout << "PLN\nKeep in mind that the final amount of the bonus may depend\n"
                        "on the amount of coffee drunk and job done." << endl;
            } else
                cout << "Invalid choice! Try again." << endl;
        }
    }
}

void compare_salary(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There are no employees whose salaries you can compare\n"
                "because no employee is hired!" << endl;
    else if (vec.size() == 1)
        cout << "You cannot compare salaries of employees\n"
                "because only one employee is hired!" << endl;
    else if (vec.size() == 2) {
        double s1 = vec[0]->get_salary_brutto();
        double s2 = vec[1]->get_salary_brutto();
        if (maximum<double>(s1, s2)) {
            cout << "Mr/Mrs " << vec[0]->get_name() << " " << vec[0]->get_surname() << " receives higher salary than\n";
            cout << "Mr/Mrs " << vec[1]->get_name() << " " << vec[1]->get_surname() << endl;
        } else {
            cout << "Mr/Mrs " << vec[1]->get_name() << " " << vec[1]->get_surname() << " receives higher salary than\n";
            cout << "Mr/Mrs " << vec[0]->get_name() << " " << vec[0]->get_surname() << endl;
        }
    } else {
        int i;
        showthelist(vec);
        cout << "Choose the first employee whose salary you would like to compare: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot compare the salary of the person nr." << i << "\n";
            cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            int j;
            cout << "Choose the second employee whose salary you would like to compare: ";
            j = readint(stream);
            cout << "\n";
            if (j > vec.size()) {
                cout << "You cannot compare the salary of the person nr." << i << "\n";
                cout << "There are only " << vec.size() << " employees hired!" << endl;
            } else if (j == i)
                cout << "You cannot compare the salary of the same person" << endl;
            else {
                double s1 = vec[i - 1]->get_salary_brutto();
                double s2 = vec[j - 1]->get_salary_brutto();
                if (maximum<double>(s1, s2)) {
                    cout << "Mr/Mrs " << vec[i - 1]->get_name() << " " << vec[i - 1]->get_surname()
                         << " receives higher salary than\n";
                    cout << "Mr/Mrs " << vec[j - 1]->get_name() << " " << vec[j - 1]->get_surname() << endl;
                } else {
                    cout << "Mr/Mrs " << vec[j - 1]->get_name() << " " << vec[j - 1]->get_surname()
                         << " receives higher salary than\n";
                    cout << "Mr/Mrs " << vec[i - 1]->get_name() << " " << vec[i - 1]->get_surname() << endl;
                }
            }
        }
    }
}

void compare_vacation_days(vector<Tworker *> &vec, istream *stream) {
    if (vec.empty())
        cout << "There are no employees whose vacation days to use you can compare\n"
                "because no employee is hired!" << endl;
    else if (vec.size() == 1)
        cout << "You cannot compare vacation days to use of employees\n"
                "because only one employee is hired!" << endl;
    else if (vec.size() == 2) {
        int v1 = vec[0]->get_vacation();
        int v2 = vec[1]->get_vacation();
        if (maximum<int>(v1, v2)) {
            cout << "Mr/Mrs " << vec[0]->get_name() << " " << vec[0]->get_surname()
                 << " has more vacation days to use than ";
            cout << "Mr/Mrs " << vec[1]->get_name() << " " << vec[1]->get_surname() << endl;
        } else {
            cout << "Mr/Mrs " << vec[1]->get_name() << " " << vec[1]->get_surname()
                 << " has more vacation days to use than ";
            cout << "Mr/Mrs " << vec[0]->get_name() << " " << vec[0]->get_surname() << endl;
        }
    } else {
        int i;
        showthelist(vec);
        cout << "Choose the first employee whose vacation days to use you would like to compare: ";
        i = readint(stream);
        cout << "\n";
        if (i > vec.size()) {
            cout << "You cannot compare vacation days to use of the person nr." << i << "\n";
            cout << "There are only " << vec.size() << " employees hired!" << endl;
        } else {
            int j;
            cout << "Choose the second employee whose vacation days to use you would like to compare: ";
            j = readint(stream);
            cout << "\n";
            if (j > vec.size()) {
                cout << "You cannot compare vacation days to use of the person nr." << i << "\n";
                cout << "There are only " << vec.size() << " employees hired!" << endl;
            } else if (j == i)
                cout << "You cannot compare vacation days to use of the same person" << endl;
            else {
                int v1 = vec[i - 1]->get_vacation();
                int v2 = vec[j - 1]->get_vacation();
                if (maximum<int>(v1, v2)) {
                    cout << "Mr/Mrs " << vec[i - 1]->get_name() << " " << vec[i - 1]->get_surname()
                         << " has more vacation days to use than ";
                    cout << "Mr/Mrs " << vec[j - 1]->get_name() << " " << vec[j - 1]->get_surname() << endl;
                } else {
                    cout << "Mr/Mrs " << vec[j - 1]->get_name() << " " << vec[j - 1]->get_surname()
                         << " has more vacation days to use than ";
                    cout << "Mr/Mrs " << vec[i - 1]->get_name() << " " << vec[i - 1]->get_surname() << endl;
                }
            }
        }
    }
}

ostream &operator<<(ostream &screen, Tworker &e) {
    screen << e.name << " " << e.surname << ", job position: " << e.position << endl;
    return screen;
}

fstream &operator<<(fstream &write, Tworker &e) {
    write << e.name << " " << e.surname << ", salary brutto: " << e.salary_brutto << "PLN, salary netto:  "
          << e.salary_netto << "PLN, bonus this month: ";
    write << e.bonus << "PLN, remaining vacation days: " << e.vacation;
    return write;
}

void hire_trainee(vector<Tworker *> &vec, istream *stream) {
    string n;
    string sn;
    double s;
    int c;
    cout << "Choose the type of contract:\n"
            "Employment contract - 1\n"
            "Specific task contract - 2\n"
            "Mandate contract - 3\n"
            "Your choice: " << endl;
    c = readint(stream);
    if (c == 1 || c == 2 || c == 3) {
        cout << "Enter the name of the new employee:" << endl;
        n = readstring(stream);
        cout << "Enter the surname of the new employee:" << endl;
        sn = readstring(stream);
        cout << "Enter the salary brutto of the new employee:" << endl;
        s = readdouble(stream);
        if (s < 0)
            throw Tnegative_value_exception();
        else if (s >= 0 && s < 3000)
            throw Ttoo_low_value_exception();
        else {
            vec.emplace_back(new Ttrainee(n, sn, s, c));
            cout << "New employee hired successfully!\nInformation about the person:" << endl;
            unsigned int i = vec.size();
            vec[i - 1]->print_all();
            cout << "Information about the new employee will be added to the documentation in the file." << endl;
            writetofile(vec, i);
            cout << "Documentation updated!" << endl;
        }
    } else
        cout << "Invalid choice! Try again";
}

void hire_administrator(vector<Tworker *> &vec, istream *stream) {
    string n;
    string sn;
    double s;
    int c;
    cout << "Choose the type of contract:\n"
            "Employment contract - 1\n"
            "Specific task contract - 2\n"
            "Mandate contract - 3\n"
            "Your choice: " << endl;
    c = readint(stream);
    if (c == 1 || c == 2 || c == 3) {
        cout << "Enter the name of the new employee:" << endl;
        n = readstring(stream);
        cout << "Enter the surname of the new employee:" << endl;
        sn = readstring(stream);
        cout << "Enter the salary brutto of the new employee:" << endl;
        s = readdouble(stream);
        if (s < 0)
            throw Tnegative_value_exception();
        else if (s >= 0 && s < 3000)
            throw Ttoo_low_value_exception();
        else {
            vec.emplace_back(new Tadministrator(n, sn, s, c));
            cout << "New employee hired successfully!\nInformation about the person:" << endl;
            unsigned int i = vec.size();
            vec[i - 1]->print_all();
            cout << "Information about the new employee will be added to the documentation in the file." << endl;
            writetofile(vec, i);
            cout << "Documentation updated!" << endl;
        }
    } else
        cout << "Invalid choice! Try again";
}

void hire_programmer(vector<Tworker *> &vec, istream *stream) {
    string n;
    string sn;
    double s;
    int c;
    cout << "Choose the type of contract:\n"
            "Employment contract - 1\n"
            "Specific task contract - 2\n"
            "Mandate contract - 3\n"
            "Your choice: " << endl;
    c = readint(stream);
    if (c == 1 || c == 2 || c == 3) {
        cout << "Enter the name of the new employee:" << endl;
        n = readstring(stream);
        cout << "Enter the surname of the new employee:" << endl;
        sn = readstring(stream);
        cout << "Enter the salary brutto of the new employee:" << endl;
        s = readdouble(stream);
        if (s < 0)
            throw Tnegative_value_exception();
        else if (s >= 0 && s < 3000)
            throw Ttoo_low_value_exception();
        else {
            vec.emplace_back(new Tprogrammer(n, sn, s, c));
            cout << "New employee hired successfully!\nInformation about the person:" << endl;
            unsigned int i = vec.size();
            vec[i - 1]->print_all();
            cout << "Information about the new employee will be added to the documentation in the file." << endl;
            writetofile(vec, i);
            cout << "Documentation updated!" << endl;
        }
    } else
        cout << "Invalid choice! Try again";
}

void hire_analyst(vector<Tworker *> &vec, istream *stream) {
    string n;
    string sn;
    double s;
    int c;
    cout << "Choose the type of contract:\n"
            "Employment contract - 1\n"
            "Specific task contract - 2\n"
            "Mandate contract - 3\n"
            "Your choice: " << endl;
    c = readint(stream);
    if (c == 1 || c == 2 || c == 3) {
        cout << "Enter the name of the new employee:" << endl;
        n = readstring(stream);
        cout << "Enter the surname of the new employee:" << endl;
        sn = readstring(stream);
        cout << "Enter the salary brutto of the new employee:" << endl;
        s = readdouble(stream);
        if (s < 0)
            throw Tnegative_value_exception();
        else if (s >= 0 && s < 3000)
            throw Ttoo_low_value_exception();
        else {
            vec.emplace_back(new Tanalyst(n, sn, s, c));
            cout << "New employee hired successfully!\nInformation about the person:" << endl;
            unsigned int i = vec.size();
            vec[i - 1]->print_all();
            cout << "Information about the new employee will be added to the documentation in the file." << endl;
            writetofile(vec, i);
            cout << "Documentation updated!" << endl;
        }
    } else
        cout << "Invalid choice! Try again";
}

void hire_accountant(vector<Tworker *> &vec, istream *stream) {
    string n;
    string sn;
    double s;
    int c = 1;
    cout << "This person will automatically be hired under a contract of employment." << endl;
    cout << "Enter the name of the new employee:" << endl;
    n = readstring(stream);
    cout << "Enter the surname of the new employee:" << endl;
    sn = readstring(stream);
    cout << "Enter the salary brutto of the new employee:" << endl;
    s = readdouble(stream);
    if (s < 0)
        throw Tnegative_value_exception();
    else if (s >= 0 && s < 3000)
        throw Ttoo_low_value_exception();
    else {
        vec.emplace_back(new Taccountant(n, sn, s, c));
        cout << "New employee hired successfully!\nInformation about the person:" << endl;
        unsigned int i = vec.size();
        vec[i - 1]->print_all();
        cout << "Information about the new employee will be added to the documentation in the file." << endl;
        writetofile(vec, i);
        cout << "Documentation updated!" << endl;
    }
}


int readint(istream *stream) {
    string line;
    getline(*stream, line);
    if (line.empty())
        getline(cin, line);
    return atoi(line.c_str());
}

double readdouble(istream *stream) {
    string line;
    getline(*stream, line);
    if (line.empty())
        getline(cin, line);
    return atof(line.c_str());
}

string readstring(istream *stream) {
    string line;
    getline(*stream, line);
    if (line.empty())
        getline(cin, line);
    return line;
}