#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SHORT 1
#define LONG 2
#define MAX_LETTER_LENGTH 2000

const char* sals1[] = {"Beloved", "Darling", "Dear", "Dearest", "Fanciful", "Honey"};
const char* sals2[] = {"Chickpea", "Dear", "Duck", "Jewel", "Love", "Moppet", "Sweetheart"};

const char* adjs[] = {"affectionate", "amorous", "anxious", "avid", "beautiful", "breathless", 
    "burning", "covetous", "craving", "curious", "eager", "fervent", "fondest", "loveable", 
    "lovesick", "loving", "passionate", "precious", "seductive", "sweet", "sympathetic", 
    "tender", "unsatisfied", "winning", "wistful"};

const char* nouns[] = {"adoration", "affection", "ambition", "appetite", "ardour", "being", 
    "burning", "charm", "craving", "desire", "devotion", "eagerness", "enchantment", 
    "enthusiasm", "fancy", "fellow feeling", "fervour", "fondness", "heart", "hunger", 
    "infatuation", "little liking", "longing", "love", "lust", "passion", "rapture", 
    "sympathy", "thirst", "wish", "yearning"};

const char* advs[] = {"affectionately", "ardently", "anxiously", "beautifully", "burningly", 
    "covetously", "curiously", "eagerly", "fervently", "fondly", "impatiently", "keenly", 
    "lovingly", "passionately", "seductively", "tenderly", "wistfully"};

const char* verbs[] = {"adores", "attracts", "clings to", "holds dear", "hopes for", 
    "hungers for", "likes", "longs for", "loves", "lusts after", "pants for", "pines for", 
    "sighs for", "tempts", "thirsts for", "treasures", "yearns for", "woos"};

const char* random_from_array(const char* arr[], int size) {
    return arr[rand() % size];
}

int main() {
    srand(time(NULL));
    
    char letter[MAX_LETTER_LENGTH] = "";
    int last = 0;
    
    sprintf(letter, "Christopher Strachey \"Loveletters\" (1952)\n\n%s %s,\n     ", 
            random_from_array(sals1, 6), random_from_array(sals2, 7));
    
    for (int i = 0; i < 5; i++) {
        char segment[500] = "";
        
        if (rand() % 10 < 5) {
            const char* optadj1 = (rand() % 10 < 5) ? "" : random_from_array(adjs, 25);
            const char* noun1 = random_from_array(nouns, 31);
            const char* optadv = (rand() % 10 < 5) ? "" : random_from_array(advs, 17);
            const char* verb = random_from_array(verbs, 18);
            const char* optadj2 = (rand() % 10 < 5) ? "" : random_from_array(adjs, 25);
            const char* noun2 = random_from_array(nouns, 31);
            
            const char* concat = (last != 0 || last == LONG) ? ". " : "";
            
            if (strlen(optadj1) > 0 && strlen(optadj2) > 0 && strlen(optadv) > 0) {
                sprintf(segment, "%sMy %s %s %s %s your %s %s", 
                        concat, optadj1, noun1, optadv, verb, optadj2, noun2);
            } else if (strlen(optadj1) > 0 && strlen(optadj2) > 0) {
                sprintf(segment, "%sMy %s %s %s your %s %s", 
                        concat, optadj1, noun1, verb, optadj2, noun2);
            } else if (strlen(optadv) > 0) {
                sprintf(segment, "%sMy %s %s %s your %s", 
                        concat, noun1, optadv, verb, noun2);
            } else {
                sprintf(segment, "%sMy %s %s your %s", 
                        concat, noun1, verb, noun2);
            }
            
            last = LONG;
        } else {
            const char* adj = random_from_array(adjs, 25);
            const char* noun = random_from_array(nouns, 31);
            const char* concat;
            
            if (last == SHORT) {
                concat = ", ";
            } else if (last == LONG) {
                concat = ". You are";
            } else {
                concat = "You are ";
            }
            
            sprintf(segment, "%s my %s %s", concat, adj, noun);
            last = SHORT;
        }
        
        strcat(letter, segment);
    }
    
    const char* adv = random_from_array(advs, 17);
    char ending[100];
    sprintf(ending, ".\n     Yours %s,\n     M.U.C.\n", adv);
    strcat(letter, ending);
    
    printf("%s", letter);
    
    return 0;
}