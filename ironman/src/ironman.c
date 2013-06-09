#include <ironlib.h>

int main(int argc, char *argv[])
{
    char cmd[80];
    char *rndname;
    int i, randfd;
    struct clinfo info;
    
    rndname = malloc(sizeof(char)*100);
    randfd = open("/dev/urandom", O_RDONLY); /*берем 100 байт для генератора хеш суммы*/
    read(randfd,rndname,100);
    close(randfd);

    MD5((const unsigned char *)rndname,100, info.hash);
    free(rndname);
    info.cpu = 2;




    
    printf("Client hashid - ");

    for (i=0;i<MD5_DIGEST_LENGTH;i++)
    { 
      printf("%02x",info.hash[i]);
    }
    printf("\n");

    while(1)
    {
      scanf("%s",cmd);
      StartClient(SVPORT,cmd,info);
    }

  return 0;
}
