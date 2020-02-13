#include<stdio.h>
int main(){
	int fix_price, variable_price, price;
	int i;

	scanf("%d %d %d", &fix_price, &variable_price, &price);
	//for(i=1;;i++){
		if(price <= variable_price) 
			i=-1;
			//break;
		
	
		/*if(fix_price <= i*(price-variable_price)) {
			i++;		
			break;
		}*/
		else
		i = fix_price/(price-variable_price) + 1 ;
	

	printf("%d", i);

}
