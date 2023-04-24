
#ifndef TTRAINEE_H
#define TTRAINEE_H
#include "Tworker.h"
#include<string>


class Ttrainee : public Tworker {
public:
    void work_remotely() override;
    void drink_coffee() override;
    void do_your_job() override;
    void print_all() override;
    void vacation_leave() override;
    Ttrainee(std::string n, std::string sn, double s, int c) : Tworker(std::move(n), std::move(sn), s, c) {
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
        vacation = 0;
        bonus = 0;
        position = "Trainee";
    }
};


#endif //TTRAINEE_H
