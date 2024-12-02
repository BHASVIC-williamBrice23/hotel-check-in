//hi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>
//global variables
// ANSI color codes used to colour print statements
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
void checkin();
void quickcheckout();
void checkstoreddata();
void BookTable();
int checkout(int info1[7],int info2[7],int info3[7],int info4[7],int info5[7],int info6[7],char bookingID1[30],char bookingID2[30],char bookingID3[30],char bookingID4[30],char bookingID5[30],char bookingID6[30]);
int TableAvailable1[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
int TableAvailable2[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
int TableAvailable3[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
int TableAvailable4[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
int TableAvailable5[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
int TableAvailable6[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
char guestname1[20];
char guestname2[20];
char guestname3[20];
char guestname4[20];
char guestname5[20];
char guestname6[20];
char guestsurname1[20];
char guestsurname2[20];
char guestsurname3[20];
char guestsurname4[20];
char guestsurname5[20];
char guestsurname6[20];
int room1 = 0;
int room2 = 0;
int room3 = 0;
int room4 = 0;
int room5 = 0;
int room6 = 0;
int guest1[7];
int guest2[7];
int guest3[7];
int guest4[7];
int guest5[7];
int guest6[7];
int DOB11 = 0;
int DOB12 = 0;
int DOB13 = 0;
int DOB21 = 0;
int DOB22 = 0;
int DOB23 = 0;
int DOB31 = 0;
int DOB32 = 0;
int DOB33 = 0;
int DOB41 = 0;
int DOB42 = 0;
int DOB43 = 0;
int DOB51 = 0;
int DOB52 = 0;
int DOB53 = 0;
int DOB61 = 0;
int DOB62 = 0;
int DOB63 = 0;
int roomnum = 0;
char bookingID1[20];
char bookingID2[20];
char bookingID3[20];
char bookingID4[20];
char bookingID5[20];
char bookingID6[20];


int main() {

    setbuf(stdout,0);
    int end = 1;
    int choice = 0;
    int room=0;
    while(end == 1){
        printf("What would you like to do?\n\nCheck in(1)\nBook a table(2)\nCheck out(3)\nCheck current stored data(4)\nQuit(5)\n");
        fflush(stdin);
        scanf("%d", &choice);
        switch(choice){
            case 1:
                checkin();
                break;
            case 2:
                BookTable();
                break;
            case 3:
                room = checkout(guest1,guest2,guest3,guest4,guest5,guest6,bookingID1,bookingID2,bookingID3,bookingID4,bookingID5,bookingID6);
                int i;
                if(room==1){    //clears data from the right info array
                    for(i=0;i<21;i++){
                        bookingID1[i]= 0;
                    }
                    for(i=0;i<7;i++){
                        guest1[i]=0;
                    }
                    room1=0;
                }
                else if(room==2){
                    for(i=0;i<21;i++){
                        bookingID2[i]= 0;
                    }
                    for(i=0;i<7;i++){
                        guest2[i]=0;
                    }
                    room2=0;
                }
                else if(room==3){
                    for(i=0;i<21;i++){
                        bookingID3[i]= 0;
                    }
                    for(i=0;i<7;i++){
                        guest3[i]=0;
                    }
                    room3=0;
                }
                else if(room==4){
                    for(i=0;i<21;i++){
                        bookingID4[i]= 0;
                    }
                    for(i=0;i<7;i++){
                        guest4[i]=0;
                    }
                    room4=0;
                }
                else if(room==5){
                    for(i=0;i<21;i++){
                        bookingID5[i]= 0;
                    }
                    for(i=0;i<7;i++){
                        guest5[i]=0;
                    }
                    room5=0;
                }
                else{
                    for(i=0;i<21;i++){
                        bookingID6[i]= 0;
                    }
                    for(i=0;i<7;i++){
                        guest6[i]=0;
                    }
                    room6=0;
                }
                break;
            case 4:
                checkstoreddata();
                break;
            case 5:
                return 0;
            default:
                printf("invalid");
        }
    }
}
void checkin(){
    srand (time(NULL));

    int valid = 1;
    char board = 0;
    char dp = 0;
// check if all rooms are booked
    if(room1 + room2 + room3 + room4 + room5 + room6 == 6){
        printf("All rooms are currently booked.\n");
        return;
    }
//printf prices
    printf("Here are the prices for this hotel:\n\nRoom Prices (Maximum of 4 people per room):\nRoom 1-2: 100 pounds per day\nRoom 3: 85 pounds per day\nRoom 4-5: 75 pounds per day\nRoom 6: 50 pounds per day\n\nBoard Prices:\nFull Board: 20 pounds per person per day\nHalf Board: 15 pounds per person per day\nBed and Breakfast: 5 pounds per person per day\n\nDaily Newspaper (one time fee): 5.50 pounds\n");

    while(valid == 1)
    {
        printf("\n\nWhat Room would you like to book? (1-6) :");
        fflush(stdin);
        scanf("%d", &roomnum);
        if (roomnum < 1) {
            printf("Invalid room number try again.");
        }
        else if (roomnum > 6) {
            printf("Invalid room number try again.");
        }
        else{
            valid = 0;
        }
    }
    switch(roomnum){
        //switch for each room (only way i could think of)
        case 1:
//room 1 stuff
            if(room1 == 1){
                printf("This room is booked, try another room.\n");
                break;
            }
            guest1[0] = 1;
            //name and surname separate because the space was messing me up
            printf("\nPlease enter your first name :");
            fflush(stdin);
            scanf("%s", guestname1);

            printf("\nPlease enter your surname :");
            fflush(stdin);
            scanf("%s", guestsurname1);
            // Date Of Birth (guest1) (pos1-3) might be able to simplify later + validation check
            while(valid == 0) {
                printf("\nPlease enter your date of birth in the format DD/MM/YYYY :");
                fflush(stdin);
                scanf("%d/%d/%d", &DOB11, &DOB12, &DOB13);
                if(DOB12 == 2){
                    if(DOB11 > 29){
                        printf("Invalid day");
                    }
                }
                else if(DOB11 < 1 || DOB11 > 31){
                    printf("invalid day");
                }
                else if(DOB12 < 1 || DOB12 > 12) {
                    printf("Invalid month");
                }
                else if(DOB13 > 2005){
                    printf("You are too young to book a room.");
                }
                else if(DOB13 < 1903){
                    printf("You are too old to book a room");
                }
                else{
                    valid = 1;
                }
            }
            //Ask for age because I cant be bothered to calculate it
            valid = 0;
            while(valid == 0){
                printf("\nPlease enter your age :");
                fflush(stdin);
                scanf("%d", &guest1[6]);
                if(2023 - guest1[6] == DOB13){
                    valid = 1;
                }
                else if(2023 - guest1[6] + 1 == DOB13){
                    valid = 1;
                }
                else if(2023 - guest1[6] - 1 ==DOB13){
                    valid = 1;
                }
                else{
                    printf("Invalid age");
                }
            }
            // length of stay validation check
            while( valid == 1) {
                printf("\nWhat is the length of your stay? :");
                fflush(stdin);
                scanf("%d", &guest1[2]);
                if(guest1[2] > 50){
                    printf("You cannot stay over 50 days");
                }
                else if(guest1[2] < 1){
                    printf("Invalid length of stay");
                }
                else{
                    valid = 0;
                }
            }

            //board type validation check
            while(valid == 0) {
                printf("\nWhat board type would you like? Full board(F), Half board(H), Bed and Breakfast(B) :");
                fflush(stdin);
                scanf("%c", &board);
                if (board == 70) {
                    guest1[1] = 1;
                    valid = 1;
                } else if (board == 72) {
                    guest1[1] = 2;
                    valid = 1;
                } else if (board == 66) {
                    guest1[1] = 3;
                    valid = 1;
                }
                else{
                    printf("Invalid board type, try again.");
                }
            }

            //guest number validation check
            while(valid == 1) {
                printf("\nHow many people will be staying in the room? :");
                fflush(stdin);
                scanf("%d", &guest1[3]);
                if (guest1[3] > 4) {
                    printf("The maximum people per room is 4.");
                }
                else if(guest1[3] < 1){
                    printf("Invalid number of guests.");
                }
                else{
                    valid = 0;
                }
            }
            //child number validation check
            while(valid == 0){
                printf("\nHow many children are there? :");
                fflush(stdin);
                scanf("%d", &guest1[4]);
                if(guest1[4] > 3){
                    printf("Invalid number of children");
                }
                else if(guest1[4] < 0){
                    printf("Invalid number of children");
                }
                else if(guest1[4] >= guest1[3]){
                    printf("Invalid number of children");
                }
                else{
                    valid = 1;
                }
            }
            //daily paper question mark
            while(valid == 1) {
                printf("\nDo you want a daily paper? y/n :");
                fflush(stdin);
                scanf("%c", &dp);
                if(dp == 121){
                    guest1[5] = 1;
                    valid = 0;
                }
                else if(dp == 110){
                    guest1[5] = 0;
                    valid = 0;
                }
                else{
                    printf("Invalid response");
                }
            }
            // booking id maker
            for(int uppy = 0; uppy < 20; uppy++){
                if(guestsurname1[uppy] == '\0'){
                    bookingID1[uppy] = rand() %9 + 48;
                    bookingID1[uppy + 1] = rand() %9 + 48;
                    uppy = 21;
                }
                bookingID1[uppy] = guestsurname1[uppy];
            }

            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest1[0],guest1[1],guest1[2],guest1[3],guest1[4],guest1[5],guest1[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname1 , guestsurname1 , DOB11 , DOB12 , DOB13 , guest1[0], guest1[3] , guest1[4] , guest1[2] , guest1[1] , guest1[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID1);

            room1 = 1;
            // room1 = 1   if 1 means room is booked, if 0 means room is empty
            break;
        case 2:
// room 2 stuff
            if(room2 == 1){
                printf("This room is booked, try another room.\n");
                break;
            }
            guest2[0] = 2;
            //name and surname separate because the space was messing me up
            printf("\nPlease enter your first name :");
            fflush(stdin);
            scanf("%s", guestname2);

            printf("\nPlease enter your surname :");
            fflush(stdin);
            scanf("%s", guestsurname2);
            // Date Of Birth (guest1) (pos1-3) might be able to simplify later + validation check
            while(valid == 0) {
                printf("\nPlease enter your date of birth in the format DD/MM/YYYY :");
                fflush(stdin);
                scanf("%d/%d/%d", &DOB21, &DOB22, &DOB23);
                if(DOB22 == 2){
                    if(DOB21 > 29){
                        printf("Invalid day");
                    }
                }
                else if(DOB21 < 1 || DOB21 > 31){
                    printf("invalid day");
                }
                else if(DOB22 < 1 || DOB22 > 12) {
                    printf("Invalid month");
                }
                else if(DOB23 > 2005){
                    printf("You are too young to book a room.");
                }
                else if(DOB23 < 1903){
                    printf("You are too old to book a room");
                }
                else{
                    valid = 1;
                }
            }

            //Ask for age because I cant be bothered to calculate it
            valid = 0;
            while(valid == 0){
                printf("\nPlease enter your age :");
                fflush(stdin);
                scanf("%d", &guest2[6]);
                if(2023 - guest2[6] == DOB23){
                    valid = 1;
                }
                else if(2023 - guest2[6] + 1 == DOB23){
                    valid = 1;
                }
                else if(2023 - guest2[6] - 1 ==DOB23){
                    valid = 1;
                }
                else{
                    printf("Invalid age");
                }
            }

            // length of stay validation check
            while( valid == 1) {
                printf("\nWhat is the length of your stay? :");
                fflush(stdin);
                scanf("%d", &guest2[2]);
                if(guest2[2] > 50){
                    printf("You cannot stay over 50 days");
                }
                else if(guest2[2] < 1){
                    printf("Invalid length of stay");
                }
                else{
                    valid = 0;
                }
            }

            //board type validation check
            while(valid == 0) {
                printf("\nWhat board type would you like? Full board(F), Half board(H), Bed and Breakfast(B) :");
                fflush(stdin);
                scanf("%c", &board);
                if (board == 70) {
                    guest2[1] = 1;
                    valid = 1;
                } else if (board == 72) {
                    guest2[1] = 2;
                    valid = 1;
                } else if (board == 66) {
                    guest2[1] = 3;
                    valid = 1;
                }
                else{
                    printf("Invalid board type, try again.");
                }
            }

            //guest number validation check
            while(valid == 1) {
                printf("\nHow many people will be staying in the room? :");
                fflush(stdin);
                scanf("%d", &guest2[3]);
                if (guest2[3] > 4) {
                    printf("The maximum people per room is 4.");
                }
                else if(guest2[3] < 1){
                    printf("Invalid number of guests.");
                }
                else{
                    valid = 0;
                }
            }
            //child number validation check
            while(valid == 0){
                printf("\nHow many children are there? :");
                fflush(stdin);
                scanf("%d", &guest2[4]);
                if(guest2[4] > 3){
                    printf("Invalid number of children");
                }
                else if(guest2[4] < 0){
                    printf("Invalid number of children");
                }
                else if(guest2[4] >= guest2[3]){
                    printf("Invalid number of children");
                }
                else{
                    valid = 1;
                }
            }
            //daily paper question mark
            while(valid == 1) {
                printf("\nDo you want a daily paper? y/n :");
                fflush(stdin);
                scanf("%c", &dp);
                if(dp == 121){
                    guest2[5] = 1;
                    valid = 0;
                }
                else if(dp == 110){
                    guest2[5] = 0;
                    valid = 0;
                }
                else{
                    printf("Invalid response");
                }
            }
            // booking id maker
            for(int uppy = 0; uppy < 20; uppy++){
                if(guestsurname2[uppy] == '\0'){
                    bookingID2[uppy] = rand() %9 + 48;
                    bookingID2[uppy + 1] = rand() %9 + 48;
                    uppy = 21;
                }
                bookingID2[uppy] = guestsurname2[uppy];
            }

            printf("\n%d,%d,%d,%d,%d,%d\n",guest2[0],guest2[1],guest2[2],guest2[3],guest2[4],guest2[5],guest2[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname2 , guestsurname2 , DOB21 , DOB22 , DOB23 , guest2[0], guest2[3] , guest2[4] , guest2[2] , guest2[1] , guest2[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID2);

            room2 = 1;
            break;
        case 3:
// room 3 stuff
            if(room3 == 1){
                printf("This room is booked, try another room.\n");
                break;
            }
            guest3[0] = 3;
            //name and surname separate because the space was messing me up
            printf("\nPlease enter your first name :");
            fflush(stdin);
            scanf("%s", guestname3);

            printf("\nPlease enter your surname :");
            fflush(stdin);
            scanf("%s", guestsurname3);
            // Date Of Birth (guest1) (pos1-3) might be able to simplify later + validation check
            while(valid == 0) {
                printf("\nPlease enter your date of birth in the format DD/MM/YYYY :");
                fflush(stdin);
                scanf("%d/%d/%d", &DOB31, &DOB32, &DOB33);
                if(DOB32 == 2){
                    if(DOB31 > 29){
                        printf("Invalid day");
                    }
                }
                else if(DOB31 < 1  || DOB31 > 31){
                    printf("invalid day");
                }
                else if(DOB32 < 1 || DOB32 > 12){
                    printf("Invalid month");
                }
                else if(DOB33 > 2005){
                    printf("You are too young to book a room.");
                }
                else if(DOB33 < 1903){
                    printf("You are too old to book a room");
                }
                else{
                    valid = 1;
                }
            }
            //Ask for age because I cant be bothered to calculate it
            valid = 0;
            while(valid == 0){
                printf("\nPlease enter your age :");
                fflush(stdin);
                scanf("%d", &guest3[6]);
                if(2023 - guest3[6] == DOB33){
                    valid = 1;
                }
                else if(2023 - guest3[6] + 1 == DOB33){
                    valid = 1;
                }
                else if(2023 - guest3[6] - 1 ==DOB33){
                    valid = 1;
                }
                else{
                    printf("Invalid age");
                }
            }
            // length of stay validation check
            while( valid == 1) {
                printf("\nWhat is the length of your stay? :");
                fflush(stdin);
                scanf("%d", &guest3[2]);
                if(guest3[2] > 50){
                    printf("You cannot stay over 50 days");
                }
                else if(guest3[2] < 1){
                    printf("Invalid length of stay");
                }
                else{
                    valid = 0;
                }
            }

            //board type validation check
            while(valid == 0) {
                printf("\nWhat board type would you like? Full board(F), Half board(H), Bed and Breakfast(B) :");
                fflush(stdin);
                scanf("%c", &board);
                if (board == 70) {
                    guest3[1] = 1;
                    valid = 1;
                } else if (board == 72) {
                    guest3[1] = 2;
                    valid = 1;
                } else if (board == 66) {
                    guest3[1] = 3;
                    valid = 1;
                }
                else{
                    printf("Invalid board type, try again.");
                }
            }

            //guest number validation check
            while(valid == 1) {
                printf("\nHow many people will be staying in the room? :");
                fflush(stdin);
                scanf("%d", &guest3[3]);
                if (guest3[3] > 4) {
                    printf("The maximum people per room is 4.");
                }
                else if(guest3[3] < 1){
                    printf("Invalid number of guests.");
                }
                else{
                    valid = 0;
                }
            }
            //child number validation check
            while(valid == 0){
                printf("\nHow many children are there? :");
                fflush(stdin);
                scanf("%d", &guest3[4]);
                if(guest3[4] > 3){
                    printf("Invalid number of children");
                }
                else if(guest3[4] < 0){
                    printf("Invalid number of children");
                }
                else if(guest3[4] >= guest3[3]){
                    printf("Invalid number of children");
                }
                else{
                    valid = 1;
                }
            }
            //daily paper question mark
            while(valid == 1) {
                printf("\nDo you want a daily paper? y/n :");
                fflush(stdin);
                scanf("%c", &dp);
                if(dp == 121){
                    guest3[5] = 1;
                    valid = 0;
                }
                else if(dp == 110){
                    guest3[5] = 0;
                    valid = 0;
                }
                else{
                    printf("Invalid response");
                }
            }
            // booking id maker
            for(int uppy = 0; uppy < 20; uppy++){
                if(guestsurname3[uppy] == '\0'){
                    bookingID3[uppy] = rand() %9 + 48;
                    bookingID3[uppy + 1] = rand() %9 + 48;
                    uppy = 21;
                }
                bookingID3[uppy] = guestsurname3[uppy];
            }

            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest3[0],guest3[1],guest3[2],guest3[3],guest3[4],guest3[5],guest3[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname3 , guestsurname3 , DOB31 , DOB32 , DOB33 , guest3[0], guest3[3] , guest3[4] , guest3[2] , guest3[1] , guest3[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID3);

            room3 = 1;
            break;
        case 4:
// room 4 stuff
            if(room4 == 1){
                printf("This room is booked, try another room.\n");
                break;
            }
            guest4[0] = 4;
            //name and surname separate because the space was messing me up
            printf("\nPlease enter your first name :");
            fflush(stdin);
            scanf("%s", guestname4);

            printf("\nPlease enter your surname :");
            fflush(stdin);
            scanf("%s", guestsurname4);
            // Date Of Birth (guest1) (pos1-3) might be able to simplify later + validation check
            while(valid == 0) {
                printf("\nPlease enter your date of birth in the format DD/MM/YYYY :");
                fflush(stdin);
                scanf("%d/%d/%d", &DOB41, &DOB42, &DOB43);
                if(DOB42 == 2){
                    if(DOB41 > 29){
                        printf("Invalid day");
                    }
                }
                else if(DOB41 < 1  || DOB41 > 31){
                    printf("invalid day");
                }
                else if(DOB42 < 1 || DOB42 > 12){
                    printf("Invalid month");
                }
                else if(DOB43 > 2005){
                    printf("You are too young to book a room.");
                }
                else if(DOB43 < 1903){
                    printf("You are too old to book a room");
                }
                else{
                    valid = 1;
                }
            }
            //Ask for age because I cant be bothered to calculate it
            valid = 0;
            while(valid == 0){
                printf("\nPlease enter your age :");
                fflush(stdin);
                scanf("%d", &guest4[6]);
                if(2023 - guest4[6] == DOB43){
                    valid = 1;
                }
                else if(2023 - guest4[6] + 1 == DOB43){
                    valid = 1;
                }
                else if(2023 - guest4[6] - 1 ==DOB43){
                    valid = 1;
                }
                else{
                    printf("Invalid age");
                }
            }
            // length of stay validation check
            while( valid == 1) {
                printf("\nWhat is the length of your stay? :");
                fflush(stdin);
                scanf("%d", &guest4[2]);
                if(guest4[2] > 50){
                    printf("You cannot stay over 50 days");
                }
                else if(guest4[2] < 1){
                    printf("Invalid length of stay");
                }
                else{
                    valid = 0;
                }
            }

            //board type validation check
            while(valid == 0) {
                printf("\nWhat board type would you like? Full board(F), Half board(H), Bed and Breakfast(B) :");
                fflush(stdin);
                scanf("%c", &board);
                if (board == 70) {
                    guest4[1] = 1;
                    valid = 1;
                } else if (board == 72) {
                    guest4[1] = 2;
                    valid = 1;
                } else if (board == 66) {
                    guest4[1] = 3;
                    valid = 1;
                }
                else{
                    printf("Invalid board type, try again.");
                }
            }

            //guest number validation check
            while(valid == 1) {
                printf("\nHow many people will be staying in the room? :");
                fflush(stdin);
                scanf("%d", &guest4[3]);
                if (guest4[3] > 4) {
                    printf("The maximum people per room is 4.");
                }
                else if(guest4[3] < 1){
                    printf("Invalid number of guests.");
                }
                else{
                    valid = 0;
                }
            }
            //child number validation check
            while(valid == 0){
                printf("\nHow many children are there? :");
                fflush(stdin);
                scanf("%d", &guest4[4]);
                if(guest4[4] > 3){
                    printf("Invalid number of children");
                }
                else if(guest4[4] < 0){
                    printf("Invalid number of children");
                }
                else if(guest4[4] >= guest4[3]){
                    printf("Invalid number of children");
                }
                else{
                    valid = 1;
                }
            }
            //daily paper question mark
            while(valid == 1) {
                printf("\nDo you want a daily paper? y/n :");
                fflush(stdin);
                scanf("%c", &dp);
                if(dp == 121){
                    guest4[5] = 1;
                    valid = 0;
                }
                else if(dp == 110){
                    guest4[5] = 0;
                    valid = 0;
                }
                else{
                    printf("Invalid response");
                }
            }
            // booking id maker
            for(int uppy = 0; uppy < 20; uppy++){
                if(guestsurname4[uppy] == '\0'){
                    bookingID4[uppy] = rand() %9 + 48;
                    bookingID4[uppy + 1] = rand() %9 + 48;
                    uppy = 21;
                }
                bookingID4[uppy] = guestsurname4[uppy];
            }

            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest4[0],guest4[1],guest4[2],guest4[3],guest4[4],guest4[5],guest4[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname4 , guestsurname4 , DOB41 , DOB42 , DOB43 , guest4[0], guest4[3] , guest4[4] , guest4[2] , guest4[1] , guest4[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID4);

            room4 = 1;
            break;
        case 5:
// room 5 stuff
            if(room5 == 1){
                printf("This room is booked, try another room.\n");
                break;
            }
            guest5[0] = 5;
            //name and surname separate because the space was messing me up
            printf("\nPlease enter your first name :");
            fflush(stdin);
            scanf("%s", guestname5);

            printf("\nPlease enter your surname :");
            fflush(stdin);
            scanf("%s", guestsurname5);
            // Date Of Birth (guest1) (pos1-3) might be able to simplify later + validation check
            while(valid == 0) {
                printf("\nPlease enter your date of birth in the format DD/MM/YYYY :");
                fflush(stdin);
                scanf("%d/%d/%d", &DOB51, &DOB52, &DOB53);
                if(DOB52 == 2){
                    if(DOB51 > 29){
                        printf("Invalid day February");
                    }
                }
                else if(DOB51 < 1 || DOB51 > 31){
                    printf("invalid day else");
                }
                else if(DOB52 < 1 || DOB52 > 12) {
                    printf("Invalid month");
                }
                else if(DOB53 > 2005){
                    printf("You are too young to book a room.");
                }
                else if(DOB53 < 1903){
                    printf("You are too old to book a room");
                }
                else{
                    valid = 1;
                }
            }
            //Ask for age because I cant be bothered to calculate it
            valid = 0;
            while(valid == 0){
                printf("\nPlease enter your age :");
                fflush(stdin);
                scanf("%d", &guest5[6]);
                if(2023 - guest5[6] == DOB53){
                    valid = 1;
                }
                else if(2023 - guest5[6] + 1 == DOB53){
                    valid = 1;
                }
                else if(2023 - guest5[6] - 1 ==DOB53){
                    valid = 1;
                }
                else{
                    printf("Invalid age");
                }
            }
            // length of stay validation check
            while( valid == 1) {
                printf("\nWhat is the length of your stay? :");
                fflush(stdin);
                scanf("%d", &guest5[2]);
                if(guest5[2] > 50){
                    printf("You cannot stay over 50 days");
                }
                else if(guest5[2] < 1){
                    printf("Invalid length of stay");
                }
                else{
                    valid = 0;
                }
            }

            //board type validation check
            while(valid == 0) {
                printf("\nWhat board type would you like? Full board(F), Half board(H), Bed and Breakfast(B) :");
                fflush(stdin);
                scanf("%c", &board);
                if (board == 70) {
                    guest5[1] = 1;
                    valid = 1;
                } else if (board == 72) {
                    guest5[1] = 2;
                    valid = 1;
                } else if (board == 66) {
                    guest5[1] = 3;
                    valid = 1;
                }
                else{
                    printf("Invalid board type, try again.");
                }
            }

            //guest number validation check
            while(valid == 1) {
                printf("\nHow many people will be staying in the room? :");
                fflush(stdin);
                scanf("%d", &guest5[3]);
                if (guest5[3] > 4) {
                    printf("The maximum people per room is 4.");
                }
                else if(guest5[3] < 1){
                    printf("Invalid number of guests.");
                }
                else{
                    valid = 0;
                }
            }
            //child number validation check
            while(valid == 0){
                printf("\nHow many children are there? :");
                fflush(stdin);
                scanf("%d", &guest5[4]);
                if(guest5[4] > 3){
                    printf("Invalid number of children");
                }
                else if(guest5[4] < 0){
                    printf("Invalid number of children");
                }
                else if(guest5[4] >= guest5[3]){
                    printf("Invalid number of children");
                }
                else{
                    valid = 1;
                }
            }
            //daily paper question mark
            while(valid == 1) {
                printf("\nDo you want a daily paper? y/n :");
                fflush(stdin);
                scanf("%c", &dp);
                if(dp == 121){
                    guest5[5] = 1;
                    valid = 0;
                }
                else if(dp == 110){
                    guest5[5] = 0;
                    valid = 0;
                }
                else{
                    printf("Invalid response");
                }
            }
            // booking id maker
            for(int uppy = 0; uppy < 20; uppy++){
                if(guestsurname5[uppy] == '\0'){
                    bookingID5[uppy] = rand() %9 + 48;
                    bookingID5[uppy + 1] = rand() %9 + 48;
                    uppy = 21;
                }
                bookingID5[uppy] = guestsurname5[uppy];
            }

            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest5[0],guest5[1],guest5[2],guest5[3],guest5[4],guest5[5],guest5[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname5 , guestsurname5 , DOB51 , DOB52 , DOB53 , guest5[0], guest5[3] , guest5[4] , guest5[2] , guest5[1] , guest5[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID5);

            room5 = 1;
            break;
        case 6:
// room 6 stuff
            if(room6 == 1){
                printf("This room is booked, try another room.\n");
                break;
            }
            guest6[0] = 6;
            //name and surname separate because the space was messing me up
            printf("\nPlease enter your first name :");
            fflush(stdin);
            scanf("%s", guestname6);

            printf("\nPlease enter your surname :");
            fflush(stdin);
            scanf("%s", guestsurname6);
            // Date Of Birth (guest1) (pos1-3) might be able to simplify later + validation check
            while(valid == 0) {
                printf("\nPlease enter your date of birth in the format DD/MM/YYYY :");
                fflush(stdin);
                scanf("%d/%d/%d", &DOB61, &DOB62, &DOB63);
                if(DOB62 == 2){
                    if(DOB61 > 29){
                        printf("Invalid day February");
                    }
                }
                else if(DOB61 < 1 || DOB61 > 31){
                    printf("invalid day else");
                }
                else if(DOB62 < 1 || DOB62 > 12) {
                    printf("Invalid month");
                }
                else if(DOB63 > 2005){
                    printf("You are too young to book a room.");
                }
                else if(DOB63 < 1903){
                    printf("You are too old to book a room");
                }
                else{
                    valid = 1;
                }
            }
            //Ask for age because I cant be bothered to calculate it
            valid = 0;
            while(valid == 0){
                printf("\nPlease enter your age :");
                fflush(stdin);
                scanf("%d", &guest6[6]);
                if(2023 - guest6[6] == DOB63){
                    valid = 1;
                }
                else if(2023 - guest6[6] + 1 == DOB63){
                    valid = 1;
                }
                else if(2023 - guest6[6] - 1 ==DOB63){
                    valid = 1;
                }
                else{
                    printf("Invalid age");
                }
            }
            // length of stay validation check
            while( valid == 1) {
                printf("\nWhat is the length of your stay? :");
                fflush(stdin);
                scanf("%d", &guest6[2]);
                if(guest6[2] > 50){
                    printf("You cannot stay over 50 days");
                }
                else if(guest6[2] < 1){
                    printf("Invalid length of stay");
                }
                else{
                    valid = 0;
                }
            }

            //board type validation check
            while(valid == 0) {
                printf("\nWhat board type would you like? Full board(F), Half board(H), Bed and Breakfast(B) :");
                fflush(stdin);
                scanf("%c", &board);
                if (board == 70) {
                    guest6[1] = 1;
                    valid = 1;
                } else if (board == 72) {
                    guest6[1] = 2;
                    valid = 1;
                } else if (board == 66) {
                    guest6[1] = 3;
                    valid = 1;
                }
                else{
                    printf("Invalid board type, try again.");
                }
            }

            //guest number validation check
            while(valid == 1) {
                printf("\nHow many people will be staying in the room? :");
                fflush(stdin);
                scanf("%d", &guest6[3]);
                if (guest6[3] > 4) {
                    printf("The maximum people per room is 4.");
                }
                else if(guest6[3] < 1){
                    printf("Invalid number of guests.");
                }
                else{
                    valid = 0;
                }
            }
            //child number validation check
            while(valid == 0){
                printf("\nHow many children are there? :");
                fflush(stdin);
                scanf("%d", &guest6[4]);
                if(guest6[4] > 3){
                    printf("Invalid number of children");
                }
                else if(guest6[4] < 0){
                    printf("Invalid number of children");
                }
                else if(guest6[4] >= guest6[3]){
                    printf("Invalid number of children");
                }
                else{
                    valid = 1;
                }
            }
            //daily paper question mark
            while(valid == 1) {
                printf("\nDo you want a daily paper? y/n :");
                fflush(stdin);
                scanf("%c", &dp);
                if(dp == 121){
                    guest6[5] = 1;
                    valid = 0;
                }
                else if(dp == 110){
                    guest6[5] = 0;
                    valid = 0;
                }
                else{
                    printf("Invalid response");
                }
            }
            // booking id maker
            for(int uppy = 0; uppy < 20; uppy++){
                if(guestsurname6[uppy] == '\0'){
                    bookingID6[uppy] = rand() %9 + 48;
                    bookingID6[uppy + 1] = rand() %9 + 48;
                    uppy = 21;
                }
                bookingID6[uppy] = guestsurname6[uppy];
            }

            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest6[0],guest6[1],guest6[2],guest6[3],guest6[4],guest6[5],guest6[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname6 , guestsurname6 , DOB61 , DOB62 , DOB63 , guest6[0], guest6[3] , guest6[4] , guest6[2] , guest6[1] , guest6[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID6);

            room6 = 1;
            break;
    }
}
void quickcheckout(){
    int roomstay = 0;
    int valid = 0;
    while(valid == 0) {
        printf("\nPlease enter your room number :");
        fflush(stdin);
        scanf("%d", &roomstay);
        switch (roomstay) {
            case 1:
                room1 = 0;
                valid = 1;
                break;
            case 2:
                room2 = 0;
                valid = 1;
                break;
            case 3:
                room3 = 0;
                valid = 1;
                break;
            case 4:
                room4 = 0;
                valid = 1;
                break;
            case 5:
                room5 = 0;
                valid = 1;
                break;
            case 6:
                room6 = 0;
                valid = 1;
                break;
            default:
                printf("\nInvalid room number");
        }
    }
    printf("\nYou're all checked out, hope you enjoyed your stay.\n");
}
void checkstoreddata(){
    int choice = 0;
    printf("what guest data would you like to view? :");
    fflush(stdin);
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest1[0],guest1[1],guest1[2],guest1[3],guest1[4],guest1[5],guest1[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname1 , guestsurname1 , DOB11 , DOB12 , DOB13 , guest1[0], guest1[3] , guest1[4] , guest1[2] , guest1[1] , guest1[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID1);
            break;
        case 2:
            printf("\n%d,%d,%d,%d,%d,%d\n",guest2[0],guest2[1],guest2[2],guest2[3],guest2[4],guest2[5],guest2[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname2 , guestsurname2 , DOB21 , DOB22 , DOB23 , guest2[0], guest2[3] , guest2[4] , guest2[2] , guest2[1] , guest2[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID2);
            break;
        case 3:
            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest3[0],guest3[1],guest3[2],guest3[3],guest3[4],guest3[5],guest3[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname3 , guestsurname3 , DOB31 , DOB32 , DOB33 , guest3[0], guest3[3] , guest3[4] , guest3[2] , guest3[1] , guest3[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID3);
            break;
        case 4:
            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest4[0],guest4[1],guest4[2],guest4[3],guest4[4],guest4[5],guest4[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname4 , guestsurname4 , DOB41 , DOB42 , DOB43 , guest4[0], guest4[3] , guest4[4] , guest4[2] , guest4[1] , guest4[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID4);
            break;
        case 5:
            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest5[0],guest5[1],guest5[2],guest5[3],guest5[4],guest5[5],guest5[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname5 , guestsurname5 , DOB51 , DOB52 , DOB53 , guest5[0], guest5[3] , guest5[4] , guest5[2] , guest5[1] , guest5[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID5);
            break;
        case 6:
            printf("\n%d,%d,%d,%d,%d,%d,%d\n",guest6[0],guest6[1],guest6[2],guest6[3],guest6[4],guest6[5],guest6[6]);
            printf("\n%s %s \n DOB: %d/%d/%d \n room: %d \n no. guests: %d \n no. children: %d \n length of stay: %d \n board type (Full-1/Half-2/B&B-3) :%d \n daily paper(y-1/n-0) : %d", guestname6 , guestsurname6 , DOB61 , DOB62 , DOB63 , guest6[0], guest6[3] , guest6[4] , guest6[2] , guest6[1] , guest6[5]);
            printf("\n\n Your booking ID is: %s \n Write this down or remember it because you need it to book dinner tables or check out.\n\n", bookingID6);
            break;
        default:
            printf("invalid guest number");
    }

}


void BookTable() {
    int valid;
    int TableTime1;
    int TableTime2;
    int TableTime3;
    int TableTime4;
    int TableTime5;
    int TableTime6;
    int TableType1;
    int TableType2;
    int TableType3;
    int TableType4;
    int TableType5;
    int TableType6;
    int NoOfGuestsAtTable1;
    int NoOfGuestsAtTable2;
    int NoOfGuestsAtTable3;
    int NoOfGuestsAtTable4;
    int NoOfGuestsAtTable5;
    int NoOfGuestsAtTable6;
    int E7pmAvailable;
    int N7pmAvailable;
    int T7pmAvailable;
    int E9pmAvailable;
    int N9pmAvailable;
    int T9pmAvailable;
    int BookingID = 0;
    char BookingIDInputComparison[30];


    printf(BLUE"Hello! Please enter your booking ID so we can check if you are able too book a table: ");//Checking against Booking ID
    scanf("%s", &BookingIDInputComparison);

    if (BookingID == (strcmp(BookingIDInputComparison, bookingID1))) {
        int DorR1;
        printf("Please enter 1 if you would like to make a table reservation of 2 if you would like to get rid of any existing reservations: ");
        scanf("%d", &DorR1);
        if (DorR1 == 1) {

            if (guest1[1] == 3) {
                printf(RED"You are unable to book a table, as you have selected the Bed in Breakfast board type. Please try booking again.\n");
                BookTable();
            } else {
                if (TableAvailable1[0][0] == 1 || TableAvailable2[0][0] == 1 || TableAvailable3[0][0] == 1 ||
                    TableAvailable4[0][0] == 1 || TableAvailable5[0][0] == 1 ||
                    TableAvailable6[0][0] == 1) { //Displaying if the table is available.
                    printf(RED"Table Endoor is booked at 7pm.\n");
                    E7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 7pm.\n");
                }
                if (TableAvailable1[0][1] == 1 || TableAvailable2[0][1] == 1 || TableAvailable3[0][1] == 1 ||
                    TableAvailable4[0][1] == 1 || TableAvailable5[0][1] == 1 || TableAvailable6[0][1] == 1) {
                    printf(RED"Table Naboo is booked at 7pm.\n");
                    N7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 7pm.\n");
                }
                if (TableAvailable1[0][2] == 1 || TableAvailable2[0][2] == 1 || TableAvailable3[0][2] == 1 ||
                    TableAvailable4[0][2] == 1 || TableAvailable5[0][2] == 1 || TableAvailable6[0][2] == 1) {
                    printf(RED"Table Tatooine is booked at 7pm.\n");
                    T7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 7pm.\n");
                }
                if (TableAvailable1[1][0] == 1 || TableAvailable2[1][0] == 1 || TableAvailable3[1][0] == 1 ||
                    TableAvailable4[1][0] == 1 || TableAvailable5[1][0] == 1 || TableAvailable6[1][0] == 1) {
                    printf(RED"Table Endoor is booked at 9pm.\n");
                    E9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 9pm.\n");
                }
                if (TableAvailable1[1][1] == 1 || TableAvailable2[1][1] == 1 || TableAvailable3[1][1] == 1 ||
                    TableAvailable4[1][1] == 1 || TableAvailable5[1][1] == 1 || TableAvailable6[1][1] == 1) {
                    printf(RED"Table Naboo is booked at 9pm.\n");
                    N9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 9pm.\n");
                }
                if (TableAvailable1[1][2] == 1 || TableAvailable2[1][2] == 1 || TableAvailable3[1][2] == 1 ||
                    TableAvailable4[1][2] == 1 || TableAvailable5[1][2] == 1 || TableAvailable6[1][2] == 1) {
                    printf(RED"Table Tatooine is booked at 9pm.\n");
                    T9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 9pm.\n");
                }
                do {
                    printf(BLUE"At what time would you like to book a table? 7 or 9? (Input 1 for 7 and 2 for 9: ");
                    scanf("%d", &TableTime1);
                    fflush(stdin);
                } while (TableTime1 < 0 || TableTime1 > 3);

                if (TableTime1 == 1 || TableTime1 == 2) {  //Validating the Table Time
                    valid = 1;
                } else {
                    valid = 0;
                }
                while (valid == 0) {
                    printf(RED"Data inputted is invalid. Please try booking a table again.\n");
                    BookTable();
                }
                while (valid == 1) {//Storing booked table time

                    printf(BLUE"Which dinner table would you like to eat at? Endoor, Naboo, or Tatooine? (Input 1 for Endoor, 2 for Naboo, or 3 for Tatooine: ");
                    scanf("%d", &TableType1);
                    fflush(stdin);
                    if (TableType1 == 1 || TableType1 == 2 || TableType1 == 3) {
                        valid = 1;
                    } else {
                        valid = 0;
                    }

                    printf(BLUE"How many guests will be eating at your booked table? (Max of 4): ");
                    scanf("%d", &NoOfGuestsAtTable1);
                    fflush(stdin);
                    if (NoOfGuestsAtTable1 > 4 || NoOfGuestsAtTable1 < 1) {
                        valid = 0;
                    } else {
                        valid = 1;
                    }

                    if (valid == 1) {//Storing booking table data

                        if (TableType1 == 1) {

                            if (TableTime1 == 1) {
                                if (E7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please try booking another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable1[0][0] = 1;
                                    TableAvailable1[0][3] = NoOfGuestsAtTable1;
                                }
                            }
                            if (TableTime1 == 2) {
                                if (E9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable1[1][0] = 1;
                                    TableAvailable1[1][3] = NoOfGuestsAtTable1;
                                }
                            }
                        }
                        if (TableType1 == 2) {

                            if (TableTime1 == 1) {
                                if (N7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable1[0][1] = 1;
                                    TableAvailable1[0][4] = NoOfGuestsAtTable1;
                                }
                            }
                            if (TableTime1 == 2) {
                                if (N9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable1[1][1] = 1;
                                    TableAvailable1[1][4] = NoOfGuestsAtTable1;
                                }
                            }
                        }
                        if (TableType1 == 3) {
                            if (TableTime1 == 1) {
                                if (T7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable1[0][2] = 1;
                                    TableAvailable1[0][5] = NoOfGuestsAtTable1;
                                }
                            }
                            if (TableTime1 == 2) {
                                if (T9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable1[1][2] = 1;
                                    TableAvailable1[1][5] = NoOfGuestsAtTable1;
                                }
                            }
                        }
                        if (TableAvailable1[0][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 7pm.\n");
                        }
                        if (TableAvailable1[0][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 7pm.\n");
                        }
                        if (TableAvailable1[0][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 7pm.\n");
                        }
                        if (TableAvailable1[1][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 9pm.\n");
                        }
                        if (TableAvailable1[1][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 9pm.\n");
                        }
                        if (TableAvailable1[1][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 9pm.\n");
                        }
                        printf(YELLOW"Endoor 7pm = %d with %d guests.\nNaboo 7pm = %d with %d guests.\nTatooine 7pm = %d with %d guests.\nEndoor 9pm = %d with %d guests.\nNaboo 9pm = %d with %d guests.\nTatooine 9pm = %d with %d guests.\n",
                               TableAvailable1[0][0], TableAvailable1[0][3],
                               TableAvailable1[0][1], TableAvailable1[0][4],
                               TableAvailable1[0][2], TableAvailable1[0][5],
                               TableAvailable1[1][0], TableAvailable1[1][3],
                               TableAvailable1[1][1], TableAvailable1[1][4],
                               TableAvailable1[1][2], TableAvailable1[1][5]);
                        printf(""RESET);
                        return;
                    }
                }
            }
        }
        if(DorR1 == 2){
            int TableAvailable1[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};

        }
        else{
            printf("Veriable input unrecognised.");
            return;
        }
    }


    if (BookingID == (strcmp(BookingIDInputComparison, bookingID2))) {
        int DorR2;
        printf("Please enter 1 if you would like to make a table reservation of 2 if you would like to get rid of any existing reservations: ");
        scanf("%d", &DorR2);
        if (DorR2 == 1) {
            if (guest2[1] == 3) {
                printf(RED"You are unable to book a table, as you have selected the Bed in Breakfast board type. Please try booking again.\n");
                BookTable();
            } else {
                if (TableAvailable1[0][0] == 1 || TableAvailable2[0][0] == 1 || TableAvailable3[0][0] == 1 ||
                    TableAvailable4[0][0] == 1 || TableAvailable5[0][0] == 1 ||
                    TableAvailable6[0][0] == 1) { //Displaying if the table is available.
                    printf(RED"Table Endoor is booked at 7pm.\n");
                    E7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 7pm.\n");
                }
                if (TableAvailable1[0][1] == 1 || TableAvailable2[0][1] == 1 || TableAvailable3[0][1] == 1 ||
                    TableAvailable4[0][1] == 1 || TableAvailable5[0][1] == 1 || TableAvailable6[0][1] == 1) {
                    printf(RED"Table Naboo is booked at 7pm.\n");
                    N7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 7pm.\n");
                }
                if (TableAvailable1[0][2] == 1 || TableAvailable2[0][2] == 1 || TableAvailable3[0][2] == 1 ||
                    TableAvailable4[0][2] == 1 || TableAvailable5[0][2] == 1 || TableAvailable6[0][2] == 1) {
                    printf(RED"Table Tatooine is booked at 7pm.\n");
                    T7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 7pm.\n");
                }
                if (TableAvailable1[1][0] == 1 || TableAvailable2[1][0] == 1 || TableAvailable3[1][0] == 1 ||
                    TableAvailable4[1][0] == 1 || TableAvailable5[1][0] == 1 || TableAvailable6[1][0] == 1) {
                    printf(RED"Table Endoor is booked at 9pm.\n");
                    E9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 9pm.\n");
                }
                if (TableAvailable1[1][1] == 1 || TableAvailable2[1][1] == 1 || TableAvailable3[1][1] == 1 ||
                    TableAvailable4[1][1] == 1 || TableAvailable5[1][1] == 1 || TableAvailable6[1][1] == 1) {
                    printf(RED"Table Naboo is booked at 9pm.\n");
                    N9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 9pm.\n");
                }
                if (TableAvailable1[1][2] == 1 || TableAvailable2[1][2] == 1 || TableAvailable3[1][2] == 1 ||
                    TableAvailable4[1][2] == 1 || TableAvailable5[1][2] == 1 || TableAvailable6[1][2] == 1) {
                    printf(RED"Table Tatooine is booked at 9pm.\n");
                    T9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 9pm.\n");
                }
                do {
                    printf(BLUE"At what time would you like to book a table? 7 or 9? (Input 1 for 7 and 2 for 9: ");
                    scanf("%d", &TableTime2);
                    fflush(stdin);
                } while (TableTime2 < 0 || TableTime2 > 3);

                if (TableTime2 == 1 || TableTime2 == 2) {  //Validating the Table Time
                    valid = 1;
                } else {
                    valid = 0;
                }
                while (valid == 0) {
                    printf(RED"Data inputted is invalid. Please try booking a table again.\n");
                    BookTable();
                }
                while (valid == 1) {//Storing booked table time

                    printf(BLUE"Which dinner table would you like to eat at? Endoor, Naboo, or Tatooine? (Input 1 for Endoor, 2 for Naboo, or 3 for Tatooine: ");
                    scanf("%d", &TableType2);
                    fflush(stdin);
                    if (TableType2 == 1 || TableType2 == 2 || TableType2 == 3) {
                        valid = 1;
                    } else {
                        valid = 0;
                    }

                    printf(BLUE"How many guests will be eating at your booked table? (Max of 4): ");
                    scanf("%d", &NoOfGuestsAtTable2);
                    fflush(stdin);
                    if (NoOfGuestsAtTable2 > 4 || NoOfGuestsAtTable2 < 1) {
                        valid = 0;
                    } else {
                        valid = 1;
                    }

                    if (valid == 1) {//Storing booking table data

                        if (TableType2 == 1) {

                            if (TableTime2 == 1) {
                                if (E7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please try booking another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable2[0][0] = 1;
                                    TableAvailable2[0][3] = NoOfGuestsAtTable2;
                                }
                            }
                            if (TableTime2 == 2) {
                                if (E9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable2[1][0] = 1;
                                    TableAvailable2[1][3] = NoOfGuestsAtTable2;
                                }
                            }
                        }
                        if (TableType2 == 2) {

                            if (TableTime2 == 1) {
                                if (N7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable2[0][1] = 1;
                                    TableAvailable2[0][4] = NoOfGuestsAtTable2;
                                }
                            }
                            if (TableTime2 == 2) {
                                if (N9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable2[1][1] = 1;
                                    TableAvailable2[1][4] = NoOfGuestsAtTable2;
                                }
                            }
                        }
                        if (TableType2 == 3) {
                            if (TableTime2 == 1) {
                                if (T7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable2[0][2] = 1;
                                    TableAvailable2[0][5] = NoOfGuestsAtTable2;
                                }
                            }
                            if (TableTime2 == 2) {
                                if (T9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable2[1][2] = 1;
                                    TableAvailable2[1][5] = NoOfGuestsAtTable2;
                                }
                            }
                        }
                        if (TableAvailable2[0][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 7pm.\n");
                        }
                        if (TableAvailable2[0][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 7pm.\n");
                        }
                        if (TableAvailable2[0][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 7pm.\n");
                        }
                        if (TableAvailable2[1][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 9pm.\n");
                        }
                        if (TableAvailable2[1][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 9pm.\n");
                        }
                        if (TableAvailable2[1][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 9pm.\n");
                        }
                        printf(YELLOW"Endoor 7pm = %d with %d guests.\nNaboo 7pm = %d with %d guests.\nTatooine 7pm = %d with %d guests.\nEndoor 9pm = %d with %d guests.\nNaboo 9pm = %d with %d guests.\nTatooine 9pm = %d with %d guests.\n",
                               TableAvailable2[0][0], TableAvailable2[0][3],
                               TableAvailable2[0][1], TableAvailable2[0][4],
                               TableAvailable2[0][2], TableAvailable2[0][5],
                               TableAvailable2[1][0], TableAvailable2[1][3],
                               TableAvailable2[1][1], TableAvailable2[1][4],
                               TableAvailable2[1][2], TableAvailable2[1][5]);
                        printf(""RESET);
                        return;
                    }
                }
            }
        }
        if(DorR2 == 2){
            int TableAvailable2[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
        }
        else{
            printf("Veriable unrecognised.");
            return;
        }
    }


    if (BookingID == (strcmp(BookingIDInputComparison, bookingID3))) {
        int DorR3;
        printf("Please enter 1 if you would like to make a table reservation of 2 if you would like to get rid of any existing reservations: ");
        scanf("%d", &DorR3);
        if (DorR3 == 1) {
            if (guest3[1] == 3) {
                printf(RED"You are unable to book a table, as you have selected the Bed in Breakfast board type. Please try booking again.\n");
                BookTable();
            } else {
                if (TableAvailable1[0][0] == 1 || TableAvailable2[0][0] == 1 || TableAvailable3[0][0] == 1 ||
                    TableAvailable4[0][0] == 1 || TableAvailable5[0][0] == 1 ||
                    TableAvailable6[0][0] == 1) { //Displaying if the table is available.
                    printf(RED"Table Endoor is booked at 7pm.\n");
                    E7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 7pm.\n");
                }
                if (TableAvailable1[0][1] == 1 || TableAvailable2[0][1] == 1 || TableAvailable3[0][1] == 1 ||
                    TableAvailable4[0][1] == 1 || TableAvailable5[0][1] == 1 || TableAvailable6[0][1] == 1) {
                    printf(RED"Table Naboo is booked at 7pm.\n");
                    N7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 7pm.\n");
                }
                if (TableAvailable1[0][2] == 1 || TableAvailable2[0][2] == 1 || TableAvailable3[0][2] == 1 ||
                    TableAvailable4[0][2] == 1 || TableAvailable5[0][2] == 1 || TableAvailable6[0][2] == 1) {
                    printf(RED"Table Tatooine is booked at 7pm.\n");
                    T7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 7pm.\n");
                }
                if (TableAvailable1[1][0] == 1 || TableAvailable2[1][0] == 1 || TableAvailable3[1][0] == 1 ||
                    TableAvailable4[1][0] == 1 || TableAvailable5[1][0] == 1 || TableAvailable6[1][0] == 1) {
                    printf(RED"Table Endoor is booked at 9pm.\n");
                    E9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 9pm.\n");
                }
                if (TableAvailable1[1][1] == 1 || TableAvailable2[1][1] == 1 || TableAvailable3[1][1] == 1 ||
                    TableAvailable4[1][1] == 1 || TableAvailable5[1][1] == 1 || TableAvailable6[1][1] == 1) {
                    printf(RED"Table Naboo is booked at 9pm.\n");
                    N9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 9pm.\n");
                }
                if (TableAvailable1[1][2] == 1 || TableAvailable2[1][2] == 1 || TableAvailable3[1][2] == 1 ||
                    TableAvailable4[1][2] == 1 || TableAvailable5[1][2] == 1 || TableAvailable6[1][2] == 1) {
                    printf(RED"Table Tatooine is booked at 9pm.\n");
                    T9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 9pm.\n");
                }

                do {
                    printf(BLUE"At what time would you like to book a table? 7 or 9? (Input 1 for 7 and 2 for 9: ");
                    scanf("%d", &TableTime3);
                    fflush(stdin);
                } while (TableTime3 < 0 || TableTime3 > 3);

                if (TableTime3 == 1 || TableTime3 == 2) {  //Validating the Table Time
                    valid = 1;
                } else {
                    valid = 0;
                }
                while (valid == 0) {
                    printf(RED"Data inputted is invalid. Please try booking a table again.\n");
                    BookTable();
                }
                while (valid == 1) {//Storing booked table time

                    printf(BLUE"Which dinner table would you like to eat at? Endoor, Naboo, or Tatooine? (Input 1 for Endoor, 2 for Naboo, or 3 for Tatooine: ");
                    scanf("%d", &TableType3);
                    fflush(stdin);
                    if (TableType3 == 1 || TableType3 == 2 || TableType3 == 3) {
                        valid = 1;
                    } else {
                        valid = 0;
                    }

                    printf(BLUE"How many guests will be eating at your booked table? (Max of 4): ");
                    scanf("%d", &NoOfGuestsAtTable3);
                    fflush(stdin);
                    if (NoOfGuestsAtTable3 > 4 || NoOfGuestsAtTable3 < 1) {
                        valid = 0;
                    } else {
                        valid = 1;
                    }

                    if (valid == 1) {//Storing booking table data

                        if (TableType3 == 1) {

                            if (TableTime3 == 1) {
                                if (E7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please try booking another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable3[0][0] = 1;
                                    TableAvailable3[0][3] = NoOfGuestsAtTable3;
                                }
                            }
                            if (TableTime3 == 2) {
                                if (E9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable3[1][0] = 1;
                                    TableAvailable3[1][3] = NoOfGuestsAtTable3;
                                }
                            }
                        }
                        if (TableType3 == 2) {

                            if (TableTime3 == 1) {
                                if (N7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable3[0][1] = 1;
                                    TableAvailable3[0][4] = NoOfGuestsAtTable3;
                                }
                            }
                            if (TableTime3 == 2) {
                                if (N9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable3[1][1] = 1;
                                    TableAvailable3[1][4] = NoOfGuestsAtTable3;
                                }
                            }
                        }
                        if (TableType3 == 3) {
                            if (TableTime3 == 1) {
                                if (T7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable3[0][2] = 1;
                                    TableAvailable3[0][5] = NoOfGuestsAtTable3;
                                }
                            }
                            if (TableTime3 == 2) {
                                if (T9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable3[1][2] = 1;
                                    TableAvailable3[1][5] = NoOfGuestsAtTable3;
                                }
                            }
                        }
                        if (TableAvailable3[0][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 7pm.\n");
                        }
                        if (TableAvailable3[0][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 7pm.\n");
                        }
                        if (TableAvailable3[0][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 7pm.\n");
                        }
                        if (TableAvailable3[1][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 9pm.\n");
                        }
                        if (TableAvailable3[1][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 9pm.\n");
                        }
                        if (TableAvailable3[1][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 9pm.\n");
                        }
                        printf(YELLOW"Endoor 7pm = %d with %d guests.\nNaboo 7pm = %d with %d guests.\nTatooine 7pm = %d with %d guests.\nEndoor 9pm = %d with %d guests.\nNaboo 9pm = %d with %d guests.\nTatooine 9pm = %d with %d guests.\n",
                               TableAvailable3[0][0], TableAvailable3[0][3],
                               TableAvailable3[0][1], TableAvailable3[0][4],
                               TableAvailable3[0][2], TableAvailable3[0][5],
                               TableAvailable3[1][0], TableAvailable3[1][3],
                               TableAvailable3[1][1], TableAvailable3[1][4],
                               TableAvailable3[1][2], TableAvailable3[1][5]);
                        printf(""RESET);
                        return;
                    }
                }
            }
        }
        if(DorR3 == 2){
            int TableAvailable1[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
        }
        else{
            printf("Veriable unrecognised");
            return;
        }
    }
    if (BookingID == (strcmp(BookingIDInputComparison, bookingID4))) {
        int DorR4;
        printf("Please enter 1 if you would like to make a table reservation of 2 if you would like to get rid of any existing reservations: ");
        scanf("%d", &DorR4);
        if (DorR4 == 1) {
            if (guest4[1] == 3) {
                printf(RED"You are unable to book a table, as you have selected the Bed in Breakfast board type. Please try booking again.\n");
                BookTable();
            } else {
                if (TableAvailable1[0][0] == 1 || TableAvailable2[0][0] == 1 || TableAvailable3[0][0] == 1 ||
                    TableAvailable4[0][0] == 1 || TableAvailable5[0][0] == 1 ||
                    TableAvailable6[0][0] == 1) { //Displaying if the table is available.
                    printf(RED"Table Endoor is booked at 7pm.\n");
                    E7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 7pm.\n");
                }
                if (TableAvailable1[0][1] == 1 || TableAvailable2[0][1] == 1 || TableAvailable3[0][1] == 1 ||
                    TableAvailable4[0][1] == 1 || TableAvailable5[0][1] == 1 || TableAvailable6[0][1] == 1) {
                    printf(RED"Table Naboo is booked at 7pm.\n");
                    N7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 7pm.\n");
                }
                if (TableAvailable1[0][2] == 1 || TableAvailable2[0][2] == 1 || TableAvailable3[0][2] == 1 ||
                    TableAvailable4[0][2] == 1 || TableAvailable5[0][2] == 1 || TableAvailable6[0][2] == 1) {
                    printf(RED"Table Tatooine is booked at 7pm.\n");
                    T7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 7pm.\n");
                }
                if (TableAvailable1[1][0] == 1 || TableAvailable2[1][0] == 1 || TableAvailable3[1][0] == 1 ||
                    TableAvailable4[1][0] == 1 || TableAvailable5[1][0] == 1 || TableAvailable6[1][0] == 1) {
                    printf(RED"Table Endoor is booked at 9pm.\n");
                    E9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 9pm.\n");
                }
                if (TableAvailable1[1][1] == 1 || TableAvailable2[1][1] == 1 || TableAvailable3[1][1] == 1 ||
                    TableAvailable4[1][1] == 1 || TableAvailable5[1][1] == 1 || TableAvailable6[1][1] == 1) {
                    printf(RED"Table Naboo is booked at 9pm.\n");
                    N9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 9pm.\n");
                }
                if (TableAvailable1[1][2] == 1 || TableAvailable2[1][2] == 1 || TableAvailable3[1][2] == 1 ||
                    TableAvailable4[1][2] == 1 || TableAvailable5[1][2] == 1 || TableAvailable6[1][2] == 1) {
                    printf(RED"Table Tatooine is booked at 9pm.\n");
                    T9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 9pm.\n");
                }

                do {
                    printf(BLUE"At what time would you like to book a table? 7 or 9? (Input 1 for 7 and 2 for 9: ");
                    scanf("%d", &TableTime4);
                    fflush(stdin);
                } while (TableTime4 < 0 || TableTime4 > 3);

                if (TableTime4 == 1 || TableTime4 == 2) {  //Validating the Table Time
                    valid = 1;
                } else {
                    valid = 0;
                }
                while (valid == 0) {
                    printf(RED"Data inputted is invalid. Please try booking a table again.\n");
                    BookTable();
                }
                while (valid == 1) {//Storing booked table time

                    printf(BLUE"Which dinner table would you like to eat at? Endoor, Naboo, or Tatooine? (Input 1 for Endoor, 2 for Naboo, or 3 for Tatooine: ");
                    scanf("%d", &TableType4);
                    fflush(stdin);
                    if (TableType4 == 1 || TableType4 == 2 || TableType4 == 3) {
                        valid = 1;
                    } else {
                        valid = 0;
                    }

                    printf(BLUE"How many guests will be eating at your booked table? (Max of 4): ");
                    scanf("%d", &NoOfGuestsAtTable4);
                    fflush(stdin);
                    if (NoOfGuestsAtTable4 > 4 || NoOfGuestsAtTable4 < 1) {
                        valid = 0;
                    } else {
                        valid = 1;
                    }

                    if (valid == 1) {//Storing booking table data

                        if (TableType4 == 1) {

                            if (TableTime4 == 1) {
                                if (E7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please try booking another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable4[0][0] = 1;
                                    TableAvailable4[0][3] = NoOfGuestsAtTable4;
                                }
                            }
                            if (TableTime4 == 2) {
                                if (E9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable4[1][0] = 1;
                                    TableAvailable4[1][3] = NoOfGuestsAtTable4;
                                }
                            }
                        }
                        if (TableType4 == 2) {

                            if (TableTime4 == 1) {
                                if (N7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable4[0][1] = 1;
                                    TableAvailable4[0][4] = NoOfGuestsAtTable4;
                                }
                            }
                            if (TableTime4 == 2) {
                                if (N9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable4[1][1] = 1;
                                    TableAvailable4[1][4] = NoOfGuestsAtTable4;
                                }
                            }
                        }
                        if (TableType4 == 3) {
                            if (TableTime4 == 1) {
                                if (T7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable4[0][2] = 1;
                                    TableAvailable4[0][5] = NoOfGuestsAtTable4;
                                }
                            }
                            if (TableTime4 == 2) {
                                if (T9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable4[1][2] = 1;
                                    TableAvailable4[1][5] = NoOfGuestsAtTable4;
                                }
                            }
                        }
                        if (TableAvailable4[0][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 7pm.\n");
                        }
                        if (TableAvailable4[0][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 7pm.\n");
                        }
                        if (TableAvailable4[0][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 7pm.\n");
                        }
                        if (TableAvailable4[1][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 9pm.\n");
                        }
                        if (TableAvailable4[1][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 9pm.\n");
                        }
                        if (TableAvailable4[1][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 9pm.\n");
                        }
                        printf(YELLOW"Endoor 7pm = %d with %d guests.\nNaboo 7pm = %d with %d guests.\nTatooine 7pm = %d with %d guests.\nEndoor 9pm = %d with %d guests.\nNaboo 9pm = %d with %d guests.\nTatooine 9pm = %d with %d guests.\n",
                               TableAvailable4[0][0], TableAvailable4[0][3],
                               TableAvailable4[0][1], TableAvailable4[0][4],
                               TableAvailable4[0][2], TableAvailable4[0][5],
                               TableAvailable4[1][0], TableAvailable4[1][3],
                               TableAvailable4[1][1], TableAvailable4[1][4],
                               TableAvailable6[1][2], TableAvailable6[1][5]);
                        printf(""RESET);
                        return;
                    }
                }
            }
        }
        if(DorR4 == 2){
            int TableAvailable4[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
        }
        else{
            printf("Veriable input unrecognised.");
            return;
        }
    }
    if (BookingID == (strcmp(BookingIDInputComparison, bookingID5))) {
        int DorR5;
        printf("Please enter 1 if you would like to make a table reservation of 2 if you would like to get rid of any existing reservations: ");
        scanf("%d", &DorR5);
        if (DorR5 == 1) {
            if (guest5[1] == 3) {
                printf(GREEN"You are unable to book a table, as you have selected the Bed in Breakfast board type. Please try booking again.\n");
                BookTable();
            } else {
                if (TableAvailable1[0][0] == 1 || TableAvailable2[0][0] == 1 || TableAvailable3[0][0] == 1 ||
                    TableAvailable4[0][0] == 1 || TableAvailable5[0][0] == 1 ||
                    TableAvailable6[0][0] == 1) { //Displaying if the table is available.
                    printf(RED"Table Endoor is booked at 7pm.\n");
                    E7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 7pm.\n");
                }
                if (TableAvailable1[0][1] == 1 || TableAvailable2[0][1] == 1 || TableAvailable3[0][1] == 1 ||
                    TableAvailable4[0][1] == 1 || TableAvailable5[0][1] == 1 || TableAvailable6[0][1] == 1) {
                    printf(RED"Table Naboo is booked at 7pm.\n");
                    N7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 7pm.\n");
                }
                if (TableAvailable1[0][2] == 1 || TableAvailable2[0][2] == 1 || TableAvailable3[0][2] == 1 ||
                    TableAvailable4[0][2] == 1 || TableAvailable5[0][2] == 1 || TableAvailable6[0][2] == 1) {
                    printf(RED"Table Tatooine is booked at 7pm.\n");
                    T7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 7pm.\n");
                }
                if (TableAvailable1[1][0] == 1 || TableAvailable2[1][0] == 1 || TableAvailable3[1][0] == 1 ||
                    TableAvailable4[1][0] == 1 || TableAvailable5[1][0] == 1 || TableAvailable6[1][0] == 1) {
                    printf(RED"Table Endoor is booked at 9pm.\n");
                    E9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 9pm.\n");
                }
                if (TableAvailable1[1][1] == 1 || TableAvailable2[1][1] == 1 || TableAvailable3[1][1] == 1 ||
                    TableAvailable4[1][1] == 1 || TableAvailable5[1][1] == 1 || TableAvailable6[1][1] == 1) {
                    printf(RED"Table Naboo is booked at 9pm.\n");
                    N9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 9pm.\n");
                }
                if (TableAvailable1[1][2] == 1 || TableAvailable2[1][2] == 1 || TableAvailable3[1][2] == 1 ||
                    TableAvailable4[1][2] == 1 || TableAvailable5[1][2] == 1 || TableAvailable6[1][2] == 1) {
                    printf(RED"Table Tatooine is booked at 9pm.\n");
                    T9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 9pm.\n");
                }

                do {
                    printf(BLUE"At what time would you like to book a table? 7 or 9? (Input 1 for 7 and 2 for 9: ");
                    scanf("%d", &TableTime5);
                    fflush(stdin);
                } while (TableTime5 < 0 || TableTime5 > 3);

                if (TableTime5 == 1 || TableTime5 == 2) {  //Validating the Table Time
                    valid = 1;
                } else {
                    valid = 0;
                }
                while (valid == 0) {
                    printf(RED"Data inputted is invalid. Please try booking a table again.\n");
                    BookTable();
                }
                while (valid == 1) {//Storing booked table time

                    printf(BLUE"Which dinner table would you like to eat at? Endoor, Naboo, or Tatooine? (Input 1 for Endoor, 2 for Naboo, or 3 for Tatooine: ");
                    scanf("%d", &TableType5);
                    fflush(stdin);
                    if (TableType5 == 1 || TableType5 == 2 || TableType5 == 3) {
                        valid = 1;
                    } else {
                        valid = 0;
                    }

                    printf(BLUE"How many guests will be eating at your booked table? (Max of 4): ");
                    scanf("%d", &NoOfGuestsAtTable5);
                    fflush(stdin);
                    if (NoOfGuestsAtTable5 > 4 || NoOfGuestsAtTable5 < 1) {
                        valid = 0;
                    } else {
                        valid = 1;
                    }

                    if (valid == 1) {//Storing booking table data

                        if (TableType5 == 1) {

                            if (TableTime5 == 1) {
                                if (E7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please try booking another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable5[0][0] = 1;
                                    TableAvailable5[0][3] = NoOfGuestsAtTable5;
                                }
                            }
                            if (TableTime5 == 2) {
                                if (E9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable5[1][0] = 1;
                                    TableAvailable5[1][3] = NoOfGuestsAtTable5;
                                }
                            }
                        }
                        if (TableType5 == 2) {

                            if (TableTime5 == 1) {
                                if (N7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable5[0][1] = 1;
                                    TableAvailable5[0][4] = NoOfGuestsAtTable5;
                                }
                            }
                            if (TableTime5 == 2) {
                                if (N9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable5[1][1] = 1;
                                    TableAvailable5[1][4] = NoOfGuestsAtTable5;
                                }
                            }
                        }
                        if (TableType5 == 3) {
                            if (TableTime5 == 1) {
                                if (T7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable5[0][2] = 1;
                                    TableAvailable5[0][5] = NoOfGuestsAtTable5;
                                }
                            }
                            if (TableTime5 == 2) {
                                if (T9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable5[1][2] = 1;
                                    TableAvailable5[1][5] = NoOfGuestsAtTable5;
                                }
                            }
                        }
                        if (TableAvailable5[0][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 7pm.\n");
                        }
                        if (TableAvailable5[0][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 7pm.\n");
                        }
                        if (TableAvailable5[0][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 7pm.\n");
                        }
                        if (TableAvailable5[1][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 9pm.\n");
                        }
                        if (TableAvailable5[1][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 9pm.\n");
                        }
                        if (TableAvailable5[1][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 9pm.\n");
                        }
                        printf(YELLOW"Endoor 7pm = %d with %d guests.\nNaboo 7pm = %d with %d guests.\nTatooine 7pm = %d with %d guests.\nEndoor 9pm = %d with %d guests.\nNaboo 9pm = %d with %d guests.\nTatooine 9pm = %d with %d guests.\n",
                               TableAvailable5[0][0], TableAvailable5[0][3],
                               TableAvailable5[0][1], TableAvailable5[0][4],
                               TableAvailable5[0][2], TableAvailable5[0][5],
                               TableAvailable5[1][0], TableAvailable5[1][3],
                               TableAvailable5[1][1], TableAvailable5[1][4],
                               TableAvailable5[1][2], TableAvailable5[1][5]);
                        printf(""RESET);
                        return;
                    }
                }
            }
        }
        if(DorR5 == 2){
            int TableAvailable5[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
        }
        else{
            printf("Veriable input unrecognised.");
            return;
        }
    }
    if (BookingID == (strcmp(BookingIDInputComparison, bookingID6))) {
        int DorR6;
        printf("Please enter 1 if you would like to make a table reservation of 2 if you would like to get rid of any existing reservations: ");
        scanf("%d", &DorR6);
        if (DorR6 == 1) {
            if (guest6[1] == 3) {
                printf(RED"You are unable to book a table, as you have selected the Bed in Breakfast board type. Please try booking again.\n");
                BookTable();
            } else {
                if (TableAvailable1[0][0] == 1 || TableAvailable2[0][0] == 1 || TableAvailable3[0][0] == 1 ||
                    TableAvailable4[0][0] == 1 || TableAvailable5[0][0] == 1 ||
                    TableAvailable6[0][0] == 1) { //Displaying if the table is available.
                    printf(RED"Table Endoor is booked at 7pm.\n");
                    E7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 7pm.\n");
                }
                if (TableAvailable1[0][1] == 1 || TableAvailable2[0][1] == 1 || TableAvailable3[0][1] == 1 ||
                    TableAvailable4[0][1] == 1 || TableAvailable5[0][1] == 1 || TableAvailable6[0][1] == 1) {
                    printf(RED"Table Naboo is booked at 7pm.\n");
                    N7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 7pm.\n");
                }
                if (TableAvailable1[0][2] == 1 || TableAvailable2[0][2] == 1 || TableAvailable3[0][2] == 1 ||
                    TableAvailable4[0][2] == 1 || TableAvailable5[0][2] == 1 || TableAvailable6[0][2] == 1) {
                    printf(RED"Table Tatooine is booked at 7pm.\n");
                    T7pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 7pm.\n");
                }
                if (TableAvailable1[1][0] == 1 || TableAvailable2[1][0] == 1 || TableAvailable3[1][0] == 1 ||
                    TableAvailable4[1][0] == 1 || TableAvailable5[1][0] == 1 || TableAvailable6[1][0] == 1) {
                    printf(RED"Table Endoor is booked at 9pm.\n");
                    E9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Endoor is available at 9pm.\n");
                }
                if (TableAvailable1[1][1] == 1 || TableAvailable2[1][1] == 1 || TableAvailable3[1][1] == 1 ||
                    TableAvailable4[1][1] == 1 || TableAvailable5[1][1] == 1 || TableAvailable6[1][1] == 1) {
                    printf(RED"Table Naboo is booked at 9pm.\n");
                    N9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Naboo is available at 9pm.\n");
                }
                if (TableAvailable1[1][2] == 1 || TableAvailable2[1][2] == 1 || TableAvailable3[1][2] == 1 ||
                    TableAvailable4[1][2] == 1 || TableAvailable5[1][2] == 1 || TableAvailable6[1][2] == 1) {
                    printf(RED"Table Tatooine is booked at 9pm.\n");
                    T9pmAvailable = 0;
                } else {
                    printf(GREEN"Table Tatooine is available at 9pm.\n");
                }

                do {
                    printf(BLUE"At what time would you like to book a table? 7 or 9? (Input 1 for 7 and 2 for 9: ");
                    scanf("%d", &TableTime6);
                    fflush(stdin);
                } while (TableTime6 < 0 || TableTime6 > 3);

                if (TableTime6 == 1 || TableTime6 == 2) {  //Validating the Table Time
                    valid = 1;
                } else {
                    valid = 0;
                }
                while (valid == 0) {
                    printf(RED"Data inputted is invalid. Please try booking a table again.\n");
                    BookTable();
                }
                while (valid == 1) {//Storing booked table time

                    printf(BLUE"Which dinner table would you like to eat at? Endoor, Naboo, or Tatooine? (Input 1 for Endoor, 2 for Naboo, or 3 for Tatooine: ");
                    scanf("%d", &TableType6);
                    fflush(stdin);
                    if (TableType6 == 1 || TableType6 == 2 || TableType6 == 3) {
                        valid = 1;
                    } else {
                        valid = 0;
                    }

                    printf(BLUE"How many guests will be eating at your booked table? (Max of 4): ");
                    scanf("%d", &NoOfGuestsAtTable6);
                    fflush(stdin);
                    if (NoOfGuestsAtTable6 > 4 || NoOfGuestsAtTable6 < 1) {
                        valid = 0;
                    } else {
                        valid = 1;
                    }

                    if (valid == 1) {//Storing booking table data

                        if (TableType6 == 1) {

                            if (TableTime6 == 1) {
                                if (E7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please try booking another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable6[0][0] = 1;
                                    TableAvailable6[0][3] = NoOfGuestsAtTable6;
                                }
                            }
                            if (TableTime6 == 2) {
                                if (E9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable6[1][0] = 1;
                                    TableAvailable6[1][3] = NoOfGuestsAtTable6;
                                }
                            }
                        }
                        if (TableType6 == 2) {

                            if (TableTime6 == 1) {
                                if (N7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable6[0][1] = 1;
                                    TableAvailable6[0][4] = NoOfGuestsAtTable6;
                                }
                            }
                            if (TableTime6 == 2) {
                                if (N9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable6[1][1] = 1;
                                    TableAvailable6[1][4] = NoOfGuestsAtTable6;
                                }
                            }
                        }
                        if (TableType6 == 3) {
                            if (TableTime6 == 1) {
                                if (T7pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable6[0][2] = 1;
                                    TableAvailable6[0][5] = NoOfGuestsAtTable6;
                                }
                            }
                            if (TableTime6 == 2) {
                                if (T9pmAvailable == 0) {
                                    printf(RED"This Table is already booked. Please book a another table.\n");
                                    BookTable();
                                } else {
                                    TableAvailable6[1][2] = 1;
                                    TableAvailable6[1][5] = NoOfGuestsAtTable6;
                                }
                            }
                        }
                        if (TableAvailable6[0][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 7pm.\n");
                        }
                        if (TableAvailable6[0][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 7pm.\n");
                        }
                        if (TableAvailable6[0][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 7pm.\n");
                        }
                        if (TableAvailable6[1][0] == 1) {
                            printf(GREEN"You have successfully booked Endoor for 9pm.\n");
                        }
                        if (TableAvailable6[1][1] == 1) {
                            printf(GREEN"You have successfully booked Naboo for 9pm.\n");
                        }
                        if (TableAvailable6[1][2] == 1) {
                            printf(GREEN"You have successfully booked Tatooine for 9pm.\n");
                        }
                        printf(YELLOW"Endoor 7pm = %d with %d guests.\nNaboo 7pm = %d with %d guests.\nTatooine 7pm = %d with %d guests.\nEndoor 9pm = %d with %d guests.\nNaboo 9pm = %d with %d guests.\nTatooine 9pm = %d with %d guests.\n",
                               TableAvailable6[0][0], TableAvailable6[0][3],
                               TableAvailable6[0][1], TableAvailable6[0][4],
                               TableAvailable6[0][2], TableAvailable6[0][5],
                               TableAvailable6[1][0], TableAvailable6[1][3],
                               TableAvailable6[1][1], TableAvailable6[1][4],
                               TableAvailable6[1][2], TableAvailable6[1][5]);
                        printf(""RESET);

                        return;
                    }
                }
            }
        }
        if(DorR6 == 2){
            int TableAvailable6[2][6] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
        }
        else{
            printf(RED"Variable input unrecognised.");
            return;
        }
    } else {
        printf(RED"Your inputed BookingID does not match with any in the database. Please try again.\n");
        return;
    }
}


int checkout(int info1[7],int info2[7],int info3[7],int info4[7],int info5[7],int info6[7],char bookingID1[30],char bookingID2[30],char bookingID3[30],char bookingID4[30],char bookingID5[30],char bookingID6[30]){
    char ID[30];
    int info[7],room=0,i;
    while(room==0) { //loops until the booking ID entered is one of the 6 booking ID's on the system
        printf("Please enter your booking ID \n");
        fflush(stdin);
        gets(ID);
        int correct = 0;
        if (strcmp(ID, bookingID1) == 0 && ID[0]!=0) {
            printf("In data base. \n");
            for(i=0;i<7;i++){
                info[i]=info1[i];//assigns each value in the info array to a separate array, so I can use it
            }
            room = 1;
        }
        else if (strcmp(ID, bookingID2) == 0 && ID[0]!=0) {
            printf("In data base. \n");
            for(i=0;i<7;i++){
                info[i]=info2[i];//assigns each value in the info array to a separate array, so I can use it
            }
            room = 2;
        }
        else if (strcmp(ID, bookingID3) == 0 && ID[0]!=0) {
            printf("In data base. \n");
            for(i=0;i<7;i++){
                info[i]=info3[i];//assigns each value in the info array to a separate array, so I can use it
            }
            room = 3;
        }
        else if (strcmp(ID, bookingID4) == 0 && ID[0]!=0) {
            printf("In data base. \n");
            for(i=0;i<7;i++){
                info[i]=info4[i];//assigns each value in the info array to a separate array, so I can use it
            }
            room = 4;
        }
        else if (strcmp(ID, bookingID5) == 0 && ID[0]!=0) {
            printf("In data base. \n");
            for(i=0;i<7;i++) {
                info[i] = info5[i];//assigns each value in the info array to a separate array, so I can use it
            }
            room = 5;
        }
        else if (strcmp(ID, bookingID6) == 0 && ID[0]!=0) {
            printf("In data base. \n");
            for(i=0;i<7;i++){
                info[i]=info6[i];//assigns each value in the info array to a separate array, so I can use it
            }
            room = 6;
        }
        else{
            printf("Isn't in the data base please try again \n");
            room=0;
        }
    }
    char surname[30];
    printf("please enter your surname \n");
    gets(surname);
    float dailypaper,discount65,discountchild;
    int boardcost,daysxpeople,roomrate;
    float newroomrate,newboardcost,boardcostsingle,boardcostchildren;
    daysxpeople=(info[2]*info[3]);
    if(info[5]==1){
        dailypaper= 5.50;
    }
    else{
        dailypaper=0.00;
    }
    if(info[1]==3){
        boardcost=(5*daysxpeople);
    }
    else if(info[1]==2){
        boardcost=(15*daysxpeople);
    }
    else{
        boardcost=(20*daysxpeople);
    }
    if(info[0]==1||info[0]==2){
        roomrate=(100*info[2]);
    }
    else if(info[0]==3){
        roomrate=(85*info[2]);
    }
    else if(info[0]==4||info[0]==5){
        roomrate=(75*info[2]);
    }
    else{
        roomrate=(50*info[2]);
    }
    if(info[4]>0){
        boardcostsingle=(boardcost/info[3]);
        boardcostchildren=(boardcostsingle*info[4]);
        discountchild=(boardcostchildren/2);
        newboardcost=(boardcost-discountchild);
    }
    else{
        newboardcost=boardcost;
    }
    if(info[6]>65){ //checks if age is above 65
        discount65=(roomrate*0.1);
        newroomrate=(roomrate-discount65);
    }
    else{
        discount65=0;
        newroomrate=roomrate;
    }
    if(discount65>0 && discountchild>0){   //prints different results depending on what discount is used
        printf("bookingID: %s \nmr/mrs %s, \ndaily paper: %.2f, \nboard cost: $ %d, \nchild discount: -$ %.2f, \nroom rate: $ %d, \n65discount: -$ %.2f, \ntotal: $ %f \n",ID,surname,dailypaper,boardcost,discountchild,roomrate,discount65,(dailypaper+newboardcost+newroomrate));
    }
    else if(discount65>0 && discountchild==0){
        printf("bookingID: %s \nmr/mrs %s, \ndaily paper: %.2f, \nboard cost: $ %d, \nroom rate: $ %d, \n65discount: -$ %.2f, \ntotal: $ %.2f \n",ID,surname,dailypaper,boardcost,roomrate,discount65,(dailypaper+newboardcost+newroomrate));
    }
    else if(discount65==0 && discountchild>0){
        printf("bookingID: %s \nmr/mrs %s, \ndaily paper: %.2f, \nboard cost: $ %d, \nchild discount: -$ %.2f, \nroom rate: $ %d, \ntotal: $ %.2f \n",ID,surname,dailypaper,boardcost,discountchild,roomrate,(dailypaper+newboardcost+newroomrate));
    }
    else if(discount65==0 && discountchild==0){
        printf("bookingID: %s \nmr/mrs %s, \ndaily paper: %.2f, \nboard cost: £%d, \nroom rate: £%d, \ntotal: £%.2f \n",ID,surname,dailypaper,boardcost,roomrate,(dailypaper+newboardcost+newroomrate));
    }
    else{
        printf("error");
    }
    return room;

}