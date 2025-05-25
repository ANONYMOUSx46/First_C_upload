#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>

void get_os_version() {
    DWORD version = GetVersion();
    DWORD major = (DWORD)(LOBYTE(LOWORD(version)));
    DWORD minor = (DWORD)(HIBYTE(LOWORD(version)));

    printf("Windows version: %lu.%lu\n", major, minor);
}

void get_hostname() {
    char hostname[MAX_PATH];
    DWORD size = sizeof(hostname);
    if (GetComputerNameA(hostname, &size)) {
        printf("Hostname: %s\n", hostname);
    } else {
        fprintf(stderr, "Could not retrieve hostname. Error: %lu\n", GetLastError());
    }
}

#else
#include <unistd.h>
#include <sys/utsname.h>

void get_os_version() {
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        printf("OS: %s %s\n", buffer.sysname, buffer.release);
    } else {
        perror("Could not retrieve OS version");
    }
}

void get_hostname() {
    char hostname[MAX_PATH];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    } else {
        perror("Could not retrieve hostname");
    }
}
#endif

int main() {
    printf("System Information Retrieval\n");
    printf("-----------------------------\n");

    get_os_version();
    get_hostname();

    return EXIT_SUCCESS;
}