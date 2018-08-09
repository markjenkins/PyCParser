#include <stdio.h>

#define NUM_TEST_SINGLE_CHAR 19
char test_single_char[NUM_TEST_SINGLE_CHAR] = {
  '\0',  // octal
  '\00', // octal
  '\000',// octal
  '\x0', // hex
  '\x00',// hex
  
  '\1',  // octal
  '\01', // octal
  '\001',// octal
  '\x1', // hex
  '\x01',// hex

  '\t',
  '\11', // octal
  '\011',// octal
  '\x9', // hex
  '\x09',// hex

  'z',
  '\172',// octal
  '\x7a',// hex
  '\x7A',// hex
};


#define NUM_TEST_STR_SINGLE_CHAR 19
char * test_str_single_char[NUM_TEST_STR_SINGLE_CHAR] = {
  "\0",  // octal
  "\00", // octal
  "\000",// octal
  "\x0", // hex
  "\x00",// hex
  
  "\1",  // octal
  "\01", // octal
  "\001",// octal
  "\x1", // hex
  "\x01",// hex

  "\t",
  "\11", // octal
  "\011",// octal
  "\x9", // hex
  "\x09",// hex

  "z",
  "\172",// octal
  "\x7a",// hex
  "\x7A",// hex
};

#define NUM_TEST_STR_MULTI_CHAR 13
char * test_str_multi_char[] = {
  "Tab\tGap",
  "Tab\11Gap",       // octal
  "Tab\011Gap",      // octal
  "Tab\x9Gap",       // hex, barely works as G is not a hex character
  "Tab\x9" "Gap",    // hex, but more clear and less scary
  "Tab\x09Gap", // hex, two characters
  "Tab\x9" "animals", // hex, restarting the quoting a nescesity
  "zzzAre sleepy time",
  "z\x7a\x7A" "Are sleepy time", // nescessary restarting of quoting
  "z z z Are sleepy time",
  "\172 \x7a \x7A Are sleepy time", // no restart of quoting required
  "time for zzzz",
  "time for \x7a\172\x7Az",
};

int main(){
  int i=0;
  for (i=0; i<NUM_TEST_SINGLE_CHAR; i++){
    // print single in quotes with trailing new line
    // \x for hex and %.2x to print in 2 digit hex format
    printf("'\\x%.2x'\n", test_single_char[i]);
  }
  printf("\n");
  for (i=0; i<NUM_TEST_STR_SINGLE_CHAR; i++){
    // print in double quotes with trailing new line
    // \x for hex and %.2x to print in 2 digit hex format
    printf("\"\\x%.2x\"\n", *test_str_single_char[i]);
  }
  printf("\n");
  
  for (i=0; i<NUM_TEST_STR_MULTI_CHAR; i++){
    printf("%s\n", test_str_multi_char[i]);
  }
  
  return 0;
}
