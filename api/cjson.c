/**Date: 18/10/2021 
 * Author: German Velardez
 * 
 * 
 * Description: 
 * Handling strings with json format in c language
 * 
 * **/



#include "cjson.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MINIMAL_SIZE        5    
#define NAME_KEY            16






static element_t * _get_element(json_t* json,uint16_t pos)
{
    element_t* element;

   element = &( json->values[pos]);

    return element;
}




static int _add_value(json_t* json, char* string,int16_t pos,type_element type)
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







static int _set_element(json_t * json, uint16_t pos, char* name,void* value, type_element type)
{
    //SET KEY
    

    json->keys[pos]= malloc(strlen(name+1));
    strcpy(json->keys[pos],name);

   
   
    
 
    int res = _add_value(json,(char*)value,pos,type);
        
    
  
    return res;
   

}




int json_add_int(json_t* json, char* key, int value)
{

    int res = 0;
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




int json_add_float(json_t* json, char* key, double value)
{

    int res = 0;
    if(key != NULL) // invalid name
    {
        int pos = json->size; // last position
        char buf[20];
        sprintf(buf,"%.2f",value);
        res =  _set_element(json,pos,key,buf,E_FLOAT);
        pos = pos + 1;
        json->size = pos ;
      
    }
    return res;
}



json_t* init_json(uint16_t size)
{
  


    //create object
    json_t* json = (json_t*)malloc(sizeof(json_t));

    if(json != NULL) 
    {
        json->size= 0;   // init to zero elements
        json->keys = malloc(sizeof(char*) * NAME_KEY); // array with name elements
        json->values = malloc(sizeof(element_t)*size);           // array with type of elements;
    }   

    return json;

}




void free_json(json_t* json);









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





int get_string(json_t* json, char *string, uint16_t size)
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
            sprintf((string+len),"\r\n %c  \"%s \" : \"%s\" ",counter == 0 ? ' ': ',' ,name,(char*)element->value);

        }
      
        else
        {
           sprintf((string+len),"\r\n %c  \"%s \" : %s ",counter == 0 ? ' ': ',' ,name,(char*)element->value);   
        }
       
                
    
       
         len = strlen(string);

    }
   
   sprintf(string+ len,"}   \n");
    return 1;
}




