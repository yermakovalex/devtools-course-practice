// Copyright 2018 Matyasov Mixail

#include<iostream>
#include<string>
#include"include/wages_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string str = app(argc, argv);
    std::cout << str;
    return 0;
}
