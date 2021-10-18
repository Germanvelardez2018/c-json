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
    printf("inicio\n");
    json_t* json;

    json = init_json(5);
    printf("se agrego el elemento\n");
    json_add_int(json,"field 1", 123);
    json_add_int(json,"field 2", 13223);
    json_add_int(json,"field 3", 1223);
    //json_add_char(json,"field 1", "hello word\r\n",strlen("hello word\r\n"));
    printf(" elemento agregado \n");

    if(json != NULL)
    {
       
     

   
        char string[200];
         get_string(json,string ,200);
        printf("json : %s ",string);
    }
     return 0;
}