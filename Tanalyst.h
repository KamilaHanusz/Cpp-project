
#ifndef TANALYST_H
#define TANALYST_H
#include "Tworker.h"
#include<string>

class Tanalyst :public Tworker {
public:
    void work_remotely() override;
    Tanalyst(std::string n, std::string sn, double s, int c) : Tworker(std::move(n), std::move(sn), s, c) {
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
        position = "Analyst";
    }
};


#endif //TANALYST_H
