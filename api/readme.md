#Basic json api for C

#Primeras implementacion de interfaz de usuario mediante UART en ESP-32


# Basic json API for C

With this api you can join elements in a json format

Supported variable types : char*, int and float

# Example
```c
    json_t* json;  // create a pointer for json_t

    
    json = init_json(5); //this function return json object with size for 5 elements
    

    
    
    if(json != NULL)
    {
      json_add_int(json,"posX",1700);   // add element with type INT
      json_add_int(json,"posY",1987);
      json_add_int(json,"numero entero",235);
      json_add_float(json,"numero real",25.5);   // add element with type float
      json_add_string(json,"elemento3","cadena");  // add element with type char* (string)
      
      char string[200];  // you need a buffer to get json string
      
      int res = get_string(json,string ,200);    //get de json string
      if(res != 0)  // if res == 0, error 
      {
        printf("json : %s ",string);
      }
      
    }
    
     return 0;
     
     --Terminal--
     -------------------------------
     json : {
    "posX " : 1700 
 ,  "posY " : 1987 
 ,  "numero entero " : 235 
 ,  "numero real " : 25.50 
 ,  "elemento3 " : "cadena" } 
 ------------------------------------

```
