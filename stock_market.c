/*----------------------------------------------------------------------*/
/*  stock_market.c                                   by Kevin Peterson  */
/*                     Stock Market  Version 1.0                        */
/*                                                                      */
/*----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

main()
{
   /*  Variable declaration  */
   unsigned int seed;     /*  random integer seed value  */
   int week=1,            /*  week                       */
       pause,             /*  creates needed pause       */
       att=0,             /*  AT&T stock price           */
       ibm=0,             /*  IBM stock price            */
       pepsi=0,           /*  PEPSI stock price          */
       ge=0,              /*  GE stock price             */
       lucent=0,          /*  LUCENT stock price         */
       delta=0,           /*  DELTA stock price          */
       maytag=0,          /*  MAYTAG stock price         */
       att_last=0,        /*  last AT&T stock price      */
       ibm_last=0,        /*  last IBM stock price       */
       pepsi_last=0,      /*  last PEPSI stock price     */
       ge_last=0,         /*  last GE stock price        */
       lucent_last=0,     /*  last LUCENT stock price    */
       delta_last=0,      /*  last DELTA stock price     */
       maytag_last=0,     /*  last MAYTAG stock price    */
       att_change=0,      /*  AT&T change                */
       ibm_change=0,      /*  IBM change                 */
       pepsi_change=0,    /*  PEPSI change               */
       ge_change=0,       /*  GE change                  */
       lucent_change=0,   /*  LUCENT change              */
       delta_change=0,    /*  DELTA change               */
       maytag_change=0,   /*  MAYTAG change              */
       att_purchase=0,    /*  AT&T purchase price        */
       ibm_purchase=0,    /*  IBM purchase price         */
       pepsi_purchase=0,  /*  PEPSI purchase price       */
       ge_purchase=0,     /*  GE purchase price          */
       lucent_purchase=0, /*  LUCENT purchase price      */
       delta_purchase=0,  /*  DELTA purchase price       */
       maytag_purchase=0; /*  MAYTAG purchase price      */
   long spend,            /*  amount spent on a stock    */
        sell,             /*  number of shares sold      */
        borrow,           /*  loan input                 */
        borrow_limit=5000000, /*  max loan               */
        payback,          /*  loan payback amount        */
        loan=0,           /*  loan amount                */
        cash=5000,        /*  cash on hand               */
        stock_worth=0,    /*  stock worth at end of game */
        new_shares=0,     /*  new shares purchased       */
        att_shares=0,     /*  AT&T shares                */
        ibm_shares=0,     /*  IBM shares                 */
        pepsi_shares=0,   /*  PEPSI shares               */
        ge_shares=0,      /*  GE shares                  */
        lucent_shares=0,  /*  LUCENT shares              */
        delta_shares=0,   /*  DELTA shares               */
        maytag_shares=0;  /*  MAYTAG shares              */
   char selection;        /*  char input variable        */

   /*  get random seed value  */
   printf("Enter a positive integer seed value: ");
   scanf("%u", &seed);
   srand(seed);

   /*  Initial values  */

   att = (rand() % 120) + 1;
   ibm = (rand() % 120) + 1;
   pepsi = (rand() % 120) + 1;
   ge = (rand() % 120) + 1;
   lucent = (rand() % 120) + 1;
   delta = (rand() % 120) + 1;
   maytag = (rand() % 120) + 1;

   att_last = att;
   ibm_last = ibm;
   pepsi_last = pepsi;
   ge_last = ge;
   lucent_last = lucent;
   delta_last = delta;
   maytag_last = maytag;

   /***  main loop  */
   for (week=1; week<=10; week++)
   {
      while (1) /*  turn loop  */
      {
         clrscr();
         printf(" ________________________________________________________ \n");
         printf("|Stock |  Shares |Purchased|   Last  | Current |  Change |\n");
         printf("|AT&T  |  %7li|   %6i|   %6i|   %6i|   %6i|\n", att_shares, att_purchase, att_last, att, att_change);
         printf("|IBM   |  %7li|   %6i|   %6i|   %6i|   %6i|\n", ibm_shares, ibm_purchase, ibm_last, ibm, ibm_change);
         printf("|PEPSI |  %7li|   %6i|   %6i|   %6i|   %6i|\n", pepsi_shares, pepsi_purchase, pepsi_last, pepsi, pepsi_change);
         printf("|GE    |  %7li|   %6i|   %6i|   %6i|   %6i|\n", ge_shares, ge_purchase, ge_last, ge, ge_change);
         printf("|LUCENT|  %7li|   %6i|   %6i|   %6i|   %6i|\n", lucent_shares, lucent_purchase, lucent_last, lucent, lucent_change);
         printf("|DELTA |  %7li|   %6i|   %6i|   %6i|   %6i|\n", delta_shares, delta_purchase, delta_last, delta, delta_change);
         printf("|MAYTAG|  %7li|   %6i|   %6i|   %6i|   %6i|\n", maytag_shares, maytag_purchase, maytag_last, maytag, maytag_change);
         printf("|______|_________|_________|_________|_________|_________|\n");
         printf("|Cash:                   %12li|Week:            %2i|\n", cash, week);
         printf("|________________________________________________________|\n");
         printf(" Options: Buy - B   Sell - S   Loan - L   End Turn - E    \n");
         printf("Make your selection: ");
         scanf("%c", &selection);
         scanf("%c", &selection);

         /*  Check to see if user wants to exit  */
         if (selection == 'e' || selection == 'E')
            break;  /*  end turn if e or E  */
         switch (selection)
         {
            case 'b':
            case 'B':

               /*  BUY commands  */

               while (1)
               {
                  printf("Type first letter of stock or x to go back: ");
                  scanf("%c", &selection);
                  scanf("%c", &selection);
                  /*  CLEAR SCREEN  */
                  clrscr();
                  /*  check users selection  */
                  if (selection == 'x' || selection == 'X')
                     break;  /*  go back to prices if x or X  */
                  switch (selection)
                  {
                     case 'a':
                     case 'A':
                        printf("\n AT&T is currently $%3i per share.  You own %7li shares. \n", att, att_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How much would you like to spend? ");
                        scanf("%li", &spend);
                        if (spend <= 0)
                           break;
                        if (spend <= cash)
                        {
                           new_shares = spend / att;
                           att_shares = att_shares + (new_shares);
                           att_purchase = att;
                           cash = cash - (new_shares * att);
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that much money.\n");
                           continue;
                        }
                     case 'i':
                     case 'I':
                        printf("\n IBM is currently $%3i per share.  You own %7li shares. \n", ibm, ibm_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How much would you like to spend? ");
                        scanf("%li", &spend);
                        if (spend <= 0)
                           break;
                        if (spend <= cash)
                        {
                           new_shares = spend / ibm;
                           ibm_shares = ibm_shares + (new_shares);
                           ibm_purchase = ibm;
                           cash = cash - (new_shares * ibm);
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that much money.\n");
                           continue;
                        }
                     case 'p':
                     case 'P':
                        printf("\n PEPSI is currently $%3i per share.  You own %7li shares. \n", pepsi, pepsi_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How much would you like to spend? ");
                        scanf("%li", &spend);
                        if (spend <= 0)
                           break;
                        if (spend <= cash)
                        {
                           new_shares = spend / pepsi;
                           pepsi_shares = pepsi_shares + (new_shares);
                           pepsi_purchase = pepsi;
                           cash = cash - (new_shares * pepsi);
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that much money.\n");
                           continue;
                        }
                     case 'g':
                     case 'G':
                        printf("\n GE is currently $%3i per share.  You own %7li shares. \n", ge, ge_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How much would you like to spend? ");
                        scanf("%li", &spend);
                        if (spend <= 0)
                           break;
                        if (spend <= cash)
                        {
                           new_shares = spend / ge;
                           ge_shares = ge_shares + (new_shares);
                           ge_purchase = ge;
                           cash = cash - (new_shares * ge);
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that much money.\n");
                           continue;
                        }                        
                     case 'l':
                     case 'L':
                        printf("\n LUCENT is currently $%3i per share.  You own %7li shares. \n", lucent, lucent_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How much would you like to spend? ");
                        scanf("%li", &spend);
                        if (spend <= 0)
                           break;
                        if (spend <= cash)
                        {
                           new_shares = spend / lucent;
                           lucent_shares = lucent_shares + (new_shares);
                           lucent_purchase = lucent;
                           cash = cash - (new_shares * lucent);
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that much money.\n");
                           continue;
                        }
                     case 'd':
                     case 'D':
                        printf("\n DELTA is currently $%3i per share.  You own %7li shares. \n", delta, delta_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How much would you like to spend? ");
                        scanf("%li", &spend);
                        if (spend <= 0)
                           break;
                        if (spend <= cash)
                        {
                           new_shares = spend / delta;
                           delta_shares = delta_shares + (new_shares);
                           delta_purchase = delta;
                           cash = cash - (new_shares * delta);
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that much money.\n");
                           continue;
                        }
                     case 'm':
                     case 'M':
                        printf("\n MAYTAG is currently $%3i per share.  You own %7li shares. \n", maytag, maytag_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How much would you like to spend? ");
                        scanf("%li", &spend);
                        if (spend <= 0)
                           break;
                        if (spend <= cash)
                        {
                           new_shares = spend / maytag;
                           maytag_shares = maytag_shares + (new_shares);
                           maytag_purchase = maytag;
                           cash = cash - (new_shares * maytag);
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that much money.\n");
                           continue;
                        }
                     default:
                        break;
                  }
               }
               break;
            case 's':
            case 'S':

               /*  SELL commands  */

               while (1)
               {
                  printf("Type first letter of stock or x to go back: ");
                  scanf("%c", &selection);
                  scanf("%c", &selection);
                  /*  CLEAR SCREEN  */
                  clrscr();
                  /*  check users selection  */
                  if (selection == 'x' || selection == 'X')
                     break;  /*  go back to prices if x or X  */
                  switch (selection)
                  {
                     case 'a':
                     case 'A':
                        printf("\n AT&T is currently $%3i per share.  You own %7li shares. \n", att, att_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How many shares would you like to sell? ");
                        scanf("%li", &sell);
                        if (sell <= 0)
                           break;
                        if (sell = att_shares)
                           att_purchase = 0;                                        
                        if (sell <= att_shares)
                           {
                           cash = cash + (sell * att);
                           att_shares = att_shares - sell;                           
                           break;
                           }
                        else
                        {
                           printf("\nYou don't have that many shares.\n");
                           continue;
                        }
                     case 'i':
                     case 'I':
                        printf("\n IBM is currently $%3i per share.  You own %7li shares. \n", ibm, ibm_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How many shares would you like to sell? ");
                        scanf("%li", &sell);
                        if (sell <= 0)
                           break;
                        if (sell = ibm_shares)
                           ibm_purchase = 0;
                        if (sell <= ibm_shares)
                        {
                           cash = cash + (sell * ibm);
                           ibm_shares = ibm_shares - sell;                                                            
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that many shares.\n");
                           continue;
                        }
                     case 'p':
                     case 'P':
                        printf("\n PEPSI is currently $%3i per share.  You own %7li shares. \n", pepsi, pepsi_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How many shares would you like to sell? ");
                        scanf("%li", &sell);
                        if (sell <= 0)
                           break;
                        if (sell = pepsi_shares)
                           pepsi_purchase = 0;
                        if (sell <= pepsi_shares)
                        {
                           cash = cash + (sell * pepsi);
                           pepsi_shares = pepsi_shares - sell;          
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that many shares.\n");
                           continue;
                        }
                     case 'g':
                     case 'G':
                        printf("\n GE is currently $%3i per share.  You own %7li shares. \n", ge, ge_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How many shares would you like to sell? ");
                        scanf("%li", &sell);
                        if (sell <= 0)
                           break;
                        if (sell = ge_shares)
                           ge_purchase = 0;
                        if (sell <= ge_shares)
                        {
                           cash = cash + (sell * ge);
                           ge_shares = ge_shares - sell;                              
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that many shares.\n");
                           continue;
                        }
                     case 'l':
                     case 'L':
                        printf("\n LUCENT is currently $%3i per share.  You own %7li shares. \n", lucent, lucent_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How many shares would you like to sell? ");
                        scanf("%li", &sell);
                        if (sell <= 0)
                           break;
                        if (sell = lucent_shares)
                           lucent_purchase = 0;
                        if (sell <= lucent_shares)
                        {
                           cash = cash + (sell * lucent);
                           lucent_shares = lucent_shares - sell;                       
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that many shares.\n");
                           continue;
                        }
                     case 'd':
                     case 'D':
                        printf("\n DELTA is currently $%3i per share.  You own %7li shares. \n", delta, delta_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("\type 0 to exit. \n ");
                        printf("How many shares would you like to sell? ");
                        scanf("%li", &sell);
                        if (sell <= 0)
                           break;
                        if (sell = delta_shares)
                           delta_purchase = 0;
                        if (sell <= delta_shares)
                        {
                           cash = cash + (sell * delta);
                           delta_shares = delta_shares - sell;                          
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that many shares.\n");
                           continue;
                        }
                     case 'm':
                     case 'M':
                        printf("\n MAYTAG is currently $%3i per share.  You own %7li shares. \n", maytag, maytag_shares);
                        printf("Your cash on hand is $%9li \n", cash);
                        printf("type 0 to exit. \n ");
                        printf("How many shares would you like to sell? ");
                        scanf("%li", &sell);
                        if (sell <= 0)
                           break;
                        if (sell = maytag_shares)
                           maytag_purchase = 0;
                        if (sell <= maytag_shares)
                        {
                           cash = cash + (sell * maytag);
                           maytag_shares = maytag_shares - sell;                           
                           break;
                        }
                        else
                        {
                           printf("\nYou don't have that many shares.\n");
                           continue;
                        }
                     default:
                        break;
                  }
               }
               break;
            case 'l':
            case 'L':
               /*  loan commands  */
               clrscr();
               while (1)
               {
                  printf("Welcome to First National Bank \n \n");
                  printf("Your choices are: \n");
                  printf("L - take out a Loan \n");
                  printf("P - Pay back the bank \n");
                  printf("B - check your Balance \n");
                  printf("R - Return to the market \n");
                  scanf("%c", &selection);
                  scanf("%c", &selection);
                  /*  CLEAR SCREEN  */
                  clrscr();
                  if (selection == 'r' || selection == 'R')
                     break;   /*  if R or r, return to market  */
                  switch (selection)
                  {
                     case 'l':
                     case 'L':
                        printf("You're cash on hand is $%li \n", cash);
                        printf("You can borrow up to $%li \n\n", borrow_limit - loan);
                        printf("Enter the amount you wish to borrow: ");
                        scanf("%li", &borrow);
                        if (borrow <= borrow_limit)
                        {
                           loan = borrow;
                           cash = cash + borrow;                   
                        }
                        else
                           printf("You can't borrow that much.");
                        break;
                     case 'p':
                     case 'P':
                        printf("Your cash on hand is $%li \n", cash);
                        printf("You owe $%li \n\n", loan);
                        printf("Enter the amount you with to pay back: ");
                        scanf("%li", &payback);
                        if (payback >= 0)
                        {
                           loan = loan - payback;
                           cash = cash - payback;
                           if (cash < 0)
                              cash = 0;
                           else
                              ;
                        }
                        else
                        {
                           printf("That is not a valid amount.\n");
                           printf("We don't like cheaters.\n");
                        }
                        break;
                     case 'b':
                     case 'B':
                        printf("Your cash on hand is $%li \n", cash);
                        printf("You currently owe the bank $%li \n\n", loan);
                        printf("thank you and have a nice day.\n");
                        printf("press 0 to exit. ->");
                        scanf("%i", &pause);
                        if (pause)
                           break;
                     default:
                        break;
                  }
               clrscr();
               }
               break;
            default:
               printf("Type either E, B, or L \n");
               break;
         }
      }
      /***  change stock prices  */
      /* store last prices */
      if (week < 10)
      {
         att_last = att;
         ibm_last = ibm;
         pepsi_last = pepsi;
         ge_last = ge;
         lucent_last = lucent;
         delta_last = delta;
         maytag_last = maytag;

         /*  change stock prices  */
         att = att + (rand() % 31 - 14);
         ibm = ibm + (rand() % 31 - 14);
         pepsi = pepsi + (rand() % 31 - 14);
         ge = ge + (rand() % 31 - 14);
         lucent = lucent + (rand() % 31 - 14);
         delta = delta + (rand() % 31 - 14);
         maytag = maytag + (rand() % 31 - 14);

         /* adjust prices so there are no negative prices  */

         if (att <= 0)
            att = 1 + (rand() % 5);
         else
            ;

         if (ibm <= 0)
            ibm = 1 + (rand() % 5);
         else
            ;

         if (pepsi <= 0)
            pepsi = 1 + (rand() % 5);
         else
            ;

         if (ge <= 0)
            ge = 1 + (rand() % 5);
         else
            ;

         if (lucent <= 0)
            lucent = 1 + (rand() % 5);
         else
            ;

         if (delta <= 0)
            delta = 1 + (rand() % 5);
         else
            ;

         if (maytag <= 0)
            maytag = 1 + (rand() % 5);
         else
            ;

         /*  calculate change  */
         att_change = att - att_last;
         ibm_change = ibm - ibm_last;
         pepsi_change = pepsi - pepsi_last;
         ge_change = ge - ge_last;
         lucent_change = lucent - lucent_last;
         delta_change = delta - delta_last;
         maytag_change = maytag - maytag_last;

         /*  adjust loan and borrow max  */
         loan = loan * 1.05;
         if (week % 2 == 0)
            borrow_limit = borrow_limit + 500000;
         else
            ;
      }
      else
         ;
   }

/*  display results  */
clrscr();
stock_worth = (att * att_shares) + (ibm * ibm_shares) + (pepsi * pepsi_shares) + (ge * ge_shares) + (lucent * lucent_shares) + (delta * delta_shares) + (maytag * maytag_shares);
printf("\n------------ Game Over ------------\n\n");
printf("Your cash:             $%8li \n", cash);
printf("Your stocks are worth: $%8li \n", stock_worth); 
printf("Your total is:         $%8li \n", stock_worth + cash);
printf("\nThank you for playing Stock Market.\n");

}
