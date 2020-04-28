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
char statusS1=0;//statusS1=0 means that the Switch S1 will fire on the falling edge
char statusS2=0;//statusS2=0 means that the Switch S2 will fire on the falling edge
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
    //starting the routine service timer
    P1->IES|=(BIT1|BIT4);
    P1->IE|=(BIT1|BIT4);
    P1->IFG=0;

    statusS1=0;
    statusS2=0;
    //clearing the status
    // Enable P1 interrupt on the NVIC
        NVIC->ISER[1] = 1 << ((PORT1_IRQn) & 31);

        // Enable PCM rude mode, which allows device to enter LPM3 without waiting for peripherals
        PCM->CTL1 = PCM_CTL0_KEY_VAL | PCM_CTL1_FORCE_LPM_ENTRY;

        // Enable global interrupt
        __enable_irq();

        // Setting the sleep deep bit
        SCB->SCR |= (SCB_SCR_SLEEPDEEP_Msk);

        // Do not wake up on exit from ISR
        SCB->SCR |= (SCB_SCR_SLEEPONEXIT_Msk);

        // Ensures SLEEPONEXIT takes effect immediately
        __DSB();

        // Go to LPM4
        __sleep();


} // pinMode all activated
void PORT1_IRQHandler(void){
    volatile uint32_t i;
    P1->IE|=(BIT1|BIT4); // disable the interrupt for port 1 in 1.1 and 1.4
    _delay_cycles(150000);
        if (P1->IFG & BIT1){
            if (statusS1==0){
                pushes = pushes + 1;        // Keep track of push quantity internally
                P1OUT |= BIT0;
                colorPrint();               //  display colours
                P1->IES^=BIT1;
                statusS1=1;
            }else {
                P1->IES^=BIT1;
                statusS1=0;
            }

        } else if (P1->IFG & BIT4){
            if (statusS2==0){
                pushes = pushes - 1;        // Keep track of push quantity internally
                if (pushes<0)pushes=8;
                P1OUT &= ~BIT0;
                colorPrint();               //display colours
                P1->IES^=BIT4;
                statusS2=1;
            }else {
                P1->IES^=BIT4;
                statusS2=0;
            }
        }

    P1->IFG&=~(BIT1|BIT4);
    P1->IE|=(BIT1|BIT4);

}
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
void main(void) {
    //WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    colorDecl();
    init();
}

