#include<stdio.h>

long long find_mod(long long base,long long exponent,long long modular){
	
	if(modular <= 0){
		printf("Modular must be greater than zero ");
		return -1;
	}
	if(exponent < 0){
		printf("Exponent must be positive");
		return -1;
	}
	if(modular == 1) return 0;
	long long result = 1;
	
	while(exponent >0){
		if(exponent %2 == 1){
			result = (result *base) % modular;
			
		}
		exponent = exponent /2;
		base = (base * base ) % modular;
	}	
	
	return result;
}

int main(){
	long long base;
	long long exponent;
	long long modular;
	long long result;
	
	printf("Enter the base value : ");
	scanf("%lld",&base);
	
	printf("Enter the exponent value : ");
	scanf("%lld",&exponent);
	
	printf("Enter the modular value : ");
	scanf("%lld",&modular);
	
	if(base == 0 && exponent<=0 ){
		printf("undefined : 0 ^ 0\n");
		return 0;
	}
	
	
	result = find_mod(base,exponent,modular);
	if(result != -1){
		printf("Output : %lld ",result);
	}
	
	
	return 0;
	
}
