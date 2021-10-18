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
   
    json_t* json;

    
    json = init_json(5);
    

    json_add_int(json,"posX",1700);
    json_add_int(json,"posY",1987);
    json_add_int(json,"numero entero",235);
      

    json_add_float(json,"numero real",25.5);

   
    json_add_element(json,"elemento3","cadena",E_STRING);
  //json_add_element(json,"measure sensor",(void*)23.5,E_FLOAT);
    printf(" elemento agregado \n");

   

    if(json != NULL)
    {
       
     

   
        char string[200];
         get_string(json,string ,200);
        printf("json : %s ",string);
    }
    
     return 0;
}