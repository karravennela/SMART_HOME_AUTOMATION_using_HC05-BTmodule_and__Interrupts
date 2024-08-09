/* UART0 DRIVER */


 #include<lpc21xx.h>

 #include"header.h"


typedef unsigned int u32;

typedef unsigned char u8;


#define THRE ((U0LSR>>5)&1)

#define RDR (U0LSR&1)




void uart0_tx(u8 data)

{

 	U0THR = data;

	while(THRE==0);

}

u8 uart0_rx(void)

{

 	while(RDR==0);

	return U0RBR;

}

void uart0_tx_str(u8 *p)

{

 	while(*p)

	{

		U0THR = *p;

		while(THRE==0);

		p++;

	}

}

void uart0_rx_str(u8 *p,u32 max_bytes)
{
	int i;
	for(i=0; i<max_bytes; i++)
	{
	 	while(RDR == 0);
		p[i] = U0RBR;
		uart0_tx(p[i]);
		if(p[i] == '\r')
			break;
	}
	p[i] = 0;
}

void uart0_atoi(int n)

{

	u8 a[5];

	int i;

	if(n==0)

		uart0_tx('0');

	else if(n<0)

	{

		uart0_tx('-');

		n = -n;

	}

	if(n>0)

	{

		for(i=0; n; i++)

		{

	 		a[i] = (n%10) + 48;

			n = n/10;

		}

		for(i=i-1; i>=0; i--)

	 	uart0_tx(a[i]);

	}			

}

void uart0_hexa(u8 n)

{

	int f=0,i,j,k=2,pos;

	u8 x,a[6] = {'A','B','C','D','E','F'};

	uart0_tx(' ');

	uart0_tx('0');

	uart0_tx('X');

	while(k)

	{

		if(f==0)

			pos=4;

		else

			pos=0;

		x = ((n>>pos)&0x0f);

		if(x>9)

		{

			for(i=10,j=0; i<x; i++,j++);

				uart0_tx(a[j]);

		}

		else

			uart0_tx(x+48);

		k--;

		f = !f;

	}	

}
void uart0_bnry(u32 n)
{
	int i,x;
	for(i=7; i>=0; i--)
	{
		x = ((n>>i)&1);
		if(x==0)
		{ uart0_tx('0');}
		else
		{ uart0_tx('1');}
	}
}

void uart0_init(u32 baud)

{

	u32 result, pclk, a[5] = {15,60,30,15,15};

	pclk = a[VPBDIV]*1000000;

	result = pclk/(16*baud);

	PINSEL0 |= 5;

	U0LCR = 0X83;

	U0DLL = result&0xff;

	U0DLM = (result>>8)&0xff;  

	U0LCR = 0X3;

}


