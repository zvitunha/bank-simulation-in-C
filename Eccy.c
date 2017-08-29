#include <stdio.h>
#include <stdlib.h>

/* assumptions
- there is only one server(teller) in the bank
-each customer takes the same time to e served by the teller ie the service time(st)
-the service time is exponentially distributed with a mean known as the service rate

-In single serve queing theory, one of the charectaristics are that we have poisson arrival of customers. 
But our question asked for binomial distribution, therefore we estimate binomial to poisson. 
to estiamte binomial to exponetial the number of custmers(n) must therefore be less than 50.
a probability(p) should also be entered.

then n*p=lamperter which the gives the poisson arrivals

-customer 1 values are fixed to that according to simulation and modelling

-what i failed is kuti after simulating for customer 1 topresser enter to view for custmer 2 topresser enter to view for customer 3 etc

*/


double main()
{
	int n;
	double p;
	int st;

	
	printf("Hi! Welcome to Eccy Bank \n ");
	
    printf("\nEnter the number of customers you want to simulate for and press Enter");
    scanf("%d",&n);
    
    printf("\nEnter the probability and press Enter");
    scanf("%d",&p);
    
    printf("\nEnter the time you think the teller will take to serve each customer and press Enter");
    scanf("%d",&st);
    
    printf("\n \n You are simulating for %d customers, at probability %d and the service time is %d", n, p, st);
    
	int customernumber = 1;
	           
	    /*Customer 1 values are always fixed*/
	    printf("\n");
        printf("\n Customer %d", customernumber);
        printf("\n Interarrival time: %d ", 0);
        printf("\n Service Time: %d", st);
        printf("\n Arrival Time: %d" ,0);
        printf("\n Time Service Begin: %d", 0);
        printf("\n Time Service Ends: %d", st);
        printf("\n Waiting Time: ");

		/*Customer 2 begins now*/
		do
		{
		customernumber = customernumber + 1;
		double lamperter = n*p;
		
		
		printf("\n");
		 printf("\n Customer: %d", customernumber);
        printf("\n Interarrival time: %d ", lamperter);
        printf("\n Service Time: %d", &st);
        
        double at = (customernumber - 1)*lamperter;
        printf("\n Arrival Time: %d" , &at);
        
        int tsb = (customernumber - 1) * st;
        printf("\n Time Service Begin: %d", &tsb );

		int tse = tsb + st;
		printf("\n Time Service Ends: %d", &tse);
		
		int wt = tse - tsb;
        printf("\n Waiting Time: %d", &wt);
        
        
        
    }
    while(customernumber < n);
    
    printf("\n");
    printf("\n You have simulated for %d customers. \n", n);
        

}

