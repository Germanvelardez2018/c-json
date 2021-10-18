/**Date: 18/10/2021 
 * Author: German Velardez
 * 
 * 
 * Description: 
 * Handling strings with json format in c language
 * 
 * **/


#include <stdint.h>

#ifndef _CJSON_H
#define _CJSON_H

typedef enum {
    E_INT,
    E_FLOAT,
    E_STRING
}type_element;

typedef struct 
{
    type_element type;
    void*    value;
}element_t;


typedef struct {
    char** keys;
    element_t* values;  //dinamic array
    char*    p_json;
    uint16_t size;
} json_t;






/**
  * @brief start the json object
  * @retval json_t*: object
  */



json_t* init_json(uint16_t size);



/**
  * @brief free the memory associated with the object
  * @param  json: Object to be released 
  * @retval None
  */


void free_json(json_t* json);



/**
  * @brief Add a numeric  field to json
  * @param  json: Object to be released 
  * @param name_element: name to the field to add
  * @param number: value of the number
  * @retval number 1 if it was successful and 0 if an error occurs
  */
int json_add_int(json_t* json,char*  name_element,int number );

/**
  * @brief Add a numeric float field to json
  * @param  json: Object to be released 
  * @param name_element: name to the field to add
  * @param number: value of the number
  * @retval number 1 if it was successful and 0 if an error occurs
  */

int json_add_float(json_t* json,char*  name_element,float number );

/**
  * @brief Add a string field to json
  * @param  json: Object to be released 
  * @param string: string to add to the json
  * @param string_size: len of the string
  * @retval number 1 if it was successful and 0 if an error occurs
  */
int json_add_char(json_t* json,char*  name_element,char string, uint16_t string_size );

/**
  * @brief return a string
  * @param  json: Object to be released 
  * @param string: string to add to the json
  * @param number: value of the number
  * @retval number 1 if it was successful and 0 if an error occurs
  */

int get_string(json_t* json, char *string, uint16_t size);








#endif