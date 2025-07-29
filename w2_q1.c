#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    printf("Opening a directory\n");
    dir=opendir(".");
    if(dir==NULL)
    {
        printf("Unable to open a directory\n");
        return 0;
    }
    printf("The name of the files in a directory are: ");
    while((entry = readdir(dir))!=NULL)
    {
        printf("%s\n",entry->d_name);
    }
    printf("Closing the directory\n");
    closedir(dir);
    return 0;
}
