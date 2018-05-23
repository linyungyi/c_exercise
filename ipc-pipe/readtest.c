/**************
* readtest.c *
* http://myblog-maurice.blogspot.tw/2011/12/linux_15.html
**************/
#include 
#include 
#include 
main()
{
  int pipe_fd[2];
  pid_t pid;
  char r_buf[100];
  char w_buf[4];
  char* p_wbuf;
  int r_num;
  int cmd;
       
  memset(r_buf,0,sizeof(r_buf));
  memset(w_buf,0,sizeof(r_buf));
  p_wbuf=w_buf;
  if(pipe(pipe_fd)<0)
  {
    printf("pipe create error\n");
    return -1;
  }
       
  if((pid=fork())==0)
  {
    printf("\n");
    close(pipe_fd[1]);
    sleep(3);//確保父進程關閉寫端
    r_num=read(pipe_fd[0],r_buf,100);
    printf( "read num is %d   the data read from the pipe is %d\n",r_num,atoi(r_buf));
        
    close(pipe_fd[0]);
    exit();
  }
  else if(pid>0)
  {
    close(pipe_fd[0]);//read
    strcpy(w_buf,"111");
    if(write(pipe_fd[1],w_buf,4)!=-1)
      printf("parent write over\n");
    close(pipe_fd[1]);//write
    printf("parent close fd[1] over\n");
    sleep(10);
  }      

}
 /**************************************************
 * 程式輸出結果：
 * parent write over
 * parent close fd[1] over
 * read num is 4   the data read from the pipe is 111
 * 附加結論：
 * 管道寫端關閉後，寫入的資料將一直存在，直到讀出為止.
 ****************************************************/