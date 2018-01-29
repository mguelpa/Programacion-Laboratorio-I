#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

//////////////////////////////////////////////////////////
/********************************************************
 * \brief  closes the stream. All buffers are flushed.
 * \param  stream: is the pointer to a FILE object
 *         that specifies the stream to be closed.
 *
 * \return 0 if the stream is successfully closed.
 *           On failure, EOF is returned.
 */
    int fclose(FILE* fp);

    #include <stdio.h>
    #include <stdlib.h>

    int main ()
    {
       FILE *fp;

       fp = fopen("file.txt", "w");

       fprintf(fp, "%s", "This is tutorialspoint.com");

       fclose(fp);

       return(0);
    }
//////////////////////////////////////////////////////////
/********************************************************
 * \brief  close all the open streams using single method.
 * \param  void.
 * \return if OK number of streams closed
 *         on failure returns EOF.
 */
    int fcloseall(void);

    #include <stdio.h>

    int main()
    {
        int streams_closed;

        fopen("ONE.txt","w");
        fopen("TWO.txt","w");

        streams_closed = fcloseall();

        if (streams_closed == EOF)
            printf("Error");
        else
            printf("%d Streams Were Closed", streams_closed);

        return 0;
    }
//////////////////////////////////////////////////////////
/********************************************************
 * \brief  close all the open streams using single method.
 * \param  void.
 * \return if OK number of streams closed
 *         on failure returns EOF.
 */
    int fread(void *memoria, int num, int cont, FILE *fp);





int fwrite(void *memoria,int num,int cont,FILE *fp);


int feof(FILE *f);

int ferror(FILE *fp);

void rewind(FILE *fp);

int fseek(FILE *fp, long num, int origen);

long ftell(FILE *f);

int getc(FILE *fp);

char* fgets(char *str,int n,FILE *fp);

int putc(int ch,FILE *fp);

int fputs(const char *str,FILE *fp);


int fscanf(FILE *fp,const char *formato[ ,dirección,...]);

int fprintf(FILE *fp,const char *formato[ ,argumento,...]);
