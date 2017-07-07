#include <dirent.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    DIR* folder = opendir(argv[1]);
    if (folder == NULL) {
        fprintf(stderr, "Error: Unable to open directory \"%s\"\n", argv[0]);
        return 2;
    }
    struct dirent* entry;
    while ((entry = readdir(folder)) != NULL) {
        printf("%s", entry->d_name);
        if (entry->d_type == DT_DIR) {
            printf("/");
        }
        printf("\t\t%d\n", entry->d_type);
    }
    closedir(folder);
    return 0;
}

