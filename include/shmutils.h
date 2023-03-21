#ifndef SHMUTILS_H
#define SHMUTILS_H

#include <sys/types.h>

#define SHM_ID 12345
#define SHM_NAME "/etc/connectail/shm"

extern int shmid;

typedef struct
{
    pid_t main_pid;
    pid_t websocket_pid;
    pid_t device_handler_pid;
} shm_t;

/**
 * @brief  Initialize the shared memory
 * @return the shared memory id
 */
int init_shared_memory();

/**
 * @brief Get the shared memory (cannot be modified)
 * @return  the shared memory
 */
shm_t *get_shm();

/**
 * @brief Change the main pid
 * @param pid the pid
 */
void change_main_pid(int pid);

/**
 * @brief Change the websocket pid
 * @param pid the pid
 */
void change_websocket_pid(int pid);

/**
 * @brief Change the device handler pid
 * @param pid the pid
 */
void change_device_handler_pid(int pid);

/**
 * @brief Set the shared memory to 0
 * @note This function is used to initialize the shared memory
 */
void set_init_shm();

#endif