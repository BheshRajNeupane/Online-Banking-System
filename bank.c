#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user {
             char name[100];
             char phone[50];
             char password[100];
             float balance  ;
};

int main(){
           struct user usr, usr1;
           usr.balance=0;
         FILE *fptr;
         char filename[100];
         char phn[50];
         char pswd[50];
      int opt,choice;
       char entry = 'y';
       float amount;

      printf("********************************************************\n");
     

      printf("What do you want to do?\n1.Register an account to online banking system\n2.Login to an account");

      printf("\n Enter your choice:\t");
      scanf("%d",&opt);


// registration section
    if( opt == 1){
              printf("\nEnter your account name:\n");
            scanf(" %[^\n]%*c",&usr.name);
              printf("Enter your phone number:\n");
              scanf("%s",usr.phone);
              printf("Enter your password :\n");
              scanf("%s",usr.password);
              usr.balance=0;
           
            strcpy(filename,usr.phone);
         
            fptr = fopen(strcat(filename,".dat"),"w");
            
            fwrite(&usr,sizeof(struct user),1,fptr);

 
            if(fwrite != 0){
            
            printf("\nAccount Successfully register!\n");
            
            }else {

              printf("\nSomthing is wrong please try again!\n");
            }
            fclose(fptr);
    }
// end of registration section!


// Account openning section
if(opt == 2){
  printf("-------------------------------------");
 
     printf("\n\nPhone Number:\t");
     scanf("%s",&phn);
     printf("Password:\t");
     scanf("%s",&pswd);
     strcpy(filename,phn);
     fptr= fopen(strcat(filename,".dat"),"r");
           
     if(fptr == NULL){  
       printf("Account number not registered!\n");
       
     }
     else{   // opening registred a/c

      fread(&usr,sizeof(struct user),1,fptr);
     fclose(fptr);
            printf("password test:%s",usr.password);
     if(strcmp(pswd,usr.password)== 0){
        // printf("Amsount test: %f",amount);
            while( entry == 'y'){
            printf("\nEnter 1 to check balance.\n");
             printf("Enter 2 for depositng cash.\n");
              printf("Enter 3 for cash withdrawl.\n");
               printf("Enter 4 for online transfer.\n");
               printf("Enter 5 for changing the password.\n");
                printf("Your choice:\t");
               scanf("%d",&choice);

               switch(choice){

               case 1:
                           printf("Your current balance is rs %.2f\n",usr.balance);
                           break;

                case 2:
                           printf("Enter the amount:\nRs.");
                           scanf("%f",&amount);
                           usr.balance += amount;
                         fptr = fopen(filename,"w");
                         fwrite(&usr,sizeof(struct user),1,fptr);
                         if(fwrite != NULL) {printf("\nSuccessfully  Deposited.\n");}
                         fclose(fptr);
                           break;

                case 3: 
                        
                           printf("Enter the amount:\nRs.");
                           scanf("%f",&amount);
                           usr.balance -= amount;
                         fptr = fopen(filename,"w");
                         fwrite(&usr,sizeof(struct user),1,fptr);
                         if(fwrite != NULL) {
                           printf("\nSuccessfully  Withdraw.\n");}
                         fclose(fptr);
                       break;


          case 4:
                printf("Enter the phone number to transfer\n ");
                scanf("%s",phn);
                printf("Enter the amount to transfer:\nRs.");
                scanf("%f",&amount);

                strcpy(filename,phn);
                fptr = fopen(strcat(filename,".dat"),"r");
                    if(fptr == NULL){
                  printf("\nAccount number not registred.\n");
                   printf("Registred account first.\n");
                   break;
                    }
                          else
                          {
                    fread(&usr1,sizeof(struct user),1,fptr);
                    fclose(fptr);
                                    if(usr.balance < amount){
                                   printf("Insufficent balance");
                                    }
                                                  else{
                    strcpy(filename,phn);
                    fptr = fopen(strcat(filename,".dat"),"r");
                    fread(&usr1,sizeof(struct user),1,fptr);
                    fclose(fptr);
                    fptr=fopen(filename,"w");
                    usr1.balance += amount;
                    fwrite(&usr1,sizeof(struct user),1,fptr);
                    fclose(fptr);
                    if(fwrite != NULL);{
                      printf("You have succesfully transfer Rs. %.2f  to %s",amount,phn);
                      //deducted sendingg amount from main balance of sender
                      strcpy(filename,usr.phone);
                    fptr = fopen(strcat(filename,".dat"),"w");
                      
                      usr.balance -=amount;
                      fwrite(&usr,sizeof(struct user),1,fptr);
                      fclose(fptr);

                    }
                    }
                        break;
                    }//case 4 closed



         case 5:
               printf("\n Enter your new password:\t");
               scanf("%s",pswd);
               fptr = fopen(filename,"w");
               strcpy(usr.password,pswd);
               fwrite(&usr,sizeof(struct user),1,fptr);
               if(fptr !=NULL){
                 printf("\nPassword succesfully changed!");
               }
              break;

         default:
            printf("Invalid option!");     









               }//switch closed




              
               printf("\nDo you want to continue [y/n]?\n");
               scanf("%s",&entry);
            
            }//while closed
     
 }// if closed
 
 else{
       ("-------------------------------------"); 
       printf(" Incorrect Password!\n");
     }

     }









  
}








return 0;

}