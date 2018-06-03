// Copyright 2018 Senina Anastasia

#ifndef MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_
#define MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_

#include <string>

class GameOfLife {
 public:
  GameOfLife();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const std::string message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
  typedef struct {
    int count;
    char** grid;
  } Arguments;
};

#endif  // MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_
