/* CS261- Assignment 1 - Q.3*/
/* Name: Kais Saradi    
 * Date:10/15/2019
 * Solution description: A program which takes a string, converts it to the
 * proper from, and passes it to a function which converts it to camelCase
 * It also contains functions to change a character to upper or lower case and
 * find the length of a string
 */

#include <stdio.h>
#include <stdlib.h>

char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
    ch = ch - 32;
    return ch;
}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/                          
    ch = ch + 32;
    return ch;
}

int stringLength(char s[]) {
   /*Return the length of the string*/
   int length = 0;
   for(int i = 0; i < 200; i++){
       if(s[i] != '\0'){
           length += 1;
       }
       if(s[i] == '\0'){
           break;
       }
   }
   return length;
}


void camelCase(char* word){
	/*Convert to camelCase*/
	for(int i = 0; i < 100; i++){
        //check if each letter if a _ and change it to the next uppercase letter
        if(word[i] == '_'){
            word[i] = toUpperCase(word[i + 1]);
            //shift the rest of the string
            for(int j = i; j < stringLength(word); j++){
                word[j + 1] = word[j + 2];
            }
            continue;
        }
        else{
            continue;
        }
    }	
}

int main(){

	/*Read the string from the keyboard*/
    char s[200];
    //check if the string is empty
    while(printf("Please Enter a String (less than 100 characters):\n") && scanf("%[^\n]", s) != 1){
        printf("\nInvalid Input String\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    //check if the string is the right length
    int length = stringLength(s); 
    while(length >= 100){
        printf("\nInvalid Input String\n");
        char s[200] = {0};
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Please Enter a String (less than 100 characters):\n\n");
        scanf("%[^\n]", s);
        length = stringLength(s);
    }
    //check if the string is valid using the requirements
    int firstLetterFlag = 0;
    int secLetterFlag = 0;
    int seperatorFlag = 0;
    int errorFlag = 1;
    char newWord[105] = {0};
    int newWordLength = 0;
    while(errorFlag != 0){
        for(int i = 0; i < 100; i++){
            //if the character is a letter
            if((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123)){
                if(firstLetterFlag == 1 && seperatorFlag == 1 && secLetterFlag == 0){
                    secLetterFlag = 1;
                    seperatorFlag = 0;
                    errorFlag = 0;
                }
                else{
                    firstLetterFlag = 1;
                }

            }
            //if the character is a special character
            if ((s[i] > 31 && s[i] < 65) || (s[i] > 90 && s[i] < 97)){
                if(firstLetterFlag == 1 && seperatorFlag != 1){
                    seperatorFlag = 1;
                }
                if(s[i + 1] == 0){
                    s[i] = '\0';
                    break;
                }
            }
            if(s[i] == '\0'){//if the end of the word is reached
                break;
            }
        }
        if(errorFlag == 1){//check if the string was valid using the error flag
            firstLetterFlag = 0;
            secLetterFlag = 0;
            printf("\nInvalid Input String\n");
            for(int i = 0; i < 105; i++){
                newWord[i] = ' ';
            }
            for(int i = 0; i < 200; i++){
                s[i] = ' ';
            }
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Please Enter a String (less than 100 characters):\n");
            scanf("%[^\n]", s);
            length = stringLength(s);
            newWordLength = 0;
        }
    
    }

    //if the string is valid loop through it again rewriting to a new word that fits the requirements
    //for the camelCase function
    firstLetterFlag = 0;
    secLetterFlag = 0;
    seperatorFlag = 0;
    for(int i = 0; i < 100; i++){
        if((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123)){
            if((s[i] > 64 && s[i] < 91)){
                s[i] = toLowerCase(s[i]);
            }
            if(firstLetterFlag == 1 && seperatorFlag == 1 && secLetterFlag == 0){
                secLetterFlag = 1;
                seperatorFlag = 0;
                errorFlag = 0;
                newWord[newWordLength] = s[i];
                newWordLength += 1;
            }
            else if(firstLetterFlag == 1 && seperatorFlag == 1 && secLetterFlag == 1){
                newWord[newWordLength] = s[i];
                newWordLength += 1;
            }
            else{
                firstLetterFlag = 1;
                newWord[newWordLength] = s[i];
                newWordLength += 1;
            }

        }
        if ((s[i] > 31 && s[i] < 65) || (s[i] > 90 && s[i] < 97))
        {
            if(firstLetterFlag == 1 && seperatorFlag != 1){
                seperatorFlag = 1;
                newWord[newWordLength] = 95;
                newWordLength += 1;
            }
        }
        if(s[i] == '\0'){
            break;
        }
    }

	/*Call camelCase*/
    printf("\nString:\t%s\n\n",s);
    printf("\nConverted word:\t%s\n\n",newWord);
	camelCase(newWord);
	
	/*Print the new string*/
	printf("\nNew string in camelCase:\t%s\n\n",newWord);
	return 0;
}

