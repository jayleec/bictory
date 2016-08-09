int msc17() {
	enum WidgetEnum { WE_W, WE_X, WE_Y, WE_Z } widget_type;
	widget_type = WE_X;
	int x;
	 
	switch (widget_type) {
	  case WE_W:
		switch (x) {
			case 0:
			case 1:
				x = x + 1;				/* Violation */
			case 2:
				x = x - 1;
				break;
			default:
			     x=x;
				/* do something */
		}
		x = 0;							/* Violation */
	  case WE_X:
		x = 1;
		break;
	  case WE_Y:
	  case WE_Z:
		x = 2;
		break;
	  default:
		x=x;	  /* can't happen */
		 /* handle error condition */
	}
}