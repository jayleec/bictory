casting_problem(){z.507,y.506,x.508,.t.301,.t.300,.t.299,.t.298,.t.297}{
  y.506 := 32760	/* integer_overflow.c:45:18:casting_problem:l.1062:integer_overflow */
  z.507 := 32760	/* integer_overflow.c:46:17:casting_problem:l.1064:integer_overflow */
  .t.300 := malloc(100)	/* integer_overflow.c:47:22:casting_problem:l.1067:integer_overflow */
  x.508 := .t.300	/* integer_overflow.c:47:22:casting_problem:l.1066:integer_overflow */
  z.507 := (y.506 + 999999999999)	/* integer_overflow.c:48:32:casting_problem:l.1068:integer_overflow */
  z.507 := (z.507 + 999999999999)	/* integer_overflow.c:49:32:casting_problem:l.1069:integer_overflow */
  .t.297 := free(x.508)	/* integer_overflow.c:50:9:casting_problem:l.1070:integer_overflow */
  return __BOT__	/* integer_overflow.c:51:3:casting_problem:l.1071:integer_overflow */
}
