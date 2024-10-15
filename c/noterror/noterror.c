#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

// Error codes
#define FILE_ERROR 1
#define MEMORY_ERROR 2
#define NETWORK_ERROR 3
#define HANDLE_ERROR(code, message) handle_error(code, message, __FUNCTION__, __LINE__)
#define LOG_FILE "error_log.txt"

void log_error(const char *error_type, const char *message, const char *func, int line) {
    FILE *log = fopen(LOG_FILE, "a");
    if (log == NULL) {
        fprintf(stderr, "Failed to open log file: %s\n", strerror(errno));
        return;
    }
    
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0';  // Remove newline from the timestamp
    
    fprintf(log, "[%s] ERROR: %s | Message: %s | Function: %s | Line: %d\n", timestamp, error_type, message, func, line);
    fclose(log);
}


void handle_error(int error_code, const char *message, const char *func, int line) {

    switch (error_code) {
        case FILE_ERROR:
            log_error("FILE ERROR", message, func, line);
            fprintf(stderr, "File operation failed: %s\n", message);
            break;
        case MEMORY_ERROR:
            log_error("MEMORY ERROR", message, func, line);
            fprintf(stderr, "Memory allocation failed: %s\n", message);
            break;
        case NETWORK_ERROR:
            log_error("NETWORK ERROR", message, func, line);
            fprintf(stderr, "Network communication failed: %s\n", message);
            break;
        default:
            log_error("UNKNOWN ERROR", message, func, line);
            fprintf(stderr, "An unknown error occurred: %s\n", message);
            break;
    }

    
    if (error_code == MEMORY_ERROR) {
        fprintf(stderr, "Critical memory error. Exiting program...\n");
        exit(EXIT_FAILURE);  // Exit on memory allocation failure
    }
}


void perform_file_operation() {
    FILE *file = fopen("non_existent_file.txt", "r");
    if (file == NULL) {
        HANDLE_ERROR(FILE_ERROR, strerror(errno));  
        return;
    }
    
    
    fclose(file);
}
void perform_memory_allocation() {
    int *array = (int*)malloc(1000 * sizeof(int));
    if (array == NULL) {
        HANDLE_ERROR(MEMORY_ERROR, "Failed to allocate memory");
        return;
    }

    free(array);
}
void perform_network_operation() {
    int network_success = 0; 
    
    if (!network_success) {
        HANDLE_ERROR(NETWORK_ERROR, "Failed to establish network connection");
        return;
    }
}
int main() {
    perform_file_operation();
    perform_memory_allocation();
    perform_network_operation();
    
    printf("Program executed successfully (if no critical errors occurred).\n");
    return 0;
}
