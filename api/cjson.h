/**
 * @file json.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief 
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */



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

    json_t* json_init(uint16_t size);



    /**
     * @brief free the memory associated with the object
     * @param  json: Object to be released 
     * @retval None
     */

    void json_delete(json_t* json);



    /**
     * @brief Add a string field 
     * @param  json: Object to be released 
     * @param key: name to the field to add
     * @param value: value of the string
     * @retval number 1 if it was successful and 0 if an error occurs
     */

    int json_add_string(json_t* json, char* key, void* value);


    /**
     * @brief Add a numeric  field to json
     * @param  json: Object to be released 
     * @param key: name to the field to add
     * @param value: value of the number
     * @retval number 1 if it was successful and 0 if an error occurs
     */

    int json_add_int(json_t* json, char* key, int32_t value);


    /**
     * @brief Add a numeric float field to json
     * @param  json: Object to be released 
     * @param key: name to the field to add
     * @param value: value of the number
     * @retval number 1 if it was successful and 0 if an error occurs
     */

    int json_add_float(json_t* json, char* key, float value);




    /**
     * @brief Add a numeric float field to json
     * @param  json: Object to be released 
     * @param name_element: name to the field to add
     * @param number: value of the number
     * @retval number 1 if it was successful and 0 if an error occurs
     */

    int json_get_string(json_t* json, char *string, uint32_t size);
#endif