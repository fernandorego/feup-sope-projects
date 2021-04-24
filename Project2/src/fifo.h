#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "string.h"
#include "utils.h"
#include "communication.h"
#include "tasks.h"


extern struct message m;


/**
 * @brief Creates a publicFIFO object.
 * @return Whether it was successful or not. 
 */
int create_publicFIFO(int argc, char* argv[]);

/**
 * @brief Eliminates a publicFIFO object.
 * @return Whether it was successful or not. 
 */
int eliminate_publicFIFO(int argc, char* argv[]);

/**
 * @brief Create a privateFIFO object.
 * @return Whether it was successful or not. 
 */
int create_privateFIFO(struct message **sms);

/**
 * @brief Unlinks a privateFIFO object.
 * @return Whether it was successful or not.
 */
int eliminate_privateFIFO(struct message **sms);