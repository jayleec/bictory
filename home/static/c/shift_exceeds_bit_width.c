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

   mc2_1208_b = (uint16_t) ((uint16_t) mc2_1208_a << 15u);  /* Compliant */
   use_uint16( mc2_1208_b );
   mc2_1208_b = get_uint16 ( );

   mc2_1208_c = (uint32_t) (mc2_1208_c << 31u);   /* Compliant */
   use_uint32( mc2_1208_c );
   mc2_1208_c = get_uint32 ( );

   mc2_1208_c = (uint32_t) (mc2_1208_c << 32u);   /* Not compliant */
   use_uint32( mc2_1208_c );

   mc2_1208_c = (uint32_t) ((uint32_t) mc2_1208_b << 31u); /* Compliant */
   use_uint32( mc2_1208_c );

}

