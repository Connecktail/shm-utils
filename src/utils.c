#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

#include "../include/shmutils.h"

int init_shared_memory()
{
    int shmflg = IPC_CREAT | 0666;
    key_t key = ftok(SHM_NAME, SHM_ID);
    return shmget(key, sizeof(shm_t), shmflg);
}

void set_init_shm()
{
    shm_t *shm = (shm_t *)shmat(shmid, NULL, 0666);
    shm->main_pid = 0;
    shm->websocket_pid = 0;
    shm->device_handler_pid = 0;
    shmdt(shm);
}

shm_t *get_shm()
{
    return (shm_t *)shmat(shmid, NULL, SHM_RDONLY);
}

void change_main_pid(int pid)
{
    shm_t *shm = (shm_t *)shmat(shmid, NULL, 0666);
    shm->main_pid = pid;
    shmdt(shm);
}

void change_websocket_pid(int pid)
{
    shm_t *shm = (shm_t *)shmat(shmid, NULL, 0666);
    shm->websocket_pid = pid;
    shmdt(shm);
}

void change_device_handler_pid(int pid)
{
    shm_t *shm = (shm_t *)shmat(shmid, NULL, 0666);
    shm->device_handler_pid = pid;
    shmdt(shm);
}