
#include "hw2.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
char* file_path = "words.txt";

void q3(void) 
//int main()
{
	char subword[20];

	printf("Enter a subword to find: ");
	scanf("%s", subword);

	// You may write your own function(s) if needed;
    int sizeofsub=strlen(subword);
	int ans_31 = 0;
	int ans_32 = 0;
	double ans_33 = 0.0;
	int ans_34 = 0;
	int ans_35 = 0;
    char ch='A';
    //char * largest;
    int inpure=0;
    FILE * fp =fopen("words.txt","r");
    char * cmp_sub; 
    char prev_ch;
    cmp_sub=(char*)malloc(sizeof(char)*strlen(subword));
    //largest=(char *)malloc(sizeof(char));
    if (fp!=NULL){
        while (ch!=EOF){

            int count=0; 
            int a=0;
            //char* tmp;
            //scanf("%d",&a);
            //char * words;
            //words=malloc(4);
            //printf("%ld\n",strlen(words));
            int inpure_temp=0;
            while (1){
                ch=fgetc(fp);
                if (ch==' ' || ch=='\0' || ch=='\n' || ch==EOF){
                    break;
                }
                
                if (count==0){
                    prev_ch=ch;
                }
                else{
                    
                    if (ch==prev_ch){
                        a+=1;
                    }
                    prev_ch=ch;
                }
                if (65>ch||(ch>90 && ch<97)||ch>122){
                    inpure_temp++;
                }
                if (count<sizeofsub){
                    cmp_sub[count]=ch;
                }
                if (count==sizeofsub-1){
                    if (strncmp(cmp_sub,subword,sizeofsub)==0){
                        ans_35++;
                    }
                }
                else if (count>sizeofsub-1){
                    for (int i=0; i<sizeofsub-1;i++){
                        cmp_sub[i]=cmp_sub[i+1];
                    }
                    cmp_sub[strlen(subword)-1]=ch;
                    if (strncmp(cmp_sub,subword,sizeofsub)==0){
                        ans_35++;
                    }
                }
                count++;
                //words[count++]=ch;
                /*
                tmp=malloc((count+1)*sizeof(char));
                printf("%ld,%d\n",strlen(words),count);
                printf("1:%p, %p\n%s  %s\n",words,tmp,words,tmp);
                strcpy(tmp,words);
                free(words);  
                printf("%ld,%d\n",strlen(tmp),count);
                printf("2:%p, %p\n%s  %s\n",words,tmp,words,tmp);
                words=tmp;
                printf("%ld,%d\n",strlen(tmp),count);
                printf("3:%p, %p\n%s  %s\n",words,tmp,words,tmp);
                */
            }
            ans_31++;
            if (a>0){
                ans_34++;
            }
            if (inpure_temp>0){inpure++;}
            if (count>ans_32){
                ans_32=count;
                /*
                free(largest);
                largest=malloc(sizeof(char)*count);
                strcpy(largest,words);
                */
            }
            //printf("\n\n%s\n\n\n",words);
            
            //free(words);
            
        }
        ans_31--; //제가 다운로드한 words.txt 파일의 마지막 줄은 빈 줄이여서 이렇게 했습니다..
        

        if (ans_31!=0){
            ans_33=100*(ans_31-inpure);
            ans_33/=ans_31;
        }
        else{
            ans_33=0;
        }
	    printf("%d %d %.2lf%% %d %d\n", ans_31, ans_32, \
				    ans_33, ans_34, ans_35);
        //free(largest);
        free(cmp_sub);
        fclose(fp);
    }

}