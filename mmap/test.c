
int main(int argc, char *argv[])
{
unsigned char *ADDR; 
int device_pointer;
device_pointer = open("/dev/mem",O_RDWR);
if (device_pointer < 0){
printf("device file open error !\n");
return ;
}
ADDR = mmap(0,0x1000,PROT_READ|PROT_WRITE,MAP_SHARED,device_pointer,0x37F80000);
*(volatile unsigned int *)(ADDR + 0x00) = 0x1;//操作實際位址0x37F80000，令其值為1
*(volatile unsigned int *)(ADDR + 0x04) = 0x1;//操作實際位址0x37F80004，令其值為1
munmap(ADDR,0x1000);
close(device_pointer);
return 0;
}