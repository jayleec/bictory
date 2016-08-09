int sums[10];
    
int getBadSum(int badIndex) {    
	int sum = 0;
	
	if(sum == 0) {
		if(badIndex + 1 > 0) {
			return sums[badIndex];
		}
		return sums[badIndex];		/* Violation : shall be validated for boundary. */
	}
	
	return sums[badIndex];			/* Violation : shall be validated for boundary. */
}

int getGoodSumG(int goodIndex) {    
	int sum = 0;

	if(goodIndex >=0 && goodIndex < 10) {
		return sums[goodIndex];
	}	
	
	return -1;
}   
