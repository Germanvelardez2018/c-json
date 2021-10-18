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


static void _set_element(json_t * json, uint16_t pos, char* name,void* value, type_element type)
{
    element_t* element= &( json->values[pos]);
    json->keys[pos]= malloc(strlen(name+1));

    
    strcpy(json->keys[pos],name);
    element->value = value;
    element->type = type;


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


int json_add_int(json_t* json,char*  name_element,int number )
{
    if(name_element == NULL) // invalid name
    {
        return 0;
    }
    else
    {
        int pos = json->size;
        _set_element(json,pos,name_element,(void*)number,E_INT);
        pos = pos + 1;
        json->size = pos ;

    }
}



int json_add_float(json_t* json,char*  name_element,float number );


int json_add_char(json_t* json,char*  name_element,char string, uint16_t string_size );



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

        
        switch (element->type)
        {
            case  E_INT:
           sprintf((string+len),"%c  \"%s \" : %d\r\n",counter == 0 ? ' ': ',',name,element->value);
                break;

            case E_FLOAT:
            sprintf((string+len),"%c  \"%s \" : %f\r\n",counter == 0 ? ' ': ',',name,(element->value));
                break;

            case E_STRING:
            sprintf((string+len),"%c  \"%s \" : %s\r\n",counter == 0 ? ' ': ',' ,name,(char*)element->value);
                
                break;

            default:
            sprintf((string+len),"not: define\r\n");

                break;
        }
       
         len = strlen(string);

    }
   
   sprintf(string+ len,"}   \n");
    return 1;
}




