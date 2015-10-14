//
//  decrypt.h
//  CMPT300
//
//  Created by Chauncey on 9/23/15.
//  Copyright (c) 2015 Chauncey. All rights reserved.
//
//(1)Name:Chauncey
//(2)Student number:301295771
//(3)SFU user name:cla284
//(4)Lecture section:CMPT 300 D100, Fall 2015
//(5)Instructor's name:Brian Booth
//(6)TA's name clearly labeled:Scott Kristjanson

#ifndef __CMPT300__decrypt__
#define __CMPT300__decrypt__
#define maxLength 180   //the longest length of each line
#define maxLine 20 //the maximum of lines
#include <stdlib.h>
#include <stdio.h>

typedef unsigned long long num;
num PowerMod(num a);  //A fast way to get Mod
char getChar(int a);    //Get char from int
int getNumber(char a);  //Get int from char
void getStringFromFile(char *filePosition,char derivative[maxLength]); //Get string from text file
void stringAfterChop(char *origin,char *derivative);  //Chop every 8 characters
void putStringIntoFile(char *filePosition,char *source); //Put string into file
void divideStringByRows(char* origin,char derivative[10][maxLength]);   //Divide string by rows
void AddUpEvery6CharByHex41(char* source,num *result);  //Get number from string added up with Hex41
void TransferNumberToCharByHex41(num *source,char *derivative); //Translate each number to six char by Hex41
void ModEachNumber(num *source);    //Mod each number
void AppendString(char* Appending,char* Appended);//Append each string to the final String to print

#endif /* defined(__CMPT300__decrypt__) */
