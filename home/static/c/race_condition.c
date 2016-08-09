static const char* coldboot_done = "/dev/.coldboot_done";
void device_init(){
  int fd;
  if (stat(coldboot_done, &info) < 0){
    fd = open(coldboot_done, 0, 0000); //@violation RACE_CONDITION
    close(fd);
  }
}
    
  
