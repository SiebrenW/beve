#pragma once

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void parse_arguments(int argc, char *const *const argv) {
  int opt;
  while ((opt = getopt(argc, argv, "a:b:")) != -1) {
    switch (opt) {
    case 'a':
      printf("Option a with value %s\n", optarg);
      break;
    case 'b':
      printf("Option b with value %s\n", optarg);
      break;
    default:
      fprintf(stderr, "Usage: %s [-a value] [-b value]\n", argv[0]);
      exit(1);
    }
  }
}