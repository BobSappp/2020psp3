#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start=0, pos=0,i,key_len;
    
    for(i=0;key[i]!='\0';i++){
        key_len = i;
    }
while(text[pos+start]!='\0'){
    if(text[start+pos]==key[pos]){
        pos++;
        if(pos=key_len+1){
            return(&text[start]);
            break;
        }
    }else{
        pos=0;
        start++;

    }
    }
    if(text[pos+start]=='\0'){
        return(NULL);
    }
}


char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int key_len=0,text_len=0;
    int i,zurashi,a,b,table[255];
    for(i=0;key[i]!='\0';i++){
        text_len = i;
    }

    for(i=0;key[i]!='\0';i++){
        key_len = i;
    }
//key_len=3?
    for(i=0;key[i]<=255;i++){
        table[i]=key_len+1;
    }

    for(i=0;key[i]!='\0';i++){
        table[(unsigned char)key[i]]=key_len-i;
    }
    
    for(i=key_len;i<=text_len;i=a+zurashi){
        for(a=i;a>=a-key_len;a--){
            if(text[a]==key[key_len-b]){
                b++;
                if(b==key_len+1){
                    return(&text[i-key_len]);

                }
                else{
                    b=0;
                    zurashi=table[(unsigned char)text[a]];
                    if(a+zurashi<=i){
                        zurashi=i+1-a;
                    }
                    break;
                }

            }
        }
    }    
    return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}