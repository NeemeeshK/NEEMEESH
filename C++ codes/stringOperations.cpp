#include <stdio.h>
int main() {
    while(1){
        char str1[20],str2[20];
        int i=0,j=0,choice;
        printf("\nChoose From the Following Operations:\n1.Length of String\n2.Copy of String\n3.Concatenate String\n4.Reverse String\n5.End\nEnter the Choice(1/2/3/4/5):");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter string S1:");
                    scanf("%s",&str1);
                while(str1[i]!='\0'){
                    i++;
                    }
                printf("\nLength of S1:", i);
            break;
            case 2:
            printf("Enter string S1:");
            scanf("%s",&str1);
            while(str1[i]!='\0'){
                str2[i]=str1[i];
                i++;
                }
            printf("Copy of string:%s",str2);
            break;
            case 3:
            printf("\nEnter string S1:");
            scanf("%s",&str1);
            printf("\nEnter string S2:");
            scanf("%s",&str2);
            while(str1[j]!='\0'){
                j++;
            }
                while(str2[i]!='\0'){
                    str1[j+i]=str2[i];
                    i++;  
                }
                str1[i+j]='\0';
            printf("Concatenated string:%s",str1);
            break;
            case 4:
                printf("\nEnter string S1:");
                scanf("%s",&str1);
                while(str1[j]!='\0'){
                    j++;
                }
                while(str1[i]!='\0'){
                    str2[i]=str1[j-i-1];
                    i++;
                    }
                str2[i]='\0';
                printf("Reverse of string:%s",str2);
            break;
            case 5:
            return 0;
            default:
            printf("Enter the valid choice.");
        }
    }
}