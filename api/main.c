/**Date: 18/10/2021 
 * Author: German Velardez
 * 
 * 
 * Description: 
 * Handling strings with json format in c language
 * 
 * **/


#include <stdio.h>

#include "api/cjson.h"



int main(void)
{
    cjson_t* json;  // create a pointer for json_t

    #define BUFFER_JSON   200
    json = cjson_create(BUFFER_JSON); //this function return json object with size for 5 elements
    

    
    
    if(json != NULL)
    {
      cjson_add_int(json,"posX",1700);   // add element with type INT
      cjson_add_int(json,"posY",1987);
      cjson_add_int(json,"numero entero",235);
      cjson_add_float(json,"numero real",25.5);   // add element with type float
      cjson_add_string(json,"elemento3","cadena");  // add element with type char* (string)
      
      char* p_string  =  cjson_get_string(json);

      
      if(p_string != NULL)  // if res == 0, error 
      {
        printf("json : %s ",p_string);
      }
      
    }
    
     return 0;

}