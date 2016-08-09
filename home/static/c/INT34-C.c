/* INT34-C. Do not shift a negative number of bits or more bits than
   exist in the operand */

void int34_bad1(){

int si1;
int si2;
int sresult;
 
/* Initialize si1 and si2 */
 
 si1 = 10;
 si2 = -100;
 sresult = si1 << si2; //@violation SHIFT_NEGATIVE
}


void int34_bad2(){

unsigned int ui1;
unsigned int ui2;
unsigned int uresult;
 
/* Initialize ui1 and ui2 */
 ui1 =1000;
 ui2 = 4328940832042304;
uresult = ui1 << ui2; //@violation SHIFT_EXCEEDS_BIT_WIDTH

}


void int34_good2(){
  unsigned int ui1;
  unsigned int ui2;
  unsigned int uresult;
  
  /* Initialize ui1 and ui2 */
  ui1 = 10;
  ui2 = 10;
  
  if (ui2 >= sizeof(unsigned int)*8) {
    /* Handle error condition */
  } else {
    uresult = ui1 << ui2;
  }
}

typedef unsigned char uint8_t; 
typedef unsigned int uint16_t;
typedef unsigned long uint32_t ; 

void mc2_1208 ( void )
{
   uint8_t  mc2_1208_a;
   uint16_t mc2_1208_b;
   uint32_t mc2_1208_c;

   mc2_1208_a = get_uint8 ( );
   mc2_1208_b = get_uint16 ( );
   mc2_1208_c = get_uint32 ( );

   mc2_1208_a = (uint8_t) (mc2_1208_a << 7u);   /* Compliant */
   use_uint8( mc2_1208_a );
   mc2_1208_a = get_uint8 ( );

   mc2_1208_a = (uint8_t) (mc2_1208_a << 8u);   /* Not compliant */
   use_uint8( mc2_1208_a );
   mc2_1208_a = get_uint8 ( );

   mc2_1208_b = (uint16_t) (mc2_1208_b << 15u);    /* Compliant */
   use_uint16( mc2_1208_b );
   mc2_1208_b = get_uint16 ( );

   mc2_1208_b = (uint16_t) (mc2_1208_b << 16u);   /* Not compliant */
   use_uint16( mc2_1208_b );

   mc2_1208_b = (uint16_t) (((uint16_t) mc2_1208_a) << 15u);  /* Compliant */
   use_uint16( mc2_1208_b );
   mc2_1208_b = get_uint16 ( );

   mc2_1208_c = (uint32_t) (mc2_1208_c << 31u);   /* Compliant */
   use_uint32( mc2_1208_c );
   mc2_1208_c = get_uint32 ( );

   mc2_1208_c = (uint32_t) (mc2_1208_c << 32u);   //@violation SHIFT_EXCEEDS_BIT_WIDTH
   use_uint32( mc2_1208_c );

   mc2_1208_c = (uint32_t) ((uint32_t) mc2_1208_b << 31u); /* Compliant */
   use_uint32( mc2_1208_c );

}
