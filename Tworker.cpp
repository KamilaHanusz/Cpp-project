
#include "Tworker.h"
#include <iostream>

void Tworker::do_your_job() {
    std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" just said, 'I'm doing my job, it's great fun!\n";
    std::cout<<"And now my bonus will be 5PLN higher!'"<<std::endl;
    bonus += 5;
}

void Tworker::drink_coffee() {
    if (bonus >= 5) {
        std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" just said,'Mmmmm this coffee is delicious!\n";
        std::cout<<"But I'm aware that my bonus will be 5PLN lower'"<<std::endl;
        bonus -= 5;
    }
    else if (bonus < 5 && bonus > 0) {
        std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" just said,'Mmmmm this coffee is delicious!\n";
        std::cout<<"But I'm aware that I will lose my remaining bonus'"<<std::endl;
        bonus = 0;
    }
    else {
        std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" just said,'Mmmmm this coffee is delicious!\n";
        std::cout<<"And my bonus is already 0PLN so I don't have to care about it'"<<std::endl;
    }
}

void Tworker::L4(int m, int l) {
    if (l == 1)
        std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" has been on a sick leave for "<<l<<" day "<<std::endl;
    else
        std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" has been a sick leave for "<<l<<" days "<<std::endl;

    double brutto_lost = (salary_brutto/m)*l*0.3;
    double netto_lost = (salary_netto/m)*l*0.3;
    salary_brutto -= brutto_lost;
    salary_netto -= netto_lost;
    std::cout<<"This month his/her salary brutto will be "<<brutto_lost<<"PLN lower than normally,\n";
    std::cout<<"witch means that his/her salary netto will be "<<netto_lost<<"PLN lower than normally.\n";
    std::cout<<"The amount of the salary brutto will be "<<salary_brutto<<"PLN.\n";
    std::cout<<"The amount of the salary netto will be "<<salary_netto<<"PLN."<<std::endl;
}

void Tworker::print_all() {
    std::cout<<name<<" "<<surname<<", job position: "<<position<<", salary brutto: "<<salary_brutto<<
             "PLN, salary netto: "<<salary_netto<<"PLN,\nbonus: "<<bonus<<"PLN, remaining vacation days: "<<vacation<<std::endl;
}

void Tworker::vacation_leave() {
    if (vacation > 0) {
        std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" is on their vacations now!\n";
        std::cout<<"Probably sunbathing in the Bahamas!"<<std::endl;
        vacation -= 1;
    }
    else {
        std::cout<<"That is very sad, but Mr/Mrs "<<name<<" "<<surname<<" has no more holiday leave to take"<<std::endl;
    }
}