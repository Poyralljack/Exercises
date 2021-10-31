#include<stdio.h>	
#include<stdlib.h>
#include<string.h>

/*Working efficieny is O(n^3) */

void substring(char s[], char sub[], int p, int len) { // This function checks whether substring of given string or not
    int c = 0;
    while (c < len) {
        sub[c] = s[p + c];
        c++;
    }
    sub[c] = '\0';
}
int isPalindrome(char str[]) // This function checks whether palindrome substring or not if palindrome substring ,then will return 1;
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char* str, c;
    char* str1;
    int i = 0, j = 1;

    str = (char*)malloc(sizeof(char));
    str = (char*)malloc(sizeof(char));
    printf("Enter String : ");

    while (c != '\n') {
        // read the input from keyboard standard input
        c = getc(stdin);

        // re-allocate (resize) memory for character read to be stored
        str = (char*)realloc(str, j * sizeof(char));
        str1 = (char*)realloc(str1, j * sizeof(char));
        // store read character by making pointer point to c
        str[i] = c;
        str1[i] = '0';
        i++;
        j++;
    }

    str[i] = '\0'; // at the end append null character to mark end of string
    str1[i] = '\0';
    int len = strlen(str);
    len -= 1;
    int counter = 0;
    for (i = 0; i < len; i++) {
        //This loop adds the next character every iteration for the subset to form and add it to the array 
        //This loop also counts the number of palindrome all substrings of the string
        for (j = 1; j <= len - i; j++) {
            substring(str, str1, i, j);
            counter+=isPalindrome(str1);
        }
    }
    printf("%d\n", counter);
    free(str);
}