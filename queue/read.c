#include 
#include 
#include 
#include 
main()
{
　int fd, num;

　fd = open("/dev/globalvar", O_RDWR, S_IRUSR | S_IWUSR);
　if (fd != - 1)
　{
　　while (1)
　　{
　　　read(fd, &num, sizeof(int)); //程序将阻塞在此语句，除非有针对globalvar的输入
　　　printf("The globalvar is %d\n", num);

　　　//如果输入是0，则退出
　　　if (num == 0)
　　　{
　　　　close(fd);
　　　　break;
　　　}
　　}
　}
　else
　{
　　printf("device open failure\n");
　}
}