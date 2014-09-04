int pd1=2;   //photodiode
 int pd2=3;
//Photodiode to digital pin 2 and pin 3
 int led=13;          //led to digital pin 9
 int pd1Read=0;      //Readings from sensor to analog pin 0                   
 int pd2Read=1;
 int limit1=975;//Threshold range of an obstacle 
 int limit2=975;
 int flag=0;

 int count=0; 
const int segment[]={4,5,6,7,8,9,10};

 void setup()   
 {   for(int i=0;i<7;i++)
     {
    pinMode(segment[i],OUTPUT);

     }
  
   pinMode(pd1,OUTPUT); 
   pinMode(pd2,OUTPUT); 
  pinMode(led,OUTPUT); 
  digitalWrite(pd1,HIGH);   //supply 5 volts to photodiode
  digitalWrite(pd2,HIGH); 
  digitalWrite(led,LOW);      //set the led in off mode (initial condition) 
  Serial.begin(9600);          //setting serial monitor at a default baund rate of 9600 
 } 
 void loop() 
 {
  int val1=analogRead(pd1Read);  //variable to store values from the photodiode  1
  int val2=analogRead(pd2Read);
  // const byte segmentnumbers[]={B1111110,B0110000,B1101101,B1111001,B0110011,B1011011,B1011111,B1110000,B1111111,B1111011};

  if(val1<=limit1)
  {count=count+1;
  //digitalWrite(led,HIGH);
  }
  delay(500);
  if(val2<=limit2)
  {count=count-1;
   if(count==-1)
   count=0;
  }
  
    for(int i=0;i<7;i++)
    {
    digitalWrite(segment[i],LOW);
    }
          
// delay(100);

   switch(count
   )
      {case 0:
         for(int i=0;i<6;i++)
         digitalWrite(segment[i],HIGH);
          break;
        case 1:
          digitalWrite(segment[1],HIGH);
          digitalWrite(segment[2],HIGH);
          break;
        
         case 2:
        
       digitalWrite(segment[0],HIGH);
       digitalWrite(segment[1],HIGH);
       digitalWrite(segment[3],HIGH);
       digitalWrite(segment[4],HIGH);
       digitalWrite(segment[6],HIGH);
       break;
              
     case 3:
      digitalWrite(segment[0],HIGH);
       digitalWrite(segment[1],HIGH);
       digitalWrite(segment[3],HIGH);
       digitalWrite(segment[2],HIGH);
       digitalWrite(segment[6],HIGH);
       break;
    
        
         case 4:
       digitalWrite(segment[2],HIGH);
       digitalWrite(segment[1],HIGH);
       digitalWrite(segment[5],HIGH);
       digitalWrite(segment[6],HIGH);
       break;
         case 5:
          digitalWrite(segment[0],HIGH);
       digitalWrite(segment[2],HIGH);
       digitalWrite(segment[3],HIGH);
       digitalWrite(segment[5],HIGH);
       digitalWrite(segment[6],HIGH);
       break;
        
         case 6:
          for(int i=0;i<7;i++)
            if(i!=1)
              digitalWrite(segment[i],HIGH);
                   break;
                
         case 7: digitalWrite(segment[0],HIGH);
       digitalWrite(segment[1],HIGH);
       digitalWrite(segment[2],HIGH);
        break;
        
         case 8:
         for(int i=0;i<7;i++)
         digitalWrite(segment[i],HIGH);
          break;
         case 9:
         for(int i=0;i<7;i++)
           if(i!=4)
           digitalWrite(segment[i],HIGH);
          break;
      }

  if(count==0)
   {digitalWrite(led,LOW);
  
  }
else
 {
  digitalWrite(led,HIGH);
 }
  delay(50);

 }

