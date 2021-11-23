/**
 * @file json.c
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Implementacion del formato json y funciones asociadas
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "cjson.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define MINIMAL_SIZE        5    
#define NAME_KEY            16




static element_t * _get_element(json_t* json,uint32_t pos)
{
    element_t* element;
    element = &( json->values[pos]);
    return element;
}




static int32_t _add_value(json_t* json, char* string,int32_t pos,type_element type)
{
    //SET VALUE IN BUFFER
    element_t* element= &( json->values[pos]);
    int16_t size = strlen((char*)string+1);
    char* buffer = (char*) malloc(size);
    if(buffer == NULL) return 0;
    strcpy(buffer,string);
    //ADD ELEMENT
    element->type = type;
    element->value = buffer;
    return 1;
}



static int32_t _set_element(json_t * json, uint32_t pos, char* name,void* value, type_element type)
{
    //SET KEY
    json->keys[pos]= malloc(strlen(name+1));
    strcpy(json->keys[pos],name);
    int32_t res = _add_value(json,(char*)value,pos,type);
    return res;
   
}




int json_add_int(json_t* json, char* key, int32_t value)
{

    int32_t res = 0;
    if(key != NULL) // invalid name
    {
        int pos = json->size; // last position
        char buf[20];
        sprintf(buf,"%i",value);
        res =  _set_element(json,pos,key,buf,E_INT);
        pos = pos + 1;
        json->size = pos ;
      
    }
    return res;
}




int json_add_float(json_t* json, char* key, float value)
{

    int res = 0;
    if(key != NULL) // invalid name
    {
        int size = json->size; // ultima posicion
        char buf[20];
        sprintf(buf,"%.2f",value);
        res =  _set_element(json,size,key,buf,E_FLOAT);
        size = size + 1;
        json->size = size ;
      
    }
    return res;
}



json_t* json_init(uint16_t size)
{
  


    //create object
    json_t* json = (json_t*)malloc(sizeof(json_t));

    if(json != NULL) 
    {
        json->size= 0;   // init to zero elements
        json->keys = malloc(sizeof(char*) * size); // array de string. 
        json->values = malloc(sizeof(element_t)*size);           // array with type of elements;
    }   

    return json;

}




void json_delete(json_t* json)
{
    uint32_t pos = json->size;

    //libero keys, libero char* en elementos, libero elementos
    if(json !=NULL)
    {
        // libero los strings de nombres keys
        for(uint32_t i=0 ; i< json->size; i++)
        {
            free(json->keys[i]);
            free(json->values[i].value); // free value dentro de elementos
    
        }
        // libero el array de keys
        free(json->keys);
        free(json->values);
    }
}









int json_add_string(json_t* json, char* key, void* value)
{

    int res = 0;
    if(key != NULL) // invalid name
    {
        int pos = json->size; // last position
        res =  _set_element(json,pos,key,value,E_STRING);
        pos = pos + 1;
        json->size = pos ;
      
    }
    return res;
}





int json_get_string(json_t* json, char *string, uint32_t size)
{
    int len = 0;
    sprintf(string,"{\n");
    len = 1;

    for( int counter= 0 ; counter < (json->size); counter++)
    {   
        
        //what is the type of the element
        element_t* element = _get_element(json,counter);
        char* name = json->keys [counter];

        if( element->type == E_STRING)
        {
            sprintf((string+len),"\r\n %c  \"%s \" : \"%s\" ",
                                    counter == 0 ? ' ': ',' ,
                                    name,
                                    (char*)element->value);
        }
      
        else
        {
           sprintf((string+len),"\r\n %c  \"%s \" : %s ",
                                    counter == 0 ? ' ': ',' ,
                                    name,
                                    (char*)element->value);   
        }
         len = strlen(string);

    }
   
   sprintf(string+ len,"}   \n");
    return 1;
}




