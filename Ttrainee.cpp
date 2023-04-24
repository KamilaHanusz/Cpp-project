
#include <iostream>
#include "Ttrainee.h"

void Ttrainee::work_remotely() {
    std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" cannot from their home.\nHe/She is a trainee and only programmers and analysts can work remotely"<<std::endl;
}

void Ttrainee::drink_coffee() {
    std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" just said,'Mmmmm this coffee is delicious!'"<<std::endl;
}

void Ttrainee::do_your_job() {
    std::cout<<"Mr/Mrs "<<name<<" "<<surname<<" just said, 'I'm doing my job, it's great fun!"<<std::endl;
}

void Ttrainee::print_all() {
    std::cout<<name<<" "<<surname<<", job position: "<<position<<", salary brutto: "<<salary_brutto<<
    "PLN, salary netto: "<<salary_netto<<"PLN\nThis person is not eligible for bonus or vacation leave"<<std::endl;
}

void Ttrainee::vacation_leave() {
    std::cout<<"That is very sad, but Mr/Mrs "<<name<<" "<<surname<<" cannot go on holidays because he/she is a trainee."<<std::endl;
}