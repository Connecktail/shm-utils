# shm-utils

## Purpose :

This repository provide a C library for shared memory in the connecktail project in order to know the pid of the different processes.

## Build the library :

- clone the repository
- execute the following commands :

```bash
make
make install
```

The headers have been added to the /usr/include/shm-utils repository

In your code, you have just to include the shmutils.h header file :

```c
#include <shm-utils/shmutils.h>
```

**Because the functions to get or modify the shared memory need the shared memory id, you have to declare a global variable in your code :**

```c
int shmid;
```

Its value will be the result of the init_shared_memory() function.

## Compilation :

If you want to use the static library, you have just to specify the path of the lib and its name :

```bash
gcc file.c -L path/to/libshm-utils.a -lshm-utils -o file
```

On the other hand, if you want to use the dynamic library, specify the name of the lib during the links edition :

```bash
gcc file.c -lshm-utils -o file
```

## Shared memory data structure :

```c
typedef struct
{
    pid_t main_pid;
    pid_t websocket_pid;
    pid_t device_handler_pid;
} shm_t;

```

## Functions :

### Utils

- Initialize the shared memory :

```c
int init_shared_memory()
```

- Retrieve the shared memory (readonly):

```c
shm_t *get_shm();
```

- Modify the pid of the main process :

```c
void change_main_pid(int pid)
```

- Modify the pid of the websocket process :

```c
void change_websocket_pid(int pid)
```

- Modify the pid of the device handler process :

```c
void change_device_handler_pid(int pid)
```

- Create and set the shared memory :

```c
void set_init_shm()
```
