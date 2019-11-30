#include <stdio.h>
#include <stdlib.h>


void fEncrypt();
void fDecrypt();

int main(){
        int option;
        printf("\n1: Encrypt file");
        printf("\n2: Decrypt file");
        printf("\nOption: ");
        scanf("%d", &option);
        switch(option) {
        case 1: fEncrypt();
                break;
        case 2: fDecrypt();
                break;
        default: printf("Please choose a valid choice!");
        }
        return 0;
}

void fEncrypt(){
        char fInput[21], fOutput[21], ch;
        int op, fn;
        FILE *f1, *f2;
        printf("\nThe name of the file to encrypt: ");
        scanf("%s", &fInput);
        printf("\nThe name of the output file: ");
        scanf("%s", &fOutput);
        printf("\nThe integer of encryption: ");
        scanf("%d", &fn);
        f1=fopen(fInput, "r");
        if(f1==NULL) {
                printf("\n%s does not exist!", fInput);
                exit(0);
        } else{
                f2=fopen(fOutput, "w");
                ch=fgetc(f1);
                while(ch!=EOF) {
                        op=(int)ch;
                        op=op+fn;
                        fprintf(f2, "%c", op);
                        ch=fgetc(f1);
                }
        }
        fclose(f2);
        fclose(f1);
        printf("Encrpted file has been created as %s", fOutput);
        return;
}
void fDecrypt(){
        char fInput[21], fOutput[21], ch;
        int op, fn;
        FILE *f1, *f2;
        printf("\nThe name of the file to decrypt: ");
        scanf("%s", &fInput);
        printf("\nThe name of the output file: ");
        scanf("%s", &fOutput);
        printf("\nThe integer of decryption: ");
        scanf("%d", &fn);
        f1=fopen(fInput, "r");

        if(f1==NULL) {
                printf("\n%s does not exist!", fInput);
                exit(0);
        } else{
                f2=fopen(fOutput, "w");
                ch=fgetc(f1);
                while(ch!=EOF) {
                        op=(int)ch;
                        op=op-fn;
                        fprintf(f2, "%c", op);
                        ch=fgetc(f1);
                }

        }
        fclose(f2);
        fclose(f1);
        printf("Decrypted file has been created as %s", fOutput);
        return;
}
