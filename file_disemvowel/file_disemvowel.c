#include "file_disemvowel.h"

#define BUF_SIZE 1024
// returns true if the character passed is a vowel
bool is_vowel(char c) {
	if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
		return true;

	}
	return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
	// number of non-vowels
	int nv_count = 0;
	for(int i =0; i < num_chars; i++){
		// counter for out_buf
		if(!is_vowel(in_buf[i])){
			out_buf[nv_count] = in_buf[i];
			nv_count++;
		}	
	}
return nv_count;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
	char* input_buf = (char*)calloc(BUF_SIZE, 1);
	char* output_buf = (char*)calloc(BUF_SIZE, 1);
	// while fread still has more stuff to read through
	while((inputFile != NULL && outputFile!=NULL) && fread(input_buf, 1, BUF_SIZE ,inputFile) > 0){
	fread(input_buf, 1, BUF_SIZE ,inputFile);
	copy_non_vowels(BUF_SIZE, input_buf, output_buf);
	fwrite(output_buf, 1, strlen(output_buf), outputFile);
	}
	free(input_buf);
	free(output_buf);
}

int main(int argc, char *argv[]) {
	FILE* inputFile = NULL;
	FILE* outputFile = NULL;
	// if we also receive an input file
	if(argc == 2){
		inputFile = fopen(argv[1], "r");
		outputFile = stdout;
	}
	// if we receive an input and output file
	else if(argc == 3){
		inputFile = fopen(argv[1], "r");
		outputFile = fopen(argv[2], "w");
	}
	else{
		inputFile = stdin;
		outputFile = stdout;
	}
	disemvowel(inputFile, outputFile);
	if(inputFile!=NULL){
		fclose(inputFile);
	}
	if(outputFile!=NULL){
	fclose(outputFile);
	}

	return 0;
}
