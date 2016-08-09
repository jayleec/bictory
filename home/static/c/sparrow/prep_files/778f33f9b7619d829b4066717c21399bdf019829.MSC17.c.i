# 1 "/home/kskyj/sparrow4/util/testcode/c/MSC17.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/MSC17.c"
int msc17() {
 enum WidgetEnum { WE_W, WE_X, WE_Y, WE_Z } widget_type;
 widget_type = WE_X;
 int x;

 switch (widget_type) {
   case WE_W:
  switch (x) {
   case 0:
   case 1:
    x = x + 1;
   case 2:
    x = x - 1;
    break;
   default:
        x=x;

  }
  x = 0;
   case WE_X:
  x = 1;
  break;
   case WE_Y:
   case WE_Z:
  x = 2;
  break;
   default:
  x=x;

 }
}
