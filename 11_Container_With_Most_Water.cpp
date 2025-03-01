int maxArea(int* height, int heightSize){
	int space = 0;

	for(int i = 0; i < heightSize; i++){
		if(*(height + i) == 0)
			continue;
		for(int j = heightSize - 1; (space / (*(height + i)) <= j - i) && j > i; j--){
			int hei = (*(height + i) < *(height + j)) ? *(height + i) : *(height + j);
			if((j - i) * hei > space)
				space = (j - i) * hei;

		}
	}
	return space;
}