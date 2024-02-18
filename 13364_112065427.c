#include <stdio.h>
#include <string.h>
#define MAX 5001


int main(void){
   int tests = 0;
   scanf("%d", &tests);

   int current = 1;
   while(current <= tests){

       //Stack Concept
       char* ori_folder[50];
       int top_ori_folder = -1; //Dummy Head

       char ori_dir[MAX];
       scanf("%s", ori_dir);

       for(int i=0; i<MAX && ori_dir[i] != '\0'; i++){
           if(ori_dir[i] == '/'){
               ori_dir[i] = '\0';
               ori_folder[++top_ori_folder] = &ori_dir[i+1];
           }
       }

       char fake_dir[MAX];
       scanf("%s", fake_dir);
       int index=strlen(fake_dir)-1;
       int not_valid = 0;

       while( index >= 0){
           if( fake_dir[index] == '/' ){
               fake_dir[index] = '\0';
               char* D_folderName = &fake_dir[index+1];
               int found = 0;
               for(int i=0; i<=top_ori_folder; i++){
                   if( strcmp(ori_folder[i], D_folderName) == 0){
                       found = 1;
                       break;
                   }
               }

               if(!found){
                   not_valid = 1;
                   break;
               }
           }
           index--;
       }

       if(not_valid) printf("not valid\n");
       else printf("valid\n");
       current++;
   }
   return 0;
}
