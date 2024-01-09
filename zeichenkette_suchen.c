#include <stdio.h>

int laenge(char *text) {
    int laenge;
    for(laenge=0;text[laenge] != 0;laenge++) {}
    
    return laenge;
}

int suche_text(char *text, char *suchwort) {
    int textLen = laenge(text);
    int suchwortLen = laenge(suchwort);
    int treffer = 0;
    int pos1;
    
    for(pos1=0;(pos1 < (textLen - suchwortLen)) && (treffer != suchwortLen);pos1++) {
        treffer = 0;
        for(int index=0;index < suchwortLen;index++) {
            treffer += (text[pos1+index] == suchwort[index]?1:0);
        }
    }
    
    return (treffer==suchwortLen?pos1-1:-1);
}

void zeige_syntax(char *name) {
    printf("Syntax:\n");
    printf("   %s <haystack> <needle>\n",name);
    printf("     haystack : string where to search in\n");
    printf("     needle   : string to search for\n");
}

int main(int argc, char *argv[])
{
    printf("Serch a string in a string\n");
    printf("%s\n",argv[0]);
    
    printf("erwartet=6 ermittelt=%d\n", suche_text("Hallo Welt!", "Welt"));
    printf("erwartet=-1 ermittelt=%d\n", suche_text("Hallo Welt!", "Test"));

    return 0;
}
