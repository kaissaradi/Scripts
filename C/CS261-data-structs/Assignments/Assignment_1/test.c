/* CS261- Assignment 1 - Q.3*/
/* Name: 
 * Date: 
 * Solution description:
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

	for(int i = 0; i < stringLength(word); i++){
        if(word[i] == '_'){
            word[i + 1] = toUpperCase(word[i + 1]);
            for(i; i < stringLength(word); i++){
                word[i] = word[i + 1];
            }
        }
    }	
}

int main(){

	/*Read the string from the keyboard*/
	char s;
    char word[200];
    //check if the string is empty
    while(printf("Please Enter a String (less than 100 characters):\n") && scanf("%[^\n]", word) != 1){
        printf("\nInvalid Input String\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    //check if the string is the right length
    int length = stringLength(word); 
    while(length >= 100){
        printf("\nInvalid Input String\n");
        char word[200] = {0};
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Please Enter a String (less than 100 characters):\n");
        scanf("%[^\n]", word);
        length = stringLength(word);
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
            if((word[i] > 64 && word[i] < 91) || (word[i] > 96 && word[i] < 123)){
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
            if ((word[i] > 31 && word[i] < 65) || (word[i] > 90 && word[i] < 97)){
                if(firstLetterFlag == 1 && seperatorFlag != 1){
                    seperatorFlag = 1;
                }
            }
            if(word[i] == '\0'){//if the end of the word is reached
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
                word[i] = ' ';
            }
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Please Enter a String (less than 100 characters):\n");
            scanf("%[^\n]", word);
            length = stringLength(word);
            newWordLength = 0;
        }
    
    }

    //if the string is valid loop through it again rewriting to a new word that fits the requirements
    //for the camelCase function
    firstLetterFlag = 0;
    secLetterFlag = 0;
    seperatorFlag = 0;
    for(int i = 0; i < 100; i++){
        if((word[i] > 64 && word[i] < 91) || (word[i] > 96 && word[i] < 123)){
            if((word[i] > 64 && word[i] < 91)){
                word[i] = toLowerCase(word[i]);
            }
            if(firstLetterFlag == 1 && seperatorFlag == 1 && secLetterFlag == 0){
                secLetterFlag = 1;
                seperatorFlag = 0;
                errorFlag = 0;
                newWord[newWordLength] = word[i];
                newWordLength += 1;
            }
            else if(firstLetterFlag == 1 && seperatorFlag == 1 && secLetterFlag == 1){
                newWord[newWordLength] = word[i];
                newWordLength += 1;
            }
            else{
                firstLetterFlag = 1;
                newWord[newWordLength] = word[i];
                newWordLength += 1;
            }

        }
        if ((word[i] > 31 && word[i] < 65) || (word[i] > 90 && word[i] < 97))
        {
            if(firstLetterFlag == 1 && seperatorFlag != 1){
                seperatorFlag = 1;
                newWord[newWordLength] = 95;
                newWordLength += 1;
            }
        }
        if(word[i] == '\0'){
            break;
        }
    }

	/*Call camelCase*/
	camelCase(newWord);
	
	/*Print the new string*/
	printf("\nNew string in camelCase:%s\n\n",newWord);
	return 0;
}
