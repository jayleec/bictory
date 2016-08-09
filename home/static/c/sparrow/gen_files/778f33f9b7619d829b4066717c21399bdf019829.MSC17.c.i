/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/MSC17.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 2 "/home/kskyj/sparrow4/util/testcode/c/MSC17.c"
enum _ZZ5msc17E10WidgetEnum_1 { _ZZ5msc17E4WE_W_1, _ZZ5msc17E4WE_X_1, _ZZ5msc17E4WE_Y_1, _ZZ5msc17E4WE_Z_1}; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 1
extern int msc17(); int msc17() {
auto enum _ZZ5msc17E10WidgetEnum_1 __6_45_widget_type;

auto int __8_6_x;
#line 3
__6_45_widget_type = ((enum _ZZ5msc17E10WidgetEnum_1)1U);


switch (__6_45_widget_type) {
case ((enum _ZZ5msc17E10WidgetEnum_1)0U):
switch (__8_6_x) {
case 0:
case 1:
__8_6_x = (__8_6_x + 1);
case 2:
__8_6_x = (__8_6_x - 1);
goto __T42313472;
default:
__8_6_x = __8_6_x;

} __T42313472:;
__8_6_x = 0;
case ((enum _ZZ5msc17E10WidgetEnum_1)1U):
__8_6_x = 1;
goto __T42314568;
case ((enum _ZZ5msc17E10WidgetEnum_1)2U):
case ((enum _ZZ5msc17E10WidgetEnum_1)3U):
__8_6_x = 2;
goto __T42314568;
default:
__8_6_x = __8_6_x;

} __T42314568:; 
}
