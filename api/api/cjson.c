/**
 * @file cjson.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include "cjson.h"

#define ADD_CJSON_UINT      "%c %s : %u \r\n "
#define ADD_CJSON_INT       "%c %s : %d \r\n "
#define ADD_CJSON_FLOAT     "%c %s : %.2f \r\n "
#define ADD_CJSON_STRING    "%c %s : %s \r\n "
#define INIT_CONTENT       "\r\n{ }" 
#define INIT_LEN            6


cjson_t* cjson_create(uint32_t len)
{


    cjson_t* cjson = (cjson_t*) malloc(sizeof(cjson_t));

    if(cjson == NULL) return NULL;

   
    cjson->p_string = (char*) malloc(sizeof(char)*len);
    if (cjson->p_string == NULL) return NULL;
    cjson->len = len;
    cjson->index=0;
    strcpy(cjson->p_string,INIT_CONTENT);   //INIT_LEN
    cjson->index = strlen(cjson->p_string);
    return cjson;
}


uint8_t cjson_add_int(cjson_t* cjson,char* key, int32_t element)
{
    uint8_t ret = 0;
    uint32_t index = cjson->index;

    char b_element[50];

    sprintf(b_element,ADD_CJSON_INT,((cjson->index<INIT_LEN)?'\n':','),key,element);
    uint32_t len_element = strlen(b_element);
    // si el tamanio del buffer puede contener el nuevo elemento, lo agrego

    if ((index + len_element) <= (cjson->len))   
    {
        sprintf(&(cjson->p_string[index-1])," %s",b_element); // agrego el nuevo elemento
        cjson->index = strlen(cjson->p_string);
        ret = 1;
    }

    return ret;
}



uint8_t cjson_add_uint(cjson_t* cjson,char* key, uint32_t element)
{
    uint8_t ret = 0;
    uint32_t index = cjson->index;

    char b_element[50];

    sprintf(b_element,ADD_CJSON_UINT,((cjson->index<INIT_LEN)?'\n':','),key,element);
    uint32_t len_element = strlen(b_element);
    // si el tamanio del buffer puede contener el nuevo elemento, lo agrego

    if ((index + len_element) <= (cjson->len))   
    {
        sprintf(&(cjson->p_string[index-1])," %s",b_element); // agrego el nuevo elemento
        cjson->index = strlen(cjson->p_string);
        ret = 1;
    }

    return ret;
}

uint8_t cjson_add_float(cjson_t* cjson,char* key, float element)
{
   
    uint8_t ret = 0;
    uint32_t index = cjson->index;

    char b_element[100];

    sprintf(b_element, ADD_CJSON_FLOAT,((cjson->index<INIT_LEN)?'\n':','),key,element);
    uint32_t len_element = strlen(b_element);
    // si el tamanio del buffer puede contener el nuevo elemento, lo agrego

    if ((index + len_element) <= (cjson->len))   
    {
        sprintf(&(cjson->p_string[index-1])," %s",b_element); // agrego el nuevo elemento
        cjson->index = strlen(cjson->p_string);
        ret = 1;
    }

    return ret;



}

uint8_t cjson_add_string(cjson_t* cjson,char* key, char* element)
{

    uint8_t ret = 0;
    uint32_t index = cjson->index;

    char b_element[100];

    sprintf(b_element, ADD_CJSON_STRING,(((cjson->index)<INIT_LEN)?'\n':','),key,element);
    uint32_t len_element = strlen(b_element);
    // si el tamanio del buffer puede contener el nuevo elemento, lo agrego

    if ((index + len_element) <= (cjson->len))   
    {
        sprintf(&(cjson->p_string[index-1])," %s",b_element); // agrego el nuevo elemento
        cjson->index = strlen(cjson->p_string);
        ret = 1;
    }

    return ret;


}


char* cjson_get_string(cjson_t* cjson)
{
     uint32_t index = cjson->index;
    sprintf(&(cjson->p_string[index-1]),"}");
    cjson->index = strlen(cjson->p_string);
    return cjson->p_string;
}



void cjson_delete(cjson_t* cjson)
{
    if(cjson != NULL)
    {
        free(cjson->p_string);
        free(cjson);
    }
}