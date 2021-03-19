#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include "register.h"


void getFichDir(const char *fichDir);
void sigtermHandler(int sig);
void sigcontHandler(int sig);
void sigHandler(int sig);
void sigHandlerDefault(int sig);