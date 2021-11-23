/**Date: 18/10/2021 
 * Author: German Velardez
 * 
 * 
 * Description: 
 * Handling strings with json format in c language
 * 
 * **/


#include <stdio.h>

#include "cjson.h"



int main(void)
{
    json_t* json;  // create a pointer for json_t

    
    json = json_init(5); //this function return json object with size for 5 elements
    

    
    
    if(json != NULL)
    {
      json_add_int(json,"posX",1700);   // add element with type INT
      json_add_int(json,"posY",1987);
      json_add_int(json,"numero entero",235);
      json_add_float(json,"numero real",25.5);   // add element with type float
      json_add_string(json,"elemento3","cadena");  // add element with type char* (string)
      
      char string[200];  // you need a buffer to get json string
      
      int res = json_get_string(json,string ,200);    //get de json string
      if(res != 0)  // if res == 0, error 
      {
        printf("json : %s ",string);
      }
      
    }
    
     return 0;

}