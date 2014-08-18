/*
    Copyright 2014 Matthew Fosdick

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#pragma once
#include <stddef.h>
#include <stdint.h>
/**
 * @file
 * @brief C style string functions
 * @details most string functions in <string.h>
 * along with UTF-8 variants and safe copy functions
 */
#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////
// Copies 'num' bytes from 'src' to   //
//   'dest'                           //
// Returns 'dest'                     //
// Created on 2014-06-13              //
////////////////////////////////////////
/**
 * @brief copies memory
 * @details using a left-to-right copy,
 * copy \a num bytes from \a src to \a
 * dest
 * 
 * @param dest pointer to a block of memory at least
 * \a num bytes big, MUST NOT overlap with \a src
 * @param src pointer to a block of memory at least
 * \a num bytes big, MUST NOT overlap with \a dest
 * @param num number of bytes to copy from \a src to \a dest
 * 
 * @return a pointer equal to \a dest
 * @date created on 2014-06-13
 * @sa memmove
 */
void *memcpy(void *dest, const void *src, size_t num);

/**
 * @brief copies potentially overlapping memory
 * @details using a left-to-right or right-to-left copy,
 * copy \a num bytes from \a src to \a
 * dest safely
 * 
 * @param dest pointer to a block of memory at least
 * \a num bytes big, MAY overlap with \a src
 * @param src pointer to a block of memory at least
 * \a num bytes big, MAY overlap with \a dest
 * @param num number of bytes to copy from \a src to \a dest
 * 
 * @return pointer equal to \a dest
 * @date created on 2014-06-13
 * @sa memcpy
 */
void *memmove(void *dest, const void *src, size_t num);

/**
 * @brief copies chars from \a src to \a dest
 * @details copies chars from \a src to \a dest
 * stopping the copy when a NULL byte is found
 * 
 * @param dest pointer to buffer of memory
 * @param src pointer to a string of UTF-8 chars
 * 
 * @return pointer equal to \a dest
 * @date created on 2014-06-13
 * @sa strncpy
 * @sa strlcpy
 * @sa mbsncpy
 */
char *strcpy(char *dest, const char *src);

/**
 * @brief copies \a num bytes from \a src to \a dest
 * @details copies \a num bytes from \a src to \a dest
 * if a NULL byte is found when copying, then the rest
 * of \dest is filled with NULL bytes
 * 
 * @note this function DOES NOT guarantee that \a dest
 * will end with a NULL byte
 * 
 * @param dest pointer to a buf of memory at least \a num bytes big
 * @param src pointer to a string of UTF-8 chars
 * @param num number of bytes to fill \a dest with
 * 
 * @return pointer equal to \a dest
 * @date created on 2014-06-13
 * @sa strcpy
 * @sa strlcpy
 * @sa mbsncpy
 */
char *strncpy(char *dest, const char *src, size_t num);

/**
 * @brief copies upto \a num bytes from \a src to \a dest
 * @details copies upto \a num bytes from \a src to \dest
 * if a NULL byte is found when coping, then the rest of
 * \a dest will be filled with NULL bytes. If the number
 * of bytes remaining to copy is less then the length of
 * the current char plus 1, then the current char is not
 * copied and the rest of \a dest is filled with NULL bytes
 * 
 * @note this function DOES guarantee that \a dest
 * will end with a NULL byte    
 * 
 * @param dest pointer to a block of memory at least \a num
 * bytes big
 * @param src pointer to a string of UTF-8 chars
 * @param num number of bytes to fill \a dest with
 * 
 * @return pointer equal to \a dest
 * @date created on 2014-06-13
 * @sa strcpy
 * @sa strncpy
 * @sa mbsncpy
 */
char *strlcpy(char *dest, const char *src, size_t num);

////////////////////////////////////////
// Copies 'num' bytes from 'src' to   //
//   'dest' if a null byte is found   //
//   in 'src', the rest of 'dest' is  //
//   appended with null bytes, does   //
//   not break apart multi-byte chars //
// Returns 'dest'                     //
// Created on 2014-06-13              //
////////////////////////////////////////
char *mbsncpy(char *dest, const char *src, size_t num);

////////////////////////////////////////
// Appends chars from 'src' onto the  //
//   end of 'dest', and a null byte   //
// Returns 'dest'                     //
// Created on 2014-05-30              //
////////////////////////////////////////
char *strcat(char *dest, const char *src);

////////////////////////////////////////
// Appends the first 'num' bytes from //
//   'src' onto the end of 'dest' and //
//   a terminating null byte          //
// Returns 'dest'                     //
// Created on 2014-06-13              //
////////////////////////////////////////
char *strncat(char *dest, const char *src, size_t num);

////////////////////////////////////////
// Appends the first 'num' bytes from //
//   'src' onto the end of 'dest' and //
//   a terminating null byte, does    //
//   not break apart multi-byte chars //
// Returns 'dest'                     //
// Created on 2014-06-13              //
////////////////////////////////////////
char *strlcat(char *dest, const char *src, size_t num);

////////////////////////////////////////
// Compares the first 'num' bytes of  //
//   'ptr1' and 'ptr2'                //
// Returns 0 if equal, or the         //
//   difference of the non-equal byte //
//   otherwise                        //
// Created on 2014-05-30              //
////////////////////////////////////////
int memcmp(const void *ptr1, const void *ptr2, size_t num);

////////////////////////////////////////
// Compares each byte of 'str1' and   //
//   'str2', stopping at a null byte  //
// Returns 0 if equal, or the         //
//   difference of the non-equal byte //
//   otherwise                        //
// Created on 2014-05-30              //
////////////////////////////////////////
int strcmp(const char *str1, const char *str2);

////////////////////////////////////////
// Compares each char of 'str1' and   //
//   'str2', stopping at a null byte  //
// Returns 0 if equal, or the         //
//   difference of the codepoints of  //
//   the non-equal char otherwise     //
// Created on 2014-07-06              //
////////////////////////////////////////
int mbscmp(const char *str1, const char *str2);

////////////////////////////////////////
// Compares up to 'num' bytes in      //
//   'str1' and 'str2', stopping if a //
//   null byte is found               //
// Returns 0 if equal, or the         //
//   difference of the non-equal byte //
//   otherwise                        //
// Created on 2014-05-30              //
////////////////////////////////////////
int strncmp(const char *str1, const char *str2, size_t num);

////////////////////////////////////////
// Compares up to 'num' bytes in      //
//   'str1' and 'str2' using          //
//   codepoints, stopping if a null   //
//   byte is found                    //
// Returns 0 if equal, or the         //
//   difference of the codepoints of  //
//   the non-equal char otherwise     //
// Created on 2014-05-30              //
////////////////////////////////////////
int mbsncmp(const char *str1, const char *str2, size_t num); //WORKS

////////////////////////////////////////
// Searches between 'ptr' and 'num'   //
//   for a byte with the value of     //
//   'value'                          //
// Returns a pointer between 'ptr'    //
//   and 'num' or NULL                //
// Created on 2014-05-30              //
////////////////////////////////////////
void *memchr(const void *ptr, int value, size_t num);

////////////////////////////////////////
// Searches in 'str' for a byte with  //
//   the value of 'value'             //
// Returns a pointer to the first     //
//   byte that matches or NULL        //
// Created on 2014-05-30              //
////////////////////////////////////////
char *strchr(const char *str, int value);

////////////////////////////////////////
// Searches in 'str' for a char with  //
//   the value of 'value'             //
// Returns a pointer to the first     //
//   char that matches or NULL        //
// Created on 2014-07-06              //
////////////////////////////////////////
char *mbschr(const char *str, const char *value);

////////////////////////////////////////
// Searches 'str' for any bytes in    //
//   'bytes'                          //
// Returns the number of bytes before //
//   the first match, or the length   //
//   in bytes of the string in 'str'  //
// Created on 2014-05-30              //
////////////////////////////////////////
size_t strcspn(const char *str, const char *bytes);

////////////////////////////////////////
// Searches 'str' for any chars in    //
//   'chars'                          //
// Returns the number of chars before //
//   the first match, or the number   //
//   of chars in the string in 'str'  //
// Created on 2014-07-06              //
////////////////////////////////////////
size_t mbscspn(const char *str, const char *chars);

////////////////////////////////////////
// Searches 'str' for any bytes in    //
//   'bytes'                          //
// Returns a pointer to the first     //
//   byte that matches, or NULL       //
// Created on 2014-05-30              //
////////////////////////////////////////
char *strpbrk(const char *str1, const char *bytes);

////////////////////////////////////////
// Searches 'str' for any chars in    //
//   'chars'                          //
// Returns a pointer to the first     //
//   char that matches, or NULL       //
// Created on 2014-07-06              //
////////////////////////////////////////
char *mbspbrk(const char *str1, const char *chars);

////////////////////////////////////////
// Searches in 'str' for a byte with  //
//   the value of 'value'             //
// Returns a pointer to the last      //
//   byte that matches or NULL        //
// Created on 2014-05-30              //
////////////////////////////////////////
char *strrchr(const char *str1, int value);

////////////////////////////////////////
// Searches in 'str' for a char with  //
//   the value of 'value'             //
// Returns a pointer to the last      //
//   char that matches or NULL        //
// Created on 2014-07-06              //
////////////////////////////////////////
char *mbsrchr(const char *str1, const char *value);

////////////////////////////////////////
// Searches 'str' for any bytes in    //
//   'bytes'                          //
// Returns length of initial portion  //
//   that contains all the bytes in   //
//   'bytes'                          //
// Created on 2014-05-30              //
////////////////////////////////////////
size_t strspn(const char *str, const char *bytes);

////////////////////////////////////////
// Searches 'str' for any chars in    //
//   'chars'                          //
// Returns number of chars in initial //
//   portion that contains all the    //
//   chars in 'chars'                 //
// Created on 2014-05-30              //
////////////////////////////////////////
size_t mbsspn(const char *str, const char *chars);

////////////////////////////////////////
// Searches 'str1' for all bytes in   //
//   'str2'                           //
// Returns pointer to the first       //
//   portion of 'str1' that matches   //
//   all the bytes in 'str2' except   //
//   the null byte                    //
// Created on 2014-05-30              //
////////////////////////////////////////
char *strstr(char *str1, const char *str2);

////////////////////////////////////////
// Searches 'str1' for all chars in   //
//   'str2'                           //
// Returns pointer to the first       //
//   portion of 'str1' that matches   //
//   all the chars in 'str2'          //
// Created on 2014-07-06              //
////////////////////////////////////////
char *mbsstr(char *str1, const char *str2);

////////////////////////////////////////
// TODO                               //
// Returns TODO                       //
// Created on 2014-05-31              //
////////////////////////////////////////
char *strtok(char *str, const char *delim);

////////////////////////////////////////
// TODO                               //
// Returns TODO                       //
// Created on 2014-07-06              //
////////////////////////////////////////
char *mbstok(char *str, const char *delim);

////////////////////////////////////////
// Sets 'num' bytes, starting from    //
//   'ptr', to 'value'                //
// Returns 'ptr'                      //
// Created on 2014-05-31              //
////////////////////////////////////////
void *memset(void *ptr,int value,size_t num);

////////////////////////////////////////
// Sets 'num' words, starting from    //
//   'ptr', to 'value'                //
// Returns 'ptr'                      //
// Created on 2014-05-31              //
////////////////////////////////////////
void *memset16(uint16_t *ptr,uint16_t value,size_t num);

////////////////////////////////////////
// Sets 'num' dwords, starting from   //
//   'ptr', to 'value'                //
// Returns 'ptr'                      //
// Created on 2014-05-31              //
////////////////////////////////////////
void *memset32(uint32_t *ptr,uint32_t value,size_t num);

////////////////////////////////////////
// Sets 'num' qwords, starting from   //
//   'ptr', to 'value'                //
// Returns 'ptr'                      //
// Created on 2014-05-31              //
////////////////////////////////////////
void *memset64(uint64_t *ptr,uint64_t value,size_t num);


////////////////////////////////////////
// Counts the number of bytes in      //
//   'str'                            //
// Returns the count                  //
// Created on 2014-05-31              //
////////////////////////////////////////
size_t strlen(const char *str);

////////////////////////////////////////
// Counts the number of chars in      //
//   'str'                            //
// Returns the count                  //
// Created on 2014-05-31              //
////////////////////////////////////////
size_t mbslen(const char *str);
#ifdef __cplusplus
}
#endif