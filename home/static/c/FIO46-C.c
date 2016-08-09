extern void pfmDbioOpenCursor(char *, void *, int, int);
extern void pfmDbioFetchCursor(char *, void *);
extern void pfmDbioCloseCursor(char *);

void fio46_bad1(void *context){
  pfmDbioOpenCursor("queryname", context, 0, 10);
  
  pfmDbioFetchCursor("queryname", context);

  pfmDbioCloseCursor("queryname");

  pfmDbioFetchCursor("queryname", context); //@violation USE_AFTER_CLOSE
}

