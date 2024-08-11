#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_tree(const char *path, int level) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    
    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        char new_path[1024];
        sprintf(new_path, "%s/%s", path, entry->d_name);
        
        if (lstat(new_path, &fileStat) < 0) {
            perror("lstat");
            return;
        }
        
        if (S_ISDIR(fileStat.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                for (int i = 0; i < level; i++) {
                    printf("  ");
                }
                printf("|- %s\n", entry->d_name);

                print_tree(new_path, level + 1);
            }
        } else {
            for (int i = 0; i < level; i++) {
                printf("  ");
            }
            printf("|- %s\n", entry->d_name);
        }
    }
    
    closedir(dir);
}

int main() {
    char *path = "."; // 遍历当前目录
    
    printf("%s\n", path);
    print_tree(path, 1);
    
    return 0;
}