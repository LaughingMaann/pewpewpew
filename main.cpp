#include <iostream>
#include <string>
#include <map>
#define maxLength (6)
using namespace std;

int isLen(int n){
    int remain = n;
    int digit = 0;
    int count = 0 ;
    while(remain != 0){
        digit = remain % 10 ;
        remain = remain/10;
        //printf("remain %i, digit %i\n", remain, digit);
        count++;
    }
    return count;
}

int isOrdered(int n ){
    int orderTrue = 0 ;
    int size = isLen(n);
    int arr[size]; // array of sliced integer digits, len=6
    int orderedCount = 0; // holder, there will be 5 comparison size-1, from n0 -> n5
    // (n0, n1) (n1, n2) (n2, n3) (n3, n4) (n4 vs n5)
    // ^1st chek  ^2nd   etc.. utnil 5th
    // should be valid <= so total is 5 ordered counts
    int sameCount = 0 ; // holder, for at least 1 equivalent adjacent tuple
    
    if (size != maxLength) {orderTrue = 0;}
    
    for (int i  = size-1 ; i >= 0 ; i--){ // build the array, start at the end to match last digit
        arr[i] = n %10;
        n = n/10;
        //printf("arr[%i] is %i\n", i, arr[i]);
    }
    for (int i = 0 ; i < size-1 ; i++){ //check check mic check one two
        if (arr[i] <= arr[i+1])  { ++orderedCount; } // only if the previous value is less OR equal to next valu
        if (arr[i] == arr[i+1]) {++sameCount; } // need at least 1
        //printf("n[%i] is  n+1[%i]\n", arr[i], arr[i+1]);
    }
    if (orderedCount == 5 && sameCount > 0){
        orderTrue = 1;
    }
    else
        orderTrue = 0;
    //printf("len count is [%i]\n", lenCount );
    //printf("count of same adjacent [%i]\n", sameCount );
    return orderTrue;
}

bool isOrdered_2(int n){
    bool ret= 0;
    int size = isLen(n);
    //printf("length is  %i\n", size);
    if (size!=6) {  return 0;}
    int arr[size]; // array of sliced integer digits, len=6
    
    for (int i  = size-1 ; i >= 0 ; i--){ // build the array, start at the end to match last digit
        arr[i] = n %10;
        n = n/10;
        //printf("arr[%i] is %i\n", i, arr[i]);
    }
    
    for (int i = 0 ; i < maxLength  ; i ++){
        if (arr[i] > arr[i+1])  {  return 0; }
    }

    int matchCount = 0;
    int theMatch = 0;
    int isDouble = 0;
    int tuple[3]={0,0,0};
    for (int i  = 0 ;  i < maxLength   ; i ++){ // n^2 inefficient :/
        printf("outer, a[i=%i]:  %i\n",i, arr[i]);
        for (int k  = 0 ;  k < maxLength   ; k ++){
            printf("in, a[k=%i]:  %i\n", k, arr[k]);
            if ((i < k) && (arr[i]==arr[k]) && (i==k-1)){
                theMatch = arr[k];
                matchCount++;
                //isDouble++;
                if ( matchCount == 1 ) {
                    tuple[isDouble] = theMatch; // isDouble is 0 1st
                    printf("WHAT IS HAENINDIGNISDN IN ARRY TUPLE %i\n", tuple[isDouble]);
                    //++isDouble;
                    printf("matching: [i=%i is %i] [k=%i is %i]-> isMatching %i, isDouble %i\n", i, arr[i],k, arr[k], matchCount, isDouble);
                    printf("THEE match: %i\n", theMatch); // now it's 1
                    printf("FUCK IN ARRAY b4 appending %i\n", tuple[isDouble]); // now it's 1
                } //if match, save the matching wurd
            }
            if ( (matchCount> 1) && (theMatch != tuple[isDouble ])) {
                printf("NOT thee match %i\n", theMatch); // now it's 1
                printf("NOT IN ARRAY b4 appending %i\n", tuple[isDouble]); // now it's 1
                ++isDouble;
                tuple[isDouble] = theMatch; // isDouble is 0 1st
                printf("not matching: [i=%i is %i] [k= is %i]-> isMatching %i, isDouble %i\n", i, arr[i], theMatch, matchCount, isDouble);
                for (int i = 0 ; i < 3 ; i++){
                    printf("WHAT IS HAENINDIGNISDN IN ARRY TUPLE %i\n", tuple[i]);
                }
            }
            if ( (matchCount> 1) && (theMatch == tuple[isDouble ])) {
                //tuple[1] = 0;
                printf("IS matching: [i=%i is %i] [k= is %i]-> isMatching %i, isDouble %i\n", i, arr[i], theMatch, matchCount, isDouble);
            }
        }
        
    }
        
    for (int i = 0 ; i < 3 ; i++){
        //printf("WHAT IS HAENINDIGNISDN IN ARRY TUPLE %i\n", tuple[isDouble]);
        if(tuple[i] >0) {ret = 1;}
        else ret=0;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    //int n = 111122;
    //int n = 112233;
    int n = 114444;
    //int n = 111444;
    //int n = 123456;
    int validCount = 0; // part 1, unique psswrds within the ranges
    int validCountTheRevenge = 0; // part 2, unique psswrds within the ranges
    int min = 265275;
    int max = 781584;
    /*
    for (int i = min ; i <= max ; i++){
        int orderTrue = isOrdered(i);
        int validCountTheRevenge = isOrdered_2(to_string(i));
        validCount = validCount + orderTrue;
    }
    */
    validCount = isOrdered( n );
    validCountTheRevenge = isOrdered_2( n );
    
    printf("1st part  %i\n", validCount);
    printf("2nd part  %i\n", validCountTheRevenge);
    return 0;
}
