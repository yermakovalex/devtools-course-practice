// Copyright 2018 Senina Anastasia

#include "include/game_of_life.h"
#include "include/game-of-life-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

GameOfLife::GameOfLife() : message_("") {}

void GameOfLife::help(const char* appname, const std::string message) {
  message_ =
    std::string(message) +
    "\nThis is a Game of Life application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <count of steps> " +
    "<string fields consisting of  symbols <*> or <.>>." +
    " Each string fields through a space  \n\n" +

    "Example: 2 *** .*. ..* ";
}

bool GameOfLife::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc == 2) {
    help(argv[0], "ERROR: Should be more than 1 arguments.\n\n");
    return false;
  }
  return true;
}

int parseInt(const char* arg) {
  int value = atoi(arg);
  if (value < 1) {
    throw std::string("Wrong number format!");
  }
  return value;
}

char** parseMas(const int argc, const char** arg, int* s1, int* s2) {
  int len = 0;
  char a = '*';
  char b = '.';

  for (; arg[2][len] != '\0'; ++len) {}

  char** grid = new char*[argc-2];
  for (int i = 0; i < argc - 2; ++i)
    grid[i] = new char[len];

  for (int i = 2; i < argc; ++i) {
    int j = 0;
    for (; arg[i][j] != '\0'; ++j) {
      if (j >= len)
        throw std::string("ERROR: Wrong lengths of strings!");
      if (arg[i][j] != a && arg[i][j] != b)
        throw  std::string("ERROR: Wrong grid format!");
      grid[i - 2][j] = arg[i][j];
    }
    if (j < len)
      throw std::string("ERROR: Wrong lengths of strings!");
  }
  *s1 = argc -2;
  *s2 = len;
  return grid;
}

std::string GameOfLife::operator()(int argc, const char** argv) {
  Arguments args;
  int s1, s2;
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    args.count = parseInt(argv[1]);
    args.grid = parseMas(argc, argv, &s1, &s2);
  }
  catch (std::string& str) {
    help(argv[0], str);
    return message_;
  }

  game_of_life* GoL;

  GoL = new game_of_life(args.grid, s1, s2);
  for (int i = 0; i < args.count; ++i)
    GoL->next_step();

  char** grid = new char*[s1];
  for (int i = 0; i < s1; ++i)
    grid[i] = new char[s2];

  GoL->get_grid(grid);

  message_ = "Input:\n";

  for (int i = 0; i < s1; ++i) {
    for (int j = 0; j < s2; ++j) {
      message_ += args.grid[i][j];
    }
    message_ += '\n';
  }

  message_ += "\nResult:\n";

  for (int i = 0; i < s1; ++i) {
    for (int j = 0; j < s2; ++j) {
      message_ += grid[i][j];
    }
    message_ += '\n';
  }

  return message_;
}
