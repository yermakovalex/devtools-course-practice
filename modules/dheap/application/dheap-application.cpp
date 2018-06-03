// Copyright 2018 Lipatov Igor

#include <include/dheap-app.h>
#include <string>

int main(int argc, const char **argv) {
    MinSearcher ms;
    std::string output = ms(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
