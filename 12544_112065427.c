#include <stdio.h>
#include <string.h>

char input[1000];
char title[1000] = {0};
int ctr_link = 0;
int ctr_tit = 0;

char target_start[] = "<title>";
char target_end[] = "</title>";

int main(void){
    while(fgets(input, sizeof(input), stdin)) {

        /*-----Sub string search-----*/
        if(!ctr_tit) {
            //1. Create pointer for saving the address of occurence
            char * head = strstr(input, target_start);
            //2. If not null, get the tail
            if(head) {
                head += strlen(target_start);//3. move the cursor the first char of the title

                //4. Get the address of the end of the title (the last)
                char * end = strstr(input, target_end);

                //5. if not null, parse the content
                if(end) {
                    strncpy(title, head, end - head); //Destination (arr), source, count
                    ctr_tit++;
                }
            }
        }

        /*-----Cursor search-----*/
        char * ptr = input; //create cursor as well as the storage for substring search
        //Only search for the end tag, since the start tag can be dynamic
        while((ptr = strstr(ptr, "</a>")) != NULL) {
            ctr_link++;
            ptr++;
        }
    }
    //CTRL + Z to EOF
    printf("%s\n", title);
    printf("%d\n", ctr_link);


    return 0;
}

/*
<head>
	<title>This is the title</title>
</head>
<body>
	<h1>Hello world</h1>
	<p>Good luck and have <a href="http://140.114.86.238/problem/12544/">fun</a>!!!</p>
</body>
*/
