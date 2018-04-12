#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_LOOP 1145


int main()
{
   unsigned long int ulTemplateFileSize = 0;
   char*             pBufferTemplate = NULL;
   int               iSizeRead = 0;
   unsigned long int ulIndex = 0;
   int               i;
   char              pTemp[32];
   
   
   FILE* fdTemplate = fopen("template.log","rb" );
   if (fdTemplate != NULL)
   {
      
      // get the template size
      fseek(fdTemplate,0,SEEK_END);
      ulTemplateFileSize = ftell(fdTemplate);
      printf ("template size = %lu\r\n",ulTemplateFileSize);      
      pBufferTemplate = calloc(ulTemplateFileSize+1,sizeof(char));
      if (pBufferTemplate != NULL)
      {
         // read the template
         fseek(fdTemplate,0,SEEK_SET);
         do
         {
            iSizeRead = fread(&pBufferTemplate[ulIndex],1,1024,fdTemplate);
            ulIndex = ulIndex + (unsigned long int)iSizeRead;
            //printf ("SizeRead=%d, index=%lu\r\n",iSizeRead,ulIndex);
         }
         while (iSizeRead == 1024);            
      
         // copy LOG_LOOP times the template into the log file
         FILE* fdLog = fopen("log.log","w" );
         if (fdTemplate != NULL)
         {
            for (i=1;i<=LOG_LOOP;i++)
            {
               sprintf(pTemp,"loop:%d\r\n",i);
               printf("%s",pTemp);
               
               fwrite((const void *)pTemp          ,1,strlen(pTemp),       fdLog);
               fwrite(("\r\n")                     ,1,2,                   fdLog);
               fwrite((const void *)pBufferTemplate,1,ulTemplateFileSize,  fdLog);
               fwrite(("\r\n")                     ,1,2,                   fdLog);
            }
            fclose(fdLog);
         }
         
         free(pBufferTemplate);
      }
      else
      {
         printf ("can't allocate memory\r\n");
      }
      fclose(fdTemplate);
   }
   else
   {
      printf ("can't find template\r\n");
   }
   return 0;
}
