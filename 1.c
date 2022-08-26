#include "hw2.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
#define PASSWD_SZ 31
#define TRUE 1
#define FALSE 0

char quit[] = "quit";
char special_letters[] = "!%_&#+-*/"; 
char numbers[]="1234567890";
char alphabets[]="abcdefghijklmnopqrstuvwxyz";
char alphabetl[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int check_passwd(char* password, int passwd_len);
int satisfy(char password[],char special_letters[]){
    for (int i=0; i<strlen(password);i++){
        char ch=password[i];
        for (int j=0; j<strlen(special_letters);j++){
            if(password[i]==special_letters[j]){
                return 1;
                }
            }
        }
    return 0;    
}
void q1(void)
//int main()
{
	
	

	while (1) {
        int res = FALSE;
        char password[PASSWD_SZ];
		printf("Create your password (up to 30 letters): ");
		scanf("%s", password);
		// Your code here

        int size= strlen(password);
        int temp=0;
        if (size==4){
            for (int i=0; i<4;i++){
                if(password[i]==quit[i]){
                    temp++;
                }
            }
        }
        if (temp==4){
            break;
        }
        if (size>=10 && size<=30){
            
        

            int flag=0;
            flag+=satisfy(password,special_letters);
            
            flag+=satisfy(password,numbers);
            
            flag+=satisfy(password,alphabets);
            
            flag+=satisfy(password,alphabetl);
            if (flag==4){
                
                res=TRUE;
            }

        }
        else{
            break;
        }
		
		if (res == TRUE)
			printf("Good password!\n");
		else
			printf("Bad password!\n");			
	}

}