#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct donor {
    char name[50];
    int age;
    int units;
    char group[5];
    char date[10];
} don;



char A1[4][15]= {{"A+"},{"O+"},{"A-"},{"O-"},};
char B1[4][15]= {{"B+"},{"O+"},{"B-"},{"O-"}};
char AB1[6][15]= {{"AB+"},{"A+"},{"B+"},{"O+"},{"AB-"},{"O-"}};
char O1[2][15]= {{"O+"},{"O-"}};
char A0[4][15]= {{"A-"},{"O-"},};
char B0[4][15]= {{"B-"},{"O-"}};
char AB0[4][15]= {{"AB-"},{"O-"},{"A-"},{"B-"}};
char O0[1][15]= {{"O-"}};



int count=0;
void add(don *d);
void display(don *d);
void request(don *d);

int main()
{

    int flag=1;
    int choice;
    don *donars;
    donars= (don*)calloc(5,sizeof(don));
    printf("         WELCOME TO BLOOD BANK MANAGEMENT SYSTEM\n");
    printf("_______________________________________________\n");
    

    do {
    printf("choose the service u want to use\n");
    printf("1) ADD DONOR DETAILS\n");
    printf("2) DISPLAY DONORS DETAILS\n");  
    printf("3) REQUEST FOR BLOOD\n");   
    printf("4) EXIT\n"); 
    scanf("%d",&choice);


    
        switch(choice) {
        case 1:
            add(donars);
            break;

        case 2:
            display(donars);
            break;


        case 3:
            request(donars);
            break;

        case 4:
            flag=0;
        }


    } while(flag);

    return 0;
}

void add(don *d) {

    if(count>=5) {
        don *temp;
      temp = (don*)realloc(d, (count+5)*sizeof(don));
      if(temp == NULL) {
          printf("Memory allocation failed\n");
          return;
       }
       free(d);
       d = temp;
    }
    printf("enter name\n");
    scanf("%s",&d[count].name);
    printf("enter age\n");
    scanf("%d",&d[count].age);
    printf("enter blood group\n");
    scanf("%s",&d[count].group);
    printf("Enter units of blood\n");
    scanf("%d",&d[count].units);
    printf("enter todays date\n");
    scanf("%s",&d[count].date);

    count++;
}

void display(don *d) {
    if(count==0) {
        printf("No donors available\n");
        return;
    }   
    for(int i=0; i<count; i++) {
        printf("Name: %s\n",d[i].name);
        printf("Age: %d\n",d[i].age);
        printf("Group: %s\n",d[i].group);
        printf("Date: %s\n",d[i].date);
        printf("Units: %d\n",d[i].units);
        printf("-----------------------\n");
    }

}

void request(don *d) {
    char bg[10];
    int u;
    printf("Enter the blood group\n");
    scanf("%s",&bg);
    printf("Enter no of units");
    scanf("%d",&u);
    printf("Searching for available donors...\n");
    printf("-----------------------\n");

    if(strcmp(bg,"A+")==0) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<count; j++) {
                if(strcmp(d[j].group,A1[i])==0 && d[j].units>=u){
                    printf("Name: %s\n",d[j].name);
                    printf("Blood Group: %s\n",d[j].group);
                    printf("Units: %d\n",d[j].units);
                    return;
                }
            }
        }
    }

    if (strcmp(bg,"A-")==0){
        for(int i=2; i<4; i++) {
            for(int j=0; j<count; j++) {
                if(strcmp(d[j].group,A1[i])==0 && d[j].units>=u) {
                    printf("Name: %s\n",d[j].name);
                    printf("Blood Group: %s\n",d[j].group);
                    printf("Units: %d\n",d[j].units);
                    return;
                }
            }
        }
    }
    
    if(strcmp(bg,"B+")==0){
        for(int i=0; i<4; i++) {
            for(int j=0; j<count; j++) {
                if(strcmp(d[j].group,B1[i])==0 && d[j].units>=u) {
                    printf("Name: %s\n",d[j].name);
                    printf("Blood Group: %s\n",d[j].group);
                    printf("Units: %d\n",d[j].units);
                    return;
                }
            }
        }
    }

    if (strcmp(bg,"B-")==0){
        for(int i=2; i<4; i++) {
            for(int j=0; j<count; j++) {
                if(strcmp(d[j].group,B1[i])==0 && d[j].units>=u) {
                    printf("Name: %s\n",d[j].name);
                    printf("Blood Group: %s\n",d[j].group);
                    printf("Units: %d\n",d[j].units);
                    return;
                }
            }
        }     
   }

   if (strcmp(bg,"AB+")==0) {
        for(int i=0; i<6; i++) {
            for(int j=0; j<count; j++) {
                if(strcmp(d[j].group,AB1[i])==0 && d[j].units>=u) {
                    printf("Name: %s\n",d[j].name);
                    printf("Blood Group: %s\n",d[j].group);
                    printf("Units: %d\n",d[j].units);
                    return;
                }
            }
        }
    }

    if (strcmp(bg,"AB-")==0){
        for(int i=4; i<6; i++) {
            for(int j=0; j<count; j++) {
                if(strcmp(d[j].group,AB1[i])==0 && d[j].units>=u) {
                    printf("Name: %s\n",d[j].name);
                    printf("Blood Group: %s\n",d[j].group);
                    printf("Units: %d\n",d[j].units);
                    return;
                }
            }
        }     
   }

    if(strcmp(bg,"O+")==0){
          for(int i=0; i<2; i++) {
                for(int j=0; j<count; j++) {
                 if(strcmp(d[j].group,O1[i])==0 && d[j].units>=u) {
                    printf("Name: %s\n",d[j].name);
                    printf("Blood Group: %s\n",d[j].group);
                    printf("Units: %d\n",d[j].units);
                    return;
                 }
                }
          }
     }
    
     if (strcmp(bg,"O-")==0){
          for(int i=1; i<2; i++) {
                for(int j=0; j<count; j++) {
                 if(strcmp(d[j].group,O1[i])==0 && d[j].units>=u) {
                    printf("Name: %s\n",d[j].name);
                    printf("Blood Group: %s\n",d[j].group);
                    printf("Units: %d\n",d[j].units);
                    return;
                 }
                }
          }     
    }

    printf("No donors available with the required blood group and units\n");


}

