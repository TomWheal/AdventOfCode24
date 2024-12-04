#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
    printf("Day Three\n");
    FILE* fptr;
    // I had to remove line endings from the text file, cause it messed with it call.
    fptr = fopen("../day3.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    regex_t reegex;
    regex_t regex_do;
    regex_t regex_nt;
    regoff_t    offset, length;
    // Variable to store the return
    // value after creation of regex
    int value;
    long sum =0;
    // Function call to create regex
    regcomp( &reegex, "mul\\(\[0-9\]{1,3},\[0-9\]{1,3}\\)", 1);
    //
    char line[30000];
    //char buf[1024];
    char str_do[] = "do()";
    char str_nt[] = "don't()";
    int line_num = 0;
    char * pch;
    while (fgets(line, 30000, fptr) != NULL) {
        regmatch_t matches;
        char *s = line;
        char *off_do;
        char *off_nt;
        //printf(line);
        for (int i = 0; ; i++) {
            if (regexec (&reegex, s, 1, &matches, 0)) {
                break;
            }
            off_do = strstr(s,str_do);
            off_nt = strstr(s,str_nt);


            if ((off_nt != NULL)&((s+matches.rm_so)>off_nt)) {
                    if (off_do != NULL) {
                        printf("Skipping to next do at %ld\n",off_do - line);
                        s = off_do ;
                    }
                    else
                        break;
            }
            else {
                if (matches.rm_so == -1)
                    break;
                offset = matches.rm_so + (s - line);
                length = matches.rm_eo - matches.rm_so;
                printf("\toffset = %jd; length = %jd\n", (int) offset,
                    (int) length);
                printf("\tsubstring = \"%.*s\"\n", length, s + matches.rm_so);
                //printf ("\t[%d] %d %d \n", j, matches [j].rm_so, matches [j].rm_eo);

                char temp[20];
                char* pch;
                int num1,num2;
                strncpy(temp, s + matches.rm_so, length);
                pch = strtok(&temp[4], ",");
                num1 = atoi(pch);
                pch = strtok(NULL, ",");
                num2 = atoi(pch);
                printf("%d*%d = %d\n", num1, num2, num1*num2);
                sum=sum+ num1*num2;
                s += matches.rm_eo-1;

           }



        }


    }
    printf("sum = %jd\n", sum);
    return 0;
}
