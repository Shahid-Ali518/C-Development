#include "iostream"

using namespace std;

void displaystr(char*);
void copystr(char*, const char*);

int main()
{
    char str1[] = "Defined as an array";
    char *str2 = "Defined as a pointer";

    // str1++;

    str2++;

    cout << str1 << endl;
    cout << str2 << endl;

    char s[] = "Shahid is yours";

    displaystr(s);

    char* src = "thi is string to be copied";
    char dest[80];

    copystr(dest, src);

    cout << dest;

    


    return 0;
}

void displaystr(char *ptr){
    while( *ptr)
        cout << *ptr++;
    cout << endl;
}

// function to copy the one string to another
void copystr(char* des, const char* src){
    while( *src )
        *des++ = *src++;
    *des = '\0';
}