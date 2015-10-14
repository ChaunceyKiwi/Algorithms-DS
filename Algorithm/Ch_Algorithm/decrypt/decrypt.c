//
//  decrypt.c
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

#include "decrypt.h"

/*A fast way to get Mod*/
num PowerMod(num a)
{
    num ans = 1;
    num b = 1921821779;
    num c = 4294434817;
    a = a % c;
    while(b>0) {
        if(b % 2 == 1)
            ans = (ans * a) % c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}

/*Mod each number*/
void ModEachNumber(num *source)
{
    int i = 0;
    while(source[i] != 0)
    {
        source[i] = PowerMod(source[i]);
        i++;
    }
    source[i] = 0;
}

/*Get int from char */
int getNumber(char a)
{
    if (a == ' ')
        return 0;
    else if (a >= 'a'&&a <='z')
        return a - 96;
    else if (a == '#')
        return 27;
    else if (a == '.')
        return 28;
    else if (a == ',')
        return 29;
    else if (a == 39)
        return 30;
    else if (a == '!')
        return 31;
    else if (a == '?')
        return 32;
    else if (a == '(')
        return 33;
    else if (a == ')')
        return 34;
    else if (a == '-')
        return 35;
    else if (a == ':')
        return 36;
    else if (a == '$')
        return 37;
    else if (a == '/')
        return 38;
    else if (a == '&')
        return 39;
    else if (a == 92)
        return 40;
    else
        return 0;
}

/*Get char from int*/
char getChar(int a)
{
    if(a == 0)
        return ' ';
    else if(a >= 1 &&a <= 26)
        return 'a'+ a - 1;
    else if (a == 27)
        return '#' ;
    else if (a == 28)
        return '.';
    else if (a == 29)
        return ',';
    else if (a == 30)
        return 39;
    else if (a == 31)
        return '!';
    else if (a == 32)
        return '?';
    else if (a == 33)
        return '(';
    else if (a == 34)
        return ')';
    else if (a == 35)
        return '-';
    else if (a == 36)
        return ':';
    else if (a == 37)
        return '$';
    else if (a == 38)
        return '/';
    else if (a == 39)
        return '&';
    else if (a == 40)
        return 92;
    else return 0;
}

/*Chop every 8 characters*/
void stringAfterChop(char *origin,char *derivative)
{
    int i = 0,j = 0;
    
    while (origin[i] != '\0')
    {
        if((i + 1) % 8 != 0 )
        {
            derivative[j] = origin[i];
            j++;
        }
        i++;
    }
    
    derivative[j]='\0';
}

/*Get string from text file*/
void getStringFromFile(char *filePosition,char *derivative)
{
    int i = 0;
    FILE *fp;
    
    if((fp = fopen(filePosition, "r")) == NULL)
    {
        printf("fail to open\n");
    }
    
    while( ( derivative[i] = fgetc(fp) ) != EOF )
    {
        i++;
    }
    
    derivative[i] = '\n';
    derivative[i+1] = '\0';
    
    fclose(fp);
}

/*Put string into file*/
void putStringIntoFile(char *filePosition,char *source)
{
    int i = 0;
    FILE *fp;
    
    if((fp = fopen(filePosition, "w")) == NULL)
    {
        printf("fail to open\n");
    }
    
    while(source[i] != '\0')
    {
        fputc(source[i],fp);
        i++;
    }
    
    fclose(fp);
}

/*Divide string by rows*/
void divideStringByRows(char* origin,char derivative[10][maxLength])
{
    int i = 0,j = 0,k = 0;
    
    while(origin[i] != '\0')
    {
        while(origin[i]!='\n')
        {
            derivative[j][k] = origin[i];
            k++;
            i++;
        }
        derivative[j][k] = '\0';
        k = 0;
        j++;
        i++;
    }
}

/*Get number from string added up with Hex41*/
void AddUpEvery6CharByHex41(char* source,num *result)
{
    int i = 0,x = 0,j = 0;
    
    
    while(source[i] != '\0')
    {
        result[x] = 0;
        for(j = i;j <= i+5 ;j++)
        {
            result[x] = result[x] * 41;
            result[x] += getNumber(source[j]);
        }
        x++;
        i = i + 6;
    }
    
    result[x] = 0;
}

/*Translate each number to six chars by Hex41*/
void TransferNumberToCharByHex41(num *source,char *derivative)
{
    num temp;
    int x = 0,i = 0;
    
    while(source[x] != 0)
    {
        temp = source[x];
        num Hex41 = 115856201;
        
        while(Hex41 > 0)
        {
            derivative[i] = temp / Hex41; //41^5
            temp = temp - (unsigned long long)derivative[i] * Hex41;
            
            derivative[i] = getChar((derivative[i]));
            
            Hex41 = Hex41 / 41;
            i++;
            
        }
        x++;
    }
    
    derivative[i] = '\0';
}

/*Append each string to the final String to print*/
void AppendString(char* Appending,char* Appended)
{
    int i = 0;
    int j = 0;
    
    while(Appended[j] != '\0')
    {
        j++;
    }
    
    while(Appending[i] != '\0')
    {
        Appended[j] = Appending[i];
        i++;
        j++;
    }
    
    Appended[j] = '\n';
    Appended[j+1] = '\0';
    
}