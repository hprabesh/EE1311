/*
 Name:Prabesh Humagain
 EDID: 1001734700
 EMail: prabesh.humagain@mavs.uta.edu
 GitHub: github.com/hprabesh
 */
#include <stdio.h>
#include "C:\ti\simplelink_msp432p4_sdk_3_40_01_02\source\ti\devices\msp432p4xx\inc\msp.h"
char currentState; //to find the current state of code
long int pushes; //find the state of pushes
struct node {
    int color;
    struct node* next;
}; //struct for the two variables to store colors: 1st var: Type of Color: 2nd Pointer for next variable _>Declaration of Single Linked List
typedef struct node color;//global linked list variable
color off, r, g, rg, b, rb, gb, rgb;
color* head;
void colorDecl() {
    //Created a linked list
    off.color = ~(BIT0 | BIT1 | BIT2);
    r.color = (BIT0 | (~(BIT2 | BIT1)));
    g.color = (BIT1 | (~(BIT0 | BIT2)));
    rg.color = ((BIT0 | BIT1) | (~BIT2));
    b.color = (BIT2 | (~(BIT0 | BIT1)));
    rb.color = ((BIT0 | BIT2) | (~BIT1));
    gb.color = ((BIT1 | BIT2) | (~BIT0));
    rgb.color = (BIT0 | BIT1 | BIT2);
    head = &off;
    off.next = &r;
    r.next = &g;
    g.next = &rg;
    rg.next = &b;
    b.next = &rb;
    rb.next = &gb;
    gb.next = &rgb;
    rgb.next = &off;
    //Ended LinkedList
}
void init(void) {
    //stop watchdog timer
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
    P1DIR |= BIT0;  //activating P1 dir for LED
    P2DIR |= (BIT0 | BIT1 | BIT2); // activating P2 dir for LED
    P1DIR &= ~(BIT1 | BIT4);
    P1REN |= (BIT1 | BIT4);
    P1OUT |= (BIT1 | BIT4); // internal resistor pull uped
    currentState = 0;
    pushes = 0;
    P1OUT &= ~(BIT0);
    P2OUT &= ~(BIT0 | BIT1 | BIT2);
} // pinMode all activated
void colorPrint() {
    color *temporary = head;
    int j = 1;
    int result;
    while (j <= pushes) {
        result = temporary->color;
        temporary = temporary->next;
        j += 1;
    }
    P2OUT = result;
}
void readS1Input() {
    if (!(P1IN & BIT1)) {           // Check status of S1 input
        pushes = pushes + 1;        // Keep track of push quantity internally
        P1OUT |= BIT0;
        colorPrint();
        // Perform counter increment
        while (!(P1IN & BIT1)) {};
    }
}
void readS2Input() {
    if (!(P1IN & BIT4)) {           // Check status of S1 input
        pushes = pushes - 1;        // Keep track of push quantity internally
        if (pushes<0)pushes=8;
        P1OUT &= ~BIT0;
        colorPrint();
        // Perform counter decrement
        while (!(P1IN & BIT4)) {};
    }
}

void main(void) {
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    init();
    colorDecl();

    while (1) {
        readS1Input();   // Check the S1 button
        readS2Input();   // Check the S2 button
    }
}

