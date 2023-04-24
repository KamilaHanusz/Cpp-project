
#ifndef HANUSZKAMILA_ETAP2_TWORKER_H
#define HANUSZKAMILA_ETAP2_TWORKER_H

#include<string>

class Tworker {
protected:
    std::string name;
    std::string surname;
    double salary_brutto;
    double salary_netto;
    int vacation;
    int bonus;
    std::string position;

public:
    virtual void work_remotely() = 0;
    virtual void do_your_job();
    virtual void drink_coffee();
    void L4(int m, int l);
    virtual void print_all();
    virtual void vacation_leave();
    double get_salary_brutto() const {
        return salary_brutto;
    }
    double get_salary_netto() const {
        return salary_netto;
    }
    int get_bonus() const {
        return bonus;
    }
    std:: string get_name() const {
        return name;
    }
    std:: string get_surname() const {
        return surname;
    }
    int get_vacation() const {
        return vacation;
    }


    friend std::ostream& operator<<(std::ostream &screen, Tworker &e);
    friend std::fstream& operator<<(std::fstream &write, Tworker &e);

    Tworker(std::string n, std::string sn, double s, int c) : name(std::move(n)),surname(std::move(sn)),salary_brutto(s) {
        switch (c) {
            case 1:
                salary_netto = s * 0.73;
                break;
            case 2:
                salary_netto = s * 0.86;
                break;
            case 3:
                salary_netto = s * 0.76;
                break;
            default:
                break;
        }
        vacation = 2;
        bonus = 50;
    }
    virtual ~Tworker() = default;
};


#endif //HANUSZKAMILA_ETAP2_TWORKER_H
